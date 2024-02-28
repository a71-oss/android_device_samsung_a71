/*
 * Copyright (C) 2024 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ANDROID_HARDWARE_POWER_POWER_H
#define ANDROID_HARDWARE_POWER_POWER_H

#include <aidl/android/hardware/power/BnPower.h>
#include "power-common.h"

namespace aidl {
namespace android {
namespace hardware {
namespace power {
namespace impl {

class Power : public BnPower {
  public:
    Power() : BnPower() { power_init(); }
    ndk::ScopedAStatus setMode(Mode type, bool enabled) override;
    ndk::ScopedAStatus isModeSupported(Mode type, bool* _aidl_return) override;
    ndk::ScopedAStatus setBoost(Boost type, int32_t durationMs) override;
    ndk::ScopedAStatus isBoostSupported(Boost type, bool* _aidl_return) override;
};

}  // namespace impl
}  // namespace power
}  // namespace hardware
}  // namespace android
}  // namespace aidl
#endif  // ANDROID_HARDWARE_POWER_POWER_H
