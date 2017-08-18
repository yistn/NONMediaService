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
#

# Test for gtest. Run using 'runtest'.
# The linux build and tests are run under valgrind by 'runtest'.

LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
#$(LOCAL_PATH)/../Android.mk
# TODO: Refactor these as 1st class build templates as suggested in
# review of the original import.

LOCAL_C_INCLUDES += \
    $(LOCAL_PATH)/../include \
    $(LOCAL_PATH)/..

# calc  
LOCAL_MODULE := HNONMediaService  
LOCAL_MODULE_TAGS := eng #optional  
LOCAL_SRC_FILES := NONMediaServiceExec.cpp   
  
#LOCAL_PRELINK_MODULE := false  
LOCAL_SHARED_LIBRARIES := liblog libbinder libutils libNONMediaService
  
  
include $(BUILD_EXECUTABLE)


include $(CLEAR_VARS)

LOCAL_C_INCLUDES += \
    $(LOCAL_PATH)/../include \
    $(LOCAL_PATH)/..

LOCAL_MODULE := HNONMediaClient
LOCAL_MODULE_TAGS := eng #optional  
LOCAL_SRC_FILES := NONMediaClientExec.cpp   

LOCAL_CFLAGS += -pie -fPIE -fpermissive
#LOCAL_PRELINK_MODULE := false  
LOCAL_SHARED_LIBRARIES := liblog libbinder libutils libNONMediaService

include $(BUILD_EXECUTABLE)
