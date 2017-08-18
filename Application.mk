#APP_ABI := all
APP_ABI := armeabi armeabi-v7a
APP_PLATFORM := android-16   
#APP_OPTIM := debug 
#APP_CFLAG := -g -ggdb -O0   
#APP_STL := stlport_static   
#NDK_TOOLCHAIN_VERSION=4.9 
#APP_STL := gnustl_shared #GNU STL                                                                                                                
APP_STL := c++_static #GNU STL
APP_CPPFLAGS := -fexceptions -frtti
APP_CPPFLAGS += -std=c++11
APP_CPPFLAGS += -fpermissive 
#APP_OPTIM := release 
#release
#NDK_TOOLCHAIN_VERSION=4.9
