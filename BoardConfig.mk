#
# Copyright (C) 2016 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

FORCE_32_BIT := true

include device/cyanogen/msm8916-common/BoardConfigCommon.mk

DEVICE_PATH := device/wingtech/wt88047
include $(DEVICE_PATH)/board/*.mk

# inherit from the proprietary version
include vendor/wingtech/wt88047/BoardConfigVendor.mk

# Kernel Toolchains
#KERNEL_TOOLCHAIN := $(ANDROID_BUILD_TOP)/prebuilts/gcc/$(HOST_OS)-x86/arm/arm-eabi-6.0/bin
#KERNEL_TOOLCHAIN_PREFIX= arm-eabi-

# Assertions
TARGET_RELEASETOOLS_EXTENSIONS := device/cyanogen/msm8916-common

ALLOW_MISSING_DEPENDENCIES=true
