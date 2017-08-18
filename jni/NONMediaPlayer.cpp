#define TAG "NONMediaPlayer"

#include "NONMediaPlayer.h"
//#include "IMediaNotify.h"
//#include "MediaNotify.h"
//#include "INONMediaService.h"

//#include <map>

//#define DEBUG
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
//#define BUILD_NULL
#define NULL 0 

//std::map< int, sp<INONMediaService> > mClientMaps;
//std::map< int, MediaNotify* > mMediaClientMaps;

NONMediaPlayer::NONMediaPlayer(getIptvUrl url, mediaIptvMsg msg)
    :m_mediaMsg(msg),
    m_getUrl(url)
{
    //MediaNotify *mediaClient = new MediaNotify(this);
    //mMediaClientMaps.insert(std::map < int, MediaNotify* >::value_type((int)this, mediaClient));
}

//NON add 
/*NONMediaPlayer& NONMediaPlayer::operator=(NONMediaPlayer& mNONMediaPlayer)
{
    if (this == &mNONMediaPlayer)
        return *this;
    if (m_getUrl != NULL)
        delete m_getUrl;
    if (m_mediaMsg != NULL)
        delete m_mediaMsg;
    m_getUrl = new char[strlen(mNONMediaPlayer.m_getUrl)+1];
    m_mediaMsg = new char[strlen(mNONMediaPlayer.m_mediaMsg)+1];
    if (m_getUrl != NULL)
        strcpy(m_getUrl,mNONMediaPlayer.m_getUrl);
    if (m_mediaMsg != NULL)
        strcpy(m_mediaMsg,mNONMediaPlayer.m_mediaMsg);
    return *this;  
}*/

int NONMediaPlayer::connect()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    sp<IServiceManager> sm = defaultServiceManager();
    sp<IBinder> ibinder = sm->getService(String16(SERVICE_NAME));
    if (ibinder == NULL){
        LOGD( "Client can't find Service" );
        return 0;
    }
    
    sp<INONMediaService> itvMediaService =  android::interface_cast<INONMediaService>(ibinder); 
    mClientMaps.insert(std::map < int, sp<INONMediaService> >::value_type((int)this, itvMediaService));
    
    //std::map < int, MediaNotify* >::iterator iter;
    //iter = mMediaClientMaps.find((int)this);
    //itvMediaService->init(iter->second != NULL);
    MediaNotify *mediaClient = NULL;

    if (m_getUrl != NULL && m_mediaMsg != NULL) {
        LOGD("%s line(%d);", __func__, __LINE__);
        mediaClient = new MediaNotify(this);
        itvMediaService->init(mediaClient);
    }

    mMediaClientMaps.insert(std::map < int, MediaNotify* >::value_type((int)this, mediaClient));
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return 1;
}

void NONMediaPlayer::disconnect()
{
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    mClientMaps.erase(iter);
#endif
}

NONMediaPlayer::~NONMediaPlayer()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    m_getUrl = NULL;
    m_mediaMsg = NULL;
    std::map < int, MediaNotify* >::iterator iter;
    if (iter->second != NULL)
        iter = mMediaClientMaps.find((int)this);

    mMediaClientMaps.erase(iter);
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::getUrl(int id)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    char *url = NULL;
    if (m_getUrl)
        url = m_getUrl(id);
    
    //get extern save id is rul run call player
    if (url) {
        std::map < int, sp<INONMediaService> >::iterator iter;
        iter = mClientMaps.find((int)this);
        if (iter->second != NULL)
            iter->second->create(url, id);
    }
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::mediaMsg(char* msg)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("mediaMsg msg=%s", msg);
#ifdef BUILD_NULL
    if (m_mediaMsg)
        m_mediaMsg(msg);
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::create(const char* url, int id)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    
    LOGD("NONMediaPlayer::callback start");
    if (iter->second != NULL)
        iter->second->create(url, id);
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::reset()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->reset();
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::play()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->play();
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::stop()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->stop();
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::pause()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->pause();
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::resume()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->resume();
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::seek(int time)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->seek(time);
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::fast(int speed)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->fast(speed);
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::rewind(int speed)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->rewind(speed);
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

