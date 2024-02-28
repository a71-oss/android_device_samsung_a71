/*
 * Copyright (C) 2024 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <android-base/file.h>
#include <android-base/strings.h>

#include <fstream>

#include "SunlightEnhancement.h"

using android::base::ReadFileToString;
using android::base::Trim;
using android::base::WriteStringToFile;

namespace vendor {
namespace lineage {
namespace livedisplay {
namespace V2_0 {
namespace samsung {

static constexpr const char* kBrightnessPath = "/sys/class/backlight/panel0-backlight/brightness";

// Methods from ::vendor::lineage::livedisplay::V2_0::ISunlightEnhancement follow.
bool SunlightEnhancement::isSupported() {
    std::fstream brightness(kBrightnessPath, brightness.in | brightness.out);
    return brightness.good();
}

// Methods from ::vendor::lineage::livedisplay::V2_0::IAdaptiveBacklight follow.
Return<bool> SunlightEnhancement::isEnabled() {
    std::string brightness;
    ReadFileToString(kBrightnessPath, &brightness);
    return brightness == "486";
}

Return<bool> SunlightEnhancement::setEnabled(bool enabled) {
    if (enabled) {
        ReadFileToString(kBrightnessPath, &previous_brightness);
        return WriteStringToFile("486", kBrightnessPath, true);
    } else if (!previous_brightness.empty()) {
        return WriteStringToFile(previous_brightness, kBrightnessPath, true);
    }
    return true;
}

}  // namespace samsung
}  // namespace V2_0
}  // namespace livedisplay
}  // namespace lineage
}  // namespace vendor
