/*
 * Copyright (C) 2024 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ANDROID_HARDWARE_AUDIO_V4_0_PRIMARYDEVICE_H
#define ANDROID_HARDWARE_AUDIO_V4_0_PRIMARYDEVICE_H

#include <android/hardware/audio/4.0/IPrimaryDevice.h>

#include "Device.h"

#define AUDIO_HAL_VERSION V4_0
#include <core/all-versions/default/PrimaryDevice.h>
#undef AUDIO_HAL_VERSION

#endif  // ANDROID_HARDWARE_AUDIO_V4_0_PRIMARYDEVICE_H