int  NONMediaPlayer::getVolume()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int volume = 0;
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        volume = iter->second->getVolume();
    LOGD("%s line(%d);", __func__, __LINE__);
#endif
    return volume;
}

void NONMediaPlayer::setVolume(int volume)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setVolume(volume);
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

int  NONMediaPlayer::getMute()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int mute = 0;
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        mute = iter->second->getMute();
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return mute;
}

void NONMediaPlayer::setMute(int volume)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setMute(volume);
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::setRatio()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setRatio();
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

int  NONMediaPlayer::getPlayMode()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int mode = 0;
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        mode = iter->second->getPlayMode();
    LOGD("%s line(%d);", __func__, __LINE__);
#endif
    return mode;
}

int  NONMediaPlayer::getCurrentPos()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int currentpos = 0; 
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        currentpos = iter->second->getCurrentPos();
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return currentpos;
}

int  NONMediaPlayer::getVideoPixels()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int pixels = 0;
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        pixels = iter->second->getVideoPixels();
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return pixels;
}

int  NONMediaPlayer::getDuration()
{
    int duration = 0;
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        duration = iter->second->getDuration();
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return duration;
}

int  NONMediaPlayer::getVersion()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int version = -1;
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        version = iter->second->getVersion();
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return version;
}

void NONMediaPlayer::setVideoWindow(int x, int y, int width, int height, int mode)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setVideoWindow(x, y, width, height, mode);
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

int  NONMediaPlayer::getPlayerInstaceId()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int id = -1;
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        id = iter->second->getPlayerInstaceId();
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return id;
}

void NONMediaPlayer::setAlpha()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setAlpha();
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

//liubin add

char* NONMediaPlayer::set(char* ioStr, char* wrStr)
{
    return NULL;
} 
    
char* NONMediaPlayer::get(char* ioStr)                                                                                                
{ 
    return NULL;
}

int NONMediaPlayer::getNativePlayerInstanceID()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_NativePlayerInstanceID = 0;
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_NativePlayerInstanceID = iter->second->getNativePlayerInstanceID();
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_NativePlayerInstanceID;
}

void NONMediaPlayer::setSingleOrPlaylistMode(int mode)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setSingleOrPlaylistMode(mode);
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaPlayer::getSingleOrPlaylistMode()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_SingleOrPlaylistMode = 0;
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_SingleOrPlaylistMode = iter->second->getSingleOrPlaylistMode();
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_SingleOrPlaylistMode;
}

void NONMediaPlayer::setVideoDisplayMode(int videoDisplayMode)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setVideoDisplayMode(videoDisplayMode);
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaPlayer::getVideoDisplayMode()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_VideoDisplayMode = 0;
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_VideoDisplayMode = iter->second->getVideoDisplayMode();
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_VideoDisplayMode;
}

void NONMediaPlayer::setVideoDisplayArea(int x, int y, int width, int height)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setVideoDisplayArea(x, y, width,height); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaPlayer::getVideoDisplayLeft()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_VideoDisplayLeft = 0;
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_VideoDisplayLeft = iter->second->getVideoDisplayLeft();
    LOGD("%s line(%d);", __func__, __LINE__);
#endif
    return m_VideoDisplayLeft;
}

int NONMediaPlayer::getVideoDisplayTop()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_VideoDisplayTop = 0;
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_VideoDisplayTop = iter->second->getVideoDisplayTop();
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_VideoDisplayTop;
}

int NONMediaPlayer::getVideoDisplayWidth()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_VideoDisplayWidth = 0;
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_VideoDisplayWidth = iter->second->getVideoDisplayWidth();
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_VideoDisplayWidth;
}

int NONMediaPlayer::getVideoDisplayHeight()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_VideoDisplayHeight = 0;
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_VideoDisplayHeight = iter->second->getVideoDisplayHeight();
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_VideoDisplayHeight;
}

