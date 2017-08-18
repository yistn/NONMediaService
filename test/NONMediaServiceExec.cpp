#define TAG "NONMediaServiceExec"

#include "NONMediaService.h"

#include <android/log.h>
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,TAG,__VA_ARGS__) // 定义LOGD类型  

#define SERVICE_NAME "NONMediaService"
//using namespace android;

int main(int argc, char **argv)
{
    sp<ProcessState> proc(ProcessState::self());
    sp<IServiceManager> sm = defaultServiceManager();
    LOGD("NONMediaService: %p",sm.get());
    NONMediaService::instantiate();
    //sm->addService(String16(SERVICE_NAME),new NONMediaService());
    ProcessState::self()->startThreadPool();
    IPCThreadState::self()->joinThreadPool();
}
