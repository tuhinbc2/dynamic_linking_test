# Copyright (C) 2009 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

#################################### core module ################################

LOCAL_PATH := $(call my-dir)
$(warning $(LOCAL_PATH))
include $(CLEAR_VARS)

LOCAL_MODULE    := libcore
LOCAL_SRC_FILES := coreproject.cpp
LOCAL_CFLAGS    := -g -std=gnu++11

LOCAL_STATIC_LIBRARIES := libcurl
LOCAL_C_INCLUDES := ../third_party_lib/libcurl/include/
LOCAL_LDLIBS := -lz -llog
$(warning $(LOCAL_C_INCLUDES))
include $(BUILD_SHARED_LIBRARY)


#################################### curl module ################################

#LOCAL_PATH := $(call my-dir)
$(warning $(LOCAL_PATH))
include $(CLEAR_VARS)
LOCAL_MODULE := libcurl
LOCAL_SRC_FILES := ../third_party_lib/libcurl/$(TARGET_ARCH_ABI)/libcurl.a
include $(PREBUILT_STATIC_LIBRARY)
