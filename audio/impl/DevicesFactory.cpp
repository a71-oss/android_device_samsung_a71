/*
 * Copyright (C) 2024 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define LOG_TAG "DevicesFactoryHAL"

#include "core/default/DevicesFactory.h"
#include "core/default/Device.h"
#include "core/default/PrimaryDevice.h"

#include <string.h>

#include <android/log.h>

namespace android {
namespace hardware {
namespace audio {
namespace CPP_VERSION {
namespace implementation {

#if MAJOR_VERSION == 2
Return<void> DevicesFactory::openDevice(IDevicesFactory::Device device, openDevice_cb _hidl_cb) {
    switch (device) {
        case IDevicesFactory::Device::PRIMARY:
            return openDevice<PrimaryDevice>(AUDIO_HARDWARE_MODULE_ID_PRIMARY, _hidl_cb);
        case IDevicesFactory::Device::A2DP:
            return openDevice(AUDIO_HARDWARE_MODULE_ID_A2DP, _hidl_cb);
        case IDevicesFactory::Device::USB:
            return openDevice(AUDIO_HARDWARE_MODULE_ID_USB, _hidl_cb);
        case IDevicesFactory::Device::R_SUBMIX:
            return openDevice(AUDIO_HARDWARE_MODULE_ID_REMOTE_SUBMIX, _hidl_cb);
        case IDevicesFactory::Device::STUB:
            return openDevice(AUDIO_HARDWARE_MODULE_ID_STUB, _hidl_cb);
    }
    _hidl_cb(Result::INVALID_ARGUMENTS, nullptr);
    return Void();
}
#elif MAJOR_VERSION >= 4
Return<void> DevicesFactory::openDevice(const hidl_string& moduleName, openDevice_cb _hidl_cb) {
    if (moduleName == AUDIO_HARDWARE_MODULE_ID_PRIMARY) {
        return openDevice<PrimaryDevice>(moduleName.c_str(), _hidl_cb);
    }
    return openDevice(moduleName.c_str(), _hidl_cb);
}
Return<void> DevicesFactory::openPrimaryDevice(openPrimaryDevice_cb _hidl_cb) {
    return openDevice<PrimaryDevice>(AUDIO_HARDWARE_MODULE_ID_PRIMARY, _hidl_cb);
}
#endif

Return<void> DevicesFactory::openDevice(const char* moduleName, openDevice_cb _hidl_cb) {
    return openDevice<implementation::Device>(moduleName, _hidl_cb);
}

template <class DeviceShim, class Callback>
Return<void> DevicesFactory::openDevice(const char* moduleName, Callback _hidl_cb) {
    audio_hw_device_t* halDevice;
    Result retval(Result::INVALID_ARGUMENTS);
    sp<DeviceShim> result;
    int halStatus = loadAudioInterface(moduleName, &halDevice);
    if (halStatus == OK) {
        result = new DeviceShim(halDevice);
        retval = Result::OK;
    } else if (halStatus == -EINVAL) {
        retval = Result::NOT_INITIALIZED;
    }
    _hidl_cb(retval, result);
    return Void();
}

// static
int DevicesFactory::loadAudioInterface(const char* if_name, audio_hw_device_t** dev) {
    const hw_module_t* mod;
    int rc;

    rc = hw_get_module_by_class(AUDIO_HARDWARE_MODULE_ID, if_name, &mod);
    if (rc) {
        ALOGE("%s couldn't load audio hw module %s.%s (%s)", __func__, AUDIO_HARDWARE_MODULE_ID,
              if_name, strerror(-rc));
        goto out;
    }
    rc = audio_hw_device_open(mod, dev);
    if (rc) {
        ALOGE("%s couldn't open audio hw device in %s.%s (%s)", __func__, AUDIO_HARDWARE_MODULE_ID,
              if_name, strerror(-rc));
        goto out;
    }
    if ((*dev)->common.version < AUDIO_DEVICE_API_VERSION_MIN) {
        ALOGE("%s wrong audio hw device version %04x", __func__, (*dev)->common.version);
        rc = -EINVAL;
        audio_hw_device_close(*dev);
        goto out;
    }
    return OK;

out:
    *dev = NULL;
    return rc;
}

IDevicesFactory* HIDL_FETCH_IDevicesFactory(const char* name) {
    return strcmp(name, "default") == 0 ? new DevicesFactory() : nullptr;
}

}  // namespace implementation
}  // namespace CPP_VERSION
}  // namespace audio
}  // namespace hardware
}  // namespace android
