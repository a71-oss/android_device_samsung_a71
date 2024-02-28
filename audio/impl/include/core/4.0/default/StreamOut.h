/*
 * Copyright (C) 2024 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ANDROID_HARDWARE_AUDIO_V4_0_STREAMOUT_H
#define ANDROID_HARDWARE_AUDIO_V4_0_STREAMOUT_H

#include <android/hardware/audio/4.0/IStreamOut.h>

#include "Device.h"
#include "Stream.h"

#define AUDIO_HAL_VERSION V4_0
#include <core/all-versions/default/StreamOut.h>
#undef AUDIO_HAL_VERSION

#endif  // ANDROID_HARDWARE_AUDIO_V4_0_STREAMOUT_H
