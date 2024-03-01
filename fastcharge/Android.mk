#
# Copyright (C) 2024 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
    FastCharge.cpp \
    service.cpp

LOCAL_SHARED_LIBRARIES := \
    libbase \
    libbinder \
    libcutils \
    libhidlbase \
    libutils \
    vendor.lineage.fastcharge@1.0

LOCAL_MODULE := vendor.lineage.fastcharge@1.0-service.a71
LOCAL_INIT_RC := vendor.lineage.fastcharge@1.0-service.a71.rc
LOCAL_MODULE_RELATIVE_PATH := hw
LOCAL_MODULE_TAGS := optional
LOCAL_VINTF_FRAGMENTS := vendor.lineage.fastcharge@1.0-service.a71.xml
LOCAL_VENDOR_MODULE := true

include $(BUILD_EXECUTABLE)
