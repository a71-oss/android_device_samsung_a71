/*
 * Copyright (C) 2024 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ANDROID_HARDWARE_AUDIO_UTIL_H
#define ANDROID_HARDWARE_AUDIO_UTIL_H

#include PATH(android/hardware/audio/FILE_VERSION/types.h)

#include <algorithm>
#include <vector>

#include <system/audio.h>

namespace android {
namespace hardware {
namespace audio {
namespace CPP_VERSION {
namespace implementation {

using namespace ::android::hardware::audio::common::CPP_VERSION;
using namespace ::android::hardware::audio::CPP_VERSION;

/** @return true if gain is between 0 and 1 included. */
constexpr bool isGainNormalized(float gain) {
    return gain >= 0.0 && gain <= 1.0;
}

namespace util {

template <typename T>
inline bool element_in(T e, const std::vector<T>& v) {
    return std::find(v.begin(), v.end(), e) != v.end();
}

static inline Result analyzeStatus(status_t status) {
    switch (status) {
        case 0:
            return Result::OK;
        case -EINVAL:
            return Result::INVALID_ARGUMENTS;
        case -ENODATA:
            return Result::INVALID_STATE;
        case -ENODEV:
            return Result::NOT_INITIALIZED;
        case -ENOSYS:
            return Result::NOT_SUPPORTED;
        default:
            return Result::INVALID_STATE;
    }
}

static inline Result analyzeStatus(const char* className, const char* funcName, status_t status,
                                   const std::vector<int>& ignoreErrors = {}) {
    if (status != 0 && !element_in(-status, ignoreErrors)) {
        ALOGW("Error from HAL %s in function %s: %s", className, funcName, strerror(-status));
    }
    return analyzeStatus(status);
}

}  // namespace util
}  // namespace implementation
}  // namespace CPP_VERSION
}  // namespace audio
}  // namespace hardware
}  // namespace android

#endif  // ANDROID_HARDWARE_AUDIO_UTIL_H
