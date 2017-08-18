LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE_TAGS := eng

LOCAL_SRC_FILES := \
	NONMediaPlayer.cpp 
	#IMediaNotify.cpp \
	#MediaNotify.cpp \
	#INONMediaService.cpp \
	#NONMediaService.cpp \
	#IMediaPlayer.cpp 
    
#	CTCMediaServiceClient.cpp	

LOCAL_C_INCLUDES += \
    $(LOCAL_PATH)/../include \
    $(LOCAL_PATH)/.. \
	bionic \
	bionic/libstdc++/include \
	external/stlport/stlport
  
#LOCAL_CPPFLAGS += -fexceptions -frtti
#LOCAL_LDFLAGS += -L$(prebuilt_stdcxx_PATH)/libs/$(TARGET_CPU_ABI) -lgnustl_static -lsupc++
#LOCAL_LDFLAGS += -L$(prebuilt_stdcxx_PATH)/libs/$(TARGET_CPU_ABI) -lstdc++
#LOCAL_SHARED_LIBRARIES := libbinder libutils liblog libNONMediaService
LOCAL_SHARED_LIBRARIES := \
	    libcutils \
		libdl \
		libstlport \
		libbinder \
		libutils \
		liblog   

#		libCTC_MediaProcessor \
#		libCTC_MediaControl
#LOCAL_CFLAGS := -DRIL_SHLIB -fpermissive

LOCAL_CFLAGS += -pie -fPIE -fpermissive
#STL_PATH=$(NDK_ROOT)/sources/cxx-stl/gnu-libstdc++/4.9/libs/armeabi-v7a
#LOCAL_LDLIBS += -L$(STL_PATH)/libsupc++.a
#LOCAL_STATIC_LIBRARIES += -L$(STL_PATH)/libsupc++.a
#LOCAL_LDFLAGS += -pie -fPIE

LOCAL_CERTIFICATE := platform

LOCAL_MODULE := libNONMediaService

include $(BUILD_SHARED_LIBRARY)
