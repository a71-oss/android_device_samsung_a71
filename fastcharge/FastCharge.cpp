/*
 * Copyright (C) 2024 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define LOG_TAG "fastcharge@1.0-service.a71"

#define FASTCHARGE_DEFAULT_SETTING true
#define FASTCHARGE_PATH "/sys/class/sec/switch/afc_disable"

#include "FastCharge.h"
#include <android-base/logging.h>
#include <cutils/properties.h>

#include <fstream>
#include <iostream>

namespace vendor {
namespace lineage {
namespace fastcharge {
namespace V1_0 {
namespace implementation {

static constexpr const char* kFastChargingProp = "persist.vendor.sec.fastchg_enabled";

/*
 * Write value to path and close file.
 */
template <typename T>
static void set(const std::string& path, const T& value) {
    std::ofstream file(path);

    if (!file) {
        PLOG(ERROR) << "Failed to open: " << path;
        return;
    }

    LOG(DEBUG) << "write: " << path << " value: " << value;

    file << value << std::endl;

    if (!file) {
        PLOG(ERROR) << "Failed to write: " << path << " value: " << value;
    }
}

template <typename T>
static T get(const std::string& path, const T& def) {
    std::ifstream file(path);

    if (!file) {
        PLOG(ERROR) << "Failed to open: " << path;
        return def;
    }

    T result;

    file >> result;

    if (file.fail()) {
        PLOG(ERROR) << "Failed to read: " << path;
        return def;
    } else {
        LOG(DEBUG) << "read: " << path << " value: " << result;
        return result;
    }
}

FastCharge::FastCharge() {
    setEnabled(property_get_bool(kFastChargingProp, FASTCHARGE_DEFAULT_SETTING));
}

Return<bool> FastCharge::isEnabled() {
    return get(FASTCHARGE_PATH, 0) < 1;
}

Return<bool> FastCharge::setEnabled(bool enable) {
    set(FASTCHARGE_PATH, enable ? 0 : 1);

    bool enabled = isEnabled();
    property_set(kFastChargingProp, enabled ? "true" : "false");

    return enabled;
}

}  // namespace implementation
}  // namespace V1_0
}  // namespace fastcharge
}  // namespace lineage
}  // namespace vendor
