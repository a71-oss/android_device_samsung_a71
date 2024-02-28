#
# Copyright (C) 2024 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
    BiometricsFingerprint.cpp \
    service.cpp

LOCAL_SHARED_LIBRARIES := \
    libbase \
    libhardware \
    libhidlbase \
    liblog \
    libutils \
    android.hardware.biometrics.fingerprint@2.1 \
    android.hardware.biometrics.fingerprint@2.2 \
    android.hardware.biometrics.fingerprint@2.3

ifeq ($(TARGET_SEC_FP_CALL_NOTIFY_ON_CANCEL),true)
    LOCAL_CFLAGS += -DCALL_NOTIFY_ON_CANCEL
endif

ifeq ($(TARGET_SEC_FP_USES_PERCENTAGE_SAMPLES),true)
    LOCAL_CFLAGS += -DUSES_PERCENTAGE_SAMPLES
endif

ifeq ($(TARGET_SEC_FP_CALL_CANCEL_ON_ENROLL_COMPLETION),true)
    LOCAL_CFLAGS += -DCALL_CANCEL_ON_ENROLL_COMPLETION
endif

ifeq ($(TARGET_SEC_FP_HAS_FINGERPRINT_GESTURES),true)
    LOCAL_CFLAGS += -DHAS_FINGERPRINT_GESTURES
endif

ifeq ($(TARGET_SEC_FP_REQUEST_FORCE_CALIBRATE),true)
    LOCAL_CFLAGS += -DREQUEST_FORCE_CALIBRATE
endif

LOCAL_MODULE := android.hardware.biometrics.fingerprint@2.3-service-samsung.sm6150
LOCAL_INIT_RC := android.hardware.biometrics.fingerprint@2.3-service-samsung.sm6150.rc
LOCAL_VINTF_FRAGMENTS := android.hardware.biometrics.fingerprint@2.3-service-samsung.sm6150.xml
LOCAL_MODULE_RELATIVE_PATH := hw
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_OWNER := samsung
LOCAL_VENDOR_MODULE := true

include $(BUILD_EXECUTABLE)
