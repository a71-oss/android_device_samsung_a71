/*
 * Copyright (C) 2024 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define LOG_TAG "fastcharge@1.0-service.a71"

#include <android-base/logging.h>
#include <hidl/HidlTransportSupport.h>

#include "FastCharge.h"

using android::hardware::configureRpcThreadpool;
using android::hardware::joinRpcThreadpool;

using vendor::lineage::fastcharge::V1_0::IFastCharge;
using vendor::lineage::fastcharge::V1_0::implementation::FastCharge;

using android::OK;
using android::status_t;

int main() {
    android::sp<FastCharge> service = new FastCharge();

    configureRpcThreadpool(1, true);

    status_t status = service->registerAsService();
    if (status != OK) {
        LOG(ERROR) << "Cannot register FastCharge HAL service.";
        return 1;
    }

    LOG(INFO) << "FastCharge HAL service ready.";

    joinRpcThreadpool();

    LOG(ERROR) << "FastCharge HAL service failed to join thread pool.";
    return 1;
}
