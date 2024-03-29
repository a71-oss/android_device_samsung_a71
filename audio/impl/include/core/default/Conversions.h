/*
 * Copyright (C) 2024 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ANDROID_HARDWARE_AUDIO_CONVERSIONS_H_
#define ANDROID_HARDWARE_AUDIO_CONVERSIONS_H_

#include PATH(android/hardware/audio/FILE_VERSION/types.h)

#include <string>

#include <system/audio.h>

namespace android {
namespace hardware {
namespace audio {
namespace CPP_VERSION {
namespace implementation {

using namespace ::android::hardware::audio::common::CPP_VERSION;
using namespace ::android::hardware::audio::CPP_VERSION;

std::string deviceAddressToHal(const DeviceAddress& address);

#if MAJOR_VERSION >= 4
bool halToMicrophoneCharacteristics(MicrophoneInfo* pDst,
                                    const struct audio_microphone_characteristic_t& src);
#endif

}  // namespace implementation
}  // namespace CPP_VERSION
}  // namespace audio
}  // namespace hardware
}  // namespace android

#endif  // ANDROID_HARDWARE_AUDIO_CONVERSIONS_H_