void NONMediaPlayer::setNativeUIFlag(int nativeUIFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setNativeUIFlag(nativeUIFlag); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaPlayer::getNativeUIFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_NativeUIFlag = 0;
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_NativeUIFlag = iter->second->getNativeUIFlag(); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_NativeUIFlag;
}

void NONMediaPlayer::setMuteUIFlag(int muteUIFlag)
{ 
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setMuteUIFlag(muteUIFlag); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaPlayer::getMuteUIFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_MuteUIFlag = 0;
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_MuteUIFlag = iter->second->getMuteUIFlag(); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_MuteUIFlag;
}

void NONMediaPlayer::setAudioVolumeUIFlag(int audioVolumeUIFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setAudioVolumeUIFlag(audioVolumeUIFlag); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaPlayer::getAudioVolumeUIFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_AudioVolumeUIFlag = 0;
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_AudioVolumeUIFlag = iter->second->getAudioVolumeUIFlag(); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_AudioVolumeUIFlag;
}

void NONMediaPlayer::setAudioTrackUIFlag(int audioTrackUIFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setAudioTrackUIFlag(audioTrackUIFlag); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaPlayer::getAudioTrackUIFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_AudioTrackUIFlag = 0;
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_AudioTrackUIFlag = iter->second->getAudioTrackUIFlag(); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_AudioTrackUIFlag;
}

void NONMediaPlayer::setProgressBarUIFlag(int progressBarUIFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setProgressBarUIFlag(progressBarUIFlag); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaPlayer::getProgressBarUIFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_ProgressBarUIFlag = 0;
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_ProgressBarUIFlag = iter->second->getProgressBarUIFlag(); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_ProgressBarUIFlag;
}

void NONMediaPlayer::setChannelNoUIFlag(int channelNOUIFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setChannelNoUIFlag(channelNOUIFlag); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaPlayer::getChannelNoUIFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_ChannelNoUIFlag = 0;
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_ChannelNoUIFlag = iter->second->getChannelNoUIFlag(); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_ChannelNoUIFlag;
}

void NONMediaPlayer::setSubtitileFlag(int subtitileFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setSubtitileFlag(subtitileFlag); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaPlayer::getSubtitileFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_SubtitileFlag = 0;
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_SubtitileFlag = iter->second->getSubtitileFlag(); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_SubtitileFlag;
}

void NONMediaPlayer::setAllowTrickmodeFlag(int allowTrickmodeFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setAllowTrickmodeFlag(allowTrickmodeFlag); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaPlayer::getAllowTrickmodeFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_AllowTrickmodeFlag = 0;
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_AllowTrickmodeFlag = iter->second->getAllowTrickmodeFlag(); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_AllowTrickmodeFlag;
}

void NONMediaPlayer::setCycleFlag(int cycleFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setCycleFlag(cycleFlag); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaPlayer::getCycleFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_CycleFlag = 0;
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_CycleFlag = iter->second->getCycleFlag(); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_CycleFlag;
}

void NONMediaPlayer::setRandomFlag(int randomFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setRandomFlag(randomFlag); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaPlayer::getRandomFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_RandomFlag = 0;
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_RandomFlag = iter->second->getRandomFlag(); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_RandomFlag;
}

void NONMediaPlayer::setVendorSpecificAttr(const char* vendorSpecificAttr)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setVendorSpecificAttr(vendorSpecificAttr); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

char* NONMediaPlayer::getVendorSpecificAttr()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    char* m_VendorSpecificAttr = NULL;
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_VendorSpecificAttr = iter->second->getVendorSpecificAttr(); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_VendorSpecificAttr;
}

char* NONMediaPlayer::getMediaCode()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    char* m_MediaCode = NULL;
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_MediaCode = iter->second->getMediaCode(); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_MediaCode;
}
    
char* NONMediaPlayer::getCurrentPlayTime()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    char* m_CurPlayTime = NULL;
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_CurPlayTime = iter->second->getCurrentPlayTime(); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    if (!m_CurPlayTime)
        return "0";
    return m_CurPlayTime;
}

