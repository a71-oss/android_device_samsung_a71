/*
 * Copyright (C) 2024 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define LOG_TAG "android.hardware.biometrics.fingerprint@2.3-service-samsung.sm6150"

#include <android-base/logging.h>
#include <hidl/HidlTransportSupport.h>
#include <utils/Errors.h>

#include "BiometricsFingerprint.h"

using android::hardware::configureRpcThreadpool;
using android::hardware::joinRpcThreadpool;

using android::hardware::biometrics::fingerprint::V2_3::IBiometricsFingerprint;
using android::hardware::biometrics::fingerprint::V2_3::implementation::BiometricsFingerprint;

using android::OK;
using android::sp;

int main() {
    android::sp<IBiometricsFingerprint> bio = BiometricsFingerprint::getInstance();

    configureRpcThreadpool(1, true);

    if (bio == nullptr || bio->registerAsService() != OK) {
        LOG(ERROR) << "Could not register service for Fingerprint HAL";
        goto shutdown;
    }

    LOG(INFO) << "Fingerprint HAL service is Ready.";
    joinRpcThreadpool();

shutdown:
    // In normal operation, we don't expect the thread pool to shutdown
    LOG(ERROR) << "Fingerprint HAL failed to join thread pool.";
    return 1;
}
