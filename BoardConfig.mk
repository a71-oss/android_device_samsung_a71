#
# Copyright (C) 2024 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

BUILD_BROKEN_VENDOR_PROPERTY_NAMESPACE := true

DEVICE_PATH := device/samsung/a71

# Assert
TARGET_OTA_ASSERT_DEVICE := a71

# Board
TARGET_BOARD_NAME := SRPSF18B008

# Security Patch Level
VENDOR_SECURITY_PATCH := 2022-09-01

# Get non-open-source specific aspects
include vendor/samsung/a71/BoardConfigVendor.mk