int NONMediaPlayer::GetLastError()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_LastError = 0;
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_LastError = iter->second->GetLastError(); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_LastError;
}

char* NONMediaPlayer::getSubtitle()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    char* m_Subtitle = NULL;
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_Subtitle = iter->second->getSubtitle(); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_Subtitle;
}

int NONMediaPlayer::getMediaCount()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_MediaCount = 0;
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_MediaCount = iter->second->getMediaCount(); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_MediaCount;
}

int NONMediaPlayer::getCurrentIndex()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_CurrentIndex = 0;
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_CurrentIndex = iter->second->getCurrentIndex(); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_CurrentIndex;
}

char* NONMediaPlayer::getEntryID()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    char* m_EntryID = NULL;
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_EntryID = iter->second->getEntryID(); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_EntryID;
}

char* NONMediaPlayer::getPlaylist()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    char* m_Playlist = NULL;
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_Playlist = iter->second->getPlaylist(); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_Playlist;
}

void NONMediaPlayer::initMediaPlayer(int nativePlayerInstanceID,
        int playlistFlag,
        int videoDisplayMode,
        int height,
        int width,
        int left,
        int top,
        int muteFlag,
        int useNativeUIFlag,
        int subtitleFlag,
        int videoAlpha,
        int cycleFlag,
        int randomFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->initMediaPlayer(nativePlayerInstanceID, playlistFlag, videoDisplayMode,height,width,
                left, top, muteFlag, useNativeUIFlag, subtitleFlag, videoAlpha,cycleFlag,randomFlag);
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaPlayer::addSingleMedia(int index, const char* mediaStr)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_SingleMedia = 0;
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_SingleMedia = iter->second->addSingleMedia(index, mediaStr); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_SingleMedia;
}

int NONMediaPlayer::addBatchMedia(const char* batchMediaStr)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_BatchMedia = 0;
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_BatchMedia = iter->second->addBatchMedia(batchMediaStr); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_BatchMedia;
}

void NONMediaPlayer::removeMediaByEntryID(const char* entryID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->removeMediaByEntryID(entryID); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::removeMediaByIndex(int index)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->removeMediaByIndex(index); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::clearAllMedia()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->clearAllMedia(); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::moveMediaByIndex(const char* entryID, int toIndex)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->moveMediaByIndex(entryID, toIndex); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::moveMediaByOffset(const char* entryID, int offset)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->moveMediaByOffset(entryID, offset); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::moveMediaByIndex1(int index, int toIndex)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->moveMediaByIndex1(index, toIndex); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::moveMediaByOffset1(int index, int offset)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->moveMediaByOffset1(index,offset); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::moveMediaToNext(const char* entryID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->moveMediaToNext(entryID); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::moveMediaToPrevious(const char* entryID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->moveMediaToPrevious(entryID); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::moveMediaToFirst(const char* entryID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->moveMediaToFirst(entryID); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::moveMediaToLast(const char* entryID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->moveMediaToLast(entryID); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::moveMediaToNext1(int index)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->moveMediaToNext1(index); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::moveMediaToPrevious1(int index)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->moveMediaToPrevious1(index); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::moveMediaToFirst1(int index)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->moveMediaToFirst1(index); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::moveMediaToLast1(int index)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->moveMediaToLast1(index); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::selectMediaByIndex(int index)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->selectMediaByIndex(index); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::selectMediaByOffset(int offset)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->selectMediaByOffset(offset); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::selectNext()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->selectNext(); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::selectPrevious()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->selectPrevious(); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::selectFirst()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->selectFirst(); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::selectLast()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->selectLast(); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::selectMediaByEntryID(const char* entryID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->selectMediaByEntryID(entryID); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaPlayer::joinChannel(int userchannelid)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_JoinChannel = 0;
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_JoinChannel = iter->second->joinChannel(userchannelid); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_JoinChannel;
}

void NONMediaPlayer::leaveChannel()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->leaveChannel();
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::playFromStart()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->playFromStart();
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::playByTime(int type, char* timestamp, int speed)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->playByTime(type, timestamp, speed);
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::switchSubtitle()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->switchSubtitle();
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::sendVendorSpecificCommand(const char* xml)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->sendVendorSpecificCommand(xml);
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaPlayer::getAudioPID()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_AudioPID = 0;
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_AudioPID = iter->second->getAudioPID();
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_AudioPID;
}

int NONMediaPlayer::getAudioPIDs()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_AudioPIDs = 0;
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_AudioPIDs = iter->second->getAudioPIDs();
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_AudioPIDs;
}

void NONMediaPlayer::setAudioPID(int pid)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setAudioPID(pid);
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaPlayer::getSubtitlePID()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_SubtitlePID = 0;
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_SubtitlePID = iter->second->getSubtitlePID();
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_SubtitlePID;
}

int NONMediaPlayer::getSubtitlePIDs()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_SubtitlePIDs = 0;
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_SubtitlePIDs = iter->second->getSubtitlePIDs();
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_SubtitlePIDs;
}

void NONMediaPlayer::setSubtitlePID(int pid)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setSubtitlePID(pid);
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaPlayer::Data(int start, int end)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_Data = 0;
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_Data = iter->second->Data(start, end);
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_Data;
}

