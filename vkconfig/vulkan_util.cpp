/*
 * Copyright (c) 2020-2021 Valve Corporation
 * Copyright (c) 2020-2021 LunarG, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Authors:
 * - Christophe Riccio <christophe@lunarg.com>
 */

#include "vulkan_util.h"
#include "configurator.h"

#include "../vkconfig_core/alert.h"
#include "../vkconfig_core/util.h"
#include "../vkconfig_core/platform.h"
#include "../vkconfig_core/override.h"

#include <vulkan/vulkan.h>

#include <QLibrary>
#include <QtGlobal>

#include <cassert>

const char *GetVulkanLibrary() {
    static const char *TABLE[] = {
        "vulkan-1.dll",              // PLATFORM_WINDOWS
        "libvulkan",                 // PLATFORM_LINUX
        "/usr/local/lib/libvulkan",  // PLATFORM_MACOS
        "N/A",                       // PLATFORM_ANDROID
    };
    static_assert(countof(TABLE) == PLATFORM_COUNT, "The tranlation table size doesn't match the enum number of elements");

    return TABLE[VKC_PLATFORM];
}

std::string GetUUIDString(const uint8_t deviceUUID[VK_UUID_SIZE]) {
    std::string result;

    for (std::size_t i = 0, n = VK_UUID_SIZE; i < n; ++i) {
        result += format("%02X", deviceUUID[i]);
    }

    return result;
}

Version GetVulkanLoaderVersion() {
    // Check loader version
    QLibrary library(GetVulkanLibrary());

    if (!library.load()) return Version::VERSION_NULL;

    PFN_vkEnumerateInstanceVersion vkEnumerateInstanceVersion;
    vkEnumerateInstanceVersion = (PFN_vkEnumerateInstanceVersion)library.resolve("vkEnumerateInstanceVersion");
    assert(vkEnumerateInstanceVersion);

    uint32_t version = 0;
    const VkResult result = vkEnumerateInstanceVersion(&version);
    assert(result == VK_SUCCESS);

    return Version(version);
}

static std::string GetUserDefinedLayersPathsLog(const char *label, UserDefinedLayersPaths custom_layer_path) {
    std::string log;

    const std::vector<std::string> &user_defined_layer_paths =
        Configurator::Get().environment.GetUserDefinedLayersPaths(custom_layer_path);
    if (!user_defined_layer_paths.empty()) {
        log += format("    - %s:\n", label);
        for (std::size_t i = 0, n = user_defined_layer_paths.size(); i < n; ++i)
            log += format("        - %s\n", user_defined_layer_paths[i].c_str());
    } else
        log += format("    - %s: None\n", label);

    return log;
}

