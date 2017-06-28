/*
   Copyright (c) 2014, The Linux Foundation. All rights reserved.
   Copyright (C) 2015-2016, The CyanogenMod Project
   Copyright (C) 2017, The LineageOS Project

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <cstdlib>
#include <fstream>
#include <string>
#include <sys/sysinfo.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#include "init_msm8916.h"

char const *heapstartsize;
char const *heapgrowthlimit;
char const *heapsize;
char const *heapminfree;

void check_device()
{
    struct sysinfo sys;

    sysinfo(&sys);

    if (sys.totalram > 1024ull * 1024 * 1024) {
        // from - phone-xhdpi-2048-dalvik-heap.mk
        heapstartsize = "8m";
        heapgrowthlimit = "192m";
        heapsize = "512m";
        heapminfree = "512k";
    } else {
        // from - phone-xhdpi-1024-dalvik-heap.mk
        heapstartsize = "8m";
        heapgrowthlimit = "96m";
        heapsize = "256m";
        heapminfree = "2m";
    }
}

void property_override(char const prop[], char const value[])
{
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void init_target_properties()
{
    check_device();

    property_set("dalvik.vm.heapstartsize", heapstartsize);
    property_set("dalvik.vm.heapgrowthlimit", heapgrowthlimit);
    property_set("dalvik.vm.heapsize", heapsize);
    property_set("dalvik.vm.heaptargetutilization", "0.75");
    property_set("dalvik.vm.heapminfree", heapminfree);
    property_set("dalvik.vm.heapmaxfree", "8m");

    std::ifstream fin;
    std::string buf;

    fin.open("/proc/cmdline");
    while (getline(fin, buf, ' '))
        if (buf.find("board_id") != std::string::npos)
            break;
    fin.close();

    /* S88047A1 and S88047A2 */
    if ((buf.find("S88047A1") != std::string::npos) ||
        (buf.find("S88047A2") != std::string::npos)) {
        property_override("ro.build.product", "HM2014811");
        property_override("ro.product.device", "HM2014811");
        property_override("ro.product.model", "2014811");
        property_override("ro.product.name", "2014811");
    }
    /* S88047B1 */
    else if (buf.find("S88047B1") != std::string::npos) {
        property_override("ro.build.product", "HM2014812");
        property_override("ro.product.device", "HM2014812");
        property_override("ro.product.model", "2014812");
        property_override("ro.product.name", "2014812");
        property_override("ro.telephony.default_network", "22,22");
        property_set("telephony.lteOnCdmaDevice", "1");
        property_set("persist.radio.sglte.eons_domain", "ps");
    }
    /* S88047B2 */
    else if (buf.find("S88047B2") != std::string::npos) {
        property_override("ro.build.product", "HM2014821");
        property_override("ro.product.device", "HM2014821");
        property_override("ro.product.model", "2014821");
        property_override("ro.product.name", "2014821");
        property_override("ro.telephony.default_network", "22,22");
        property_set("telephony.lteOnCdmaDevice", "1");
        property_set("persist.radio.sglte.eons_domain", "ps");
    }
    /* S88047C1 */
    else if (buf.find("S88047C1") != std::string::npos) {
        property_override("ro.build.product", "HM2014818");
        property_override("ro.product.device", "HM2014818");
        property_override("ro.product.model", "2014818");
        property_override("ro.product.name", "2014818");
        property_set("persist.dbg.volte_avail_ovr", "1");
        property_set("persist.dbg.vt_avail_ovr", "1");
    }
    /* S88047D1 */
    else if (buf.find("S88047D1") != std::string::npos) {
        property_override("ro.build.product", "HM2014819");
        property_override("ro.product.device", "HM2014819");
        property_override("ro.product.model", "2014819");
        property_override("ro.product.name", "2014819");
    }
    /* S88047E1 */
    else if (buf.find("S88047E1") != std::string::npos) {
        property_override("ro.build.product", "HM2014817");
        property_override("ro.product.device", "HM2014817");
        property_override("ro.product.model", "2014817");
        property_override("ro.product.name", "2014817");
    }
    /* S86047A1 and S86047A1_CD */
    else if (buf.find("S86047A1") != std::string::npos) {
        property_override("ro.build.product", "HM2014813");
        property_override("ro.product.device", "HM2014813");
        property_override("ro.product.model", "2014813");
        property_override("ro.product.name", "2014813");
    }
    /* S86047A2 and S86047A2_CD */
    else if (buf.find("S86047A2") != std::string::npos) {
        property_override("ro.build.product", "HM2014112");
        property_override("ro.product.device", "HM2014112");
        property_override("ro.product.model", "2014112");
        property_override("ro.product.name", "2014112");
    }
}
