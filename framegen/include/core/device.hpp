#pragma once

#include "core/instance.hpp"

#include <vulkan/vulkan_core.h>

#include <cstdint>
#include <memory>

namespace LSFG::Core {

    class Image;

    class Device {
    public:
        Device(const Instance& instance, uint64_t deviceUUID);

        [[nodiscard]] auto handle() const { return *this->device; }
        [[nodiscard]] VkPhysicalDevice getPhysicalDevice() const { return this->physicalDevice; }
        [[nodiscard]] uint32_t getComputeFamilyIdx() const { return this->computeFamilyIdx; }
        [[nodiscard]] VkQueue getComputeQueue() const { return this->computeQueue; }
        [[nodiscard]] const Image& getNullImage() const;

        Device(const Core::Device&) noexcept = default;
        Device& operator=(const Core::Device&) noexcept = default;
        Device(Device&&) noexcept = default;
        Device& operator=(Device&&) noexcept = default;
        ~Device();

    private:
        mutable std::shared_ptr<Image> nullImage;
        std::shared_ptr<VkDevice> device;
        VkPhysicalDevice physicalDevice{};
        uint32_t computeFamilyIdx{0};
        VkQueue computeQueue{};
    };

}
