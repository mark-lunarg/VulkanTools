
/* Copyright (c) 2015-2016, 2021 Valve Corporation
 * Copyright (c) 2015-2016, 2021 LunarG, Inc.
 * Copyright (c) 2015-2016, 2021 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Author: Lenny Komow <lenny@lunarg.com>
 * Author: Shannon McPherson <shannon@lunarg.com>
 * Author: Charles Giessen <charles@lunarg.com>
 */

/*
 * This file is generated from the Khronos Vulkan XML API Registry.
 */

#include "api_dump_text.h"
#include "api_dump_html.h"
#include "api_dump_json.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

// Specifically implemented functions

#if defined(__GNUC__) && __GNUC__ >= 4
#define EXPORT_FUNCTION __attribute__((visibility("default")))
#elif defined(__SUNPRO_C) && (__SUNPRO_C >= 0x590)
#define EXPORT_FUNCTION __attribute__((visibility("default")))
#else
#define EXPORT_FUNCTION
#endif

VKAPI_ATTR VkResult VKAPI_CALL vkCreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    ApiDumpInstance::current().initLayerSettings(pCreateInfo, pAllocator);
    dump_function_head(ApiDumpInstance::current(), "vkCreateInstance", "pCreateInfo, pAllocator, pInstance", "VkResult");

    // Get the function pointer
    VkLayerInstanceCreateInfo* chain_info = get_chain_info(pCreateInfo, VK_LAYER_LINK_INFO);
    assert(chain_info->u.pLayerInfo != 0);
    PFN_vkGetInstanceProcAddr fpGetInstanceProcAddr = chain_info->u.pLayerInfo->pfnNextGetInstanceProcAddr;
    assert(fpGetInstanceProcAddr != 0);
    PFN_vkCreateInstance fpCreateInstance = (PFN_vkCreateInstance) fpGetInstanceProcAddr(NULL, "vkCreateInstance");
    if(fpCreateInstance == NULL) {
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    // Call the function and create the dispatch table
    chain_info->u.pLayerInfo = chain_info->u.pLayerInfo->pNext;
    VkResult result = fpCreateInstance(pCreateInfo, pAllocator, pInstance);
    if(result == VK_SUCCESS) {
        initInstanceTable(*pInstance, fpGetInstanceProcAddr);
    }

    // Output the API dump
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateInstance(ApiDumpInstance::current(), result, pCreateInfo, pAllocator, pInstance);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateInstance(ApiDumpInstance::current(), result, pCreateInfo, pAllocator, pInstance);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateInstance(ApiDumpInstance::current(), result, pCreateInfo, pAllocator, pInstance);
                break;
        }
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL vkCreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDevice* pDevice)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateDevice", "physicalDevice, pCreateInfo, pAllocator, pDevice", "VkResult");

    // Get the function pointer
    VkLayerDeviceCreateInfo* chain_info = get_chain_info(pCreateInfo, VK_LAYER_LINK_INFO);
    assert(chain_info->u.pLayerInfo != 0);
    PFN_vkGetInstanceProcAddr fpGetInstanceProcAddr = chain_info->u.pLayerInfo->pfnNextGetInstanceProcAddr;
    PFN_vkGetDeviceProcAddr fpGetDeviceProcAddr = chain_info->u.pLayerInfo->pfnNextGetDeviceProcAddr;
    VkInstance vk_instance = ApiDumpInstance::current().get_vk_instance(physicalDevice);
    PFN_vkCreateDevice fpCreateDevice = (PFN_vkCreateDevice) fpGetInstanceProcAddr(vk_instance, "vkCreateDevice");
    if(fpCreateDevice == NULL) {
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    // Call the function and create the dispatch table
    chain_info->u.pLayerInfo = chain_info->u.pLayerInfo->pNext;
    VkResult result = fpCreateDevice(physicalDevice, pCreateInfo, pAllocator, pDevice);
    if(result == VK_SUCCESS) {
        initDeviceTable(*pDevice, fpGetDeviceProcAddr);
    }

    // Output the API dump
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateDevice(ApiDumpInstance::current(), result, physicalDevice, pCreateInfo, pAllocator, pDevice);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateDevice(ApiDumpInstance::current(), result, physicalDevice, pCreateInfo, pAllocator, pDevice);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateDevice(ApiDumpInstance::current(), result, physicalDevice, pCreateInfo, pAllocator, pDevice);
                break;
        }
    }
    return result;
}

EXPORT_FUNCTION VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceExtensionProperties(const char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties)
{
    return util_GetExtensionProperties(0, NULL, pPropertyCount, pProperties);
}

EXPORT_FUNCTION VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceLayerProperties(uint32_t* pPropertyCount, VkLayerProperties* pProperties)
{
    static const VkLayerProperties layerProperties[] = {
        {
            "VK_LAYER_LUNARG_api_dump",
            VK_MAKE_VERSION(1, 2, VK_HEADER_VERSION), // specVersion
            VK_MAKE_VERSION(0, 2, 0), // implementationVersion
            "layer: api_dump",
        }
    };

    return util_GetLayerProperties(ARRAY_SIZE(layerProperties), layerProperties, pPropertyCount, pProperties);
}

EXPORT_FUNCTION VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateDeviceLayerProperties(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkLayerProperties* pProperties)
{
    static const VkLayerProperties layerProperties[] = {
        {
            "VK_LAYER_LUNARG_api_dump",
            VK_MAKE_VERSION(1, 2, VK_HEADER_VERSION),
            VK_MAKE_VERSION(0, 2, 0),
            "layer: api_dump",
        }
    };

    return util_GetLayerProperties(ARRAY_SIZE(layerProperties), layerProperties, pPropertyCount, pProperties);
}

// Autogen instance functions

VKAPI_ATTR void VKAPI_CALL vkDestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyInstance", "instance, pAllocator", "void");
    instance_dispatch_table(instance)->DestroyInstance(instance, pAllocator);
    
    destroy_instance_dispatch_table(get_dispatch_key(instance));
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyInstance(ApiDumpInstance::current(), instance, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyInstance(ApiDumpInstance::current(), instance, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyInstance(ApiDumpInstance::current(), instance, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkEnumeratePhysicalDevices(VkInstance instance, uint32_t* pPhysicalDeviceCount, VkPhysicalDevice* pPhysicalDevices)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkEnumeratePhysicalDevices", "instance, pPhysicalDeviceCount, pPhysicalDevices", "VkResult");
    VkResult result = instance_dispatch_table(instance)->EnumeratePhysicalDevices(instance, pPhysicalDeviceCount, pPhysicalDevices);
    
    if (pPhysicalDeviceCount != nullptr && pPhysicalDevices != nullptr) {
        for (uint32_t i = 0; i < *pPhysicalDeviceCount; i++) {
            ApiDumpInstance::current().set_vk_instance(pPhysicalDevices[i], instance);
        }
    }
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkEnumeratePhysicalDevices(ApiDumpInstance::current(), result, instance, pPhysicalDeviceCount, pPhysicalDevices);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkEnumeratePhysicalDevices(ApiDumpInstance::current(), result, instance, pPhysicalDeviceCount, pPhysicalDevices);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkEnumeratePhysicalDevices(ApiDumpInstance::current(), result, instance, pPhysicalDeviceCount, pPhysicalDevices);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFeatures(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures* pFeatures)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceFeatures", "physicalDevice, pFeatures", "void");
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceFeatures(physicalDevice, pFeatures);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceFeatures(ApiDumpInstance::current(), physicalDevice, pFeatures);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceFeatures(ApiDumpInstance::current(), physicalDevice, pFeatures);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceFeatures(ApiDumpInstance::current(), physicalDevice, pFeatures);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties* pFormatProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceFormatProperties", "physicalDevice, format, pFormatProperties", "void");
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceFormatProperties(physicalDevice, format, pFormatProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceFormatProperties(ApiDumpInstance::current(), physicalDevice, format, pFormatProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceFormatProperties(ApiDumpInstance::current(), physicalDevice, format, pFormatProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceFormatProperties(ApiDumpInstance::current(), physicalDevice, format, pFormatProperties);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkImageFormatProperties* pImageFormatProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceImageFormatProperties", "physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceImageFormatProperties(physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceImageFormatProperties(ApiDumpInstance::current(), result, physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceImageFormatProperties(ApiDumpInstance::current(), result, physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceImageFormatProperties(ApiDumpInstance::current(), result, physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties* pProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceProperties", "physicalDevice, pProperties", "void");
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceProperties(physicalDevice, pProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceProperties(ApiDumpInstance::current(), physicalDevice, pProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceProperties(ApiDumpInstance::current(), physicalDevice, pProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceProperties(ApiDumpInstance::current(), physicalDevice, pProperties);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties* pQueueFamilyProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceQueueFamilyProperties", "physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties", "void");
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceQueueFamilyProperties(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceQueueFamilyProperties(ApiDumpInstance::current(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceQueueFamilyProperties(ApiDumpInstance::current(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceQueueFamilyProperties(ApiDumpInstance::current(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceMemoryProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties* pMemoryProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceMemoryProperties", "physicalDevice, pMemoryProperties", "void");
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceMemoryProperties(physicalDevice, pMemoryProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceMemoryProperties(ApiDumpInstance::current(), physicalDevice, pMemoryProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceMemoryProperties(ApiDumpInstance::current(), physicalDevice, pMemoryProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceMemoryProperties(ApiDumpInstance::current(), physicalDevice, pMemoryProperties);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceSparseImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, uint32_t* pPropertyCount, VkSparseImageFormatProperties* pProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceSparseImageFormatProperties", "physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties", "void");
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties(physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceSparseImageFormatProperties(ApiDumpInstance::current(), physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceSparseImageFormatProperties(ApiDumpInstance::current(), physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceSparseImageFormatProperties(ApiDumpInstance::current(), physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkEnumeratePhysicalDeviceGroups(VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkEnumeratePhysicalDeviceGroups", "instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties", "VkResult");
    VkResult result = instance_dispatch_table(instance)->EnumeratePhysicalDeviceGroups(instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkEnumeratePhysicalDeviceGroups(ApiDumpInstance::current(), result, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkEnumeratePhysicalDeviceGroups(ApiDumpInstance::current(), result, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkEnumeratePhysicalDeviceGroups(ApiDumpInstance::current(), result, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFeatures2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceFeatures2", "physicalDevice, pFeatures", "void");
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceFeatures2(physicalDevice, pFeatures);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceFeatures2(ApiDumpInstance::current(), physicalDevice, pFeatures);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceFeatures2(ApiDumpInstance::current(), physicalDevice, pFeatures);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceFeatures2(ApiDumpInstance::current(), physicalDevice, pFeatures);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceProperties2", "physicalDevice, pProperties", "void");
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceProperties2(physicalDevice, pProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceProperties2(ApiDumpInstance::current(), physicalDevice, pProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceProperties2(ApiDumpInstance::current(), physicalDevice, pProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceProperties2(ApiDumpInstance::current(), physicalDevice, pProperties);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFormatProperties2(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceFormatProperties2", "physicalDevice, format, pFormatProperties", "void");
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceFormatProperties2(physicalDevice, format, pFormatProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceFormatProperties2(ApiDumpInstance::current(), physicalDevice, format, pFormatProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceFormatProperties2(ApiDumpInstance::current(), physicalDevice, format, pFormatProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceFormatProperties2(ApiDumpInstance::current(), physicalDevice, format, pFormatProperties);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceImageFormatProperties2(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceImageFormatProperties2", "physicalDevice, pImageFormatInfo, pImageFormatProperties", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceImageFormatProperties2(physicalDevice, pImageFormatInfo, pImageFormatProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceImageFormatProperties2(ApiDumpInstance::current(), result, physicalDevice, pImageFormatInfo, pImageFormatProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceImageFormatProperties2(ApiDumpInstance::current(), result, physicalDevice, pImageFormatInfo, pImageFormatProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceImageFormatProperties2(ApiDumpInstance::current(), result, physicalDevice, pImageFormatInfo, pImageFormatProperties);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceQueueFamilyProperties2(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceQueueFamilyProperties2", "physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties", "void");
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceQueueFamilyProperties2(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceQueueFamilyProperties2(ApiDumpInstance::current(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceQueueFamilyProperties2(ApiDumpInstance::current(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceQueueFamilyProperties2(ApiDumpInstance::current(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceMemoryProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceMemoryProperties2", "physicalDevice, pMemoryProperties", "void");
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceMemoryProperties2(physicalDevice, pMemoryProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceMemoryProperties2(ApiDumpInstance::current(), physicalDevice, pMemoryProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceMemoryProperties2(ApiDumpInstance::current(), physicalDevice, pMemoryProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceMemoryProperties2(ApiDumpInstance::current(), physicalDevice, pMemoryProperties);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceSparseImageFormatProperties2(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceSparseImageFormatProperties2", "physicalDevice, pFormatInfo, pPropertyCount, pProperties", "void");
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties2(physicalDevice, pFormatInfo, pPropertyCount, pProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceSparseImageFormatProperties2(ApiDumpInstance::current(), physicalDevice, pFormatInfo, pPropertyCount, pProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceSparseImageFormatProperties2(ApiDumpInstance::current(), physicalDevice, pFormatInfo, pPropertyCount, pProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceSparseImageFormatProperties2(ApiDumpInstance::current(), physicalDevice, pFormatInfo, pPropertyCount, pProperties);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceExternalBufferProperties(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceExternalBufferProperties", "physicalDevice, pExternalBufferInfo, pExternalBufferProperties", "void");
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceExternalBufferProperties(physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceExternalBufferProperties(ApiDumpInstance::current(), physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceExternalBufferProperties(ApiDumpInstance::current(), physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceExternalBufferProperties(ApiDumpInstance::current(), physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceExternalFenceProperties(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceExternalFenceProperties", "physicalDevice, pExternalFenceInfo, pExternalFenceProperties", "void");
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceExternalFenceProperties(physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceExternalFenceProperties(ApiDumpInstance::current(), physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceExternalFenceProperties(ApiDumpInstance::current(), physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceExternalFenceProperties(ApiDumpInstance::current(), physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceExternalSemaphoreProperties(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceExternalSemaphoreProperties", "physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties", "void");
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceExternalSemaphoreProperties(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceExternalSemaphoreProperties(ApiDumpInstance::current(), physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceExternalSemaphoreProperties(ApiDumpInstance::current(), physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceExternalSemaphoreProperties(ApiDumpInstance::current(), physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceToolProperties(VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolProperties* pToolProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceToolProperties", "physicalDevice, pToolCount, pToolProperties", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceToolProperties(physicalDevice, pToolCount, pToolProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceToolProperties(ApiDumpInstance::current(), result, physicalDevice, pToolCount, pToolProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceToolProperties(ApiDumpInstance::current(), result, physicalDevice, pToolCount, pToolProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceToolProperties(ApiDumpInstance::current(), result, physicalDevice, pToolCount, pToolProperties);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroySurfaceKHR(VkInstance instance, VkSurfaceKHR surface, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroySurfaceKHR", "instance, surface, pAllocator", "void");
    instance_dispatch_table(instance)->DestroySurfaceKHR(instance, surface, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroySurfaceKHR(ApiDumpInstance::current(), instance, surface, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroySurfaceKHR(ApiDumpInstance::current(), instance, surface, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroySurfaceKHR(ApiDumpInstance::current(), instance, surface, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfaceSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, VkSurfaceKHR surface, VkBool32* pSupported)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceSurfaceSupportKHR", "physicalDevice, queueFamilyIndex, surface, pSupported", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceSurfaceSupportKHR(physicalDevice, queueFamilyIndex, surface, pSupported);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceSurfaceSupportKHR(ApiDumpInstance::current(), result, physicalDevice, queueFamilyIndex, surface, pSupported);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceSurfaceSupportKHR(ApiDumpInstance::current(), result, physicalDevice, queueFamilyIndex, surface, pSupported);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceSurfaceSupportKHR(ApiDumpInstance::current(), result, physicalDevice, queueFamilyIndex, surface, pSupported);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfaceCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR* pSurfaceCapabilities)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceSurfaceCapabilitiesKHR", "physicalDevice, surface, pSurfaceCapabilities", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice, surface, pSurfaceCapabilities);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(ApiDumpInstance::current(), result, physicalDevice, surface, pSurfaceCapabilities);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(ApiDumpInstance::current(), result, physicalDevice, surface, pSurfaceCapabilities);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(ApiDumpInstance::current(), result, physicalDevice, surface, pSurfaceCapabilities);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfaceFormatsKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pSurfaceFormatCount, VkSurfaceFormatKHR* pSurfaceFormats)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceSurfaceFormatsKHR", "physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceSurfaceFormatsKHR(ApiDumpInstance::current(), result, physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceSurfaceFormatsKHR(ApiDumpInstance::current(), result, physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceSurfaceFormatsKHR(ApiDumpInstance::current(), result, physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfacePresentModesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceSurfacePresentModesKHR", "physicalDevice, surface, pPresentModeCount, pPresentModes", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, pPresentModeCount, pPresentModes);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceSurfacePresentModesKHR(ApiDumpInstance::current(), result, physicalDevice, surface, pPresentModeCount, pPresentModes);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceSurfacePresentModesKHR(ApiDumpInstance::current(), result, physicalDevice, surface, pPresentModeCount, pPresentModes);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceSurfacePresentModesKHR(ApiDumpInstance::current(), result, physicalDevice, surface, pPresentModeCount, pPresentModes);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDevicePresentRectanglesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pRectCount, VkRect2D* pRects)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDevicePresentRectanglesKHR", "physicalDevice, surface, pRectCount, pRects", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDevicePresentRectanglesKHR(physicalDevice, surface, pRectCount, pRects);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDevicePresentRectanglesKHR(ApiDumpInstance::current(), result, physicalDevice, surface, pRectCount, pRects);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDevicePresentRectanglesKHR(ApiDumpInstance::current(), result, physicalDevice, surface, pRectCount, pRects);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDevicePresentRectanglesKHR(ApiDumpInstance::current(), result, physicalDevice, surface, pRectCount, pRects);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceDisplayPropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPropertiesKHR* pProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceDisplayPropertiesKHR", "physicalDevice, pPropertyCount, pProperties", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceDisplayPropertiesKHR(physicalDevice, pPropertyCount, pProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceDisplayPropertiesKHR(ApiDumpInstance::current(), result, physicalDevice, pPropertyCount, pProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceDisplayPropertiesKHR(ApiDumpInstance::current(), result, physicalDevice, pPropertyCount, pProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceDisplayPropertiesKHR(ApiDumpInstance::current(), result, physicalDevice, pPropertyCount, pProperties);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceDisplayPlanePropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlanePropertiesKHR* pProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceDisplayPlanePropertiesKHR", "physicalDevice, pPropertyCount, pProperties", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice, pPropertyCount, pProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(ApiDumpInstance::current(), result, physicalDevice, pPropertyCount, pProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(ApiDumpInstance::current(), result, physicalDevice, pPropertyCount, pProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(ApiDumpInstance::current(), result, physicalDevice, pPropertyCount, pProperties);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetDisplayPlaneSupportedDisplaysKHR(VkPhysicalDevice physicalDevice, uint32_t planeIndex, uint32_t* pDisplayCount, VkDisplayKHR* pDisplays)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDisplayPlaneSupportedDisplaysKHR", "physicalDevice, planeIndex, pDisplayCount, pDisplays", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->GetDisplayPlaneSupportedDisplaysKHR(physicalDevice, planeIndex, pDisplayCount, pDisplays);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDisplayPlaneSupportedDisplaysKHR(ApiDumpInstance::current(), result, physicalDevice, planeIndex, pDisplayCount, pDisplays);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDisplayPlaneSupportedDisplaysKHR(ApiDumpInstance::current(), result, physicalDevice, planeIndex, pDisplayCount, pDisplays);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDisplayPlaneSupportedDisplaysKHR(ApiDumpInstance::current(), result, physicalDevice, planeIndex, pDisplayCount, pDisplays);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetDisplayModePropertiesKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModePropertiesKHR* pProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDisplayModePropertiesKHR", "physicalDevice, display, pPropertyCount, pProperties", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->GetDisplayModePropertiesKHR(physicalDevice, display, pPropertyCount, pProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDisplayModePropertiesKHR(ApiDumpInstance::current(), result, physicalDevice, display, pPropertyCount, pProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDisplayModePropertiesKHR(ApiDumpInstance::current(), result, physicalDevice, display, pPropertyCount, pProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDisplayModePropertiesKHR(ApiDumpInstance::current(), result, physicalDevice, display, pPropertyCount, pProperties);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDisplayModeKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, const VkDisplayModeCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDisplayModeKHR* pMode)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateDisplayModeKHR", "physicalDevice, display, pCreateInfo, pAllocator, pMode", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->CreateDisplayModeKHR(physicalDevice, display, pCreateInfo, pAllocator, pMode);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateDisplayModeKHR(ApiDumpInstance::current(), result, physicalDevice, display, pCreateInfo, pAllocator, pMode);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateDisplayModeKHR(ApiDumpInstance::current(), result, physicalDevice, display, pCreateInfo, pAllocator, pMode);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateDisplayModeKHR(ApiDumpInstance::current(), result, physicalDevice, display, pCreateInfo, pAllocator, pMode);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetDisplayPlaneCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkDisplayModeKHR mode, uint32_t planeIndex, VkDisplayPlaneCapabilitiesKHR* pCapabilities)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDisplayPlaneCapabilitiesKHR", "physicalDevice, mode, planeIndex, pCapabilities", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->GetDisplayPlaneCapabilitiesKHR(physicalDevice, mode, planeIndex, pCapabilities);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDisplayPlaneCapabilitiesKHR(ApiDumpInstance::current(), result, physicalDevice, mode, planeIndex, pCapabilities);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDisplayPlaneCapabilitiesKHR(ApiDumpInstance::current(), result, physicalDevice, mode, planeIndex, pCapabilities);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDisplayPlaneCapabilitiesKHR(ApiDumpInstance::current(), result, physicalDevice, mode, planeIndex, pCapabilities);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDisplayPlaneSurfaceKHR(VkInstance instance, const VkDisplaySurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateDisplayPlaneSurfaceKHR", "instance, pCreateInfo, pAllocator, pSurface", "VkResult");
    VkResult result = instance_dispatch_table(instance)->CreateDisplayPlaneSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateDisplayPlaneSurfaceKHR(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateDisplayPlaneSurfaceKHR(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateDisplayPlaneSurfaceKHR(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
        }
    }
    return result;
}
#if defined(VK_USE_PLATFORM_XLIB_KHR)
VKAPI_ATTR VkResult VKAPI_CALL vkCreateXlibSurfaceKHR(VkInstance instance, const VkXlibSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateXlibSurfaceKHR", "instance, pCreateInfo, pAllocator, pSurface", "VkResult");
    VkResult result = instance_dispatch_table(instance)->CreateXlibSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateXlibSurfaceKHR(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateXlibSurfaceKHR(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateXlibSurfaceKHR(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_XLIB_KHR
#if defined(VK_USE_PLATFORM_XLIB_KHR)
VKAPI_ATTR VkBool32 VKAPI_CALL vkGetPhysicalDeviceXlibPresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, Display* dpy, VisualID visualID)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceXlibPresentationSupportKHR", "physicalDevice, queueFamilyIndex, dpy, visualID", "VkBool32");
    VkBool32 result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceXlibPresentationSupportKHR(physicalDevice, queueFamilyIndex, dpy, visualID);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceXlibPresentationSupportKHR(ApiDumpInstance::current(), result, physicalDevice, queueFamilyIndex, dpy, visualID);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceXlibPresentationSupportKHR(ApiDumpInstance::current(), result, physicalDevice, queueFamilyIndex, dpy, visualID);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceXlibPresentationSupportKHR(ApiDumpInstance::current(), result, physicalDevice, queueFamilyIndex, dpy, visualID);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_XLIB_KHR
#if defined(VK_USE_PLATFORM_XCB_KHR)
VKAPI_ATTR VkResult VKAPI_CALL vkCreateXcbSurfaceKHR(VkInstance instance, const VkXcbSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateXcbSurfaceKHR", "instance, pCreateInfo, pAllocator, pSurface", "VkResult");
    VkResult result = instance_dispatch_table(instance)->CreateXcbSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateXcbSurfaceKHR(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateXcbSurfaceKHR(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateXcbSurfaceKHR(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_XCB_KHR
#if defined(VK_USE_PLATFORM_XCB_KHR)
VKAPI_ATTR VkBool32 VKAPI_CALL vkGetPhysicalDeviceXcbPresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, xcb_connection_t* connection, xcb_visualid_t visual_id)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceXcbPresentationSupportKHR", "physicalDevice, queueFamilyIndex, connection, visual_id", "VkBool32");
    VkBool32 result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceXcbPresentationSupportKHR(physicalDevice, queueFamilyIndex, connection, visual_id);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceXcbPresentationSupportKHR(ApiDumpInstance::current(), result, physicalDevice, queueFamilyIndex, connection, visual_id);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceXcbPresentationSupportKHR(ApiDumpInstance::current(), result, physicalDevice, queueFamilyIndex, connection, visual_id);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceXcbPresentationSupportKHR(ApiDumpInstance::current(), result, physicalDevice, queueFamilyIndex, connection, visual_id);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_XCB_KHR
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
VKAPI_ATTR VkResult VKAPI_CALL vkCreateWaylandSurfaceKHR(VkInstance instance, const VkWaylandSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateWaylandSurfaceKHR", "instance, pCreateInfo, pAllocator, pSurface", "VkResult");
    VkResult result = instance_dispatch_table(instance)->CreateWaylandSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateWaylandSurfaceKHR(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateWaylandSurfaceKHR(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateWaylandSurfaceKHR(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_WAYLAND_KHR
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
VKAPI_ATTR VkBool32 VKAPI_CALL vkGetPhysicalDeviceWaylandPresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct wl_display* display)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceWaylandPresentationSupportKHR", "physicalDevice, queueFamilyIndex, display", "VkBool32");
    VkBool32 result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceWaylandPresentationSupportKHR(physicalDevice, queueFamilyIndex, display);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceWaylandPresentationSupportKHR(ApiDumpInstance::current(), result, physicalDevice, queueFamilyIndex, display);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceWaylandPresentationSupportKHR(ApiDumpInstance::current(), result, physicalDevice, queueFamilyIndex, display);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceWaylandPresentationSupportKHR(ApiDumpInstance::current(), result, physicalDevice, queueFamilyIndex, display);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_WAYLAND_KHR
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
VKAPI_ATTR VkResult VKAPI_CALL vkCreateAndroidSurfaceKHR(VkInstance instance, const VkAndroidSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateAndroidSurfaceKHR", "instance, pCreateInfo, pAllocator, pSurface", "VkResult");
    VkResult result = instance_dispatch_table(instance)->CreateAndroidSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateAndroidSurfaceKHR(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateAndroidSurfaceKHR(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateAndroidSurfaceKHR(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_ANDROID_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
VKAPI_ATTR VkResult VKAPI_CALL vkCreateWin32SurfaceKHR(VkInstance instance, const VkWin32SurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateWin32SurfaceKHR", "instance, pCreateInfo, pAllocator, pSurface", "VkResult");
    VkResult result = instance_dispatch_table(instance)->CreateWin32SurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateWin32SurfaceKHR(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateWin32SurfaceKHR(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateWin32SurfaceKHR(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
VKAPI_ATTR VkBool32 VKAPI_CALL vkGetPhysicalDeviceWin32PresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceWin32PresentationSupportKHR", "physicalDevice, queueFamilyIndex", "VkBool32");
    VkBool32 result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceWin32PresentationSupportKHR(physicalDevice, queueFamilyIndex);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceWin32PresentationSupportKHR(ApiDumpInstance::current(), result, physicalDevice, queueFamilyIndex);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceWin32PresentationSupportKHR(ApiDumpInstance::current(), result, physicalDevice, queueFamilyIndex);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceWin32PresentationSupportKHR(ApiDumpInstance::current(), result, physicalDevice, queueFamilyIndex);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_WIN32_KHR
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDebugReportCallbackEXT(VkInstance instance, const VkDebugReportCallbackCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugReportCallbackEXT* pCallback)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateDebugReportCallbackEXT", "instance, pCreateInfo, pAllocator, pCallback", "VkResult");
    VkResult result = instance_dispatch_table(instance)->CreateDebugReportCallbackEXT(instance, pCreateInfo, pAllocator, pCallback);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateDebugReportCallbackEXT(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pCallback);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateDebugReportCallbackEXT(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pCallback);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateDebugReportCallbackEXT(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pCallback);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyDebugReportCallbackEXT(VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyDebugReportCallbackEXT", "instance, callback, pAllocator", "void");
    instance_dispatch_table(instance)->DestroyDebugReportCallbackEXT(instance, callback, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyDebugReportCallbackEXT(ApiDumpInstance::current(), instance, callback, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyDebugReportCallbackEXT(ApiDumpInstance::current(), instance, callback, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyDebugReportCallbackEXT(ApiDumpInstance::current(), instance, callback, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkDebugReportMessageEXT(VkInstance instance, VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, const char* pLayerPrefix, const char* pMessage)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDebugReportMessageEXT", "instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage", "void");
    instance_dispatch_table(instance)->DebugReportMessageEXT(instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDebugReportMessageEXT(ApiDumpInstance::current(), instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDebugReportMessageEXT(ApiDumpInstance::current(), instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDebugReportMessageEXT(ApiDumpInstance::current(), instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceVideoCapabilitiesKHR(VkPhysicalDevice physicalDevice, const VkVideoProfileInfoKHR* pVideoProfile, VkVideoCapabilitiesKHR* pCapabilities)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceVideoCapabilitiesKHR", "physicalDevice, pVideoProfile, pCapabilities", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceVideoCapabilitiesKHR(physicalDevice, pVideoProfile, pCapabilities);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceVideoCapabilitiesKHR(ApiDumpInstance::current(), result, physicalDevice, pVideoProfile, pCapabilities);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceVideoCapabilitiesKHR(ApiDumpInstance::current(), result, physicalDevice, pVideoProfile, pCapabilities);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceVideoCapabilitiesKHR(ApiDumpInstance::current(), result, physicalDevice, pVideoProfile, pCapabilities);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceVideoFormatPropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceVideoFormatInfoKHR* pVideoFormatInfo, uint32_t* pVideoFormatPropertyCount, VkVideoFormatPropertiesKHR* pVideoFormatProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceVideoFormatPropertiesKHR", "physicalDevice, pVideoFormatInfo, pVideoFormatPropertyCount, pVideoFormatProperties", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceVideoFormatPropertiesKHR(physicalDevice, pVideoFormatInfo, pVideoFormatPropertyCount, pVideoFormatProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceVideoFormatPropertiesKHR(ApiDumpInstance::current(), result, physicalDevice, pVideoFormatInfo, pVideoFormatPropertyCount, pVideoFormatProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceVideoFormatPropertiesKHR(ApiDumpInstance::current(), result, physicalDevice, pVideoFormatInfo, pVideoFormatPropertyCount, pVideoFormatProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceVideoFormatPropertiesKHR(ApiDumpInstance::current(), result, physicalDevice, pVideoFormatInfo, pVideoFormatPropertyCount, pVideoFormatProperties);
                break;
        }
    }
    return result;
}
#if defined(VK_USE_PLATFORM_GGP)
VKAPI_ATTR VkResult VKAPI_CALL vkCreateStreamDescriptorSurfaceGGP(VkInstance instance, const VkStreamDescriptorSurfaceCreateInfoGGP* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateStreamDescriptorSurfaceGGP", "instance, pCreateInfo, pAllocator, pSurface", "VkResult");
    VkResult result = instance_dispatch_table(instance)->CreateStreamDescriptorSurfaceGGP(instance, pCreateInfo, pAllocator, pSurface);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateStreamDescriptorSurfaceGGP(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateStreamDescriptorSurfaceGGP(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateStreamDescriptorSurfaceGGP(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_GGP
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceExternalImageFormatPropertiesNV(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkExternalMemoryHandleTypeFlagsNV externalHandleType, VkExternalImageFormatPropertiesNV* pExternalImageFormatProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceExternalImageFormatPropertiesNV", "physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceExternalImageFormatPropertiesNV(physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(ApiDumpInstance::current(), result, physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(ApiDumpInstance::current(), result, physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(ApiDumpInstance::current(), result, physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFeatures2KHR(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceFeatures2KHR", "physicalDevice, pFeatures", "void");
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceFeatures2KHR(physicalDevice, pFeatures);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceFeatures2KHR(ApiDumpInstance::current(), physicalDevice, pFeatures);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceFeatures2KHR(ApiDumpInstance::current(), physicalDevice, pFeatures);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceFeatures2KHR(ApiDumpInstance::current(), physicalDevice, pFeatures);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceProperties2KHR(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceProperties2KHR", "physicalDevice, pProperties", "void");
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceProperties2KHR(physicalDevice, pProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceProperties2KHR(ApiDumpInstance::current(), physicalDevice, pProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceProperties2KHR(ApiDumpInstance::current(), physicalDevice, pProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceProperties2KHR(ApiDumpInstance::current(), physicalDevice, pProperties);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFormatProperties2KHR(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceFormatProperties2KHR", "physicalDevice, format, pFormatProperties", "void");
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceFormatProperties2KHR(physicalDevice, format, pFormatProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceFormatProperties2KHR(ApiDumpInstance::current(), physicalDevice, format, pFormatProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceFormatProperties2KHR(ApiDumpInstance::current(), physicalDevice, format, pFormatProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceFormatProperties2KHR(ApiDumpInstance::current(), physicalDevice, format, pFormatProperties);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceImageFormatProperties2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceImageFormatProperties2KHR", "physicalDevice, pImageFormatInfo, pImageFormatProperties", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceImageFormatProperties2KHR(physicalDevice, pImageFormatInfo, pImageFormatProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceImageFormatProperties2KHR(ApiDumpInstance::current(), result, physicalDevice, pImageFormatInfo, pImageFormatProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceImageFormatProperties2KHR(ApiDumpInstance::current(), result, physicalDevice, pImageFormatInfo, pImageFormatProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceImageFormatProperties2KHR(ApiDumpInstance::current(), result, physicalDevice, pImageFormatInfo, pImageFormatProperties);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceQueueFamilyProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceQueueFamilyProperties2KHR", "physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties", "void");
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceQueueFamilyProperties2KHR(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceQueueFamilyProperties2KHR(ApiDumpInstance::current(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceQueueFamilyProperties2KHR(ApiDumpInstance::current(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceQueueFamilyProperties2KHR(ApiDumpInstance::current(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceMemoryProperties2KHR(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceMemoryProperties2KHR", "physicalDevice, pMemoryProperties", "void");
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceMemoryProperties2KHR(physicalDevice, pMemoryProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceMemoryProperties2KHR(ApiDumpInstance::current(), physicalDevice, pMemoryProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceMemoryProperties2KHR(ApiDumpInstance::current(), physicalDevice, pMemoryProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceMemoryProperties2KHR(ApiDumpInstance::current(), physicalDevice, pMemoryProperties);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceSparseImageFormatProperties2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceSparseImageFormatProperties2KHR", "physicalDevice, pFormatInfo, pPropertyCount, pProperties", "void");
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties2KHR(physicalDevice, pFormatInfo, pPropertyCount, pProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(ApiDumpInstance::current(), physicalDevice, pFormatInfo, pPropertyCount, pProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(ApiDumpInstance::current(), physicalDevice, pFormatInfo, pPropertyCount, pProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(ApiDumpInstance::current(), physicalDevice, pFormatInfo, pPropertyCount, pProperties);
                break;
        }
    }
}
#if defined(VK_USE_PLATFORM_VI_NN)
VKAPI_ATTR VkResult VKAPI_CALL vkCreateViSurfaceNN(VkInstance instance, const VkViSurfaceCreateInfoNN* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateViSurfaceNN", "instance, pCreateInfo, pAllocator, pSurface", "VkResult");
    VkResult result = instance_dispatch_table(instance)->CreateViSurfaceNN(instance, pCreateInfo, pAllocator, pSurface);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateViSurfaceNN(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateViSurfaceNN(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateViSurfaceNN(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_VI_NN
VKAPI_ATTR VkResult VKAPI_CALL vkEnumeratePhysicalDeviceGroupsKHR(VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkEnumeratePhysicalDeviceGroupsKHR", "instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties", "VkResult");
    VkResult result = instance_dispatch_table(instance)->EnumeratePhysicalDeviceGroupsKHR(instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkEnumeratePhysicalDeviceGroupsKHR(ApiDumpInstance::current(), result, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkEnumeratePhysicalDeviceGroupsKHR(ApiDumpInstance::current(), result, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkEnumeratePhysicalDeviceGroupsKHR(ApiDumpInstance::current(), result, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceExternalBufferPropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceExternalBufferPropertiesKHR", "physicalDevice, pExternalBufferInfo, pExternalBufferProperties", "void");
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceExternalBufferPropertiesKHR(physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceExternalBufferPropertiesKHR(ApiDumpInstance::current(), physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceExternalBufferPropertiesKHR(ApiDumpInstance::current(), physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceExternalBufferPropertiesKHR(ApiDumpInstance::current(), physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceExternalSemaphorePropertiesKHR", "physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties", "void");
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceExternalSemaphorePropertiesKHR(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(ApiDumpInstance::current(), physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(ApiDumpInstance::current(), physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(ApiDumpInstance::current(), physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkReleaseDisplayEXT(VkPhysicalDevice physicalDevice, VkDisplayKHR display)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkReleaseDisplayEXT", "physicalDevice, display", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->ReleaseDisplayEXT(physicalDevice, display);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkReleaseDisplayEXT(ApiDumpInstance::current(), result, physicalDevice, display);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkReleaseDisplayEXT(ApiDumpInstance::current(), result, physicalDevice, display);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkReleaseDisplayEXT(ApiDumpInstance::current(), result, physicalDevice, display);
                break;
        }
    }
    return result;
}
#if defined(VK_USE_PLATFORM_XLIB_XRANDR_EXT)
VKAPI_ATTR VkResult VKAPI_CALL vkAcquireXlibDisplayEXT(VkPhysicalDevice physicalDevice, Display* dpy, VkDisplayKHR display)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkAcquireXlibDisplayEXT", "physicalDevice, dpy, display", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->AcquireXlibDisplayEXT(physicalDevice, dpy, display);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkAcquireXlibDisplayEXT(ApiDumpInstance::current(), result, physicalDevice, dpy, display);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkAcquireXlibDisplayEXT(ApiDumpInstance::current(), result, physicalDevice, dpy, display);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkAcquireXlibDisplayEXT(ApiDumpInstance::current(), result, physicalDevice, dpy, display);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_XLIB_XRANDR_EXT
#if defined(VK_USE_PLATFORM_XLIB_XRANDR_EXT)
VKAPI_ATTR VkResult VKAPI_CALL vkGetRandROutputDisplayEXT(VkPhysicalDevice physicalDevice, Display* dpy, RROutput rrOutput, VkDisplayKHR* pDisplay)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetRandROutputDisplayEXT", "physicalDevice, dpy, rrOutput, pDisplay", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->GetRandROutputDisplayEXT(physicalDevice, dpy, rrOutput, pDisplay);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetRandROutputDisplayEXT(ApiDumpInstance::current(), result, physicalDevice, dpy, rrOutput, pDisplay);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetRandROutputDisplayEXT(ApiDumpInstance::current(), result, physicalDevice, dpy, rrOutput, pDisplay);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetRandROutputDisplayEXT(ApiDumpInstance::current(), result, physicalDevice, dpy, rrOutput, pDisplay);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_XLIB_XRANDR_EXT
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfaceCapabilities2EXT(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilities2EXT* pSurfaceCapabilities)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceSurfaceCapabilities2EXT", "physicalDevice, surface, pSurfaceCapabilities", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice, surface, pSurfaceCapabilities);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceSurfaceCapabilities2EXT(ApiDumpInstance::current(), result, physicalDevice, surface, pSurfaceCapabilities);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceSurfaceCapabilities2EXT(ApiDumpInstance::current(), result, physicalDevice, surface, pSurfaceCapabilities);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceSurfaceCapabilities2EXT(ApiDumpInstance::current(), result, physicalDevice, surface, pSurfaceCapabilities);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceExternalFencePropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceExternalFencePropertiesKHR", "physicalDevice, pExternalFenceInfo, pExternalFenceProperties", "void");
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceExternalFencePropertiesKHR(physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceExternalFencePropertiesKHR(ApiDumpInstance::current(), physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceExternalFencePropertiesKHR(ApiDumpInstance::current(), physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceExternalFencePropertiesKHR(ApiDumpInstance::current(), physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t* pCounterCount, VkPerformanceCounterKHR* pCounters, VkPerformanceCounterDescriptionKHR* pCounterDescriptions)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR", "physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(ApiDumpInstance::current(), result, physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(ApiDumpInstance::current(), result, physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(ApiDumpInstance::current(), result, physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(VkPhysicalDevice physicalDevice, const VkQueryPoolPerformanceCreateInfoKHR* pPerformanceQueryCreateInfo, uint32_t* pNumPasses)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR", "physicalDevice, pPerformanceQueryCreateInfo, pNumPasses", "void");
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(physicalDevice, pPerformanceQueryCreateInfo, pNumPasses);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(ApiDumpInstance::current(), physicalDevice, pPerformanceQueryCreateInfo, pNumPasses);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(ApiDumpInstance::current(), physicalDevice, pPerformanceQueryCreateInfo, pNumPasses);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(ApiDumpInstance::current(), physicalDevice, pPerformanceQueryCreateInfo, pNumPasses);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfaceCapabilities2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkSurfaceCapabilities2KHR* pSurfaceCapabilities)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceSurfaceCapabilities2KHR", "physicalDevice, pSurfaceInfo, pSurfaceCapabilities", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceSurfaceCapabilities2KHR(physicalDevice, pSurfaceInfo, pSurfaceCapabilities);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceSurfaceCapabilities2KHR(ApiDumpInstance::current(), result, physicalDevice, pSurfaceInfo, pSurfaceCapabilities);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceSurfaceCapabilities2KHR(ApiDumpInstance::current(), result, physicalDevice, pSurfaceInfo, pSurfaceCapabilities);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceSurfaceCapabilities2KHR(ApiDumpInstance::current(), result, physicalDevice, pSurfaceInfo, pSurfaceCapabilities);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfaceFormats2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pSurfaceFormatCount, VkSurfaceFormat2KHR* pSurfaceFormats)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceSurfaceFormats2KHR", "physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceSurfaceFormats2KHR(physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceSurfaceFormats2KHR(ApiDumpInstance::current(), result, physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceSurfaceFormats2KHR(ApiDumpInstance::current(), result, physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceSurfaceFormats2KHR(ApiDumpInstance::current(), result, physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceDisplayProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayProperties2KHR* pProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceDisplayProperties2KHR", "physicalDevice, pPropertyCount, pProperties", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceDisplayProperties2KHR(physicalDevice, pPropertyCount, pProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceDisplayProperties2KHR(ApiDumpInstance::current(), result, physicalDevice, pPropertyCount, pProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceDisplayProperties2KHR(ApiDumpInstance::current(), result, physicalDevice, pPropertyCount, pProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceDisplayProperties2KHR(ApiDumpInstance::current(), result, physicalDevice, pPropertyCount, pProperties);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceDisplayPlaneProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlaneProperties2KHR* pProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceDisplayPlaneProperties2KHR", "physicalDevice, pPropertyCount, pProperties", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceDisplayPlaneProperties2KHR(physicalDevice, pPropertyCount, pProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(ApiDumpInstance::current(), result, physicalDevice, pPropertyCount, pProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(ApiDumpInstance::current(), result, physicalDevice, pPropertyCount, pProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(ApiDumpInstance::current(), result, physicalDevice, pPropertyCount, pProperties);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetDisplayModeProperties2KHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModeProperties2KHR* pProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDisplayModeProperties2KHR", "physicalDevice, display, pPropertyCount, pProperties", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->GetDisplayModeProperties2KHR(physicalDevice, display, pPropertyCount, pProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDisplayModeProperties2KHR(ApiDumpInstance::current(), result, physicalDevice, display, pPropertyCount, pProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDisplayModeProperties2KHR(ApiDumpInstance::current(), result, physicalDevice, display, pPropertyCount, pProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDisplayModeProperties2KHR(ApiDumpInstance::current(), result, physicalDevice, display, pPropertyCount, pProperties);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetDisplayPlaneCapabilities2KHR(VkPhysicalDevice physicalDevice, const VkDisplayPlaneInfo2KHR* pDisplayPlaneInfo, VkDisplayPlaneCapabilities2KHR* pCapabilities)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDisplayPlaneCapabilities2KHR", "physicalDevice, pDisplayPlaneInfo, pCapabilities", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->GetDisplayPlaneCapabilities2KHR(physicalDevice, pDisplayPlaneInfo, pCapabilities);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDisplayPlaneCapabilities2KHR(ApiDumpInstance::current(), result, physicalDevice, pDisplayPlaneInfo, pCapabilities);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDisplayPlaneCapabilities2KHR(ApiDumpInstance::current(), result, physicalDevice, pDisplayPlaneInfo, pCapabilities);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDisplayPlaneCapabilities2KHR(ApiDumpInstance::current(), result, physicalDevice, pDisplayPlaneInfo, pCapabilities);
                break;
        }
    }
    return result;
}
#if defined(VK_USE_PLATFORM_IOS_MVK)
VKAPI_ATTR VkResult VKAPI_CALL vkCreateIOSSurfaceMVK(VkInstance instance, const VkIOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateIOSSurfaceMVK", "instance, pCreateInfo, pAllocator, pSurface", "VkResult");
    VkResult result = instance_dispatch_table(instance)->CreateIOSSurfaceMVK(instance, pCreateInfo, pAllocator, pSurface);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateIOSSurfaceMVK(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateIOSSurfaceMVK(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateIOSSurfaceMVK(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_IOS_MVK
#if defined(VK_USE_PLATFORM_MACOS_MVK)
VKAPI_ATTR VkResult VKAPI_CALL vkCreateMacOSSurfaceMVK(VkInstance instance, const VkMacOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateMacOSSurfaceMVK", "instance, pCreateInfo, pAllocator, pSurface", "VkResult");
    VkResult result = instance_dispatch_table(instance)->CreateMacOSSurfaceMVK(instance, pCreateInfo, pAllocator, pSurface);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateMacOSSurfaceMVK(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateMacOSSurfaceMVK(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateMacOSSurfaceMVK(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_MACOS_MVK
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pMessenger)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateDebugUtilsMessengerEXT", "instance, pCreateInfo, pAllocator, pMessenger", "VkResult");
    VkResult result = instance_dispatch_table(instance)->CreateDebugUtilsMessengerEXT(instance, pCreateInfo, pAllocator, pMessenger);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateDebugUtilsMessengerEXT(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pMessenger);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateDebugUtilsMessengerEXT(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pMessenger);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateDebugUtilsMessengerEXT(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pMessenger);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT messenger, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyDebugUtilsMessengerEXT", "instance, messenger, pAllocator", "void");
    instance_dispatch_table(instance)->DestroyDebugUtilsMessengerEXT(instance, messenger, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyDebugUtilsMessengerEXT(ApiDumpInstance::current(), instance, messenger, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyDebugUtilsMessengerEXT(ApiDumpInstance::current(), instance, messenger, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyDebugUtilsMessengerEXT(ApiDumpInstance::current(), instance, messenger, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkSubmitDebugUtilsMessageEXT(VkInstance instance, VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageTypes, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkSubmitDebugUtilsMessageEXT", "instance, messageSeverity, messageTypes, pCallbackData", "void");
    instance_dispatch_table(instance)->SubmitDebugUtilsMessageEXT(instance, messageSeverity, messageTypes, pCallbackData);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkSubmitDebugUtilsMessageEXT(ApiDumpInstance::current(), instance, messageSeverity, messageTypes, pCallbackData);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkSubmitDebugUtilsMessageEXT(ApiDumpInstance::current(), instance, messageSeverity, messageTypes, pCallbackData);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkSubmitDebugUtilsMessageEXT(ApiDumpInstance::current(), instance, messageSeverity, messageTypes, pCallbackData);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceMultisamplePropertiesEXT(VkPhysicalDevice physicalDevice, VkSampleCountFlagBits samples, VkMultisamplePropertiesEXT* pMultisampleProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceMultisamplePropertiesEXT", "physicalDevice, samples, pMultisampleProperties", "void");
    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceMultisamplePropertiesEXT(physicalDevice, samples, pMultisampleProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceMultisamplePropertiesEXT(ApiDumpInstance::current(), physicalDevice, samples, pMultisampleProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceMultisamplePropertiesEXT(ApiDumpInstance::current(), physicalDevice, samples, pMultisampleProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceMultisamplePropertiesEXT(ApiDumpInstance::current(), physicalDevice, samples, pMultisampleProperties);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceCalibrateableTimeDomainsKHR(VkPhysicalDevice physicalDevice, uint32_t* pTimeDomainCount, VkTimeDomainKHR* pTimeDomains)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceCalibrateableTimeDomainsKHR", "physicalDevice, pTimeDomainCount, pTimeDomains", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceCalibrateableTimeDomainsKHR(physicalDevice, pTimeDomainCount, pTimeDomains);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR(ApiDumpInstance::current(), result, physicalDevice, pTimeDomainCount, pTimeDomains);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR(ApiDumpInstance::current(), result, physicalDevice, pTimeDomainCount, pTimeDomains);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR(ApiDumpInstance::current(), result, physicalDevice, pTimeDomainCount, pTimeDomains);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(VkPhysicalDevice physicalDevice, uint32_t* pTimeDomainCount, VkTimeDomainKHR* pTimeDomains)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceCalibrateableTimeDomainsEXT", "physicalDevice, pTimeDomainCount, pTimeDomains", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceCalibrateableTimeDomainsEXT(physicalDevice, pTimeDomainCount, pTimeDomains);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(ApiDumpInstance::current(), result, physicalDevice, pTimeDomainCount, pTimeDomains);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(ApiDumpInstance::current(), result, physicalDevice, pTimeDomainCount, pTimeDomains);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(ApiDumpInstance::current(), result, physicalDevice, pTimeDomainCount, pTimeDomains);
                break;
        }
    }
    return result;
}
#if defined(VK_USE_PLATFORM_FUCHSIA)
VKAPI_ATTR VkResult VKAPI_CALL vkCreateImagePipeSurfaceFUCHSIA(VkInstance instance, const VkImagePipeSurfaceCreateInfoFUCHSIA* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateImagePipeSurfaceFUCHSIA", "instance, pCreateInfo, pAllocator, pSurface", "VkResult");
    VkResult result = instance_dispatch_table(instance)->CreateImagePipeSurfaceFUCHSIA(instance, pCreateInfo, pAllocator, pSurface);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateImagePipeSurfaceFUCHSIA(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateImagePipeSurfaceFUCHSIA(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateImagePipeSurfaceFUCHSIA(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_FUCHSIA
#if defined(VK_USE_PLATFORM_METAL_EXT)
VKAPI_ATTR VkResult VKAPI_CALL vkCreateMetalSurfaceEXT(VkInstance instance, const VkMetalSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateMetalSurfaceEXT", "instance, pCreateInfo, pAllocator, pSurface", "VkResult");
    VkResult result = instance_dispatch_table(instance)->CreateMetalSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateMetalSurfaceEXT(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateMetalSurfaceEXT(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateMetalSurfaceEXT(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_METAL_EXT
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceFragmentShadingRatesKHR(VkPhysicalDevice physicalDevice, uint32_t* pFragmentShadingRateCount, VkPhysicalDeviceFragmentShadingRateKHR* pFragmentShadingRates)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceFragmentShadingRatesKHR", "physicalDevice, pFragmentShadingRateCount, pFragmentShadingRates", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceFragmentShadingRatesKHR(physicalDevice, pFragmentShadingRateCount, pFragmentShadingRates);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceFragmentShadingRatesKHR(ApiDumpInstance::current(), result, physicalDevice, pFragmentShadingRateCount, pFragmentShadingRates);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceFragmentShadingRatesKHR(ApiDumpInstance::current(), result, physicalDevice, pFragmentShadingRateCount, pFragmentShadingRates);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceFragmentShadingRatesKHR(ApiDumpInstance::current(), result, physicalDevice, pFragmentShadingRateCount, pFragmentShadingRates);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceToolPropertiesEXT(VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolProperties* pToolProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceToolPropertiesEXT", "physicalDevice, pToolCount, pToolProperties", "VkResult");
    static const VkPhysicalDeviceToolPropertiesEXT api_dump_layer_tool_props = {
        VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES_EXT,
        nullptr,
        "API Dump Layer",
        "2",
        VK_TOOL_PURPOSE_PROFILING_BIT_EXT | VK_TOOL_PURPOSE_TRACING_BIT_EXT,
        "The VK_LAYER_LUNARG_api_dump utility layer prints API calls, parameters, and values to the identified output stream.",
        "VK_LAYER_LUNARG_api_dump"};

    auto original_pToolProperties = pToolProperties;
    if (pToolProperties != nullptr) {
        *pToolProperties = api_dump_layer_tool_props;
        pToolProperties = ((*pToolCount > 1) ? &pToolProperties[1] : nullptr);
        (*pToolCount)--;
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceToolPropertiesEXT(physicalDevice, pToolCount, pToolProperties);
    
    if (original_pToolProperties != nullptr) {
        pToolProperties = original_pToolProperties;
    }

    (*pToolCount)++;
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceToolPropertiesEXT(ApiDumpInstance::current(), result, physicalDevice, pToolCount, pToolProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceToolPropertiesEXT(ApiDumpInstance::current(), result, physicalDevice, pToolCount, pToolProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceToolPropertiesEXT(ApiDumpInstance::current(), result, physicalDevice, pToolCount, pToolProperties);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkCooperativeMatrixPropertiesNV* pProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceCooperativeMatrixPropertiesNV", "physicalDevice, pPropertyCount, pProperties", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceCooperativeMatrixPropertiesNV(physicalDevice, pPropertyCount, pProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(ApiDumpInstance::current(), result, physicalDevice, pPropertyCount, pProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(ApiDumpInstance::current(), result, physicalDevice, pPropertyCount, pProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(ApiDumpInstance::current(), result, physicalDevice, pPropertyCount, pProperties);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(VkPhysicalDevice physicalDevice, uint32_t* pCombinationCount, VkFramebufferMixedSamplesCombinationNV* pCombinations)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV", "physicalDevice, pCombinationCount, pCombinations", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(physicalDevice, pCombinationCount, pCombinations);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(ApiDumpInstance::current(), result, physicalDevice, pCombinationCount, pCombinations);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(ApiDumpInstance::current(), result, physicalDevice, pCombinationCount, pCombinations);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(ApiDumpInstance::current(), result, physicalDevice, pCombinationCount, pCombinations);
                break;
        }
    }
    return result;
}
#if defined(VK_USE_PLATFORM_WIN32_KHR)
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfacePresentModes2EXT(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceSurfacePresentModes2EXT", "physicalDevice, pSurfaceInfo, pPresentModeCount, pPresentModes", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceSurfacePresentModes2EXT(physicalDevice, pSurfaceInfo, pPresentModeCount, pPresentModes);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceSurfacePresentModes2EXT(ApiDumpInstance::current(), result, physicalDevice, pSurfaceInfo, pPresentModeCount, pPresentModes);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceSurfacePresentModes2EXT(ApiDumpInstance::current(), result, physicalDevice, pSurfaceInfo, pPresentModeCount, pPresentModes);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceSurfacePresentModes2EXT(ApiDumpInstance::current(), result, physicalDevice, pSurfaceInfo, pPresentModeCount, pPresentModes);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_WIN32_KHR
VKAPI_ATTR VkResult VKAPI_CALL vkCreateHeadlessSurfaceEXT(VkInstance instance, const VkHeadlessSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateHeadlessSurfaceEXT", "instance, pCreateInfo, pAllocator, pSurface", "VkResult");
    VkResult result = instance_dispatch_table(instance)->CreateHeadlessSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateHeadlessSurfaceEXT(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateHeadlessSurfaceEXT(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateHeadlessSurfaceEXT(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkAcquireDrmDisplayEXT(VkPhysicalDevice physicalDevice, int32_t drmFd, VkDisplayKHR display)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkAcquireDrmDisplayEXT", "physicalDevice, drmFd, display", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->AcquireDrmDisplayEXT(physicalDevice, drmFd, display);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkAcquireDrmDisplayEXT(ApiDumpInstance::current(), result, physicalDevice, drmFd, display);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkAcquireDrmDisplayEXT(ApiDumpInstance::current(), result, physicalDevice, drmFd, display);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkAcquireDrmDisplayEXT(ApiDumpInstance::current(), result, physicalDevice, drmFd, display);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetDrmDisplayEXT(VkPhysicalDevice physicalDevice, int32_t drmFd, uint32_t connectorId, VkDisplayKHR* display)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDrmDisplayEXT", "physicalDevice, drmFd, connectorId, display", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->GetDrmDisplayEXT(physicalDevice, drmFd, connectorId, display);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDrmDisplayEXT(ApiDumpInstance::current(), result, physicalDevice, drmFd, connectorId, display);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDrmDisplayEXT(ApiDumpInstance::current(), result, physicalDevice, drmFd, connectorId, display);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDrmDisplayEXT(ApiDumpInstance::current(), result, physicalDevice, drmFd, connectorId, display);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR* pQualityLevelInfo, VkVideoEncodeQualityLevelPropertiesKHR* pQualityLevelProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR", "physicalDevice, pQualityLevelInfo, pQualityLevelProperties", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(physicalDevice, pQualityLevelInfo, pQualityLevelProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(ApiDumpInstance::current(), result, physicalDevice, pQualityLevelInfo, pQualityLevelProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(ApiDumpInstance::current(), result, physicalDevice, pQualityLevelInfo, pQualityLevelProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(ApiDumpInstance::current(), result, physicalDevice, pQualityLevelInfo, pQualityLevelProperties);
                break;
        }
    }
    return result;
}
#if defined(VK_USE_PLATFORM_WIN32_KHR)
VKAPI_ATTR VkResult VKAPI_CALL vkAcquireWinrtDisplayNV(VkPhysicalDevice physicalDevice, VkDisplayKHR display)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkAcquireWinrtDisplayNV", "physicalDevice, display", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->AcquireWinrtDisplayNV(physicalDevice, display);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkAcquireWinrtDisplayNV(ApiDumpInstance::current(), result, physicalDevice, display);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkAcquireWinrtDisplayNV(ApiDumpInstance::current(), result, physicalDevice, display);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkAcquireWinrtDisplayNV(ApiDumpInstance::current(), result, physicalDevice, display);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
VKAPI_ATTR VkResult VKAPI_CALL vkGetWinrtDisplayNV(VkPhysicalDevice physicalDevice, uint32_t deviceRelativeId, VkDisplayKHR* pDisplay)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetWinrtDisplayNV", "physicalDevice, deviceRelativeId, pDisplay", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->GetWinrtDisplayNV(physicalDevice, deviceRelativeId, pDisplay);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetWinrtDisplayNV(ApiDumpInstance::current(), result, physicalDevice, deviceRelativeId, pDisplay);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetWinrtDisplayNV(ApiDumpInstance::current(), result, physicalDevice, deviceRelativeId, pDisplay);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetWinrtDisplayNV(ApiDumpInstance::current(), result, physicalDevice, deviceRelativeId, pDisplay);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_DIRECTFB_EXT)
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDirectFBSurfaceEXT(VkInstance instance, const VkDirectFBSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateDirectFBSurfaceEXT", "instance, pCreateInfo, pAllocator, pSurface", "VkResult");
    VkResult result = instance_dispatch_table(instance)->CreateDirectFBSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateDirectFBSurfaceEXT(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateDirectFBSurfaceEXT(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateDirectFBSurfaceEXT(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_DIRECTFB_EXT
#if defined(VK_USE_PLATFORM_DIRECTFB_EXT)
VKAPI_ATTR VkBool32 VKAPI_CALL vkGetPhysicalDeviceDirectFBPresentationSupportEXT(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, IDirectFB* dfb)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceDirectFBPresentationSupportEXT", "physicalDevice, queueFamilyIndex, dfb", "VkBool32");
    VkBool32 result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceDirectFBPresentationSupportEXT(physicalDevice, queueFamilyIndex, dfb);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(ApiDumpInstance::current(), result, physicalDevice, queueFamilyIndex, dfb);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(ApiDumpInstance::current(), result, physicalDevice, queueFamilyIndex, dfb);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(ApiDumpInstance::current(), result, physicalDevice, queueFamilyIndex, dfb);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_DIRECTFB_EXT
#if defined(VK_USE_PLATFORM_SCREEN_QNX)
VKAPI_ATTR VkResult VKAPI_CALL vkCreateScreenSurfaceQNX(VkInstance instance, const VkScreenSurfaceCreateInfoQNX* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateScreenSurfaceQNX", "instance, pCreateInfo, pAllocator, pSurface", "VkResult");
    VkResult result = instance_dispatch_table(instance)->CreateScreenSurfaceQNX(instance, pCreateInfo, pAllocator, pSurface);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateScreenSurfaceQNX(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateScreenSurfaceQNX(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateScreenSurfaceQNX(ApiDumpInstance::current(), result, instance, pCreateInfo, pAllocator, pSurface);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_SCREEN_QNX
#if defined(VK_USE_PLATFORM_SCREEN_QNX)
VKAPI_ATTR VkBool32 VKAPI_CALL vkGetPhysicalDeviceScreenPresentationSupportQNX(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct _screen_window* window)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceScreenPresentationSupportQNX", "physicalDevice, queueFamilyIndex, window", "VkBool32");
    VkBool32 result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceScreenPresentationSupportQNX(physicalDevice, queueFamilyIndex, window);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceScreenPresentationSupportQNX(ApiDumpInstance::current(), result, physicalDevice, queueFamilyIndex, window);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceScreenPresentationSupportQNX(ApiDumpInstance::current(), result, physicalDevice, queueFamilyIndex, window);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceScreenPresentationSupportQNX(ApiDumpInstance::current(), result, physicalDevice, queueFamilyIndex, window);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_SCREEN_QNX
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceOpticalFlowImageFormatsNV(VkPhysicalDevice physicalDevice, const VkOpticalFlowImageFormatInfoNV* pOpticalFlowImageFormatInfo, uint32_t* pFormatCount, VkOpticalFlowImageFormatPropertiesNV* pImageFormatProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceOpticalFlowImageFormatsNV", "physicalDevice, pOpticalFlowImageFormatInfo, pFormatCount, pImageFormatProperties", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceOpticalFlowImageFormatsNV(physicalDevice, pOpticalFlowImageFormatInfo, pFormatCount, pImageFormatProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceOpticalFlowImageFormatsNV(ApiDumpInstance::current(), result, physicalDevice, pOpticalFlowImageFormatInfo, pFormatCount, pImageFormatProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceOpticalFlowImageFormatsNV(ApiDumpInstance::current(), result, physicalDevice, pOpticalFlowImageFormatInfo, pFormatCount, pImageFormatProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceOpticalFlowImageFormatsNV(ApiDumpInstance::current(), result, physicalDevice, pOpticalFlowImageFormatInfo, pFormatCount, pImageFormatProperties);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkCooperativeMatrixPropertiesKHR* pProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR", "physicalDevice, pPropertyCount, pProperties", "VkResult");
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceCooperativeMatrixPropertiesKHR(physicalDevice, pPropertyCount, pProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR(ApiDumpInstance::current(), result, physicalDevice, pPropertyCount, pProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR(ApiDumpInstance::current(), result, physicalDevice, pPropertyCount, pProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR(ApiDumpInstance::current(), result, physicalDevice, pPropertyCount, pProperties);
                break;
        }
    }
    return result;
}

// Autogen device functions

VKAPI_ATTR void VKAPI_CALL vkDestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyDevice", "device, pAllocator", "void");
    device_dispatch_table(device)->DestroyDevice(device, pAllocator);
    
    destroy_device_dispatch_table(get_dispatch_key(device));
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyDevice(ApiDumpInstance::current(), device, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyDevice(ApiDumpInstance::current(), device, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyDevice(ApiDumpInstance::current(), device, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDeviceQueue", "device, queueFamilyIndex, queueIndex, pQueue", "void");
    device_dispatch_table(device)->GetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDeviceQueue(ApiDumpInstance::current(), device, queueFamilyIndex, queueIndex, pQueue);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDeviceQueue(ApiDumpInstance::current(), device, queueFamilyIndex, queueIndex, pQueue);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDeviceQueue(ApiDumpInstance::current(), device, queueFamilyIndex, queueIndex, pQueue);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkQueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkQueueSubmit", "queue, submitCount, pSubmits, fence", "VkResult");
    VkResult result = device_dispatch_table(queue)->QueueSubmit(queue, submitCount, pSubmits, fence);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkQueueSubmit(ApiDumpInstance::current(), result, queue, submitCount, pSubmits, fence);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkQueueSubmit(ApiDumpInstance::current(), result, queue, submitCount, pSubmits, fence);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkQueueSubmit(ApiDumpInstance::current(), result, queue, submitCount, pSubmits, fence);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkQueueWaitIdle(VkQueue queue)
{
    VkResult result = device_dispatch_table(queue)->QueueWaitIdle(queue);
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkQueueWaitIdle", "queue", "VkResult");
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkQueueWaitIdle(ApiDumpInstance::current(), result, queue);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkQueueWaitIdle(ApiDumpInstance::current(), result, queue);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkQueueWaitIdle(ApiDumpInstance::current(), result, queue);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkDeviceWaitIdle(VkDevice device)
{
    VkResult result = device_dispatch_table(device)->DeviceWaitIdle(device);
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDeviceWaitIdle", "device", "VkResult");
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDeviceWaitIdle(ApiDumpInstance::current(), result, device);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDeviceWaitIdle(ApiDumpInstance::current(), result, device);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDeviceWaitIdle(ApiDumpInstance::current(), result, device);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkAllocateMemory(VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo, const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkAllocateMemory", "device, pAllocateInfo, pAllocator, pMemory", "VkResult");
    VkResult result = device_dispatch_table(device)->AllocateMemory(device, pAllocateInfo, pAllocator, pMemory);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkAllocateMemory(ApiDumpInstance::current(), result, device, pAllocateInfo, pAllocator, pMemory);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkAllocateMemory(ApiDumpInstance::current(), result, device, pAllocateInfo, pAllocator, pMemory);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkAllocateMemory(ApiDumpInstance::current(), result, device, pAllocateInfo, pAllocator, pMemory);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkFreeMemory(VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkFreeMemory", "device, memory, pAllocator", "void");
    device_dispatch_table(device)->FreeMemory(device, memory, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkFreeMemory(ApiDumpInstance::current(), device, memory, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkFreeMemory(ApiDumpInstance::current(), device, memory, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkFreeMemory(ApiDumpInstance::current(), device, memory, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkMapMemory(VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkMapMemory", "device, memory, offset, size, flags, ppData", "VkResult");
    VkResult result = device_dispatch_table(device)->MapMemory(device, memory, offset, size, flags, ppData);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkMapMemory(ApiDumpInstance::current(), result, device, memory, offset, size, flags, ppData);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkMapMemory(ApiDumpInstance::current(), result, device, memory, offset, size, flags, ppData);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkMapMemory(ApiDumpInstance::current(), result, device, memory, offset, size, flags, ppData);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkUnmapMemory(VkDevice device, VkDeviceMemory memory)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkUnmapMemory", "device, memory", "void");
    device_dispatch_table(device)->UnmapMemory(device, memory);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkUnmapMemory(ApiDumpInstance::current(), device, memory);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkUnmapMemory(ApiDumpInstance::current(), device, memory);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkUnmapMemory(ApiDumpInstance::current(), device, memory);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkFlushMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkFlushMappedMemoryRanges", "device, memoryRangeCount, pMemoryRanges", "VkResult");
    VkResult result = device_dispatch_table(device)->FlushMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkFlushMappedMemoryRanges(ApiDumpInstance::current(), result, device, memoryRangeCount, pMemoryRanges);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkFlushMappedMemoryRanges(ApiDumpInstance::current(), result, device, memoryRangeCount, pMemoryRanges);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkFlushMappedMemoryRanges(ApiDumpInstance::current(), result, device, memoryRangeCount, pMemoryRanges);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkInvalidateMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkInvalidateMappedMemoryRanges", "device, memoryRangeCount, pMemoryRanges", "VkResult");
    VkResult result = device_dispatch_table(device)->InvalidateMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkInvalidateMappedMemoryRanges(ApiDumpInstance::current(), result, device, memoryRangeCount, pMemoryRanges);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkInvalidateMappedMemoryRanges(ApiDumpInstance::current(), result, device, memoryRangeCount, pMemoryRanges);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkInvalidateMappedMemoryRanges(ApiDumpInstance::current(), result, device, memoryRangeCount, pMemoryRanges);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetDeviceMemoryCommitment(VkDevice device, VkDeviceMemory memory, VkDeviceSize* pCommittedMemoryInBytes)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDeviceMemoryCommitment", "device, memory, pCommittedMemoryInBytes", "void");
    device_dispatch_table(device)->GetDeviceMemoryCommitment(device, memory, pCommittedMemoryInBytes);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDeviceMemoryCommitment(ApiDumpInstance::current(), device, memory, pCommittedMemoryInBytes);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDeviceMemoryCommitment(ApiDumpInstance::current(), device, memory, pCommittedMemoryInBytes);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDeviceMemoryCommitment(ApiDumpInstance::current(), device, memory, pCommittedMemoryInBytes);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkBindBufferMemory(VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkBindBufferMemory", "device, buffer, memory, memoryOffset", "VkResult");
    VkResult result = device_dispatch_table(device)->BindBufferMemory(device, buffer, memory, memoryOffset);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkBindBufferMemory(ApiDumpInstance::current(), result, device, buffer, memory, memoryOffset);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkBindBufferMemory(ApiDumpInstance::current(), result, device, buffer, memory, memoryOffset);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkBindBufferMemory(ApiDumpInstance::current(), result, device, buffer, memory, memoryOffset);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkBindImageMemory(VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkBindImageMemory", "device, image, memory, memoryOffset", "VkResult");
    VkResult result = device_dispatch_table(device)->BindImageMemory(device, image, memory, memoryOffset);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkBindImageMemory(ApiDumpInstance::current(), result, device, image, memory, memoryOffset);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkBindImageMemory(ApiDumpInstance::current(), result, device, image, memory, memoryOffset);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkBindImageMemory(ApiDumpInstance::current(), result, device, image, memory, memoryOffset);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetBufferMemoryRequirements(VkDevice device, VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetBufferMemoryRequirements", "device, buffer, pMemoryRequirements", "void");
    device_dispatch_table(device)->GetBufferMemoryRequirements(device, buffer, pMemoryRequirements);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetBufferMemoryRequirements(ApiDumpInstance::current(), device, buffer, pMemoryRequirements);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetBufferMemoryRequirements(ApiDumpInstance::current(), device, buffer, pMemoryRequirements);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetBufferMemoryRequirements(ApiDumpInstance::current(), device, buffer, pMemoryRequirements);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetImageMemoryRequirements(VkDevice device, VkImage image, VkMemoryRequirements* pMemoryRequirements)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetImageMemoryRequirements", "device, image, pMemoryRequirements", "void");
    device_dispatch_table(device)->GetImageMemoryRequirements(device, image, pMemoryRequirements);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetImageMemoryRequirements(ApiDumpInstance::current(), device, image, pMemoryRequirements);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetImageMemoryRequirements(ApiDumpInstance::current(), device, image, pMemoryRequirements);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetImageMemoryRequirements(ApiDumpInstance::current(), device, image, pMemoryRequirements);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetImageSparseMemoryRequirements(VkDevice device, VkImage image, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements* pSparseMemoryRequirements)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetImageSparseMemoryRequirements", "device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements", "void");
    device_dispatch_table(device)->GetImageSparseMemoryRequirements(device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetImageSparseMemoryRequirements(ApiDumpInstance::current(), device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetImageSparseMemoryRequirements(ApiDumpInstance::current(), device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetImageSparseMemoryRequirements(ApiDumpInstance::current(), device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkQueueBindSparse(VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence fence)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkQueueBindSparse", "queue, bindInfoCount, pBindInfo, fence", "VkResult");
    VkResult result = device_dispatch_table(queue)->QueueBindSparse(queue, bindInfoCount, pBindInfo, fence);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkQueueBindSparse(ApiDumpInstance::current(), result, queue, bindInfoCount, pBindInfo, fence);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkQueueBindSparse(ApiDumpInstance::current(), result, queue, bindInfoCount, pBindInfo, fence);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkQueueBindSparse(ApiDumpInstance::current(), result, queue, bindInfoCount, pBindInfo, fence);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateFence(VkDevice device, const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateFence", "device, pCreateInfo, pAllocator, pFence", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateFence(device, pCreateInfo, pAllocator, pFence);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateFence(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pFence);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateFence(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pFence);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateFence(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pFence);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyFence(VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyFence", "device, fence, pAllocator", "void");
    device_dispatch_table(device)->DestroyFence(device, fence, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyFence(ApiDumpInstance::current(), device, fence, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyFence(ApiDumpInstance::current(), device, fence, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyFence(ApiDumpInstance::current(), device, fence, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkResetFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkResetFences", "device, fenceCount, pFences", "VkResult");
    VkResult result = device_dispatch_table(device)->ResetFences(device, fenceCount, pFences);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkResetFences(ApiDumpInstance::current(), result, device, fenceCount, pFences);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkResetFences(ApiDumpInstance::current(), result, device, fenceCount, pFences);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkResetFences(ApiDumpInstance::current(), result, device, fenceCount, pFences);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetFenceStatus(VkDevice device, VkFence fence)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetFenceStatus", "device, fence", "VkResult");
    VkResult result = device_dispatch_table(device)->GetFenceStatus(device, fence);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetFenceStatus(ApiDumpInstance::current(), result, device, fence);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetFenceStatus(ApiDumpInstance::current(), result, device, fence);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetFenceStatus(ApiDumpInstance::current(), result, device, fence);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkWaitForFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout)
{
    VkResult result = device_dispatch_table(device)->WaitForFences(device, fenceCount, pFences, waitAll, timeout);
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkWaitForFences", "device, fenceCount, pFences, waitAll, timeout", "VkResult");
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkWaitForFences(ApiDumpInstance::current(), result, device, fenceCount, pFences, waitAll, timeout);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkWaitForFences(ApiDumpInstance::current(), result, device, fenceCount, pFences, waitAll, timeout);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkWaitForFences(ApiDumpInstance::current(), result, device, fenceCount, pFences, waitAll, timeout);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateSemaphore", "device, pCreateInfo, pAllocator, pSemaphore", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateSemaphore(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pSemaphore);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateSemaphore(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pSemaphore);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateSemaphore(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pSemaphore);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroySemaphore", "device, semaphore, pAllocator", "void");
    device_dispatch_table(device)->DestroySemaphore(device, semaphore, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroySemaphore(ApiDumpInstance::current(), device, semaphore, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroySemaphore(ApiDumpInstance::current(), device, semaphore, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroySemaphore(ApiDumpInstance::current(), device, semaphore, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateEvent(VkDevice device, const VkEventCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkEvent* pEvent)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateEvent", "device, pCreateInfo, pAllocator, pEvent", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateEvent(device, pCreateInfo, pAllocator, pEvent);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateEvent(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pEvent);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateEvent(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pEvent);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateEvent(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pEvent);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyEvent(VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyEvent", "device, event, pAllocator", "void");
    device_dispatch_table(device)->DestroyEvent(device, event, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyEvent(ApiDumpInstance::current(), device, event, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyEvent(ApiDumpInstance::current(), device, event, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyEvent(ApiDumpInstance::current(), device, event, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetEventStatus(VkDevice device, VkEvent event)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetEventStatus", "device, event", "VkResult");
    VkResult result = device_dispatch_table(device)->GetEventStatus(device, event);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetEventStatus(ApiDumpInstance::current(), result, device, event);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetEventStatus(ApiDumpInstance::current(), result, device, event);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetEventStatus(ApiDumpInstance::current(), result, device, event);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkSetEvent(VkDevice device, VkEvent event)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkSetEvent", "device, event", "VkResult");
    VkResult result = device_dispatch_table(device)->SetEvent(device, event);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkSetEvent(ApiDumpInstance::current(), result, device, event);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkSetEvent(ApiDumpInstance::current(), result, device, event);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkSetEvent(ApiDumpInstance::current(), result, device, event);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkResetEvent(VkDevice device, VkEvent event)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkResetEvent", "device, event", "VkResult");
    VkResult result = device_dispatch_table(device)->ResetEvent(device, event);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkResetEvent(ApiDumpInstance::current(), result, device, event);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkResetEvent(ApiDumpInstance::current(), result, device, event);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkResetEvent(ApiDumpInstance::current(), result, device, event);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateQueryPool(VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateQueryPool", "device, pCreateInfo, pAllocator, pQueryPool", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateQueryPool(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pQueryPool);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateQueryPool(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pQueryPool);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateQueryPool(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pQueryPool);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyQueryPool(VkDevice device, VkQueryPool queryPool, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyQueryPool", "device, queryPool, pAllocator", "void");
    device_dispatch_table(device)->DestroyQueryPool(device, queryPool, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyQueryPool(ApiDumpInstance::current(), device, queryPool, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyQueryPool(ApiDumpInstance::current(), device, queryPool, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyQueryPool(ApiDumpInstance::current(), device, queryPool, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetQueryPoolResults(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride, VkQueryResultFlags flags)
{
    VkResult result = device_dispatch_table(device)->GetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetQueryPoolResults", "device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags", "VkResult");
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetQueryPoolResults(ApiDumpInstance::current(), result, device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetQueryPoolResults(ApiDumpInstance::current(), result, device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetQueryPoolResults(ApiDumpInstance::current(), result, device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateBuffer(VkDevice device, const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateBuffer", "device, pCreateInfo, pAllocator, pBuffer", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateBuffer(device, pCreateInfo, pAllocator, pBuffer);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateBuffer(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pBuffer);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateBuffer(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pBuffer);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateBuffer(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pBuffer);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyBuffer(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyBuffer", "device, buffer, pAllocator", "void");
    device_dispatch_table(device)->DestroyBuffer(device, buffer, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyBuffer(ApiDumpInstance::current(), device, buffer, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyBuffer(ApiDumpInstance::current(), device, buffer, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyBuffer(ApiDumpInstance::current(), device, buffer, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateBufferView(VkDevice device, const VkBufferViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferView* pView)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateBufferView", "device, pCreateInfo, pAllocator, pView", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateBufferView(device, pCreateInfo, pAllocator, pView);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateBufferView(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pView);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateBufferView(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pView);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateBufferView(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pView);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyBufferView(VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyBufferView", "device, bufferView, pAllocator", "void");
    device_dispatch_table(device)->DestroyBufferView(device, bufferView, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyBufferView(ApiDumpInstance::current(), device, bufferView, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyBufferView(ApiDumpInstance::current(), device, bufferView, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyBufferView(ApiDumpInstance::current(), device, bufferView, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateImage(VkDevice device, const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImage* pImage)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateImage", "device, pCreateInfo, pAllocator, pImage", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateImage(device, pCreateInfo, pAllocator, pImage);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateImage(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pImage);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateImage(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pImage);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateImage(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pImage);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyImage(VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyImage", "device, image, pAllocator", "void");
    device_dispatch_table(device)->DestroyImage(device, image, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyImage(ApiDumpInstance::current(), device, image, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyImage(ApiDumpInstance::current(), device, image, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyImage(ApiDumpInstance::current(), device, image, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetImageSubresourceLayout(VkDevice device, VkImage image, const VkImageSubresource* pSubresource, VkSubresourceLayout* pLayout)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetImageSubresourceLayout", "device, image, pSubresource, pLayout", "void");
    device_dispatch_table(device)->GetImageSubresourceLayout(device, image, pSubresource, pLayout);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetImageSubresourceLayout(ApiDumpInstance::current(), device, image, pSubresource, pLayout);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetImageSubresourceLayout(ApiDumpInstance::current(), device, image, pSubresource, pLayout);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetImageSubresourceLayout(ApiDumpInstance::current(), device, image, pSubresource, pLayout);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateImageView(VkDevice device, const VkImageViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImageView* pView)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateImageView", "device, pCreateInfo, pAllocator, pView", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateImageView(device, pCreateInfo, pAllocator, pView);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateImageView(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pView);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateImageView(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pView);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateImageView(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pView);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyImageView(VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyImageView", "device, imageView, pAllocator", "void");
    device_dispatch_table(device)->DestroyImageView(device, imageView, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyImageView(ApiDumpInstance::current(), device, imageView, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyImageView(ApiDumpInstance::current(), device, imageView, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyImageView(ApiDumpInstance::current(), device, imageView, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateShaderModule(VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateShaderModule", "device, pCreateInfo, pAllocator, pShaderModule", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateShaderModule(device, pCreateInfo, pAllocator, pShaderModule);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateShaderModule(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pShaderModule);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateShaderModule(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pShaderModule);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateShaderModule(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pShaderModule);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyShaderModule(VkDevice device, VkShaderModule shaderModule, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyShaderModule", "device, shaderModule, pAllocator", "void");
    device_dispatch_table(device)->DestroyShaderModule(device, shaderModule, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyShaderModule(ApiDumpInstance::current(), device, shaderModule, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyShaderModule(ApiDumpInstance::current(), device, shaderModule, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyShaderModule(ApiDumpInstance::current(), device, shaderModule, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreatePipelineCache(VkDevice device, const VkPipelineCacheCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreatePipelineCache", "device, pCreateInfo, pAllocator, pPipelineCache", "VkResult");
    VkResult result = device_dispatch_table(device)->CreatePipelineCache(device, pCreateInfo, pAllocator, pPipelineCache);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreatePipelineCache(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pPipelineCache);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreatePipelineCache(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pPipelineCache);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreatePipelineCache(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pPipelineCache);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyPipelineCache(VkDevice device, VkPipelineCache pipelineCache, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyPipelineCache", "device, pipelineCache, pAllocator", "void");
    device_dispatch_table(device)->DestroyPipelineCache(device, pipelineCache, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyPipelineCache(ApiDumpInstance::current(), device, pipelineCache, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyPipelineCache(ApiDumpInstance::current(), device, pipelineCache, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyPipelineCache(ApiDumpInstance::current(), device, pipelineCache, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPipelineCacheData(VkDevice device, VkPipelineCache pipelineCache, size_t* pDataSize, void* pData)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPipelineCacheData", "device, pipelineCache, pDataSize, pData", "VkResult");
    VkResult result = device_dispatch_table(device)->GetPipelineCacheData(device, pipelineCache, pDataSize, pData);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPipelineCacheData(ApiDumpInstance::current(), result, device, pipelineCache, pDataSize, pData);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPipelineCacheData(ApiDumpInstance::current(), result, device, pipelineCache, pDataSize, pData);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPipelineCacheData(ApiDumpInstance::current(), result, device, pipelineCache, pDataSize, pData);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkMergePipelineCaches(VkDevice device, VkPipelineCache dstCache, uint32_t srcCacheCount, const VkPipelineCache* pSrcCaches)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkMergePipelineCaches", "device, dstCache, srcCacheCount, pSrcCaches", "VkResult");
    VkResult result = device_dispatch_table(device)->MergePipelineCaches(device, dstCache, srcCacheCount, pSrcCaches);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkMergePipelineCaches(ApiDumpInstance::current(), result, device, dstCache, srcCacheCount, pSrcCaches);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkMergePipelineCaches(ApiDumpInstance::current(), result, device, dstCache, srcCacheCount, pSrcCaches);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkMergePipelineCaches(ApiDumpInstance::current(), result, device, dstCache, srcCacheCount, pSrcCaches);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateGraphicsPipelines", "device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateGraphicsPipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateGraphicsPipelines(ApiDumpInstance::current(), result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateGraphicsPipelines(ApiDumpInstance::current(), result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateGraphicsPipelines(ApiDumpInstance::current(), result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkComputePipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateComputePipelines", "device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateComputePipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateComputePipelines(ApiDumpInstance::current(), result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateComputePipelines(ApiDumpInstance::current(), result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateComputePipelines(ApiDumpInstance::current(), result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyPipeline", "device, pipeline, pAllocator", "void");
    device_dispatch_table(device)->DestroyPipeline(device, pipeline, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyPipeline(ApiDumpInstance::current(), device, pipeline, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyPipeline(ApiDumpInstance::current(), device, pipeline, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyPipeline(ApiDumpInstance::current(), device, pipeline, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreatePipelineLayout(VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreatePipelineLayout", "device, pCreateInfo, pAllocator, pPipelineLayout", "VkResult");
    VkResult result = device_dispatch_table(device)->CreatePipelineLayout(device, pCreateInfo, pAllocator, pPipelineLayout);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreatePipelineLayout(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pPipelineLayout);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreatePipelineLayout(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pPipelineLayout);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreatePipelineLayout(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pPipelineLayout);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyPipelineLayout(VkDevice device, VkPipelineLayout pipelineLayout, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyPipelineLayout", "device, pipelineLayout, pAllocator", "void");
    device_dispatch_table(device)->DestroyPipelineLayout(device, pipelineLayout, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyPipelineLayout(ApiDumpInstance::current(), device, pipelineLayout, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyPipelineLayout(ApiDumpInstance::current(), device, pipelineLayout, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyPipelineLayout(ApiDumpInstance::current(), device, pipelineLayout, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateSampler(VkDevice device, const VkSamplerCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSampler* pSampler)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateSampler", "device, pCreateInfo, pAllocator, pSampler", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateSampler(device, pCreateInfo, pAllocator, pSampler);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateSampler(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pSampler);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateSampler(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pSampler);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateSampler(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pSampler);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroySampler(VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroySampler", "device, sampler, pAllocator", "void");
    device_dispatch_table(device)->DestroySampler(device, sampler, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroySampler(ApiDumpInstance::current(), device, sampler, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroySampler(ApiDumpInstance::current(), device, sampler, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroySampler(ApiDumpInstance::current(), device, sampler, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDescriptorSetLayout(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorSetLayout* pSetLayout)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateDescriptorSetLayout", "device, pCreateInfo, pAllocator, pSetLayout", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateDescriptorSetLayout(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pSetLayout);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateDescriptorSetLayout(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pSetLayout);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateDescriptorSetLayout(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pSetLayout);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyDescriptorSetLayout(VkDevice device, VkDescriptorSetLayout descriptorSetLayout, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyDescriptorSetLayout", "device, descriptorSetLayout, pAllocator", "void");
    device_dispatch_table(device)->DestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyDescriptorSetLayout(ApiDumpInstance::current(), device, descriptorSetLayout, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyDescriptorSetLayout(ApiDumpInstance::current(), device, descriptorSetLayout, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyDescriptorSetLayout(ApiDumpInstance::current(), device, descriptorSetLayout, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDescriptorPool(VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateDescriptorPool", "device, pCreateInfo, pAllocator, pDescriptorPool", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateDescriptorPool(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pDescriptorPool);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateDescriptorPool(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pDescriptorPool);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateDescriptorPool(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pDescriptorPool);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyDescriptorPool", "device, descriptorPool, pAllocator", "void");
    device_dispatch_table(device)->DestroyDescriptorPool(device, descriptorPool, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyDescriptorPool(ApiDumpInstance::current(), device, descriptorPool, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyDescriptorPool(ApiDumpInstance::current(), device, descriptorPool, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyDescriptorPool(ApiDumpInstance::current(), device, descriptorPool, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkResetDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkResetDescriptorPool", "device, descriptorPool, flags", "VkResult");
    VkResult result = device_dispatch_table(device)->ResetDescriptorPool(device, descriptorPool, flags);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkResetDescriptorPool(ApiDumpInstance::current(), result, device, descriptorPool, flags);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkResetDescriptorPool(ApiDumpInstance::current(), result, device, descriptorPool, flags);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkResetDescriptorPool(ApiDumpInstance::current(), result, device, descriptorPool, flags);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkAllocateDescriptorSets(VkDevice device, const VkDescriptorSetAllocateInfo* pAllocateInfo, VkDescriptorSet* pDescriptorSets)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkAllocateDescriptorSets", "device, pAllocateInfo, pDescriptorSets", "VkResult");
    VkResult result = device_dispatch_table(device)->AllocateDescriptorSets(device, pAllocateInfo, pDescriptorSets);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkAllocateDescriptorSets(ApiDumpInstance::current(), result, device, pAllocateInfo, pDescriptorSets);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkAllocateDescriptorSets(ApiDumpInstance::current(), result, device, pAllocateInfo, pDescriptorSets);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkAllocateDescriptorSets(ApiDumpInstance::current(), result, device, pAllocateInfo, pDescriptorSets);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkFreeDescriptorSets(VkDevice device, VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkFreeDescriptorSets", "device, descriptorPool, descriptorSetCount, pDescriptorSets", "VkResult");
    VkResult result = device_dispatch_table(device)->FreeDescriptorSets(device, descriptorPool, descriptorSetCount, pDescriptorSets);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkFreeDescriptorSets(ApiDumpInstance::current(), result, device, descriptorPool, descriptorSetCount, pDescriptorSets);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkFreeDescriptorSets(ApiDumpInstance::current(), result, device, descriptorPool, descriptorSetCount, pDescriptorSets);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkFreeDescriptorSets(ApiDumpInstance::current(), result, device, descriptorPool, descriptorSetCount, pDescriptorSets);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkUpdateDescriptorSets(VkDevice device, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount, const VkCopyDescriptorSet* pDescriptorCopies)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkUpdateDescriptorSets", "device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies", "void");
    device_dispatch_table(device)->UpdateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkUpdateDescriptorSets(ApiDumpInstance::current(), device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkUpdateDescriptorSets(ApiDumpInstance::current(), device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkUpdateDescriptorSets(ApiDumpInstance::current(), device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateFramebuffer(VkDevice device, const VkFramebufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateFramebuffer", "device, pCreateInfo, pAllocator, pFramebuffer", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateFramebuffer(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pFramebuffer);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateFramebuffer(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pFramebuffer);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateFramebuffer(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pFramebuffer);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyFramebuffer(VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyFramebuffer", "device, framebuffer, pAllocator", "void");
    device_dispatch_table(device)->DestroyFramebuffer(device, framebuffer, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyFramebuffer(ApiDumpInstance::current(), device, framebuffer, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyFramebuffer(ApiDumpInstance::current(), device, framebuffer, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyFramebuffer(ApiDumpInstance::current(), device, framebuffer, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateRenderPass(VkDevice device, const VkRenderPassCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateRenderPass", "device, pCreateInfo, pAllocator, pRenderPass", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateRenderPass(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pRenderPass);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateRenderPass(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pRenderPass);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateRenderPass(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pRenderPass);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyRenderPass(VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyRenderPass", "device, renderPass, pAllocator", "void");
    device_dispatch_table(device)->DestroyRenderPass(device, renderPass, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyRenderPass(ApiDumpInstance::current(), device, renderPass, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyRenderPass(ApiDumpInstance::current(), device, renderPass, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyRenderPass(ApiDumpInstance::current(), device, renderPass, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetRenderAreaGranularity(VkDevice device, VkRenderPass renderPass, VkExtent2D* pGranularity)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetRenderAreaGranularity", "device, renderPass, pGranularity", "void");
    device_dispatch_table(device)->GetRenderAreaGranularity(device, renderPass, pGranularity);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetRenderAreaGranularity(ApiDumpInstance::current(), device, renderPass, pGranularity);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetRenderAreaGranularity(ApiDumpInstance::current(), device, renderPass, pGranularity);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetRenderAreaGranularity(ApiDumpInstance::current(), device, renderPass, pGranularity);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateCommandPool", "device, pCreateInfo, pAllocator, pCommandPool", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateCommandPool(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pCommandPool);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateCommandPool(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pCommandPool);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateCommandPool(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pCommandPool);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyCommandPool(VkDevice device, VkCommandPool commandPool, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyCommandPool", "device, commandPool, pAllocator", "void");
    device_dispatch_table(device)->DestroyCommandPool(device, commandPool, pAllocator);
    ApiDumpInstance::current().eraseCmdBufferPool(device, commandPool);
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyCommandPool(ApiDumpInstance::current(), device, commandPool, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyCommandPool(ApiDumpInstance::current(), device, commandPool, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyCommandPool(ApiDumpInstance::current(), device, commandPool, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkResetCommandPool", "device, commandPool, flags", "VkResult");
    VkResult result = device_dispatch_table(device)->ResetCommandPool(device, commandPool, flags);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkResetCommandPool(ApiDumpInstance::current(), result, device, commandPool, flags);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkResetCommandPool(ApiDumpInstance::current(), result, device, commandPool, flags);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkResetCommandPool(ApiDumpInstance::current(), result, device, commandPool, flags);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkAllocateCommandBuffers(VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkAllocateCommandBuffers", "device, pAllocateInfo, pCommandBuffers", "VkResult");
    VkResult result = device_dispatch_table(device)->AllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers);
    if(result == VK_SUCCESS)
ApiDumpInstance::current().addCmdBuffers(
device,
pAllocateInfo->commandPool,
std::vector<VkCommandBuffer>(pCommandBuffers, pCommandBuffers + pAllocateInfo->commandBufferCount),
pAllocateInfo->level
);
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkAllocateCommandBuffers(ApiDumpInstance::current(), result, device, pAllocateInfo, pCommandBuffers);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkAllocateCommandBuffers(ApiDumpInstance::current(), result, device, pAllocateInfo, pCommandBuffers);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkAllocateCommandBuffers(ApiDumpInstance::current(), result, device, pAllocateInfo, pCommandBuffers);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkFreeCommandBuffers(VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkFreeCommandBuffers", "device, commandPool, commandBufferCount, pCommandBuffers", "void");
    device_dispatch_table(device)->FreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);
    ApiDumpInstance::current().eraseCmdBuffers(device, commandPool, std::vector<VkCommandBuffer>(pCommandBuffers, pCommandBuffers + commandBufferCount));
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkFreeCommandBuffers(ApiDumpInstance::current(), device, commandPool, commandBufferCount, pCommandBuffers);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkFreeCommandBuffers(ApiDumpInstance::current(), device, commandPool, commandBufferCount, pCommandBuffers);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkFreeCommandBuffers(ApiDumpInstance::current(), device, commandPool, commandBufferCount, pCommandBuffers);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkBeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkBeginCommandBuffer", "commandBuffer, pBeginInfo", "VkResult");
    VkResult result = device_dispatch_table(commandBuffer)->BeginCommandBuffer(commandBuffer, pBeginInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkBeginCommandBuffer(ApiDumpInstance::current(), result, commandBuffer, pBeginInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkBeginCommandBuffer(ApiDumpInstance::current(), result, commandBuffer, pBeginInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkBeginCommandBuffer(ApiDumpInstance::current(), result, commandBuffer, pBeginInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkEndCommandBuffer(VkCommandBuffer commandBuffer)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkEndCommandBuffer", "commandBuffer", "VkResult");
    VkResult result = device_dispatch_table(commandBuffer)->EndCommandBuffer(commandBuffer);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkEndCommandBuffer(ApiDumpInstance::current(), result, commandBuffer);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkEndCommandBuffer(ApiDumpInstance::current(), result, commandBuffer);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkEndCommandBuffer(ApiDumpInstance::current(), result, commandBuffer);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkResetCommandBuffer", "commandBuffer, flags", "VkResult");
    VkResult result = device_dispatch_table(commandBuffer)->ResetCommandBuffer(commandBuffer, flags);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkResetCommandBuffer(ApiDumpInstance::current(), result, commandBuffer, flags);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkResetCommandBuffer(ApiDumpInstance::current(), result, commandBuffer, flags);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkResetCommandBuffer(ApiDumpInstance::current(), result, commandBuffer, flags);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdBindPipeline", "commandBuffer, pipelineBindPoint, pipeline", "void");
    device_dispatch_table(commandBuffer)->CmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdBindPipeline(ApiDumpInstance::current(), commandBuffer, pipelineBindPoint, pipeline);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdBindPipeline(ApiDumpInstance::current(), commandBuffer, pipelineBindPoint, pipeline);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdBindPipeline(ApiDumpInstance::current(), commandBuffer, pipelineBindPoint, pipeline);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewport* pViewports)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetViewport", "commandBuffer, firstViewport, viewportCount, pViewports", "void");
    device_dispatch_table(commandBuffer)->CmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetViewport(ApiDumpInstance::current(), commandBuffer, firstViewport, viewportCount, pViewports);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetViewport(ApiDumpInstance::current(), commandBuffer, firstViewport, viewportCount, pViewports);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetViewport(ApiDumpInstance::current(), commandBuffer, firstViewport, viewportCount, pViewports);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const VkRect2D* pScissors)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetScissor", "commandBuffer, firstScissor, scissorCount, pScissors", "void");
    device_dispatch_table(commandBuffer)->CmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetScissor(ApiDumpInstance::current(), commandBuffer, firstScissor, scissorCount, pScissors);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetScissor(ApiDumpInstance::current(), commandBuffer, firstScissor, scissorCount, pScissors);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetScissor(ApiDumpInstance::current(), commandBuffer, firstScissor, scissorCount, pScissors);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetLineWidth", "commandBuffer, lineWidth", "void");
    device_dispatch_table(commandBuffer)->CmdSetLineWidth(commandBuffer, lineWidth);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetLineWidth(ApiDumpInstance::current(), commandBuffer, lineWidth);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetLineWidth(ApiDumpInstance::current(), commandBuffer, lineWidth);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetLineWidth(ApiDumpInstance::current(), commandBuffer, lineWidth);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetDepthBias", "commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor", "void");
    device_dispatch_table(commandBuffer)->CmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetDepthBias(ApiDumpInstance::current(), commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetDepthBias(ApiDumpInstance::current(), commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetDepthBias(ApiDumpInstance::current(), commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4])
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetBlendConstants", "commandBuffer, blendConstants", "void");
    device_dispatch_table(commandBuffer)->CmdSetBlendConstants(commandBuffer, blendConstants);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetBlendConstants(ApiDumpInstance::current(), commandBuffer, blendConstants);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetBlendConstants(ApiDumpInstance::current(), commandBuffer, blendConstants);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetBlendConstants(ApiDumpInstance::current(), commandBuffer, blendConstants);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetDepthBounds", "commandBuffer, minDepthBounds, maxDepthBounds", "void");
    device_dispatch_table(commandBuffer)->CmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetDepthBounds(ApiDumpInstance::current(), commandBuffer, minDepthBounds, maxDepthBounds);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetDepthBounds(ApiDumpInstance::current(), commandBuffer, minDepthBounds, maxDepthBounds);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetDepthBounds(ApiDumpInstance::current(), commandBuffer, minDepthBounds, maxDepthBounds);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetStencilCompareMask", "commandBuffer, faceMask, compareMask", "void");
    device_dispatch_table(commandBuffer)->CmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetStencilCompareMask(ApiDumpInstance::current(), commandBuffer, faceMask, compareMask);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetStencilCompareMask(ApiDumpInstance::current(), commandBuffer, faceMask, compareMask);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetStencilCompareMask(ApiDumpInstance::current(), commandBuffer, faceMask, compareMask);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetStencilWriteMask", "commandBuffer, faceMask, writeMask", "void");
    device_dispatch_table(commandBuffer)->CmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetStencilWriteMask(ApiDumpInstance::current(), commandBuffer, faceMask, writeMask);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetStencilWriteMask(ApiDumpInstance::current(), commandBuffer, faceMask, writeMask);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetStencilWriteMask(ApiDumpInstance::current(), commandBuffer, faceMask, writeMask);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetStencilReference", "commandBuffer, faceMask, reference", "void");
    device_dispatch_table(commandBuffer)->CmdSetStencilReference(commandBuffer, faceMask, reference);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetStencilReference(ApiDumpInstance::current(), commandBuffer, faceMask, reference);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetStencilReference(ApiDumpInstance::current(), commandBuffer, faceMask, reference);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetStencilReference(ApiDumpInstance::current(), commandBuffer, faceMask, reference);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t* pDynamicOffsets)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdBindDescriptorSets", "commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets", "void");
    device_dispatch_table(commandBuffer)->CmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdBindDescriptorSets(ApiDumpInstance::current(), commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdBindDescriptorSets(ApiDumpInstance::current(), commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdBindDescriptorSets(ApiDumpInstance::current(), commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdBindIndexBuffer", "commandBuffer, buffer, offset, indexType", "void");
    device_dispatch_table(commandBuffer)->CmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdBindIndexBuffer(ApiDumpInstance::current(), commandBuffer, buffer, offset, indexType);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdBindIndexBuffer(ApiDumpInstance::current(), commandBuffer, buffer, offset, indexType);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdBindIndexBuffer(ApiDumpInstance::current(), commandBuffer, buffer, offset, indexType);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdBindVertexBuffers", "commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets", "void");
    device_dispatch_table(commandBuffer)->CmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdBindVertexBuffers(ApiDumpInstance::current(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdBindVertexBuffers(ApiDumpInstance::current(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdBindVertexBuffers(ApiDumpInstance::current(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdDraw", "commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance", "void");
    device_dispatch_table(commandBuffer)->CmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdDraw(ApiDumpInstance::current(), commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdDraw(ApiDumpInstance::current(), commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdDraw(ApiDumpInstance::current(), commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdDrawIndexed", "commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance", "void");
    device_dispatch_table(commandBuffer)->CmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdDrawIndexed(ApiDumpInstance::current(), commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdDrawIndexed(ApiDumpInstance::current(), commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdDrawIndexed(ApiDumpInstance::current(), commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdDrawIndirect", "commandBuffer, buffer, offset, drawCount, stride", "void");
    device_dispatch_table(commandBuffer)->CmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdDrawIndirect(ApiDumpInstance::current(), commandBuffer, buffer, offset, drawCount, stride);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdDrawIndirect(ApiDumpInstance::current(), commandBuffer, buffer, offset, drawCount, stride);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdDrawIndirect(ApiDumpInstance::current(), commandBuffer, buffer, offset, drawCount, stride);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdDrawIndexedIndirect", "commandBuffer, buffer, offset, drawCount, stride", "void");
    device_dispatch_table(commandBuffer)->CmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdDrawIndexedIndirect(ApiDumpInstance::current(), commandBuffer, buffer, offset, drawCount, stride);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdDrawIndexedIndirect(ApiDumpInstance::current(), commandBuffer, buffer, offset, drawCount, stride);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdDrawIndexedIndirect(ApiDumpInstance::current(), commandBuffer, buffer, offset, drawCount, stride);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdDispatch", "commandBuffer, groupCountX, groupCountY, groupCountZ", "void");
    device_dispatch_table(commandBuffer)->CmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdDispatch(ApiDumpInstance::current(), commandBuffer, groupCountX, groupCountY, groupCountZ);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdDispatch(ApiDumpInstance::current(), commandBuffer, groupCountX, groupCountY, groupCountZ);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdDispatch(ApiDumpInstance::current(), commandBuffer, groupCountX, groupCountY, groupCountZ);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdDispatchIndirect", "commandBuffer, buffer, offset", "void");
    device_dispatch_table(commandBuffer)->CmdDispatchIndirect(commandBuffer, buffer, offset);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdDispatchIndirect(ApiDumpInstance::current(), commandBuffer, buffer, offset);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdDispatchIndirect(ApiDumpInstance::current(), commandBuffer, buffer, offset);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdDispatchIndirect(ApiDumpInstance::current(), commandBuffer, buffer, offset);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferCopy* pRegions)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdCopyBuffer", "commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions", "void");
    device_dispatch_table(commandBuffer)->CmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdCopyBuffer(ApiDumpInstance::current(), commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdCopyBuffer(ApiDumpInstance::current(), commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdCopyBuffer(ApiDumpInstance::current(), commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy* pRegions)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdCopyImage", "commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions", "void");
    device_dispatch_table(commandBuffer)->CmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdCopyImage(ApiDumpInstance::current(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdCopyImage(ApiDumpInstance::current(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdCopyImage(ApiDumpInstance::current(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit* pRegions, VkFilter filter)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdBlitImage", "commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter", "void");
    device_dispatch_table(commandBuffer)->CmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdBlitImage(ApiDumpInstance::current(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdBlitImage(ApiDumpInstance::current(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdBlitImage(ApiDumpInstance::current(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy* pRegions)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdCopyBufferToImage", "commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions", "void");
    device_dispatch_table(commandBuffer)->CmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdCopyBufferToImage(ApiDumpInstance::current(), commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdCopyBufferToImage(ApiDumpInstance::current(), commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdCopyBufferToImage(ApiDumpInstance::current(), commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdCopyImageToBuffer", "commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions", "void");
    device_dispatch_table(commandBuffer)->CmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdCopyImageToBuffer(ApiDumpInstance::current(), commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdCopyImageToBuffer(ApiDumpInstance::current(), commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdCopyImageToBuffer(ApiDumpInstance::current(), commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void* pData)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdUpdateBuffer", "commandBuffer, dstBuffer, dstOffset, dataSize, pData", "void");
    device_dispatch_table(commandBuffer)->CmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdUpdateBuffer(ApiDumpInstance::current(), commandBuffer, dstBuffer, dstOffset, dataSize, pData);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdUpdateBuffer(ApiDumpInstance::current(), commandBuffer, dstBuffer, dstOffset, dataSize, pData);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdUpdateBuffer(ApiDumpInstance::current(), commandBuffer, dstBuffer, dstOffset, dataSize, pData);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdFillBuffer", "commandBuffer, dstBuffer, dstOffset, size, data", "void");
    device_dispatch_table(commandBuffer)->CmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdFillBuffer(ApiDumpInstance::current(), commandBuffer, dstBuffer, dstOffset, size, data);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdFillBuffer(ApiDumpInstance::current(), commandBuffer, dstBuffer, dstOffset, size, data);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdFillBuffer(ApiDumpInstance::current(), commandBuffer, dstBuffer, dstOffset, size, data);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearColorValue* pColor, uint32_t rangeCount, const VkImageSubresourceRange* pRanges)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdClearColorImage", "commandBuffer, image, imageLayout, pColor, rangeCount, pRanges", "void");
    device_dispatch_table(commandBuffer)->CmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdClearColorImage(ApiDumpInstance::current(), commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdClearColorImage(ApiDumpInstance::current(), commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdClearColorImage(ApiDumpInstance::current(), commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount, const VkImageSubresourceRange* pRanges)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdClearDepthStencilImage", "commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges", "void");
    device_dispatch_table(commandBuffer)->CmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdClearDepthStencilImage(ApiDumpInstance::current(), commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdClearDepthStencilImage(ApiDumpInstance::current(), commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdClearDepthStencilImage(ApiDumpInstance::current(), commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkClearAttachment* pAttachments, uint32_t rectCount, const VkClearRect* pRects)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdClearAttachments", "commandBuffer, attachmentCount, pAttachments, rectCount, pRects", "void");
    device_dispatch_table(commandBuffer)->CmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdClearAttachments(ApiDumpInstance::current(), commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdClearAttachments(ApiDumpInstance::current(), commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdClearAttachments(ApiDumpInstance::current(), commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageResolve* pRegions)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdResolveImage", "commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions", "void");
    device_dispatch_table(commandBuffer)->CmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdResolveImage(ApiDumpInstance::current(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdResolveImage(ApiDumpInstance::current(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdResolveImage(ApiDumpInstance::current(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetEvent", "commandBuffer, event, stageMask", "void");
    device_dispatch_table(commandBuffer)->CmdSetEvent(commandBuffer, event, stageMask);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetEvent(ApiDumpInstance::current(), commandBuffer, event, stageMask);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetEvent(ApiDumpInstance::current(), commandBuffer, event, stageMask);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetEvent(ApiDumpInstance::current(), commandBuffer, event, stageMask);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdResetEvent", "commandBuffer, event, stageMask", "void");
    device_dispatch_table(commandBuffer)->CmdResetEvent(commandBuffer, event, stageMask);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdResetEvent(ApiDumpInstance::current(), commandBuffer, event, stageMask);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdResetEvent(ApiDumpInstance::current(), commandBuffer, event, stageMask);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdResetEvent(ApiDumpInstance::current(), commandBuffer, event, stageMask);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdWaitEvents", "commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers", "void");
    device_dispatch_table(commandBuffer)->CmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdWaitEvents(ApiDumpInstance::current(), commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdWaitEvents(ApiDumpInstance::current(), commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdWaitEvents(ApiDumpInstance::current(), commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdPipelineBarrier", "commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers", "void");
    device_dispatch_table(commandBuffer)->CmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdPipelineBarrier(ApiDumpInstance::current(), commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdPipelineBarrier(ApiDumpInstance::current(), commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdPipelineBarrier(ApiDumpInstance::current(), commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdBeginQuery", "commandBuffer, queryPool, query, flags", "void");
    device_dispatch_table(commandBuffer)->CmdBeginQuery(commandBuffer, queryPool, query, flags);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdBeginQuery(ApiDumpInstance::current(), commandBuffer, queryPool, query, flags);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdBeginQuery(ApiDumpInstance::current(), commandBuffer, queryPool, query, flags);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdBeginQuery(ApiDumpInstance::current(), commandBuffer, queryPool, query, flags);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdEndQuery", "commandBuffer, queryPool, query", "void");
    device_dispatch_table(commandBuffer)->CmdEndQuery(commandBuffer, queryPool, query);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdEndQuery(ApiDumpInstance::current(), commandBuffer, queryPool, query);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdEndQuery(ApiDumpInstance::current(), commandBuffer, queryPool, query);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdEndQuery(ApiDumpInstance::current(), commandBuffer, queryPool, query);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdResetQueryPool", "commandBuffer, queryPool, firstQuery, queryCount", "void");
    device_dispatch_table(commandBuffer)->CmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdResetQueryPool(ApiDumpInstance::current(), commandBuffer, queryPool, firstQuery, queryCount);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdResetQueryPool(ApiDumpInstance::current(), commandBuffer, queryPool, firstQuery, queryCount);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdResetQueryPool(ApiDumpInstance::current(), commandBuffer, queryPool, firstQuery, queryCount);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool, uint32_t query)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdWriteTimestamp", "commandBuffer, pipelineStage, queryPool, query", "void");
    device_dispatch_table(commandBuffer)->CmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdWriteTimestamp(ApiDumpInstance::current(), commandBuffer, pipelineStage, queryPool, query);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdWriteTimestamp(ApiDumpInstance::current(), commandBuffer, pipelineStage, queryPool, query);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdWriteTimestamp(ApiDumpInstance::current(), commandBuffer, pipelineStage, queryPool, query);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdCopyQueryPoolResults", "commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags", "void");
    device_dispatch_table(commandBuffer)->CmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdCopyQueryPoolResults(ApiDumpInstance::current(), commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdCopyQueryPoolResults(ApiDumpInstance::current(), commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdCopyQueryPoolResults(ApiDumpInstance::current(), commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void* pValues)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdPushConstants", "commandBuffer, layout, stageFlags, offset, size, pValues", "void");
    device_dispatch_table(commandBuffer)->CmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdPushConstants(ApiDumpInstance::current(), commandBuffer, layout, stageFlags, offset, size, pValues);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdPushConstants(ApiDumpInstance::current(), commandBuffer, layout, stageFlags, offset, size, pValues);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdPushConstants(ApiDumpInstance::current(), commandBuffer, layout, stageFlags, offset, size, pValues);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdBeginRenderPass", "commandBuffer, pRenderPassBegin, contents", "void");
    device_dispatch_table(commandBuffer)->CmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdBeginRenderPass(ApiDumpInstance::current(), commandBuffer, pRenderPassBegin, contents);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdBeginRenderPass(ApiDumpInstance::current(), commandBuffer, pRenderPassBegin, contents);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdBeginRenderPass(ApiDumpInstance::current(), commandBuffer, pRenderPassBegin, contents);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdNextSubpass", "commandBuffer, contents", "void");
    device_dispatch_table(commandBuffer)->CmdNextSubpass(commandBuffer, contents);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdNextSubpass(ApiDumpInstance::current(), commandBuffer, contents);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdNextSubpass(ApiDumpInstance::current(), commandBuffer, contents);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdNextSubpass(ApiDumpInstance::current(), commandBuffer, contents);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdEndRenderPass(VkCommandBuffer commandBuffer)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdEndRenderPass", "commandBuffer", "void");
    device_dispatch_table(commandBuffer)->CmdEndRenderPass(commandBuffer);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdEndRenderPass(ApiDumpInstance::current(), commandBuffer);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdEndRenderPass(ApiDumpInstance::current(), commandBuffer);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdEndRenderPass(ApiDumpInstance::current(), commandBuffer);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdExecuteCommands", "commandBuffer, commandBufferCount, pCommandBuffers", "void");
    device_dispatch_table(commandBuffer)->CmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdExecuteCommands(ApiDumpInstance::current(), commandBuffer, commandBufferCount, pCommandBuffers);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdExecuteCommands(ApiDumpInstance::current(), commandBuffer, commandBufferCount, pCommandBuffers);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdExecuteCommands(ApiDumpInstance::current(), commandBuffer, commandBufferCount, pCommandBuffers);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkBindBufferMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkBindBufferMemory2", "device, bindInfoCount, pBindInfos", "VkResult");
    VkResult result = device_dispatch_table(device)->BindBufferMemory2(device, bindInfoCount, pBindInfos);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkBindBufferMemory2(ApiDumpInstance::current(), result, device, bindInfoCount, pBindInfos);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkBindBufferMemory2(ApiDumpInstance::current(), result, device, bindInfoCount, pBindInfos);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkBindBufferMemory2(ApiDumpInstance::current(), result, device, bindInfoCount, pBindInfos);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkBindImageMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkBindImageMemory2", "device, bindInfoCount, pBindInfos", "VkResult");
    VkResult result = device_dispatch_table(device)->BindImageMemory2(device, bindInfoCount, pBindInfos);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkBindImageMemory2(ApiDumpInstance::current(), result, device, bindInfoCount, pBindInfos);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkBindImageMemory2(ApiDumpInstance::current(), result, device, bindInfoCount, pBindInfos);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkBindImageMemory2(ApiDumpInstance::current(), result, device, bindInfoCount, pBindInfos);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetDeviceGroupPeerMemoryFeatures(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDeviceGroupPeerMemoryFeatures", "device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures", "void");
    device_dispatch_table(device)->GetDeviceGroupPeerMemoryFeatures(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDeviceGroupPeerMemoryFeatures(ApiDumpInstance::current(), device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDeviceGroupPeerMemoryFeatures(ApiDumpInstance::current(), device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDeviceGroupPeerMemoryFeatures(ApiDumpInstance::current(), device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetDeviceMask", "commandBuffer, deviceMask", "void");
    device_dispatch_table(commandBuffer)->CmdSetDeviceMask(commandBuffer, deviceMask);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetDeviceMask(ApiDumpInstance::current(), commandBuffer, deviceMask);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetDeviceMask(ApiDumpInstance::current(), commandBuffer, deviceMask);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetDeviceMask(ApiDumpInstance::current(), commandBuffer, deviceMask);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdDispatchBase", "commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ", "void");
    device_dispatch_table(commandBuffer)->CmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdDispatchBase(ApiDumpInstance::current(), commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdDispatchBase(ApiDumpInstance::current(), commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdDispatchBase(ApiDumpInstance::current(), commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetImageMemoryRequirements2(VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetImageMemoryRequirements2", "device, pInfo, pMemoryRequirements", "void");
    device_dispatch_table(device)->GetImageMemoryRequirements2(device, pInfo, pMemoryRequirements);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetImageMemoryRequirements2(ApiDumpInstance::current(), device, pInfo, pMemoryRequirements);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetImageMemoryRequirements2(ApiDumpInstance::current(), device, pInfo, pMemoryRequirements);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetImageMemoryRequirements2(ApiDumpInstance::current(), device, pInfo, pMemoryRequirements);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetBufferMemoryRequirements2(VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetBufferMemoryRequirements2", "device, pInfo, pMemoryRequirements", "void");
    device_dispatch_table(device)->GetBufferMemoryRequirements2(device, pInfo, pMemoryRequirements);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetBufferMemoryRequirements2(ApiDumpInstance::current(), device, pInfo, pMemoryRequirements);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetBufferMemoryRequirements2(ApiDumpInstance::current(), device, pInfo, pMemoryRequirements);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetBufferMemoryRequirements2(ApiDumpInstance::current(), device, pInfo, pMemoryRequirements);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetImageSparseMemoryRequirements2(VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetImageSparseMemoryRequirements2", "device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements", "void");
    device_dispatch_table(device)->GetImageSparseMemoryRequirements2(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetImageSparseMemoryRequirements2(ApiDumpInstance::current(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetImageSparseMemoryRequirements2(ApiDumpInstance::current(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetImageSparseMemoryRequirements2(ApiDumpInstance::current(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkTrimCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkTrimCommandPool", "device, commandPool, flags", "void");
    device_dispatch_table(device)->TrimCommandPool(device, commandPool, flags);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkTrimCommandPool(ApiDumpInstance::current(), device, commandPool, flags);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkTrimCommandPool(ApiDumpInstance::current(), device, commandPool, flags);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkTrimCommandPool(ApiDumpInstance::current(), device, commandPool, flags);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetDeviceQueue2(VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDeviceQueue2", "device, pQueueInfo, pQueue", "void");
    device_dispatch_table(device)->GetDeviceQueue2(device, pQueueInfo, pQueue);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDeviceQueue2(ApiDumpInstance::current(), device, pQueueInfo, pQueue);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDeviceQueue2(ApiDumpInstance::current(), device, pQueueInfo, pQueue);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDeviceQueue2(ApiDumpInstance::current(), device, pQueueInfo, pQueue);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateSamplerYcbcrConversion(VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateSamplerYcbcrConversion", "device, pCreateInfo, pAllocator, pYcbcrConversion", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateSamplerYcbcrConversion(device, pCreateInfo, pAllocator, pYcbcrConversion);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateSamplerYcbcrConversion(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pYcbcrConversion);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateSamplerYcbcrConversion(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pYcbcrConversion);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateSamplerYcbcrConversion(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pYcbcrConversion);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroySamplerYcbcrConversion(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroySamplerYcbcrConversion", "device, ycbcrConversion, pAllocator", "void");
    device_dispatch_table(device)->DestroySamplerYcbcrConversion(device, ycbcrConversion, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroySamplerYcbcrConversion(ApiDumpInstance::current(), device, ycbcrConversion, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroySamplerYcbcrConversion(ApiDumpInstance::current(), device, ycbcrConversion, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroySamplerYcbcrConversion(ApiDumpInstance::current(), device, ycbcrConversion, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDescriptorUpdateTemplate(VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateDescriptorUpdateTemplate", "device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateDescriptorUpdateTemplate(device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateDescriptorUpdateTemplate(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateDescriptorUpdateTemplate(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateDescriptorUpdateTemplate(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyDescriptorUpdateTemplate(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyDescriptorUpdateTemplate", "device, descriptorUpdateTemplate, pAllocator", "void");
    device_dispatch_table(device)->DestroyDescriptorUpdateTemplate(device, descriptorUpdateTemplate, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyDescriptorUpdateTemplate(ApiDumpInstance::current(), device, descriptorUpdateTemplate, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyDescriptorUpdateTemplate(ApiDumpInstance::current(), device, descriptorUpdateTemplate, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyDescriptorUpdateTemplate(ApiDumpInstance::current(), device, descriptorUpdateTemplate, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkUpdateDescriptorSetWithTemplate(VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkUpdateDescriptorSetWithTemplate", "device, descriptorSet, descriptorUpdateTemplate, pData", "void");
    device_dispatch_table(device)->UpdateDescriptorSetWithTemplate(device, descriptorSet, descriptorUpdateTemplate, pData);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkUpdateDescriptorSetWithTemplate(ApiDumpInstance::current(), device, descriptorSet, descriptorUpdateTemplate, pData);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkUpdateDescriptorSetWithTemplate(ApiDumpInstance::current(), device, descriptorSet, descriptorUpdateTemplate, pData);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkUpdateDescriptorSetWithTemplate(ApiDumpInstance::current(), device, descriptorSet, descriptorUpdateTemplate, pData);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetDescriptorSetLayoutSupport(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDescriptorSetLayoutSupport", "device, pCreateInfo, pSupport", "void");
    device_dispatch_table(device)->GetDescriptorSetLayoutSupport(device, pCreateInfo, pSupport);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDescriptorSetLayoutSupport(ApiDumpInstance::current(), device, pCreateInfo, pSupport);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDescriptorSetLayoutSupport(ApiDumpInstance::current(), device, pCreateInfo, pSupport);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDescriptorSetLayoutSupport(ApiDumpInstance::current(), device, pCreateInfo, pSupport);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdDrawIndirectCount", "commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride", "void");
    device_dispatch_table(commandBuffer)->CmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdDrawIndirectCount(ApiDumpInstance::current(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdDrawIndirectCount(ApiDumpInstance::current(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdDrawIndirectCount(ApiDumpInstance::current(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdDrawIndexedIndirectCount", "commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride", "void");
    device_dispatch_table(commandBuffer)->CmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdDrawIndexedIndirectCount(ApiDumpInstance::current(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdDrawIndexedIndirectCount(ApiDumpInstance::current(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdDrawIndexedIndirectCount(ApiDumpInstance::current(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateRenderPass2(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateRenderPass2", "device, pCreateInfo, pAllocator, pRenderPass", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateRenderPass2(device, pCreateInfo, pAllocator, pRenderPass);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateRenderPass2(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pRenderPass);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateRenderPass2(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pRenderPass);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateRenderPass2(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pRenderPass);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo*      pRenderPassBegin, const VkSubpassBeginInfo*      pSubpassBeginInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdBeginRenderPass2", "commandBuffer, pRenderPassBegin, pSubpassBeginInfo", "void");
    device_dispatch_table(commandBuffer)->CmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdBeginRenderPass2(ApiDumpInstance::current(), commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdBeginRenderPass2(ApiDumpInstance::current(), commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdBeginRenderPass2(ApiDumpInstance::current(), commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo*      pSubpassBeginInfo, const VkSubpassEndInfo*        pSubpassEndInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdNextSubpass2", "commandBuffer, pSubpassBeginInfo, pSubpassEndInfo", "void");
    device_dispatch_table(commandBuffer)->CmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdNextSubpass2(ApiDumpInstance::current(), commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdNextSubpass2(ApiDumpInstance::current(), commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdNextSubpass2(ApiDumpInstance::current(), commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo*        pSubpassEndInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdEndRenderPass2", "commandBuffer, pSubpassEndInfo", "void");
    device_dispatch_table(commandBuffer)->CmdEndRenderPass2(commandBuffer, pSubpassEndInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdEndRenderPass2(ApiDumpInstance::current(), commandBuffer, pSubpassEndInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdEndRenderPass2(ApiDumpInstance::current(), commandBuffer, pSubpassEndInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdEndRenderPass2(ApiDumpInstance::current(), commandBuffer, pSubpassEndInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkResetQueryPool(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkResetQueryPool", "device, queryPool, firstQuery, queryCount", "void");
    device_dispatch_table(device)->ResetQueryPool(device, queryPool, firstQuery, queryCount);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkResetQueryPool(ApiDumpInstance::current(), device, queryPool, firstQuery, queryCount);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkResetQueryPool(ApiDumpInstance::current(), device, queryPool, firstQuery, queryCount);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkResetQueryPool(ApiDumpInstance::current(), device, queryPool, firstQuery, queryCount);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetSemaphoreCounterValue(VkDevice device, VkSemaphore semaphore, uint64_t* pValue)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetSemaphoreCounterValue", "device, semaphore, pValue", "VkResult");
    VkResult result = device_dispatch_table(device)->GetSemaphoreCounterValue(device, semaphore, pValue);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetSemaphoreCounterValue(ApiDumpInstance::current(), result, device, semaphore, pValue);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetSemaphoreCounterValue(ApiDumpInstance::current(), result, device, semaphore, pValue);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetSemaphoreCounterValue(ApiDumpInstance::current(), result, device, semaphore, pValue);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkWaitSemaphores(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout)
{
    VkResult result = device_dispatch_table(device)->WaitSemaphores(device, pWaitInfo, timeout);
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkWaitSemaphores", "device, pWaitInfo, timeout", "VkResult");
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkWaitSemaphores(ApiDumpInstance::current(), result, device, pWaitInfo, timeout);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkWaitSemaphores(ApiDumpInstance::current(), result, device, pWaitInfo, timeout);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkWaitSemaphores(ApiDumpInstance::current(), result, device, pWaitInfo, timeout);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkSignalSemaphore(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkSignalSemaphore", "device, pSignalInfo", "VkResult");
    VkResult result = device_dispatch_table(device)->SignalSemaphore(device, pSignalInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkSignalSemaphore(ApiDumpInstance::current(), result, device, pSignalInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkSignalSemaphore(ApiDumpInstance::current(), result, device, pSignalInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkSignalSemaphore(ApiDumpInstance::current(), result, device, pSignalInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkDeviceAddress VKAPI_CALL vkGetBufferDeviceAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetBufferDeviceAddress", "device, pInfo", "VkDeviceAddress");
    VkDeviceAddress result = device_dispatch_table(device)->GetBufferDeviceAddress(device, pInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetBufferDeviceAddress(ApiDumpInstance::current(), result, device, pInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetBufferDeviceAddress(ApiDumpInstance::current(), result, device, pInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetBufferDeviceAddress(ApiDumpInstance::current(), result, device, pInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR uint64_t VKAPI_CALL vkGetBufferOpaqueCaptureAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetBufferOpaqueCaptureAddress", "device, pInfo", "uint64_t");
    uint64_t result = device_dispatch_table(device)->GetBufferOpaqueCaptureAddress(device, pInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetBufferOpaqueCaptureAddress(ApiDumpInstance::current(), result, device, pInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetBufferOpaqueCaptureAddress(ApiDumpInstance::current(), result, device, pInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetBufferOpaqueCaptureAddress(ApiDumpInstance::current(), result, device, pInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR uint64_t VKAPI_CALL vkGetDeviceMemoryOpaqueCaptureAddress(VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDeviceMemoryOpaqueCaptureAddress", "device, pInfo", "uint64_t");
    uint64_t result = device_dispatch_table(device)->GetDeviceMemoryOpaqueCaptureAddress(device, pInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDeviceMemoryOpaqueCaptureAddress(ApiDumpInstance::current(), result, device, pInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDeviceMemoryOpaqueCaptureAddress(ApiDumpInstance::current(), result, device, pInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDeviceMemoryOpaqueCaptureAddress(ApiDumpInstance::current(), result, device, pInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreatePrivateDataSlot(VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreatePrivateDataSlot", "device, pCreateInfo, pAllocator, pPrivateDataSlot", "VkResult");
    VkResult result = device_dispatch_table(device)->CreatePrivateDataSlot(device, pCreateInfo, pAllocator, pPrivateDataSlot);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreatePrivateDataSlot(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pPrivateDataSlot);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreatePrivateDataSlot(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pPrivateDataSlot);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreatePrivateDataSlot(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pPrivateDataSlot);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyPrivateDataSlot(VkDevice device, VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyPrivateDataSlot", "device, privateDataSlot, pAllocator", "void");
    device_dispatch_table(device)->DestroyPrivateDataSlot(device, privateDataSlot, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyPrivateDataSlot(ApiDumpInstance::current(), device, privateDataSlot, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyPrivateDataSlot(ApiDumpInstance::current(), device, privateDataSlot, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyPrivateDataSlot(ApiDumpInstance::current(), device, privateDataSlot, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkSetPrivateData(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkSetPrivateData", "device, objectType, objectHandle, privateDataSlot, data", "VkResult");
    VkResult result = device_dispatch_table(device)->SetPrivateData(device, objectType, objectHandle, privateDataSlot, data);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkSetPrivateData(ApiDumpInstance::current(), result, device, objectType, objectHandle, privateDataSlot, data);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkSetPrivateData(ApiDumpInstance::current(), result, device, objectType, objectHandle, privateDataSlot, data);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkSetPrivateData(ApiDumpInstance::current(), result, device, objectType, objectHandle, privateDataSlot, data);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetPrivateData(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t* pData)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPrivateData", "device, objectType, objectHandle, privateDataSlot, pData", "void");
    device_dispatch_table(device)->GetPrivateData(device, objectType, objectHandle, privateDataSlot, pData);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPrivateData(ApiDumpInstance::current(), device, objectType, objectHandle, privateDataSlot, pData);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPrivateData(ApiDumpInstance::current(), device, objectType, objectHandle, privateDataSlot, pData);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPrivateData(ApiDumpInstance::current(), device, objectType, objectHandle, privateDataSlot, pData);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetEvent2(VkCommandBuffer                   commandBuffer, VkEvent                                             event, const VkDependencyInfo*                             pDependencyInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetEvent2", "commandBuffer, event, pDependencyInfo", "void");
    device_dispatch_table(commandBuffer)->CmdSetEvent2(commandBuffer, event, pDependencyInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetEvent2(ApiDumpInstance::current(), commandBuffer, event, pDependencyInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetEvent2(ApiDumpInstance::current(), commandBuffer, event, pDependencyInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetEvent2(ApiDumpInstance::current(), commandBuffer, event, pDependencyInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdResetEvent2(VkCommandBuffer                   commandBuffer, VkEvent                                             event, VkPipelineStageFlags2               stageMask)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdResetEvent2", "commandBuffer, event, stageMask", "void");
    device_dispatch_table(commandBuffer)->CmdResetEvent2(commandBuffer, event, stageMask);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdResetEvent2(ApiDumpInstance::current(), commandBuffer, event, stageMask);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdResetEvent2(ApiDumpInstance::current(), commandBuffer, event, stageMask);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdResetEvent2(ApiDumpInstance::current(), commandBuffer, event, stageMask);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdWaitEvents2(VkCommandBuffer                   commandBuffer, uint32_t                                            eventCount, const VkEvent*                     pEvents, const VkDependencyInfo*            pDependencyInfos)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdWaitEvents2", "commandBuffer, eventCount, pEvents, pDependencyInfos", "void");
    device_dispatch_table(commandBuffer)->CmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdWaitEvents2(ApiDumpInstance::current(), commandBuffer, eventCount, pEvents, pDependencyInfos);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdWaitEvents2(ApiDumpInstance::current(), commandBuffer, eventCount, pEvents, pDependencyInfos);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdWaitEvents2(ApiDumpInstance::current(), commandBuffer, eventCount, pEvents, pDependencyInfos);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdPipelineBarrier2(VkCommandBuffer                   commandBuffer, const VkDependencyInfo*                             pDependencyInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdPipelineBarrier2", "commandBuffer, pDependencyInfo", "void");
    device_dispatch_table(commandBuffer)->CmdPipelineBarrier2(commandBuffer, pDependencyInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdPipelineBarrier2(ApiDumpInstance::current(), commandBuffer, pDependencyInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdPipelineBarrier2(ApiDumpInstance::current(), commandBuffer, pDependencyInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdPipelineBarrier2(ApiDumpInstance::current(), commandBuffer, pDependencyInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdWriteTimestamp2(VkCommandBuffer                   commandBuffer, VkPipelineStageFlags2               stage, VkQueryPool                                         queryPool, uint32_t                                            query)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdWriteTimestamp2", "commandBuffer, stage, queryPool, query", "void");
    device_dispatch_table(commandBuffer)->CmdWriteTimestamp2(commandBuffer, stage, queryPool, query);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdWriteTimestamp2(ApiDumpInstance::current(), commandBuffer, stage, queryPool, query);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdWriteTimestamp2(ApiDumpInstance::current(), commandBuffer, stage, queryPool, query);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdWriteTimestamp2(ApiDumpInstance::current(), commandBuffer, stage, queryPool, query);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkQueueSubmit2(VkQueue                           queue, uint32_t                            submitCount, const VkSubmitInfo2*              pSubmits, VkFence           fence)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkQueueSubmit2", "queue, submitCount, pSubmits, fence", "VkResult");
    VkResult result = device_dispatch_table(queue)->QueueSubmit2(queue, submitCount, pSubmits, fence);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkQueueSubmit2(ApiDumpInstance::current(), result, queue, submitCount, pSubmits, fence);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkQueueSubmit2(ApiDumpInstance::current(), result, queue, submitCount, pSubmits, fence);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkQueueSubmit2(ApiDumpInstance::current(), result, queue, submitCount, pSubmits, fence);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdCopyBuffer2", "commandBuffer, pCopyBufferInfo", "void");
    device_dispatch_table(commandBuffer)->CmdCopyBuffer2(commandBuffer, pCopyBufferInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdCopyBuffer2(ApiDumpInstance::current(), commandBuffer, pCopyBufferInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdCopyBuffer2(ApiDumpInstance::current(), commandBuffer, pCopyBufferInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdCopyBuffer2(ApiDumpInstance::current(), commandBuffer, pCopyBufferInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdCopyImage2", "commandBuffer, pCopyImageInfo", "void");
    device_dispatch_table(commandBuffer)->CmdCopyImage2(commandBuffer, pCopyImageInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdCopyImage2(ApiDumpInstance::current(), commandBuffer, pCopyImageInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdCopyImage2(ApiDumpInstance::current(), commandBuffer, pCopyImageInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdCopyImage2(ApiDumpInstance::current(), commandBuffer, pCopyImageInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyBufferToImage2(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdCopyBufferToImage2", "commandBuffer, pCopyBufferToImageInfo", "void");
    device_dispatch_table(commandBuffer)->CmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdCopyBufferToImage2(ApiDumpInstance::current(), commandBuffer, pCopyBufferToImageInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdCopyBufferToImage2(ApiDumpInstance::current(), commandBuffer, pCopyBufferToImageInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdCopyBufferToImage2(ApiDumpInstance::current(), commandBuffer, pCopyBufferToImageInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyImageToBuffer2(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdCopyImageToBuffer2", "commandBuffer, pCopyImageToBufferInfo", "void");
    device_dispatch_table(commandBuffer)->CmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdCopyImageToBuffer2(ApiDumpInstance::current(), commandBuffer, pCopyImageToBufferInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdCopyImageToBuffer2(ApiDumpInstance::current(), commandBuffer, pCopyImageToBufferInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdCopyImageToBuffer2(ApiDumpInstance::current(), commandBuffer, pCopyImageToBufferInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdBlitImage2", "commandBuffer, pBlitImageInfo", "void");
    device_dispatch_table(commandBuffer)->CmdBlitImage2(commandBuffer, pBlitImageInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdBlitImage2(ApiDumpInstance::current(), commandBuffer, pBlitImageInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdBlitImage2(ApiDumpInstance::current(), commandBuffer, pBlitImageInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdBlitImage2(ApiDumpInstance::current(), commandBuffer, pBlitImageInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdResolveImage2", "commandBuffer, pResolveImageInfo", "void");
    device_dispatch_table(commandBuffer)->CmdResolveImage2(commandBuffer, pResolveImageInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdResolveImage2(ApiDumpInstance::current(), commandBuffer, pResolveImageInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdResolveImage2(ApiDumpInstance::current(), commandBuffer, pResolveImageInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdResolveImage2(ApiDumpInstance::current(), commandBuffer, pResolveImageInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdBeginRendering(VkCommandBuffer                   commandBuffer, const VkRenderingInfo*                              pRenderingInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdBeginRendering", "commandBuffer, pRenderingInfo", "void");
    device_dispatch_table(commandBuffer)->CmdBeginRendering(commandBuffer, pRenderingInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdBeginRendering(ApiDumpInstance::current(), commandBuffer, pRenderingInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdBeginRendering(ApiDumpInstance::current(), commandBuffer, pRenderingInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdBeginRendering(ApiDumpInstance::current(), commandBuffer, pRenderingInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdEndRendering(VkCommandBuffer                   commandBuffer)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdEndRendering", "commandBuffer", "void");
    device_dispatch_table(commandBuffer)->CmdEndRendering(commandBuffer);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdEndRendering(ApiDumpInstance::current(), commandBuffer);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdEndRendering(ApiDumpInstance::current(), commandBuffer);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdEndRendering(ApiDumpInstance::current(), commandBuffer);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetCullMode", "commandBuffer, cullMode", "void");
    device_dispatch_table(commandBuffer)->CmdSetCullMode(commandBuffer, cullMode);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetCullMode(ApiDumpInstance::current(), commandBuffer, cullMode);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetCullMode(ApiDumpInstance::current(), commandBuffer, cullMode);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetCullMode(ApiDumpInstance::current(), commandBuffer, cullMode);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetFrontFace", "commandBuffer, frontFace", "void");
    device_dispatch_table(commandBuffer)->CmdSetFrontFace(commandBuffer, frontFace);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetFrontFace(ApiDumpInstance::current(), commandBuffer, frontFace);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetFrontFace(ApiDumpInstance::current(), commandBuffer, frontFace);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetFrontFace(ApiDumpInstance::current(), commandBuffer, frontFace);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetPrimitiveTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetPrimitiveTopology", "commandBuffer, primitiveTopology", "void");
    device_dispatch_table(commandBuffer)->CmdSetPrimitiveTopology(commandBuffer, primitiveTopology);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetPrimitiveTopology(ApiDumpInstance::current(), commandBuffer, primitiveTopology);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetPrimitiveTopology(ApiDumpInstance::current(), commandBuffer, primitiveTopology);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetPrimitiveTopology(ApiDumpInstance::current(), commandBuffer, primitiveTopology);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetViewportWithCount", "commandBuffer, viewportCount, pViewports", "void");
    device_dispatch_table(commandBuffer)->CmdSetViewportWithCount(commandBuffer, viewportCount, pViewports);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetViewportWithCount(ApiDumpInstance::current(), commandBuffer, viewportCount, pViewports);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetViewportWithCount(ApiDumpInstance::current(), commandBuffer, viewportCount, pViewports);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetViewportWithCount(ApiDumpInstance::current(), commandBuffer, viewportCount, pViewports);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetScissorWithCount", "commandBuffer, scissorCount, pScissors", "void");
    device_dispatch_table(commandBuffer)->CmdSetScissorWithCount(commandBuffer, scissorCount, pScissors);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetScissorWithCount(ApiDumpInstance::current(), commandBuffer, scissorCount, pScissors);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetScissorWithCount(ApiDumpInstance::current(), commandBuffer, scissorCount, pScissors);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetScissorWithCount(ApiDumpInstance::current(), commandBuffer, scissorCount, pScissors);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdBindVertexBuffers2", "commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides", "void");
    device_dispatch_table(commandBuffer)->CmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdBindVertexBuffers2(ApiDumpInstance::current(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdBindVertexBuffers2(ApiDumpInstance::current(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdBindVertexBuffers2(ApiDumpInstance::current(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetDepthTestEnable", "commandBuffer, depthTestEnable", "void");
    device_dispatch_table(commandBuffer)->CmdSetDepthTestEnable(commandBuffer, depthTestEnable);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetDepthTestEnable(ApiDumpInstance::current(), commandBuffer, depthTestEnable);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetDepthTestEnable(ApiDumpInstance::current(), commandBuffer, depthTestEnable);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetDepthTestEnable(ApiDumpInstance::current(), commandBuffer, depthTestEnable);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetDepthWriteEnable", "commandBuffer, depthWriteEnable", "void");
    device_dispatch_table(commandBuffer)->CmdSetDepthWriteEnable(commandBuffer, depthWriteEnable);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetDepthWriteEnable(ApiDumpInstance::current(), commandBuffer, depthWriteEnable);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetDepthWriteEnable(ApiDumpInstance::current(), commandBuffer, depthWriteEnable);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetDepthWriteEnable(ApiDumpInstance::current(), commandBuffer, depthWriteEnable);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetDepthCompareOp", "commandBuffer, depthCompareOp", "void");
    device_dispatch_table(commandBuffer)->CmdSetDepthCompareOp(commandBuffer, depthCompareOp);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetDepthCompareOp(ApiDumpInstance::current(), commandBuffer, depthCompareOp);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetDepthCompareOp(ApiDumpInstance::current(), commandBuffer, depthCompareOp);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetDepthCompareOp(ApiDumpInstance::current(), commandBuffer, depthCompareOp);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetDepthBoundsTestEnable", "commandBuffer, depthBoundsTestEnable", "void");
    device_dispatch_table(commandBuffer)->CmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetDepthBoundsTestEnable(ApiDumpInstance::current(), commandBuffer, depthBoundsTestEnable);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetDepthBoundsTestEnable(ApiDumpInstance::current(), commandBuffer, depthBoundsTestEnable);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetDepthBoundsTestEnable(ApiDumpInstance::current(), commandBuffer, depthBoundsTestEnable);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetStencilTestEnable", "commandBuffer, stencilTestEnable", "void");
    device_dispatch_table(commandBuffer)->CmdSetStencilTestEnable(commandBuffer, stencilTestEnable);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetStencilTestEnable(ApiDumpInstance::current(), commandBuffer, stencilTestEnable);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetStencilTestEnable(ApiDumpInstance::current(), commandBuffer, stencilTestEnable);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetStencilTestEnable(ApiDumpInstance::current(), commandBuffer, stencilTestEnable);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetStencilOp", "commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp", "void");
    device_dispatch_table(commandBuffer)->CmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetStencilOp(ApiDumpInstance::current(), commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetStencilOp(ApiDumpInstance::current(), commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetStencilOp(ApiDumpInstance::current(), commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetRasterizerDiscardEnable", "commandBuffer, rasterizerDiscardEnable", "void");
    device_dispatch_table(commandBuffer)->CmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetRasterizerDiscardEnable(ApiDumpInstance::current(), commandBuffer, rasterizerDiscardEnable);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetRasterizerDiscardEnable(ApiDumpInstance::current(), commandBuffer, rasterizerDiscardEnable);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetRasterizerDiscardEnable(ApiDumpInstance::current(), commandBuffer, rasterizerDiscardEnable);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetDepthBiasEnable", "commandBuffer, depthBiasEnable", "void");
    device_dispatch_table(commandBuffer)->CmdSetDepthBiasEnable(commandBuffer, depthBiasEnable);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetDepthBiasEnable(ApiDumpInstance::current(), commandBuffer, depthBiasEnable);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetDepthBiasEnable(ApiDumpInstance::current(), commandBuffer, depthBiasEnable);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetDepthBiasEnable(ApiDumpInstance::current(), commandBuffer, depthBiasEnable);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetPrimitiveRestartEnable", "commandBuffer, primitiveRestartEnable", "void");
    device_dispatch_table(commandBuffer)->CmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetPrimitiveRestartEnable(ApiDumpInstance::current(), commandBuffer, primitiveRestartEnable);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetPrimitiveRestartEnable(ApiDumpInstance::current(), commandBuffer, primitiveRestartEnable);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetPrimitiveRestartEnable(ApiDumpInstance::current(), commandBuffer, primitiveRestartEnable);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetDeviceBufferMemoryRequirements(VkDevice device, const VkDeviceBufferMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDeviceBufferMemoryRequirements", "device, pInfo, pMemoryRequirements", "void");
    device_dispatch_table(device)->GetDeviceBufferMemoryRequirements(device, pInfo, pMemoryRequirements);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDeviceBufferMemoryRequirements(ApiDumpInstance::current(), device, pInfo, pMemoryRequirements);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDeviceBufferMemoryRequirements(ApiDumpInstance::current(), device, pInfo, pMemoryRequirements);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDeviceBufferMemoryRequirements(ApiDumpInstance::current(), device, pInfo, pMemoryRequirements);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetDeviceImageMemoryRequirements(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDeviceImageMemoryRequirements", "device, pInfo, pMemoryRequirements", "void");
    device_dispatch_table(device)->GetDeviceImageMemoryRequirements(device, pInfo, pMemoryRequirements);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDeviceImageMemoryRequirements(ApiDumpInstance::current(), device, pInfo, pMemoryRequirements);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDeviceImageMemoryRequirements(ApiDumpInstance::current(), device, pInfo, pMemoryRequirements);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDeviceImageMemoryRequirements(ApiDumpInstance::current(), device, pInfo, pMemoryRequirements);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetDeviceImageSparseMemoryRequirements(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDeviceImageSparseMemoryRequirements", "device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements", "void");
    device_dispatch_table(device)->GetDeviceImageSparseMemoryRequirements(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDeviceImageSparseMemoryRequirements(ApiDumpInstance::current(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDeviceImageSparseMemoryRequirements(ApiDumpInstance::current(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDeviceImageSparseMemoryRequirements(ApiDumpInstance::current(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateSwapchainKHR", "device, pCreateInfo, pAllocator, pSwapchain", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateSwapchainKHR(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pSwapchain);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateSwapchainKHR(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pSwapchain);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateSwapchainKHR(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pSwapchain);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroySwapchainKHR(VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroySwapchainKHR", "device, swapchain, pAllocator", "void");
    device_dispatch_table(device)->DestroySwapchainKHR(device, swapchain, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroySwapchainKHR(ApiDumpInstance::current(), device, swapchain, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroySwapchainKHR(ApiDumpInstance::current(), device, swapchain, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroySwapchainKHR(ApiDumpInstance::current(), device, swapchain, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetSwapchainImagesKHR(VkDevice device, VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetSwapchainImagesKHR", "device, swapchain, pSwapchainImageCount, pSwapchainImages", "VkResult");
    VkResult result = device_dispatch_table(device)->GetSwapchainImagesKHR(device, swapchain, pSwapchainImageCount, pSwapchainImages);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetSwapchainImagesKHR(ApiDumpInstance::current(), result, device, swapchain, pSwapchainImageCount, pSwapchainImages);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetSwapchainImagesKHR(ApiDumpInstance::current(), result, device, swapchain, pSwapchainImageCount, pSwapchainImages);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetSwapchainImagesKHR(ApiDumpInstance::current(), result, device, swapchain, pSwapchainImageCount, pSwapchainImages);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkAcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex)
{
    VkResult result = device_dispatch_table(device)->AcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex);
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkAcquireNextImageKHR", "device, swapchain, timeout, semaphore, fence, pImageIndex", "VkResult");
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkAcquireNextImageKHR(ApiDumpInstance::current(), result, device, swapchain, timeout, semaphore, fence, pImageIndex);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkAcquireNextImageKHR(ApiDumpInstance::current(), result, device, swapchain, timeout, semaphore, fence, pImageIndex);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkAcquireNextImageKHR(ApiDumpInstance::current(), result, device, swapchain, timeout, semaphore, fence, pImageIndex);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkQueuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo)
{
    VkResult result = device_dispatch_table(queue)->QueuePresentKHR(queue, pPresentInfo);
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkQueuePresentKHR", "queue, pPresentInfo", "VkResult");
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkQueuePresentKHR(ApiDumpInstance::current(), result, queue, pPresentInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkQueuePresentKHR(ApiDumpInstance::current(), result, queue, pPresentInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkQueuePresentKHR(ApiDumpInstance::current(), result, queue, pPresentInfo);
                break;
        }
    }
    ApiDumpInstance::current().nextFrame();
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetDeviceGroupPresentCapabilitiesKHR(VkDevice device, VkDeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDeviceGroupPresentCapabilitiesKHR", "device, pDeviceGroupPresentCapabilities", "VkResult");
    VkResult result = device_dispatch_table(device)->GetDeviceGroupPresentCapabilitiesKHR(device, pDeviceGroupPresentCapabilities);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDeviceGroupPresentCapabilitiesKHR(ApiDumpInstance::current(), result, device, pDeviceGroupPresentCapabilities);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDeviceGroupPresentCapabilitiesKHR(ApiDumpInstance::current(), result, device, pDeviceGroupPresentCapabilities);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDeviceGroupPresentCapabilitiesKHR(ApiDumpInstance::current(), result, device, pDeviceGroupPresentCapabilities);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetDeviceGroupSurfacePresentModesKHR(VkDevice device, VkSurfaceKHR surface, VkDeviceGroupPresentModeFlagsKHR* pModes)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDeviceGroupSurfacePresentModesKHR", "device, surface, pModes", "VkResult");
    VkResult result = device_dispatch_table(device)->GetDeviceGroupSurfacePresentModesKHR(device, surface, pModes);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDeviceGroupSurfacePresentModesKHR(ApiDumpInstance::current(), result, device, surface, pModes);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDeviceGroupSurfacePresentModesKHR(ApiDumpInstance::current(), result, device, surface, pModes);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDeviceGroupSurfacePresentModesKHR(ApiDumpInstance::current(), result, device, surface, pModes);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkAcquireNextImage2KHR(VkDevice device, const VkAcquireNextImageInfoKHR* pAcquireInfo, uint32_t* pImageIndex)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkAcquireNextImage2KHR", "device, pAcquireInfo, pImageIndex", "VkResult");
    VkResult result = device_dispatch_table(device)->AcquireNextImage2KHR(device, pAcquireInfo, pImageIndex);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkAcquireNextImage2KHR(ApiDumpInstance::current(), result, device, pAcquireInfo, pImageIndex);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkAcquireNextImage2KHR(ApiDumpInstance::current(), result, device, pAcquireInfo, pImageIndex);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkAcquireNextImage2KHR(ApiDumpInstance::current(), result, device, pAcquireInfo, pImageIndex);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateSharedSwapchainsKHR(VkDevice device, uint32_t swapchainCount, const VkSwapchainCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchains)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateSharedSwapchainsKHR", "device, swapchainCount, pCreateInfos, pAllocator, pSwapchains", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateSharedSwapchainsKHR(device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateSharedSwapchainsKHR(ApiDumpInstance::current(), result, device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateSharedSwapchainsKHR(ApiDumpInstance::current(), result, device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateSharedSwapchainsKHR(ApiDumpInstance::current(), result, device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkDebugMarkerSetObjectTagEXT(VkDevice device, const VkDebugMarkerObjectTagInfoEXT* pTagInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDebugMarkerSetObjectTagEXT", "device, pTagInfo", "VkResult");
    VkResult result = device_dispatch_table(device)->DebugMarkerSetObjectTagEXT(device, pTagInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDebugMarkerSetObjectTagEXT(ApiDumpInstance::current(), result, device, pTagInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDebugMarkerSetObjectTagEXT(ApiDumpInstance::current(), result, device, pTagInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDebugMarkerSetObjectTagEXT(ApiDumpInstance::current(), result, device, pTagInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkDebugMarkerSetObjectNameEXT(VkDevice device, const VkDebugMarkerObjectNameInfoEXT* pNameInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    ApiDumpInstance::current().update_object_name_map(pNameInfo);
    dump_function_head(ApiDumpInstance::current(), "vkDebugMarkerSetObjectNameEXT", "device, pNameInfo", "VkResult");
    VkResult result = device_dispatch_table(device)->DebugMarkerSetObjectNameEXT(device, pNameInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDebugMarkerSetObjectNameEXT(ApiDumpInstance::current(), result, device, pNameInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDebugMarkerSetObjectNameEXT(ApiDumpInstance::current(), result, device, pNameInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDebugMarkerSetObjectNameEXT(ApiDumpInstance::current(), result, device, pNameInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdDebugMarkerBeginEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdDebugMarkerBeginEXT", "commandBuffer, pMarkerInfo", "void");
    device_dispatch_table(commandBuffer)->CmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdDebugMarkerBeginEXT(ApiDumpInstance::current(), commandBuffer, pMarkerInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdDebugMarkerBeginEXT(ApiDumpInstance::current(), commandBuffer, pMarkerInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdDebugMarkerBeginEXT(ApiDumpInstance::current(), commandBuffer, pMarkerInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdDebugMarkerEndEXT", "commandBuffer", "void");
    device_dispatch_table(commandBuffer)->CmdDebugMarkerEndEXT(commandBuffer);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdDebugMarkerEndEXT(ApiDumpInstance::current(), commandBuffer);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdDebugMarkerEndEXT(ApiDumpInstance::current(), commandBuffer);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdDebugMarkerEndEXT(ApiDumpInstance::current(), commandBuffer);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdDebugMarkerInsertEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdDebugMarkerInsertEXT", "commandBuffer, pMarkerInfo", "void");
    device_dispatch_table(commandBuffer)->CmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdDebugMarkerInsertEXT(ApiDumpInstance::current(), commandBuffer, pMarkerInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdDebugMarkerInsertEXT(ApiDumpInstance::current(), commandBuffer, pMarkerInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdDebugMarkerInsertEXT(ApiDumpInstance::current(), commandBuffer, pMarkerInfo);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateVideoSessionKHR(VkDevice device, const VkVideoSessionCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkVideoSessionKHR* pVideoSession)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateVideoSessionKHR", "device, pCreateInfo, pAllocator, pVideoSession", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateVideoSessionKHR(device, pCreateInfo, pAllocator, pVideoSession);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateVideoSessionKHR(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pVideoSession);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateVideoSessionKHR(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pVideoSession);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateVideoSessionKHR(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pVideoSession);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyVideoSessionKHR(VkDevice device, VkVideoSessionKHR videoSession, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyVideoSessionKHR", "device, videoSession, pAllocator", "void");
    device_dispatch_table(device)->DestroyVideoSessionKHR(device, videoSession, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyVideoSessionKHR(ApiDumpInstance::current(), device, videoSession, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyVideoSessionKHR(ApiDumpInstance::current(), device, videoSession, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyVideoSessionKHR(ApiDumpInstance::current(), device, videoSession, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetVideoSessionMemoryRequirementsKHR(VkDevice device, VkVideoSessionKHR videoSession, uint32_t* pMemoryRequirementsCount, VkVideoSessionMemoryRequirementsKHR* pMemoryRequirements)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetVideoSessionMemoryRequirementsKHR", "device, videoSession, pMemoryRequirementsCount, pMemoryRequirements", "VkResult");
    VkResult result = device_dispatch_table(device)->GetVideoSessionMemoryRequirementsKHR(device, videoSession, pMemoryRequirementsCount, pMemoryRequirements);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetVideoSessionMemoryRequirementsKHR(ApiDumpInstance::current(), result, device, videoSession, pMemoryRequirementsCount, pMemoryRequirements);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetVideoSessionMemoryRequirementsKHR(ApiDumpInstance::current(), result, device, videoSession, pMemoryRequirementsCount, pMemoryRequirements);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetVideoSessionMemoryRequirementsKHR(ApiDumpInstance::current(), result, device, videoSession, pMemoryRequirementsCount, pMemoryRequirements);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkBindVideoSessionMemoryKHR(VkDevice device, VkVideoSessionKHR videoSession, uint32_t bindSessionMemoryInfoCount, const VkBindVideoSessionMemoryInfoKHR* pBindSessionMemoryInfos)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkBindVideoSessionMemoryKHR", "device, videoSession, bindSessionMemoryInfoCount, pBindSessionMemoryInfos", "VkResult");
    VkResult result = device_dispatch_table(device)->BindVideoSessionMemoryKHR(device, videoSession, bindSessionMemoryInfoCount, pBindSessionMemoryInfos);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkBindVideoSessionMemoryKHR(ApiDumpInstance::current(), result, device, videoSession, bindSessionMemoryInfoCount, pBindSessionMemoryInfos);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkBindVideoSessionMemoryKHR(ApiDumpInstance::current(), result, device, videoSession, bindSessionMemoryInfoCount, pBindSessionMemoryInfos);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkBindVideoSessionMemoryKHR(ApiDumpInstance::current(), result, device, videoSession, bindSessionMemoryInfoCount, pBindSessionMemoryInfos);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateVideoSessionParametersKHR(VkDevice device, const VkVideoSessionParametersCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkVideoSessionParametersKHR* pVideoSessionParameters)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateVideoSessionParametersKHR", "device, pCreateInfo, pAllocator, pVideoSessionParameters", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateVideoSessionParametersKHR(device, pCreateInfo, pAllocator, pVideoSessionParameters);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateVideoSessionParametersKHR(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pVideoSessionParameters);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateVideoSessionParametersKHR(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pVideoSessionParameters);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateVideoSessionParametersKHR(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pVideoSessionParameters);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkUpdateVideoSessionParametersKHR(VkDevice device, VkVideoSessionParametersKHR videoSessionParameters, const VkVideoSessionParametersUpdateInfoKHR* pUpdateInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkUpdateVideoSessionParametersKHR", "device, videoSessionParameters, pUpdateInfo", "VkResult");
    VkResult result = device_dispatch_table(device)->UpdateVideoSessionParametersKHR(device, videoSessionParameters, pUpdateInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkUpdateVideoSessionParametersKHR(ApiDumpInstance::current(), result, device, videoSessionParameters, pUpdateInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkUpdateVideoSessionParametersKHR(ApiDumpInstance::current(), result, device, videoSessionParameters, pUpdateInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkUpdateVideoSessionParametersKHR(ApiDumpInstance::current(), result, device, videoSessionParameters, pUpdateInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyVideoSessionParametersKHR(VkDevice device, VkVideoSessionParametersKHR videoSessionParameters, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyVideoSessionParametersKHR", "device, videoSessionParameters, pAllocator", "void");
    device_dispatch_table(device)->DestroyVideoSessionParametersKHR(device, videoSessionParameters, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyVideoSessionParametersKHR(ApiDumpInstance::current(), device, videoSessionParameters, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyVideoSessionParametersKHR(ApiDumpInstance::current(), device, videoSessionParameters, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyVideoSessionParametersKHR(ApiDumpInstance::current(), device, videoSessionParameters, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdBeginVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoBeginCodingInfoKHR* pBeginInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdBeginVideoCodingKHR", "commandBuffer, pBeginInfo", "void");
    device_dispatch_table(commandBuffer)->CmdBeginVideoCodingKHR(commandBuffer, pBeginInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdBeginVideoCodingKHR(ApiDumpInstance::current(), commandBuffer, pBeginInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdBeginVideoCodingKHR(ApiDumpInstance::current(), commandBuffer, pBeginInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdBeginVideoCodingKHR(ApiDumpInstance::current(), commandBuffer, pBeginInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdEndVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoEndCodingInfoKHR* pEndCodingInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdEndVideoCodingKHR", "commandBuffer, pEndCodingInfo", "void");
    device_dispatch_table(commandBuffer)->CmdEndVideoCodingKHR(commandBuffer, pEndCodingInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdEndVideoCodingKHR(ApiDumpInstance::current(), commandBuffer, pEndCodingInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdEndVideoCodingKHR(ApiDumpInstance::current(), commandBuffer, pEndCodingInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdEndVideoCodingKHR(ApiDumpInstance::current(), commandBuffer, pEndCodingInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdControlVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoCodingControlInfoKHR* pCodingControlInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdControlVideoCodingKHR", "commandBuffer, pCodingControlInfo", "void");
    device_dispatch_table(commandBuffer)->CmdControlVideoCodingKHR(commandBuffer, pCodingControlInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdControlVideoCodingKHR(ApiDumpInstance::current(), commandBuffer, pCodingControlInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdControlVideoCodingKHR(ApiDumpInstance::current(), commandBuffer, pCodingControlInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdControlVideoCodingKHR(ApiDumpInstance::current(), commandBuffer, pCodingControlInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdDecodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pDecodeInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdDecodeVideoKHR", "commandBuffer, pDecodeInfo", "void");
    device_dispatch_table(commandBuffer)->CmdDecodeVideoKHR(commandBuffer, pDecodeInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdDecodeVideoKHR(ApiDumpInstance::current(), commandBuffer, pDecodeInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdDecodeVideoKHR(ApiDumpInstance::current(), commandBuffer, pDecodeInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdDecodeVideoKHR(ApiDumpInstance::current(), commandBuffer, pDecodeInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindTransformFeedbackBuffersEXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdBindTransformFeedbackBuffersEXT", "commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes", "void");
    device_dispatch_table(commandBuffer)->CmdBindTransformFeedbackBuffersEXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdBindTransformFeedbackBuffersEXT(ApiDumpInstance::current(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdBindTransformFeedbackBuffersEXT(ApiDumpInstance::current(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdBindTransformFeedbackBuffersEXT(ApiDumpInstance::current(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdBeginTransformFeedbackEXT", "commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets", "void");
    device_dispatch_table(commandBuffer)->CmdBeginTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdBeginTransformFeedbackEXT(ApiDumpInstance::current(), commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdBeginTransformFeedbackEXT(ApiDumpInstance::current(), commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdBeginTransformFeedbackEXT(ApiDumpInstance::current(), commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdEndTransformFeedbackEXT", "commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets", "void");
    device_dispatch_table(commandBuffer)->CmdEndTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdEndTransformFeedbackEXT(ApiDumpInstance::current(), commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdEndTransformFeedbackEXT(ApiDumpInstance::current(), commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdEndTransformFeedbackEXT(ApiDumpInstance::current(), commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags, uint32_t index)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdBeginQueryIndexedEXT", "commandBuffer, queryPool, query, flags, index", "void");
    device_dispatch_table(commandBuffer)->CmdBeginQueryIndexedEXT(commandBuffer, queryPool, query, flags, index);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdBeginQueryIndexedEXT(ApiDumpInstance::current(), commandBuffer, queryPool, query, flags, index);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdBeginQueryIndexedEXT(ApiDumpInstance::current(), commandBuffer, queryPool, query, flags, index);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdBeginQueryIndexedEXT(ApiDumpInstance::current(), commandBuffer, queryPool, query, flags, index);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, uint32_t index)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdEndQueryIndexedEXT", "commandBuffer, queryPool, query, index", "void");
    device_dispatch_table(commandBuffer)->CmdEndQueryIndexedEXT(commandBuffer, queryPool, query, index);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdEndQueryIndexedEXT(ApiDumpInstance::current(), commandBuffer, queryPool, query, index);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdEndQueryIndexedEXT(ApiDumpInstance::current(), commandBuffer, queryPool, query, index);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdEndQueryIndexedEXT(ApiDumpInstance::current(), commandBuffer, queryPool, query, index);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndirectByteCountEXT(VkCommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance, VkBuffer counterBuffer, VkDeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdDrawIndirectByteCountEXT", "commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride", "void");
    device_dispatch_table(commandBuffer)->CmdDrawIndirectByteCountEXT(commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdDrawIndirectByteCountEXT(ApiDumpInstance::current(), commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdDrawIndirectByteCountEXT(ApiDumpInstance::current(), commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdDrawIndirectByteCountEXT(ApiDumpInstance::current(), commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateCuModuleNVX(VkDevice device, const VkCuModuleCreateInfoNVX* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCuModuleNVX* pModule)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateCuModuleNVX", "device, pCreateInfo, pAllocator, pModule", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateCuModuleNVX(device, pCreateInfo, pAllocator, pModule);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateCuModuleNVX(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pModule);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateCuModuleNVX(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pModule);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateCuModuleNVX(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pModule);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateCuFunctionNVX(VkDevice device, const VkCuFunctionCreateInfoNVX* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCuFunctionNVX* pFunction)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateCuFunctionNVX", "device, pCreateInfo, pAllocator, pFunction", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateCuFunctionNVX(device, pCreateInfo, pAllocator, pFunction);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateCuFunctionNVX(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pFunction);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateCuFunctionNVX(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pFunction);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateCuFunctionNVX(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pFunction);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyCuModuleNVX(VkDevice device, VkCuModuleNVX module, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyCuModuleNVX", "device, module, pAllocator", "void");
    device_dispatch_table(device)->DestroyCuModuleNVX(device, module, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyCuModuleNVX(ApiDumpInstance::current(), device, module, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyCuModuleNVX(ApiDumpInstance::current(), device, module, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyCuModuleNVX(ApiDumpInstance::current(), device, module, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkDestroyCuFunctionNVX(VkDevice device, VkCuFunctionNVX function, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyCuFunctionNVX", "device, function, pAllocator", "void");
    device_dispatch_table(device)->DestroyCuFunctionNVX(device, function, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyCuFunctionNVX(ApiDumpInstance::current(), device, function, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyCuFunctionNVX(ApiDumpInstance::current(), device, function, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyCuFunctionNVX(ApiDumpInstance::current(), device, function, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdCuLaunchKernelNVX(VkCommandBuffer commandBuffer, const VkCuLaunchInfoNVX* pLaunchInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdCuLaunchKernelNVX", "commandBuffer, pLaunchInfo", "void");
    device_dispatch_table(commandBuffer)->CmdCuLaunchKernelNVX(commandBuffer, pLaunchInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdCuLaunchKernelNVX(ApiDumpInstance::current(), commandBuffer, pLaunchInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdCuLaunchKernelNVX(ApiDumpInstance::current(), commandBuffer, pLaunchInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdCuLaunchKernelNVX(ApiDumpInstance::current(), commandBuffer, pLaunchInfo);
                break;
        }
    }
}
VKAPI_ATTR uint32_t VKAPI_CALL vkGetImageViewHandleNVX(VkDevice device, const VkImageViewHandleInfoNVX* pInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetImageViewHandleNVX", "device, pInfo", "uint32_t");
    uint32_t result = device_dispatch_table(device)->GetImageViewHandleNVX(device, pInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetImageViewHandleNVX(ApiDumpInstance::current(), result, device, pInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetImageViewHandleNVX(ApiDumpInstance::current(), result, device, pInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetImageViewHandleNVX(ApiDumpInstance::current(), result, device, pInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetImageViewAddressNVX(VkDevice device, VkImageView imageView, VkImageViewAddressPropertiesNVX* pProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetImageViewAddressNVX", "device, imageView, pProperties", "VkResult");
    VkResult result = device_dispatch_table(device)->GetImageViewAddressNVX(device, imageView, pProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetImageViewAddressNVX(ApiDumpInstance::current(), result, device, imageView, pProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetImageViewAddressNVX(ApiDumpInstance::current(), result, device, imageView, pProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetImageViewAddressNVX(ApiDumpInstance::current(), result, device, imageView, pProperties);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdDrawIndirectCountAMD", "commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride", "void");
    device_dispatch_table(commandBuffer)->CmdDrawIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdDrawIndirectCountAMD(ApiDumpInstance::current(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdDrawIndirectCountAMD(ApiDumpInstance::current(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdDrawIndirectCountAMD(ApiDumpInstance::current(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndexedIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdDrawIndexedIndirectCountAMD", "commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride", "void");
    device_dispatch_table(commandBuffer)->CmdDrawIndexedIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdDrawIndexedIndirectCountAMD(ApiDumpInstance::current(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdDrawIndexedIndirectCountAMD(ApiDumpInstance::current(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdDrawIndexedIndirectCountAMD(ApiDumpInstance::current(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetShaderInfoAMD(VkDevice device, VkPipeline pipeline, VkShaderStageFlagBits shaderStage, VkShaderInfoTypeAMD infoType, size_t* pInfoSize, void* pInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetShaderInfoAMD", "device, pipeline, shaderStage, infoType, pInfoSize, pInfo", "VkResult");
    VkResult result = device_dispatch_table(device)->GetShaderInfoAMD(device, pipeline, shaderStage, infoType, pInfoSize, pInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetShaderInfoAMD(ApiDumpInstance::current(), result, device, pipeline, shaderStage, infoType, pInfoSize, pInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetShaderInfoAMD(ApiDumpInstance::current(), result, device, pipeline, shaderStage, infoType, pInfoSize, pInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetShaderInfoAMD(ApiDumpInstance::current(), result, device, pipeline, shaderStage, infoType, pInfoSize, pInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdBeginRenderingKHR(VkCommandBuffer                   commandBuffer, const VkRenderingInfo*                              pRenderingInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdBeginRenderingKHR", "commandBuffer, pRenderingInfo", "void");
    device_dispatch_table(commandBuffer)->CmdBeginRenderingKHR(commandBuffer, pRenderingInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdBeginRenderingKHR(ApiDumpInstance::current(), commandBuffer, pRenderingInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdBeginRenderingKHR(ApiDumpInstance::current(), commandBuffer, pRenderingInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdBeginRenderingKHR(ApiDumpInstance::current(), commandBuffer, pRenderingInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdEndRenderingKHR(VkCommandBuffer                   commandBuffer)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdEndRenderingKHR", "commandBuffer", "void");
    device_dispatch_table(commandBuffer)->CmdEndRenderingKHR(commandBuffer);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdEndRenderingKHR(ApiDumpInstance::current(), commandBuffer);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdEndRenderingKHR(ApiDumpInstance::current(), commandBuffer);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdEndRenderingKHR(ApiDumpInstance::current(), commandBuffer);
                break;
        }
    }
}
#if defined(VK_USE_PLATFORM_WIN32_KHR)
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryWin32HandleNV(VkDevice device, VkDeviceMemory memory, VkExternalMemoryHandleTypeFlagsNV handleType, HANDLE* pHandle)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetMemoryWin32HandleNV", "device, memory, handleType, pHandle", "VkResult");
    VkResult result = device_dispatch_table(device)->GetMemoryWin32HandleNV(device, memory, handleType, pHandle);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetMemoryWin32HandleNV(ApiDumpInstance::current(), result, device, memory, handleType, pHandle);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetMemoryWin32HandleNV(ApiDumpInstance::current(), result, device, memory, handleType, pHandle);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetMemoryWin32HandleNV(ApiDumpInstance::current(), result, device, memory, handleType, pHandle);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_WIN32_KHR
VKAPI_ATTR void VKAPI_CALL vkGetDeviceGroupPeerMemoryFeaturesKHR(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDeviceGroupPeerMemoryFeaturesKHR", "device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures", "void");
    device_dispatch_table(device)->GetDeviceGroupPeerMemoryFeaturesKHR(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDeviceGroupPeerMemoryFeaturesKHR(ApiDumpInstance::current(), device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDeviceGroupPeerMemoryFeaturesKHR(ApiDumpInstance::current(), device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDeviceGroupPeerMemoryFeaturesKHR(ApiDumpInstance::current(), device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDeviceMaskKHR(VkCommandBuffer commandBuffer, uint32_t deviceMask)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetDeviceMaskKHR", "commandBuffer, deviceMask", "void");
    device_dispatch_table(commandBuffer)->CmdSetDeviceMaskKHR(commandBuffer, deviceMask);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetDeviceMaskKHR(ApiDumpInstance::current(), commandBuffer, deviceMask);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetDeviceMaskKHR(ApiDumpInstance::current(), commandBuffer, deviceMask);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetDeviceMaskKHR(ApiDumpInstance::current(), commandBuffer, deviceMask);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdDispatchBaseKHR(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdDispatchBaseKHR", "commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ", "void");
    device_dispatch_table(commandBuffer)->CmdDispatchBaseKHR(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdDispatchBaseKHR(ApiDumpInstance::current(), commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdDispatchBaseKHR(ApiDumpInstance::current(), commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdDispatchBaseKHR(ApiDumpInstance::current(), commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkTrimCommandPoolKHR(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkTrimCommandPoolKHR", "device, commandPool, flags", "void");
    device_dispatch_table(device)->TrimCommandPoolKHR(device, commandPool, flags);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkTrimCommandPoolKHR(ApiDumpInstance::current(), device, commandPool, flags);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkTrimCommandPoolKHR(ApiDumpInstance::current(), device, commandPool, flags);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkTrimCommandPoolKHR(ApiDumpInstance::current(), device, commandPool, flags);
                break;
        }
    }
}
#if defined(VK_USE_PLATFORM_WIN32_KHR)
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryWin32HandleKHR(VkDevice device, const VkMemoryGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetMemoryWin32HandleKHR", "device, pGetWin32HandleInfo, pHandle", "VkResult");
    VkResult result = device_dispatch_table(device)->GetMemoryWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetMemoryWin32HandleKHR(ApiDumpInstance::current(), result, device, pGetWin32HandleInfo, pHandle);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetMemoryWin32HandleKHR(ApiDumpInstance::current(), result, device, pGetWin32HandleInfo, pHandle);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetMemoryWin32HandleKHR(ApiDumpInstance::current(), result, device, pGetWin32HandleInfo, pHandle);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryWin32HandlePropertiesKHR(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, HANDLE handle, VkMemoryWin32HandlePropertiesKHR* pMemoryWin32HandleProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetMemoryWin32HandlePropertiesKHR", "device, handleType, handle, pMemoryWin32HandleProperties", "VkResult");
    VkResult result = device_dispatch_table(device)->GetMemoryWin32HandlePropertiesKHR(device, handleType, handle, pMemoryWin32HandleProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetMemoryWin32HandlePropertiesKHR(ApiDumpInstance::current(), result, device, handleType, handle, pMemoryWin32HandleProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetMemoryWin32HandlePropertiesKHR(ApiDumpInstance::current(), result, device, handleType, handle, pMemoryWin32HandleProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetMemoryWin32HandlePropertiesKHR(ApiDumpInstance::current(), result, device, handleType, handle, pMemoryWin32HandleProperties);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_WIN32_KHR
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryFdKHR(VkDevice device, const VkMemoryGetFdInfoKHR* pGetFdInfo, int* pFd)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetMemoryFdKHR", "device, pGetFdInfo, pFd", "VkResult");
    VkResult result = device_dispatch_table(device)->GetMemoryFdKHR(device, pGetFdInfo, pFd);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetMemoryFdKHR(ApiDumpInstance::current(), result, device, pGetFdInfo, pFd);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetMemoryFdKHR(ApiDumpInstance::current(), result, device, pGetFdInfo, pFd);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetMemoryFdKHR(ApiDumpInstance::current(), result, device, pGetFdInfo, pFd);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryFdPropertiesKHR(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, int fd, VkMemoryFdPropertiesKHR* pMemoryFdProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetMemoryFdPropertiesKHR", "device, handleType, fd, pMemoryFdProperties", "VkResult");
    VkResult result = device_dispatch_table(device)->GetMemoryFdPropertiesKHR(device, handleType, fd, pMemoryFdProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetMemoryFdPropertiesKHR(ApiDumpInstance::current(), result, device, handleType, fd, pMemoryFdProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetMemoryFdPropertiesKHR(ApiDumpInstance::current(), result, device, handleType, fd, pMemoryFdProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetMemoryFdPropertiesKHR(ApiDumpInstance::current(), result, device, handleType, fd, pMemoryFdProperties);
                break;
        }
    }
    return result;
}
#if defined(VK_USE_PLATFORM_WIN32_KHR)
VKAPI_ATTR VkResult VKAPI_CALL vkImportSemaphoreWin32HandleKHR(VkDevice device, const VkImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkImportSemaphoreWin32HandleKHR", "device, pImportSemaphoreWin32HandleInfo", "VkResult");
    VkResult result = device_dispatch_table(device)->ImportSemaphoreWin32HandleKHR(device, pImportSemaphoreWin32HandleInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkImportSemaphoreWin32HandleKHR(ApiDumpInstance::current(), result, device, pImportSemaphoreWin32HandleInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkImportSemaphoreWin32HandleKHR(ApiDumpInstance::current(), result, device, pImportSemaphoreWin32HandleInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkImportSemaphoreWin32HandleKHR(ApiDumpInstance::current(), result, device, pImportSemaphoreWin32HandleInfo);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
VKAPI_ATTR VkResult VKAPI_CALL vkGetSemaphoreWin32HandleKHR(VkDevice device, const VkSemaphoreGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetSemaphoreWin32HandleKHR", "device, pGetWin32HandleInfo, pHandle", "VkResult");
    VkResult result = device_dispatch_table(device)->GetSemaphoreWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetSemaphoreWin32HandleKHR(ApiDumpInstance::current(), result, device, pGetWin32HandleInfo, pHandle);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetSemaphoreWin32HandleKHR(ApiDumpInstance::current(), result, device, pGetWin32HandleInfo, pHandle);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetSemaphoreWin32HandleKHR(ApiDumpInstance::current(), result, device, pGetWin32HandleInfo, pHandle);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_WIN32_KHR
VKAPI_ATTR VkResult VKAPI_CALL vkImportSemaphoreFdKHR(VkDevice device, const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkImportSemaphoreFdKHR", "device, pImportSemaphoreFdInfo", "VkResult");
    VkResult result = device_dispatch_table(device)->ImportSemaphoreFdKHR(device, pImportSemaphoreFdInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkImportSemaphoreFdKHR(ApiDumpInstance::current(), result, device, pImportSemaphoreFdInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkImportSemaphoreFdKHR(ApiDumpInstance::current(), result, device, pImportSemaphoreFdInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkImportSemaphoreFdKHR(ApiDumpInstance::current(), result, device, pImportSemaphoreFdInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetSemaphoreFdKHR(VkDevice device, const VkSemaphoreGetFdInfoKHR* pGetFdInfo, int* pFd)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetSemaphoreFdKHR", "device, pGetFdInfo, pFd", "VkResult");
    VkResult result = device_dispatch_table(device)->GetSemaphoreFdKHR(device, pGetFdInfo, pFd);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetSemaphoreFdKHR(ApiDumpInstance::current(), result, device, pGetFdInfo, pFd);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetSemaphoreFdKHR(ApiDumpInstance::current(), result, device, pGetFdInfo, pFd);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetSemaphoreFdKHR(ApiDumpInstance::current(), result, device, pGetFdInfo, pFd);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSetKHR(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdPushDescriptorSetKHR", "commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites", "void");
    device_dispatch_table(commandBuffer)->CmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdPushDescriptorSetKHR(ApiDumpInstance::current(), commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdPushDescriptorSetKHR(ApiDumpInstance::current(), commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdPushDescriptorSetKHR(ApiDumpInstance::current(), commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer commandBuffer, VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout, uint32_t set, const void* pData)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdPushDescriptorSetWithTemplateKHR", "commandBuffer, descriptorUpdateTemplate, layout, set, pData", "void");
    device_dispatch_table(commandBuffer)->CmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate, layout, set, pData);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdPushDescriptorSetWithTemplateKHR(ApiDumpInstance::current(), commandBuffer, descriptorUpdateTemplate, layout, set, pData);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdPushDescriptorSetWithTemplateKHR(ApiDumpInstance::current(), commandBuffer, descriptorUpdateTemplate, layout, set, pData);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdPushDescriptorSetWithTemplateKHR(ApiDumpInstance::current(), commandBuffer, descriptorUpdateTemplate, layout, set, pData);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdBeginConditionalRenderingEXT(VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdBeginConditionalRenderingEXT", "commandBuffer, pConditionalRenderingBegin", "void");
    device_dispatch_table(commandBuffer)->CmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdBeginConditionalRenderingEXT(ApiDumpInstance::current(), commandBuffer, pConditionalRenderingBegin);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdBeginConditionalRenderingEXT(ApiDumpInstance::current(), commandBuffer, pConditionalRenderingBegin);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdBeginConditionalRenderingEXT(ApiDumpInstance::current(), commandBuffer, pConditionalRenderingBegin);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdEndConditionalRenderingEXT", "commandBuffer", "void");
    device_dispatch_table(commandBuffer)->CmdEndConditionalRenderingEXT(commandBuffer);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdEndConditionalRenderingEXT(ApiDumpInstance::current(), commandBuffer);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdEndConditionalRenderingEXT(ApiDumpInstance::current(), commandBuffer);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdEndConditionalRenderingEXT(ApiDumpInstance::current(), commandBuffer);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDescriptorUpdateTemplateKHR(VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateDescriptorUpdateTemplateKHR", "device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateDescriptorUpdateTemplateKHR(device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateDescriptorUpdateTemplateKHR(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateDescriptorUpdateTemplateKHR(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateDescriptorUpdateTemplateKHR(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyDescriptorUpdateTemplateKHR(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyDescriptorUpdateTemplateKHR", "device, descriptorUpdateTemplate, pAllocator", "void");
    device_dispatch_table(device)->DestroyDescriptorUpdateTemplateKHR(device, descriptorUpdateTemplate, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyDescriptorUpdateTemplateKHR(ApiDumpInstance::current(), device, descriptorUpdateTemplate, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyDescriptorUpdateTemplateKHR(ApiDumpInstance::current(), device, descriptorUpdateTemplate, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyDescriptorUpdateTemplateKHR(ApiDumpInstance::current(), device, descriptorUpdateTemplate, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkUpdateDescriptorSetWithTemplateKHR(VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkUpdateDescriptorSetWithTemplateKHR", "device, descriptorSet, descriptorUpdateTemplate, pData", "void");
    device_dispatch_table(device)->UpdateDescriptorSetWithTemplateKHR(device, descriptorSet, descriptorUpdateTemplate, pData);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkUpdateDescriptorSetWithTemplateKHR(ApiDumpInstance::current(), device, descriptorSet, descriptorUpdateTemplate, pData);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkUpdateDescriptorSetWithTemplateKHR(ApiDumpInstance::current(), device, descriptorSet, descriptorUpdateTemplate, pData);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkUpdateDescriptorSetWithTemplateKHR(ApiDumpInstance::current(), device, descriptorSet, descriptorUpdateTemplate, pData);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetViewportWScalingNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportWScalingNV* pViewportWScalings)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetViewportWScalingNV", "commandBuffer, firstViewport, viewportCount, pViewportWScalings", "void");
    device_dispatch_table(commandBuffer)->CmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, pViewportWScalings);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetViewportWScalingNV(ApiDumpInstance::current(), commandBuffer, firstViewport, viewportCount, pViewportWScalings);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetViewportWScalingNV(ApiDumpInstance::current(), commandBuffer, firstViewport, viewportCount, pViewportWScalings);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetViewportWScalingNV(ApiDumpInstance::current(), commandBuffer, firstViewport, viewportCount, pViewportWScalings);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkDisplayPowerControlEXT(VkDevice device, VkDisplayKHR display, const VkDisplayPowerInfoEXT* pDisplayPowerInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDisplayPowerControlEXT", "device, display, pDisplayPowerInfo", "VkResult");
    VkResult result = device_dispatch_table(device)->DisplayPowerControlEXT(device, display, pDisplayPowerInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDisplayPowerControlEXT(ApiDumpInstance::current(), result, device, display, pDisplayPowerInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDisplayPowerControlEXT(ApiDumpInstance::current(), result, device, display, pDisplayPowerInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDisplayPowerControlEXT(ApiDumpInstance::current(), result, device, display, pDisplayPowerInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkRegisterDeviceEventEXT(VkDevice device, const VkDeviceEventInfoEXT* pDeviceEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkRegisterDeviceEventEXT", "device, pDeviceEventInfo, pAllocator, pFence", "VkResult");
    VkResult result = device_dispatch_table(device)->RegisterDeviceEventEXT(device, pDeviceEventInfo, pAllocator, pFence);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkRegisterDeviceEventEXT(ApiDumpInstance::current(), result, device, pDeviceEventInfo, pAllocator, pFence);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkRegisterDeviceEventEXT(ApiDumpInstance::current(), result, device, pDeviceEventInfo, pAllocator, pFence);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkRegisterDeviceEventEXT(ApiDumpInstance::current(), result, device, pDeviceEventInfo, pAllocator, pFence);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkRegisterDisplayEventEXT(VkDevice device, VkDisplayKHR display, const VkDisplayEventInfoEXT* pDisplayEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkRegisterDisplayEventEXT", "device, display, pDisplayEventInfo, pAllocator, pFence", "VkResult");
    VkResult result = device_dispatch_table(device)->RegisterDisplayEventEXT(device, display, pDisplayEventInfo, pAllocator, pFence);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkRegisterDisplayEventEXT(ApiDumpInstance::current(), result, device, display, pDisplayEventInfo, pAllocator, pFence);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkRegisterDisplayEventEXT(ApiDumpInstance::current(), result, device, display, pDisplayEventInfo, pAllocator, pFence);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkRegisterDisplayEventEXT(ApiDumpInstance::current(), result, device, display, pDisplayEventInfo, pAllocator, pFence);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetSwapchainCounterEXT(VkDevice device, VkSwapchainKHR swapchain, VkSurfaceCounterFlagBitsEXT counter, uint64_t* pCounterValue)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetSwapchainCounterEXT", "device, swapchain, counter, pCounterValue", "VkResult");
    VkResult result = device_dispatch_table(device)->GetSwapchainCounterEXT(device, swapchain, counter, pCounterValue);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetSwapchainCounterEXT(ApiDumpInstance::current(), result, device, swapchain, counter, pCounterValue);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetSwapchainCounterEXT(ApiDumpInstance::current(), result, device, swapchain, counter, pCounterValue);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetSwapchainCounterEXT(ApiDumpInstance::current(), result, device, swapchain, counter, pCounterValue);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetRefreshCycleDurationGOOGLE(VkDevice device, VkSwapchainKHR swapchain, VkRefreshCycleDurationGOOGLE* pDisplayTimingProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetRefreshCycleDurationGOOGLE", "device, swapchain, pDisplayTimingProperties", "VkResult");
    VkResult result = device_dispatch_table(device)->GetRefreshCycleDurationGOOGLE(device, swapchain, pDisplayTimingProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetRefreshCycleDurationGOOGLE(ApiDumpInstance::current(), result, device, swapchain, pDisplayTimingProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetRefreshCycleDurationGOOGLE(ApiDumpInstance::current(), result, device, swapchain, pDisplayTimingProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetRefreshCycleDurationGOOGLE(ApiDumpInstance::current(), result, device, swapchain, pDisplayTimingProperties);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPastPresentationTimingGOOGLE(VkDevice device, VkSwapchainKHR swapchain, uint32_t* pPresentationTimingCount, VkPastPresentationTimingGOOGLE* pPresentationTimings)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPastPresentationTimingGOOGLE", "device, swapchain, pPresentationTimingCount, pPresentationTimings", "VkResult");
    VkResult result = device_dispatch_table(device)->GetPastPresentationTimingGOOGLE(device, swapchain, pPresentationTimingCount, pPresentationTimings);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPastPresentationTimingGOOGLE(ApiDumpInstance::current(), result, device, swapchain, pPresentationTimingCount, pPresentationTimings);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPastPresentationTimingGOOGLE(ApiDumpInstance::current(), result, device, swapchain, pPresentationTimingCount, pPresentationTimings);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPastPresentationTimingGOOGLE(ApiDumpInstance::current(), result, device, swapchain, pPresentationTimingCount, pPresentationTimings);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle, uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetDiscardRectangleEXT", "commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles", "void");
    device_dispatch_table(commandBuffer)->CmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetDiscardRectangleEXT(ApiDumpInstance::current(), commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetDiscardRectangleEXT(ApiDumpInstance::current(), commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetDiscardRectangleEXT(ApiDumpInstance::current(), commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDiscardRectangleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetDiscardRectangleEnableEXT", "commandBuffer, discardRectangleEnable", "void");
    device_dispatch_table(commandBuffer)->CmdSetDiscardRectangleEnableEXT(commandBuffer, discardRectangleEnable);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetDiscardRectangleEnableEXT(ApiDumpInstance::current(), commandBuffer, discardRectangleEnable);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetDiscardRectangleEnableEXT(ApiDumpInstance::current(), commandBuffer, discardRectangleEnable);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetDiscardRectangleEnableEXT(ApiDumpInstance::current(), commandBuffer, discardRectangleEnable);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDiscardRectangleModeEXT(VkCommandBuffer commandBuffer, VkDiscardRectangleModeEXT discardRectangleMode)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetDiscardRectangleModeEXT", "commandBuffer, discardRectangleMode", "void");
    device_dispatch_table(commandBuffer)->CmdSetDiscardRectangleModeEXT(commandBuffer, discardRectangleMode);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetDiscardRectangleModeEXT(ApiDumpInstance::current(), commandBuffer, discardRectangleMode);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetDiscardRectangleModeEXT(ApiDumpInstance::current(), commandBuffer, discardRectangleMode);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetDiscardRectangleModeEXT(ApiDumpInstance::current(), commandBuffer, discardRectangleMode);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkSetHdrMetadataEXT(VkDevice device, uint32_t swapchainCount, const VkSwapchainKHR* pSwapchains, const VkHdrMetadataEXT* pMetadata)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkSetHdrMetadataEXT", "device, swapchainCount, pSwapchains, pMetadata", "void");
    device_dispatch_table(device)->SetHdrMetadataEXT(device, swapchainCount, pSwapchains, pMetadata);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkSetHdrMetadataEXT(ApiDumpInstance::current(), device, swapchainCount, pSwapchains, pMetadata);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkSetHdrMetadataEXT(ApiDumpInstance::current(), device, swapchainCount, pSwapchains, pMetadata);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkSetHdrMetadataEXT(ApiDumpInstance::current(), device, swapchainCount, pSwapchains, pMetadata);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateRenderPass2KHR(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateRenderPass2KHR", "device, pCreateInfo, pAllocator, pRenderPass", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateRenderPass2KHR(device, pCreateInfo, pAllocator, pRenderPass);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateRenderPass2KHR(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pRenderPass);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateRenderPass2KHR(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pRenderPass);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateRenderPass2KHR(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pRenderPass);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdBeginRenderPass2KHR(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo*      pRenderPassBegin, const VkSubpassBeginInfo*      pSubpassBeginInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdBeginRenderPass2KHR", "commandBuffer, pRenderPassBegin, pSubpassBeginInfo", "void");
    device_dispatch_table(commandBuffer)->CmdBeginRenderPass2KHR(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdBeginRenderPass2KHR(ApiDumpInstance::current(), commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdBeginRenderPass2KHR(ApiDumpInstance::current(), commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdBeginRenderPass2KHR(ApiDumpInstance::current(), commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdNextSubpass2KHR(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo*      pSubpassBeginInfo, const VkSubpassEndInfo*        pSubpassEndInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdNextSubpass2KHR", "commandBuffer, pSubpassBeginInfo, pSubpassEndInfo", "void");
    device_dispatch_table(commandBuffer)->CmdNextSubpass2KHR(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdNextSubpass2KHR(ApiDumpInstance::current(), commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdNextSubpass2KHR(ApiDumpInstance::current(), commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdNextSubpass2KHR(ApiDumpInstance::current(), commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdEndRenderPass2KHR(VkCommandBuffer commandBuffer, const VkSubpassEndInfo*        pSubpassEndInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdEndRenderPass2KHR", "commandBuffer, pSubpassEndInfo", "void");
    device_dispatch_table(commandBuffer)->CmdEndRenderPass2KHR(commandBuffer, pSubpassEndInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdEndRenderPass2KHR(ApiDumpInstance::current(), commandBuffer, pSubpassEndInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdEndRenderPass2KHR(ApiDumpInstance::current(), commandBuffer, pSubpassEndInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdEndRenderPass2KHR(ApiDumpInstance::current(), commandBuffer, pSubpassEndInfo);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetSwapchainStatusKHR(VkDevice device, VkSwapchainKHR swapchain)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetSwapchainStatusKHR", "device, swapchain", "VkResult");
    VkResult result = device_dispatch_table(device)->GetSwapchainStatusKHR(device, swapchain);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetSwapchainStatusKHR(ApiDumpInstance::current(), result, device, swapchain);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetSwapchainStatusKHR(ApiDumpInstance::current(), result, device, swapchain);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetSwapchainStatusKHR(ApiDumpInstance::current(), result, device, swapchain);
                break;
        }
    }
    return result;
}
#if defined(VK_USE_PLATFORM_WIN32_KHR)
VKAPI_ATTR VkResult VKAPI_CALL vkImportFenceWin32HandleKHR(VkDevice device, const VkImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkImportFenceWin32HandleKHR", "device, pImportFenceWin32HandleInfo", "VkResult");
    VkResult result = device_dispatch_table(device)->ImportFenceWin32HandleKHR(device, pImportFenceWin32HandleInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkImportFenceWin32HandleKHR(ApiDumpInstance::current(), result, device, pImportFenceWin32HandleInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkImportFenceWin32HandleKHR(ApiDumpInstance::current(), result, device, pImportFenceWin32HandleInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkImportFenceWin32HandleKHR(ApiDumpInstance::current(), result, device, pImportFenceWin32HandleInfo);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
VKAPI_ATTR VkResult VKAPI_CALL vkGetFenceWin32HandleKHR(VkDevice device, const VkFenceGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetFenceWin32HandleKHR", "device, pGetWin32HandleInfo, pHandle", "VkResult");
    VkResult result = device_dispatch_table(device)->GetFenceWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetFenceWin32HandleKHR(ApiDumpInstance::current(), result, device, pGetWin32HandleInfo, pHandle);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetFenceWin32HandleKHR(ApiDumpInstance::current(), result, device, pGetWin32HandleInfo, pHandle);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetFenceWin32HandleKHR(ApiDumpInstance::current(), result, device, pGetWin32HandleInfo, pHandle);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_WIN32_KHR
VKAPI_ATTR VkResult VKAPI_CALL vkImportFenceFdKHR(VkDevice device, const VkImportFenceFdInfoKHR* pImportFenceFdInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkImportFenceFdKHR", "device, pImportFenceFdInfo", "VkResult");
    VkResult result = device_dispatch_table(device)->ImportFenceFdKHR(device, pImportFenceFdInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkImportFenceFdKHR(ApiDumpInstance::current(), result, device, pImportFenceFdInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkImportFenceFdKHR(ApiDumpInstance::current(), result, device, pImportFenceFdInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkImportFenceFdKHR(ApiDumpInstance::current(), result, device, pImportFenceFdInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetFenceFdKHR(VkDevice device, const VkFenceGetFdInfoKHR* pGetFdInfo, int* pFd)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetFenceFdKHR", "device, pGetFdInfo, pFd", "VkResult");
    VkResult result = device_dispatch_table(device)->GetFenceFdKHR(device, pGetFdInfo, pFd);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetFenceFdKHR(ApiDumpInstance::current(), result, device, pGetFdInfo, pFd);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetFenceFdKHR(ApiDumpInstance::current(), result, device, pGetFdInfo, pFd);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetFenceFdKHR(ApiDumpInstance::current(), result, device, pGetFdInfo, pFd);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkAcquireProfilingLockKHR(VkDevice device, const VkAcquireProfilingLockInfoKHR* pInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkAcquireProfilingLockKHR", "device, pInfo", "VkResult");
    VkResult result = device_dispatch_table(device)->AcquireProfilingLockKHR(device, pInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkAcquireProfilingLockKHR(ApiDumpInstance::current(), result, device, pInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkAcquireProfilingLockKHR(ApiDumpInstance::current(), result, device, pInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkAcquireProfilingLockKHR(ApiDumpInstance::current(), result, device, pInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkReleaseProfilingLockKHR(VkDevice device)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkReleaseProfilingLockKHR", "device", "void");
    device_dispatch_table(device)->ReleaseProfilingLockKHR(device);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkReleaseProfilingLockKHR(ApiDumpInstance::current(), device);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkReleaseProfilingLockKHR(ApiDumpInstance::current(), device);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkReleaseProfilingLockKHR(ApiDumpInstance::current(), device);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkSetDebugUtilsObjectNameEXT(VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    ApiDumpInstance::current().update_object_name_map(pNameInfo);
    dump_function_head(ApiDumpInstance::current(), "vkSetDebugUtilsObjectNameEXT", "device, pNameInfo", "VkResult");
    VkResult result = device_dispatch_table(device)->SetDebugUtilsObjectNameEXT(device, pNameInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkSetDebugUtilsObjectNameEXT(ApiDumpInstance::current(), result, device, pNameInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkSetDebugUtilsObjectNameEXT(ApiDumpInstance::current(), result, device, pNameInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkSetDebugUtilsObjectNameEXT(ApiDumpInstance::current(), result, device, pNameInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkSetDebugUtilsObjectTagEXT(VkDevice device, const VkDebugUtilsObjectTagInfoEXT* pTagInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkSetDebugUtilsObjectTagEXT", "device, pTagInfo", "VkResult");
    VkResult result = device_dispatch_table(device)->SetDebugUtilsObjectTagEXT(device, pTagInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkSetDebugUtilsObjectTagEXT(ApiDumpInstance::current(), result, device, pTagInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkSetDebugUtilsObjectTagEXT(ApiDumpInstance::current(), result, device, pTagInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkSetDebugUtilsObjectTagEXT(ApiDumpInstance::current(), result, device, pTagInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkQueueBeginDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkQueueBeginDebugUtilsLabelEXT", "queue, pLabelInfo", "void");
    device_dispatch_table(queue)->QueueBeginDebugUtilsLabelEXT(queue, pLabelInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkQueueBeginDebugUtilsLabelEXT(ApiDumpInstance::current(), queue, pLabelInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkQueueBeginDebugUtilsLabelEXT(ApiDumpInstance::current(), queue, pLabelInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkQueueBeginDebugUtilsLabelEXT(ApiDumpInstance::current(), queue, pLabelInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkQueueEndDebugUtilsLabelEXT(VkQueue queue)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkQueueEndDebugUtilsLabelEXT", "queue", "void");
    device_dispatch_table(queue)->QueueEndDebugUtilsLabelEXT(queue);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkQueueEndDebugUtilsLabelEXT(ApiDumpInstance::current(), queue);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkQueueEndDebugUtilsLabelEXT(ApiDumpInstance::current(), queue);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkQueueEndDebugUtilsLabelEXT(ApiDumpInstance::current(), queue);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkQueueInsertDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkQueueInsertDebugUtilsLabelEXT", "queue, pLabelInfo", "void");
    device_dispatch_table(queue)->QueueInsertDebugUtilsLabelEXT(queue, pLabelInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkQueueInsertDebugUtilsLabelEXT(ApiDumpInstance::current(), queue, pLabelInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkQueueInsertDebugUtilsLabelEXT(ApiDumpInstance::current(), queue, pLabelInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkQueueInsertDebugUtilsLabelEXT(ApiDumpInstance::current(), queue, pLabelInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdBeginDebugUtilsLabelEXT", "commandBuffer, pLabelInfo", "void");
    device_dispatch_table(commandBuffer)->CmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdBeginDebugUtilsLabelEXT(ApiDumpInstance::current(), commandBuffer, pLabelInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdBeginDebugUtilsLabelEXT(ApiDumpInstance::current(), commandBuffer, pLabelInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdBeginDebugUtilsLabelEXT(ApiDumpInstance::current(), commandBuffer, pLabelInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdEndDebugUtilsLabelEXT", "commandBuffer", "void");
    device_dispatch_table(commandBuffer)->CmdEndDebugUtilsLabelEXT(commandBuffer);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdEndDebugUtilsLabelEXT(ApiDumpInstance::current(), commandBuffer);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdEndDebugUtilsLabelEXT(ApiDumpInstance::current(), commandBuffer);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdEndDebugUtilsLabelEXT(ApiDumpInstance::current(), commandBuffer);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdInsertDebugUtilsLabelEXT", "commandBuffer, pLabelInfo", "void");
    device_dispatch_table(commandBuffer)->CmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdInsertDebugUtilsLabelEXT(ApiDumpInstance::current(), commandBuffer, pLabelInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdInsertDebugUtilsLabelEXT(ApiDumpInstance::current(), commandBuffer, pLabelInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdInsertDebugUtilsLabelEXT(ApiDumpInstance::current(), commandBuffer, pLabelInfo);
                break;
        }
    }
}
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
VKAPI_ATTR VkResult VKAPI_CALL vkGetAndroidHardwareBufferPropertiesANDROID(VkDevice device, const struct AHardwareBuffer* buffer, VkAndroidHardwareBufferPropertiesANDROID* pProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetAndroidHardwareBufferPropertiesANDROID", "device, buffer, pProperties", "VkResult");
    VkResult result = device_dispatch_table(device)->GetAndroidHardwareBufferPropertiesANDROID(device, buffer, pProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetAndroidHardwareBufferPropertiesANDROID(ApiDumpInstance::current(), result, device, buffer, pProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetAndroidHardwareBufferPropertiesANDROID(ApiDumpInstance::current(), result, device, buffer, pProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetAndroidHardwareBufferPropertiesANDROID(ApiDumpInstance::current(), result, device, buffer, pProperties);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_ANDROID_KHR
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryAndroidHardwareBufferANDROID(VkDevice device, const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo, struct AHardwareBuffer** pBuffer)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetMemoryAndroidHardwareBufferANDROID", "device, pInfo, pBuffer", "VkResult");
    VkResult result = device_dispatch_table(device)->GetMemoryAndroidHardwareBufferANDROID(device, pInfo, pBuffer);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetMemoryAndroidHardwareBufferANDROID(ApiDumpInstance::current(), result, device, pInfo, pBuffer);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetMemoryAndroidHardwareBufferANDROID(ApiDumpInstance::current(), result, device, pInfo, pBuffer);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetMemoryAndroidHardwareBufferANDROID(ApiDumpInstance::current(), result, device, pInfo, pBuffer);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_ANDROID_KHR
#if defined(VK_ENABLE_BETA_EXTENSIONS)
VKAPI_ATTR VkResult VKAPI_CALL vkCreateExecutionGraphPipelinesAMDX(VkDevice                                        device, VkPipelineCache                 pipelineCache, uint32_t                                        createInfoCount, const VkExecutionGraphPipelineCreateInfoAMDX* pCreateInfos, const VkAllocationCallbacks*    pAllocator, VkPipeline*               pPipelines)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateExecutionGraphPipelinesAMDX", "device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateExecutionGraphPipelinesAMDX(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateExecutionGraphPipelinesAMDX(ApiDumpInstance::current(), result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateExecutionGraphPipelinesAMDX(ApiDumpInstance::current(), result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateExecutionGraphPipelinesAMDX(ApiDumpInstance::current(), result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
                break;
        }
    }
    return result;
}
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
VKAPI_ATTR VkResult VKAPI_CALL vkGetExecutionGraphPipelineScratchSizeAMDX(VkDevice                                        device, VkPipeline                                      executionGraph, VkExecutionGraphPipelineScratchSizeAMDX*         pSizeInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetExecutionGraphPipelineScratchSizeAMDX", "device, executionGraph, pSizeInfo", "VkResult");
    VkResult result = device_dispatch_table(device)->GetExecutionGraphPipelineScratchSizeAMDX(device, executionGraph, pSizeInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetExecutionGraphPipelineScratchSizeAMDX(ApiDumpInstance::current(), result, device, executionGraph, pSizeInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetExecutionGraphPipelineScratchSizeAMDX(ApiDumpInstance::current(), result, device, executionGraph, pSizeInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetExecutionGraphPipelineScratchSizeAMDX(ApiDumpInstance::current(), result, device, executionGraph, pSizeInfo);
                break;
        }
    }
    return result;
}
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
VKAPI_ATTR VkResult VKAPI_CALL vkGetExecutionGraphPipelineNodeIndexAMDX(VkDevice                                        device, VkPipeline                                      executionGraph, const VkPipelineShaderStageNodeCreateInfoAMDX*   pNodeInfo, uint32_t*                                       pNodeIndex)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetExecutionGraphPipelineNodeIndexAMDX", "device, executionGraph, pNodeInfo, pNodeIndex", "VkResult");
    VkResult result = device_dispatch_table(device)->GetExecutionGraphPipelineNodeIndexAMDX(device, executionGraph, pNodeInfo, pNodeIndex);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetExecutionGraphPipelineNodeIndexAMDX(ApiDumpInstance::current(), result, device, executionGraph, pNodeInfo, pNodeIndex);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetExecutionGraphPipelineNodeIndexAMDX(ApiDumpInstance::current(), result, device, executionGraph, pNodeInfo, pNodeIndex);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetExecutionGraphPipelineNodeIndexAMDX(ApiDumpInstance::current(), result, device, executionGraph, pNodeInfo, pNodeIndex);
                break;
        }
    }
    return result;
}
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
VKAPI_ATTR void VKAPI_CALL vkCmdInitializeGraphScratchMemoryAMDX(VkCommandBuffer                                 commandBuffer, VkDeviceAddress                                 scratch)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdInitializeGraphScratchMemoryAMDX", "commandBuffer, scratch", "void");
    device_dispatch_table(commandBuffer)->CmdInitializeGraphScratchMemoryAMDX(commandBuffer, scratch);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdInitializeGraphScratchMemoryAMDX(ApiDumpInstance::current(), commandBuffer, scratch);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdInitializeGraphScratchMemoryAMDX(ApiDumpInstance::current(), commandBuffer, scratch);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdInitializeGraphScratchMemoryAMDX(ApiDumpInstance::current(), commandBuffer, scratch);
                break;
        }
    }
}
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
VKAPI_ATTR void VKAPI_CALL vkCmdDispatchGraphAMDX(VkCommandBuffer                                 commandBuffer, VkDeviceAddress                                 scratch, const VkDispatchGraphCountInfoAMDX*              pCountInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdDispatchGraphAMDX", "commandBuffer, scratch, pCountInfo", "void");
    device_dispatch_table(commandBuffer)->CmdDispatchGraphAMDX(commandBuffer, scratch, pCountInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdDispatchGraphAMDX(ApiDumpInstance::current(), commandBuffer, scratch, pCountInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdDispatchGraphAMDX(ApiDumpInstance::current(), commandBuffer, scratch, pCountInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdDispatchGraphAMDX(ApiDumpInstance::current(), commandBuffer, scratch, pCountInfo);
                break;
        }
    }
}
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
VKAPI_ATTR void VKAPI_CALL vkCmdDispatchGraphIndirectAMDX(VkCommandBuffer                                 commandBuffer, VkDeviceAddress                                 scratch, const VkDispatchGraphCountInfoAMDX*              pCountInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdDispatchGraphIndirectAMDX", "commandBuffer, scratch, pCountInfo", "void");
    device_dispatch_table(commandBuffer)->CmdDispatchGraphIndirectAMDX(commandBuffer, scratch, pCountInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdDispatchGraphIndirectAMDX(ApiDumpInstance::current(), commandBuffer, scratch, pCountInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdDispatchGraphIndirectAMDX(ApiDumpInstance::current(), commandBuffer, scratch, pCountInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdDispatchGraphIndirectAMDX(ApiDumpInstance::current(), commandBuffer, scratch, pCountInfo);
                break;
        }
    }
}
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
VKAPI_ATTR void VKAPI_CALL vkCmdDispatchGraphIndirectCountAMDX(VkCommandBuffer                                 commandBuffer, VkDeviceAddress                                 scratch, VkDeviceAddress                                 countInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdDispatchGraphIndirectCountAMDX", "commandBuffer, scratch, countInfo", "void");
    device_dispatch_table(commandBuffer)->CmdDispatchGraphIndirectCountAMDX(commandBuffer, scratch, countInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdDispatchGraphIndirectCountAMDX(ApiDumpInstance::current(), commandBuffer, scratch, countInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdDispatchGraphIndirectCountAMDX(ApiDumpInstance::current(), commandBuffer, scratch, countInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdDispatchGraphIndirectCountAMDX(ApiDumpInstance::current(), commandBuffer, scratch, countInfo);
                break;
        }
    }
}
#endif // VK_ENABLE_BETA_EXTENSIONS
VKAPI_ATTR void VKAPI_CALL vkCmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer, const VkSampleLocationsInfoEXT* pSampleLocationsInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetSampleLocationsEXT", "commandBuffer, pSampleLocationsInfo", "void");
    device_dispatch_table(commandBuffer)->CmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetSampleLocationsEXT(ApiDumpInstance::current(), commandBuffer, pSampleLocationsInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetSampleLocationsEXT(ApiDumpInstance::current(), commandBuffer, pSampleLocationsInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetSampleLocationsEXT(ApiDumpInstance::current(), commandBuffer, pSampleLocationsInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetImageMemoryRequirements2KHR(VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetImageMemoryRequirements2KHR", "device, pInfo, pMemoryRequirements", "void");
    device_dispatch_table(device)->GetImageMemoryRequirements2KHR(device, pInfo, pMemoryRequirements);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetImageMemoryRequirements2KHR(ApiDumpInstance::current(), device, pInfo, pMemoryRequirements);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetImageMemoryRequirements2KHR(ApiDumpInstance::current(), device, pInfo, pMemoryRequirements);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetImageMemoryRequirements2KHR(ApiDumpInstance::current(), device, pInfo, pMemoryRequirements);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetBufferMemoryRequirements2KHR(VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetBufferMemoryRequirements2KHR", "device, pInfo, pMemoryRequirements", "void");
    device_dispatch_table(device)->GetBufferMemoryRequirements2KHR(device, pInfo, pMemoryRequirements);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetBufferMemoryRequirements2KHR(ApiDumpInstance::current(), device, pInfo, pMemoryRequirements);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetBufferMemoryRequirements2KHR(ApiDumpInstance::current(), device, pInfo, pMemoryRequirements);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetBufferMemoryRequirements2KHR(ApiDumpInstance::current(), device, pInfo, pMemoryRequirements);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetImageSparseMemoryRequirements2KHR(VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetImageSparseMemoryRequirements2KHR", "device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements", "void");
    device_dispatch_table(device)->GetImageSparseMemoryRequirements2KHR(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetImageSparseMemoryRequirements2KHR(ApiDumpInstance::current(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetImageSparseMemoryRequirements2KHR(ApiDumpInstance::current(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetImageSparseMemoryRequirements2KHR(ApiDumpInstance::current(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateAccelerationStructureKHR(VkDevice                                           device, const VkAccelerationStructureCreateInfoKHR*        pCreateInfo, const VkAllocationCallbacks*       pAllocator, VkAccelerationStructureKHR*                        pAccelerationStructure)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateAccelerationStructureKHR", "device, pCreateInfo, pAllocator, pAccelerationStructure", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateAccelerationStructureKHR(device, pCreateInfo, pAllocator, pAccelerationStructure);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateAccelerationStructureKHR(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pAccelerationStructure);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateAccelerationStructureKHR(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pAccelerationStructure);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateAccelerationStructureKHR(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pAccelerationStructure);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyAccelerationStructureKHR(VkDevice device, VkAccelerationStructureKHR accelerationStructure, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyAccelerationStructureKHR", "device, accelerationStructure, pAllocator", "void");
    device_dispatch_table(device)->DestroyAccelerationStructureKHR(device, accelerationStructure, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyAccelerationStructureKHR(ApiDumpInstance::current(), device, accelerationStructure, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyAccelerationStructureKHR(ApiDumpInstance::current(), device, accelerationStructure, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyAccelerationStructureKHR(ApiDumpInstance::current(), device, accelerationStructure, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdBuildAccelerationStructuresKHR(VkCommandBuffer                                    commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdBuildAccelerationStructuresKHR", "commandBuffer, infoCount, pInfos, ppBuildRangeInfos", "void");
    device_dispatch_table(commandBuffer)->CmdBuildAccelerationStructuresKHR(commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdBuildAccelerationStructuresKHR(ApiDumpInstance::current(), commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdBuildAccelerationStructuresKHR(ApiDumpInstance::current(), commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdBuildAccelerationStructuresKHR(ApiDumpInstance::current(), commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdBuildAccelerationStructuresIndirectKHR(VkCommandBuffer                  commandBuffer, uint32_t                                           infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkDeviceAddress*             pIndirectDeviceAddresses, const uint32_t*                    pIndirectStrides, const uint32_t* const*             ppMaxPrimitiveCounts)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdBuildAccelerationStructuresIndirectKHR", "commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts", "void");
    device_dispatch_table(commandBuffer)->CmdBuildAccelerationStructuresIndirectKHR(commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdBuildAccelerationStructuresIndirectKHR(ApiDumpInstance::current(), commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdBuildAccelerationStructuresIndirectKHR(ApiDumpInstance::current(), commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdBuildAccelerationStructuresIndirectKHR(ApiDumpInstance::current(), commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkBuildAccelerationStructuresKHR(VkDevice                                           device, VkDeferredOperationKHR deferredOperation, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkBuildAccelerationStructuresKHR", "device, deferredOperation, infoCount, pInfos, ppBuildRangeInfos", "VkResult");
    VkResult result = device_dispatch_table(device)->BuildAccelerationStructuresKHR(device, deferredOperation, infoCount, pInfos, ppBuildRangeInfos);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkBuildAccelerationStructuresKHR(ApiDumpInstance::current(), result, device, deferredOperation, infoCount, pInfos, ppBuildRangeInfos);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkBuildAccelerationStructuresKHR(ApiDumpInstance::current(), result, device, deferredOperation, infoCount, pInfos, ppBuildRangeInfos);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkBuildAccelerationStructuresKHR(ApiDumpInstance::current(), result, device, deferredOperation, infoCount, pInfos, ppBuildRangeInfos);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCopyAccelerationStructureKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureInfoKHR* pInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCopyAccelerationStructureKHR", "device, deferredOperation, pInfo", "VkResult");
    VkResult result = device_dispatch_table(device)->CopyAccelerationStructureKHR(device, deferredOperation, pInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCopyAccelerationStructureKHR(ApiDumpInstance::current(), result, device, deferredOperation, pInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCopyAccelerationStructureKHR(ApiDumpInstance::current(), result, device, deferredOperation, pInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCopyAccelerationStructureKHR(ApiDumpInstance::current(), result, device, deferredOperation, pInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCopyAccelerationStructureToMemoryKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCopyAccelerationStructureToMemoryKHR", "device, deferredOperation, pInfo", "VkResult");
    VkResult result = device_dispatch_table(device)->CopyAccelerationStructureToMemoryKHR(device, deferredOperation, pInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCopyAccelerationStructureToMemoryKHR(ApiDumpInstance::current(), result, device, deferredOperation, pInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCopyAccelerationStructureToMemoryKHR(ApiDumpInstance::current(), result, device, deferredOperation, pInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCopyAccelerationStructureToMemoryKHR(ApiDumpInstance::current(), result, device, deferredOperation, pInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCopyMemoryToAccelerationStructureKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCopyMemoryToAccelerationStructureKHR", "device, deferredOperation, pInfo", "VkResult");
    VkResult result = device_dispatch_table(device)->CopyMemoryToAccelerationStructureKHR(device, deferredOperation, pInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCopyMemoryToAccelerationStructureKHR(ApiDumpInstance::current(), result, device, deferredOperation, pInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCopyMemoryToAccelerationStructureKHR(ApiDumpInstance::current(), result, device, deferredOperation, pInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCopyMemoryToAccelerationStructureKHR(ApiDumpInstance::current(), result, device, deferredOperation, pInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkWriteAccelerationStructuresPropertiesKHR(VkDevice device, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType  queryType, size_t       dataSize, void* pData, size_t stride)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkWriteAccelerationStructuresPropertiesKHR", "device, accelerationStructureCount, pAccelerationStructures, queryType, dataSize, pData, stride", "VkResult");
    VkResult result = device_dispatch_table(device)->WriteAccelerationStructuresPropertiesKHR(device, accelerationStructureCount, pAccelerationStructures, queryType, dataSize, pData, stride);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkWriteAccelerationStructuresPropertiesKHR(ApiDumpInstance::current(), result, device, accelerationStructureCount, pAccelerationStructures, queryType, dataSize, pData, stride);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkWriteAccelerationStructuresPropertiesKHR(ApiDumpInstance::current(), result, device, accelerationStructureCount, pAccelerationStructures, queryType, dataSize, pData, stride);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkWriteAccelerationStructuresPropertiesKHR(ApiDumpInstance::current(), result, device, accelerationStructureCount, pAccelerationStructures, queryType, dataSize, pData, stride);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyAccelerationStructureKHR(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureInfoKHR* pInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdCopyAccelerationStructureKHR", "commandBuffer, pInfo", "void");
    device_dispatch_table(commandBuffer)->CmdCopyAccelerationStructureKHR(commandBuffer, pInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdCopyAccelerationStructureKHR(ApiDumpInstance::current(), commandBuffer, pInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdCopyAccelerationStructureKHR(ApiDumpInstance::current(), commandBuffer, pInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdCopyAccelerationStructureKHR(ApiDumpInstance::current(), commandBuffer, pInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyAccelerationStructureToMemoryKHR(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdCopyAccelerationStructureToMemoryKHR", "commandBuffer, pInfo", "void");
    device_dispatch_table(commandBuffer)->CmdCopyAccelerationStructureToMemoryKHR(commandBuffer, pInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdCopyAccelerationStructureToMemoryKHR(ApiDumpInstance::current(), commandBuffer, pInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdCopyAccelerationStructureToMemoryKHR(ApiDumpInstance::current(), commandBuffer, pInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdCopyAccelerationStructureToMemoryKHR(ApiDumpInstance::current(), commandBuffer, pInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyMemoryToAccelerationStructureKHR(VkCommandBuffer commandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdCopyMemoryToAccelerationStructureKHR", "commandBuffer, pInfo", "void");
    device_dispatch_table(commandBuffer)->CmdCopyMemoryToAccelerationStructureKHR(commandBuffer, pInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdCopyMemoryToAccelerationStructureKHR(ApiDumpInstance::current(), commandBuffer, pInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdCopyMemoryToAccelerationStructureKHR(ApiDumpInstance::current(), commandBuffer, pInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdCopyMemoryToAccelerationStructureKHR(ApiDumpInstance::current(), commandBuffer, pInfo);
                break;
        }
    }
}
VKAPI_ATTR VkDeviceAddress VKAPI_CALL vkGetAccelerationStructureDeviceAddressKHR(VkDevice device, const VkAccelerationStructureDeviceAddressInfoKHR* pInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetAccelerationStructureDeviceAddressKHR", "device, pInfo", "VkDeviceAddress");
    VkDeviceAddress result = device_dispatch_table(device)->GetAccelerationStructureDeviceAddressKHR(device, pInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetAccelerationStructureDeviceAddressKHR(ApiDumpInstance::current(), result, device, pInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetAccelerationStructureDeviceAddressKHR(ApiDumpInstance::current(), result, device, pInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetAccelerationStructureDeviceAddressKHR(ApiDumpInstance::current(), result, device, pInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdWriteAccelerationStructuresPropertiesKHR(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdWriteAccelerationStructuresPropertiesKHR", "commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery", "void");
    device_dispatch_table(commandBuffer)->CmdWriteAccelerationStructuresPropertiesKHR(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdWriteAccelerationStructuresPropertiesKHR(ApiDumpInstance::current(), commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdWriteAccelerationStructuresPropertiesKHR(ApiDumpInstance::current(), commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdWriteAccelerationStructuresPropertiesKHR(ApiDumpInstance::current(), commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetDeviceAccelerationStructureCompatibilityKHR(VkDevice device, const VkAccelerationStructureVersionInfoKHR* pVersionInfo, VkAccelerationStructureCompatibilityKHR* pCompatibility)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDeviceAccelerationStructureCompatibilityKHR", "device, pVersionInfo, pCompatibility", "void");
    device_dispatch_table(device)->GetDeviceAccelerationStructureCompatibilityKHR(device, pVersionInfo, pCompatibility);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDeviceAccelerationStructureCompatibilityKHR(ApiDumpInstance::current(), device, pVersionInfo, pCompatibility);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDeviceAccelerationStructureCompatibilityKHR(ApiDumpInstance::current(), device, pVersionInfo, pCompatibility);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDeviceAccelerationStructureCompatibilityKHR(ApiDumpInstance::current(), device, pVersionInfo, pCompatibility);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetAccelerationStructureBuildSizesKHR(VkDevice                                            device, VkAccelerationStructureBuildTypeKHR                 buildType, const VkAccelerationStructureBuildGeometryInfoKHR*  pBuildInfo, const uint32_t*  pMaxPrimitiveCounts, VkAccelerationStructureBuildSizesInfoKHR*           pSizeInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetAccelerationStructureBuildSizesKHR", "device, buildType, pBuildInfo, pMaxPrimitiveCounts, pSizeInfo", "void");
    device_dispatch_table(device)->GetAccelerationStructureBuildSizesKHR(device, buildType, pBuildInfo, pMaxPrimitiveCounts, pSizeInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetAccelerationStructureBuildSizesKHR(ApiDumpInstance::current(), device, buildType, pBuildInfo, pMaxPrimitiveCounts, pSizeInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetAccelerationStructureBuildSizesKHR(ApiDumpInstance::current(), device, buildType, pBuildInfo, pMaxPrimitiveCounts, pSizeInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetAccelerationStructureBuildSizesKHR(ApiDumpInstance::current(), device, buildType, pBuildInfo, pMaxPrimitiveCounts, pSizeInfo);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateSamplerYcbcrConversionKHR(VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateSamplerYcbcrConversionKHR", "device, pCreateInfo, pAllocator, pYcbcrConversion", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateSamplerYcbcrConversionKHR(device, pCreateInfo, pAllocator, pYcbcrConversion);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateSamplerYcbcrConversionKHR(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pYcbcrConversion);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateSamplerYcbcrConversionKHR(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pYcbcrConversion);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateSamplerYcbcrConversionKHR(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pYcbcrConversion);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroySamplerYcbcrConversionKHR(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroySamplerYcbcrConversionKHR", "device, ycbcrConversion, pAllocator", "void");
    device_dispatch_table(device)->DestroySamplerYcbcrConversionKHR(device, ycbcrConversion, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroySamplerYcbcrConversionKHR(ApiDumpInstance::current(), device, ycbcrConversion, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroySamplerYcbcrConversionKHR(ApiDumpInstance::current(), device, ycbcrConversion, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroySamplerYcbcrConversionKHR(ApiDumpInstance::current(), device, ycbcrConversion, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkBindBufferMemory2KHR(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkBindBufferMemory2KHR", "device, bindInfoCount, pBindInfos", "VkResult");
    VkResult result = device_dispatch_table(device)->BindBufferMemory2KHR(device, bindInfoCount, pBindInfos);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkBindBufferMemory2KHR(ApiDumpInstance::current(), result, device, bindInfoCount, pBindInfos);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkBindBufferMemory2KHR(ApiDumpInstance::current(), result, device, bindInfoCount, pBindInfos);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkBindBufferMemory2KHR(ApiDumpInstance::current(), result, device, bindInfoCount, pBindInfos);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkBindImageMemory2KHR(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkBindImageMemory2KHR", "device, bindInfoCount, pBindInfos", "VkResult");
    VkResult result = device_dispatch_table(device)->BindImageMemory2KHR(device, bindInfoCount, pBindInfos);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkBindImageMemory2KHR(ApiDumpInstance::current(), result, device, bindInfoCount, pBindInfos);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkBindImageMemory2KHR(ApiDumpInstance::current(), result, device, bindInfoCount, pBindInfos);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkBindImageMemory2KHR(ApiDumpInstance::current(), result, device, bindInfoCount, pBindInfos);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetImageDrmFormatModifierPropertiesEXT(VkDevice device, VkImage image, VkImageDrmFormatModifierPropertiesEXT* pProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetImageDrmFormatModifierPropertiesEXT", "device, image, pProperties", "VkResult");
    VkResult result = device_dispatch_table(device)->GetImageDrmFormatModifierPropertiesEXT(device, image, pProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetImageDrmFormatModifierPropertiesEXT(ApiDumpInstance::current(), result, device, image, pProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetImageDrmFormatModifierPropertiesEXT(ApiDumpInstance::current(), result, device, image, pProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetImageDrmFormatModifierPropertiesEXT(ApiDumpInstance::current(), result, device, image, pProperties);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateValidationCacheEXT(VkDevice device, const VkValidationCacheCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkValidationCacheEXT* pValidationCache)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateValidationCacheEXT", "device, pCreateInfo, pAllocator, pValidationCache", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateValidationCacheEXT(device, pCreateInfo, pAllocator, pValidationCache);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateValidationCacheEXT(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pValidationCache);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateValidationCacheEXT(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pValidationCache);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateValidationCacheEXT(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pValidationCache);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyValidationCacheEXT(VkDevice device, VkValidationCacheEXT validationCache, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyValidationCacheEXT", "device, validationCache, pAllocator", "void");
    device_dispatch_table(device)->DestroyValidationCacheEXT(device, validationCache, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyValidationCacheEXT(ApiDumpInstance::current(), device, validationCache, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyValidationCacheEXT(ApiDumpInstance::current(), device, validationCache, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyValidationCacheEXT(ApiDumpInstance::current(), device, validationCache, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkMergeValidationCachesEXT(VkDevice device, VkValidationCacheEXT dstCache, uint32_t srcCacheCount, const VkValidationCacheEXT* pSrcCaches)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkMergeValidationCachesEXT", "device, dstCache, srcCacheCount, pSrcCaches", "VkResult");
    VkResult result = device_dispatch_table(device)->MergeValidationCachesEXT(device, dstCache, srcCacheCount, pSrcCaches);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkMergeValidationCachesEXT(ApiDumpInstance::current(), result, device, dstCache, srcCacheCount, pSrcCaches);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkMergeValidationCachesEXT(ApiDumpInstance::current(), result, device, dstCache, srcCacheCount, pSrcCaches);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkMergeValidationCachesEXT(ApiDumpInstance::current(), result, device, dstCache, srcCacheCount, pSrcCaches);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetValidationCacheDataEXT(VkDevice device, VkValidationCacheEXT validationCache, size_t* pDataSize, void* pData)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetValidationCacheDataEXT", "device, validationCache, pDataSize, pData", "VkResult");
    VkResult result = device_dispatch_table(device)->GetValidationCacheDataEXT(device, validationCache, pDataSize, pData);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetValidationCacheDataEXT(ApiDumpInstance::current(), result, device, validationCache, pDataSize, pData);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetValidationCacheDataEXT(ApiDumpInstance::current(), result, device, validationCache, pDataSize, pData);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetValidationCacheDataEXT(ApiDumpInstance::current(), result, device, validationCache, pDataSize, pData);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindShadingRateImageNV(VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdBindShadingRateImageNV", "commandBuffer, imageView, imageLayout", "void");
    device_dispatch_table(commandBuffer)->CmdBindShadingRateImageNV(commandBuffer, imageView, imageLayout);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdBindShadingRateImageNV(ApiDumpInstance::current(), commandBuffer, imageView, imageLayout);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdBindShadingRateImageNV(ApiDumpInstance::current(), commandBuffer, imageView, imageLayout);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdBindShadingRateImageNV(ApiDumpInstance::current(), commandBuffer, imageView, imageLayout);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetViewportShadingRatePaletteNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkShadingRatePaletteNV* pShadingRatePalettes)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetViewportShadingRatePaletteNV", "commandBuffer, firstViewport, viewportCount, pShadingRatePalettes", "void");
    device_dispatch_table(commandBuffer)->CmdSetViewportShadingRatePaletteNV(commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetViewportShadingRatePaletteNV(ApiDumpInstance::current(), commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetViewportShadingRatePaletteNV(ApiDumpInstance::current(), commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetViewportShadingRatePaletteNV(ApiDumpInstance::current(), commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetCoarseSampleOrderNV(VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount, const VkCoarseSampleOrderCustomNV* pCustomSampleOrders)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetCoarseSampleOrderNV", "commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders", "void");
    device_dispatch_table(commandBuffer)->CmdSetCoarseSampleOrderNV(commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetCoarseSampleOrderNV(ApiDumpInstance::current(), commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetCoarseSampleOrderNV(ApiDumpInstance::current(), commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetCoarseSampleOrderNV(ApiDumpInstance::current(), commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateAccelerationStructureNV(VkDevice device, const VkAccelerationStructureCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureNV* pAccelerationStructure)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateAccelerationStructureNV", "device, pCreateInfo, pAllocator, pAccelerationStructure", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateAccelerationStructureNV(device, pCreateInfo, pAllocator, pAccelerationStructure);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateAccelerationStructureNV(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pAccelerationStructure);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateAccelerationStructureNV(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pAccelerationStructure);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateAccelerationStructureNV(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pAccelerationStructure);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyAccelerationStructureNV(VkDevice device, VkAccelerationStructureNV accelerationStructure, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyAccelerationStructureNV", "device, accelerationStructure, pAllocator", "void");
    device_dispatch_table(device)->DestroyAccelerationStructureNV(device, accelerationStructure, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyAccelerationStructureNV(ApiDumpInstance::current(), device, accelerationStructure, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyAccelerationStructureNV(ApiDumpInstance::current(), device, accelerationStructure, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyAccelerationStructureNV(ApiDumpInstance::current(), device, accelerationStructure, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetAccelerationStructureMemoryRequirementsNV(VkDevice device, const VkAccelerationStructureMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2KHR* pMemoryRequirements)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetAccelerationStructureMemoryRequirementsNV", "device, pInfo, pMemoryRequirements", "void");
    device_dispatch_table(device)->GetAccelerationStructureMemoryRequirementsNV(device, pInfo, pMemoryRequirements);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetAccelerationStructureMemoryRequirementsNV(ApiDumpInstance::current(), device, pInfo, pMemoryRequirements);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetAccelerationStructureMemoryRequirementsNV(ApiDumpInstance::current(), device, pInfo, pMemoryRequirements);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetAccelerationStructureMemoryRequirementsNV(ApiDumpInstance::current(), device, pInfo, pMemoryRequirements);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkBindAccelerationStructureMemoryNV(VkDevice device, uint32_t bindInfoCount, const VkBindAccelerationStructureMemoryInfoNV* pBindInfos)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkBindAccelerationStructureMemoryNV", "device, bindInfoCount, pBindInfos", "VkResult");
    VkResult result = device_dispatch_table(device)->BindAccelerationStructureMemoryNV(device, bindInfoCount, pBindInfos);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkBindAccelerationStructureMemoryNV(ApiDumpInstance::current(), result, device, bindInfoCount, pBindInfos);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkBindAccelerationStructureMemoryNV(ApiDumpInstance::current(), result, device, bindInfoCount, pBindInfos);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkBindAccelerationStructureMemoryNV(ApiDumpInstance::current(), result, device, bindInfoCount, pBindInfos);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdBuildAccelerationStructureNV(VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData, VkDeviceSize instanceOffset, VkBool32 update, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch, VkDeviceSize scratchOffset)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdBuildAccelerationStructureNV", "commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset", "void");
    device_dispatch_table(commandBuffer)->CmdBuildAccelerationStructureNV(commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdBuildAccelerationStructureNV(ApiDumpInstance::current(), commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdBuildAccelerationStructureNV(ApiDumpInstance::current(), commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdBuildAccelerationStructureNV(ApiDumpInstance::current(), commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyAccelerationStructureNV(VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkCopyAccelerationStructureModeKHR mode)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdCopyAccelerationStructureNV", "commandBuffer, dst, src, mode", "void");
    device_dispatch_table(commandBuffer)->CmdCopyAccelerationStructureNV(commandBuffer, dst, src, mode);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdCopyAccelerationStructureNV(ApiDumpInstance::current(), commandBuffer, dst, src, mode);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdCopyAccelerationStructureNV(ApiDumpInstance::current(), commandBuffer, dst, src, mode);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdCopyAccelerationStructureNV(ApiDumpInstance::current(), commandBuffer, dst, src, mode);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdTraceRaysNV(VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer, VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer, VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride, VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset, VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer, VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdTraceRaysNV", "commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth", "void");
    device_dispatch_table(commandBuffer)->CmdTraceRaysNV(commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdTraceRaysNV(ApiDumpInstance::current(), commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdTraceRaysNV(ApiDumpInstance::current(), commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdTraceRaysNV(ApiDumpInstance::current(), commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateRayTracingPipelinesNV(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoNV* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateRayTracingPipelinesNV", "device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateRayTracingPipelinesNV(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateRayTracingPipelinesNV(ApiDumpInstance::current(), result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateRayTracingPipelinesNV(ApiDumpInstance::current(), result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateRayTracingPipelinesNV(ApiDumpInstance::current(), result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetRayTracingShaderGroupHandlesKHR(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetRayTracingShaderGroupHandlesKHR", "device, pipeline, firstGroup, groupCount, dataSize, pData", "VkResult");
    VkResult result = device_dispatch_table(device)->GetRayTracingShaderGroupHandlesKHR(device, pipeline, firstGroup, groupCount, dataSize, pData);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetRayTracingShaderGroupHandlesKHR(ApiDumpInstance::current(), result, device, pipeline, firstGroup, groupCount, dataSize, pData);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetRayTracingShaderGroupHandlesKHR(ApiDumpInstance::current(), result, device, pipeline, firstGroup, groupCount, dataSize, pData);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetRayTracingShaderGroupHandlesKHR(ApiDumpInstance::current(), result, device, pipeline, firstGroup, groupCount, dataSize, pData);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetRayTracingShaderGroupHandlesNV(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetRayTracingShaderGroupHandlesNV", "device, pipeline, firstGroup, groupCount, dataSize, pData", "VkResult");
    VkResult result = device_dispatch_table(device)->GetRayTracingShaderGroupHandlesNV(device, pipeline, firstGroup, groupCount, dataSize, pData);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetRayTracingShaderGroupHandlesNV(ApiDumpInstance::current(), result, device, pipeline, firstGroup, groupCount, dataSize, pData);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetRayTracingShaderGroupHandlesNV(ApiDumpInstance::current(), result, device, pipeline, firstGroup, groupCount, dataSize, pData);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetRayTracingShaderGroupHandlesNV(ApiDumpInstance::current(), result, device, pipeline, firstGroup, groupCount, dataSize, pData);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetAccelerationStructureHandleNV(VkDevice device, VkAccelerationStructureNV accelerationStructure, size_t dataSize, void* pData)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetAccelerationStructureHandleNV", "device, accelerationStructure, dataSize, pData", "VkResult");
    VkResult result = device_dispatch_table(device)->GetAccelerationStructureHandleNV(device, accelerationStructure, dataSize, pData);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetAccelerationStructureHandleNV(ApiDumpInstance::current(), result, device, accelerationStructure, dataSize, pData);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetAccelerationStructureHandleNV(ApiDumpInstance::current(), result, device, accelerationStructure, dataSize, pData);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetAccelerationStructureHandleNV(ApiDumpInstance::current(), result, device, accelerationStructure, dataSize, pData);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdWriteAccelerationStructuresPropertiesNV(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureNV* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdWriteAccelerationStructuresPropertiesNV", "commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery", "void");
    device_dispatch_table(commandBuffer)->CmdWriteAccelerationStructuresPropertiesNV(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdWriteAccelerationStructuresPropertiesNV(ApiDumpInstance::current(), commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdWriteAccelerationStructuresPropertiesNV(ApiDumpInstance::current(), commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdWriteAccelerationStructuresPropertiesNV(ApiDumpInstance::current(), commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkCompileDeferredNV(VkDevice device, VkPipeline pipeline, uint32_t shader)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCompileDeferredNV", "device, pipeline, shader", "VkResult");
    VkResult result = device_dispatch_table(device)->CompileDeferredNV(device, pipeline, shader);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCompileDeferredNV(ApiDumpInstance::current(), result, device, pipeline, shader);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCompileDeferredNV(ApiDumpInstance::current(), result, device, pipeline, shader);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCompileDeferredNV(ApiDumpInstance::current(), result, device, pipeline, shader);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetDescriptorSetLayoutSupportKHR(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDescriptorSetLayoutSupportKHR", "device, pCreateInfo, pSupport", "void");
    device_dispatch_table(device)->GetDescriptorSetLayoutSupportKHR(device, pCreateInfo, pSupport);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDescriptorSetLayoutSupportKHR(ApiDumpInstance::current(), device, pCreateInfo, pSupport);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDescriptorSetLayoutSupportKHR(ApiDumpInstance::current(), device, pCreateInfo, pSupport);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDescriptorSetLayoutSupportKHR(ApiDumpInstance::current(), device, pCreateInfo, pSupport);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdDrawIndirectCountKHR", "commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride", "void");
    device_dispatch_table(commandBuffer)->CmdDrawIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdDrawIndirectCountKHR(ApiDumpInstance::current(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdDrawIndirectCountKHR(ApiDumpInstance::current(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdDrawIndirectCountKHR(ApiDumpInstance::current(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdDrawIndexedIndirectCountKHR", "commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride", "void");
    device_dispatch_table(commandBuffer)->CmdDrawIndexedIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdDrawIndexedIndirectCountKHR(ApiDumpInstance::current(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdDrawIndexedIndirectCountKHR(ApiDumpInstance::current(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdDrawIndexedIndirectCountKHR(ApiDumpInstance::current(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryHostPointerPropertiesEXT(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, const void* pHostPointer, VkMemoryHostPointerPropertiesEXT* pMemoryHostPointerProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetMemoryHostPointerPropertiesEXT", "device, handleType, pHostPointer, pMemoryHostPointerProperties", "VkResult");
    VkResult result = device_dispatch_table(device)->GetMemoryHostPointerPropertiesEXT(device, handleType, pHostPointer, pMemoryHostPointerProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetMemoryHostPointerPropertiesEXT(ApiDumpInstance::current(), result, device, handleType, pHostPointer, pMemoryHostPointerProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetMemoryHostPointerPropertiesEXT(ApiDumpInstance::current(), result, device, handleType, pHostPointer, pMemoryHostPointerProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetMemoryHostPointerPropertiesEXT(ApiDumpInstance::current(), result, device, handleType, pHostPointer, pMemoryHostPointerProperties);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdWriteBufferMarkerAMD", "commandBuffer, pipelineStage, dstBuffer, dstOffset, marker", "void");
    device_dispatch_table(commandBuffer)->CmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdWriteBufferMarkerAMD(ApiDumpInstance::current(), commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdWriteBufferMarkerAMD(ApiDumpInstance::current(), commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdWriteBufferMarkerAMD(ApiDumpInstance::current(), commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetCalibratedTimestampsKHR(VkDevice device, uint32_t timestampCount, const VkCalibratedTimestampInfoKHR* pTimestampInfos, uint64_t* pTimestamps, uint64_t* pMaxDeviation)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetCalibratedTimestampsKHR", "device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation", "VkResult");
    VkResult result = device_dispatch_table(device)->GetCalibratedTimestampsKHR(device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetCalibratedTimestampsKHR(ApiDumpInstance::current(), result, device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetCalibratedTimestampsKHR(ApiDumpInstance::current(), result, device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetCalibratedTimestampsKHR(ApiDumpInstance::current(), result, device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetCalibratedTimestampsEXT(VkDevice device, uint32_t timestampCount, const VkCalibratedTimestampInfoKHR* pTimestampInfos, uint64_t* pTimestamps, uint64_t* pMaxDeviation)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetCalibratedTimestampsEXT", "device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation", "VkResult");
    VkResult result = device_dispatch_table(device)->GetCalibratedTimestampsEXT(device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetCalibratedTimestampsEXT(ApiDumpInstance::current(), result, device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetCalibratedTimestampsEXT(ApiDumpInstance::current(), result, device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetCalibratedTimestampsEXT(ApiDumpInstance::current(), result, device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdDrawMeshTasksNV", "commandBuffer, taskCount, firstTask", "void");
    device_dispatch_table(commandBuffer)->CmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdDrawMeshTasksNV(ApiDumpInstance::current(), commandBuffer, taskCount, firstTask);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdDrawMeshTasksNV(ApiDumpInstance::current(), commandBuffer, taskCount, firstTask);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdDrawMeshTasksNV(ApiDumpInstance::current(), commandBuffer, taskCount, firstTask);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawMeshTasksIndirectNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdDrawMeshTasksIndirectNV", "commandBuffer, buffer, offset, drawCount, stride", "void");
    device_dispatch_table(commandBuffer)->CmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdDrawMeshTasksIndirectNV(ApiDumpInstance::current(), commandBuffer, buffer, offset, drawCount, stride);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdDrawMeshTasksIndirectNV(ApiDumpInstance::current(), commandBuffer, buffer, offset, drawCount, stride);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdDrawMeshTasksIndirectNV(ApiDumpInstance::current(), commandBuffer, buffer, offset, drawCount, stride);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdDrawMeshTasksIndirectCountNV", "commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride", "void");
    device_dispatch_table(commandBuffer)->CmdDrawMeshTasksIndirectCountNV(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdDrawMeshTasksIndirectCountNV(ApiDumpInstance::current(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdDrawMeshTasksIndirectCountNV(ApiDumpInstance::current(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdDrawMeshTasksIndirectCountNV(ApiDumpInstance::current(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetExclusiveScissorEnableNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkBool32* pExclusiveScissorEnables)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetExclusiveScissorEnableNV", "commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissorEnables", "void");
    device_dispatch_table(commandBuffer)->CmdSetExclusiveScissorEnableNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissorEnables);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetExclusiveScissorEnableNV(ApiDumpInstance::current(), commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissorEnables);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetExclusiveScissorEnableNV(ApiDumpInstance::current(), commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissorEnables);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetExclusiveScissorEnableNV(ApiDumpInstance::current(), commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissorEnables);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetExclusiveScissorNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetExclusiveScissorNV", "commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors", "void");
    device_dispatch_table(commandBuffer)->CmdSetExclusiveScissorNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetExclusiveScissorNV(ApiDumpInstance::current(), commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetExclusiveScissorNV(ApiDumpInstance::current(), commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetExclusiveScissorNV(ApiDumpInstance::current(), commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetCheckpointNV(VkCommandBuffer commandBuffer, const void* pCheckpointMarker)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetCheckpointNV", "commandBuffer, pCheckpointMarker", "void");
    device_dispatch_table(commandBuffer)->CmdSetCheckpointNV(commandBuffer, pCheckpointMarker);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetCheckpointNV(ApiDumpInstance::current(), commandBuffer, pCheckpointMarker);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetCheckpointNV(ApiDumpInstance::current(), commandBuffer, pCheckpointMarker);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetCheckpointNV(ApiDumpInstance::current(), commandBuffer, pCheckpointMarker);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetQueueCheckpointDataNV(VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointDataNV* pCheckpointData)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetQueueCheckpointDataNV", "queue, pCheckpointDataCount, pCheckpointData", "void");
    device_dispatch_table(queue)->GetQueueCheckpointDataNV(queue, pCheckpointDataCount, pCheckpointData);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetQueueCheckpointDataNV(ApiDumpInstance::current(), queue, pCheckpointDataCount, pCheckpointData);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetQueueCheckpointDataNV(ApiDumpInstance::current(), queue, pCheckpointDataCount, pCheckpointData);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetQueueCheckpointDataNV(ApiDumpInstance::current(), queue, pCheckpointDataCount, pCheckpointData);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetSemaphoreCounterValueKHR(VkDevice device, VkSemaphore semaphore, uint64_t* pValue)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetSemaphoreCounterValueKHR", "device, semaphore, pValue", "VkResult");
    VkResult result = device_dispatch_table(device)->GetSemaphoreCounterValueKHR(device, semaphore, pValue);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetSemaphoreCounterValueKHR(ApiDumpInstance::current(), result, device, semaphore, pValue);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetSemaphoreCounterValueKHR(ApiDumpInstance::current(), result, device, semaphore, pValue);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetSemaphoreCounterValueKHR(ApiDumpInstance::current(), result, device, semaphore, pValue);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkWaitSemaphoresKHR(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkWaitSemaphoresKHR", "device, pWaitInfo, timeout", "VkResult");
    VkResult result = device_dispatch_table(device)->WaitSemaphoresKHR(device, pWaitInfo, timeout);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkWaitSemaphoresKHR(ApiDumpInstance::current(), result, device, pWaitInfo, timeout);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkWaitSemaphoresKHR(ApiDumpInstance::current(), result, device, pWaitInfo, timeout);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkWaitSemaphoresKHR(ApiDumpInstance::current(), result, device, pWaitInfo, timeout);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkSignalSemaphoreKHR(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkSignalSemaphoreKHR", "device, pSignalInfo", "VkResult");
    VkResult result = device_dispatch_table(device)->SignalSemaphoreKHR(device, pSignalInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkSignalSemaphoreKHR(ApiDumpInstance::current(), result, device, pSignalInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkSignalSemaphoreKHR(ApiDumpInstance::current(), result, device, pSignalInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkSignalSemaphoreKHR(ApiDumpInstance::current(), result, device, pSignalInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkInitializePerformanceApiINTEL(VkDevice device, const VkInitializePerformanceApiInfoINTEL* pInitializeInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkInitializePerformanceApiINTEL", "device, pInitializeInfo", "VkResult");
    VkResult result = device_dispatch_table(device)->InitializePerformanceApiINTEL(device, pInitializeInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkInitializePerformanceApiINTEL(ApiDumpInstance::current(), result, device, pInitializeInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkInitializePerformanceApiINTEL(ApiDumpInstance::current(), result, device, pInitializeInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkInitializePerformanceApiINTEL(ApiDumpInstance::current(), result, device, pInitializeInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkUninitializePerformanceApiINTEL(VkDevice device)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkUninitializePerformanceApiINTEL", "device", "void");
    device_dispatch_table(device)->UninitializePerformanceApiINTEL(device);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkUninitializePerformanceApiINTEL(ApiDumpInstance::current(), device);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkUninitializePerformanceApiINTEL(ApiDumpInstance::current(), device);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkUninitializePerformanceApiINTEL(ApiDumpInstance::current(), device);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkCmdSetPerformanceMarkerINTEL(VkCommandBuffer commandBuffer, const VkPerformanceMarkerInfoINTEL* pMarkerInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetPerformanceMarkerINTEL", "commandBuffer, pMarkerInfo", "VkResult");
    VkResult result = device_dispatch_table(commandBuffer)->CmdSetPerformanceMarkerINTEL(commandBuffer, pMarkerInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetPerformanceMarkerINTEL(ApiDumpInstance::current(), result, commandBuffer, pMarkerInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetPerformanceMarkerINTEL(ApiDumpInstance::current(), result, commandBuffer, pMarkerInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetPerformanceMarkerINTEL(ApiDumpInstance::current(), result, commandBuffer, pMarkerInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCmdSetPerformanceStreamMarkerINTEL(VkCommandBuffer commandBuffer, const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetPerformanceStreamMarkerINTEL", "commandBuffer, pMarkerInfo", "VkResult");
    VkResult result = device_dispatch_table(commandBuffer)->CmdSetPerformanceStreamMarkerINTEL(commandBuffer, pMarkerInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetPerformanceStreamMarkerINTEL(ApiDumpInstance::current(), result, commandBuffer, pMarkerInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetPerformanceStreamMarkerINTEL(ApiDumpInstance::current(), result, commandBuffer, pMarkerInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetPerformanceStreamMarkerINTEL(ApiDumpInstance::current(), result, commandBuffer, pMarkerInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCmdSetPerformanceOverrideINTEL(VkCommandBuffer commandBuffer, const VkPerformanceOverrideInfoINTEL* pOverrideInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetPerformanceOverrideINTEL", "commandBuffer, pOverrideInfo", "VkResult");
    VkResult result = device_dispatch_table(commandBuffer)->CmdSetPerformanceOverrideINTEL(commandBuffer, pOverrideInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetPerformanceOverrideINTEL(ApiDumpInstance::current(), result, commandBuffer, pOverrideInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetPerformanceOverrideINTEL(ApiDumpInstance::current(), result, commandBuffer, pOverrideInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetPerformanceOverrideINTEL(ApiDumpInstance::current(), result, commandBuffer, pOverrideInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkAcquirePerformanceConfigurationINTEL(VkDevice device, const VkPerformanceConfigurationAcquireInfoINTEL* pAcquireInfo, VkPerformanceConfigurationINTEL* pConfiguration)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkAcquirePerformanceConfigurationINTEL", "device, pAcquireInfo, pConfiguration", "VkResult");
    VkResult result = device_dispatch_table(device)->AcquirePerformanceConfigurationINTEL(device, pAcquireInfo, pConfiguration);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkAcquirePerformanceConfigurationINTEL(ApiDumpInstance::current(), result, device, pAcquireInfo, pConfiguration);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkAcquirePerformanceConfigurationINTEL(ApiDumpInstance::current(), result, device, pAcquireInfo, pConfiguration);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkAcquirePerformanceConfigurationINTEL(ApiDumpInstance::current(), result, device, pAcquireInfo, pConfiguration);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkReleasePerformanceConfigurationINTEL(VkDevice device, VkPerformanceConfigurationINTEL configuration)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkReleasePerformanceConfigurationINTEL", "device, configuration", "VkResult");
    VkResult result = device_dispatch_table(device)->ReleasePerformanceConfigurationINTEL(device, configuration);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkReleasePerformanceConfigurationINTEL(ApiDumpInstance::current(), result, device, configuration);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkReleasePerformanceConfigurationINTEL(ApiDumpInstance::current(), result, device, configuration);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkReleasePerformanceConfigurationINTEL(ApiDumpInstance::current(), result, device, configuration);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkQueueSetPerformanceConfigurationINTEL(VkQueue queue, VkPerformanceConfigurationINTEL configuration)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkQueueSetPerformanceConfigurationINTEL", "queue, configuration", "VkResult");
    VkResult result = device_dispatch_table(queue)->QueueSetPerformanceConfigurationINTEL(queue, configuration);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkQueueSetPerformanceConfigurationINTEL(ApiDumpInstance::current(), result, queue, configuration);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkQueueSetPerformanceConfigurationINTEL(ApiDumpInstance::current(), result, queue, configuration);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkQueueSetPerformanceConfigurationINTEL(ApiDumpInstance::current(), result, queue, configuration);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPerformanceParameterINTEL(VkDevice device, VkPerformanceParameterTypeINTEL parameter, VkPerformanceValueINTEL* pValue)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPerformanceParameterINTEL", "device, parameter, pValue", "VkResult");
    VkResult result = device_dispatch_table(device)->GetPerformanceParameterINTEL(device, parameter, pValue);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPerformanceParameterINTEL(ApiDumpInstance::current(), result, device, parameter, pValue);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPerformanceParameterINTEL(ApiDumpInstance::current(), result, device, parameter, pValue);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPerformanceParameterINTEL(ApiDumpInstance::current(), result, device, parameter, pValue);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkSetLocalDimmingAMD(VkDevice device, VkSwapchainKHR swapChain, VkBool32 localDimmingEnable)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkSetLocalDimmingAMD", "device, swapChain, localDimmingEnable", "void");
    device_dispatch_table(device)->SetLocalDimmingAMD(device, swapChain, localDimmingEnable);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkSetLocalDimmingAMD(ApiDumpInstance::current(), device, swapChain, localDimmingEnable);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkSetLocalDimmingAMD(ApiDumpInstance::current(), device, swapChain, localDimmingEnable);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkSetLocalDimmingAMD(ApiDumpInstance::current(), device, swapChain, localDimmingEnable);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetFragmentShadingRateKHR(VkCommandBuffer           commandBuffer, const VkExtent2D*                           pFragmentSize, const VkFragmentShadingRateCombinerOpKHR    combinerOps[2])
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetFragmentShadingRateKHR", "commandBuffer, pFragmentSize, combinerOps", "void");
    device_dispatch_table(commandBuffer)->CmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetFragmentShadingRateKHR(ApiDumpInstance::current(), commandBuffer, pFragmentSize, combinerOps);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetFragmentShadingRateKHR(ApiDumpInstance::current(), commandBuffer, pFragmentSize, combinerOps);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetFragmentShadingRateKHR(ApiDumpInstance::current(), commandBuffer, pFragmentSize, combinerOps);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetRenderingAttachmentLocationsKHR(VkCommandBuffer commandBuffer, const VkRenderingAttachmentLocationInfoKHR* pLocationInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetRenderingAttachmentLocationsKHR", "commandBuffer, pLocationInfo", "void");
    device_dispatch_table(commandBuffer)->CmdSetRenderingAttachmentLocationsKHR(commandBuffer, pLocationInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetRenderingAttachmentLocationsKHR(ApiDumpInstance::current(), commandBuffer, pLocationInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetRenderingAttachmentLocationsKHR(ApiDumpInstance::current(), commandBuffer, pLocationInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetRenderingAttachmentLocationsKHR(ApiDumpInstance::current(), commandBuffer, pLocationInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetRenderingInputAttachmentIndicesKHR(VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfoKHR* pInputAttachmentIndexInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetRenderingInputAttachmentIndicesKHR", "commandBuffer, pInputAttachmentIndexInfo", "void");
    device_dispatch_table(commandBuffer)->CmdSetRenderingInputAttachmentIndicesKHR(commandBuffer, pInputAttachmentIndexInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetRenderingInputAttachmentIndicesKHR(ApiDumpInstance::current(), commandBuffer, pInputAttachmentIndexInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetRenderingInputAttachmentIndicesKHR(ApiDumpInstance::current(), commandBuffer, pInputAttachmentIndexInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetRenderingInputAttachmentIndicesKHR(ApiDumpInstance::current(), commandBuffer, pInputAttachmentIndexInfo);
                break;
        }
    }
}
VKAPI_ATTR VkDeviceAddress VKAPI_CALL vkGetBufferDeviceAddressEXT(VkDevice device, const VkBufferDeviceAddressInfo* pInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetBufferDeviceAddressEXT", "device, pInfo", "VkDeviceAddress");
    VkDeviceAddress result = device_dispatch_table(device)->GetBufferDeviceAddressEXT(device, pInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetBufferDeviceAddressEXT(ApiDumpInstance::current(), result, device, pInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetBufferDeviceAddressEXT(ApiDumpInstance::current(), result, device, pInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetBufferDeviceAddressEXT(ApiDumpInstance::current(), result, device, pInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkWaitForPresentKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t presentId, uint64_t timeout)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkWaitForPresentKHR", "device, swapchain, presentId, timeout", "VkResult");
    VkResult result = device_dispatch_table(device)->WaitForPresentKHR(device, swapchain, presentId, timeout);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkWaitForPresentKHR(ApiDumpInstance::current(), result, device, swapchain, presentId, timeout);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkWaitForPresentKHR(ApiDumpInstance::current(), result, device, swapchain, presentId, timeout);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkWaitForPresentKHR(ApiDumpInstance::current(), result, device, swapchain, presentId, timeout);
                break;
        }
    }
    return result;
}
#if defined(VK_USE_PLATFORM_WIN32_KHR)
VKAPI_ATTR VkResult VKAPI_CALL vkAcquireFullScreenExclusiveModeEXT(VkDevice device, VkSwapchainKHR swapchain)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkAcquireFullScreenExclusiveModeEXT", "device, swapchain", "VkResult");
    VkResult result = device_dispatch_table(device)->AcquireFullScreenExclusiveModeEXT(device, swapchain);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkAcquireFullScreenExclusiveModeEXT(ApiDumpInstance::current(), result, device, swapchain);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkAcquireFullScreenExclusiveModeEXT(ApiDumpInstance::current(), result, device, swapchain);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkAcquireFullScreenExclusiveModeEXT(ApiDumpInstance::current(), result, device, swapchain);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
VKAPI_ATTR VkResult VKAPI_CALL vkReleaseFullScreenExclusiveModeEXT(VkDevice device, VkSwapchainKHR swapchain)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkReleaseFullScreenExclusiveModeEXT", "device, swapchain", "VkResult");
    VkResult result = device_dispatch_table(device)->ReleaseFullScreenExclusiveModeEXT(device, swapchain);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkReleaseFullScreenExclusiveModeEXT(ApiDumpInstance::current(), result, device, swapchain);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkReleaseFullScreenExclusiveModeEXT(ApiDumpInstance::current(), result, device, swapchain);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkReleaseFullScreenExclusiveModeEXT(ApiDumpInstance::current(), result, device, swapchain);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
VKAPI_ATTR VkResult VKAPI_CALL vkGetDeviceGroupSurfacePresentModes2EXT(VkDevice device, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkDeviceGroupPresentModeFlagsKHR* pModes)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDeviceGroupSurfacePresentModes2EXT", "device, pSurfaceInfo, pModes", "VkResult");
    VkResult result = device_dispatch_table(device)->GetDeviceGroupSurfacePresentModes2EXT(device, pSurfaceInfo, pModes);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDeviceGroupSurfacePresentModes2EXT(ApiDumpInstance::current(), result, device, pSurfaceInfo, pModes);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDeviceGroupSurfacePresentModes2EXT(ApiDumpInstance::current(), result, device, pSurfaceInfo, pModes);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDeviceGroupSurfacePresentModes2EXT(ApiDumpInstance::current(), result, device, pSurfaceInfo, pModes);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_WIN32_KHR
VKAPI_ATTR VkDeviceAddress VKAPI_CALL vkGetBufferDeviceAddressKHR(VkDevice device, const VkBufferDeviceAddressInfo* pInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetBufferDeviceAddressKHR", "device, pInfo", "VkDeviceAddress");
    VkDeviceAddress result = device_dispatch_table(device)->GetBufferDeviceAddressKHR(device, pInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetBufferDeviceAddressKHR(ApiDumpInstance::current(), result, device, pInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetBufferDeviceAddressKHR(ApiDumpInstance::current(), result, device, pInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetBufferDeviceAddressKHR(ApiDumpInstance::current(), result, device, pInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR uint64_t VKAPI_CALL vkGetBufferOpaqueCaptureAddressKHR(VkDevice device, const VkBufferDeviceAddressInfo* pInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetBufferOpaqueCaptureAddressKHR", "device, pInfo", "uint64_t");
    uint64_t result = device_dispatch_table(device)->GetBufferOpaqueCaptureAddressKHR(device, pInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetBufferOpaqueCaptureAddressKHR(ApiDumpInstance::current(), result, device, pInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetBufferOpaqueCaptureAddressKHR(ApiDumpInstance::current(), result, device, pInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetBufferOpaqueCaptureAddressKHR(ApiDumpInstance::current(), result, device, pInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR uint64_t VKAPI_CALL vkGetDeviceMemoryOpaqueCaptureAddressKHR(VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDeviceMemoryOpaqueCaptureAddressKHR", "device, pInfo", "uint64_t");
    uint64_t result = device_dispatch_table(device)->GetDeviceMemoryOpaqueCaptureAddressKHR(device, pInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDeviceMemoryOpaqueCaptureAddressKHR(ApiDumpInstance::current(), result, device, pInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDeviceMemoryOpaqueCaptureAddressKHR(ApiDumpInstance::current(), result, device, pInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDeviceMemoryOpaqueCaptureAddressKHR(ApiDumpInstance::current(), result, device, pInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetLineStippleKHR(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetLineStippleKHR", "commandBuffer, lineStippleFactor, lineStipplePattern", "void");
    device_dispatch_table(commandBuffer)->CmdSetLineStippleKHR(commandBuffer, lineStippleFactor, lineStipplePattern);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetLineStippleKHR(ApiDumpInstance::current(), commandBuffer, lineStippleFactor, lineStipplePattern);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetLineStippleKHR(ApiDumpInstance::current(), commandBuffer, lineStippleFactor, lineStipplePattern);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetLineStippleKHR(ApiDumpInstance::current(), commandBuffer, lineStippleFactor, lineStipplePattern);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetLineStippleEXT", "commandBuffer, lineStippleFactor, lineStipplePattern", "void");
    device_dispatch_table(commandBuffer)->CmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetLineStippleEXT(ApiDumpInstance::current(), commandBuffer, lineStippleFactor, lineStipplePattern);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetLineStippleEXT(ApiDumpInstance::current(), commandBuffer, lineStippleFactor, lineStipplePattern);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetLineStippleEXT(ApiDumpInstance::current(), commandBuffer, lineStippleFactor, lineStipplePattern);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkResetQueryPoolEXT(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkResetQueryPoolEXT", "device, queryPool, firstQuery, queryCount", "void");
    device_dispatch_table(device)->ResetQueryPoolEXT(device, queryPool, firstQuery, queryCount);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkResetQueryPoolEXT(ApiDumpInstance::current(), device, queryPool, firstQuery, queryCount);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkResetQueryPoolEXT(ApiDumpInstance::current(), device, queryPool, firstQuery, queryCount);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkResetQueryPoolEXT(ApiDumpInstance::current(), device, queryPool, firstQuery, queryCount);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetCullModeEXT", "commandBuffer, cullMode", "void");
    device_dispatch_table(commandBuffer)->CmdSetCullModeEXT(commandBuffer, cullMode);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetCullModeEXT(ApiDumpInstance::current(), commandBuffer, cullMode);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetCullModeEXT(ApiDumpInstance::current(), commandBuffer, cullMode);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetCullModeEXT(ApiDumpInstance::current(), commandBuffer, cullMode);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetFrontFaceEXT", "commandBuffer, frontFace", "void");
    device_dispatch_table(commandBuffer)->CmdSetFrontFaceEXT(commandBuffer, frontFace);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetFrontFaceEXT(ApiDumpInstance::current(), commandBuffer, frontFace);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetFrontFaceEXT(ApiDumpInstance::current(), commandBuffer, frontFace);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetFrontFaceEXT(ApiDumpInstance::current(), commandBuffer, frontFace);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetPrimitiveTopologyEXT", "commandBuffer, primitiveTopology", "void");
    device_dispatch_table(commandBuffer)->CmdSetPrimitiveTopologyEXT(commandBuffer, primitiveTopology);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetPrimitiveTopologyEXT(ApiDumpInstance::current(), commandBuffer, primitiveTopology);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetPrimitiveTopologyEXT(ApiDumpInstance::current(), commandBuffer, primitiveTopology);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetPrimitiveTopologyEXT(ApiDumpInstance::current(), commandBuffer, primitiveTopology);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetViewportWithCountEXT", "commandBuffer, viewportCount, pViewports", "void");
    device_dispatch_table(commandBuffer)->CmdSetViewportWithCountEXT(commandBuffer, viewportCount, pViewports);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetViewportWithCountEXT(ApiDumpInstance::current(), commandBuffer, viewportCount, pViewports);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetViewportWithCountEXT(ApiDumpInstance::current(), commandBuffer, viewportCount, pViewports);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetViewportWithCountEXT(ApiDumpInstance::current(), commandBuffer, viewportCount, pViewports);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetScissorWithCountEXT", "commandBuffer, scissorCount, pScissors", "void");
    device_dispatch_table(commandBuffer)->CmdSetScissorWithCountEXT(commandBuffer, scissorCount, pScissors);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetScissorWithCountEXT(ApiDumpInstance::current(), commandBuffer, scissorCount, pScissors);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetScissorWithCountEXT(ApiDumpInstance::current(), commandBuffer, scissorCount, pScissors);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetScissorWithCountEXT(ApiDumpInstance::current(), commandBuffer, scissorCount, pScissors);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdBindVertexBuffers2EXT", "commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides", "void");
    device_dispatch_table(commandBuffer)->CmdBindVertexBuffers2EXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdBindVertexBuffers2EXT(ApiDumpInstance::current(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdBindVertexBuffers2EXT(ApiDumpInstance::current(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdBindVertexBuffers2EXT(ApiDumpInstance::current(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetDepthTestEnableEXT", "commandBuffer, depthTestEnable", "void");
    device_dispatch_table(commandBuffer)->CmdSetDepthTestEnableEXT(commandBuffer, depthTestEnable);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetDepthTestEnableEXT(ApiDumpInstance::current(), commandBuffer, depthTestEnable);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetDepthTestEnableEXT(ApiDumpInstance::current(), commandBuffer, depthTestEnable);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetDepthTestEnableEXT(ApiDumpInstance::current(), commandBuffer, depthTestEnable);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetDepthWriteEnableEXT", "commandBuffer, depthWriteEnable", "void");
    device_dispatch_table(commandBuffer)->CmdSetDepthWriteEnableEXT(commandBuffer, depthWriteEnable);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetDepthWriteEnableEXT(ApiDumpInstance::current(), commandBuffer, depthWriteEnable);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetDepthWriteEnableEXT(ApiDumpInstance::current(), commandBuffer, depthWriteEnable);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetDepthWriteEnableEXT(ApiDumpInstance::current(), commandBuffer, depthWriteEnable);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetDepthCompareOpEXT", "commandBuffer, depthCompareOp", "void");
    device_dispatch_table(commandBuffer)->CmdSetDepthCompareOpEXT(commandBuffer, depthCompareOp);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetDepthCompareOpEXT(ApiDumpInstance::current(), commandBuffer, depthCompareOp);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetDepthCompareOpEXT(ApiDumpInstance::current(), commandBuffer, depthCompareOp);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetDepthCompareOpEXT(ApiDumpInstance::current(), commandBuffer, depthCompareOp);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetDepthBoundsTestEnableEXT", "commandBuffer, depthBoundsTestEnable", "void");
    device_dispatch_table(commandBuffer)->CmdSetDepthBoundsTestEnableEXT(commandBuffer, depthBoundsTestEnable);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetDepthBoundsTestEnableEXT(ApiDumpInstance::current(), commandBuffer, depthBoundsTestEnable);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetDepthBoundsTestEnableEXT(ApiDumpInstance::current(), commandBuffer, depthBoundsTestEnable);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetDepthBoundsTestEnableEXT(ApiDumpInstance::current(), commandBuffer, depthBoundsTestEnable);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetStencilTestEnableEXT", "commandBuffer, stencilTestEnable", "void");
    device_dispatch_table(commandBuffer)->CmdSetStencilTestEnableEXT(commandBuffer, stencilTestEnable);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetStencilTestEnableEXT(ApiDumpInstance::current(), commandBuffer, stencilTestEnable);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetStencilTestEnableEXT(ApiDumpInstance::current(), commandBuffer, stencilTestEnable);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetStencilTestEnableEXT(ApiDumpInstance::current(), commandBuffer, stencilTestEnable);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetStencilOpEXT", "commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp", "void");
    device_dispatch_table(commandBuffer)->CmdSetStencilOpEXT(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetStencilOpEXT(ApiDumpInstance::current(), commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetStencilOpEXT(ApiDumpInstance::current(), commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetStencilOpEXT(ApiDumpInstance::current(), commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDeferredOperationKHR(VkDevice device, const VkAllocationCallbacks* pAllocator, VkDeferredOperationKHR* pDeferredOperation)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateDeferredOperationKHR", "device, pAllocator, pDeferredOperation", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateDeferredOperationKHR(device, pAllocator, pDeferredOperation);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateDeferredOperationKHR(ApiDumpInstance::current(), result, device, pAllocator, pDeferredOperation);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateDeferredOperationKHR(ApiDumpInstance::current(), result, device, pAllocator, pDeferredOperation);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateDeferredOperationKHR(ApiDumpInstance::current(), result, device, pAllocator, pDeferredOperation);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyDeferredOperationKHR(VkDevice device, VkDeferredOperationKHR operation, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyDeferredOperationKHR", "device, operation, pAllocator", "void");
    device_dispatch_table(device)->DestroyDeferredOperationKHR(device, operation, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyDeferredOperationKHR(ApiDumpInstance::current(), device, operation, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyDeferredOperationKHR(ApiDumpInstance::current(), device, operation, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyDeferredOperationKHR(ApiDumpInstance::current(), device, operation, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR uint32_t VKAPI_CALL vkGetDeferredOperationMaxConcurrencyKHR(VkDevice device, VkDeferredOperationKHR operation)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDeferredOperationMaxConcurrencyKHR", "device, operation", "uint32_t");
    uint32_t result = device_dispatch_table(device)->GetDeferredOperationMaxConcurrencyKHR(device, operation);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDeferredOperationMaxConcurrencyKHR(ApiDumpInstance::current(), result, device, operation);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDeferredOperationMaxConcurrencyKHR(ApiDumpInstance::current(), result, device, operation);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDeferredOperationMaxConcurrencyKHR(ApiDumpInstance::current(), result, device, operation);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetDeferredOperationResultKHR(VkDevice device, VkDeferredOperationKHR operation)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDeferredOperationResultKHR", "device, operation", "VkResult");
    VkResult result = device_dispatch_table(device)->GetDeferredOperationResultKHR(device, operation);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDeferredOperationResultKHR(ApiDumpInstance::current(), result, device, operation);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDeferredOperationResultKHR(ApiDumpInstance::current(), result, device, operation);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDeferredOperationResultKHR(ApiDumpInstance::current(), result, device, operation);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkDeferredOperationJoinKHR(VkDevice device, VkDeferredOperationKHR operation)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDeferredOperationJoinKHR", "device, operation", "VkResult");
    VkResult result = device_dispatch_table(device)->DeferredOperationJoinKHR(device, operation);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDeferredOperationJoinKHR(ApiDumpInstance::current(), result, device, operation);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDeferredOperationJoinKHR(ApiDumpInstance::current(), result, device, operation);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDeferredOperationJoinKHR(ApiDumpInstance::current(), result, device, operation);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPipelineExecutablePropertiesKHR(VkDevice                        device, const VkPipelineInfoKHR*        pPipelineInfo, uint32_t* pExecutableCount, VkPipelineExecutablePropertiesKHR* pProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPipelineExecutablePropertiesKHR", "device, pPipelineInfo, pExecutableCount, pProperties", "VkResult");
    VkResult result = device_dispatch_table(device)->GetPipelineExecutablePropertiesKHR(device, pPipelineInfo, pExecutableCount, pProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPipelineExecutablePropertiesKHR(ApiDumpInstance::current(), result, device, pPipelineInfo, pExecutableCount, pProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPipelineExecutablePropertiesKHR(ApiDumpInstance::current(), result, device, pPipelineInfo, pExecutableCount, pProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPipelineExecutablePropertiesKHR(ApiDumpInstance::current(), result, device, pPipelineInfo, pExecutableCount, pProperties);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPipelineExecutableStatisticsKHR(VkDevice                        device, const VkPipelineExecutableInfoKHR*  pExecutableInfo, uint32_t* pStatisticCount, VkPipelineExecutableStatisticKHR* pStatistics)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPipelineExecutableStatisticsKHR", "device, pExecutableInfo, pStatisticCount, pStatistics", "VkResult");
    VkResult result = device_dispatch_table(device)->GetPipelineExecutableStatisticsKHR(device, pExecutableInfo, pStatisticCount, pStatistics);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPipelineExecutableStatisticsKHR(ApiDumpInstance::current(), result, device, pExecutableInfo, pStatisticCount, pStatistics);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPipelineExecutableStatisticsKHR(ApiDumpInstance::current(), result, device, pExecutableInfo, pStatisticCount, pStatistics);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPipelineExecutableStatisticsKHR(ApiDumpInstance::current(), result, device, pExecutableInfo, pStatisticCount, pStatistics);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPipelineExecutableInternalRepresentationsKHR(VkDevice                        device, const VkPipelineExecutableInfoKHR*  pExecutableInfo, uint32_t* pInternalRepresentationCount, VkPipelineExecutableInternalRepresentationKHR* pInternalRepresentations)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPipelineExecutableInternalRepresentationsKHR", "device, pExecutableInfo, pInternalRepresentationCount, pInternalRepresentations", "VkResult");
    VkResult result = device_dispatch_table(device)->GetPipelineExecutableInternalRepresentationsKHR(device, pExecutableInfo, pInternalRepresentationCount, pInternalRepresentations);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPipelineExecutableInternalRepresentationsKHR(ApiDumpInstance::current(), result, device, pExecutableInfo, pInternalRepresentationCount, pInternalRepresentations);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPipelineExecutableInternalRepresentationsKHR(ApiDumpInstance::current(), result, device, pExecutableInfo, pInternalRepresentationCount, pInternalRepresentations);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPipelineExecutableInternalRepresentationsKHR(ApiDumpInstance::current(), result, device, pExecutableInfo, pInternalRepresentationCount, pInternalRepresentations);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCopyMemoryToImageEXT(VkDevice device, const VkCopyMemoryToImageInfoEXT* pCopyMemoryToImageInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCopyMemoryToImageEXT", "device, pCopyMemoryToImageInfo", "VkResult");
    VkResult result = device_dispatch_table(device)->CopyMemoryToImageEXT(device, pCopyMemoryToImageInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCopyMemoryToImageEXT(ApiDumpInstance::current(), result, device, pCopyMemoryToImageInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCopyMemoryToImageEXT(ApiDumpInstance::current(), result, device, pCopyMemoryToImageInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCopyMemoryToImageEXT(ApiDumpInstance::current(), result, device, pCopyMemoryToImageInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCopyImageToMemoryEXT(VkDevice device, const VkCopyImageToMemoryInfoEXT* pCopyImageToMemoryInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCopyImageToMemoryEXT", "device, pCopyImageToMemoryInfo", "VkResult");
    VkResult result = device_dispatch_table(device)->CopyImageToMemoryEXT(device, pCopyImageToMemoryInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCopyImageToMemoryEXT(ApiDumpInstance::current(), result, device, pCopyImageToMemoryInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCopyImageToMemoryEXT(ApiDumpInstance::current(), result, device, pCopyImageToMemoryInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCopyImageToMemoryEXT(ApiDumpInstance::current(), result, device, pCopyImageToMemoryInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCopyImageToImageEXT(VkDevice device, const VkCopyImageToImageInfoEXT* pCopyImageToImageInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCopyImageToImageEXT", "device, pCopyImageToImageInfo", "VkResult");
    VkResult result = device_dispatch_table(device)->CopyImageToImageEXT(device, pCopyImageToImageInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCopyImageToImageEXT(ApiDumpInstance::current(), result, device, pCopyImageToImageInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCopyImageToImageEXT(ApiDumpInstance::current(), result, device, pCopyImageToImageInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCopyImageToImageEXT(ApiDumpInstance::current(), result, device, pCopyImageToImageInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkTransitionImageLayoutEXT(VkDevice device, uint32_t transitionCount, const VkHostImageLayoutTransitionInfoEXT* pTransitions)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkTransitionImageLayoutEXT", "device, transitionCount, pTransitions", "VkResult");
    VkResult result = device_dispatch_table(device)->TransitionImageLayoutEXT(device, transitionCount, pTransitions);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkTransitionImageLayoutEXT(ApiDumpInstance::current(), result, device, transitionCount, pTransitions);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkTransitionImageLayoutEXT(ApiDumpInstance::current(), result, device, transitionCount, pTransitions);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkTransitionImageLayoutEXT(ApiDumpInstance::current(), result, device, transitionCount, pTransitions);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetImageSubresourceLayout2KHR(VkDevice device, VkImage image, const VkImageSubresource2KHR* pSubresource, VkSubresourceLayout2KHR* pLayout)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetImageSubresourceLayout2KHR", "device, image, pSubresource, pLayout", "void");
    device_dispatch_table(device)->GetImageSubresourceLayout2KHR(device, image, pSubresource, pLayout);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetImageSubresourceLayout2KHR(ApiDumpInstance::current(), device, image, pSubresource, pLayout);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetImageSubresourceLayout2KHR(ApiDumpInstance::current(), device, image, pSubresource, pLayout);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetImageSubresourceLayout2KHR(ApiDumpInstance::current(), device, image, pSubresource, pLayout);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetImageSubresourceLayout2EXT(VkDevice device, VkImage image, const VkImageSubresource2KHR* pSubresource, VkSubresourceLayout2KHR* pLayout)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetImageSubresourceLayout2EXT", "device, image, pSubresource, pLayout", "void");
    device_dispatch_table(device)->GetImageSubresourceLayout2EXT(device, image, pSubresource, pLayout);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetImageSubresourceLayout2EXT(ApiDumpInstance::current(), device, image, pSubresource, pLayout);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetImageSubresourceLayout2EXT(ApiDumpInstance::current(), device, image, pSubresource, pLayout);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetImageSubresourceLayout2EXT(ApiDumpInstance::current(), device, image, pSubresource, pLayout);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkMapMemory2KHR(VkDevice device, const VkMemoryMapInfoKHR* pMemoryMapInfo, void** ppData)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkMapMemory2KHR", "device, pMemoryMapInfo, ppData", "VkResult");
    VkResult result = device_dispatch_table(device)->MapMemory2KHR(device, pMemoryMapInfo, ppData);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkMapMemory2KHR(ApiDumpInstance::current(), result, device, pMemoryMapInfo, ppData);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkMapMemory2KHR(ApiDumpInstance::current(), result, device, pMemoryMapInfo, ppData);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkMapMemory2KHR(ApiDumpInstance::current(), result, device, pMemoryMapInfo, ppData);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkUnmapMemory2KHR(VkDevice device, const VkMemoryUnmapInfoKHR* pMemoryUnmapInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkUnmapMemory2KHR", "device, pMemoryUnmapInfo", "VkResult");
    VkResult result = device_dispatch_table(device)->UnmapMemory2KHR(device, pMemoryUnmapInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkUnmapMemory2KHR(ApiDumpInstance::current(), result, device, pMemoryUnmapInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkUnmapMemory2KHR(ApiDumpInstance::current(), result, device, pMemoryUnmapInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkUnmapMemory2KHR(ApiDumpInstance::current(), result, device, pMemoryUnmapInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkReleaseSwapchainImagesEXT(VkDevice device, const VkReleaseSwapchainImagesInfoEXT* pReleaseInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkReleaseSwapchainImagesEXT", "device, pReleaseInfo", "VkResult");
    VkResult result = device_dispatch_table(device)->ReleaseSwapchainImagesEXT(device, pReleaseInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkReleaseSwapchainImagesEXT(ApiDumpInstance::current(), result, device, pReleaseInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkReleaseSwapchainImagesEXT(ApiDumpInstance::current(), result, device, pReleaseInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkReleaseSwapchainImagesEXT(ApiDumpInstance::current(), result, device, pReleaseInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetGeneratedCommandsMemoryRequirementsNV(VkDevice device, const VkGeneratedCommandsMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2* pMemoryRequirements)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetGeneratedCommandsMemoryRequirementsNV", "device, pInfo, pMemoryRequirements", "void");
    device_dispatch_table(device)->GetGeneratedCommandsMemoryRequirementsNV(device, pInfo, pMemoryRequirements);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetGeneratedCommandsMemoryRequirementsNV(ApiDumpInstance::current(), device, pInfo, pMemoryRequirements);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetGeneratedCommandsMemoryRequirementsNV(ApiDumpInstance::current(), device, pInfo, pMemoryRequirements);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetGeneratedCommandsMemoryRequirementsNV(ApiDumpInstance::current(), device, pInfo, pMemoryRequirements);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdPreprocessGeneratedCommandsNV(VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdPreprocessGeneratedCommandsNV", "commandBuffer, pGeneratedCommandsInfo", "void");
    device_dispatch_table(commandBuffer)->CmdPreprocessGeneratedCommandsNV(commandBuffer, pGeneratedCommandsInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdPreprocessGeneratedCommandsNV(ApiDumpInstance::current(), commandBuffer, pGeneratedCommandsInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdPreprocessGeneratedCommandsNV(ApiDumpInstance::current(), commandBuffer, pGeneratedCommandsInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdPreprocessGeneratedCommandsNV(ApiDumpInstance::current(), commandBuffer, pGeneratedCommandsInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdExecuteGeneratedCommandsNV(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdExecuteGeneratedCommandsNV", "commandBuffer, isPreprocessed, pGeneratedCommandsInfo", "void");
    device_dispatch_table(commandBuffer)->CmdExecuteGeneratedCommandsNV(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdExecuteGeneratedCommandsNV(ApiDumpInstance::current(), commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdExecuteGeneratedCommandsNV(ApiDumpInstance::current(), commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdExecuteGeneratedCommandsNV(ApiDumpInstance::current(), commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindPipelineShaderGroupNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline, uint32_t groupIndex)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdBindPipelineShaderGroupNV", "commandBuffer, pipelineBindPoint, pipeline, groupIndex", "void");
    device_dispatch_table(commandBuffer)->CmdBindPipelineShaderGroupNV(commandBuffer, pipelineBindPoint, pipeline, groupIndex);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdBindPipelineShaderGroupNV(ApiDumpInstance::current(), commandBuffer, pipelineBindPoint, pipeline, groupIndex);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdBindPipelineShaderGroupNV(ApiDumpInstance::current(), commandBuffer, pipelineBindPoint, pipeline, groupIndex);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdBindPipelineShaderGroupNV(ApiDumpInstance::current(), commandBuffer, pipelineBindPoint, pipeline, groupIndex);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateIndirectCommandsLayoutNV(VkDevice device, const VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkIndirectCommandsLayoutNV* pIndirectCommandsLayout)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateIndirectCommandsLayoutNV", "device, pCreateInfo, pAllocator, pIndirectCommandsLayout", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateIndirectCommandsLayoutNV(device, pCreateInfo, pAllocator, pIndirectCommandsLayout);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateIndirectCommandsLayoutNV(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pIndirectCommandsLayout);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateIndirectCommandsLayoutNV(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pIndirectCommandsLayout);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateIndirectCommandsLayoutNV(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pIndirectCommandsLayout);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyIndirectCommandsLayoutNV(VkDevice device, VkIndirectCommandsLayoutNV indirectCommandsLayout, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyIndirectCommandsLayoutNV", "device, indirectCommandsLayout, pAllocator", "void");
    device_dispatch_table(device)->DestroyIndirectCommandsLayoutNV(device, indirectCommandsLayout, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyIndirectCommandsLayoutNV(ApiDumpInstance::current(), device, indirectCommandsLayout, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyIndirectCommandsLayoutNV(ApiDumpInstance::current(), device, indirectCommandsLayout, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyIndirectCommandsLayoutNV(ApiDumpInstance::current(), device, indirectCommandsLayout, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthBias2EXT(VkCommandBuffer commandBuffer, const VkDepthBiasInfoEXT*         pDepthBiasInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetDepthBias2EXT", "commandBuffer, pDepthBiasInfo", "void");
    device_dispatch_table(commandBuffer)->CmdSetDepthBias2EXT(commandBuffer, pDepthBiasInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetDepthBias2EXT(ApiDumpInstance::current(), commandBuffer, pDepthBiasInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetDepthBias2EXT(ApiDumpInstance::current(), commandBuffer, pDepthBiasInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetDepthBias2EXT(ApiDumpInstance::current(), commandBuffer, pDepthBiasInfo);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreatePrivateDataSlotEXT(VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreatePrivateDataSlotEXT", "device, pCreateInfo, pAllocator, pPrivateDataSlot", "VkResult");
    VkResult result = device_dispatch_table(device)->CreatePrivateDataSlotEXT(device, pCreateInfo, pAllocator, pPrivateDataSlot);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreatePrivateDataSlotEXT(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pPrivateDataSlot);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreatePrivateDataSlotEXT(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pPrivateDataSlot);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreatePrivateDataSlotEXT(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pPrivateDataSlot);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyPrivateDataSlotEXT(VkDevice device, VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyPrivateDataSlotEXT", "device, privateDataSlot, pAllocator", "void");
    device_dispatch_table(device)->DestroyPrivateDataSlotEXT(device, privateDataSlot, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyPrivateDataSlotEXT(ApiDumpInstance::current(), device, privateDataSlot, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyPrivateDataSlotEXT(ApiDumpInstance::current(), device, privateDataSlot, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyPrivateDataSlotEXT(ApiDumpInstance::current(), device, privateDataSlot, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkSetPrivateDataEXT(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkSetPrivateDataEXT", "device, objectType, objectHandle, privateDataSlot, data", "VkResult");
    VkResult result = device_dispatch_table(device)->SetPrivateDataEXT(device, objectType, objectHandle, privateDataSlot, data);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkSetPrivateDataEXT(ApiDumpInstance::current(), result, device, objectType, objectHandle, privateDataSlot, data);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkSetPrivateDataEXT(ApiDumpInstance::current(), result, device, objectType, objectHandle, privateDataSlot, data);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkSetPrivateDataEXT(ApiDumpInstance::current(), result, device, objectType, objectHandle, privateDataSlot, data);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetPrivateDataEXT(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t* pData)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPrivateDataEXT", "device, objectType, objectHandle, privateDataSlot, pData", "void");
    device_dispatch_table(device)->GetPrivateDataEXT(device, objectType, objectHandle, privateDataSlot, pData);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPrivateDataEXT(ApiDumpInstance::current(), device, objectType, objectHandle, privateDataSlot, pData);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPrivateDataEXT(ApiDumpInstance::current(), device, objectType, objectHandle, privateDataSlot, pData);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPrivateDataEXT(ApiDumpInstance::current(), device, objectType, objectHandle, privateDataSlot, pData);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetEncodedVideoSessionParametersKHR(VkDevice device, const VkVideoEncodeSessionParametersGetInfoKHR* pVideoSessionParametersInfo, VkVideoEncodeSessionParametersFeedbackInfoKHR* pFeedbackInfo, size_t* pDataSize, void* pData)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetEncodedVideoSessionParametersKHR", "device, pVideoSessionParametersInfo, pFeedbackInfo, pDataSize, pData", "VkResult");
    VkResult result = device_dispatch_table(device)->GetEncodedVideoSessionParametersKHR(device, pVideoSessionParametersInfo, pFeedbackInfo, pDataSize, pData);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetEncodedVideoSessionParametersKHR(ApiDumpInstance::current(), result, device, pVideoSessionParametersInfo, pFeedbackInfo, pDataSize, pData);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetEncodedVideoSessionParametersKHR(ApiDumpInstance::current(), result, device, pVideoSessionParametersInfo, pFeedbackInfo, pDataSize, pData);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetEncodedVideoSessionParametersKHR(ApiDumpInstance::current(), result, device, pVideoSessionParametersInfo, pFeedbackInfo, pDataSize, pData);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdEncodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdEncodeVideoKHR", "commandBuffer, pEncodeInfo", "void");
    device_dispatch_table(commandBuffer)->CmdEncodeVideoKHR(commandBuffer, pEncodeInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdEncodeVideoKHR(ApiDumpInstance::current(), commandBuffer, pEncodeInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdEncodeVideoKHR(ApiDumpInstance::current(), commandBuffer, pEncodeInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdEncodeVideoKHR(ApiDumpInstance::current(), commandBuffer, pEncodeInfo);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateCudaModuleNV(VkDevice device, const VkCudaModuleCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCudaModuleNV* pModule)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateCudaModuleNV", "device, pCreateInfo, pAllocator, pModule", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateCudaModuleNV(device, pCreateInfo, pAllocator, pModule);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateCudaModuleNV(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pModule);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateCudaModuleNV(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pModule);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateCudaModuleNV(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pModule);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetCudaModuleCacheNV(VkDevice device, VkCudaModuleNV module, size_t* pCacheSize, void* pCacheData)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetCudaModuleCacheNV", "device, module, pCacheSize, pCacheData", "VkResult");
    VkResult result = device_dispatch_table(device)->GetCudaModuleCacheNV(device, module, pCacheSize, pCacheData);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetCudaModuleCacheNV(ApiDumpInstance::current(), result, device, module, pCacheSize, pCacheData);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetCudaModuleCacheNV(ApiDumpInstance::current(), result, device, module, pCacheSize, pCacheData);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetCudaModuleCacheNV(ApiDumpInstance::current(), result, device, module, pCacheSize, pCacheData);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateCudaFunctionNV(VkDevice device, const VkCudaFunctionCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCudaFunctionNV* pFunction)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateCudaFunctionNV", "device, pCreateInfo, pAllocator, pFunction", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateCudaFunctionNV(device, pCreateInfo, pAllocator, pFunction);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateCudaFunctionNV(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pFunction);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateCudaFunctionNV(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pFunction);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateCudaFunctionNV(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pFunction);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyCudaModuleNV(VkDevice device, VkCudaModuleNV module, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyCudaModuleNV", "device, module, pAllocator", "void");
    device_dispatch_table(device)->DestroyCudaModuleNV(device, module, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyCudaModuleNV(ApiDumpInstance::current(), device, module, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyCudaModuleNV(ApiDumpInstance::current(), device, module, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyCudaModuleNV(ApiDumpInstance::current(), device, module, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkDestroyCudaFunctionNV(VkDevice device, VkCudaFunctionNV function, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyCudaFunctionNV", "device, function, pAllocator", "void");
    device_dispatch_table(device)->DestroyCudaFunctionNV(device, function, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyCudaFunctionNV(ApiDumpInstance::current(), device, function, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyCudaFunctionNV(ApiDumpInstance::current(), device, function, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyCudaFunctionNV(ApiDumpInstance::current(), device, function, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdCudaLaunchKernelNV(VkCommandBuffer commandBuffer, const VkCudaLaunchInfoNV* pLaunchInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdCudaLaunchKernelNV", "commandBuffer, pLaunchInfo", "void");
    device_dispatch_table(commandBuffer)->CmdCudaLaunchKernelNV(commandBuffer, pLaunchInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdCudaLaunchKernelNV(ApiDumpInstance::current(), commandBuffer, pLaunchInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdCudaLaunchKernelNV(ApiDumpInstance::current(), commandBuffer, pLaunchInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdCudaLaunchKernelNV(ApiDumpInstance::current(), commandBuffer, pLaunchInfo);
                break;
        }
    }
}
#if defined(VK_USE_PLATFORM_METAL_EXT)
VKAPI_ATTR void VKAPI_CALL vkExportMetalObjectsEXT(VkDevice device, VkExportMetalObjectsInfoEXT* pMetalObjectsInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkExportMetalObjectsEXT", "device, pMetalObjectsInfo", "void");
    device_dispatch_table(device)->ExportMetalObjectsEXT(device, pMetalObjectsInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkExportMetalObjectsEXT(ApiDumpInstance::current(), device, pMetalObjectsInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkExportMetalObjectsEXT(ApiDumpInstance::current(), device, pMetalObjectsInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkExportMetalObjectsEXT(ApiDumpInstance::current(), device, pMetalObjectsInfo);
                break;
        }
    }
}
#endif // VK_USE_PLATFORM_METAL_EXT
VKAPI_ATTR void VKAPI_CALL vkCmdSetEvent2KHR(VkCommandBuffer                   commandBuffer, VkEvent                                             event, const VkDependencyInfo*                             pDependencyInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetEvent2KHR", "commandBuffer, event, pDependencyInfo", "void");
    device_dispatch_table(commandBuffer)->CmdSetEvent2KHR(commandBuffer, event, pDependencyInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetEvent2KHR(ApiDumpInstance::current(), commandBuffer, event, pDependencyInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetEvent2KHR(ApiDumpInstance::current(), commandBuffer, event, pDependencyInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetEvent2KHR(ApiDumpInstance::current(), commandBuffer, event, pDependencyInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdResetEvent2KHR(VkCommandBuffer                   commandBuffer, VkEvent                                             event, VkPipelineStageFlags2               stageMask)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdResetEvent2KHR", "commandBuffer, event, stageMask", "void");
    device_dispatch_table(commandBuffer)->CmdResetEvent2KHR(commandBuffer, event, stageMask);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdResetEvent2KHR(ApiDumpInstance::current(), commandBuffer, event, stageMask);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdResetEvent2KHR(ApiDumpInstance::current(), commandBuffer, event, stageMask);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdResetEvent2KHR(ApiDumpInstance::current(), commandBuffer, event, stageMask);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdWaitEvents2KHR(VkCommandBuffer                   commandBuffer, uint32_t                                            eventCount, const VkEvent*                     pEvents, const VkDependencyInfo*            pDependencyInfos)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdWaitEvents2KHR", "commandBuffer, eventCount, pEvents, pDependencyInfos", "void");
    device_dispatch_table(commandBuffer)->CmdWaitEvents2KHR(commandBuffer, eventCount, pEvents, pDependencyInfos);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdWaitEvents2KHR(ApiDumpInstance::current(), commandBuffer, eventCount, pEvents, pDependencyInfos);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdWaitEvents2KHR(ApiDumpInstance::current(), commandBuffer, eventCount, pEvents, pDependencyInfos);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdWaitEvents2KHR(ApiDumpInstance::current(), commandBuffer, eventCount, pEvents, pDependencyInfos);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdPipelineBarrier2KHR(VkCommandBuffer                   commandBuffer, const VkDependencyInfo*                             pDependencyInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdPipelineBarrier2KHR", "commandBuffer, pDependencyInfo", "void");
    device_dispatch_table(commandBuffer)->CmdPipelineBarrier2KHR(commandBuffer, pDependencyInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdPipelineBarrier2KHR(ApiDumpInstance::current(), commandBuffer, pDependencyInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdPipelineBarrier2KHR(ApiDumpInstance::current(), commandBuffer, pDependencyInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdPipelineBarrier2KHR(ApiDumpInstance::current(), commandBuffer, pDependencyInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdWriteTimestamp2KHR(VkCommandBuffer                   commandBuffer, VkPipelineStageFlags2               stage, VkQueryPool                                         queryPool, uint32_t                                            query)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdWriteTimestamp2KHR", "commandBuffer, stage, queryPool, query", "void");
    device_dispatch_table(commandBuffer)->CmdWriteTimestamp2KHR(commandBuffer, stage, queryPool, query);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdWriteTimestamp2KHR(ApiDumpInstance::current(), commandBuffer, stage, queryPool, query);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdWriteTimestamp2KHR(ApiDumpInstance::current(), commandBuffer, stage, queryPool, query);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdWriteTimestamp2KHR(ApiDumpInstance::current(), commandBuffer, stage, queryPool, query);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkQueueSubmit2KHR(VkQueue                           queue, uint32_t                            submitCount, const VkSubmitInfo2*              pSubmits, VkFence           fence)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkQueueSubmit2KHR", "queue, submitCount, pSubmits, fence", "VkResult");
    VkResult result = device_dispatch_table(queue)->QueueSubmit2KHR(queue, submitCount, pSubmits, fence);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkQueueSubmit2KHR(ApiDumpInstance::current(), result, queue, submitCount, pSubmits, fence);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkQueueSubmit2KHR(ApiDumpInstance::current(), result, queue, submitCount, pSubmits, fence);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkQueueSubmit2KHR(ApiDumpInstance::current(), result, queue, submitCount, pSubmits, fence);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdWriteBufferMarker2AMD(VkCommandBuffer                   commandBuffer, VkPipelineStageFlags2               stage, VkBuffer                                            dstBuffer, VkDeviceSize                                        dstOffset, uint32_t                                            marker)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdWriteBufferMarker2AMD", "commandBuffer, stage, dstBuffer, dstOffset, marker", "void");
    device_dispatch_table(commandBuffer)->CmdWriteBufferMarker2AMD(commandBuffer, stage, dstBuffer, dstOffset, marker);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdWriteBufferMarker2AMD(ApiDumpInstance::current(), commandBuffer, stage, dstBuffer, dstOffset, marker);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdWriteBufferMarker2AMD(ApiDumpInstance::current(), commandBuffer, stage, dstBuffer, dstOffset, marker);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdWriteBufferMarker2AMD(ApiDumpInstance::current(), commandBuffer, stage, dstBuffer, dstOffset, marker);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetQueueCheckpointData2NV(VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointData2NV* pCheckpointData)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetQueueCheckpointData2NV", "queue, pCheckpointDataCount, pCheckpointData", "void");
    device_dispatch_table(queue)->GetQueueCheckpointData2NV(queue, pCheckpointDataCount, pCheckpointData);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetQueueCheckpointData2NV(ApiDumpInstance::current(), queue, pCheckpointDataCount, pCheckpointData);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetQueueCheckpointData2NV(ApiDumpInstance::current(), queue, pCheckpointDataCount, pCheckpointData);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetQueueCheckpointData2NV(ApiDumpInstance::current(), queue, pCheckpointDataCount, pCheckpointData);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetDescriptorSetLayoutSizeEXT(VkDevice device, VkDescriptorSetLayout layout, VkDeviceSize* pLayoutSizeInBytes)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDescriptorSetLayoutSizeEXT", "device, layout, pLayoutSizeInBytes", "void");
    device_dispatch_table(device)->GetDescriptorSetLayoutSizeEXT(device, layout, pLayoutSizeInBytes);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDescriptorSetLayoutSizeEXT(ApiDumpInstance::current(), device, layout, pLayoutSizeInBytes);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDescriptorSetLayoutSizeEXT(ApiDumpInstance::current(), device, layout, pLayoutSizeInBytes);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDescriptorSetLayoutSizeEXT(ApiDumpInstance::current(), device, layout, pLayoutSizeInBytes);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetDescriptorSetLayoutBindingOffsetEXT(VkDevice device, VkDescriptorSetLayout layout, uint32_t binding, VkDeviceSize* pOffset)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDescriptorSetLayoutBindingOffsetEXT", "device, layout, binding, pOffset", "void");
    device_dispatch_table(device)->GetDescriptorSetLayoutBindingOffsetEXT(device, layout, binding, pOffset);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDescriptorSetLayoutBindingOffsetEXT(ApiDumpInstance::current(), device, layout, binding, pOffset);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDescriptorSetLayoutBindingOffsetEXT(ApiDumpInstance::current(), device, layout, binding, pOffset);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDescriptorSetLayoutBindingOffsetEXT(ApiDumpInstance::current(), device, layout, binding, pOffset);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetDescriptorEXT(VkDevice device, const VkDescriptorGetInfoEXT* pDescriptorInfo, size_t dataSize, void* pDescriptor)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDescriptorEXT", "device, pDescriptorInfo, dataSize, pDescriptor", "void");
    device_dispatch_table(device)->GetDescriptorEXT(device, pDescriptorInfo, dataSize, pDescriptor);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDescriptorEXT(ApiDumpInstance::current(), device, pDescriptorInfo, dataSize, pDescriptor);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDescriptorEXT(ApiDumpInstance::current(), device, pDescriptorInfo, dataSize, pDescriptor);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDescriptorEXT(ApiDumpInstance::current(), device, pDescriptorInfo, dataSize, pDescriptor);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindDescriptorBuffersEXT(VkCommandBuffer commandBuffer, uint32_t bufferCount, const VkDescriptorBufferBindingInfoEXT* pBindingInfos)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdBindDescriptorBuffersEXT", "commandBuffer, bufferCount, pBindingInfos", "void");
    device_dispatch_table(commandBuffer)->CmdBindDescriptorBuffersEXT(commandBuffer, bufferCount, pBindingInfos);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdBindDescriptorBuffersEXT(ApiDumpInstance::current(), commandBuffer, bufferCount, pBindingInfos);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdBindDescriptorBuffersEXT(ApiDumpInstance::current(), commandBuffer, bufferCount, pBindingInfos);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdBindDescriptorBuffersEXT(ApiDumpInstance::current(), commandBuffer, bufferCount, pBindingInfos);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDescriptorBufferOffsetsEXT(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t setCount, const uint32_t* pBufferIndices, const VkDeviceSize* pOffsets)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetDescriptorBufferOffsetsEXT", "commandBuffer, pipelineBindPoint, layout, firstSet, setCount, pBufferIndices, pOffsets", "void");
    device_dispatch_table(commandBuffer)->CmdSetDescriptorBufferOffsetsEXT(commandBuffer, pipelineBindPoint, layout, firstSet, setCount, pBufferIndices, pOffsets);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetDescriptorBufferOffsetsEXT(ApiDumpInstance::current(), commandBuffer, pipelineBindPoint, layout, firstSet, setCount, pBufferIndices, pOffsets);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetDescriptorBufferOffsetsEXT(ApiDumpInstance::current(), commandBuffer, pipelineBindPoint, layout, firstSet, setCount, pBufferIndices, pOffsets);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetDescriptorBufferOffsetsEXT(ApiDumpInstance::current(), commandBuffer, pipelineBindPoint, layout, firstSet, setCount, pBufferIndices, pOffsets);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindDescriptorBufferEmbeddedSamplersEXT(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdBindDescriptorBufferEmbeddedSamplersEXT", "commandBuffer, pipelineBindPoint, layout, set", "void");
    device_dispatch_table(commandBuffer)->CmdBindDescriptorBufferEmbeddedSamplersEXT(commandBuffer, pipelineBindPoint, layout, set);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdBindDescriptorBufferEmbeddedSamplersEXT(ApiDumpInstance::current(), commandBuffer, pipelineBindPoint, layout, set);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdBindDescriptorBufferEmbeddedSamplersEXT(ApiDumpInstance::current(), commandBuffer, pipelineBindPoint, layout, set);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdBindDescriptorBufferEmbeddedSamplersEXT(ApiDumpInstance::current(), commandBuffer, pipelineBindPoint, layout, set);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetBufferOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkBufferCaptureDescriptorDataInfoEXT* pInfo, void* pData)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetBufferOpaqueCaptureDescriptorDataEXT", "device, pInfo, pData", "VkResult");
    VkResult result = device_dispatch_table(device)->GetBufferOpaqueCaptureDescriptorDataEXT(device, pInfo, pData);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetBufferOpaqueCaptureDescriptorDataEXT(ApiDumpInstance::current(), result, device, pInfo, pData);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetBufferOpaqueCaptureDescriptorDataEXT(ApiDumpInstance::current(), result, device, pInfo, pData);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetBufferOpaqueCaptureDescriptorDataEXT(ApiDumpInstance::current(), result, device, pInfo, pData);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetImageOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkImageCaptureDescriptorDataInfoEXT* pInfo, void* pData)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetImageOpaqueCaptureDescriptorDataEXT", "device, pInfo, pData", "VkResult");
    VkResult result = device_dispatch_table(device)->GetImageOpaqueCaptureDescriptorDataEXT(device, pInfo, pData);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetImageOpaqueCaptureDescriptorDataEXT(ApiDumpInstance::current(), result, device, pInfo, pData);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetImageOpaqueCaptureDescriptorDataEXT(ApiDumpInstance::current(), result, device, pInfo, pData);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetImageOpaqueCaptureDescriptorDataEXT(ApiDumpInstance::current(), result, device, pInfo, pData);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetImageViewOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkImageViewCaptureDescriptorDataInfoEXT* pInfo, void* pData)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetImageViewOpaqueCaptureDescriptorDataEXT", "device, pInfo, pData", "VkResult");
    VkResult result = device_dispatch_table(device)->GetImageViewOpaqueCaptureDescriptorDataEXT(device, pInfo, pData);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetImageViewOpaqueCaptureDescriptorDataEXT(ApiDumpInstance::current(), result, device, pInfo, pData);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetImageViewOpaqueCaptureDescriptorDataEXT(ApiDumpInstance::current(), result, device, pInfo, pData);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetImageViewOpaqueCaptureDescriptorDataEXT(ApiDumpInstance::current(), result, device, pInfo, pData);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetSamplerOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkSamplerCaptureDescriptorDataInfoEXT* pInfo, void* pData)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetSamplerOpaqueCaptureDescriptorDataEXT", "device, pInfo, pData", "VkResult");
    VkResult result = device_dispatch_table(device)->GetSamplerOpaqueCaptureDescriptorDataEXT(device, pInfo, pData);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetSamplerOpaqueCaptureDescriptorDataEXT(ApiDumpInstance::current(), result, device, pInfo, pData);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetSamplerOpaqueCaptureDescriptorDataEXT(ApiDumpInstance::current(), result, device, pInfo, pData);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetSamplerOpaqueCaptureDescriptorDataEXT(ApiDumpInstance::current(), result, device, pInfo, pData);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkAccelerationStructureCaptureDescriptorDataInfoEXT* pInfo, void* pData)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT", "device, pInfo, pData", "VkResult");
    VkResult result = device_dispatch_table(device)->GetAccelerationStructureOpaqueCaptureDescriptorDataEXT(device, pInfo, pData);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT(ApiDumpInstance::current(), result, device, pInfo, pData);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT(ApiDumpInstance::current(), result, device, pInfo, pData);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT(ApiDumpInstance::current(), result, device, pInfo, pData);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetFragmentShadingRateEnumNV(VkCommandBuffer           commandBuffer, VkFragmentShadingRateNV                     shadingRate, const VkFragmentShadingRateCombinerOpKHR    combinerOps[2])
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetFragmentShadingRateEnumNV", "commandBuffer, shadingRate, combinerOps", "void");
    device_dispatch_table(commandBuffer)->CmdSetFragmentShadingRateEnumNV(commandBuffer, shadingRate, combinerOps);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetFragmentShadingRateEnumNV(ApiDumpInstance::current(), commandBuffer, shadingRate, combinerOps);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetFragmentShadingRateEnumNV(ApiDumpInstance::current(), commandBuffer, shadingRate, combinerOps);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetFragmentShadingRateEnumNV(ApiDumpInstance::current(), commandBuffer, shadingRate, combinerOps);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawMeshTasksEXT(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdDrawMeshTasksEXT", "commandBuffer, groupCountX, groupCountY, groupCountZ", "void");
    device_dispatch_table(commandBuffer)->CmdDrawMeshTasksEXT(commandBuffer, groupCountX, groupCountY, groupCountZ);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdDrawMeshTasksEXT(ApiDumpInstance::current(), commandBuffer, groupCountX, groupCountY, groupCountZ);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdDrawMeshTasksEXT(ApiDumpInstance::current(), commandBuffer, groupCountX, groupCountY, groupCountZ);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdDrawMeshTasksEXT(ApiDumpInstance::current(), commandBuffer, groupCountX, groupCountY, groupCountZ);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawMeshTasksIndirectEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdDrawMeshTasksIndirectEXT", "commandBuffer, buffer, offset, drawCount, stride", "void");
    device_dispatch_table(commandBuffer)->CmdDrawMeshTasksIndirectEXT(commandBuffer, buffer, offset, drawCount, stride);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdDrawMeshTasksIndirectEXT(ApiDumpInstance::current(), commandBuffer, buffer, offset, drawCount, stride);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdDrawMeshTasksIndirectEXT(ApiDumpInstance::current(), commandBuffer, buffer, offset, drawCount, stride);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdDrawMeshTasksIndirectEXT(ApiDumpInstance::current(), commandBuffer, buffer, offset, drawCount, stride);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawMeshTasksIndirectCountEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdDrawMeshTasksIndirectCountEXT", "commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride", "void");
    device_dispatch_table(commandBuffer)->CmdDrawMeshTasksIndirectCountEXT(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdDrawMeshTasksIndirectCountEXT(ApiDumpInstance::current(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdDrawMeshTasksIndirectCountEXT(ApiDumpInstance::current(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdDrawMeshTasksIndirectCountEXT(ApiDumpInstance::current(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdCopyBuffer2KHR", "commandBuffer, pCopyBufferInfo", "void");
    device_dispatch_table(commandBuffer)->CmdCopyBuffer2KHR(commandBuffer, pCopyBufferInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdCopyBuffer2KHR(ApiDumpInstance::current(), commandBuffer, pCopyBufferInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdCopyBuffer2KHR(ApiDumpInstance::current(), commandBuffer, pCopyBufferInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdCopyBuffer2KHR(ApiDumpInstance::current(), commandBuffer, pCopyBufferInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdCopyImage2KHR", "commandBuffer, pCopyImageInfo", "void");
    device_dispatch_table(commandBuffer)->CmdCopyImage2KHR(commandBuffer, pCopyImageInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdCopyImage2KHR(ApiDumpInstance::current(), commandBuffer, pCopyImageInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdCopyImage2KHR(ApiDumpInstance::current(), commandBuffer, pCopyImageInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdCopyImage2KHR(ApiDumpInstance::current(), commandBuffer, pCopyImageInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyBufferToImage2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdCopyBufferToImage2KHR", "commandBuffer, pCopyBufferToImageInfo", "void");
    device_dispatch_table(commandBuffer)->CmdCopyBufferToImage2KHR(commandBuffer, pCopyBufferToImageInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdCopyBufferToImage2KHR(ApiDumpInstance::current(), commandBuffer, pCopyBufferToImageInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdCopyBufferToImage2KHR(ApiDumpInstance::current(), commandBuffer, pCopyBufferToImageInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdCopyBufferToImage2KHR(ApiDumpInstance::current(), commandBuffer, pCopyBufferToImageInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyImageToBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdCopyImageToBuffer2KHR", "commandBuffer, pCopyImageToBufferInfo", "void");
    device_dispatch_table(commandBuffer)->CmdCopyImageToBuffer2KHR(commandBuffer, pCopyImageToBufferInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdCopyImageToBuffer2KHR(ApiDumpInstance::current(), commandBuffer, pCopyImageToBufferInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdCopyImageToBuffer2KHR(ApiDumpInstance::current(), commandBuffer, pCopyImageToBufferInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdCopyImageToBuffer2KHR(ApiDumpInstance::current(), commandBuffer, pCopyImageToBufferInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdBlitImage2KHR", "commandBuffer, pBlitImageInfo", "void");
    device_dispatch_table(commandBuffer)->CmdBlitImage2KHR(commandBuffer, pBlitImageInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdBlitImage2KHR(ApiDumpInstance::current(), commandBuffer, pBlitImageInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdBlitImage2KHR(ApiDumpInstance::current(), commandBuffer, pBlitImageInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdBlitImage2KHR(ApiDumpInstance::current(), commandBuffer, pBlitImageInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdResolveImage2KHR(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdResolveImage2KHR", "commandBuffer, pResolveImageInfo", "void");
    device_dispatch_table(commandBuffer)->CmdResolveImage2KHR(commandBuffer, pResolveImageInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdResolveImage2KHR(ApiDumpInstance::current(), commandBuffer, pResolveImageInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdResolveImage2KHR(ApiDumpInstance::current(), commandBuffer, pResolveImageInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdResolveImage2KHR(ApiDumpInstance::current(), commandBuffer, pResolveImageInfo);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetDeviceFaultInfoEXT(VkDevice device, VkDeviceFaultCountsEXT* pFaultCounts, VkDeviceFaultInfoEXT* pFaultInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDeviceFaultInfoEXT", "device, pFaultCounts, pFaultInfo", "VkResult");
    VkResult result = device_dispatch_table(device)->GetDeviceFaultInfoEXT(device, pFaultCounts, pFaultInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDeviceFaultInfoEXT(ApiDumpInstance::current(), result, device, pFaultCounts, pFaultInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDeviceFaultInfoEXT(ApiDumpInstance::current(), result, device, pFaultCounts, pFaultInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDeviceFaultInfoEXT(ApiDumpInstance::current(), result, device, pFaultCounts, pFaultInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdTraceRaysKHR(VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width, uint32_t height, uint32_t depth)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdTraceRaysKHR", "commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth", "void");
    device_dispatch_table(commandBuffer)->CmdTraceRaysKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdTraceRaysKHR(ApiDumpInstance::current(), commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdTraceRaysKHR(ApiDumpInstance::current(), commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdTraceRaysKHR(ApiDumpInstance::current(), commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateRayTracingPipelinesKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateRayTracingPipelinesKHR", "device, deferredOperation, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateRayTracingPipelinesKHR(device, deferredOperation, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateRayTracingPipelinesKHR(ApiDumpInstance::current(), result, device, deferredOperation, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateRayTracingPipelinesKHR(ApiDumpInstance::current(), result, device, deferredOperation, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateRayTracingPipelinesKHR(ApiDumpInstance::current(), result, device, deferredOperation, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR", "device, pipeline, firstGroup, groupCount, dataSize, pData", "VkResult");
    VkResult result = device_dispatch_table(device)->GetRayTracingCaptureReplayShaderGroupHandlesKHR(device, pipeline, firstGroup, groupCount, dataSize, pData);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(ApiDumpInstance::current(), result, device, pipeline, firstGroup, groupCount, dataSize, pData);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(ApiDumpInstance::current(), result, device, pipeline, firstGroup, groupCount, dataSize, pData);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(ApiDumpInstance::current(), result, device, pipeline, firstGroup, groupCount, dataSize, pData);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdTraceRaysIndirectKHR(VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, VkDeviceAddress indirectDeviceAddress)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdTraceRaysIndirectKHR", "commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress", "void");
    device_dispatch_table(commandBuffer)->CmdTraceRaysIndirectKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdTraceRaysIndirectKHR(ApiDumpInstance::current(), commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdTraceRaysIndirectKHR(ApiDumpInstance::current(), commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdTraceRaysIndirectKHR(ApiDumpInstance::current(), commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);
                break;
        }
    }
}
VKAPI_ATTR VkDeviceSize VKAPI_CALL vkGetRayTracingShaderGroupStackSizeKHR(VkDevice device, VkPipeline pipeline, uint32_t group, VkShaderGroupShaderKHR groupShader)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetRayTracingShaderGroupStackSizeKHR", "device, pipeline, group, groupShader", "VkDeviceSize");
    VkDeviceSize result = device_dispatch_table(device)->GetRayTracingShaderGroupStackSizeKHR(device, pipeline, group, groupShader);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetRayTracingShaderGroupStackSizeKHR(ApiDumpInstance::current(), result, device, pipeline, group, groupShader);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetRayTracingShaderGroupStackSizeKHR(ApiDumpInstance::current(), result, device, pipeline, group, groupShader);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetRayTracingShaderGroupStackSizeKHR(ApiDumpInstance::current(), result, device, pipeline, group, groupShader);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetRayTracingPipelineStackSizeKHR(VkCommandBuffer commandBuffer, uint32_t pipelineStackSize)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetRayTracingPipelineStackSizeKHR", "commandBuffer, pipelineStackSize", "void");
    device_dispatch_table(commandBuffer)->CmdSetRayTracingPipelineStackSizeKHR(commandBuffer, pipelineStackSize);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetRayTracingPipelineStackSizeKHR(ApiDumpInstance::current(), commandBuffer, pipelineStackSize);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetRayTracingPipelineStackSizeKHR(ApiDumpInstance::current(), commandBuffer, pipelineStackSize);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetRayTracingPipelineStackSizeKHR(ApiDumpInstance::current(), commandBuffer, pipelineStackSize);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetVertexInputEXT(VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount, const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount, const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetVertexInputEXT", "commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions", "void");
    device_dispatch_table(commandBuffer)->CmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetVertexInputEXT(ApiDumpInstance::current(), commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetVertexInputEXT(ApiDumpInstance::current(), commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetVertexInputEXT(ApiDumpInstance::current(), commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
                break;
        }
    }
}
#if defined(VK_USE_PLATFORM_FUCHSIA)
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryZirconHandleFUCHSIA(VkDevice device, const VkMemoryGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetMemoryZirconHandleFUCHSIA", "device, pGetZirconHandleInfo, pZirconHandle", "VkResult");
    VkResult result = device_dispatch_table(device)->GetMemoryZirconHandleFUCHSIA(device, pGetZirconHandleInfo, pZirconHandle);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetMemoryZirconHandleFUCHSIA(ApiDumpInstance::current(), result, device, pGetZirconHandleInfo, pZirconHandle);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetMemoryZirconHandleFUCHSIA(ApiDumpInstance::current(), result, device, pGetZirconHandleInfo, pZirconHandle);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetMemoryZirconHandleFUCHSIA(ApiDumpInstance::current(), result, device, pGetZirconHandleInfo, pZirconHandle);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_FUCHSIA
#if defined(VK_USE_PLATFORM_FUCHSIA)
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryZirconHandlePropertiesFUCHSIA(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, zx_handle_t zirconHandle, VkMemoryZirconHandlePropertiesFUCHSIA* pMemoryZirconHandleProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetMemoryZirconHandlePropertiesFUCHSIA", "device, handleType, zirconHandle, pMemoryZirconHandleProperties", "VkResult");
    VkResult result = device_dispatch_table(device)->GetMemoryZirconHandlePropertiesFUCHSIA(device, handleType, zirconHandle, pMemoryZirconHandleProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetMemoryZirconHandlePropertiesFUCHSIA(ApiDumpInstance::current(), result, device, handleType, zirconHandle, pMemoryZirconHandleProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetMemoryZirconHandlePropertiesFUCHSIA(ApiDumpInstance::current(), result, device, handleType, zirconHandle, pMemoryZirconHandleProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetMemoryZirconHandlePropertiesFUCHSIA(ApiDumpInstance::current(), result, device, handleType, zirconHandle, pMemoryZirconHandleProperties);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_FUCHSIA
#if defined(VK_USE_PLATFORM_FUCHSIA)
VKAPI_ATTR VkResult VKAPI_CALL vkImportSemaphoreZirconHandleFUCHSIA(VkDevice device, const VkImportSemaphoreZirconHandleInfoFUCHSIA* pImportSemaphoreZirconHandleInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkImportSemaphoreZirconHandleFUCHSIA", "device, pImportSemaphoreZirconHandleInfo", "VkResult");
    VkResult result = device_dispatch_table(device)->ImportSemaphoreZirconHandleFUCHSIA(device, pImportSemaphoreZirconHandleInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkImportSemaphoreZirconHandleFUCHSIA(ApiDumpInstance::current(), result, device, pImportSemaphoreZirconHandleInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkImportSemaphoreZirconHandleFUCHSIA(ApiDumpInstance::current(), result, device, pImportSemaphoreZirconHandleInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkImportSemaphoreZirconHandleFUCHSIA(ApiDumpInstance::current(), result, device, pImportSemaphoreZirconHandleInfo);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_FUCHSIA
#if defined(VK_USE_PLATFORM_FUCHSIA)
VKAPI_ATTR VkResult VKAPI_CALL vkGetSemaphoreZirconHandleFUCHSIA(VkDevice device, const VkSemaphoreGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetSemaphoreZirconHandleFUCHSIA", "device, pGetZirconHandleInfo, pZirconHandle", "VkResult");
    VkResult result = device_dispatch_table(device)->GetSemaphoreZirconHandleFUCHSIA(device, pGetZirconHandleInfo, pZirconHandle);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetSemaphoreZirconHandleFUCHSIA(ApiDumpInstance::current(), result, device, pGetZirconHandleInfo, pZirconHandle);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetSemaphoreZirconHandleFUCHSIA(ApiDumpInstance::current(), result, device, pGetZirconHandleInfo, pZirconHandle);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetSemaphoreZirconHandleFUCHSIA(ApiDumpInstance::current(), result, device, pGetZirconHandleInfo, pZirconHandle);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_FUCHSIA
#if defined(VK_USE_PLATFORM_FUCHSIA)
VKAPI_ATTR VkResult VKAPI_CALL vkCreateBufferCollectionFUCHSIA(VkDevice device, const VkBufferCollectionCreateInfoFUCHSIA* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferCollectionFUCHSIA* pCollection)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateBufferCollectionFUCHSIA", "device, pCreateInfo, pAllocator, pCollection", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateBufferCollectionFUCHSIA(device, pCreateInfo, pAllocator, pCollection);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateBufferCollectionFUCHSIA(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pCollection);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateBufferCollectionFUCHSIA(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pCollection);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateBufferCollectionFUCHSIA(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pCollection);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_FUCHSIA
#if defined(VK_USE_PLATFORM_FUCHSIA)
VKAPI_ATTR VkResult VKAPI_CALL vkSetBufferCollectionImageConstraintsFUCHSIA(VkDevice device, VkBufferCollectionFUCHSIA collection, const VkImageConstraintsInfoFUCHSIA* pImageConstraintsInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkSetBufferCollectionImageConstraintsFUCHSIA", "device, collection, pImageConstraintsInfo", "VkResult");
    VkResult result = device_dispatch_table(device)->SetBufferCollectionImageConstraintsFUCHSIA(device, collection, pImageConstraintsInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkSetBufferCollectionImageConstraintsFUCHSIA(ApiDumpInstance::current(), result, device, collection, pImageConstraintsInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkSetBufferCollectionImageConstraintsFUCHSIA(ApiDumpInstance::current(), result, device, collection, pImageConstraintsInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkSetBufferCollectionImageConstraintsFUCHSIA(ApiDumpInstance::current(), result, device, collection, pImageConstraintsInfo);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_FUCHSIA
#if defined(VK_USE_PLATFORM_FUCHSIA)
VKAPI_ATTR VkResult VKAPI_CALL vkSetBufferCollectionBufferConstraintsFUCHSIA(VkDevice device, VkBufferCollectionFUCHSIA collection, const VkBufferConstraintsInfoFUCHSIA* pBufferConstraintsInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkSetBufferCollectionBufferConstraintsFUCHSIA", "device, collection, pBufferConstraintsInfo", "VkResult");
    VkResult result = device_dispatch_table(device)->SetBufferCollectionBufferConstraintsFUCHSIA(device, collection, pBufferConstraintsInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkSetBufferCollectionBufferConstraintsFUCHSIA(ApiDumpInstance::current(), result, device, collection, pBufferConstraintsInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkSetBufferCollectionBufferConstraintsFUCHSIA(ApiDumpInstance::current(), result, device, collection, pBufferConstraintsInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkSetBufferCollectionBufferConstraintsFUCHSIA(ApiDumpInstance::current(), result, device, collection, pBufferConstraintsInfo);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_FUCHSIA
#if defined(VK_USE_PLATFORM_FUCHSIA)
VKAPI_ATTR void VKAPI_CALL vkDestroyBufferCollectionFUCHSIA(VkDevice device, VkBufferCollectionFUCHSIA collection, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyBufferCollectionFUCHSIA", "device, collection, pAllocator", "void");
    device_dispatch_table(device)->DestroyBufferCollectionFUCHSIA(device, collection, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyBufferCollectionFUCHSIA(ApiDumpInstance::current(), device, collection, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyBufferCollectionFUCHSIA(ApiDumpInstance::current(), device, collection, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyBufferCollectionFUCHSIA(ApiDumpInstance::current(), device, collection, pAllocator);
                break;
        }
    }
}
#endif // VK_USE_PLATFORM_FUCHSIA
#if defined(VK_USE_PLATFORM_FUCHSIA)
VKAPI_ATTR VkResult VKAPI_CALL vkGetBufferCollectionPropertiesFUCHSIA(VkDevice device, VkBufferCollectionFUCHSIA collection, VkBufferCollectionPropertiesFUCHSIA* pProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetBufferCollectionPropertiesFUCHSIA", "device, collection, pProperties", "VkResult");
    VkResult result = device_dispatch_table(device)->GetBufferCollectionPropertiesFUCHSIA(device, collection, pProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetBufferCollectionPropertiesFUCHSIA(ApiDumpInstance::current(), result, device, collection, pProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetBufferCollectionPropertiesFUCHSIA(ApiDumpInstance::current(), result, device, collection, pProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetBufferCollectionPropertiesFUCHSIA(ApiDumpInstance::current(), result, device, collection, pProperties);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_FUCHSIA
VKAPI_ATTR VkResult VKAPI_CALL vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI(VkDevice device, VkRenderPass renderpass, VkExtent2D* pMaxWorkgroupSize)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI", "device, renderpass, pMaxWorkgroupSize", "VkResult");
    VkResult result = device_dispatch_table(device)->GetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI(device, renderpass, pMaxWorkgroupSize);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI(ApiDumpInstance::current(), result, device, renderpass, pMaxWorkgroupSize);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI(ApiDumpInstance::current(), result, device, renderpass, pMaxWorkgroupSize);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI(ApiDumpInstance::current(), result, device, renderpass, pMaxWorkgroupSize);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdSubpassShadingHUAWEI(VkCommandBuffer commandBuffer)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSubpassShadingHUAWEI", "commandBuffer", "void");
    device_dispatch_table(commandBuffer)->CmdSubpassShadingHUAWEI(commandBuffer);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSubpassShadingHUAWEI(ApiDumpInstance::current(), commandBuffer);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSubpassShadingHUAWEI(ApiDumpInstance::current(), commandBuffer);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSubpassShadingHUAWEI(ApiDumpInstance::current(), commandBuffer);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindInvocationMaskHUAWEI(VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdBindInvocationMaskHUAWEI", "commandBuffer, imageView, imageLayout", "void");
    device_dispatch_table(commandBuffer)->CmdBindInvocationMaskHUAWEI(commandBuffer, imageView, imageLayout);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdBindInvocationMaskHUAWEI(ApiDumpInstance::current(), commandBuffer, imageView, imageLayout);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdBindInvocationMaskHUAWEI(ApiDumpInstance::current(), commandBuffer, imageView, imageLayout);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdBindInvocationMaskHUAWEI(ApiDumpInstance::current(), commandBuffer, imageView, imageLayout);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryRemoteAddressNV(VkDevice device, const VkMemoryGetRemoteAddressInfoNV* pMemoryGetRemoteAddressInfo, VkRemoteAddressNV* pAddress)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetMemoryRemoteAddressNV", "device, pMemoryGetRemoteAddressInfo, pAddress", "VkResult");
    VkResult result = device_dispatch_table(device)->GetMemoryRemoteAddressNV(device, pMemoryGetRemoteAddressInfo, pAddress);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetMemoryRemoteAddressNV(ApiDumpInstance::current(), result, device, pMemoryGetRemoteAddressInfo, pAddress);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetMemoryRemoteAddressNV(ApiDumpInstance::current(), result, device, pMemoryGetRemoteAddressInfo, pAddress);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetMemoryRemoteAddressNV(ApiDumpInstance::current(), result, device, pMemoryGetRemoteAddressInfo, pAddress);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPipelinePropertiesEXT(VkDevice device, const VkPipelineInfoEXT* pPipelineInfo, VkBaseOutStructure* pPipelineProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPipelinePropertiesEXT", "device, pPipelineInfo, pPipelineProperties", "VkResult");
    VkResult result = device_dispatch_table(device)->GetPipelinePropertiesEXT(device, pPipelineInfo, pPipelineProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPipelinePropertiesEXT(ApiDumpInstance::current(), result, device, pPipelineInfo, pPipelineProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPipelinePropertiesEXT(ApiDumpInstance::current(), result, device, pPipelineInfo, pPipelineProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPipelinePropertiesEXT(ApiDumpInstance::current(), result, device, pPipelineInfo, pPipelineProperties);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer, uint32_t patchControlPoints)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetPatchControlPointsEXT", "commandBuffer, patchControlPoints", "void");
    device_dispatch_table(commandBuffer)->CmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetPatchControlPointsEXT(ApiDumpInstance::current(), commandBuffer, patchControlPoints);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetPatchControlPointsEXT(ApiDumpInstance::current(), commandBuffer, patchControlPoints);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetPatchControlPointsEXT(ApiDumpInstance::current(), commandBuffer, patchControlPoints);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetRasterizerDiscardEnableEXT(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetRasterizerDiscardEnableEXT", "commandBuffer, rasterizerDiscardEnable", "void");
    device_dispatch_table(commandBuffer)->CmdSetRasterizerDiscardEnableEXT(commandBuffer, rasterizerDiscardEnable);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetRasterizerDiscardEnableEXT(ApiDumpInstance::current(), commandBuffer, rasterizerDiscardEnable);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetRasterizerDiscardEnableEXT(ApiDumpInstance::current(), commandBuffer, rasterizerDiscardEnable);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetRasterizerDiscardEnableEXT(ApiDumpInstance::current(), commandBuffer, rasterizerDiscardEnable);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthBiasEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetDepthBiasEnableEXT", "commandBuffer, depthBiasEnable", "void");
    device_dispatch_table(commandBuffer)->CmdSetDepthBiasEnableEXT(commandBuffer, depthBiasEnable);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetDepthBiasEnableEXT(ApiDumpInstance::current(), commandBuffer, depthBiasEnable);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetDepthBiasEnableEXT(ApiDumpInstance::current(), commandBuffer, depthBiasEnable);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetDepthBiasEnableEXT(ApiDumpInstance::current(), commandBuffer, depthBiasEnable);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetLogicOpEXT", "commandBuffer, logicOp", "void");
    device_dispatch_table(commandBuffer)->CmdSetLogicOpEXT(commandBuffer, logicOp);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetLogicOpEXT(ApiDumpInstance::current(), commandBuffer, logicOp);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetLogicOpEXT(ApiDumpInstance::current(), commandBuffer, logicOp);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetLogicOpEXT(ApiDumpInstance::current(), commandBuffer, logicOp);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetPrimitiveRestartEnableEXT(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetPrimitiveRestartEnableEXT", "commandBuffer, primitiveRestartEnable", "void");
    device_dispatch_table(commandBuffer)->CmdSetPrimitiveRestartEnableEXT(commandBuffer, primitiveRestartEnable);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetPrimitiveRestartEnableEXT(ApiDumpInstance::current(), commandBuffer, primitiveRestartEnable);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetPrimitiveRestartEnableEXT(ApiDumpInstance::current(), commandBuffer, primitiveRestartEnable);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetPrimitiveRestartEnableEXT(ApiDumpInstance::current(), commandBuffer, primitiveRestartEnable);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetColorWriteEnableEXT(VkCommandBuffer       commandBuffer, uint32_t                                attachmentCount, const VkBool32*   pColorWriteEnables)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetColorWriteEnableEXT", "commandBuffer, attachmentCount, pColorWriteEnables", "void");
    device_dispatch_table(commandBuffer)->CmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetColorWriteEnableEXT(ApiDumpInstance::current(), commandBuffer, attachmentCount, pColorWriteEnables);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetColorWriteEnableEXT(ApiDumpInstance::current(), commandBuffer, attachmentCount, pColorWriteEnables);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetColorWriteEnableEXT(ApiDumpInstance::current(), commandBuffer, attachmentCount, pColorWriteEnables);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdTraceRaysIndirect2KHR(VkCommandBuffer commandBuffer, VkDeviceAddress indirectDeviceAddress)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdTraceRaysIndirect2KHR", "commandBuffer, indirectDeviceAddress", "void");
    device_dispatch_table(commandBuffer)->CmdTraceRaysIndirect2KHR(commandBuffer, indirectDeviceAddress);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdTraceRaysIndirect2KHR(ApiDumpInstance::current(), commandBuffer, indirectDeviceAddress);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdTraceRaysIndirect2KHR(ApiDumpInstance::current(), commandBuffer, indirectDeviceAddress);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdTraceRaysIndirect2KHR(ApiDumpInstance::current(), commandBuffer, indirectDeviceAddress);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawMultiEXT(VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawInfoEXT* pVertexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdDrawMultiEXT", "commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride", "void");
    device_dispatch_table(commandBuffer)->CmdDrawMultiEXT(commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdDrawMultiEXT(ApiDumpInstance::current(), commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdDrawMultiEXT(ApiDumpInstance::current(), commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdDrawMultiEXT(ApiDumpInstance::current(), commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawMultiIndexedEXT(VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawIndexedInfoEXT* pIndexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride, const int32_t* pVertexOffset)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdDrawMultiIndexedEXT", "commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset", "void");
    device_dispatch_table(commandBuffer)->CmdDrawMultiIndexedEXT(commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdDrawMultiIndexedEXT(ApiDumpInstance::current(), commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdDrawMultiIndexedEXT(ApiDumpInstance::current(), commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdDrawMultiIndexedEXT(ApiDumpInstance::current(), commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateMicromapEXT(VkDevice                                           device, const VkMicromapCreateInfoEXT*        pCreateInfo, const VkAllocationCallbacks*       pAllocator, VkMicromapEXT*                        pMicromap)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateMicromapEXT", "device, pCreateInfo, pAllocator, pMicromap", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateMicromapEXT(device, pCreateInfo, pAllocator, pMicromap);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateMicromapEXT(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pMicromap);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateMicromapEXT(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pMicromap);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateMicromapEXT(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pMicromap);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyMicromapEXT(VkDevice device, VkMicromapEXT micromap, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyMicromapEXT", "device, micromap, pAllocator", "void");
    device_dispatch_table(device)->DestroyMicromapEXT(device, micromap, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyMicromapEXT(ApiDumpInstance::current(), device, micromap, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyMicromapEXT(ApiDumpInstance::current(), device, micromap, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyMicromapEXT(ApiDumpInstance::current(), device, micromap, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdBuildMicromapsEXT(VkCommandBuffer                                    commandBuffer, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdBuildMicromapsEXT", "commandBuffer, infoCount, pInfos", "void");
    device_dispatch_table(commandBuffer)->CmdBuildMicromapsEXT(commandBuffer, infoCount, pInfos);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdBuildMicromapsEXT(ApiDumpInstance::current(), commandBuffer, infoCount, pInfos);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdBuildMicromapsEXT(ApiDumpInstance::current(), commandBuffer, infoCount, pInfos);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdBuildMicromapsEXT(ApiDumpInstance::current(), commandBuffer, infoCount, pInfos);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkBuildMicromapsEXT(VkDevice                                           device, VkDeferredOperationKHR deferredOperation, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkBuildMicromapsEXT", "device, deferredOperation, infoCount, pInfos", "VkResult");
    VkResult result = device_dispatch_table(device)->BuildMicromapsEXT(device, deferredOperation, infoCount, pInfos);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkBuildMicromapsEXT(ApiDumpInstance::current(), result, device, deferredOperation, infoCount, pInfos);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkBuildMicromapsEXT(ApiDumpInstance::current(), result, device, deferredOperation, infoCount, pInfos);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkBuildMicromapsEXT(ApiDumpInstance::current(), result, device, deferredOperation, infoCount, pInfos);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCopyMicromapEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMicromapInfoEXT* pInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCopyMicromapEXT", "device, deferredOperation, pInfo", "VkResult");
    VkResult result = device_dispatch_table(device)->CopyMicromapEXT(device, deferredOperation, pInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCopyMicromapEXT(ApiDumpInstance::current(), result, device, deferredOperation, pInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCopyMicromapEXT(ApiDumpInstance::current(), result, device, deferredOperation, pInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCopyMicromapEXT(ApiDumpInstance::current(), result, device, deferredOperation, pInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCopyMicromapToMemoryEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMicromapToMemoryInfoEXT* pInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCopyMicromapToMemoryEXT", "device, deferredOperation, pInfo", "VkResult");
    VkResult result = device_dispatch_table(device)->CopyMicromapToMemoryEXT(device, deferredOperation, pInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCopyMicromapToMemoryEXT(ApiDumpInstance::current(), result, device, deferredOperation, pInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCopyMicromapToMemoryEXT(ApiDumpInstance::current(), result, device, deferredOperation, pInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCopyMicromapToMemoryEXT(ApiDumpInstance::current(), result, device, deferredOperation, pInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCopyMemoryToMicromapEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToMicromapInfoEXT* pInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCopyMemoryToMicromapEXT", "device, deferredOperation, pInfo", "VkResult");
    VkResult result = device_dispatch_table(device)->CopyMemoryToMicromapEXT(device, deferredOperation, pInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCopyMemoryToMicromapEXT(ApiDumpInstance::current(), result, device, deferredOperation, pInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCopyMemoryToMicromapEXT(ApiDumpInstance::current(), result, device, deferredOperation, pInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCopyMemoryToMicromapEXT(ApiDumpInstance::current(), result, device, deferredOperation, pInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkWriteMicromapsPropertiesEXT(VkDevice device, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryType  queryType, size_t       dataSize, void* pData, size_t stride)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkWriteMicromapsPropertiesEXT", "device, micromapCount, pMicromaps, queryType, dataSize, pData, stride", "VkResult");
    VkResult result = device_dispatch_table(device)->WriteMicromapsPropertiesEXT(device, micromapCount, pMicromaps, queryType, dataSize, pData, stride);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkWriteMicromapsPropertiesEXT(ApiDumpInstance::current(), result, device, micromapCount, pMicromaps, queryType, dataSize, pData, stride);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkWriteMicromapsPropertiesEXT(ApiDumpInstance::current(), result, device, micromapCount, pMicromaps, queryType, dataSize, pData, stride);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkWriteMicromapsPropertiesEXT(ApiDumpInstance::current(), result, device, micromapCount, pMicromaps, queryType, dataSize, pData, stride);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdCopyMicromapEXT", "commandBuffer, pInfo", "void");
    device_dispatch_table(commandBuffer)->CmdCopyMicromapEXT(commandBuffer, pInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdCopyMicromapEXT(ApiDumpInstance::current(), commandBuffer, pInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdCopyMicromapEXT(ApiDumpInstance::current(), commandBuffer, pInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdCopyMicromapEXT(ApiDumpInstance::current(), commandBuffer, pInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyMicromapToMemoryEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapToMemoryInfoEXT* pInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdCopyMicromapToMemoryEXT", "commandBuffer, pInfo", "void");
    device_dispatch_table(commandBuffer)->CmdCopyMicromapToMemoryEXT(commandBuffer, pInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdCopyMicromapToMemoryEXT(ApiDumpInstance::current(), commandBuffer, pInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdCopyMicromapToMemoryEXT(ApiDumpInstance::current(), commandBuffer, pInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdCopyMicromapToMemoryEXT(ApiDumpInstance::current(), commandBuffer, pInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyMemoryToMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMemoryToMicromapInfoEXT* pInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdCopyMemoryToMicromapEXT", "commandBuffer, pInfo", "void");
    device_dispatch_table(commandBuffer)->CmdCopyMemoryToMicromapEXT(commandBuffer, pInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdCopyMemoryToMicromapEXT(ApiDumpInstance::current(), commandBuffer, pInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdCopyMemoryToMicromapEXT(ApiDumpInstance::current(), commandBuffer, pInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdCopyMemoryToMicromapEXT(ApiDumpInstance::current(), commandBuffer, pInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdWriteMicromapsPropertiesEXT(VkCommandBuffer commandBuffer, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdWriteMicromapsPropertiesEXT", "commandBuffer, micromapCount, pMicromaps, queryType, queryPool, firstQuery", "void");
    device_dispatch_table(commandBuffer)->CmdWriteMicromapsPropertiesEXT(commandBuffer, micromapCount, pMicromaps, queryType, queryPool, firstQuery);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdWriteMicromapsPropertiesEXT(ApiDumpInstance::current(), commandBuffer, micromapCount, pMicromaps, queryType, queryPool, firstQuery);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdWriteMicromapsPropertiesEXT(ApiDumpInstance::current(), commandBuffer, micromapCount, pMicromaps, queryType, queryPool, firstQuery);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdWriteMicromapsPropertiesEXT(ApiDumpInstance::current(), commandBuffer, micromapCount, pMicromaps, queryType, queryPool, firstQuery);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetDeviceMicromapCompatibilityEXT(VkDevice device, const VkMicromapVersionInfoEXT* pVersionInfo, VkAccelerationStructureCompatibilityKHR* pCompatibility)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDeviceMicromapCompatibilityEXT", "device, pVersionInfo, pCompatibility", "void");
    device_dispatch_table(device)->GetDeviceMicromapCompatibilityEXT(device, pVersionInfo, pCompatibility);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDeviceMicromapCompatibilityEXT(ApiDumpInstance::current(), device, pVersionInfo, pCompatibility);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDeviceMicromapCompatibilityEXT(ApiDumpInstance::current(), device, pVersionInfo, pCompatibility);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDeviceMicromapCompatibilityEXT(ApiDumpInstance::current(), device, pVersionInfo, pCompatibility);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetMicromapBuildSizesEXT(VkDevice                                            device, VkAccelerationStructureBuildTypeKHR                 buildType, const VkMicromapBuildInfoEXT*  pBuildInfo, VkMicromapBuildSizesInfoEXT*           pSizeInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetMicromapBuildSizesEXT", "device, buildType, pBuildInfo, pSizeInfo", "void");
    device_dispatch_table(device)->GetMicromapBuildSizesEXT(device, buildType, pBuildInfo, pSizeInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetMicromapBuildSizesEXT(ApiDumpInstance::current(), device, buildType, pBuildInfo, pSizeInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetMicromapBuildSizesEXT(ApiDumpInstance::current(), device, buildType, pBuildInfo, pSizeInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetMicromapBuildSizesEXT(ApiDumpInstance::current(), device, buildType, pBuildInfo, pSizeInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawClusterHUAWEI(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdDrawClusterHUAWEI", "commandBuffer, groupCountX, groupCountY, groupCountZ", "void");
    device_dispatch_table(commandBuffer)->CmdDrawClusterHUAWEI(commandBuffer, groupCountX, groupCountY, groupCountZ);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdDrawClusterHUAWEI(ApiDumpInstance::current(), commandBuffer, groupCountX, groupCountY, groupCountZ);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdDrawClusterHUAWEI(ApiDumpInstance::current(), commandBuffer, groupCountX, groupCountY, groupCountZ);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdDrawClusterHUAWEI(ApiDumpInstance::current(), commandBuffer, groupCountX, groupCountY, groupCountZ);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawClusterIndirectHUAWEI(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdDrawClusterIndirectHUAWEI", "commandBuffer, buffer, offset", "void");
    device_dispatch_table(commandBuffer)->CmdDrawClusterIndirectHUAWEI(commandBuffer, buffer, offset);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdDrawClusterIndirectHUAWEI(ApiDumpInstance::current(), commandBuffer, buffer, offset);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdDrawClusterIndirectHUAWEI(ApiDumpInstance::current(), commandBuffer, buffer, offset);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdDrawClusterIndirectHUAWEI(ApiDumpInstance::current(), commandBuffer, buffer, offset);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkSetDeviceMemoryPriorityEXT(VkDevice       device, VkDeviceMemory memory, float          priority)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkSetDeviceMemoryPriorityEXT", "device, memory, priority", "void");
    device_dispatch_table(device)->SetDeviceMemoryPriorityEXT(device, memory, priority);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkSetDeviceMemoryPriorityEXT(ApiDumpInstance::current(), device, memory, priority);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkSetDeviceMemoryPriorityEXT(ApiDumpInstance::current(), device, memory, priority);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkSetDeviceMemoryPriorityEXT(ApiDumpInstance::current(), device, memory, priority);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetDeviceBufferMemoryRequirementsKHR(VkDevice device, const VkDeviceBufferMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDeviceBufferMemoryRequirementsKHR", "device, pInfo, pMemoryRequirements", "void");
    device_dispatch_table(device)->GetDeviceBufferMemoryRequirementsKHR(device, pInfo, pMemoryRequirements);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDeviceBufferMemoryRequirementsKHR(ApiDumpInstance::current(), device, pInfo, pMemoryRequirements);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDeviceBufferMemoryRequirementsKHR(ApiDumpInstance::current(), device, pInfo, pMemoryRequirements);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDeviceBufferMemoryRequirementsKHR(ApiDumpInstance::current(), device, pInfo, pMemoryRequirements);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetDeviceImageMemoryRequirementsKHR(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDeviceImageMemoryRequirementsKHR", "device, pInfo, pMemoryRequirements", "void");
    device_dispatch_table(device)->GetDeviceImageMemoryRequirementsKHR(device, pInfo, pMemoryRequirements);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDeviceImageMemoryRequirementsKHR(ApiDumpInstance::current(), device, pInfo, pMemoryRequirements);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDeviceImageMemoryRequirementsKHR(ApiDumpInstance::current(), device, pInfo, pMemoryRequirements);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDeviceImageMemoryRequirementsKHR(ApiDumpInstance::current(), device, pInfo, pMemoryRequirements);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetDeviceImageSparseMemoryRequirementsKHR(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDeviceImageSparseMemoryRequirementsKHR", "device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements", "void");
    device_dispatch_table(device)->GetDeviceImageSparseMemoryRequirementsKHR(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDeviceImageSparseMemoryRequirementsKHR(ApiDumpInstance::current(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDeviceImageSparseMemoryRequirementsKHR(ApiDumpInstance::current(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDeviceImageSparseMemoryRequirementsKHR(ApiDumpInstance::current(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetDescriptorSetLayoutHostMappingInfoVALVE(VkDevice device, const VkDescriptorSetBindingReferenceVALVE* pBindingReference, VkDescriptorSetLayoutHostMappingInfoVALVE* pHostMapping)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDescriptorSetLayoutHostMappingInfoVALVE", "device, pBindingReference, pHostMapping", "void");
    device_dispatch_table(device)->GetDescriptorSetLayoutHostMappingInfoVALVE(device, pBindingReference, pHostMapping);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDescriptorSetLayoutHostMappingInfoVALVE(ApiDumpInstance::current(), device, pBindingReference, pHostMapping);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDescriptorSetLayoutHostMappingInfoVALVE(ApiDumpInstance::current(), device, pBindingReference, pHostMapping);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDescriptorSetLayoutHostMappingInfoVALVE(ApiDumpInstance::current(), device, pBindingReference, pHostMapping);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetDescriptorSetHostMappingVALVE(VkDevice device, VkDescriptorSet descriptorSet, void** ppData)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDescriptorSetHostMappingVALVE", "device, descriptorSet, ppData", "void");
    device_dispatch_table(device)->GetDescriptorSetHostMappingVALVE(device, descriptorSet, ppData);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDescriptorSetHostMappingVALVE(ApiDumpInstance::current(), device, descriptorSet, ppData);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDescriptorSetHostMappingVALVE(ApiDumpInstance::current(), device, descriptorSet, ppData);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDescriptorSetHostMappingVALVE(ApiDumpInstance::current(), device, descriptorSet, ppData);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyMemoryIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress, uint32_t copyCount, uint32_t stride)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdCopyMemoryIndirectNV", "commandBuffer, copyBufferAddress, copyCount, stride", "void");
    device_dispatch_table(commandBuffer)->CmdCopyMemoryIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdCopyMemoryIndirectNV(ApiDumpInstance::current(), commandBuffer, copyBufferAddress, copyCount, stride);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdCopyMemoryIndirectNV(ApiDumpInstance::current(), commandBuffer, copyBufferAddress, copyCount, stride);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdCopyMemoryIndirectNV(ApiDumpInstance::current(), commandBuffer, copyBufferAddress, copyCount, stride);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyMemoryToImageIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress, uint32_t copyCount, uint32_t stride, VkImage dstImage, VkImageLayout dstImageLayout, const VkImageSubresourceLayers* pImageSubresources)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdCopyMemoryToImageIndirectNV", "commandBuffer, copyBufferAddress, copyCount, stride, dstImage, dstImageLayout, pImageSubresources", "void");
    device_dispatch_table(commandBuffer)->CmdCopyMemoryToImageIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride, dstImage, dstImageLayout, pImageSubresources);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdCopyMemoryToImageIndirectNV(ApiDumpInstance::current(), commandBuffer, copyBufferAddress, copyCount, stride, dstImage, dstImageLayout, pImageSubresources);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdCopyMemoryToImageIndirectNV(ApiDumpInstance::current(), commandBuffer, copyBufferAddress, copyCount, stride, dstImage, dstImageLayout, pImageSubresources);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdCopyMemoryToImageIndirectNV(ApiDumpInstance::current(), commandBuffer, copyBufferAddress, copyCount, stride, dstImage, dstImageLayout, pImageSubresources);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdDecompressMemoryNV(VkCommandBuffer commandBuffer, uint32_t decompressRegionCount, const VkDecompressMemoryRegionNV* pDecompressMemoryRegions)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdDecompressMemoryNV", "commandBuffer, decompressRegionCount, pDecompressMemoryRegions", "void");
    device_dispatch_table(commandBuffer)->CmdDecompressMemoryNV(commandBuffer, decompressRegionCount, pDecompressMemoryRegions);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdDecompressMemoryNV(ApiDumpInstance::current(), commandBuffer, decompressRegionCount, pDecompressMemoryRegions);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdDecompressMemoryNV(ApiDumpInstance::current(), commandBuffer, decompressRegionCount, pDecompressMemoryRegions);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdDecompressMemoryNV(ApiDumpInstance::current(), commandBuffer, decompressRegionCount, pDecompressMemoryRegions);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdDecompressMemoryIndirectCountNV(VkCommandBuffer commandBuffer, VkDeviceAddress indirectCommandsAddress, VkDeviceAddress indirectCommandsCountAddress, uint32_t stride)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdDecompressMemoryIndirectCountNV", "commandBuffer, indirectCommandsAddress, indirectCommandsCountAddress, stride", "void");
    device_dispatch_table(commandBuffer)->CmdDecompressMemoryIndirectCountNV(commandBuffer, indirectCommandsAddress, indirectCommandsCountAddress, stride);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdDecompressMemoryIndirectCountNV(ApiDumpInstance::current(), commandBuffer, indirectCommandsAddress, indirectCommandsCountAddress, stride);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdDecompressMemoryIndirectCountNV(ApiDumpInstance::current(), commandBuffer, indirectCommandsAddress, indirectCommandsCountAddress, stride);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdDecompressMemoryIndirectCountNV(ApiDumpInstance::current(), commandBuffer, indirectCommandsAddress, indirectCommandsCountAddress, stride);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetPipelineIndirectMemoryRequirementsNV(VkDevice device, const VkComputePipelineCreateInfo* pCreateInfo, VkMemoryRequirements2* pMemoryRequirements)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPipelineIndirectMemoryRequirementsNV", "device, pCreateInfo, pMemoryRequirements", "void");
    device_dispatch_table(device)->GetPipelineIndirectMemoryRequirementsNV(device, pCreateInfo, pMemoryRequirements);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPipelineIndirectMemoryRequirementsNV(ApiDumpInstance::current(), device, pCreateInfo, pMemoryRequirements);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPipelineIndirectMemoryRequirementsNV(ApiDumpInstance::current(), device, pCreateInfo, pMemoryRequirements);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPipelineIndirectMemoryRequirementsNV(ApiDumpInstance::current(), device, pCreateInfo, pMemoryRequirements);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdUpdatePipelineIndirectBufferNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint           pipelineBindPoint, VkPipeline                    pipeline)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdUpdatePipelineIndirectBufferNV", "commandBuffer, pipelineBindPoint, pipeline", "void");
    device_dispatch_table(commandBuffer)->CmdUpdatePipelineIndirectBufferNV(commandBuffer, pipelineBindPoint, pipeline);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdUpdatePipelineIndirectBufferNV(ApiDumpInstance::current(), commandBuffer, pipelineBindPoint, pipeline);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdUpdatePipelineIndirectBufferNV(ApiDumpInstance::current(), commandBuffer, pipelineBindPoint, pipeline);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdUpdatePipelineIndirectBufferNV(ApiDumpInstance::current(), commandBuffer, pipelineBindPoint, pipeline);
                break;
        }
    }
}
VKAPI_ATTR VkDeviceAddress VKAPI_CALL vkGetPipelineIndirectDeviceAddressNV(VkDevice device, const VkPipelineIndirectDeviceAddressInfoNV* pInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetPipelineIndirectDeviceAddressNV", "device, pInfo", "VkDeviceAddress");
    VkDeviceAddress result = device_dispatch_table(device)->GetPipelineIndirectDeviceAddressNV(device, pInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetPipelineIndirectDeviceAddressNV(ApiDumpInstance::current(), result, device, pInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetPipelineIndirectDeviceAddressNV(ApiDumpInstance::current(), result, device, pInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetPipelineIndirectDeviceAddressNV(ApiDumpInstance::current(), result, device, pInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthClampEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClampEnable)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetDepthClampEnableEXT", "commandBuffer, depthClampEnable", "void");
    device_dispatch_table(commandBuffer)->CmdSetDepthClampEnableEXT(commandBuffer, depthClampEnable);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetDepthClampEnableEXT(ApiDumpInstance::current(), commandBuffer, depthClampEnable);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetDepthClampEnableEXT(ApiDumpInstance::current(), commandBuffer, depthClampEnable);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetDepthClampEnableEXT(ApiDumpInstance::current(), commandBuffer, depthClampEnable);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetPolygonModeEXT(VkCommandBuffer commandBuffer, VkPolygonMode polygonMode)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetPolygonModeEXT", "commandBuffer, polygonMode", "void");
    device_dispatch_table(commandBuffer)->CmdSetPolygonModeEXT(commandBuffer, polygonMode);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetPolygonModeEXT(ApiDumpInstance::current(), commandBuffer, polygonMode);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetPolygonModeEXT(ApiDumpInstance::current(), commandBuffer, polygonMode);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetPolygonModeEXT(ApiDumpInstance::current(), commandBuffer, polygonMode);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetRasterizationSamplesEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits  rasterizationSamples)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetRasterizationSamplesEXT", "commandBuffer, rasterizationSamples", "void");
    device_dispatch_table(commandBuffer)->CmdSetRasterizationSamplesEXT(commandBuffer, rasterizationSamples);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetRasterizationSamplesEXT(ApiDumpInstance::current(), commandBuffer, rasterizationSamples);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetRasterizationSamplesEXT(ApiDumpInstance::current(), commandBuffer, rasterizationSamples);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetRasterizationSamplesEXT(ApiDumpInstance::current(), commandBuffer, rasterizationSamples);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetSampleMaskEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits  samples, const VkSampleMask*    pSampleMask)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetSampleMaskEXT", "commandBuffer, samples, pSampleMask", "void");
    device_dispatch_table(commandBuffer)->CmdSetSampleMaskEXT(commandBuffer, samples, pSampleMask);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetSampleMaskEXT(ApiDumpInstance::current(), commandBuffer, samples, pSampleMask);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetSampleMaskEXT(ApiDumpInstance::current(), commandBuffer, samples, pSampleMask);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetSampleMaskEXT(ApiDumpInstance::current(), commandBuffer, samples, pSampleMask);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetAlphaToCoverageEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToCoverageEnable)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetAlphaToCoverageEnableEXT", "commandBuffer, alphaToCoverageEnable", "void");
    device_dispatch_table(commandBuffer)->CmdSetAlphaToCoverageEnableEXT(commandBuffer, alphaToCoverageEnable);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetAlphaToCoverageEnableEXT(ApiDumpInstance::current(), commandBuffer, alphaToCoverageEnable);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetAlphaToCoverageEnableEXT(ApiDumpInstance::current(), commandBuffer, alphaToCoverageEnable);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetAlphaToCoverageEnableEXT(ApiDumpInstance::current(), commandBuffer, alphaToCoverageEnable);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetAlphaToOneEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToOneEnable)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetAlphaToOneEnableEXT", "commandBuffer, alphaToOneEnable", "void");
    device_dispatch_table(commandBuffer)->CmdSetAlphaToOneEnableEXT(commandBuffer, alphaToOneEnable);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetAlphaToOneEnableEXT(ApiDumpInstance::current(), commandBuffer, alphaToOneEnable);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetAlphaToOneEnableEXT(ApiDumpInstance::current(), commandBuffer, alphaToOneEnable);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetAlphaToOneEnableEXT(ApiDumpInstance::current(), commandBuffer, alphaToOneEnable);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetLogicOpEnableEXT(VkCommandBuffer commandBuffer, VkBool32 logicOpEnable)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetLogicOpEnableEXT", "commandBuffer, logicOpEnable", "void");
    device_dispatch_table(commandBuffer)->CmdSetLogicOpEnableEXT(commandBuffer, logicOpEnable);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetLogicOpEnableEXT(ApiDumpInstance::current(), commandBuffer, logicOpEnable);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetLogicOpEnableEXT(ApiDumpInstance::current(), commandBuffer, logicOpEnable);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetLogicOpEnableEXT(ApiDumpInstance::current(), commandBuffer, logicOpEnable);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetColorBlendEnableEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkBool32* pColorBlendEnables)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetColorBlendEnableEXT", "commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables", "void");
    device_dispatch_table(commandBuffer)->CmdSetColorBlendEnableEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetColorBlendEnableEXT(ApiDumpInstance::current(), commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetColorBlendEnableEXT(ApiDumpInstance::current(), commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetColorBlendEnableEXT(ApiDumpInstance::current(), commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetColorBlendEquationEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorBlendEquationEXT* pColorBlendEquations)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetColorBlendEquationEXT", "commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations", "void");
    device_dispatch_table(commandBuffer)->CmdSetColorBlendEquationEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetColorBlendEquationEXT(ApiDumpInstance::current(), commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetColorBlendEquationEXT(ApiDumpInstance::current(), commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetColorBlendEquationEXT(ApiDumpInstance::current(), commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetColorWriteMaskEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorComponentFlags* pColorWriteMasks)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetColorWriteMaskEXT", "commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks", "void");
    device_dispatch_table(commandBuffer)->CmdSetColorWriteMaskEXT(commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetColorWriteMaskEXT(ApiDumpInstance::current(), commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetColorWriteMaskEXT(ApiDumpInstance::current(), commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetColorWriteMaskEXT(ApiDumpInstance::current(), commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetTessellationDomainOriginEXT(VkCommandBuffer commandBuffer, VkTessellationDomainOrigin domainOrigin)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetTessellationDomainOriginEXT", "commandBuffer, domainOrigin", "void");
    device_dispatch_table(commandBuffer)->CmdSetTessellationDomainOriginEXT(commandBuffer, domainOrigin);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetTessellationDomainOriginEXT(ApiDumpInstance::current(), commandBuffer, domainOrigin);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetTessellationDomainOriginEXT(ApiDumpInstance::current(), commandBuffer, domainOrigin);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetTessellationDomainOriginEXT(ApiDumpInstance::current(), commandBuffer, domainOrigin);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetRasterizationStreamEXT(VkCommandBuffer commandBuffer, uint32_t rasterizationStream)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetRasterizationStreamEXT", "commandBuffer, rasterizationStream", "void");
    device_dispatch_table(commandBuffer)->CmdSetRasterizationStreamEXT(commandBuffer, rasterizationStream);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetRasterizationStreamEXT(ApiDumpInstance::current(), commandBuffer, rasterizationStream);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetRasterizationStreamEXT(ApiDumpInstance::current(), commandBuffer, rasterizationStream);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetRasterizationStreamEXT(ApiDumpInstance::current(), commandBuffer, rasterizationStream);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetConservativeRasterizationModeEXT(VkCommandBuffer commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetConservativeRasterizationModeEXT", "commandBuffer, conservativeRasterizationMode", "void");
    device_dispatch_table(commandBuffer)->CmdSetConservativeRasterizationModeEXT(commandBuffer, conservativeRasterizationMode);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetConservativeRasterizationModeEXT(ApiDumpInstance::current(), commandBuffer, conservativeRasterizationMode);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetConservativeRasterizationModeEXT(ApiDumpInstance::current(), commandBuffer, conservativeRasterizationMode);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetConservativeRasterizationModeEXT(ApiDumpInstance::current(), commandBuffer, conservativeRasterizationMode);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetExtraPrimitiveOverestimationSizeEXT(VkCommandBuffer commandBuffer, float extraPrimitiveOverestimationSize)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetExtraPrimitiveOverestimationSizeEXT", "commandBuffer, extraPrimitiveOverestimationSize", "void");
    device_dispatch_table(commandBuffer)->CmdSetExtraPrimitiveOverestimationSizeEXT(commandBuffer, extraPrimitiveOverestimationSize);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetExtraPrimitiveOverestimationSizeEXT(ApiDumpInstance::current(), commandBuffer, extraPrimitiveOverestimationSize);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetExtraPrimitiveOverestimationSizeEXT(ApiDumpInstance::current(), commandBuffer, extraPrimitiveOverestimationSize);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetExtraPrimitiveOverestimationSizeEXT(ApiDumpInstance::current(), commandBuffer, extraPrimitiveOverestimationSize);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthClipEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClipEnable)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetDepthClipEnableEXT", "commandBuffer, depthClipEnable", "void");
    device_dispatch_table(commandBuffer)->CmdSetDepthClipEnableEXT(commandBuffer, depthClipEnable);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetDepthClipEnableEXT(ApiDumpInstance::current(), commandBuffer, depthClipEnable);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetDepthClipEnableEXT(ApiDumpInstance::current(), commandBuffer, depthClipEnable);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetDepthClipEnableEXT(ApiDumpInstance::current(), commandBuffer, depthClipEnable);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetSampleLocationsEnableEXT(VkCommandBuffer commandBuffer, VkBool32 sampleLocationsEnable)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetSampleLocationsEnableEXT", "commandBuffer, sampleLocationsEnable", "void");
    device_dispatch_table(commandBuffer)->CmdSetSampleLocationsEnableEXT(commandBuffer, sampleLocationsEnable);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetSampleLocationsEnableEXT(ApiDumpInstance::current(), commandBuffer, sampleLocationsEnable);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetSampleLocationsEnableEXT(ApiDumpInstance::current(), commandBuffer, sampleLocationsEnable);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetSampleLocationsEnableEXT(ApiDumpInstance::current(), commandBuffer, sampleLocationsEnable);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetColorBlendAdvancedEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorBlendAdvancedEXT* pColorBlendAdvanced)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetColorBlendAdvancedEXT", "commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced", "void");
    device_dispatch_table(commandBuffer)->CmdSetColorBlendAdvancedEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetColorBlendAdvancedEXT(ApiDumpInstance::current(), commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetColorBlendAdvancedEXT(ApiDumpInstance::current(), commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetColorBlendAdvancedEXT(ApiDumpInstance::current(), commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetProvokingVertexModeEXT(VkCommandBuffer commandBuffer, VkProvokingVertexModeEXT provokingVertexMode)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetProvokingVertexModeEXT", "commandBuffer, provokingVertexMode", "void");
    device_dispatch_table(commandBuffer)->CmdSetProvokingVertexModeEXT(commandBuffer, provokingVertexMode);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetProvokingVertexModeEXT(ApiDumpInstance::current(), commandBuffer, provokingVertexMode);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetProvokingVertexModeEXT(ApiDumpInstance::current(), commandBuffer, provokingVertexMode);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetProvokingVertexModeEXT(ApiDumpInstance::current(), commandBuffer, provokingVertexMode);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetLineRasterizationModeEXT(VkCommandBuffer commandBuffer, VkLineRasterizationModeEXT lineRasterizationMode)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetLineRasterizationModeEXT", "commandBuffer, lineRasterizationMode", "void");
    device_dispatch_table(commandBuffer)->CmdSetLineRasterizationModeEXT(commandBuffer, lineRasterizationMode);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetLineRasterizationModeEXT(ApiDumpInstance::current(), commandBuffer, lineRasterizationMode);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetLineRasterizationModeEXT(ApiDumpInstance::current(), commandBuffer, lineRasterizationMode);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetLineRasterizationModeEXT(ApiDumpInstance::current(), commandBuffer, lineRasterizationMode);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetLineStippleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stippledLineEnable)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetLineStippleEnableEXT", "commandBuffer, stippledLineEnable", "void");
    device_dispatch_table(commandBuffer)->CmdSetLineStippleEnableEXT(commandBuffer, stippledLineEnable);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetLineStippleEnableEXT(ApiDumpInstance::current(), commandBuffer, stippledLineEnable);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetLineStippleEnableEXT(ApiDumpInstance::current(), commandBuffer, stippledLineEnable);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetLineStippleEnableEXT(ApiDumpInstance::current(), commandBuffer, stippledLineEnable);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthClipNegativeOneToOneEXT(VkCommandBuffer commandBuffer, VkBool32 negativeOneToOne)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetDepthClipNegativeOneToOneEXT", "commandBuffer, negativeOneToOne", "void");
    device_dispatch_table(commandBuffer)->CmdSetDepthClipNegativeOneToOneEXT(commandBuffer, negativeOneToOne);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetDepthClipNegativeOneToOneEXT(ApiDumpInstance::current(), commandBuffer, negativeOneToOne);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetDepthClipNegativeOneToOneEXT(ApiDumpInstance::current(), commandBuffer, negativeOneToOne);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetDepthClipNegativeOneToOneEXT(ApiDumpInstance::current(), commandBuffer, negativeOneToOne);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetViewportWScalingEnableNV(VkCommandBuffer commandBuffer, VkBool32 viewportWScalingEnable)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetViewportWScalingEnableNV", "commandBuffer, viewportWScalingEnable", "void");
    device_dispatch_table(commandBuffer)->CmdSetViewportWScalingEnableNV(commandBuffer, viewportWScalingEnable);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetViewportWScalingEnableNV(ApiDumpInstance::current(), commandBuffer, viewportWScalingEnable);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetViewportWScalingEnableNV(ApiDumpInstance::current(), commandBuffer, viewportWScalingEnable);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetViewportWScalingEnableNV(ApiDumpInstance::current(), commandBuffer, viewportWScalingEnable);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetViewportSwizzleNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportSwizzleNV* pViewportSwizzles)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetViewportSwizzleNV", "commandBuffer, firstViewport, viewportCount, pViewportSwizzles", "void");
    device_dispatch_table(commandBuffer)->CmdSetViewportSwizzleNV(commandBuffer, firstViewport, viewportCount, pViewportSwizzles);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetViewportSwizzleNV(ApiDumpInstance::current(), commandBuffer, firstViewport, viewportCount, pViewportSwizzles);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetViewportSwizzleNV(ApiDumpInstance::current(), commandBuffer, firstViewport, viewportCount, pViewportSwizzles);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetViewportSwizzleNV(ApiDumpInstance::current(), commandBuffer, firstViewport, viewportCount, pViewportSwizzles);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetCoverageToColorEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageToColorEnable)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetCoverageToColorEnableNV", "commandBuffer, coverageToColorEnable", "void");
    device_dispatch_table(commandBuffer)->CmdSetCoverageToColorEnableNV(commandBuffer, coverageToColorEnable);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetCoverageToColorEnableNV(ApiDumpInstance::current(), commandBuffer, coverageToColorEnable);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetCoverageToColorEnableNV(ApiDumpInstance::current(), commandBuffer, coverageToColorEnable);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetCoverageToColorEnableNV(ApiDumpInstance::current(), commandBuffer, coverageToColorEnable);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetCoverageToColorLocationNV(VkCommandBuffer commandBuffer, uint32_t coverageToColorLocation)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetCoverageToColorLocationNV", "commandBuffer, coverageToColorLocation", "void");
    device_dispatch_table(commandBuffer)->CmdSetCoverageToColorLocationNV(commandBuffer, coverageToColorLocation);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetCoverageToColorLocationNV(ApiDumpInstance::current(), commandBuffer, coverageToColorLocation);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetCoverageToColorLocationNV(ApiDumpInstance::current(), commandBuffer, coverageToColorLocation);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetCoverageToColorLocationNV(ApiDumpInstance::current(), commandBuffer, coverageToColorLocation);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetCoverageModulationModeNV(VkCommandBuffer commandBuffer, VkCoverageModulationModeNV coverageModulationMode)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetCoverageModulationModeNV", "commandBuffer, coverageModulationMode", "void");
    device_dispatch_table(commandBuffer)->CmdSetCoverageModulationModeNV(commandBuffer, coverageModulationMode);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetCoverageModulationModeNV(ApiDumpInstance::current(), commandBuffer, coverageModulationMode);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetCoverageModulationModeNV(ApiDumpInstance::current(), commandBuffer, coverageModulationMode);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetCoverageModulationModeNV(ApiDumpInstance::current(), commandBuffer, coverageModulationMode);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetCoverageModulationTableEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageModulationTableEnable)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetCoverageModulationTableEnableNV", "commandBuffer, coverageModulationTableEnable", "void");
    device_dispatch_table(commandBuffer)->CmdSetCoverageModulationTableEnableNV(commandBuffer, coverageModulationTableEnable);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetCoverageModulationTableEnableNV(ApiDumpInstance::current(), commandBuffer, coverageModulationTableEnable);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetCoverageModulationTableEnableNV(ApiDumpInstance::current(), commandBuffer, coverageModulationTableEnable);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetCoverageModulationTableEnableNV(ApiDumpInstance::current(), commandBuffer, coverageModulationTableEnable);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetCoverageModulationTableNV(VkCommandBuffer commandBuffer, uint32_t coverageModulationTableCount, const float* pCoverageModulationTable)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetCoverageModulationTableNV", "commandBuffer, coverageModulationTableCount, pCoverageModulationTable", "void");
    device_dispatch_table(commandBuffer)->CmdSetCoverageModulationTableNV(commandBuffer, coverageModulationTableCount, pCoverageModulationTable);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetCoverageModulationTableNV(ApiDumpInstance::current(), commandBuffer, coverageModulationTableCount, pCoverageModulationTable);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetCoverageModulationTableNV(ApiDumpInstance::current(), commandBuffer, coverageModulationTableCount, pCoverageModulationTable);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetCoverageModulationTableNV(ApiDumpInstance::current(), commandBuffer, coverageModulationTableCount, pCoverageModulationTable);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetShadingRateImageEnableNV(VkCommandBuffer commandBuffer, VkBool32 shadingRateImageEnable)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetShadingRateImageEnableNV", "commandBuffer, shadingRateImageEnable", "void");
    device_dispatch_table(commandBuffer)->CmdSetShadingRateImageEnableNV(commandBuffer, shadingRateImageEnable);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetShadingRateImageEnableNV(ApiDumpInstance::current(), commandBuffer, shadingRateImageEnable);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetShadingRateImageEnableNV(ApiDumpInstance::current(), commandBuffer, shadingRateImageEnable);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetShadingRateImageEnableNV(ApiDumpInstance::current(), commandBuffer, shadingRateImageEnable);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetRepresentativeFragmentTestEnableNV(VkCommandBuffer commandBuffer, VkBool32 representativeFragmentTestEnable)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetRepresentativeFragmentTestEnableNV", "commandBuffer, representativeFragmentTestEnable", "void");
    device_dispatch_table(commandBuffer)->CmdSetRepresentativeFragmentTestEnableNV(commandBuffer, representativeFragmentTestEnable);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetRepresentativeFragmentTestEnableNV(ApiDumpInstance::current(), commandBuffer, representativeFragmentTestEnable);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetRepresentativeFragmentTestEnableNV(ApiDumpInstance::current(), commandBuffer, representativeFragmentTestEnable);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetRepresentativeFragmentTestEnableNV(ApiDumpInstance::current(), commandBuffer, representativeFragmentTestEnable);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetCoverageReductionModeNV(VkCommandBuffer commandBuffer, VkCoverageReductionModeNV coverageReductionMode)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetCoverageReductionModeNV", "commandBuffer, coverageReductionMode", "void");
    device_dispatch_table(commandBuffer)->CmdSetCoverageReductionModeNV(commandBuffer, coverageReductionMode);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetCoverageReductionModeNV(ApiDumpInstance::current(), commandBuffer, coverageReductionMode);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetCoverageReductionModeNV(ApiDumpInstance::current(), commandBuffer, coverageReductionMode);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetCoverageReductionModeNV(ApiDumpInstance::current(), commandBuffer, coverageReductionMode);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetShaderModuleIdentifierEXT(VkDevice device, VkShaderModule shaderModule, VkShaderModuleIdentifierEXT* pIdentifier)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetShaderModuleIdentifierEXT", "device, shaderModule, pIdentifier", "void");
    device_dispatch_table(device)->GetShaderModuleIdentifierEXT(device, shaderModule, pIdentifier);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetShaderModuleIdentifierEXT(ApiDumpInstance::current(), device, shaderModule, pIdentifier);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetShaderModuleIdentifierEXT(ApiDumpInstance::current(), device, shaderModule, pIdentifier);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetShaderModuleIdentifierEXT(ApiDumpInstance::current(), device, shaderModule, pIdentifier);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetShaderModuleCreateInfoIdentifierEXT(VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, VkShaderModuleIdentifierEXT* pIdentifier)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetShaderModuleCreateInfoIdentifierEXT", "device, pCreateInfo, pIdentifier", "void");
    device_dispatch_table(device)->GetShaderModuleCreateInfoIdentifierEXT(device, pCreateInfo, pIdentifier);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetShaderModuleCreateInfoIdentifierEXT(ApiDumpInstance::current(), device, pCreateInfo, pIdentifier);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetShaderModuleCreateInfoIdentifierEXT(ApiDumpInstance::current(), device, pCreateInfo, pIdentifier);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetShaderModuleCreateInfoIdentifierEXT(ApiDumpInstance::current(), device, pCreateInfo, pIdentifier);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateOpticalFlowSessionNV(VkDevice device, const VkOpticalFlowSessionCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkOpticalFlowSessionNV* pSession)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateOpticalFlowSessionNV", "device, pCreateInfo, pAllocator, pSession", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateOpticalFlowSessionNV(device, pCreateInfo, pAllocator, pSession);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateOpticalFlowSessionNV(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pSession);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateOpticalFlowSessionNV(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pSession);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateOpticalFlowSessionNV(ApiDumpInstance::current(), result, device, pCreateInfo, pAllocator, pSession);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyOpticalFlowSessionNV(VkDevice device, VkOpticalFlowSessionNV session, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyOpticalFlowSessionNV", "device, session, pAllocator", "void");
    device_dispatch_table(device)->DestroyOpticalFlowSessionNV(device, session, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyOpticalFlowSessionNV(ApiDumpInstance::current(), device, session, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyOpticalFlowSessionNV(ApiDumpInstance::current(), device, session, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyOpticalFlowSessionNV(ApiDumpInstance::current(), device, session, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkBindOpticalFlowSessionImageNV(VkDevice device, VkOpticalFlowSessionNV session, VkOpticalFlowSessionBindingPointNV bindingPoint, VkImageView view, VkImageLayout layout)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkBindOpticalFlowSessionImageNV", "device, session, bindingPoint, view, layout", "VkResult");
    VkResult result = device_dispatch_table(device)->BindOpticalFlowSessionImageNV(device, session, bindingPoint, view, layout);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkBindOpticalFlowSessionImageNV(ApiDumpInstance::current(), result, device, session, bindingPoint, view, layout);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkBindOpticalFlowSessionImageNV(ApiDumpInstance::current(), result, device, session, bindingPoint, view, layout);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkBindOpticalFlowSessionImageNV(ApiDumpInstance::current(), result, device, session, bindingPoint, view, layout);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdOpticalFlowExecuteNV(VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session, const VkOpticalFlowExecuteInfoNV* pExecuteInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdOpticalFlowExecuteNV", "commandBuffer, session, pExecuteInfo", "void");
    device_dispatch_table(commandBuffer)->CmdOpticalFlowExecuteNV(commandBuffer, session, pExecuteInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdOpticalFlowExecuteNV(ApiDumpInstance::current(), commandBuffer, session, pExecuteInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdOpticalFlowExecuteNV(ApiDumpInstance::current(), commandBuffer, session, pExecuteInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdOpticalFlowExecuteNV(ApiDumpInstance::current(), commandBuffer, session, pExecuteInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindIndexBuffer2KHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkDeviceSize size, VkIndexType indexType)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdBindIndexBuffer2KHR", "commandBuffer, buffer, offset, size, indexType", "void");
    device_dispatch_table(commandBuffer)->CmdBindIndexBuffer2KHR(commandBuffer, buffer, offset, size, indexType);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdBindIndexBuffer2KHR(ApiDumpInstance::current(), commandBuffer, buffer, offset, size, indexType);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdBindIndexBuffer2KHR(ApiDumpInstance::current(), commandBuffer, buffer, offset, size, indexType);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdBindIndexBuffer2KHR(ApiDumpInstance::current(), commandBuffer, buffer, offset, size, indexType);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetRenderingAreaGranularityKHR(VkDevice device, const VkRenderingAreaInfoKHR* pRenderingAreaInfo, VkExtent2D* pGranularity)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetRenderingAreaGranularityKHR", "device, pRenderingAreaInfo, pGranularity", "void");
    device_dispatch_table(device)->GetRenderingAreaGranularityKHR(device, pRenderingAreaInfo, pGranularity);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetRenderingAreaGranularityKHR(ApiDumpInstance::current(), device, pRenderingAreaInfo, pGranularity);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetRenderingAreaGranularityKHR(ApiDumpInstance::current(), device, pRenderingAreaInfo, pGranularity);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetRenderingAreaGranularityKHR(ApiDumpInstance::current(), device, pRenderingAreaInfo, pGranularity);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetDeviceImageSubresourceLayoutKHR(VkDevice device, const VkDeviceImageSubresourceInfoKHR* pInfo, VkSubresourceLayout2KHR* pLayout)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDeviceImageSubresourceLayoutKHR", "device, pInfo, pLayout", "void");
    device_dispatch_table(device)->GetDeviceImageSubresourceLayoutKHR(device, pInfo, pLayout);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDeviceImageSubresourceLayoutKHR(ApiDumpInstance::current(), device, pInfo, pLayout);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDeviceImageSubresourceLayoutKHR(ApiDumpInstance::current(), device, pInfo, pLayout);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDeviceImageSubresourceLayoutKHR(ApiDumpInstance::current(), device, pInfo, pLayout);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkAntiLagUpdateAMD(VkDevice device, const VkAntiLagDataAMD* pData)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkAntiLagUpdateAMD", "device, pData", "void");
    device_dispatch_table(device)->AntiLagUpdateAMD(device, pData);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkAntiLagUpdateAMD(ApiDumpInstance::current(), device, pData);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkAntiLagUpdateAMD(ApiDumpInstance::current(), device, pData);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkAntiLagUpdateAMD(ApiDumpInstance::current(), device, pData);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateShadersEXT(VkDevice device, uint32_t createInfoCount, const VkShaderCreateInfoEXT* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkShaderEXT* pShaders)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCreateShadersEXT", "device, createInfoCount, pCreateInfos, pAllocator, pShaders", "VkResult");
    VkResult result = device_dispatch_table(device)->CreateShadersEXT(device, createInfoCount, pCreateInfos, pAllocator, pShaders);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCreateShadersEXT(ApiDumpInstance::current(), result, device, createInfoCount, pCreateInfos, pAllocator, pShaders);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCreateShadersEXT(ApiDumpInstance::current(), result, device, createInfoCount, pCreateInfos, pAllocator, pShaders);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCreateShadersEXT(ApiDumpInstance::current(), result, device, createInfoCount, pCreateInfos, pAllocator, pShaders);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyShaderEXT(VkDevice device, VkShaderEXT shader, const VkAllocationCallbacks* pAllocator)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkDestroyShaderEXT", "device, shader, pAllocator", "void");
    device_dispatch_table(device)->DestroyShaderEXT(device, shader, pAllocator);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkDestroyShaderEXT(ApiDumpInstance::current(), device, shader, pAllocator);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkDestroyShaderEXT(ApiDumpInstance::current(), device, shader, pAllocator);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkDestroyShaderEXT(ApiDumpInstance::current(), device, shader, pAllocator);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetShaderBinaryDataEXT(VkDevice device, VkShaderEXT shader, size_t* pDataSize, void* pData)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetShaderBinaryDataEXT", "device, shader, pDataSize, pData", "VkResult");
    VkResult result = device_dispatch_table(device)->GetShaderBinaryDataEXT(device, shader, pDataSize, pData);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetShaderBinaryDataEXT(ApiDumpInstance::current(), result, device, shader, pDataSize, pData);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetShaderBinaryDataEXT(ApiDumpInstance::current(), result, device, shader, pDataSize, pData);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetShaderBinaryDataEXT(ApiDumpInstance::current(), result, device, shader, pDataSize, pData);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindShadersEXT(VkCommandBuffer commandBuffer, uint32_t stageCount, const VkShaderStageFlagBits* pStages, const VkShaderEXT* pShaders)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdBindShadersEXT", "commandBuffer, stageCount, pStages, pShaders", "void");
    device_dispatch_table(commandBuffer)->CmdBindShadersEXT(commandBuffer, stageCount, pStages, pShaders);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdBindShadersEXT(ApiDumpInstance::current(), commandBuffer, stageCount, pStages, pShaders);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdBindShadersEXT(ApiDumpInstance::current(), commandBuffer, stageCount, pStages, pShaders);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdBindShadersEXT(ApiDumpInstance::current(), commandBuffer, stageCount, pStages, pShaders);
                break;
        }
    }
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetFramebufferTilePropertiesQCOM(VkDevice device, VkFramebuffer framebuffer, uint32_t* pPropertiesCount, VkTilePropertiesQCOM* pProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetFramebufferTilePropertiesQCOM", "device, framebuffer, pPropertiesCount, pProperties", "VkResult");
    VkResult result = device_dispatch_table(device)->GetFramebufferTilePropertiesQCOM(device, framebuffer, pPropertiesCount, pProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetFramebufferTilePropertiesQCOM(ApiDumpInstance::current(), result, device, framebuffer, pPropertiesCount, pProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetFramebufferTilePropertiesQCOM(ApiDumpInstance::current(), result, device, framebuffer, pPropertiesCount, pProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetFramebufferTilePropertiesQCOM(ApiDumpInstance::current(), result, device, framebuffer, pPropertiesCount, pProperties);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetDynamicRenderingTilePropertiesQCOM(VkDevice device, const VkRenderingInfo* pRenderingInfo, VkTilePropertiesQCOM* pProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetDynamicRenderingTilePropertiesQCOM", "device, pRenderingInfo, pProperties", "VkResult");
    VkResult result = device_dispatch_table(device)->GetDynamicRenderingTilePropertiesQCOM(device, pRenderingInfo, pProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetDynamicRenderingTilePropertiesQCOM(ApiDumpInstance::current(), result, device, pRenderingInfo, pProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetDynamicRenderingTilePropertiesQCOM(ApiDumpInstance::current(), result, device, pRenderingInfo, pProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetDynamicRenderingTilePropertiesQCOM(ApiDumpInstance::current(), result, device, pRenderingInfo, pProperties);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkSetLatencySleepModeNV(VkDevice device, VkSwapchainKHR swapchain, const VkLatencySleepModeInfoNV* pSleepModeInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkSetLatencySleepModeNV", "device, swapchain, pSleepModeInfo", "VkResult");
    VkResult result = device_dispatch_table(device)->SetLatencySleepModeNV(device, swapchain, pSleepModeInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkSetLatencySleepModeNV(ApiDumpInstance::current(), result, device, swapchain, pSleepModeInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkSetLatencySleepModeNV(ApiDumpInstance::current(), result, device, swapchain, pSleepModeInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkSetLatencySleepModeNV(ApiDumpInstance::current(), result, device, swapchain, pSleepModeInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkLatencySleepNV(VkDevice device, VkSwapchainKHR swapchain, const VkLatencySleepInfoNV* pSleepInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkLatencySleepNV", "device, swapchain, pSleepInfo", "VkResult");
    VkResult result = device_dispatch_table(device)->LatencySleepNV(device, swapchain, pSleepInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkLatencySleepNV(ApiDumpInstance::current(), result, device, swapchain, pSleepInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkLatencySleepNV(ApiDumpInstance::current(), result, device, swapchain, pSleepInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkLatencySleepNV(ApiDumpInstance::current(), result, device, swapchain, pSleepInfo);
                break;
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkSetLatencyMarkerNV(VkDevice device, VkSwapchainKHR swapchain, const VkSetLatencyMarkerInfoNV* pLatencyMarkerInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkSetLatencyMarkerNV", "device, swapchain, pLatencyMarkerInfo", "void");
    device_dispatch_table(device)->SetLatencyMarkerNV(device, swapchain, pLatencyMarkerInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkSetLatencyMarkerNV(ApiDumpInstance::current(), device, swapchain, pLatencyMarkerInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkSetLatencyMarkerNV(ApiDumpInstance::current(), device, swapchain, pLatencyMarkerInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkSetLatencyMarkerNV(ApiDumpInstance::current(), device, swapchain, pLatencyMarkerInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkGetLatencyTimingsNV(VkDevice device, VkSwapchainKHR swapchain, VkGetLatencyMarkerInfoNV* pLatencyMarkerInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetLatencyTimingsNV", "device, swapchain, pLatencyMarkerInfo", "void");
    device_dispatch_table(device)->GetLatencyTimingsNV(device, swapchain, pLatencyMarkerInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetLatencyTimingsNV(ApiDumpInstance::current(), device, swapchain, pLatencyMarkerInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetLatencyTimingsNV(ApiDumpInstance::current(), device, swapchain, pLatencyMarkerInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetLatencyTimingsNV(ApiDumpInstance::current(), device, swapchain, pLatencyMarkerInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkQueueNotifyOutOfBandNV(VkQueue queue, const VkOutOfBandQueueTypeInfoNV* pQueueTypeInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkQueueNotifyOutOfBandNV", "queue, pQueueTypeInfo", "void");
    device_dispatch_table(queue)->QueueNotifyOutOfBandNV(queue, pQueueTypeInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkQueueNotifyOutOfBandNV(ApiDumpInstance::current(), queue, pQueueTypeInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkQueueNotifyOutOfBandNV(ApiDumpInstance::current(), queue, pQueueTypeInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkQueueNotifyOutOfBandNV(ApiDumpInstance::current(), queue, pQueueTypeInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetAttachmentFeedbackLoopEnableEXT(VkCommandBuffer commandBuffer, VkImageAspectFlags aspectMask)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetAttachmentFeedbackLoopEnableEXT", "commandBuffer, aspectMask", "void");
    device_dispatch_table(commandBuffer)->CmdSetAttachmentFeedbackLoopEnableEXT(commandBuffer, aspectMask);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetAttachmentFeedbackLoopEnableEXT(ApiDumpInstance::current(), commandBuffer, aspectMask);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetAttachmentFeedbackLoopEnableEXT(ApiDumpInstance::current(), commandBuffer, aspectMask);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetAttachmentFeedbackLoopEnableEXT(ApiDumpInstance::current(), commandBuffer, aspectMask);
                break;
        }
    }
}
#if defined(VK_USE_PLATFORM_SCREEN_QNX)
VKAPI_ATTR VkResult VKAPI_CALL vkGetScreenBufferPropertiesQNX(VkDevice device, const struct _screen_buffer* buffer, VkScreenBufferPropertiesQNX* pProperties)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkGetScreenBufferPropertiesQNX", "device, buffer, pProperties", "VkResult");
    VkResult result = device_dispatch_table(device)->GetScreenBufferPropertiesQNX(device, buffer, pProperties);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkGetScreenBufferPropertiesQNX(ApiDumpInstance::current(), result, device, buffer, pProperties);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkGetScreenBufferPropertiesQNX(ApiDumpInstance::current(), result, device, buffer, pProperties);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkGetScreenBufferPropertiesQNX(ApiDumpInstance::current(), result, device, buffer, pProperties);
                break;
        }
    }
    return result;
}
#endif // VK_USE_PLATFORM_SCREEN_QNX
VKAPI_ATTR void VKAPI_CALL vkCmdBindDescriptorSets2KHR(VkCommandBuffer commandBuffer, const VkBindDescriptorSetsInfoKHR* pBindDescriptorSetsInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdBindDescriptorSets2KHR", "commandBuffer, pBindDescriptorSetsInfo", "void");
    device_dispatch_table(commandBuffer)->CmdBindDescriptorSets2KHR(commandBuffer, pBindDescriptorSetsInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdBindDescriptorSets2KHR(ApiDumpInstance::current(), commandBuffer, pBindDescriptorSetsInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdBindDescriptorSets2KHR(ApiDumpInstance::current(), commandBuffer, pBindDescriptorSetsInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdBindDescriptorSets2KHR(ApiDumpInstance::current(), commandBuffer, pBindDescriptorSetsInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdPushConstants2KHR(VkCommandBuffer commandBuffer, const VkPushConstantsInfoKHR* pPushConstantsInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdPushConstants2KHR", "commandBuffer, pPushConstantsInfo", "void");
    device_dispatch_table(commandBuffer)->CmdPushConstants2KHR(commandBuffer, pPushConstantsInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdPushConstants2KHR(ApiDumpInstance::current(), commandBuffer, pPushConstantsInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdPushConstants2KHR(ApiDumpInstance::current(), commandBuffer, pPushConstantsInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdPushConstants2KHR(ApiDumpInstance::current(), commandBuffer, pPushConstantsInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSet2KHR(VkCommandBuffer commandBuffer, const VkPushDescriptorSetInfoKHR* pPushDescriptorSetInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdPushDescriptorSet2KHR", "commandBuffer, pPushDescriptorSetInfo", "void");
    device_dispatch_table(commandBuffer)->CmdPushDescriptorSet2KHR(commandBuffer, pPushDescriptorSetInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdPushDescriptorSet2KHR(ApiDumpInstance::current(), commandBuffer, pPushDescriptorSetInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdPushDescriptorSet2KHR(ApiDumpInstance::current(), commandBuffer, pPushDescriptorSetInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdPushDescriptorSet2KHR(ApiDumpInstance::current(), commandBuffer, pPushDescriptorSetInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSetWithTemplate2KHR(VkCommandBuffer commandBuffer, const VkPushDescriptorSetWithTemplateInfoKHR* pPushDescriptorSetWithTemplateInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdPushDescriptorSetWithTemplate2KHR", "commandBuffer, pPushDescriptorSetWithTemplateInfo", "void");
    device_dispatch_table(commandBuffer)->CmdPushDescriptorSetWithTemplate2KHR(commandBuffer, pPushDescriptorSetWithTemplateInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdPushDescriptorSetWithTemplate2KHR(ApiDumpInstance::current(), commandBuffer, pPushDescriptorSetWithTemplateInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdPushDescriptorSetWithTemplate2KHR(ApiDumpInstance::current(), commandBuffer, pPushDescriptorSetWithTemplateInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdPushDescriptorSetWithTemplate2KHR(ApiDumpInstance::current(), commandBuffer, pPushDescriptorSetWithTemplateInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDescriptorBufferOffsets2EXT(VkCommandBuffer commandBuffer, const VkSetDescriptorBufferOffsetsInfoEXT* pSetDescriptorBufferOffsetsInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdSetDescriptorBufferOffsets2EXT", "commandBuffer, pSetDescriptorBufferOffsetsInfo", "void");
    device_dispatch_table(commandBuffer)->CmdSetDescriptorBufferOffsets2EXT(commandBuffer, pSetDescriptorBufferOffsetsInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdSetDescriptorBufferOffsets2EXT(ApiDumpInstance::current(), commandBuffer, pSetDescriptorBufferOffsetsInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdSetDescriptorBufferOffsets2EXT(ApiDumpInstance::current(), commandBuffer, pSetDescriptorBufferOffsetsInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdSetDescriptorBufferOffsets2EXT(ApiDumpInstance::current(), commandBuffer, pSetDescriptorBufferOffsetsInfo);
                break;
        }
    }
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(VkCommandBuffer commandBuffer, const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo)
{
    std::lock_guard<std::mutex> lg(ApiDumpInstance::current().outputMutex());
    dump_function_head(ApiDumpInstance::current(), "vkCmdBindDescriptorBufferEmbeddedSamplers2EXT", "commandBuffer, pBindDescriptorBufferEmbeddedSamplersInfo", "void");
    device_dispatch_table(commandBuffer)->CmdBindDescriptorBufferEmbeddedSamplers2EXT(commandBuffer, pBindDescriptorBufferEmbeddedSamplersInfo);
    
    if (ApiDumpInstance::current().shouldDumpOutput()) {
        switch(ApiDumpInstance::current().settings().format())
        {
            case ApiDumpFormat::Text:
                dump_text_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(ApiDumpInstance::current(), commandBuffer, pBindDescriptorBufferEmbeddedSamplersInfo);
                break;
            case ApiDumpFormat::Html:
                dump_html_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(ApiDumpInstance::current(), commandBuffer, pBindDescriptorBufferEmbeddedSamplersInfo);
                break;
            case ApiDumpFormat::Json:
                dump_json_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(ApiDumpInstance::current(), commandBuffer, pBindDescriptorBufferEmbeddedSamplersInfo);
                break;
        }
    }
}

VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL api_dump_known_instance_functions(VkInstance instance, const char* pName)
{

    if(strcmp(pName, "vkCreateInstance") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateInstance);
    if(strcmp(pName, "vkDestroyInstance") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyInstance);
    if(strcmp(pName, "vkEnumeratePhysicalDevices") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkEnumeratePhysicalDevices);
    if(strcmp(pName, "vkGetPhysicalDeviceFeatures") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceFeatures);
    if(strcmp(pName, "vkGetPhysicalDeviceFormatProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceFormatProperties);
    if(strcmp(pName, "vkGetPhysicalDeviceImageFormatProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceImageFormatProperties);
    if(strcmp(pName, "vkGetPhysicalDeviceProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceProperties);
    if(strcmp(pName, "vkGetPhysicalDeviceQueueFamilyProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceQueueFamilyProperties);
    if(strcmp(pName, "vkGetPhysicalDeviceMemoryProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceMemoryProperties);
    if(strcmp(pName, "vkGetInstanceProcAddr") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetInstanceProcAddr);
    if(strcmp(pName, "vkCreateDevice") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDevice);
    if(strcmp(pName, "vkEnumerateInstanceExtensionProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkEnumerateInstanceExtensionProperties);
    if(strcmp(pName, "vkEnumerateInstanceLayerProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkEnumerateInstanceLayerProperties);
    if(strcmp(pName, "vkEnumerateDeviceLayerProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkEnumerateDeviceLayerProperties);
    if(strcmp(pName, "vkGetPhysicalDeviceSparseImageFormatProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceSparseImageFormatProperties);
    if(strcmp(pName, "vkEnumeratePhysicalDeviceGroups") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkEnumeratePhysicalDeviceGroups);
    if(strcmp(pName, "vkGetPhysicalDeviceFeatures2") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceFeatures2);
    if(strcmp(pName, "vkGetPhysicalDeviceProperties2") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceProperties2);
    if(strcmp(pName, "vkGetPhysicalDeviceFormatProperties2") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceFormatProperties2);
    if(strcmp(pName, "vkGetPhysicalDeviceImageFormatProperties2") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceImageFormatProperties2);
    if(strcmp(pName, "vkGetPhysicalDeviceQueueFamilyProperties2") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceQueueFamilyProperties2);
    if(strcmp(pName, "vkGetPhysicalDeviceMemoryProperties2") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceMemoryProperties2);
    if(strcmp(pName, "vkGetPhysicalDeviceSparseImageFormatProperties2") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceSparseImageFormatProperties2);
    if(strcmp(pName, "vkGetPhysicalDeviceExternalBufferProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceExternalBufferProperties);
    if(strcmp(pName, "vkGetPhysicalDeviceExternalFenceProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceExternalFenceProperties);
    if(strcmp(pName, "vkGetPhysicalDeviceExternalSemaphoreProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceExternalSemaphoreProperties);
    if(strcmp(pName, "vkGetPhysicalDeviceToolProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceToolProperties);
    if(strcmp(pName, "vkDestroySurfaceKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroySurfaceKHR);
    if(strcmp(pName, "vkGetPhysicalDeviceSurfaceSupportKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceSurfaceSupportKHR);
    if(strcmp(pName, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceSurfaceCapabilitiesKHR);
    if(strcmp(pName, "vkGetPhysicalDeviceSurfaceFormatsKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceSurfaceFormatsKHR);
    if(strcmp(pName, "vkGetPhysicalDeviceSurfacePresentModesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceSurfacePresentModesKHR);
    if(strcmp(pName, "vkGetPhysicalDevicePresentRectanglesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDevicePresentRectanglesKHR);
    if(strcmp(pName, "vkGetPhysicalDeviceDisplayPropertiesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceDisplayPropertiesKHR);
    if(strcmp(pName, "vkGetPhysicalDeviceDisplayPlanePropertiesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceDisplayPlanePropertiesKHR);
    if(strcmp(pName, "vkGetDisplayPlaneSupportedDisplaysKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDisplayPlaneSupportedDisplaysKHR);
    if(strcmp(pName, "vkGetDisplayModePropertiesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDisplayModePropertiesKHR);
    if(strcmp(pName, "vkCreateDisplayModeKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDisplayModeKHR);
    if(strcmp(pName, "vkGetDisplayPlaneCapabilitiesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDisplayPlaneCapabilitiesKHR);
    if(strcmp(pName, "vkCreateDisplayPlaneSurfaceKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDisplayPlaneSurfaceKHR);
#if defined(VK_USE_PLATFORM_XLIB_KHR)
    if(strcmp(pName, "vkCreateXlibSurfaceKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateXlibSurfaceKHR);
#endif // VK_USE_PLATFORM_XLIB_KHR
#if defined(VK_USE_PLATFORM_XLIB_KHR)
    if(strcmp(pName, "vkGetPhysicalDeviceXlibPresentationSupportKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceXlibPresentationSupportKHR);
#endif // VK_USE_PLATFORM_XLIB_KHR
#if defined(VK_USE_PLATFORM_XCB_KHR)
    if(strcmp(pName, "vkCreateXcbSurfaceKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateXcbSurfaceKHR);
#endif // VK_USE_PLATFORM_XCB_KHR
#if defined(VK_USE_PLATFORM_XCB_KHR)
    if(strcmp(pName, "vkGetPhysicalDeviceXcbPresentationSupportKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceXcbPresentationSupportKHR);
#endif // VK_USE_PLATFORM_XCB_KHR
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
    if(strcmp(pName, "vkCreateWaylandSurfaceKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateWaylandSurfaceKHR);
#endif // VK_USE_PLATFORM_WAYLAND_KHR
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
    if(strcmp(pName, "vkGetPhysicalDeviceWaylandPresentationSupportKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceWaylandPresentationSupportKHR);
#endif // VK_USE_PLATFORM_WAYLAND_KHR
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    if(strcmp(pName, "vkCreateAndroidSurfaceKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateAndroidSurfaceKHR);
#endif // VK_USE_PLATFORM_ANDROID_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    if(strcmp(pName, "vkCreateWin32SurfaceKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateWin32SurfaceKHR);
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    if(strcmp(pName, "vkGetPhysicalDeviceWin32PresentationSupportKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceWin32PresentationSupportKHR);
#endif // VK_USE_PLATFORM_WIN32_KHR
    if(strcmp(pName, "vkCreateDebugReportCallbackEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDebugReportCallbackEXT);
    if(strcmp(pName, "vkDestroyDebugReportCallbackEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyDebugReportCallbackEXT);
    if(strcmp(pName, "vkDebugReportMessageEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkDebugReportMessageEXT);
    if(strcmp(pName, "vkGetPhysicalDeviceVideoCapabilitiesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceVideoCapabilitiesKHR);
    if(strcmp(pName, "vkGetPhysicalDeviceVideoFormatPropertiesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceVideoFormatPropertiesKHR);
#if defined(VK_USE_PLATFORM_GGP)
    if(strcmp(pName, "vkCreateStreamDescriptorSurfaceGGP") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateStreamDescriptorSurfaceGGP);
#endif // VK_USE_PLATFORM_GGP
    if(strcmp(pName, "vkGetPhysicalDeviceExternalImageFormatPropertiesNV") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceExternalImageFormatPropertiesNV);
    if(strcmp(pName, "vkGetPhysicalDeviceFeatures2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceFeatures2KHR);
    if(strcmp(pName, "vkGetPhysicalDeviceProperties2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceProperties2KHR);
    if(strcmp(pName, "vkGetPhysicalDeviceFormatProperties2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceFormatProperties2KHR);
    if(strcmp(pName, "vkGetPhysicalDeviceImageFormatProperties2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceImageFormatProperties2KHR);
    if(strcmp(pName, "vkGetPhysicalDeviceQueueFamilyProperties2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceQueueFamilyProperties2KHR);
    if(strcmp(pName, "vkGetPhysicalDeviceMemoryProperties2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceMemoryProperties2KHR);
    if(strcmp(pName, "vkGetPhysicalDeviceSparseImageFormatProperties2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceSparseImageFormatProperties2KHR);
#if defined(VK_USE_PLATFORM_VI_NN)
    if(strcmp(pName, "vkCreateViSurfaceNN") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateViSurfaceNN);
#endif // VK_USE_PLATFORM_VI_NN
    if(strcmp(pName, "vkEnumeratePhysicalDeviceGroupsKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkEnumeratePhysicalDeviceGroupsKHR);
    if(strcmp(pName, "vkGetPhysicalDeviceExternalBufferPropertiesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceExternalBufferPropertiesKHR);
    if(strcmp(pName, "vkGetPhysicalDeviceExternalSemaphorePropertiesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceExternalSemaphorePropertiesKHR);
    if(strcmp(pName, "vkReleaseDisplayEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkReleaseDisplayEXT);
#if defined(VK_USE_PLATFORM_XLIB_XRANDR_EXT)
    if(strcmp(pName, "vkAcquireXlibDisplayEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkAcquireXlibDisplayEXT);
#endif // VK_USE_PLATFORM_XLIB_XRANDR_EXT
#if defined(VK_USE_PLATFORM_XLIB_XRANDR_EXT)
    if(strcmp(pName, "vkGetRandROutputDisplayEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetRandROutputDisplayEXT);
#endif // VK_USE_PLATFORM_XLIB_XRANDR_EXT
    if(strcmp(pName, "vkGetPhysicalDeviceSurfaceCapabilities2EXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceSurfaceCapabilities2EXT);
    if(strcmp(pName, "vkGetPhysicalDeviceExternalFencePropertiesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceExternalFencePropertiesKHR);
    if(strcmp(pName, "vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR);
    if(strcmp(pName, "vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR);
    if(strcmp(pName, "vkGetPhysicalDeviceSurfaceCapabilities2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceSurfaceCapabilities2KHR);
    if(strcmp(pName, "vkGetPhysicalDeviceSurfaceFormats2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceSurfaceFormats2KHR);
    if(strcmp(pName, "vkGetPhysicalDeviceDisplayProperties2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceDisplayProperties2KHR);
    if(strcmp(pName, "vkGetPhysicalDeviceDisplayPlaneProperties2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceDisplayPlaneProperties2KHR);
    if(strcmp(pName, "vkGetDisplayModeProperties2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDisplayModeProperties2KHR);
    if(strcmp(pName, "vkGetDisplayPlaneCapabilities2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDisplayPlaneCapabilities2KHR);
#if defined(VK_USE_PLATFORM_IOS_MVK)
    if(strcmp(pName, "vkCreateIOSSurfaceMVK") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateIOSSurfaceMVK);
#endif // VK_USE_PLATFORM_IOS_MVK
#if defined(VK_USE_PLATFORM_MACOS_MVK)
    if(strcmp(pName, "vkCreateMacOSSurfaceMVK") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateMacOSSurfaceMVK);
#endif // VK_USE_PLATFORM_MACOS_MVK
    if(strcmp(pName, "vkSetDebugUtilsObjectNameEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetDebugUtilsObjectNameEXT);
    if(strcmp(pName, "vkSetDebugUtilsObjectTagEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetDebugUtilsObjectTagEXT);
    if(strcmp(pName, "vkQueueBeginDebugUtilsLabelEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueBeginDebugUtilsLabelEXT);
    if(strcmp(pName, "vkQueueEndDebugUtilsLabelEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueEndDebugUtilsLabelEXT);
    if(strcmp(pName, "vkQueueInsertDebugUtilsLabelEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueInsertDebugUtilsLabelEXT);
    if(strcmp(pName, "vkCmdBeginDebugUtilsLabelEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginDebugUtilsLabelEXT);
    if(strcmp(pName, "vkCmdEndDebugUtilsLabelEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndDebugUtilsLabelEXT);
    if(strcmp(pName, "vkCmdInsertDebugUtilsLabelEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdInsertDebugUtilsLabelEXT);
    if(strcmp(pName, "vkCreateDebugUtilsMessengerEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDebugUtilsMessengerEXT);
    if(strcmp(pName, "vkDestroyDebugUtilsMessengerEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyDebugUtilsMessengerEXT);
    if(strcmp(pName, "vkSubmitDebugUtilsMessageEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkSubmitDebugUtilsMessageEXT);
    if(strcmp(pName, "vkGetPhysicalDeviceMultisamplePropertiesEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceMultisamplePropertiesEXT);
    if(strcmp(pName, "vkGetPhysicalDeviceCalibrateableTimeDomainsKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceCalibrateableTimeDomainsKHR);
    if(strcmp(pName, "vkGetPhysicalDeviceCalibrateableTimeDomainsEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceCalibrateableTimeDomainsEXT);
#if defined(VK_USE_PLATFORM_FUCHSIA)
    if(strcmp(pName, "vkCreateImagePipeSurfaceFUCHSIA") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateImagePipeSurfaceFUCHSIA);
#endif // VK_USE_PLATFORM_FUCHSIA
#if defined(VK_USE_PLATFORM_METAL_EXT)
    if(strcmp(pName, "vkCreateMetalSurfaceEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateMetalSurfaceEXT);
#endif // VK_USE_PLATFORM_METAL_EXT
    if(strcmp(pName, "vkGetPhysicalDeviceFragmentShadingRatesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceFragmentShadingRatesKHR);
    if(strcmp(pName, "vkGetPhysicalDeviceToolPropertiesEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceToolPropertiesEXT);
    if(strcmp(pName, "vkGetPhysicalDeviceCooperativeMatrixPropertiesNV") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceCooperativeMatrixPropertiesNV);
    if(strcmp(pName, "vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV);
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    if(strcmp(pName, "vkGetPhysicalDeviceSurfacePresentModes2EXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceSurfacePresentModes2EXT);
#endif // VK_USE_PLATFORM_WIN32_KHR
    if(strcmp(pName, "vkCreateHeadlessSurfaceEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateHeadlessSurfaceEXT);
    if(strcmp(pName, "vkAcquireDrmDisplayEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkAcquireDrmDisplayEXT);
    if(strcmp(pName, "vkGetDrmDisplayEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDrmDisplayEXT);
    if(strcmp(pName, "vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR);
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    if(strcmp(pName, "vkAcquireWinrtDisplayNV") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkAcquireWinrtDisplayNV);
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    if(strcmp(pName, "vkGetWinrtDisplayNV") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetWinrtDisplayNV);
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_DIRECTFB_EXT)
    if(strcmp(pName, "vkCreateDirectFBSurfaceEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDirectFBSurfaceEXT);
#endif // VK_USE_PLATFORM_DIRECTFB_EXT
#if defined(VK_USE_PLATFORM_DIRECTFB_EXT)
    if(strcmp(pName, "vkGetPhysicalDeviceDirectFBPresentationSupportEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceDirectFBPresentationSupportEXT);
#endif // VK_USE_PLATFORM_DIRECTFB_EXT
#if defined(VK_USE_PLATFORM_SCREEN_QNX)
    if(strcmp(pName, "vkCreateScreenSurfaceQNX") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateScreenSurfaceQNX);
#endif // VK_USE_PLATFORM_SCREEN_QNX
#if defined(VK_USE_PLATFORM_SCREEN_QNX)
    if(strcmp(pName, "vkGetPhysicalDeviceScreenPresentationSupportQNX") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceScreenPresentationSupportQNX);
#endif // VK_USE_PLATFORM_SCREEN_QNX
    if(strcmp(pName, "vkGetPhysicalDeviceOpticalFlowImageFormatsNV") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceOpticalFlowImageFormatsNV);
    if(strcmp(pName, "vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR);

    return nullptr;
}

VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL api_dump_known_device_functions(VkDevice device, const char* pName)
{

    if(strcmp(pName, "vkGetDeviceProcAddr") == 0 && (!device || device_dispatch_table(device)->GetDeviceProcAddr))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceProcAddr);
    if(strcmp(pName, "vkDestroyDevice") == 0 && (!device || device_dispatch_table(device)->DestroyDevice))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyDevice);
    if(strcmp(pName, "vkGetDeviceQueue") == 0 && (!device || device_dispatch_table(device)->GetDeviceQueue))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceQueue);
    if(strcmp(pName, "vkQueueSubmit") == 0 && (!device || device_dispatch_table(device)->QueueSubmit))
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueSubmit);
    if(strcmp(pName, "vkQueueWaitIdle") == 0 && (!device || device_dispatch_table(device)->QueueWaitIdle))
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueWaitIdle);
    if(strcmp(pName, "vkDeviceWaitIdle") == 0 && (!device || device_dispatch_table(device)->DeviceWaitIdle))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDeviceWaitIdle);
    if(strcmp(pName, "vkAllocateMemory") == 0 && (!device || device_dispatch_table(device)->AllocateMemory))
        return reinterpret_cast<PFN_vkVoidFunction>(vkAllocateMemory);
    if(strcmp(pName, "vkFreeMemory") == 0 && (!device || device_dispatch_table(device)->FreeMemory))
        return reinterpret_cast<PFN_vkVoidFunction>(vkFreeMemory);
    if(strcmp(pName, "vkMapMemory") == 0 && (!device || device_dispatch_table(device)->MapMemory))
        return reinterpret_cast<PFN_vkVoidFunction>(vkMapMemory);
    if(strcmp(pName, "vkUnmapMemory") == 0 && (!device || device_dispatch_table(device)->UnmapMemory))
        return reinterpret_cast<PFN_vkVoidFunction>(vkUnmapMemory);
    if(strcmp(pName, "vkFlushMappedMemoryRanges") == 0 && (!device || device_dispatch_table(device)->FlushMappedMemoryRanges))
        return reinterpret_cast<PFN_vkVoidFunction>(vkFlushMappedMemoryRanges);
    if(strcmp(pName, "vkInvalidateMappedMemoryRanges") == 0 && (!device || device_dispatch_table(device)->InvalidateMappedMemoryRanges))
        return reinterpret_cast<PFN_vkVoidFunction>(vkInvalidateMappedMemoryRanges);
    if(strcmp(pName, "vkGetDeviceMemoryCommitment") == 0 && (!device || device_dispatch_table(device)->GetDeviceMemoryCommitment))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceMemoryCommitment);
    if(strcmp(pName, "vkBindBufferMemory") == 0 && (!device || device_dispatch_table(device)->BindBufferMemory))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBindBufferMemory);
    if(strcmp(pName, "vkBindImageMemory") == 0 && (!device || device_dispatch_table(device)->BindImageMemory))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBindImageMemory);
    if(strcmp(pName, "vkGetBufferMemoryRequirements") == 0 && (!device || device_dispatch_table(device)->GetBufferMemoryRequirements))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetBufferMemoryRequirements);
    if(strcmp(pName, "vkGetImageMemoryRequirements") == 0 && (!device || device_dispatch_table(device)->GetImageMemoryRequirements))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageMemoryRequirements);
    if(strcmp(pName, "vkGetImageSparseMemoryRequirements") == 0 && (!device || device_dispatch_table(device)->GetImageSparseMemoryRequirements))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageSparseMemoryRequirements);
    if(strcmp(pName, "vkQueueBindSparse") == 0 && (!device || device_dispatch_table(device)->QueueBindSparse))
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueBindSparse);
    if(strcmp(pName, "vkCreateFence") == 0 && (!device || device_dispatch_table(device)->CreateFence))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateFence);
    if(strcmp(pName, "vkDestroyFence") == 0 && (!device || device_dispatch_table(device)->DestroyFence))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyFence);
    if(strcmp(pName, "vkResetFences") == 0 && (!device || device_dispatch_table(device)->ResetFences))
        return reinterpret_cast<PFN_vkVoidFunction>(vkResetFences);
    if(strcmp(pName, "vkGetFenceStatus") == 0 && (!device || device_dispatch_table(device)->GetFenceStatus))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetFenceStatus);
    if(strcmp(pName, "vkWaitForFences") == 0 && (!device || device_dispatch_table(device)->WaitForFences))
        return reinterpret_cast<PFN_vkVoidFunction>(vkWaitForFences);
    if(strcmp(pName, "vkCreateSemaphore") == 0 && (!device || device_dispatch_table(device)->CreateSemaphore))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateSemaphore);
    if(strcmp(pName, "vkDestroySemaphore") == 0 && (!device || device_dispatch_table(device)->DestroySemaphore))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroySemaphore);
    if(strcmp(pName, "vkCreateEvent") == 0 && (!device || device_dispatch_table(device)->CreateEvent))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateEvent);
    if(strcmp(pName, "vkDestroyEvent") == 0 && (!device || device_dispatch_table(device)->DestroyEvent))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyEvent);
    if(strcmp(pName, "vkGetEventStatus") == 0 && (!device || device_dispatch_table(device)->GetEventStatus))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetEventStatus);
    if(strcmp(pName, "vkSetEvent") == 0 && (!device || device_dispatch_table(device)->SetEvent))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetEvent);
    if(strcmp(pName, "vkResetEvent") == 0 && (!device || device_dispatch_table(device)->ResetEvent))
        return reinterpret_cast<PFN_vkVoidFunction>(vkResetEvent);
    if(strcmp(pName, "vkCreateQueryPool") == 0 && (!device || device_dispatch_table(device)->CreateQueryPool))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateQueryPool);
    if(strcmp(pName, "vkDestroyQueryPool") == 0 && (!device || device_dispatch_table(device)->DestroyQueryPool))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyQueryPool);
    if(strcmp(pName, "vkGetQueryPoolResults") == 0 && (!device || device_dispatch_table(device)->GetQueryPoolResults))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetQueryPoolResults);
    if(strcmp(pName, "vkCreateBuffer") == 0 && (!device || device_dispatch_table(device)->CreateBuffer))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateBuffer);
    if(strcmp(pName, "vkDestroyBuffer") == 0 && (!device || device_dispatch_table(device)->DestroyBuffer))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyBuffer);
    if(strcmp(pName, "vkCreateBufferView") == 0 && (!device || device_dispatch_table(device)->CreateBufferView))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateBufferView);
    if(strcmp(pName, "vkDestroyBufferView") == 0 && (!device || device_dispatch_table(device)->DestroyBufferView))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyBufferView);
    if(strcmp(pName, "vkCreateImage") == 0 && (!device || device_dispatch_table(device)->CreateImage))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateImage);
    if(strcmp(pName, "vkDestroyImage") == 0 && (!device || device_dispatch_table(device)->DestroyImage))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyImage);
    if(strcmp(pName, "vkGetImageSubresourceLayout") == 0 && (!device || device_dispatch_table(device)->GetImageSubresourceLayout))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageSubresourceLayout);
    if(strcmp(pName, "vkCreateImageView") == 0 && (!device || device_dispatch_table(device)->CreateImageView))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateImageView);
    if(strcmp(pName, "vkDestroyImageView") == 0 && (!device || device_dispatch_table(device)->DestroyImageView))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyImageView);
    if(strcmp(pName, "vkCreateShaderModule") == 0 && (!device || device_dispatch_table(device)->CreateShaderModule))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateShaderModule);
    if(strcmp(pName, "vkDestroyShaderModule") == 0 && (!device || device_dispatch_table(device)->DestroyShaderModule))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyShaderModule);
    if(strcmp(pName, "vkCreatePipelineCache") == 0 && (!device || device_dispatch_table(device)->CreatePipelineCache))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreatePipelineCache);
    if(strcmp(pName, "vkDestroyPipelineCache") == 0 && (!device || device_dispatch_table(device)->DestroyPipelineCache))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyPipelineCache);
    if(strcmp(pName, "vkGetPipelineCacheData") == 0 && (!device || device_dispatch_table(device)->GetPipelineCacheData))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPipelineCacheData);
    if(strcmp(pName, "vkMergePipelineCaches") == 0 && (!device || device_dispatch_table(device)->MergePipelineCaches))
        return reinterpret_cast<PFN_vkVoidFunction>(vkMergePipelineCaches);
    if(strcmp(pName, "vkCreateGraphicsPipelines") == 0 && (!device || device_dispatch_table(device)->CreateGraphicsPipelines))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateGraphicsPipelines);
    if(strcmp(pName, "vkCreateComputePipelines") == 0 && (!device || device_dispatch_table(device)->CreateComputePipelines))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateComputePipelines);
    if(strcmp(pName, "vkDestroyPipeline") == 0 && (!device || device_dispatch_table(device)->DestroyPipeline))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyPipeline);
    if(strcmp(pName, "vkCreatePipelineLayout") == 0 && (!device || device_dispatch_table(device)->CreatePipelineLayout))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreatePipelineLayout);
    if(strcmp(pName, "vkDestroyPipelineLayout") == 0 && (!device || device_dispatch_table(device)->DestroyPipelineLayout))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyPipelineLayout);
    if(strcmp(pName, "vkCreateSampler") == 0 && (!device || device_dispatch_table(device)->CreateSampler))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateSampler);
    if(strcmp(pName, "vkDestroySampler") == 0 && (!device || device_dispatch_table(device)->DestroySampler))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroySampler);
    if(strcmp(pName, "vkCreateDescriptorSetLayout") == 0 && (!device || device_dispatch_table(device)->CreateDescriptorSetLayout))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDescriptorSetLayout);
    if(strcmp(pName, "vkDestroyDescriptorSetLayout") == 0 && (!device || device_dispatch_table(device)->DestroyDescriptorSetLayout))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyDescriptorSetLayout);
    if(strcmp(pName, "vkCreateDescriptorPool") == 0 && (!device || device_dispatch_table(device)->CreateDescriptorPool))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDescriptorPool);
    if(strcmp(pName, "vkDestroyDescriptorPool") == 0 && (!device || device_dispatch_table(device)->DestroyDescriptorPool))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyDescriptorPool);
    if(strcmp(pName, "vkResetDescriptorPool") == 0 && (!device || device_dispatch_table(device)->ResetDescriptorPool))
        return reinterpret_cast<PFN_vkVoidFunction>(vkResetDescriptorPool);
    if(strcmp(pName, "vkAllocateDescriptorSets") == 0 && (!device || device_dispatch_table(device)->AllocateDescriptorSets))
        return reinterpret_cast<PFN_vkVoidFunction>(vkAllocateDescriptorSets);
    if(strcmp(pName, "vkFreeDescriptorSets") == 0 && (!device || device_dispatch_table(device)->FreeDescriptorSets))
        return reinterpret_cast<PFN_vkVoidFunction>(vkFreeDescriptorSets);
    if(strcmp(pName, "vkUpdateDescriptorSets") == 0 && (!device || device_dispatch_table(device)->UpdateDescriptorSets))
        return reinterpret_cast<PFN_vkVoidFunction>(vkUpdateDescriptorSets);
    if(strcmp(pName, "vkCreateFramebuffer") == 0 && (!device || device_dispatch_table(device)->CreateFramebuffer))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateFramebuffer);
    if(strcmp(pName, "vkDestroyFramebuffer") == 0 && (!device || device_dispatch_table(device)->DestroyFramebuffer))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyFramebuffer);
    if(strcmp(pName, "vkCreateRenderPass") == 0 && (!device || device_dispatch_table(device)->CreateRenderPass))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateRenderPass);
    if(strcmp(pName, "vkDestroyRenderPass") == 0 && (!device || device_dispatch_table(device)->DestroyRenderPass))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyRenderPass);
    if(strcmp(pName, "vkGetRenderAreaGranularity") == 0 && (!device || device_dispatch_table(device)->GetRenderAreaGranularity))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetRenderAreaGranularity);
    if(strcmp(pName, "vkCreateCommandPool") == 0 && (!device || device_dispatch_table(device)->CreateCommandPool))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateCommandPool);
    if(strcmp(pName, "vkDestroyCommandPool") == 0 && (!device || device_dispatch_table(device)->DestroyCommandPool))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyCommandPool);
    if(strcmp(pName, "vkResetCommandPool") == 0 && (!device || device_dispatch_table(device)->ResetCommandPool))
        return reinterpret_cast<PFN_vkVoidFunction>(vkResetCommandPool);
    if(strcmp(pName, "vkAllocateCommandBuffers") == 0 && (!device || device_dispatch_table(device)->AllocateCommandBuffers))
        return reinterpret_cast<PFN_vkVoidFunction>(vkAllocateCommandBuffers);
    if(strcmp(pName, "vkFreeCommandBuffers") == 0 && (!device || device_dispatch_table(device)->FreeCommandBuffers))
        return reinterpret_cast<PFN_vkVoidFunction>(vkFreeCommandBuffers);
    if(strcmp(pName, "vkBeginCommandBuffer") == 0 && (!device || device_dispatch_table(device)->BeginCommandBuffer))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBeginCommandBuffer);
    if(strcmp(pName, "vkEndCommandBuffer") == 0 && (!device || device_dispatch_table(device)->EndCommandBuffer))
        return reinterpret_cast<PFN_vkVoidFunction>(vkEndCommandBuffer);
    if(strcmp(pName, "vkResetCommandBuffer") == 0 && (!device || device_dispatch_table(device)->ResetCommandBuffer))
        return reinterpret_cast<PFN_vkVoidFunction>(vkResetCommandBuffer);
    if(strcmp(pName, "vkCmdBindPipeline") == 0 && (!device || device_dispatch_table(device)->CmdBindPipeline))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindPipeline);
    if(strcmp(pName, "vkCmdSetViewport") == 0 && (!device || device_dispatch_table(device)->CmdSetViewport))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetViewport);
    if(strcmp(pName, "vkCmdSetScissor") == 0 && (!device || device_dispatch_table(device)->CmdSetScissor))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetScissor);
    if(strcmp(pName, "vkCmdSetLineWidth") == 0 && (!device || device_dispatch_table(device)->CmdSetLineWidth))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetLineWidth);
    if(strcmp(pName, "vkCmdSetDepthBias") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthBias))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthBias);
    if(strcmp(pName, "vkCmdSetBlendConstants") == 0 && (!device || device_dispatch_table(device)->CmdSetBlendConstants))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetBlendConstants);
    if(strcmp(pName, "vkCmdSetDepthBounds") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthBounds))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthBounds);
    if(strcmp(pName, "vkCmdSetStencilCompareMask") == 0 && (!device || device_dispatch_table(device)->CmdSetStencilCompareMask))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetStencilCompareMask);
    if(strcmp(pName, "vkCmdSetStencilWriteMask") == 0 && (!device || device_dispatch_table(device)->CmdSetStencilWriteMask))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetStencilWriteMask);
    if(strcmp(pName, "vkCmdSetStencilReference") == 0 && (!device || device_dispatch_table(device)->CmdSetStencilReference))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetStencilReference);
    if(strcmp(pName, "vkCmdBindDescriptorSets") == 0 && (!device || device_dispatch_table(device)->CmdBindDescriptorSets))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindDescriptorSets);
    if(strcmp(pName, "vkCmdBindIndexBuffer") == 0 && (!device || device_dispatch_table(device)->CmdBindIndexBuffer))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindIndexBuffer);
    if(strcmp(pName, "vkCmdBindVertexBuffers") == 0 && (!device || device_dispatch_table(device)->CmdBindVertexBuffers))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindVertexBuffers);
    if(strcmp(pName, "vkCmdDraw") == 0 && (!device || device_dispatch_table(device)->CmdDraw))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDraw);
    if(strcmp(pName, "vkCmdDrawIndexed") == 0 && (!device || device_dispatch_table(device)->CmdDrawIndexed))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawIndexed);
    if(strcmp(pName, "vkCmdDrawIndirect") == 0 && (!device || device_dispatch_table(device)->CmdDrawIndirect))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawIndirect);
    if(strcmp(pName, "vkCmdDrawIndexedIndirect") == 0 && (!device || device_dispatch_table(device)->CmdDrawIndexedIndirect))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawIndexedIndirect);
    if(strcmp(pName, "vkCmdDispatch") == 0 && (!device || device_dispatch_table(device)->CmdDispatch))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDispatch);
    if(strcmp(pName, "vkCmdDispatchIndirect") == 0 && (!device || device_dispatch_table(device)->CmdDispatchIndirect))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDispatchIndirect);
    if(strcmp(pName, "vkCmdCopyBuffer") == 0 && (!device || device_dispatch_table(device)->CmdCopyBuffer))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyBuffer);
    if(strcmp(pName, "vkCmdCopyImage") == 0 && (!device || device_dispatch_table(device)->CmdCopyImage))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyImage);
    if(strcmp(pName, "vkCmdBlitImage") == 0 && (!device || device_dispatch_table(device)->CmdBlitImage))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBlitImage);
    if(strcmp(pName, "vkCmdCopyBufferToImage") == 0 && (!device || device_dispatch_table(device)->CmdCopyBufferToImage))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyBufferToImage);
    if(strcmp(pName, "vkCmdCopyImageToBuffer") == 0 && (!device || device_dispatch_table(device)->CmdCopyImageToBuffer))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyImageToBuffer);
    if(strcmp(pName, "vkCmdUpdateBuffer") == 0 && (!device || device_dispatch_table(device)->CmdUpdateBuffer))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdUpdateBuffer);
    if(strcmp(pName, "vkCmdFillBuffer") == 0 && (!device || device_dispatch_table(device)->CmdFillBuffer))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdFillBuffer);
    if(strcmp(pName, "vkCmdClearColorImage") == 0 && (!device || device_dispatch_table(device)->CmdClearColorImage))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdClearColorImage);
    if(strcmp(pName, "vkCmdClearDepthStencilImage") == 0 && (!device || device_dispatch_table(device)->CmdClearDepthStencilImage))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdClearDepthStencilImage);
    if(strcmp(pName, "vkCmdClearAttachments") == 0 && (!device || device_dispatch_table(device)->CmdClearAttachments))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdClearAttachments);
    if(strcmp(pName, "vkCmdResolveImage") == 0 && (!device || device_dispatch_table(device)->CmdResolveImage))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdResolveImage);
    if(strcmp(pName, "vkCmdSetEvent") == 0 && (!device || device_dispatch_table(device)->CmdSetEvent))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetEvent);
    if(strcmp(pName, "vkCmdResetEvent") == 0 && (!device || device_dispatch_table(device)->CmdResetEvent))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdResetEvent);
    if(strcmp(pName, "vkCmdWaitEvents") == 0 && (!device || device_dispatch_table(device)->CmdWaitEvents))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdWaitEvents);
    if(strcmp(pName, "vkCmdPipelineBarrier") == 0 && (!device || device_dispatch_table(device)->CmdPipelineBarrier))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPipelineBarrier);
    if(strcmp(pName, "vkCmdBeginQuery") == 0 && (!device || device_dispatch_table(device)->CmdBeginQuery))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginQuery);
    if(strcmp(pName, "vkCmdEndQuery") == 0 && (!device || device_dispatch_table(device)->CmdEndQuery))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndQuery);
    if(strcmp(pName, "vkCmdResetQueryPool") == 0 && (!device || device_dispatch_table(device)->CmdResetQueryPool))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdResetQueryPool);
    if(strcmp(pName, "vkCmdWriteTimestamp") == 0 && (!device || device_dispatch_table(device)->CmdWriteTimestamp))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdWriteTimestamp);
    if(strcmp(pName, "vkCmdCopyQueryPoolResults") == 0 && (!device || device_dispatch_table(device)->CmdCopyQueryPoolResults))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyQueryPoolResults);
    if(strcmp(pName, "vkCmdPushConstants") == 0 && (!device || device_dispatch_table(device)->CmdPushConstants))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPushConstants);
    if(strcmp(pName, "vkCmdBeginRenderPass") == 0 && (!device || device_dispatch_table(device)->CmdBeginRenderPass))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginRenderPass);
    if(strcmp(pName, "vkCmdNextSubpass") == 0 && (!device || device_dispatch_table(device)->CmdNextSubpass))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdNextSubpass);
    if(strcmp(pName, "vkCmdEndRenderPass") == 0 && (!device || device_dispatch_table(device)->CmdEndRenderPass))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndRenderPass);
    if(strcmp(pName, "vkCmdExecuteCommands") == 0 && (!device || device_dispatch_table(device)->CmdExecuteCommands))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdExecuteCommands);
    if(strcmp(pName, "vkBindBufferMemory2") == 0 && (!device || device_dispatch_table(device)->BindBufferMemory2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBindBufferMemory2);
    if(strcmp(pName, "vkBindImageMemory2") == 0 && (!device || device_dispatch_table(device)->BindImageMemory2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBindImageMemory2);
    if(strcmp(pName, "vkGetDeviceGroupPeerMemoryFeatures") == 0 && (!device || device_dispatch_table(device)->GetDeviceGroupPeerMemoryFeatures))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceGroupPeerMemoryFeatures);
    if(strcmp(pName, "vkCmdSetDeviceMask") == 0 && (!device || device_dispatch_table(device)->CmdSetDeviceMask))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDeviceMask);
    if(strcmp(pName, "vkCmdDispatchBase") == 0 && (!device || device_dispatch_table(device)->CmdDispatchBase))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDispatchBase);
    if(strcmp(pName, "vkGetImageMemoryRequirements2") == 0 && (!device || device_dispatch_table(device)->GetImageMemoryRequirements2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageMemoryRequirements2);
    if(strcmp(pName, "vkGetBufferMemoryRequirements2") == 0 && (!device || device_dispatch_table(device)->GetBufferMemoryRequirements2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetBufferMemoryRequirements2);
    if(strcmp(pName, "vkGetImageSparseMemoryRequirements2") == 0 && (!device || device_dispatch_table(device)->GetImageSparseMemoryRequirements2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageSparseMemoryRequirements2);
    if(strcmp(pName, "vkTrimCommandPool") == 0 && (!device || device_dispatch_table(device)->TrimCommandPool))
        return reinterpret_cast<PFN_vkVoidFunction>(vkTrimCommandPool);
    if(strcmp(pName, "vkGetDeviceQueue2") == 0 && (!device || device_dispatch_table(device)->GetDeviceQueue2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceQueue2);
    if(strcmp(pName, "vkCreateSamplerYcbcrConversion") == 0 && (!device || device_dispatch_table(device)->CreateSamplerYcbcrConversion))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateSamplerYcbcrConversion);
    if(strcmp(pName, "vkDestroySamplerYcbcrConversion") == 0 && (!device || device_dispatch_table(device)->DestroySamplerYcbcrConversion))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroySamplerYcbcrConversion);
    if(strcmp(pName, "vkCreateDescriptorUpdateTemplate") == 0 && (!device || device_dispatch_table(device)->CreateDescriptorUpdateTemplate))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDescriptorUpdateTemplate);
    if(strcmp(pName, "vkDestroyDescriptorUpdateTemplate") == 0 && (!device || device_dispatch_table(device)->DestroyDescriptorUpdateTemplate))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyDescriptorUpdateTemplate);
    if(strcmp(pName, "vkUpdateDescriptorSetWithTemplate") == 0 && (!device || device_dispatch_table(device)->UpdateDescriptorSetWithTemplate))
        return reinterpret_cast<PFN_vkVoidFunction>(vkUpdateDescriptorSetWithTemplate);
    if(strcmp(pName, "vkGetDescriptorSetLayoutSupport") == 0 && (!device || device_dispatch_table(device)->GetDescriptorSetLayoutSupport))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDescriptorSetLayoutSupport);
    if(strcmp(pName, "vkCmdDrawIndirectCount") == 0 && (!device || device_dispatch_table(device)->CmdDrawIndirectCount))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawIndirectCount);
    if(strcmp(pName, "vkCmdDrawIndexedIndirectCount") == 0 && (!device || device_dispatch_table(device)->CmdDrawIndexedIndirectCount))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawIndexedIndirectCount);
    if(strcmp(pName, "vkCreateRenderPass2") == 0 && (!device || device_dispatch_table(device)->CreateRenderPass2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateRenderPass2);
    if(strcmp(pName, "vkCmdBeginRenderPass2") == 0 && (!device || device_dispatch_table(device)->CmdBeginRenderPass2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginRenderPass2);
    if(strcmp(pName, "vkCmdNextSubpass2") == 0 && (!device || device_dispatch_table(device)->CmdNextSubpass2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdNextSubpass2);
    if(strcmp(pName, "vkCmdEndRenderPass2") == 0 && (!device || device_dispatch_table(device)->CmdEndRenderPass2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndRenderPass2);
    if(strcmp(pName, "vkResetQueryPool") == 0 && (!device || device_dispatch_table(device)->ResetQueryPool))
        return reinterpret_cast<PFN_vkVoidFunction>(vkResetQueryPool);
    if(strcmp(pName, "vkGetSemaphoreCounterValue") == 0 && (!device || device_dispatch_table(device)->GetSemaphoreCounterValue))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetSemaphoreCounterValue);
    if(strcmp(pName, "vkWaitSemaphores") == 0 && (!device || device_dispatch_table(device)->WaitSemaphores))
        return reinterpret_cast<PFN_vkVoidFunction>(vkWaitSemaphores);
    if(strcmp(pName, "vkSignalSemaphore") == 0 && (!device || device_dispatch_table(device)->SignalSemaphore))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSignalSemaphore);
    if(strcmp(pName, "vkGetBufferDeviceAddress") == 0 && (!device || device_dispatch_table(device)->GetBufferDeviceAddress))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetBufferDeviceAddress);
    if(strcmp(pName, "vkGetBufferOpaqueCaptureAddress") == 0 && (!device || device_dispatch_table(device)->GetBufferOpaqueCaptureAddress))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetBufferOpaqueCaptureAddress);
    if(strcmp(pName, "vkGetDeviceMemoryOpaqueCaptureAddress") == 0 && (!device || device_dispatch_table(device)->GetDeviceMemoryOpaqueCaptureAddress))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceMemoryOpaqueCaptureAddress);
    if(strcmp(pName, "vkCreatePrivateDataSlot") == 0 && (!device || device_dispatch_table(device)->CreatePrivateDataSlot))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreatePrivateDataSlot);
    if(strcmp(pName, "vkDestroyPrivateDataSlot") == 0 && (!device || device_dispatch_table(device)->DestroyPrivateDataSlot))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyPrivateDataSlot);
    if(strcmp(pName, "vkSetPrivateData") == 0 && (!device || device_dispatch_table(device)->SetPrivateData))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetPrivateData);
    if(strcmp(pName, "vkGetPrivateData") == 0 && (!device || device_dispatch_table(device)->GetPrivateData))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPrivateData);
    if(strcmp(pName, "vkCmdSetEvent2") == 0 && (!device || device_dispatch_table(device)->CmdSetEvent2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetEvent2);
    if(strcmp(pName, "vkCmdResetEvent2") == 0 && (!device || device_dispatch_table(device)->CmdResetEvent2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdResetEvent2);
    if(strcmp(pName, "vkCmdWaitEvents2") == 0 && (!device || device_dispatch_table(device)->CmdWaitEvents2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdWaitEvents2);
    if(strcmp(pName, "vkCmdPipelineBarrier2") == 0 && (!device || device_dispatch_table(device)->CmdPipelineBarrier2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPipelineBarrier2);
    if(strcmp(pName, "vkCmdWriteTimestamp2") == 0 && (!device || device_dispatch_table(device)->CmdWriteTimestamp2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdWriteTimestamp2);
    if(strcmp(pName, "vkQueueSubmit2") == 0 && (!device || device_dispatch_table(device)->QueueSubmit2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueSubmit2);
    if(strcmp(pName, "vkCmdCopyBuffer2") == 0 && (!device || device_dispatch_table(device)->CmdCopyBuffer2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyBuffer2);
    if(strcmp(pName, "vkCmdCopyImage2") == 0 && (!device || device_dispatch_table(device)->CmdCopyImage2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyImage2);
    if(strcmp(pName, "vkCmdCopyBufferToImage2") == 0 && (!device || device_dispatch_table(device)->CmdCopyBufferToImage2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyBufferToImage2);
    if(strcmp(pName, "vkCmdCopyImageToBuffer2") == 0 && (!device || device_dispatch_table(device)->CmdCopyImageToBuffer2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyImageToBuffer2);
    if(strcmp(pName, "vkCmdBlitImage2") == 0 && (!device || device_dispatch_table(device)->CmdBlitImage2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBlitImage2);
    if(strcmp(pName, "vkCmdResolveImage2") == 0 && (!device || device_dispatch_table(device)->CmdResolveImage2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdResolveImage2);
    if(strcmp(pName, "vkCmdBeginRendering") == 0 && (!device || device_dispatch_table(device)->CmdBeginRendering))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginRendering);
    if(strcmp(pName, "vkCmdEndRendering") == 0 && (!device || device_dispatch_table(device)->CmdEndRendering))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndRendering);
    if(strcmp(pName, "vkCmdSetCullMode") == 0 && (!device || device_dispatch_table(device)->CmdSetCullMode))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetCullMode);
    if(strcmp(pName, "vkCmdSetFrontFace") == 0 && (!device || device_dispatch_table(device)->CmdSetFrontFace))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetFrontFace);
    if(strcmp(pName, "vkCmdSetPrimitiveTopology") == 0 && (!device || device_dispatch_table(device)->CmdSetPrimitiveTopology))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetPrimitiveTopology);
    if(strcmp(pName, "vkCmdSetViewportWithCount") == 0 && (!device || device_dispatch_table(device)->CmdSetViewportWithCount))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetViewportWithCount);
    if(strcmp(pName, "vkCmdSetScissorWithCount") == 0 && (!device || device_dispatch_table(device)->CmdSetScissorWithCount))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetScissorWithCount);
    if(strcmp(pName, "vkCmdBindVertexBuffers2") == 0 && (!device || device_dispatch_table(device)->CmdBindVertexBuffers2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindVertexBuffers2);
    if(strcmp(pName, "vkCmdSetDepthTestEnable") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthTestEnable))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthTestEnable);
    if(strcmp(pName, "vkCmdSetDepthWriteEnable") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthWriteEnable))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthWriteEnable);
    if(strcmp(pName, "vkCmdSetDepthCompareOp") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthCompareOp))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthCompareOp);
    if(strcmp(pName, "vkCmdSetDepthBoundsTestEnable") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthBoundsTestEnable))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthBoundsTestEnable);
    if(strcmp(pName, "vkCmdSetStencilTestEnable") == 0 && (!device || device_dispatch_table(device)->CmdSetStencilTestEnable))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetStencilTestEnable);
    if(strcmp(pName, "vkCmdSetStencilOp") == 0 && (!device || device_dispatch_table(device)->CmdSetStencilOp))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetStencilOp);
    if(strcmp(pName, "vkCmdSetRasterizerDiscardEnable") == 0 && (!device || device_dispatch_table(device)->CmdSetRasterizerDiscardEnable))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetRasterizerDiscardEnable);
    if(strcmp(pName, "vkCmdSetDepthBiasEnable") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthBiasEnable))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthBiasEnable);
    if(strcmp(pName, "vkCmdSetPrimitiveRestartEnable") == 0 && (!device || device_dispatch_table(device)->CmdSetPrimitiveRestartEnable))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetPrimitiveRestartEnable);
    if(strcmp(pName, "vkGetDeviceBufferMemoryRequirements") == 0 && (!device || device_dispatch_table(device)->GetDeviceBufferMemoryRequirements))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceBufferMemoryRequirements);
    if(strcmp(pName, "vkGetDeviceImageMemoryRequirements") == 0 && (!device || device_dispatch_table(device)->GetDeviceImageMemoryRequirements))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceImageMemoryRequirements);
    if(strcmp(pName, "vkGetDeviceImageSparseMemoryRequirements") == 0 && (!device || device_dispatch_table(device)->GetDeviceImageSparseMemoryRequirements))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceImageSparseMemoryRequirements);
    if(strcmp(pName, "vkCreateSwapchainKHR") == 0 && (!device || device_dispatch_table(device)->CreateSwapchainKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateSwapchainKHR);
    if(strcmp(pName, "vkDestroySwapchainKHR") == 0 && (!device || device_dispatch_table(device)->DestroySwapchainKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroySwapchainKHR);
    if(strcmp(pName, "vkGetSwapchainImagesKHR") == 0 && (!device || device_dispatch_table(device)->GetSwapchainImagesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetSwapchainImagesKHR);
    if(strcmp(pName, "vkAcquireNextImageKHR") == 0 && (!device || device_dispatch_table(device)->AcquireNextImageKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkAcquireNextImageKHR);
    if(strcmp(pName, "vkQueuePresentKHR") == 0 && (!device || device_dispatch_table(device)->QueuePresentKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueuePresentKHR);
    if(strcmp(pName, "vkGetDeviceGroupPresentCapabilitiesKHR") == 0 && (!device || device_dispatch_table(device)->GetDeviceGroupPresentCapabilitiesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceGroupPresentCapabilitiesKHR);
    if(strcmp(pName, "vkGetDeviceGroupSurfacePresentModesKHR") == 0 && (!device || device_dispatch_table(device)->GetDeviceGroupSurfacePresentModesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceGroupSurfacePresentModesKHR);
    if(strcmp(pName, "vkAcquireNextImage2KHR") == 0 && (!device || device_dispatch_table(device)->AcquireNextImage2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkAcquireNextImage2KHR);
    if(strcmp(pName, "vkCreateSharedSwapchainsKHR") == 0 && (!device || device_dispatch_table(device)->CreateSharedSwapchainsKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateSharedSwapchainsKHR);
    if(strcmp(pName, "vkDebugMarkerSetObjectTagEXT") == 0 && (!device || device_dispatch_table(device)->DebugMarkerSetObjectTagEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDebugMarkerSetObjectTagEXT);
    if(strcmp(pName, "vkDebugMarkerSetObjectNameEXT") == 0 && (!device || device_dispatch_table(device)->DebugMarkerSetObjectNameEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDebugMarkerSetObjectNameEXT);
    if(strcmp(pName, "vkCmdDebugMarkerBeginEXT") == 0 && (!device || device_dispatch_table(device)->CmdDebugMarkerBeginEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDebugMarkerBeginEXT);
    if(strcmp(pName, "vkCmdDebugMarkerEndEXT") == 0 && (!device || device_dispatch_table(device)->CmdDebugMarkerEndEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDebugMarkerEndEXT);
    if(strcmp(pName, "vkCmdDebugMarkerInsertEXT") == 0 && (!device || device_dispatch_table(device)->CmdDebugMarkerInsertEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDebugMarkerInsertEXT);
    if(strcmp(pName, "vkCreateVideoSessionKHR") == 0 && (!device || device_dispatch_table(device)->CreateVideoSessionKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateVideoSessionKHR);
    if(strcmp(pName, "vkDestroyVideoSessionKHR") == 0 && (!device || device_dispatch_table(device)->DestroyVideoSessionKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyVideoSessionKHR);
    if(strcmp(pName, "vkGetVideoSessionMemoryRequirementsKHR") == 0 && (!device || device_dispatch_table(device)->GetVideoSessionMemoryRequirementsKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetVideoSessionMemoryRequirementsKHR);
    if(strcmp(pName, "vkBindVideoSessionMemoryKHR") == 0 && (!device || device_dispatch_table(device)->BindVideoSessionMemoryKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBindVideoSessionMemoryKHR);
    if(strcmp(pName, "vkCreateVideoSessionParametersKHR") == 0 && (!device || device_dispatch_table(device)->CreateVideoSessionParametersKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateVideoSessionParametersKHR);
    if(strcmp(pName, "vkUpdateVideoSessionParametersKHR") == 0 && (!device || device_dispatch_table(device)->UpdateVideoSessionParametersKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkUpdateVideoSessionParametersKHR);
    if(strcmp(pName, "vkDestroyVideoSessionParametersKHR") == 0 && (!device || device_dispatch_table(device)->DestroyVideoSessionParametersKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyVideoSessionParametersKHR);
    if(strcmp(pName, "vkCmdBeginVideoCodingKHR") == 0 && (!device || device_dispatch_table(device)->CmdBeginVideoCodingKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginVideoCodingKHR);
    if(strcmp(pName, "vkCmdEndVideoCodingKHR") == 0 && (!device || device_dispatch_table(device)->CmdEndVideoCodingKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndVideoCodingKHR);
    if(strcmp(pName, "vkCmdControlVideoCodingKHR") == 0 && (!device || device_dispatch_table(device)->CmdControlVideoCodingKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdControlVideoCodingKHR);
    if(strcmp(pName, "vkCmdDecodeVideoKHR") == 0 && (!device || device_dispatch_table(device)->CmdDecodeVideoKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDecodeVideoKHR);
    if(strcmp(pName, "vkCmdBindTransformFeedbackBuffersEXT") == 0 && (!device || device_dispatch_table(device)->CmdBindTransformFeedbackBuffersEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindTransformFeedbackBuffersEXT);
    if(strcmp(pName, "vkCmdBeginTransformFeedbackEXT") == 0 && (!device || device_dispatch_table(device)->CmdBeginTransformFeedbackEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginTransformFeedbackEXT);
    if(strcmp(pName, "vkCmdEndTransformFeedbackEXT") == 0 && (!device || device_dispatch_table(device)->CmdEndTransformFeedbackEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndTransformFeedbackEXT);
    if(strcmp(pName, "vkCmdBeginQueryIndexedEXT") == 0 && (!device || device_dispatch_table(device)->CmdBeginQueryIndexedEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginQueryIndexedEXT);
    if(strcmp(pName, "vkCmdEndQueryIndexedEXT") == 0 && (!device || device_dispatch_table(device)->CmdEndQueryIndexedEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndQueryIndexedEXT);
    if(strcmp(pName, "vkCmdDrawIndirectByteCountEXT") == 0 && (!device || device_dispatch_table(device)->CmdDrawIndirectByteCountEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawIndirectByteCountEXT);
    if(strcmp(pName, "vkCreateCuModuleNVX") == 0 && (!device || device_dispatch_table(device)->CreateCuModuleNVX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateCuModuleNVX);
    if(strcmp(pName, "vkCreateCuFunctionNVX") == 0 && (!device || device_dispatch_table(device)->CreateCuFunctionNVX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateCuFunctionNVX);
    if(strcmp(pName, "vkDestroyCuModuleNVX") == 0 && (!device || device_dispatch_table(device)->DestroyCuModuleNVX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyCuModuleNVX);
    if(strcmp(pName, "vkDestroyCuFunctionNVX") == 0 && (!device || device_dispatch_table(device)->DestroyCuFunctionNVX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyCuFunctionNVX);
    if(strcmp(pName, "vkCmdCuLaunchKernelNVX") == 0 && (!device || device_dispatch_table(device)->CmdCuLaunchKernelNVX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCuLaunchKernelNVX);
    if(strcmp(pName, "vkGetImageViewHandleNVX") == 0 && (!device || device_dispatch_table(device)->GetImageViewHandleNVX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageViewHandleNVX);
    if(strcmp(pName, "vkGetImageViewAddressNVX") == 0 && (!device || device_dispatch_table(device)->GetImageViewAddressNVX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageViewAddressNVX);
    if(strcmp(pName, "vkCmdDrawIndirectCountAMD") == 0 && (!device || device_dispatch_table(device)->CmdDrawIndirectCountAMD))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawIndirectCountAMD);
    if(strcmp(pName, "vkCmdDrawIndexedIndirectCountAMD") == 0 && (!device || device_dispatch_table(device)->CmdDrawIndexedIndirectCountAMD))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawIndexedIndirectCountAMD);
    if(strcmp(pName, "vkGetShaderInfoAMD") == 0 && (!device || device_dispatch_table(device)->GetShaderInfoAMD))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetShaderInfoAMD);
    if(strcmp(pName, "vkCmdBeginRenderingKHR") == 0 && (!device || device_dispatch_table(device)->CmdBeginRenderingKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginRenderingKHR);
    if(strcmp(pName, "vkCmdEndRenderingKHR") == 0 && (!device || device_dispatch_table(device)->CmdEndRenderingKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndRenderingKHR);
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    if(strcmp(pName, "vkGetMemoryWin32HandleNV") == 0 && (!device || device_dispatch_table(device)->GetMemoryWin32HandleNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMemoryWin32HandleNV);
#endif // VK_USE_PLATFORM_WIN32_KHR
    if(strcmp(pName, "vkGetDeviceGroupPeerMemoryFeaturesKHR") == 0 && (!device || device_dispatch_table(device)->GetDeviceGroupPeerMemoryFeaturesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceGroupPeerMemoryFeaturesKHR);
    if(strcmp(pName, "vkCmdSetDeviceMaskKHR") == 0 && (!device || device_dispatch_table(device)->CmdSetDeviceMaskKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDeviceMaskKHR);
    if(strcmp(pName, "vkCmdDispatchBaseKHR") == 0 && (!device || device_dispatch_table(device)->CmdDispatchBaseKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDispatchBaseKHR);
    if(strcmp(pName, "vkTrimCommandPoolKHR") == 0 && (!device || device_dispatch_table(device)->TrimCommandPoolKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkTrimCommandPoolKHR);
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    if(strcmp(pName, "vkGetMemoryWin32HandleKHR") == 0 && (!device || device_dispatch_table(device)->GetMemoryWin32HandleKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMemoryWin32HandleKHR);
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    if(strcmp(pName, "vkGetMemoryWin32HandlePropertiesKHR") == 0 && (!device || device_dispatch_table(device)->GetMemoryWin32HandlePropertiesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMemoryWin32HandlePropertiesKHR);
#endif // VK_USE_PLATFORM_WIN32_KHR
    if(strcmp(pName, "vkGetMemoryFdKHR") == 0 && (!device || device_dispatch_table(device)->GetMemoryFdKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMemoryFdKHR);
    if(strcmp(pName, "vkGetMemoryFdPropertiesKHR") == 0 && (!device || device_dispatch_table(device)->GetMemoryFdPropertiesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMemoryFdPropertiesKHR);
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    if(strcmp(pName, "vkImportSemaphoreWin32HandleKHR") == 0 && (!device || device_dispatch_table(device)->ImportSemaphoreWin32HandleKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkImportSemaphoreWin32HandleKHR);
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    if(strcmp(pName, "vkGetSemaphoreWin32HandleKHR") == 0 && (!device || device_dispatch_table(device)->GetSemaphoreWin32HandleKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetSemaphoreWin32HandleKHR);
#endif // VK_USE_PLATFORM_WIN32_KHR
    if(strcmp(pName, "vkImportSemaphoreFdKHR") == 0 && (!device || device_dispatch_table(device)->ImportSemaphoreFdKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkImportSemaphoreFdKHR);
    if(strcmp(pName, "vkGetSemaphoreFdKHR") == 0 && (!device || device_dispatch_table(device)->GetSemaphoreFdKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetSemaphoreFdKHR);
    if(strcmp(pName, "vkCmdPushDescriptorSetKHR") == 0 && (!device || device_dispatch_table(device)->CmdPushDescriptorSetKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPushDescriptorSetKHR);
    if(strcmp(pName, "vkCmdPushDescriptorSetWithTemplateKHR") == 0 && (!device || device_dispatch_table(device)->CmdPushDescriptorSetWithTemplateKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPushDescriptorSetWithTemplateKHR);
    if(strcmp(pName, "vkCmdBeginConditionalRenderingEXT") == 0 && (!device || device_dispatch_table(device)->CmdBeginConditionalRenderingEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginConditionalRenderingEXT);
    if(strcmp(pName, "vkCmdEndConditionalRenderingEXT") == 0 && (!device || device_dispatch_table(device)->CmdEndConditionalRenderingEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndConditionalRenderingEXT);
    if(strcmp(pName, "vkCreateDescriptorUpdateTemplateKHR") == 0 && (!device || device_dispatch_table(device)->CreateDescriptorUpdateTemplateKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDescriptorUpdateTemplateKHR);
    if(strcmp(pName, "vkDestroyDescriptorUpdateTemplateKHR") == 0 && (!device || device_dispatch_table(device)->DestroyDescriptorUpdateTemplateKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyDescriptorUpdateTemplateKHR);
    if(strcmp(pName, "vkUpdateDescriptorSetWithTemplateKHR") == 0 && (!device || device_dispatch_table(device)->UpdateDescriptorSetWithTemplateKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkUpdateDescriptorSetWithTemplateKHR);
    if(strcmp(pName, "vkCmdSetViewportWScalingNV") == 0 && (!device || device_dispatch_table(device)->CmdSetViewportWScalingNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetViewportWScalingNV);
    if(strcmp(pName, "vkDisplayPowerControlEXT") == 0 && (!device || device_dispatch_table(device)->DisplayPowerControlEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDisplayPowerControlEXT);
    if(strcmp(pName, "vkRegisterDeviceEventEXT") == 0 && (!device || device_dispatch_table(device)->RegisterDeviceEventEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkRegisterDeviceEventEXT);
    if(strcmp(pName, "vkRegisterDisplayEventEXT") == 0 && (!device || device_dispatch_table(device)->RegisterDisplayEventEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkRegisterDisplayEventEXT);
    if(strcmp(pName, "vkGetSwapchainCounterEXT") == 0 && (!device || device_dispatch_table(device)->GetSwapchainCounterEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetSwapchainCounterEXT);
    if(strcmp(pName, "vkGetRefreshCycleDurationGOOGLE") == 0 && (!device || device_dispatch_table(device)->GetRefreshCycleDurationGOOGLE))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetRefreshCycleDurationGOOGLE);
    if(strcmp(pName, "vkGetPastPresentationTimingGOOGLE") == 0 && (!device || device_dispatch_table(device)->GetPastPresentationTimingGOOGLE))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPastPresentationTimingGOOGLE);
    if(strcmp(pName, "vkCmdSetDiscardRectangleEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDiscardRectangleEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDiscardRectangleEXT);
    if(strcmp(pName, "vkCmdSetDiscardRectangleEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDiscardRectangleEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDiscardRectangleEnableEXT);
    if(strcmp(pName, "vkCmdSetDiscardRectangleModeEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDiscardRectangleModeEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDiscardRectangleModeEXT);
    if(strcmp(pName, "vkSetHdrMetadataEXT") == 0 && (!device || device_dispatch_table(device)->SetHdrMetadataEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetHdrMetadataEXT);
    if(strcmp(pName, "vkCreateRenderPass2KHR") == 0 && (!device || device_dispatch_table(device)->CreateRenderPass2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateRenderPass2KHR);
    if(strcmp(pName, "vkCmdBeginRenderPass2KHR") == 0 && (!device || device_dispatch_table(device)->CmdBeginRenderPass2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginRenderPass2KHR);
    if(strcmp(pName, "vkCmdNextSubpass2KHR") == 0 && (!device || device_dispatch_table(device)->CmdNextSubpass2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdNextSubpass2KHR);
    if(strcmp(pName, "vkCmdEndRenderPass2KHR") == 0 && (!device || device_dispatch_table(device)->CmdEndRenderPass2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndRenderPass2KHR);
    if(strcmp(pName, "vkGetSwapchainStatusKHR") == 0 && (!device || device_dispatch_table(device)->GetSwapchainStatusKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetSwapchainStatusKHR);
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    if(strcmp(pName, "vkImportFenceWin32HandleKHR") == 0 && (!device || device_dispatch_table(device)->ImportFenceWin32HandleKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkImportFenceWin32HandleKHR);
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    if(strcmp(pName, "vkGetFenceWin32HandleKHR") == 0 && (!device || device_dispatch_table(device)->GetFenceWin32HandleKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetFenceWin32HandleKHR);
#endif // VK_USE_PLATFORM_WIN32_KHR
    if(strcmp(pName, "vkImportFenceFdKHR") == 0 && (!device || device_dispatch_table(device)->ImportFenceFdKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkImportFenceFdKHR);
    if(strcmp(pName, "vkGetFenceFdKHR") == 0 && (!device || device_dispatch_table(device)->GetFenceFdKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetFenceFdKHR);
    if(strcmp(pName, "vkAcquireProfilingLockKHR") == 0 && (!device || device_dispatch_table(device)->AcquireProfilingLockKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkAcquireProfilingLockKHR);
    if(strcmp(pName, "vkReleaseProfilingLockKHR") == 0 && (!device || device_dispatch_table(device)->ReleaseProfilingLockKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkReleaseProfilingLockKHR);
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    if(strcmp(pName, "vkGetAndroidHardwareBufferPropertiesANDROID") == 0 && (!device || device_dispatch_table(device)->GetAndroidHardwareBufferPropertiesANDROID))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetAndroidHardwareBufferPropertiesANDROID);
#endif // VK_USE_PLATFORM_ANDROID_KHR
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    if(strcmp(pName, "vkGetMemoryAndroidHardwareBufferANDROID") == 0 && (!device || device_dispatch_table(device)->GetMemoryAndroidHardwareBufferANDROID))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMemoryAndroidHardwareBufferANDROID);
#endif // VK_USE_PLATFORM_ANDROID_KHR
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    if(strcmp(pName, "vkCreateExecutionGraphPipelinesAMDX") == 0 && (!device || device_dispatch_table(device)->CreateExecutionGraphPipelinesAMDX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateExecutionGraphPipelinesAMDX);
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    if(strcmp(pName, "vkGetExecutionGraphPipelineScratchSizeAMDX") == 0 && (!device || device_dispatch_table(device)->GetExecutionGraphPipelineScratchSizeAMDX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetExecutionGraphPipelineScratchSizeAMDX);
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    if(strcmp(pName, "vkGetExecutionGraphPipelineNodeIndexAMDX") == 0 && (!device || device_dispatch_table(device)->GetExecutionGraphPipelineNodeIndexAMDX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetExecutionGraphPipelineNodeIndexAMDX);
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    if(strcmp(pName, "vkCmdInitializeGraphScratchMemoryAMDX") == 0 && (!device || device_dispatch_table(device)->CmdInitializeGraphScratchMemoryAMDX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdInitializeGraphScratchMemoryAMDX);
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    if(strcmp(pName, "vkCmdDispatchGraphAMDX") == 0 && (!device || device_dispatch_table(device)->CmdDispatchGraphAMDX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDispatchGraphAMDX);
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    if(strcmp(pName, "vkCmdDispatchGraphIndirectAMDX") == 0 && (!device || device_dispatch_table(device)->CmdDispatchGraphIndirectAMDX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDispatchGraphIndirectAMDX);
#endif // VK_ENABLE_BETA_EXTENSIONS
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    if(strcmp(pName, "vkCmdDispatchGraphIndirectCountAMDX") == 0 && (!device || device_dispatch_table(device)->CmdDispatchGraphIndirectCountAMDX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDispatchGraphIndirectCountAMDX);
#endif // VK_ENABLE_BETA_EXTENSIONS
    if(strcmp(pName, "vkCmdSetSampleLocationsEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetSampleLocationsEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetSampleLocationsEXT);
    if(strcmp(pName, "vkGetImageMemoryRequirements2KHR") == 0 && (!device || device_dispatch_table(device)->GetImageMemoryRequirements2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageMemoryRequirements2KHR);
    if(strcmp(pName, "vkGetBufferMemoryRequirements2KHR") == 0 && (!device || device_dispatch_table(device)->GetBufferMemoryRequirements2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetBufferMemoryRequirements2KHR);
    if(strcmp(pName, "vkGetImageSparseMemoryRequirements2KHR") == 0 && (!device || device_dispatch_table(device)->GetImageSparseMemoryRequirements2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageSparseMemoryRequirements2KHR);
    if(strcmp(pName, "vkCreateAccelerationStructureKHR") == 0 && (!device || device_dispatch_table(device)->CreateAccelerationStructureKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateAccelerationStructureKHR);
    if(strcmp(pName, "vkDestroyAccelerationStructureKHR") == 0 && (!device || device_dispatch_table(device)->DestroyAccelerationStructureKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyAccelerationStructureKHR);
    if(strcmp(pName, "vkCmdBuildAccelerationStructuresKHR") == 0 && (!device || device_dispatch_table(device)->CmdBuildAccelerationStructuresKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBuildAccelerationStructuresKHR);
    if(strcmp(pName, "vkCmdBuildAccelerationStructuresIndirectKHR") == 0 && (!device || device_dispatch_table(device)->CmdBuildAccelerationStructuresIndirectKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBuildAccelerationStructuresIndirectKHR);
    if(strcmp(pName, "vkBuildAccelerationStructuresKHR") == 0 && (!device || device_dispatch_table(device)->BuildAccelerationStructuresKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBuildAccelerationStructuresKHR);
    if(strcmp(pName, "vkCopyAccelerationStructureKHR") == 0 && (!device || device_dispatch_table(device)->CopyAccelerationStructureKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCopyAccelerationStructureKHR);
    if(strcmp(pName, "vkCopyAccelerationStructureToMemoryKHR") == 0 && (!device || device_dispatch_table(device)->CopyAccelerationStructureToMemoryKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCopyAccelerationStructureToMemoryKHR);
    if(strcmp(pName, "vkCopyMemoryToAccelerationStructureKHR") == 0 && (!device || device_dispatch_table(device)->CopyMemoryToAccelerationStructureKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCopyMemoryToAccelerationStructureKHR);
    if(strcmp(pName, "vkWriteAccelerationStructuresPropertiesKHR") == 0 && (!device || device_dispatch_table(device)->WriteAccelerationStructuresPropertiesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkWriteAccelerationStructuresPropertiesKHR);
    if(strcmp(pName, "vkCmdCopyAccelerationStructureKHR") == 0 && (!device || device_dispatch_table(device)->CmdCopyAccelerationStructureKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyAccelerationStructureKHR);
    if(strcmp(pName, "vkCmdCopyAccelerationStructureToMemoryKHR") == 0 && (!device || device_dispatch_table(device)->CmdCopyAccelerationStructureToMemoryKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyAccelerationStructureToMemoryKHR);
    if(strcmp(pName, "vkCmdCopyMemoryToAccelerationStructureKHR") == 0 && (!device || device_dispatch_table(device)->CmdCopyMemoryToAccelerationStructureKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyMemoryToAccelerationStructureKHR);
    if(strcmp(pName, "vkGetAccelerationStructureDeviceAddressKHR") == 0 && (!device || device_dispatch_table(device)->GetAccelerationStructureDeviceAddressKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetAccelerationStructureDeviceAddressKHR);
    if(strcmp(pName, "vkCmdWriteAccelerationStructuresPropertiesKHR") == 0 && (!device || device_dispatch_table(device)->CmdWriteAccelerationStructuresPropertiesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdWriteAccelerationStructuresPropertiesKHR);
    if(strcmp(pName, "vkGetDeviceAccelerationStructureCompatibilityKHR") == 0 && (!device || device_dispatch_table(device)->GetDeviceAccelerationStructureCompatibilityKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceAccelerationStructureCompatibilityKHR);
    if(strcmp(pName, "vkGetAccelerationStructureBuildSizesKHR") == 0 && (!device || device_dispatch_table(device)->GetAccelerationStructureBuildSizesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetAccelerationStructureBuildSizesKHR);
    if(strcmp(pName, "vkCreateSamplerYcbcrConversionKHR") == 0 && (!device || device_dispatch_table(device)->CreateSamplerYcbcrConversionKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateSamplerYcbcrConversionKHR);
    if(strcmp(pName, "vkDestroySamplerYcbcrConversionKHR") == 0 && (!device || device_dispatch_table(device)->DestroySamplerYcbcrConversionKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroySamplerYcbcrConversionKHR);
    if(strcmp(pName, "vkBindBufferMemory2KHR") == 0 && (!device || device_dispatch_table(device)->BindBufferMemory2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBindBufferMemory2KHR);
    if(strcmp(pName, "vkBindImageMemory2KHR") == 0 && (!device || device_dispatch_table(device)->BindImageMemory2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBindImageMemory2KHR);
    if(strcmp(pName, "vkGetImageDrmFormatModifierPropertiesEXT") == 0 && (!device || device_dispatch_table(device)->GetImageDrmFormatModifierPropertiesEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageDrmFormatModifierPropertiesEXT);
    if(strcmp(pName, "vkCreateValidationCacheEXT") == 0 && (!device || device_dispatch_table(device)->CreateValidationCacheEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateValidationCacheEXT);
    if(strcmp(pName, "vkDestroyValidationCacheEXT") == 0 && (!device || device_dispatch_table(device)->DestroyValidationCacheEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyValidationCacheEXT);
    if(strcmp(pName, "vkMergeValidationCachesEXT") == 0 && (!device || device_dispatch_table(device)->MergeValidationCachesEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkMergeValidationCachesEXT);
    if(strcmp(pName, "vkGetValidationCacheDataEXT") == 0 && (!device || device_dispatch_table(device)->GetValidationCacheDataEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetValidationCacheDataEXT);
    if(strcmp(pName, "vkCmdBindShadingRateImageNV") == 0 && (!device || device_dispatch_table(device)->CmdBindShadingRateImageNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindShadingRateImageNV);
    if(strcmp(pName, "vkCmdSetViewportShadingRatePaletteNV") == 0 && (!device || device_dispatch_table(device)->CmdSetViewportShadingRatePaletteNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetViewportShadingRatePaletteNV);
    if(strcmp(pName, "vkCmdSetCoarseSampleOrderNV") == 0 && (!device || device_dispatch_table(device)->CmdSetCoarseSampleOrderNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetCoarseSampleOrderNV);
    if(strcmp(pName, "vkCreateAccelerationStructureNV") == 0 && (!device || device_dispatch_table(device)->CreateAccelerationStructureNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateAccelerationStructureNV);
    if(strcmp(pName, "vkDestroyAccelerationStructureNV") == 0 && (!device || device_dispatch_table(device)->DestroyAccelerationStructureNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyAccelerationStructureNV);
    if(strcmp(pName, "vkGetAccelerationStructureMemoryRequirementsNV") == 0 && (!device || device_dispatch_table(device)->GetAccelerationStructureMemoryRequirementsNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetAccelerationStructureMemoryRequirementsNV);
    if(strcmp(pName, "vkBindAccelerationStructureMemoryNV") == 0 && (!device || device_dispatch_table(device)->BindAccelerationStructureMemoryNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBindAccelerationStructureMemoryNV);
    if(strcmp(pName, "vkCmdBuildAccelerationStructureNV") == 0 && (!device || device_dispatch_table(device)->CmdBuildAccelerationStructureNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBuildAccelerationStructureNV);
    if(strcmp(pName, "vkCmdCopyAccelerationStructureNV") == 0 && (!device || device_dispatch_table(device)->CmdCopyAccelerationStructureNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyAccelerationStructureNV);
    if(strcmp(pName, "vkCmdTraceRaysNV") == 0 && (!device || device_dispatch_table(device)->CmdTraceRaysNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdTraceRaysNV);
    if(strcmp(pName, "vkCreateRayTracingPipelinesNV") == 0 && (!device || device_dispatch_table(device)->CreateRayTracingPipelinesNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateRayTracingPipelinesNV);
    if(strcmp(pName, "vkGetRayTracingShaderGroupHandlesKHR") == 0 && (!device || device_dispatch_table(device)->GetRayTracingShaderGroupHandlesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetRayTracingShaderGroupHandlesKHR);
    if(strcmp(pName, "vkGetRayTracingShaderGroupHandlesNV") == 0 && (!device || device_dispatch_table(device)->GetRayTracingShaderGroupHandlesNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetRayTracingShaderGroupHandlesNV);
    if(strcmp(pName, "vkGetAccelerationStructureHandleNV") == 0 && (!device || device_dispatch_table(device)->GetAccelerationStructureHandleNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetAccelerationStructureHandleNV);
    if(strcmp(pName, "vkCmdWriteAccelerationStructuresPropertiesNV") == 0 && (!device || device_dispatch_table(device)->CmdWriteAccelerationStructuresPropertiesNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdWriteAccelerationStructuresPropertiesNV);
    if(strcmp(pName, "vkCompileDeferredNV") == 0 && (!device || device_dispatch_table(device)->CompileDeferredNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCompileDeferredNV);
    if(strcmp(pName, "vkGetDescriptorSetLayoutSupportKHR") == 0 && (!device || device_dispatch_table(device)->GetDescriptorSetLayoutSupportKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDescriptorSetLayoutSupportKHR);
    if(strcmp(pName, "vkCmdDrawIndirectCountKHR") == 0 && (!device || device_dispatch_table(device)->CmdDrawIndirectCountKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawIndirectCountKHR);
    if(strcmp(pName, "vkCmdDrawIndexedIndirectCountKHR") == 0 && (!device || device_dispatch_table(device)->CmdDrawIndexedIndirectCountKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawIndexedIndirectCountKHR);
    if(strcmp(pName, "vkGetMemoryHostPointerPropertiesEXT") == 0 && (!device || device_dispatch_table(device)->GetMemoryHostPointerPropertiesEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMemoryHostPointerPropertiesEXT);
    if(strcmp(pName, "vkCmdWriteBufferMarkerAMD") == 0 && (!device || device_dispatch_table(device)->CmdWriteBufferMarkerAMD))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdWriteBufferMarkerAMD);
    if(strcmp(pName, "vkGetCalibratedTimestampsKHR") == 0 && (!device || device_dispatch_table(device)->GetCalibratedTimestampsKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetCalibratedTimestampsKHR);
    if(strcmp(pName, "vkGetCalibratedTimestampsEXT") == 0 && (!device || device_dispatch_table(device)->GetCalibratedTimestampsEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetCalibratedTimestampsEXT);
    if(strcmp(pName, "vkCmdDrawMeshTasksNV") == 0 && (!device || device_dispatch_table(device)->CmdDrawMeshTasksNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawMeshTasksNV);
    if(strcmp(pName, "vkCmdDrawMeshTasksIndirectNV") == 0 && (!device || device_dispatch_table(device)->CmdDrawMeshTasksIndirectNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawMeshTasksIndirectNV);
    if(strcmp(pName, "vkCmdDrawMeshTasksIndirectCountNV") == 0 && (!device || device_dispatch_table(device)->CmdDrawMeshTasksIndirectCountNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawMeshTasksIndirectCountNV);
    if(strcmp(pName, "vkCmdSetExclusiveScissorEnableNV") == 0 && (!device || device_dispatch_table(device)->CmdSetExclusiveScissorEnableNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetExclusiveScissorEnableNV);
    if(strcmp(pName, "vkCmdSetExclusiveScissorNV") == 0 && (!device || device_dispatch_table(device)->CmdSetExclusiveScissorNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetExclusiveScissorNV);
    if(strcmp(pName, "vkCmdSetCheckpointNV") == 0 && (!device || device_dispatch_table(device)->CmdSetCheckpointNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetCheckpointNV);
    if(strcmp(pName, "vkGetQueueCheckpointDataNV") == 0 && (!device || device_dispatch_table(device)->GetQueueCheckpointDataNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetQueueCheckpointDataNV);
    if(strcmp(pName, "vkGetSemaphoreCounterValueKHR") == 0 && (!device || device_dispatch_table(device)->GetSemaphoreCounterValueKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetSemaphoreCounterValueKHR);
    if(strcmp(pName, "vkWaitSemaphoresKHR") == 0 && (!device || device_dispatch_table(device)->WaitSemaphoresKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkWaitSemaphoresKHR);
    if(strcmp(pName, "vkSignalSemaphoreKHR") == 0 && (!device || device_dispatch_table(device)->SignalSemaphoreKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSignalSemaphoreKHR);
    if(strcmp(pName, "vkInitializePerformanceApiINTEL") == 0 && (!device || device_dispatch_table(device)->InitializePerformanceApiINTEL))
        return reinterpret_cast<PFN_vkVoidFunction>(vkInitializePerformanceApiINTEL);
    if(strcmp(pName, "vkUninitializePerformanceApiINTEL") == 0 && (!device || device_dispatch_table(device)->UninitializePerformanceApiINTEL))
        return reinterpret_cast<PFN_vkVoidFunction>(vkUninitializePerformanceApiINTEL);
    if(strcmp(pName, "vkCmdSetPerformanceMarkerINTEL") == 0 && (!device || device_dispatch_table(device)->CmdSetPerformanceMarkerINTEL))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetPerformanceMarkerINTEL);
    if(strcmp(pName, "vkCmdSetPerformanceStreamMarkerINTEL") == 0 && (!device || device_dispatch_table(device)->CmdSetPerformanceStreamMarkerINTEL))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetPerformanceStreamMarkerINTEL);
    if(strcmp(pName, "vkCmdSetPerformanceOverrideINTEL") == 0 && (!device || device_dispatch_table(device)->CmdSetPerformanceOverrideINTEL))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetPerformanceOverrideINTEL);
    if(strcmp(pName, "vkAcquirePerformanceConfigurationINTEL") == 0 && (!device || device_dispatch_table(device)->AcquirePerformanceConfigurationINTEL))
        return reinterpret_cast<PFN_vkVoidFunction>(vkAcquirePerformanceConfigurationINTEL);
    if(strcmp(pName, "vkReleasePerformanceConfigurationINTEL") == 0 && (!device || device_dispatch_table(device)->ReleasePerformanceConfigurationINTEL))
        return reinterpret_cast<PFN_vkVoidFunction>(vkReleasePerformanceConfigurationINTEL);
    if(strcmp(pName, "vkQueueSetPerformanceConfigurationINTEL") == 0 && (!device || device_dispatch_table(device)->QueueSetPerformanceConfigurationINTEL))
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueSetPerformanceConfigurationINTEL);
    if(strcmp(pName, "vkGetPerformanceParameterINTEL") == 0 && (!device || device_dispatch_table(device)->GetPerformanceParameterINTEL))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPerformanceParameterINTEL);
    if(strcmp(pName, "vkSetLocalDimmingAMD") == 0 && (!device || device_dispatch_table(device)->SetLocalDimmingAMD))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetLocalDimmingAMD);
    if(strcmp(pName, "vkCmdSetFragmentShadingRateKHR") == 0 && (!device || device_dispatch_table(device)->CmdSetFragmentShadingRateKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetFragmentShadingRateKHR);
    if(strcmp(pName, "vkCmdSetRenderingAttachmentLocationsKHR") == 0 && (!device || device_dispatch_table(device)->CmdSetRenderingAttachmentLocationsKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetRenderingAttachmentLocationsKHR);
    if(strcmp(pName, "vkCmdSetRenderingInputAttachmentIndicesKHR") == 0 && (!device || device_dispatch_table(device)->CmdSetRenderingInputAttachmentIndicesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetRenderingInputAttachmentIndicesKHR);
    if(strcmp(pName, "vkGetBufferDeviceAddressEXT") == 0 && (!device || device_dispatch_table(device)->GetBufferDeviceAddressEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetBufferDeviceAddressEXT);
    if(strcmp(pName, "vkWaitForPresentKHR") == 0 && (!device || device_dispatch_table(device)->WaitForPresentKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkWaitForPresentKHR);
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    if(strcmp(pName, "vkAcquireFullScreenExclusiveModeEXT") == 0 && (!device || device_dispatch_table(device)->AcquireFullScreenExclusiveModeEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkAcquireFullScreenExclusiveModeEXT);
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    if(strcmp(pName, "vkReleaseFullScreenExclusiveModeEXT") == 0 && (!device || device_dispatch_table(device)->ReleaseFullScreenExclusiveModeEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkReleaseFullScreenExclusiveModeEXT);
#endif // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    if(strcmp(pName, "vkGetDeviceGroupSurfacePresentModes2EXT") == 0 && (!device || device_dispatch_table(device)->GetDeviceGroupSurfacePresentModes2EXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceGroupSurfacePresentModes2EXT);
#endif // VK_USE_PLATFORM_WIN32_KHR
    if(strcmp(pName, "vkGetBufferDeviceAddressKHR") == 0 && (!device || device_dispatch_table(device)->GetBufferDeviceAddressKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetBufferDeviceAddressKHR);
    if(strcmp(pName, "vkGetBufferOpaqueCaptureAddressKHR") == 0 && (!device || device_dispatch_table(device)->GetBufferOpaqueCaptureAddressKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetBufferOpaqueCaptureAddressKHR);
    if(strcmp(pName, "vkGetDeviceMemoryOpaqueCaptureAddressKHR") == 0 && (!device || device_dispatch_table(device)->GetDeviceMemoryOpaqueCaptureAddressKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceMemoryOpaqueCaptureAddressKHR);
    if(strcmp(pName, "vkCmdSetLineStippleKHR") == 0 && (!device || device_dispatch_table(device)->CmdSetLineStippleKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetLineStippleKHR);
    if(strcmp(pName, "vkCmdSetLineStippleEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetLineStippleEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetLineStippleEXT);
    if(strcmp(pName, "vkResetQueryPoolEXT") == 0 && (!device || device_dispatch_table(device)->ResetQueryPoolEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkResetQueryPoolEXT);
    if(strcmp(pName, "vkCmdSetCullModeEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetCullModeEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetCullModeEXT);
    if(strcmp(pName, "vkCmdSetFrontFaceEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetFrontFaceEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetFrontFaceEXT);
    if(strcmp(pName, "vkCmdSetPrimitiveTopologyEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetPrimitiveTopologyEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetPrimitiveTopologyEXT);
    if(strcmp(pName, "vkCmdSetViewportWithCountEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetViewportWithCountEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetViewportWithCountEXT);
    if(strcmp(pName, "vkCmdSetScissorWithCountEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetScissorWithCountEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetScissorWithCountEXT);
    if(strcmp(pName, "vkCmdBindVertexBuffers2EXT") == 0 && (!device || device_dispatch_table(device)->CmdBindVertexBuffers2EXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindVertexBuffers2EXT);
    if(strcmp(pName, "vkCmdSetDepthTestEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthTestEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthTestEnableEXT);
    if(strcmp(pName, "vkCmdSetDepthWriteEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthWriteEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthWriteEnableEXT);
    if(strcmp(pName, "vkCmdSetDepthCompareOpEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthCompareOpEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthCompareOpEXT);
    if(strcmp(pName, "vkCmdSetDepthBoundsTestEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthBoundsTestEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthBoundsTestEnableEXT);
    if(strcmp(pName, "vkCmdSetStencilTestEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetStencilTestEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetStencilTestEnableEXT);
    if(strcmp(pName, "vkCmdSetStencilOpEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetStencilOpEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetStencilOpEXT);
    if(strcmp(pName, "vkCreateDeferredOperationKHR") == 0 && (!device || device_dispatch_table(device)->CreateDeferredOperationKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDeferredOperationKHR);
    if(strcmp(pName, "vkDestroyDeferredOperationKHR") == 0 && (!device || device_dispatch_table(device)->DestroyDeferredOperationKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyDeferredOperationKHR);
    if(strcmp(pName, "vkGetDeferredOperationMaxConcurrencyKHR") == 0 && (!device || device_dispatch_table(device)->GetDeferredOperationMaxConcurrencyKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeferredOperationMaxConcurrencyKHR);
    if(strcmp(pName, "vkGetDeferredOperationResultKHR") == 0 && (!device || device_dispatch_table(device)->GetDeferredOperationResultKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeferredOperationResultKHR);
    if(strcmp(pName, "vkDeferredOperationJoinKHR") == 0 && (!device || device_dispatch_table(device)->DeferredOperationJoinKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDeferredOperationJoinKHR);
    if(strcmp(pName, "vkGetPipelineExecutablePropertiesKHR") == 0 && (!device || device_dispatch_table(device)->GetPipelineExecutablePropertiesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPipelineExecutablePropertiesKHR);
    if(strcmp(pName, "vkGetPipelineExecutableStatisticsKHR") == 0 && (!device || device_dispatch_table(device)->GetPipelineExecutableStatisticsKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPipelineExecutableStatisticsKHR);
    if(strcmp(pName, "vkGetPipelineExecutableInternalRepresentationsKHR") == 0 && (!device || device_dispatch_table(device)->GetPipelineExecutableInternalRepresentationsKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPipelineExecutableInternalRepresentationsKHR);
    if(strcmp(pName, "vkCopyMemoryToImageEXT") == 0 && (!device || device_dispatch_table(device)->CopyMemoryToImageEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCopyMemoryToImageEXT);
    if(strcmp(pName, "vkCopyImageToMemoryEXT") == 0 && (!device || device_dispatch_table(device)->CopyImageToMemoryEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCopyImageToMemoryEXT);
    if(strcmp(pName, "vkCopyImageToImageEXT") == 0 && (!device || device_dispatch_table(device)->CopyImageToImageEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCopyImageToImageEXT);
    if(strcmp(pName, "vkTransitionImageLayoutEXT") == 0 && (!device || device_dispatch_table(device)->TransitionImageLayoutEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkTransitionImageLayoutEXT);
    if(strcmp(pName, "vkGetImageSubresourceLayout2KHR") == 0 && (!device || device_dispatch_table(device)->GetImageSubresourceLayout2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageSubresourceLayout2KHR);
    if(strcmp(pName, "vkGetImageSubresourceLayout2EXT") == 0 && (!device || device_dispatch_table(device)->GetImageSubresourceLayout2EXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageSubresourceLayout2EXT);
    if(strcmp(pName, "vkMapMemory2KHR") == 0 && (!device || device_dispatch_table(device)->MapMemory2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkMapMemory2KHR);
    if(strcmp(pName, "vkUnmapMemory2KHR") == 0 && (!device || device_dispatch_table(device)->UnmapMemory2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkUnmapMemory2KHR);
    if(strcmp(pName, "vkReleaseSwapchainImagesEXT") == 0 && (!device || device_dispatch_table(device)->ReleaseSwapchainImagesEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkReleaseSwapchainImagesEXT);
    if(strcmp(pName, "vkGetGeneratedCommandsMemoryRequirementsNV") == 0 && (!device || device_dispatch_table(device)->GetGeneratedCommandsMemoryRequirementsNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetGeneratedCommandsMemoryRequirementsNV);
    if(strcmp(pName, "vkCmdPreprocessGeneratedCommandsNV") == 0 && (!device || device_dispatch_table(device)->CmdPreprocessGeneratedCommandsNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPreprocessGeneratedCommandsNV);
    if(strcmp(pName, "vkCmdExecuteGeneratedCommandsNV") == 0 && (!device || device_dispatch_table(device)->CmdExecuteGeneratedCommandsNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdExecuteGeneratedCommandsNV);
    if(strcmp(pName, "vkCmdBindPipelineShaderGroupNV") == 0 && (!device || device_dispatch_table(device)->CmdBindPipelineShaderGroupNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindPipelineShaderGroupNV);
    if(strcmp(pName, "vkCreateIndirectCommandsLayoutNV") == 0 && (!device || device_dispatch_table(device)->CreateIndirectCommandsLayoutNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateIndirectCommandsLayoutNV);
    if(strcmp(pName, "vkDestroyIndirectCommandsLayoutNV") == 0 && (!device || device_dispatch_table(device)->DestroyIndirectCommandsLayoutNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyIndirectCommandsLayoutNV);
    if(strcmp(pName, "vkCmdSetDepthBias2EXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthBias2EXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthBias2EXT);
    if(strcmp(pName, "vkCreatePrivateDataSlotEXT") == 0 && (!device || device_dispatch_table(device)->CreatePrivateDataSlotEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreatePrivateDataSlotEXT);
    if(strcmp(pName, "vkDestroyPrivateDataSlotEXT") == 0 && (!device || device_dispatch_table(device)->DestroyPrivateDataSlotEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyPrivateDataSlotEXT);
    if(strcmp(pName, "vkSetPrivateDataEXT") == 0 && (!device || device_dispatch_table(device)->SetPrivateDataEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetPrivateDataEXT);
    if(strcmp(pName, "vkGetPrivateDataEXT") == 0 && (!device || device_dispatch_table(device)->GetPrivateDataEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPrivateDataEXT);
    if(strcmp(pName, "vkGetEncodedVideoSessionParametersKHR") == 0 && (!device || device_dispatch_table(device)->GetEncodedVideoSessionParametersKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetEncodedVideoSessionParametersKHR);
    if(strcmp(pName, "vkCmdEncodeVideoKHR") == 0 && (!device || device_dispatch_table(device)->CmdEncodeVideoKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEncodeVideoKHR);
    if(strcmp(pName, "vkCreateCudaModuleNV") == 0 && (!device || device_dispatch_table(device)->CreateCudaModuleNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateCudaModuleNV);
    if(strcmp(pName, "vkGetCudaModuleCacheNV") == 0 && (!device || device_dispatch_table(device)->GetCudaModuleCacheNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetCudaModuleCacheNV);
    if(strcmp(pName, "vkCreateCudaFunctionNV") == 0 && (!device || device_dispatch_table(device)->CreateCudaFunctionNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateCudaFunctionNV);
    if(strcmp(pName, "vkDestroyCudaModuleNV") == 0 && (!device || device_dispatch_table(device)->DestroyCudaModuleNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyCudaModuleNV);
    if(strcmp(pName, "vkDestroyCudaFunctionNV") == 0 && (!device || device_dispatch_table(device)->DestroyCudaFunctionNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyCudaFunctionNV);
    if(strcmp(pName, "vkCmdCudaLaunchKernelNV") == 0 && (!device || device_dispatch_table(device)->CmdCudaLaunchKernelNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCudaLaunchKernelNV);
#if defined(VK_USE_PLATFORM_METAL_EXT)
    if(strcmp(pName, "vkExportMetalObjectsEXT") == 0 && (!device || device_dispatch_table(device)->ExportMetalObjectsEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkExportMetalObjectsEXT);
#endif // VK_USE_PLATFORM_METAL_EXT
    if(strcmp(pName, "vkCmdSetEvent2KHR") == 0 && (!device || device_dispatch_table(device)->CmdSetEvent2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetEvent2KHR);
    if(strcmp(pName, "vkCmdResetEvent2KHR") == 0 && (!device || device_dispatch_table(device)->CmdResetEvent2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdResetEvent2KHR);
    if(strcmp(pName, "vkCmdWaitEvents2KHR") == 0 && (!device || device_dispatch_table(device)->CmdWaitEvents2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdWaitEvents2KHR);
    if(strcmp(pName, "vkCmdPipelineBarrier2KHR") == 0 && (!device || device_dispatch_table(device)->CmdPipelineBarrier2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPipelineBarrier2KHR);
    if(strcmp(pName, "vkCmdWriteTimestamp2KHR") == 0 && (!device || device_dispatch_table(device)->CmdWriteTimestamp2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdWriteTimestamp2KHR);
    if(strcmp(pName, "vkQueueSubmit2KHR") == 0 && (!device || device_dispatch_table(device)->QueueSubmit2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueSubmit2KHR);
    if(strcmp(pName, "vkCmdWriteBufferMarker2AMD") == 0 && (!device || device_dispatch_table(device)->CmdWriteBufferMarker2AMD))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdWriteBufferMarker2AMD);
    if(strcmp(pName, "vkGetQueueCheckpointData2NV") == 0 && (!device || device_dispatch_table(device)->GetQueueCheckpointData2NV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetQueueCheckpointData2NV);
    if(strcmp(pName, "vkGetDescriptorSetLayoutSizeEXT") == 0 && (!device || device_dispatch_table(device)->GetDescriptorSetLayoutSizeEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDescriptorSetLayoutSizeEXT);
    if(strcmp(pName, "vkGetDescriptorSetLayoutBindingOffsetEXT") == 0 && (!device || device_dispatch_table(device)->GetDescriptorSetLayoutBindingOffsetEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDescriptorSetLayoutBindingOffsetEXT);
    if(strcmp(pName, "vkGetDescriptorEXT") == 0 && (!device || device_dispatch_table(device)->GetDescriptorEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDescriptorEXT);
    if(strcmp(pName, "vkCmdBindDescriptorBuffersEXT") == 0 && (!device || device_dispatch_table(device)->CmdBindDescriptorBuffersEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindDescriptorBuffersEXT);
    if(strcmp(pName, "vkCmdSetDescriptorBufferOffsetsEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDescriptorBufferOffsetsEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDescriptorBufferOffsetsEXT);
    if(strcmp(pName, "vkCmdBindDescriptorBufferEmbeddedSamplersEXT") == 0 && (!device || device_dispatch_table(device)->CmdBindDescriptorBufferEmbeddedSamplersEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindDescriptorBufferEmbeddedSamplersEXT);
    if(strcmp(pName, "vkGetBufferOpaqueCaptureDescriptorDataEXT") == 0 && (!device || device_dispatch_table(device)->GetBufferOpaqueCaptureDescriptorDataEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetBufferOpaqueCaptureDescriptorDataEXT);
    if(strcmp(pName, "vkGetImageOpaqueCaptureDescriptorDataEXT") == 0 && (!device || device_dispatch_table(device)->GetImageOpaqueCaptureDescriptorDataEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageOpaqueCaptureDescriptorDataEXT);
    if(strcmp(pName, "vkGetImageViewOpaqueCaptureDescriptorDataEXT") == 0 && (!device || device_dispatch_table(device)->GetImageViewOpaqueCaptureDescriptorDataEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageViewOpaqueCaptureDescriptorDataEXT);
    if(strcmp(pName, "vkGetSamplerOpaqueCaptureDescriptorDataEXT") == 0 && (!device || device_dispatch_table(device)->GetSamplerOpaqueCaptureDescriptorDataEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetSamplerOpaqueCaptureDescriptorDataEXT);
    if(strcmp(pName, "vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT") == 0 && (!device || device_dispatch_table(device)->GetAccelerationStructureOpaqueCaptureDescriptorDataEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT);
    if(strcmp(pName, "vkCmdSetFragmentShadingRateEnumNV") == 0 && (!device || device_dispatch_table(device)->CmdSetFragmentShadingRateEnumNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetFragmentShadingRateEnumNV);
    if(strcmp(pName, "vkCmdDrawMeshTasksEXT") == 0 && (!device || device_dispatch_table(device)->CmdDrawMeshTasksEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawMeshTasksEXT);
    if(strcmp(pName, "vkCmdDrawMeshTasksIndirectEXT") == 0 && (!device || device_dispatch_table(device)->CmdDrawMeshTasksIndirectEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawMeshTasksIndirectEXT);
    if(strcmp(pName, "vkCmdDrawMeshTasksIndirectCountEXT") == 0 && (!device || device_dispatch_table(device)->CmdDrawMeshTasksIndirectCountEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawMeshTasksIndirectCountEXT);
    if(strcmp(pName, "vkCmdCopyBuffer2KHR") == 0 && (!device || device_dispatch_table(device)->CmdCopyBuffer2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyBuffer2KHR);
    if(strcmp(pName, "vkCmdCopyImage2KHR") == 0 && (!device || device_dispatch_table(device)->CmdCopyImage2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyImage2KHR);
    if(strcmp(pName, "vkCmdCopyBufferToImage2KHR") == 0 && (!device || device_dispatch_table(device)->CmdCopyBufferToImage2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyBufferToImage2KHR);
    if(strcmp(pName, "vkCmdCopyImageToBuffer2KHR") == 0 && (!device || device_dispatch_table(device)->CmdCopyImageToBuffer2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyImageToBuffer2KHR);
    if(strcmp(pName, "vkCmdBlitImage2KHR") == 0 && (!device || device_dispatch_table(device)->CmdBlitImage2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBlitImage2KHR);
    if(strcmp(pName, "vkCmdResolveImage2KHR") == 0 && (!device || device_dispatch_table(device)->CmdResolveImage2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdResolveImage2KHR);
    if(strcmp(pName, "vkGetDeviceFaultInfoEXT") == 0 && (!device || device_dispatch_table(device)->GetDeviceFaultInfoEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceFaultInfoEXT);
    if(strcmp(pName, "vkCmdTraceRaysKHR") == 0 && (!device || device_dispatch_table(device)->CmdTraceRaysKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdTraceRaysKHR);
    if(strcmp(pName, "vkCreateRayTracingPipelinesKHR") == 0 && (!device || device_dispatch_table(device)->CreateRayTracingPipelinesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateRayTracingPipelinesKHR);
    if(strcmp(pName, "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR") == 0 && (!device || device_dispatch_table(device)->GetRayTracingCaptureReplayShaderGroupHandlesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetRayTracingCaptureReplayShaderGroupHandlesKHR);
    if(strcmp(pName, "vkCmdTraceRaysIndirectKHR") == 0 && (!device || device_dispatch_table(device)->CmdTraceRaysIndirectKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdTraceRaysIndirectKHR);
    if(strcmp(pName, "vkGetRayTracingShaderGroupStackSizeKHR") == 0 && (!device || device_dispatch_table(device)->GetRayTracingShaderGroupStackSizeKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetRayTracingShaderGroupStackSizeKHR);
    if(strcmp(pName, "vkCmdSetRayTracingPipelineStackSizeKHR") == 0 && (!device || device_dispatch_table(device)->CmdSetRayTracingPipelineStackSizeKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetRayTracingPipelineStackSizeKHR);
    if(strcmp(pName, "vkCmdSetVertexInputEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetVertexInputEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetVertexInputEXT);
#if defined(VK_USE_PLATFORM_FUCHSIA)
    if(strcmp(pName, "vkGetMemoryZirconHandleFUCHSIA") == 0 && (!device || device_dispatch_table(device)->GetMemoryZirconHandleFUCHSIA))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMemoryZirconHandleFUCHSIA);
#endif // VK_USE_PLATFORM_FUCHSIA
#if defined(VK_USE_PLATFORM_FUCHSIA)
    if(strcmp(pName, "vkGetMemoryZirconHandlePropertiesFUCHSIA") == 0 && (!device || device_dispatch_table(device)->GetMemoryZirconHandlePropertiesFUCHSIA))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMemoryZirconHandlePropertiesFUCHSIA);
#endif // VK_USE_PLATFORM_FUCHSIA
#if defined(VK_USE_PLATFORM_FUCHSIA)
    if(strcmp(pName, "vkImportSemaphoreZirconHandleFUCHSIA") == 0 && (!device || device_dispatch_table(device)->ImportSemaphoreZirconHandleFUCHSIA))
        return reinterpret_cast<PFN_vkVoidFunction>(vkImportSemaphoreZirconHandleFUCHSIA);
#endif // VK_USE_PLATFORM_FUCHSIA
#if defined(VK_USE_PLATFORM_FUCHSIA)
    if(strcmp(pName, "vkGetSemaphoreZirconHandleFUCHSIA") == 0 && (!device || device_dispatch_table(device)->GetSemaphoreZirconHandleFUCHSIA))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetSemaphoreZirconHandleFUCHSIA);
#endif // VK_USE_PLATFORM_FUCHSIA
#if defined(VK_USE_PLATFORM_FUCHSIA)
    if(strcmp(pName, "vkCreateBufferCollectionFUCHSIA") == 0 && (!device || device_dispatch_table(device)->CreateBufferCollectionFUCHSIA))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateBufferCollectionFUCHSIA);
#endif // VK_USE_PLATFORM_FUCHSIA
#if defined(VK_USE_PLATFORM_FUCHSIA)
    if(strcmp(pName, "vkSetBufferCollectionImageConstraintsFUCHSIA") == 0 && (!device || device_dispatch_table(device)->SetBufferCollectionImageConstraintsFUCHSIA))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetBufferCollectionImageConstraintsFUCHSIA);
#endif // VK_USE_PLATFORM_FUCHSIA
#if defined(VK_USE_PLATFORM_FUCHSIA)
    if(strcmp(pName, "vkSetBufferCollectionBufferConstraintsFUCHSIA") == 0 && (!device || device_dispatch_table(device)->SetBufferCollectionBufferConstraintsFUCHSIA))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetBufferCollectionBufferConstraintsFUCHSIA);
#endif // VK_USE_PLATFORM_FUCHSIA
#if defined(VK_USE_PLATFORM_FUCHSIA)
    if(strcmp(pName, "vkDestroyBufferCollectionFUCHSIA") == 0 && (!device || device_dispatch_table(device)->DestroyBufferCollectionFUCHSIA))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyBufferCollectionFUCHSIA);
#endif // VK_USE_PLATFORM_FUCHSIA
#if defined(VK_USE_PLATFORM_FUCHSIA)
    if(strcmp(pName, "vkGetBufferCollectionPropertiesFUCHSIA") == 0 && (!device || device_dispatch_table(device)->GetBufferCollectionPropertiesFUCHSIA))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetBufferCollectionPropertiesFUCHSIA);
#endif // VK_USE_PLATFORM_FUCHSIA
    if(strcmp(pName, "vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI") == 0 && (!device || device_dispatch_table(device)->GetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI);
    if(strcmp(pName, "vkCmdSubpassShadingHUAWEI") == 0 && (!device || device_dispatch_table(device)->CmdSubpassShadingHUAWEI))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSubpassShadingHUAWEI);
    if(strcmp(pName, "vkCmdBindInvocationMaskHUAWEI") == 0 && (!device || device_dispatch_table(device)->CmdBindInvocationMaskHUAWEI))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindInvocationMaskHUAWEI);
    if(strcmp(pName, "vkGetMemoryRemoteAddressNV") == 0 && (!device || device_dispatch_table(device)->GetMemoryRemoteAddressNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMemoryRemoteAddressNV);
    if(strcmp(pName, "vkGetPipelinePropertiesEXT") == 0 && (!device || device_dispatch_table(device)->GetPipelinePropertiesEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPipelinePropertiesEXT);
    if(strcmp(pName, "vkCmdSetPatchControlPointsEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetPatchControlPointsEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetPatchControlPointsEXT);
    if(strcmp(pName, "vkCmdSetRasterizerDiscardEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetRasterizerDiscardEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetRasterizerDiscardEnableEXT);
    if(strcmp(pName, "vkCmdSetDepthBiasEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthBiasEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthBiasEnableEXT);
    if(strcmp(pName, "vkCmdSetLogicOpEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetLogicOpEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetLogicOpEXT);
    if(strcmp(pName, "vkCmdSetPrimitiveRestartEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetPrimitiveRestartEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetPrimitiveRestartEnableEXT);
    if(strcmp(pName, "vkCmdSetColorWriteEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetColorWriteEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetColorWriteEnableEXT);
    if(strcmp(pName, "vkCmdTraceRaysIndirect2KHR") == 0 && (!device || device_dispatch_table(device)->CmdTraceRaysIndirect2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdTraceRaysIndirect2KHR);
    if(strcmp(pName, "vkCmdDrawMultiEXT") == 0 && (!device || device_dispatch_table(device)->CmdDrawMultiEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawMultiEXT);
    if(strcmp(pName, "vkCmdDrawMultiIndexedEXT") == 0 && (!device || device_dispatch_table(device)->CmdDrawMultiIndexedEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawMultiIndexedEXT);
    if(strcmp(pName, "vkCreateMicromapEXT") == 0 && (!device || device_dispatch_table(device)->CreateMicromapEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateMicromapEXT);
    if(strcmp(pName, "vkDestroyMicromapEXT") == 0 && (!device || device_dispatch_table(device)->DestroyMicromapEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyMicromapEXT);
    if(strcmp(pName, "vkCmdBuildMicromapsEXT") == 0 && (!device || device_dispatch_table(device)->CmdBuildMicromapsEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBuildMicromapsEXT);
    if(strcmp(pName, "vkBuildMicromapsEXT") == 0 && (!device || device_dispatch_table(device)->BuildMicromapsEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBuildMicromapsEXT);
    if(strcmp(pName, "vkCopyMicromapEXT") == 0 && (!device || device_dispatch_table(device)->CopyMicromapEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCopyMicromapEXT);
    if(strcmp(pName, "vkCopyMicromapToMemoryEXT") == 0 && (!device || device_dispatch_table(device)->CopyMicromapToMemoryEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCopyMicromapToMemoryEXT);
    if(strcmp(pName, "vkCopyMemoryToMicromapEXT") == 0 && (!device || device_dispatch_table(device)->CopyMemoryToMicromapEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCopyMemoryToMicromapEXT);
    if(strcmp(pName, "vkWriteMicromapsPropertiesEXT") == 0 && (!device || device_dispatch_table(device)->WriteMicromapsPropertiesEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkWriteMicromapsPropertiesEXT);
    if(strcmp(pName, "vkCmdCopyMicromapEXT") == 0 && (!device || device_dispatch_table(device)->CmdCopyMicromapEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyMicromapEXT);
    if(strcmp(pName, "vkCmdCopyMicromapToMemoryEXT") == 0 && (!device || device_dispatch_table(device)->CmdCopyMicromapToMemoryEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyMicromapToMemoryEXT);
    if(strcmp(pName, "vkCmdCopyMemoryToMicromapEXT") == 0 && (!device || device_dispatch_table(device)->CmdCopyMemoryToMicromapEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyMemoryToMicromapEXT);
    if(strcmp(pName, "vkCmdWriteMicromapsPropertiesEXT") == 0 && (!device || device_dispatch_table(device)->CmdWriteMicromapsPropertiesEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdWriteMicromapsPropertiesEXT);
    if(strcmp(pName, "vkGetDeviceMicromapCompatibilityEXT") == 0 && (!device || device_dispatch_table(device)->GetDeviceMicromapCompatibilityEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceMicromapCompatibilityEXT);
    if(strcmp(pName, "vkGetMicromapBuildSizesEXT") == 0 && (!device || device_dispatch_table(device)->GetMicromapBuildSizesEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMicromapBuildSizesEXT);
    if(strcmp(pName, "vkCmdDrawClusterHUAWEI") == 0 && (!device || device_dispatch_table(device)->CmdDrawClusterHUAWEI))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawClusterHUAWEI);
    if(strcmp(pName, "vkCmdDrawClusterIndirectHUAWEI") == 0 && (!device || device_dispatch_table(device)->CmdDrawClusterIndirectHUAWEI))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawClusterIndirectHUAWEI);
    if(strcmp(pName, "vkSetDeviceMemoryPriorityEXT") == 0 && (!device || device_dispatch_table(device)->SetDeviceMemoryPriorityEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetDeviceMemoryPriorityEXT);
    if(strcmp(pName, "vkGetDeviceBufferMemoryRequirementsKHR") == 0 && (!device || device_dispatch_table(device)->GetDeviceBufferMemoryRequirementsKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceBufferMemoryRequirementsKHR);
    if(strcmp(pName, "vkGetDeviceImageMemoryRequirementsKHR") == 0 && (!device || device_dispatch_table(device)->GetDeviceImageMemoryRequirementsKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceImageMemoryRequirementsKHR);
    if(strcmp(pName, "vkGetDeviceImageSparseMemoryRequirementsKHR") == 0 && (!device || device_dispatch_table(device)->GetDeviceImageSparseMemoryRequirementsKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceImageSparseMemoryRequirementsKHR);
    if(strcmp(pName, "vkGetDescriptorSetLayoutHostMappingInfoVALVE") == 0 && (!device || device_dispatch_table(device)->GetDescriptorSetLayoutHostMappingInfoVALVE))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDescriptorSetLayoutHostMappingInfoVALVE);
    if(strcmp(pName, "vkGetDescriptorSetHostMappingVALVE") == 0 && (!device || device_dispatch_table(device)->GetDescriptorSetHostMappingVALVE))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDescriptorSetHostMappingVALVE);
    if(strcmp(pName, "vkCmdCopyMemoryIndirectNV") == 0 && (!device || device_dispatch_table(device)->CmdCopyMemoryIndirectNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyMemoryIndirectNV);
    if(strcmp(pName, "vkCmdCopyMemoryToImageIndirectNV") == 0 && (!device || device_dispatch_table(device)->CmdCopyMemoryToImageIndirectNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyMemoryToImageIndirectNV);
    if(strcmp(pName, "vkCmdDecompressMemoryNV") == 0 && (!device || device_dispatch_table(device)->CmdDecompressMemoryNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDecompressMemoryNV);
    if(strcmp(pName, "vkCmdDecompressMemoryIndirectCountNV") == 0 && (!device || device_dispatch_table(device)->CmdDecompressMemoryIndirectCountNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDecompressMemoryIndirectCountNV);
    if(strcmp(pName, "vkGetPipelineIndirectMemoryRequirementsNV") == 0 && (!device || device_dispatch_table(device)->GetPipelineIndirectMemoryRequirementsNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPipelineIndirectMemoryRequirementsNV);
    if(strcmp(pName, "vkCmdUpdatePipelineIndirectBufferNV") == 0 && (!device || device_dispatch_table(device)->CmdUpdatePipelineIndirectBufferNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdUpdatePipelineIndirectBufferNV);
    if(strcmp(pName, "vkGetPipelineIndirectDeviceAddressNV") == 0 && (!device || device_dispatch_table(device)->GetPipelineIndirectDeviceAddressNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPipelineIndirectDeviceAddressNV);
    if(strcmp(pName, "vkCmdSetDepthClampEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthClampEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthClampEnableEXT);
    if(strcmp(pName, "vkCmdSetPolygonModeEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetPolygonModeEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetPolygonModeEXT);
    if(strcmp(pName, "vkCmdSetRasterizationSamplesEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetRasterizationSamplesEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetRasterizationSamplesEXT);
    if(strcmp(pName, "vkCmdSetSampleMaskEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetSampleMaskEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetSampleMaskEXT);
    if(strcmp(pName, "vkCmdSetAlphaToCoverageEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetAlphaToCoverageEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetAlphaToCoverageEnableEXT);
    if(strcmp(pName, "vkCmdSetAlphaToOneEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetAlphaToOneEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetAlphaToOneEnableEXT);
    if(strcmp(pName, "vkCmdSetLogicOpEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetLogicOpEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetLogicOpEnableEXT);
    if(strcmp(pName, "vkCmdSetColorBlendEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetColorBlendEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetColorBlendEnableEXT);
    if(strcmp(pName, "vkCmdSetColorBlendEquationEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetColorBlendEquationEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetColorBlendEquationEXT);
    if(strcmp(pName, "vkCmdSetColorWriteMaskEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetColorWriteMaskEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetColorWriteMaskEXT);
    if(strcmp(pName, "vkCmdSetTessellationDomainOriginEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetTessellationDomainOriginEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetTessellationDomainOriginEXT);
    if(strcmp(pName, "vkCmdSetRasterizationStreamEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetRasterizationStreamEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetRasterizationStreamEXT);
    if(strcmp(pName, "vkCmdSetConservativeRasterizationModeEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetConservativeRasterizationModeEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetConservativeRasterizationModeEXT);
    if(strcmp(pName, "vkCmdSetExtraPrimitiveOverestimationSizeEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetExtraPrimitiveOverestimationSizeEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetExtraPrimitiveOverestimationSizeEXT);
    if(strcmp(pName, "vkCmdSetDepthClipEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthClipEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthClipEnableEXT);
    if(strcmp(pName, "vkCmdSetSampleLocationsEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetSampleLocationsEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetSampleLocationsEnableEXT);
    if(strcmp(pName, "vkCmdSetColorBlendAdvancedEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetColorBlendAdvancedEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetColorBlendAdvancedEXT);
    if(strcmp(pName, "vkCmdSetProvokingVertexModeEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetProvokingVertexModeEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetProvokingVertexModeEXT);
    if(strcmp(pName, "vkCmdSetLineRasterizationModeEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetLineRasterizationModeEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetLineRasterizationModeEXT);
    if(strcmp(pName, "vkCmdSetLineStippleEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetLineStippleEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetLineStippleEnableEXT);
    if(strcmp(pName, "vkCmdSetDepthClipNegativeOneToOneEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthClipNegativeOneToOneEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthClipNegativeOneToOneEXT);
    if(strcmp(pName, "vkCmdSetViewportWScalingEnableNV") == 0 && (!device || device_dispatch_table(device)->CmdSetViewportWScalingEnableNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetViewportWScalingEnableNV);
    if(strcmp(pName, "vkCmdSetViewportSwizzleNV") == 0 && (!device || device_dispatch_table(device)->CmdSetViewportSwizzleNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetViewportSwizzleNV);
    if(strcmp(pName, "vkCmdSetCoverageToColorEnableNV") == 0 && (!device || device_dispatch_table(device)->CmdSetCoverageToColorEnableNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetCoverageToColorEnableNV);
    if(strcmp(pName, "vkCmdSetCoverageToColorLocationNV") == 0 && (!device || device_dispatch_table(device)->CmdSetCoverageToColorLocationNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetCoverageToColorLocationNV);
    if(strcmp(pName, "vkCmdSetCoverageModulationModeNV") == 0 && (!device || device_dispatch_table(device)->CmdSetCoverageModulationModeNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetCoverageModulationModeNV);
    if(strcmp(pName, "vkCmdSetCoverageModulationTableEnableNV") == 0 && (!device || device_dispatch_table(device)->CmdSetCoverageModulationTableEnableNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetCoverageModulationTableEnableNV);
    if(strcmp(pName, "vkCmdSetCoverageModulationTableNV") == 0 && (!device || device_dispatch_table(device)->CmdSetCoverageModulationTableNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetCoverageModulationTableNV);
    if(strcmp(pName, "vkCmdSetShadingRateImageEnableNV") == 0 && (!device || device_dispatch_table(device)->CmdSetShadingRateImageEnableNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetShadingRateImageEnableNV);
    if(strcmp(pName, "vkCmdSetRepresentativeFragmentTestEnableNV") == 0 && (!device || device_dispatch_table(device)->CmdSetRepresentativeFragmentTestEnableNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetRepresentativeFragmentTestEnableNV);
    if(strcmp(pName, "vkCmdSetCoverageReductionModeNV") == 0 && (!device || device_dispatch_table(device)->CmdSetCoverageReductionModeNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetCoverageReductionModeNV);
    if(strcmp(pName, "vkGetShaderModuleIdentifierEXT") == 0 && (!device || device_dispatch_table(device)->GetShaderModuleIdentifierEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetShaderModuleIdentifierEXT);
    if(strcmp(pName, "vkGetShaderModuleCreateInfoIdentifierEXT") == 0 && (!device || device_dispatch_table(device)->GetShaderModuleCreateInfoIdentifierEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetShaderModuleCreateInfoIdentifierEXT);
    if(strcmp(pName, "vkCreateOpticalFlowSessionNV") == 0 && (!device || device_dispatch_table(device)->CreateOpticalFlowSessionNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateOpticalFlowSessionNV);
    if(strcmp(pName, "vkDestroyOpticalFlowSessionNV") == 0 && (!device || device_dispatch_table(device)->DestroyOpticalFlowSessionNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyOpticalFlowSessionNV);
    if(strcmp(pName, "vkBindOpticalFlowSessionImageNV") == 0 && (!device || device_dispatch_table(device)->BindOpticalFlowSessionImageNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBindOpticalFlowSessionImageNV);
    if(strcmp(pName, "vkCmdOpticalFlowExecuteNV") == 0 && (!device || device_dispatch_table(device)->CmdOpticalFlowExecuteNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdOpticalFlowExecuteNV);
    if(strcmp(pName, "vkCmdBindIndexBuffer2KHR") == 0 && (!device || device_dispatch_table(device)->CmdBindIndexBuffer2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindIndexBuffer2KHR);
    if(strcmp(pName, "vkGetRenderingAreaGranularityKHR") == 0 && (!device || device_dispatch_table(device)->GetRenderingAreaGranularityKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetRenderingAreaGranularityKHR);
    if(strcmp(pName, "vkGetDeviceImageSubresourceLayoutKHR") == 0 && (!device || device_dispatch_table(device)->GetDeviceImageSubresourceLayoutKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceImageSubresourceLayoutKHR);
    if(strcmp(pName, "vkAntiLagUpdateAMD") == 0 && (!device || device_dispatch_table(device)->AntiLagUpdateAMD))
        return reinterpret_cast<PFN_vkVoidFunction>(vkAntiLagUpdateAMD);
    if(strcmp(pName, "vkCreateShadersEXT") == 0 && (!device || device_dispatch_table(device)->CreateShadersEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateShadersEXT);
    if(strcmp(pName, "vkDestroyShaderEXT") == 0 && (!device || device_dispatch_table(device)->DestroyShaderEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyShaderEXT);
    if(strcmp(pName, "vkGetShaderBinaryDataEXT") == 0 && (!device || device_dispatch_table(device)->GetShaderBinaryDataEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetShaderBinaryDataEXT);
    if(strcmp(pName, "vkCmdBindShadersEXT") == 0 && (!device || device_dispatch_table(device)->CmdBindShadersEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindShadersEXT);
    if(strcmp(pName, "vkGetFramebufferTilePropertiesQCOM") == 0 && (!device || device_dispatch_table(device)->GetFramebufferTilePropertiesQCOM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetFramebufferTilePropertiesQCOM);
    if(strcmp(pName, "vkGetDynamicRenderingTilePropertiesQCOM") == 0 && (!device || device_dispatch_table(device)->GetDynamicRenderingTilePropertiesQCOM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDynamicRenderingTilePropertiesQCOM);
    if(strcmp(pName, "vkSetLatencySleepModeNV") == 0 && (!device || device_dispatch_table(device)->SetLatencySleepModeNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetLatencySleepModeNV);
    if(strcmp(pName, "vkLatencySleepNV") == 0 && (!device || device_dispatch_table(device)->LatencySleepNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkLatencySleepNV);
    if(strcmp(pName, "vkSetLatencyMarkerNV") == 0 && (!device || device_dispatch_table(device)->SetLatencyMarkerNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetLatencyMarkerNV);
    if(strcmp(pName, "vkGetLatencyTimingsNV") == 0 && (!device || device_dispatch_table(device)->GetLatencyTimingsNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetLatencyTimingsNV);
    if(strcmp(pName, "vkQueueNotifyOutOfBandNV") == 0 && (!device || device_dispatch_table(device)->QueueNotifyOutOfBandNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueNotifyOutOfBandNV);
    if(strcmp(pName, "vkCmdSetAttachmentFeedbackLoopEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetAttachmentFeedbackLoopEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetAttachmentFeedbackLoopEnableEXT);
#if defined(VK_USE_PLATFORM_SCREEN_QNX)
    if(strcmp(pName, "vkGetScreenBufferPropertiesQNX") == 0 && (!device || device_dispatch_table(device)->GetScreenBufferPropertiesQNX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetScreenBufferPropertiesQNX);
#endif // VK_USE_PLATFORM_SCREEN_QNX
    if(strcmp(pName, "vkCmdBindDescriptorSets2KHR") == 0 && (!device || device_dispatch_table(device)->CmdBindDescriptorSets2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindDescriptorSets2KHR);
    if(strcmp(pName, "vkCmdPushConstants2KHR") == 0 && (!device || device_dispatch_table(device)->CmdPushConstants2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPushConstants2KHR);
    if(strcmp(pName, "vkCmdPushDescriptorSet2KHR") == 0 && (!device || device_dispatch_table(device)->CmdPushDescriptorSet2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPushDescriptorSet2KHR);
    if(strcmp(pName, "vkCmdPushDescriptorSetWithTemplate2KHR") == 0 && (!device || device_dispatch_table(device)->CmdPushDescriptorSetWithTemplate2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPushDescriptorSetWithTemplate2KHR);
    if(strcmp(pName, "vkCmdSetDescriptorBufferOffsets2EXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDescriptorBufferOffsets2EXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDescriptorBufferOffsets2EXT);
    if(strcmp(pName, "vkCmdBindDescriptorBufferEmbeddedSamplers2EXT") == 0 && (!device || device_dispatch_table(device)->CmdBindDescriptorBufferEmbeddedSamplers2EXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindDescriptorBufferEmbeddedSamplers2EXT);

    return nullptr;
}

EXPORT_FUNCTION VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vkGetInstanceProcAddr(VkInstance instance, const char* pName)
{
    auto instance_func = api_dump_known_instance_functions(instance, pName);
    if (instance_func) return instance_func;

    // Make sure that device functions queried through GIPA works
    auto device_func = api_dump_known_device_functions(NULL, pName);
    if (device_func) return device_func;

    // Haven't created an instance yet, exit now since there is no instance_dispatch_table
    if(instance_dispatch_table(instance)->GetInstanceProcAddr == NULL)
        return nullptr;
    return instance_dispatch_table(instance)->GetInstanceProcAddr(instance, pName);
}

EXPORT_FUNCTION VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vkGetDeviceProcAddr(VkDevice device, const char* pName)
{
    auto device_func = api_dump_known_device_functions(device, pName);
    if (device_func) return device_func;

    // Haven't created a device yet, exit now since there is no device_dispatch_table
    if(device_dispatch_table(device)->GetDeviceProcAddr == NULL)
        return nullptr;
    return device_dispatch_table(device)->GetDeviceProcAddr(device, pName);
}
