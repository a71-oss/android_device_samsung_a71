/*
 * Copyright (C) 2024 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

package android.hardware.display;

import android.content.Context;
import android.content.Intent;
import android.os.UserHandle;
import android.util.Log;

public final class Utils {

    private static final String TAG = "UDFPSUtils";
    private static final boolean DEBUG = false;

    protected static void startService(Context context) {
        if (DEBUG) Log.d(TAG, "Starting service");
        context.startServiceAsUser(new Intent(context, SamsungUdfpsHandlerService.class),
                UserHandle.CURRENT);
    }

    protected static void stopService(Context context) {
        if (DEBUG) Log.d(TAG, "Stopping service");
        context.stopServiceAsUser(new Intent(context, SamsungUdfpsHandlerService.class),
                UserHandle.CURRENT);
    }
}