VkResult CreateInstance(QLibrary &library, VkInstance &instance, bool enumerate_portability) {
    if (!enumerate_portability) return VK_ERROR_INCOMPATIBLE_DRIVER;

    PFN_vkEnumerateInstanceExtensionProperties vkEnumerateInstanceExtensionProperties =
        (PFN_vkEnumerateInstanceExtensionProperties)library.resolve("vkEnumerateInstanceExtensionProperties");
    assert(vkEnumerateInstanceExtensionProperties);

    uint32_t property_count = 0;
    VkResult err = vkEnumerateInstanceExtensionProperties(nullptr, &property_count, nullptr);
    assert(err == VK_SUCCESS);

    std::vector<VkExtensionProperties> instance_properties(property_count);
    err = vkEnumerateInstanceExtensionProperties(nullptr, &property_count, &instance_properties[0]);
    assert(err == VK_SUCCESS);

    // Handle Portability Enumeration requirements
    std::vector<const char *> instance_extensions;

    for (std::size_t i = 0, n = instance_properties.size(); i < n && enumerate_portability; ++i) {
        if (instance_properties[i].extensionName == std::string(VK_KHR_EXTERNAL_MEMORY_CAPABILITIES_EXTENSION_NAME)) {
            instance_extensions.push_back(VK_KHR_EXTERNAL_MEMORY_CAPABILITIES_EXTENSION_NAME);
        }
#if VK_KHR_portability_enumeration
        else if (instance_properties[i].extensionName == std::string(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME)) {
            instance_extensions.push_back(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME);
        }
#endif
    }

    // Check Vulkan Devices

    VkApplicationInfo app = {};
    app.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    app.pNext = nullptr;
    app.pApplicationName = VKCONFIG_SHORT_NAME;
    app.applicationVersion = 0;
    app.pEngineName = VKCONFIG_SHORT_NAME;
    app.engineVersion = 0;
    app.apiVersion = VK_API_VERSION_1_1;

    VkInstanceCreateInfo inst_info = {};
    inst_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
#if VK_KHR_portability_enumeration
    if (!instance_extensions.empty()) {
        inst_info.flags = VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;
    }
#endif
    inst_info.pNext = nullptr;
    inst_info.pApplicationInfo = &app;
    inst_info.enabledLayerCount = 0;
    inst_info.ppEnabledLayerNames = nullptr;
    inst_info.enabledExtensionCount = static_cast<uint32_t>(instance_extensions.size());
    inst_info.ppEnabledExtensionNames = instance_extensions.empty() ? nullptr : &instance_extensions[0];

    PFN_vkCreateInstance vkCreateInstance = (PFN_vkCreateInstance)library.resolve("vkCreateInstance");
    assert(vkCreateInstance);

    return vkCreateInstance(&inst_info, nullptr, &instance);
}

