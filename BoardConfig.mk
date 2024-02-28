#
# Copyright (C) 2024 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

BUILD_BROKEN_VENDOR_PROPERTY_NAMESPACE := true

DEVICE_PATH := device/samsung/a71

# 64 Bit
TARGET_USES_64_BIT_BINDER := true

# Architecture
TARGET_ARCH := arm64
TARGET_ARCH_VARIANT := armv8-a
TARGET_CPU_ABI := arm64-v8a
TARGET_CPU_ABI2 :=
TARGET_CPU_VARIANT := generic

TARGET_2ND_ARCH := arm
TARGET_2ND_ARCH_VARIANT := armv7-a-neon
TARGET_2ND_CPU_ABI := armeabi-v7a
TARGET_2ND_CPU_ABI2 := armeabi
TARGET_2ND_CPU_VARIANT := cortex-a9

# Assert
TARGET_OTA_ASSERT_DEVICE := a71

# Board
TARGET_BOARD_NAME := SRPSF18B008

# Security Patch Level
VENDOR_SECURITY_PATCH := 2022-09-01

# Get non-open-source specific aspects
include vendor/samsung/a71/BoardConfigVendor.mk