void NONMediaPlayer::videoshow()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->videoshow();
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::videohide()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->videohide();
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaPlayer::bindNativePlayerInstance(int nativePlayerInstanceID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_BindnativePlayerInstanceID = 0;
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_BindnativePlayerInstanceID = iter->second->bindNativePlayerInstance(nativePlayerInstanceID);
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_BindnativePlayerInstanceID;
}

void NONMediaPlayer::releaseMediaPlayer(int nativePlayerInstanceID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->releaseMediaPlayer(nativePlayerInstanceID);
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::setMuteFlag(int muteFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setMuteFlag(muteFlag); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaPlayer::getMuteFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_MuteFlag = 0;
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_MuteFlag = iter->second->getMuteFlag(); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_MuteFlag;
}

void NONMediaPlayer::setVideoAlpha(int videoAlpha)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setVideoAlpha(videoAlpha); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaPlayer::getVideoAlpha()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_VideoAlpha = 0;
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_VideoAlpha = iter->second->getVideoAlpha(); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_VideoAlpha;
}

char* NONMediaPlayer::getPlaybackMode()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    char* m_PlaybackMode = NULL;
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_PlaybackMode = iter->second->getPlaybackMode(); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_PlaybackMode;
}

int NONMediaPlayer::getChannelNum()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_ChannelNum = 0;
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_ChannelNum = iter->second->getChannelNum(); 
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_ChannelNum;
}

char* NONMediaPlayer::getCurrentAudioChannel()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    char* m_CurAudioChannel = NULL;
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
       m_CurAudioChannel = iter->second->getCurrentAudioChannel();
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_CurAudioChannel;
}

char* NONMediaPlayer::getAudioTrack()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    char* m_AudioTrack = NULL;
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        m_AudioTrack = iter->second->getAudioTrack();
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_AudioTrack;
}

void NONMediaPlayer::setSingleMedia(char* mediaStr)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map< int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->setSingleMedia(mediaStr);
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::gotoStart()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->gotoStart();
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::gotoEnd()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->gotoEnd();
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::refreshVideoDisplay()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->refreshVideoDisplay();
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::switchAudioChannel()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->switchAudioChannel();
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaPlayer::switchAudioTrack()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->switchAudioTrack();
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}

//game call function                                                                                                                 
void NONMediaPlayer::runGame(const char* values)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef BUILD_NULL
    std::map < int, sp<INONMediaService> >::iterator iter;
    iter = mClientMaps.find((int)this);
    if (iter->second != NULL)
        iter->second->runGame(values);
#endif
    LOGD("%s line(%d);", __func__, __LINE__);
}
