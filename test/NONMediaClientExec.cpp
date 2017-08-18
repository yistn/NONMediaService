#define TAG "NONMediaClientExec"

#include "INONMediaService.h"
#include "NONMediaPlayer.h"

#include <android/log.h>
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,TAG,__VA_ARGS__) // 定义LOGD类型  

using namespace android;

char * GetURL(int id)
{
    return (char*)"http://www.sina.com.cn";
}

void MediaMsg(char *msg)
{
    LOGD("msg=%s\n", msg); 
    return;
}

int main(int argc, char **argv)
{
#if 0
    sp<IServiceManager> sm = defaultServiceManager();
    sp<IBinder> ibinder = sm->getService(String16(SERVICE_NAME));
    if (ibinder == NULL){
        LOGD( "Client can't find Service" );
    }
    sp<INONMediaService> itvMediaService =  android::interface_cast<INONMediaService>(ibinder); 
    NONMediaClient *mediaClient; // = new NONMediaClient(this);
    itvMediaService->init(mediaClient = new NONMediaClient(NULL));
    itvMediaService->registerCallback(NULL);
#endif

#if 1
    NONMediaPlayer *iptvclient = new NONMediaPlayer();
    if (iptvclient)
        iptvclient->connect();

    sleep(3);

    if (iptvclient) {
        iptvclient->create(NULL, 21);
        //iptvclient->registerCallback();
    }
#endif
    android::ProcessState::self()->startThreadPool();  
    android::IPCThreadState::self()->joinThreadPool(); 
    return 0;
}
