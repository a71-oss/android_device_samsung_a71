/*
 * Copyright (C) 2024 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef VENDOR_LINEAGE_FASTCHARGE_V1_0_FASTCHARGE_H
#define VENDOR_LINEAGE_FASTCHARGE_V1_0_FASTCHARGE_H

#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <vendor/lineage/fastcharge/1.0/IFastCharge.h>

namespace vendor {
namespace lineage {
namespace fastcharge {
namespace V1_0 {
namespace implementation {

using ::android::sp;
using ::android::hardware::hidl_array;
using ::android::hardware::hidl_memory;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;

using ::vendor::lineage::fastcharge::V1_0::IFastCharge;


struct FastCharge : public IFastCharge {
    Return<bool> isEnabled() override;
    Return<bool> setEnabled(bool enable) override;
};

}  // namespace implementation
}  // namespace V1_0
}  // namespace fastcharge
}  // namespace lineage
}  // namespace vendor

#endif  // VENDOR_LINEAGE_FASTCHARGE_V1_0_FASTCHARGE_H
