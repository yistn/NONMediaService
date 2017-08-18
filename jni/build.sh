#/bin/sh

PWD=`pwd`

export PATH=$PATH:$HOME/work/Workspace/chromium-crosswalk/src/third_party/android_tools/ndk

rm ../libs/armeabi -rf

ndk-build -B

#CVMDIR=$PWD/../assets/cvm
#if [ -z "$CVMDIR" ]
#then
#	echo "no cvm yes"
#	mkdir $PWD/../assets/cvm -p
#fi
