#define TAG "MediaNotify"

#include "MediaNotify.h"

#define DEBUG
#ifdef DEBUG                                                                                                              
#include <android/log.h>
#undef XLOGD
#define XLOGD(...)  __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__) // 定义LOGD类型  
#else
#undef XLOGD
#define XLOGD(...)
#define LOGD(...)
#endif // DEBUG 

MediaNotify::MediaNotify(NONMediaPlayer *iptvMClient)
    : BnMediaNotify()
    , m_iptvMClient(iptvMClient)
{
    LOGD("MediaNotify::MediaNotify\n");
}

MediaNotify::~MediaNotify()
{
    LOGD("MediaNotify::~MediaNotify\n");
}

void MediaNotify::instantiate()
{
    LOGD("MediaNotify::instantiate\n");
    //defaultServiceManager()->addService(String16(SERVICE_NAME),new MediaNotify());
}

void MediaNotify::getUrl(int id)
{
    if (m_iptvMClient)
        m_iptvMClient->getUrl(id);
    return;
}

void MediaNotify::mediaMsg(char *msg)
{
    LOGD("MediaNotify::mediaMsg start");
    LOGD("MediaNotify::mediaMsg msg=%s", msg);
    if (m_iptvMClient)
        m_iptvMClient->mediaMsg(msg); 
    LOGD("MediaNotify::mediaMsg msg");
    return;
}

void MediaNotify::notify(int msg, int ext1, int ext2, const Parcel *obj)
{
    return;
}