std::string GenerateVulkanStatus() {
    std::string log;

    Configurator &configurator = Configurator::Get();

    // Layers override configuration
    switch (configurator.environment.GetMode()) {
        default:
        case LAYERS_MODE_BY_APPLICATIONS:
            log += "- Vulkan Layers Controlled by Vulkan Applications\n";
            break;
        case LAYERS_MODE_BY_CONFIGURATOR_RUNNING:
            if (configurator.configurations.HasActiveConfiguration(configurator.layers.available_layers)) {
                log += format("- Vulkan Layers Controlled by \"%s\" configuration\n",
                              configurator.environment.GetSelectedConfiguration().c_str());
            } else {
                log += format("- Vulkan Layers Controlled by Vulkan Configurator but no configuration selected\n",
                              configurator.environment.GetSelectedConfiguration().c_str());
            }
            break;
        case LAYERS_MODE_BY_CONFIGURATOR_ALL_DISABLED:
            log += "- Vulkan Layers Disabled by Vulkan Configurator\n";
            break;
    }

    log += "- Environment variables:\n";

    // Check Vulkan SDK path
    const std::string search_path(configurator.path.GetPath(PATH_VULKAN_SDK));
    if (!search_path.empty())
        log += format("    - VULKAN_SDK: %s\n", search_path.c_str());
    else
        log += "    - VULKAN_SDK not set\n";

    // Check VK_LOCAL path
    const std::string vk_local_path(GetPath(BUILTIN_PATH_LOCAL));
    if (!vk_local_path.empty()) {
        log += format("    - VK_LOCAL: %s\n", vk_local_path.c_str());
    }

    const Version loader_version = GetVulkanLoaderVersion();

    if (loader_version == Version::VERSION_NULL) {
        Alert::LoaderFailure();

        log += "- Could not find a Vulkan Loader.\n";
        return log;
    } else {
        log += format("- Vulkan Loader version: %s\n", loader_version.str().c_str());
        const int loader_message_types = configurator.environment.GetLoaderMessageTypes();
        if (loader_message_types != LOADER_MESSAGE_NONE) {
            log += format("    - VK_LOADER_DEBUG=%s\n", GetLoaderMessageTokens(loader_message_types).c_str());
        }
    }

    log += "- User-Defined Layers locations:\n";
    log += GetUserDefinedLayersPathsLog("VK_LAYER_PATH variable", USER_DEFINED_LAYERS_PATHS_ENV_SET);
    log += GetUserDefinedLayersPathsLog("Per-configuration paths", USER_DEFINED_LAYERS_PATHS_GUI);
    log += GetUserDefinedLayersPathsLog("VK_ADD_LAYER_PATH variable", USER_DEFINED_LAYERS_PATHS_ENV_ADD);

    const std::string layer_settings_path(qgetenv("VK_LAYER_SETTINGS_PATH"));
    if (!layer_settings_path.empty()) {
        log += "- `vk_layer_settings.txt` location overridden by VK_LAYER_SETTINGS_PATH:\n";
        if (layer_settings_path.find("vk_layer_settings.txt") == std::string::npos) {
            log += format("    %s\n", layer_settings_path.c_str());
        } else {
            log += format("    %s\n", ExtractAbsoluteDir(layer_settings_path).c_str());
        }
    } else {
        const std::string path = GetPath(BUILTIN_PATH_OVERRIDE_SETTINGS);
        log += "- `vk_layer_settings.txt` uses the default platform path:\n";
        log += format("    %s\n", ExtractAbsoluteDir(path).c_str());
    }

    // If there is no Vulkan loader installed, we can't call any Vulkan API.
    if (loader_version == Version::VERSION_NULL) {
        return log;
    }

    LayersMode saved_mode = configurator.environment.GetMode();
    configurator.environment.SetMode(LAYERS_MODE_BY_APPLICATIONS);
    configurator.configurations.Configure(configurator.layers.available_layers);

    QLibrary library(GetVulkanLibrary());
    PFN_vkEnumerateInstanceLayerProperties vkEnumerateInstanceLayerProperties =
        (PFN_vkEnumerateInstanceLayerProperties)library.resolve("vkEnumerateInstanceLayerProperties");
    assert(vkEnumerateInstanceLayerProperties);

    std::uint32_t instance_layer_count = 0;
    VkResult err = vkEnumerateInstanceLayerProperties(&instance_layer_count, NULL);
    assert(!err);

    std::vector<VkLayerProperties> layers_properties;
    layers_properties.resize(instance_layer_count);

    err = vkEnumerateInstanceLayerProperties(&instance_layer_count, &layers_properties[0]);
    assert(!err);

    log += "- Available Layers:\n";
    for (std::size_t i = 0, n = layers_properties.size(); i < n; ++i) {
        const Layer *layer = FindByKey(configurator.layers.available_layers, layers_properties[i].layerName);

        std::string status;
        if (layer != nullptr) {
            if (layer->status != STATUS_STABLE) {
                status = GetToken(layer->status);
            }
        }

        if (status.empty()) {
            log += format("    - %s\n", layers_properties[i].layerName);
        } else {
            log += format("    - %s (%s)\n", layers_properties[i].layerName, status.c_str());
        }
    }

    VkInstance inst = VK_NULL_HANDLE;
    err = CreateInstance(library, inst, false);
    if (err == VK_ERROR_INCOMPATIBLE_DRIVER) {
        // If no compatible driver were found, trying with portability enumeration
        err = CreateInstance(library, inst, true);
        if (err == VK_ERROR_INCOMPATIBLE_DRIVER) {
            Alert::InstanceFailure();

            log += "- Cannot find a compatible Vulkan installable client driver (ICD).\n";
            return log;
        }
    }
    assert(err == VK_SUCCESS);

    PFN_vkEnumeratePhysicalDevices vkEnumeratePhysicalDevices =
        (PFN_vkEnumeratePhysicalDevices)library.resolve("vkEnumeratePhysicalDevices");
    assert(vkEnumeratePhysicalDevices);

    PFN_vkEnumerateInstanceExtensionProperties vkEnumerateInstanceExtensionProperties =
        (PFN_vkEnumerateInstanceExtensionProperties)library.resolve("vkEnumerateInstanceExtensionProperties");
    assert(vkEnumerateInstanceExtensionProperties);

    VkResult result = VK_SUCCESS;

    uint32_t instance_extension_count = 0;
    result = vkEnumerateInstanceExtensionProperties(nullptr, &instance_extension_count, nullptr);

    std::vector<VkExtensionProperties> instance_extensions;
    if (instance_extension_count > 0) {
        instance_extensions.resize(instance_extension_count);
    }
    result = vkEnumerateInstanceExtensionProperties(nullptr, &instance_extension_count, instance_extensions.data());

    bool has_device_id = false;
    if (result == VK_SUCCESS) {
        for (std::size_t i = 0, n = instance_extensions.size(); i < n; ++i) {
            if (instance_extensions[i].extensionName == std::string(VK_KHR_EXTERNAL_MEMORY_CAPABILITIES_EXTENSION_NAME)) {
                has_device_id = true;
                break;
            }
        }
    }

    uint32_t gpu_count = 0;
    err = vkEnumeratePhysicalDevices(inst, &gpu_count, NULL);

    PFN_vkDestroyInstance vkDestroyInstance = (PFN_vkDestroyInstance)library.resolve("vkDestroyInstance");
    assert(vkDestroyInstance);

    // This can fail on a new Linux setup. Check and fail gracefully rather than crash.
    if (err != VK_SUCCESS) {
        Alert::PhysicalDeviceFailure();
        vkDestroyInstance(inst, NULL);

        log += "- Cannot find a compatible Vulkan installable client driver (ICD).\n";
        return log;
    }

    std::vector<VkPhysicalDevice> devices;
    devices.resize(gpu_count);

    err = vkEnumeratePhysicalDevices(inst, &gpu_count, &devices[0]);
    assert(!err);

    PFN_vkGetPhysicalDeviceProperties pfnGetPhysicalDeviceProperties =
        (PFN_vkGetPhysicalDeviceProperties)library.resolve("vkGetPhysicalDeviceProperties");
    assert(pfnGetPhysicalDeviceProperties);

    Configurator &configurator_edit = Configurator::Get();
    configurator_edit.device_names.clear();

    log += "- Physical Devices:\n";
    for (std::size_t i = 0, n = devices.size(); i < n; ++i) {
        VkPhysicalDeviceProperties properties;
        pfnGetPhysicalDeviceProperties(devices[i], &properties);

        const std::string vk_version = format("%d.%d.%d", VK_VERSION_MAJOR(properties.apiVersion),
                                              VK_VERSION_MINOR(properties.apiVersion), VK_VERSION_PATCH(properties.apiVersion));

        log += format("    - %s with Vulkan %s\n", properties.deviceName, vk_version.c_str());

        if (has_device_id) {
            PFN_vkGetPhysicalDeviceProperties2 pfnGetPhysicalDeviceProperties2 =
                (PFN_vkGetPhysicalDeviceProperties2)library.resolve("vkGetPhysicalDeviceProperties2");
            assert(pfnGetPhysicalDeviceProperties2);

            VkPhysicalDeviceIDPropertiesKHR properties_deviceid{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES_KHR, nullptr};
            VkPhysicalDeviceProperties2 properties2{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2, &properties_deviceid};

            pfnGetPhysicalDeviceProperties2(devices[i], &properties2);

            const std::string deviceUUID = GetUUIDString(properties_deviceid.deviceUUID);
            log += format("        - deviceUUID: %s\n", deviceUUID.c_str());

            const std::string driverUUID = GetUUIDString(properties_deviceid.driverUUID);
            log += format("        - driverUUID: %s\n", driverUUID.c_str());
        }

        configurator_edit.device_names.push_back(properties.deviceName);
    }

    vkDestroyInstance(inst, NULL);

    configurator.environment.SetMode(saved_mode);
    configurator.configurations.Configure(configurator.layers.available_layers);

    return log;
}
