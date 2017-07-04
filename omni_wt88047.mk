# Copyright (C) 2016 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

#
# This file is the build configuration for a full Android
# build for grouper hardware. This cleanly combines a set of
# device-specific aspects (drivers) with a device-agnostic
# product configuration (apps).
#

# Get the prebuilt list of APNs
$(call inherit-product, vendor/omni/config/gsm.mk)

# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/aosp_base_telephony.mk)

# must be before including omni part
TARGET_BOOTANIMATION_SIZE := 640x362

# Inherit from our custom product configuration
$(call inherit-product, vendor/omni/config/common.mk)

# Inherit AOSP device configuration
$(call inherit-product, device/xiaomi/wt88047/wt88047.mk)

# Must define platform variant before including any common things
TARGET_BOARD_PLATFORM_VARIANT := msm8916

TARGET_OTA_ASSERT_DEVICE := HM2014811,HM2014812,HM2014813,HM2014814,HM2014815,HM2014816,HM2014817,HM2014818,HM2014819,HM2014820,HM2014821,HM2014112,wt88047,wt86047

PRODUCT_NAME := omni_wt88047
PRODUCT_DEVICE := wt88047
BOARD_VENDOR := Xiaomi
PRODUCT_MANUFACTURER := Xiaomi

PRODUCT_GMS_CLIENTID_BASE := android-xiaomi

PRODUCT_BUILD_PROP_OVERRIDES += \
    BUILD_FINGERPRINT=Xiaomi/wt88047/wt88047:5.1.1/LMY47V/V8.2.1.0.LHJMIDL:user/release-keys \
    PRIVATE_BUILD_DESC="wt88047-user 5.1.1 LMY47V V8.2.1.0.LHJMIDL release-keys"
