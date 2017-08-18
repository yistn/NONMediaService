#define TAG "NONMediaService"

#include "NONMediaService.h"

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

//IMPLEMENT_META_INTERFACE(NONMediaService,"com.example.yistn.testservice.NONMediaService");

static NONMediaService* m_active = NULL;

void NONMediaService::instantiate()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("instantiate\n");
    LOGD("NONMediaService:ServiceManager: start\n");
    defaultServiceManager()->addService(String16(SERVICE_NAME),new NONMediaService());
    m_active = NULL;
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::iptvMediaMsg(void *arg)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("IPNONMediaPlayer msg = %s", (char*)arg);
    
    if(m_active && m_active->m_client.get())
       m_active->m_client->mediaMsg((char*)arg);
    LOGD("%s line(%d);", __func__, __LINE__);
}

NONMediaService::NONMediaService()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    m_iptvMedia = IMediaPlayer::create(this);
    LOGD("%s line(%d);", __func__, __LINE__);
}

NONMediaService::~NONMediaService()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (this == m_active)
        m_active = NULL;
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::init(const sp<IMediaNotify>& client)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    m_client = client;
    LOGD("%s line(%d);", __func__, __LINE__);
}


int NONMediaService::create(const char* url, int id)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int res = -1;
    if (url == NULL || strlen(url) <= 0) {
        if(m_client.get()) {
            LOGD("%s line(%d);", __func__, __LINE__);
            m_client->getUrl(id);
            return res;
        }
        LOGD("create get url no extern callback\n");
        return res;
    } 
    
    //m_active = this; 
    LOGD("create url = %s\n", url);
    if (m_iptvMedia)
        res = m_iptvMedia->create(url);

    LOGD("%s line(%d);", __func__, __LINE__);
    return res;
}

void NONMediaService::reset()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
        m_iptvMedia->reset();
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::play()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
        m_iptvMedia->play();
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::stop()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
        m_iptvMedia->stop();
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::pause()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
        m_iptvMedia->pause();
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::resume()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
        m_iptvMedia->resume();
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::seek(int time) 
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
        m_iptvMedia->seek(time);
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::fast(int speed) 
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
        m_iptvMedia->seek(speed);
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::rewind(int speed)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
        m_iptvMedia->rewind(speed);
    LOGD("%s line(%d);", __func__, __LINE__);
}

int  NONMediaService::getVolume()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int volume = 0;
    if (m_iptvMedia)
        volume = m_iptvMedia->getVolume();
    LOGD("%s line(%d);", __func__, __LINE__);
    return volume;
}

void NONMediaService::setVolume(int volume)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
        m_iptvMedia->setVolume(volume);
    LOGD("%s line(%d);", __func__, __LINE__);
}

int  NONMediaService::getMute()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int mute = 0;
    if (m_iptvMedia)
        mute = m_iptvMedia->getMute();
    LOGD("%s line(%d);", __func__, __LINE__);
    return mute;
}

void NONMediaService::setMute(int mute)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
        m_iptvMedia->setMute(mute);
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::setRatio() 
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
        m_iptvMedia->setRatio();
    LOGD("%s line(%d);", __func__, __LINE__);
}

int  NONMediaService::getPlayMode()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int mode = 0;
    if (m_iptvMedia)
        mode = m_iptvMedia->getPlayMode();
    LOGD("%s line(%d);", __func__, __LINE__);
    return mode;
}

int  NONMediaService::getCurrentPos()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int pos = 0;
    if (m_iptvMedia)
        pos = m_iptvMedia->getCurrentPos();
    LOGD("%s line(%d);", __func__, __LINE__);
    return pos;
}

int  NONMediaService::getVideoPixels()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int pixels = 0;
    if (m_iptvMedia)
        pixels = m_iptvMedia->getVideoPixels();
    LOGD("%s line(%d);", __func__, __LINE__);
    return pixels;
}

int  NONMediaService::getDuration()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int duration = 0;
    if (m_iptvMedia)
        duration = m_iptvMedia->getDuration();
    LOGD("%s line(%d);", __func__, __LINE__);
    return duration;
}

int  NONMediaService::getVersion()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int version = 0;
    if (m_iptvMedia)
        version = m_iptvMedia->getVersion();
    LOGD("%s line(%d);", __func__, __LINE__);
    return version;
}

void NONMediaService::setVideoWindow(int x, int y, int width, int height, int mode)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
        m_iptvMedia->setVideoWindow(x, y, width, height, mode);
    LOGD("%s line(%d);", __func__, __LINE__);
}

int  NONMediaService::getPlayerInstaceId()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int id = 0;
    if (m_iptvMedia)
        id = m_iptvMedia->getPlayerInstaceId();
    LOGD("%s line(%d);", __func__, __LINE__);
    return id;
}

void NONMediaService::setAlpha()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->setAlpha();
    LOGD("%s line(%d);", __func__, __LINE__);
}

//liubin add 
char* NONMediaService::set(char* ioStr, char* wrStr)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    char* setStr = NULL;
    if (m_iptvMedia)
       setStr = m_iptvMedia->set(ioStr, wrStr);
    LOGD("%s line(%d);", __func__, __LINE__);
    return setStr;
}

char* NONMediaService::get(char* ioStr)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    char* getStr = NULL;
    if (m_iptvMedia)
       getStr = m_iptvMedia->get(ioStr);
    LOGD("%s line(%d);", __func__, __LINE__);
    return getStr;
}

int NONMediaService::getNativePlayerInstanceID()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int nativePlayerInstanceID = 0;
    if (m_iptvMedia)
       nativePlayerInstanceID = m_iptvMedia->getNativePlayerInstanceID();
    LOGD("%s line(%d);", __func__, __LINE__);
    return nativePlayerInstanceID;
}

void NONMediaService::setSingleOrPlaylistMode(int mode)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->setSingleOrPlaylistMode(mode);
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaService::getSingleOrPlaylistMode()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_SingleOrPlaylistMode = 0;
    if (m_iptvMedia)
       m_SingleOrPlaylistMode = m_iptvMedia->getSingleOrPlaylistMode();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_SingleOrPlaylistMode;
}

void NONMediaService::setVideoDisplayMode(int videoDisplayMode)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->setVideoDisplayMode(videoDisplayMode);
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaService::getVideoDisplayMode()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_VideoDisplayMode = 0;
    if (m_iptvMedia)
       m_VideoDisplayMode = m_iptvMedia->getVideoDisplayMode();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_VideoDisplayMode;
}

void NONMediaService::setVideoDisplayArea(int x, int y, int width, int height)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->setVideoDisplayArea(x, y, width, height);
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaService::getVideoDisplayLeft()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_VideoDisplayLeft = 0;
    if (m_iptvMedia)
       m_VideoDisplayLeft = m_iptvMedia->getVideoDisplayLeft();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_VideoDisplayLeft;
}

int NONMediaService::getVideoDisplayTop()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_VideoDisplayTop = 0;
    if (m_iptvMedia)
       m_VideoDisplayTop = m_iptvMedia->getVideoDisplayTop();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_VideoDisplayTop;
}

int NONMediaService::getVideoDisplayWidth()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_VideoDisplayWidth = 0;
    if (m_iptvMedia)
       m_VideoDisplayWidth = m_iptvMedia->getVideoDisplayWidth();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_VideoDisplayWidth;
}

int NONMediaService::getVideoDisplayHeight()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_VideoDisplayHeight = 0;
    if (m_iptvMedia)
       m_VideoDisplayHeight = m_iptvMedia->getVideoDisplayHeight();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_VideoDisplayHeight;
}

void NONMediaService::setNativeUIFlag(int nativeUIFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->setNativeUIFlag(nativeUIFlag);
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaService::getNativeUIFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_NativeUIFlag = 0;
    if (m_iptvMedia)
       m_NativeUIFlag = m_iptvMedia->getNativeUIFlag();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_NativeUIFlag;
}

void NONMediaService::setMuteUIFlag(int muteUIFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->setMuteUIFlag(muteUIFlag);
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaService::getMuteUIFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_MuteUIFlag = 0;
    if (m_iptvMedia)
       m_MuteUIFlag = m_iptvMedia->getMuteUIFlag();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_MuteUIFlag;
}

void NONMediaService::setAudioVolumeUIFlag(int audioVolumeUIFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->setAudioVolumeUIFlag(audioVolumeUIFlag);
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaService::getAudioVolumeUIFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_AudioVolumeUIFlag = 0;
    if (m_iptvMedia)
       m_AudioVolumeUIFlag = m_iptvMedia->getAudioVolumeUIFlag();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_AudioVolumeUIFlag;
}

void NONMediaService::setAudioTrackUIFlag(int audioTrackUIFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->setAudioTrackUIFlag(audioTrackUIFlag);
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaService::getAudioTrackUIFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_AudioTrackUIFlag = 0;
    if (m_iptvMedia)
       m_AudioTrackUIFlag = m_iptvMedia->getAudioTrackUIFlag();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_AudioTrackUIFlag;
}

void NONMediaService::setProgressBarUIFlag(int progressBarUIFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->setProgressBarUIFlag(progressBarUIFlag);
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaService::getProgressBarUIFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_ProgressBarUIFlag = 0;
    if (m_iptvMedia)
       m_ProgressBarUIFlag = m_iptvMedia->getProgressBarUIFlag();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_ProgressBarUIFlag;
}

void NONMediaService::setChannelNoUIFlag(int channelNOUIFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->setChannelNoUIFlag(channelNOUIFlag);
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaService::getChannelNoUIFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_ChannelNoUIFlag = 0;
    if (m_iptvMedia)
       m_ChannelNoUIFlag = m_iptvMedia->getChannelNoUIFlag();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_ChannelNoUIFlag;
}

void NONMediaService::setSubtitileFlag(int subtitileFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->setSubtitileFlag(subtitileFlag);
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaService::getSubtitileFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_SubtitileFlag = 0;
    if (m_iptvMedia)
       m_SubtitileFlag = m_iptvMedia->getSubtitileFlag();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_SubtitileFlag;
}

void NONMediaService::setAllowTrickmodeFlag(int allowTrickmodeFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->setAllowTrickmodeFlag(allowTrickmodeFlag);
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaService::getAllowTrickmodeFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_AllowTrickmodeFlag = 0;
    if (m_iptvMedia)
       m_AllowTrickmodeFlag = m_iptvMedia->getAllowTrickmodeFlag();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_AllowTrickmodeFlag;
}

void NONMediaService::setCycleFlag(int cycleFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->setCycleFlag(cycleFlag);
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaService::getCycleFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_CycleFlag = 0;
    if (m_iptvMedia)
       m_CycleFlag = m_iptvMedia->getCycleFlag();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_CycleFlag;
}

void NONMediaService::setRandomFlag(int randomFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->setRandomFlag(randomFlag);
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaService::getRandomFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_RandomFlag = 0;
    if (m_iptvMedia)
       m_RandomFlag = m_iptvMedia->getRandomFlag();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_RandomFlag;
}

void NONMediaService::setVendorSpecificAttr(const char* vendorSpecificAttr)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->setVendorSpecificAttr(vendorSpecificAttr);
    LOGD("%s line(%d);", __func__, __LINE__);
}

char* NONMediaService::getVendorSpecificAttr()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    char* m_VendorSpecificAttr = NULL;
    if (m_iptvMedia)
       m_VendorSpecificAttr = m_iptvMedia->getVendorSpecificAttr();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_VendorSpecificAttr;
}

char* NONMediaService::getMediaCode()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    char* m_MediaCode = NULL;
    if (m_iptvMedia)
       m_MediaCode = m_iptvMedia->getMediaCode();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_MediaCode;
}

char* NONMediaService::getCurrentPlayTime()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    char* m_CurrentPlayTime = NULL;
    if (m_iptvMedia)
       m_CurrentPlayTime = m_iptvMedia->getCurrentPlayTime();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_CurrentPlayTime;
}

int NONMediaService::GetLastError()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_LastError = 0;
    if (m_iptvMedia)
       m_LastError = m_iptvMedia->GetLastError();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_LastError;
}

char* NONMediaService::getSubtitle()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    char* m_Subtitle = NULL;
    if (m_iptvMedia)
       m_Subtitle = m_iptvMedia->getSubtitle();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_Subtitle;
}

int NONMediaService::getMediaCount()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_MediaCount = 0;
    if (m_iptvMedia)
       m_MediaCount = m_iptvMedia->getMediaCount();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_MediaCount;
}

int NONMediaService::getCurrentIndex()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_CurrentIndex = 0;
    if (m_iptvMedia)
       m_CurrentIndex = m_iptvMedia->getCurrentIndex();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_CurrentIndex;
}

char* NONMediaService::getEntryID()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    char* m_EntryID = NULL;
    if (m_iptvMedia)
       m_EntryID = m_iptvMedia->getEntryID();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_EntryID;
}

char* NONMediaService::getPlaylist()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    char* m_Playlist = NULL;
    if (m_iptvMedia)
       m_Playlist = m_iptvMedia->getPlaylist();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_Playlist;
}

void NONMediaService::initMediaPlayer(int nativePlayerInstanceID,
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
    if (m_iptvMedia)
       m_iptvMedia->initMediaPlayer(nativePlayerInstanceID, playlistFlag, videoDisplayMode, height,
               width, left, top, muteFlag, useNativeUIFlag, subtitleFlag, videoAlpha,cycleFlag,randomFlag);
    LOGD("%s line(%d);", __func__, __LINE__);
}

int  NONMediaService::addSingleMedia(int index, const char* mediaStr)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_SingleMedia = 0;
    if (m_iptvMedia)
       m_SingleMedia = m_iptvMedia->addSingleMedia(index, mediaStr);
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_SingleMedia;
}

int NONMediaService::addBatchMedia(const char* batchMediaStr)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_BatchMedia = 0;
    if (m_iptvMedia)
       m_BatchMedia = m_iptvMedia->addBatchMedia(batchMediaStr);
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_BatchMedia;
}

void NONMediaService::removeMediaByEntryID(const char* entryID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->removeMediaByEntryID(entryID);
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::removeMediaByIndex(int index)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->removeMediaByIndex(index);
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::clearAllMedia()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->clearAllMedia();
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::moveMediaByIndex(const char* entryID, int toIndex)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->moveMediaByIndex(entryID, toIndex);
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::moveMediaByOffset(const char* entryID, int offset)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->moveMediaByOffset(entryID, offset);
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::moveMediaByIndex1(int index, int toIndex)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->moveMediaByIndex1(index, toIndex);
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::moveMediaByOffset1(int index, int offset)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->moveMediaByOffset1(index, offset);
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::moveMediaToNext(const char* entryID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->moveMediaToNext(entryID);
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::moveMediaToPrevious(const char* entryID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->moveMediaToPrevious(entryID);
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::moveMediaToFirst(const char* entryID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->moveMediaToFirst(entryID);
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::moveMediaToLast(const char* entryID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->moveMediaToLast(entryID);
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::moveMediaToNext1(int index)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->moveMediaToNext1(index);
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::moveMediaToPrevious1(int index)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->moveMediaToPrevious1(index);
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::moveMediaToFirst1(int index)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->moveMediaToFirst1(index);
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::moveMediaToLast1(int index)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->moveMediaToLast1(index);
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::selectMediaByIndex(int index)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->selectMediaByIndex(index);
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::selectMediaByOffset(int offset)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->selectMediaByOffset(offset);
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::selectNext()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->selectNext();
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::selectPrevious()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->selectPrevious();
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::selectFirst()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->selectFirst();
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::selectLast()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->selectLast();
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::selectMediaByEntryID(const char* entryID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->selectMediaByEntryID(entryID);
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaService::joinChannel(int userchannelid)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_JoinChannel = 0;
    if (m_iptvMedia)
	create(NULL, userchannelid);
       //m_JoinChannel = m_iptvMedia->joinChannel(userchannelid);
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_JoinChannel;
}

void NONMediaService::leaveChannel()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->leaveChannel();
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::playFromStart()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->playFromStart();
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::playByTime(int type, char* timestamp, int speed)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->playByTime(type, timestamp, speed);
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::switchSubtitle()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->switchSubtitle();
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::sendVendorSpecificCommand(const char* xml)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->sendVendorSpecificCommand(xml);
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaService::getAudioPID()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_AudioPID = 0;
    if (m_iptvMedia)
       m_AudioPID = m_iptvMedia->getAudioPID();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_AudioPID;
}

int NONMediaService::getAudioPIDs()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_AudioPIDs = 0;
    if (m_iptvMedia)
       m_AudioPIDs = m_iptvMedia->getAudioPIDs();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_AudioPIDs;
}

void NONMediaService::setAudioPID(int pid)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->setAudioPID(pid);
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaService::getSubtitlePID()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_SubtitlePID = 0;
    if (m_iptvMedia)
       m_SubtitlePID = m_iptvMedia->getSubtitlePID();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_SubtitlePID;
}

int NONMediaService::getSubtitlePIDs()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_SubtitlePIDs = 0;
    if (m_iptvMedia)
       m_SubtitlePIDs = m_iptvMedia->getSubtitlePIDs();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_SubtitlePIDs;
}

void NONMediaService::setSubtitlePID(int pid)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->setSubtitlePID(pid);
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaService::Data(int start, int end)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_Data = 0;
    if (m_iptvMedia)
       m_Data = m_iptvMedia->Data(start, end);
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_Data;
}

void NONMediaService::videoshow()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->videoshow();
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::videohide()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->videohide();
    LOGD("%s line(%d);", __func__, __LINE__);
}

int  NONMediaService::bindNativePlayerInstance(int nativePlayerInstanceID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_BindNativePlayerInstance = 0;
    if (m_iptvMedia)
       m_BindNativePlayerInstance = m_iptvMedia->bindNativePlayerInstance(nativePlayerInstanceID);
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_BindNativePlayerInstance;
}

void NONMediaService::releaseMediaPlayer(int nativePlayerInstanceID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->releaseMediaPlayer(nativePlayerInstanceID);
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::setMuteFlag(int muteFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->setMuteFlag(muteFlag);
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaService::getMuteFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_MuteFlag = 0;
    if (m_iptvMedia)
       m_MuteFlag = m_iptvMedia->getMuteFlag();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_MuteFlag;
}

void NONMediaService::setVideoAlpha(int videoAlpha)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->setVideoAlpha(videoAlpha);
    LOGD("%s line(%d);", __func__, __LINE__);
}

int NONMediaService::getVideoAlpha()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_VideoAlpha = 0;
    if (m_iptvMedia)
       m_VideoAlpha = m_iptvMedia->getVideoAlpha();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_VideoAlpha;
}

char* NONMediaService::getPlaybackMode()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    char* m_PlaybackMode = NULL;
    if (m_iptvMedia)
       m_PlaybackMode = m_iptvMedia->getPlaybackMode();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_PlaybackMode;
}

int NONMediaService::getChannelNum()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    int m_ChannelNum = 0;
    if (m_iptvMedia)
       m_ChannelNum = m_iptvMedia->getChannelNum();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_ChannelNum;
}

char* NONMediaService::getCurrentAudioChannel()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    char* m_CurAudioChannel = NULL;
    if (m_iptvMedia)
       m_CurAudioChannel = m_iptvMedia->getCurrentAudioChannel();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_CurAudioChannel;
}

char* NONMediaService::getAudioTrack()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    char* m_AudioTrack = NULL;
    if (m_iptvMedia)
       m_AudioTrack = m_iptvMedia->getAudioTrack();
    LOGD("%s line(%d);", __func__, __LINE__);
    return m_AudioTrack;
}

void NONMediaService::setSingleMedia(char* mediaStr)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->setSingleMedia(mediaStr);
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::gotoStart()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->gotoStart();
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::gotoEnd()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->gotoEnd();
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::refreshVideoDisplay()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->refreshVideoDisplay();
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::switchAudioChannel()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->switchAudioChannel();
    LOGD("%s line(%d);", __func__, __LINE__);
}

void NONMediaService::switchAudioTrack()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
       m_iptvMedia->switchAudioTrack();
    LOGD("%s line(%d);", __func__, __LINE__);
}

//game call function                                                                                                                 
void NONMediaService::runGame(const char* values)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    if (m_iptvMedia)
        m_iptvMedia->runGame(values);
    LOGD("%s line(%d);", __func__, __LINE__);
}
    



status_t BnNONMediaService::onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{
    LOGD("onTransact received request.");
    reply->writeInt32(0);
    switch(code)
    {
        case MEDIA_INIT:
        {
            LOGD("BnNONMediaService init");
            CHECK_INTERFACE(INONMediaService,data,reply);
            sp<IMediaNotify> client = interface_cast<IMediaNotify>(data.readStrongBinder());
            init(client);
            return NO_ERROR;
        }
        case MEDIA_CREATE:
        {
            LOGD("BnNONMediaService create");
            CHECK_INTERFACE(INONMediaService,data,reply);
            char *url = const_cast<char *>(data.readCString());
            int id = data.readInt32();
            reply->writeInt32(create(url, id));
            return NO_ERROR;
        }

        case MEDIA_RESET:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reset();
            return NO_ERROR;
        }

        case MEDIA_PLAY:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            play();
            return NO_ERROR;
        }

        case MEDIA_STOP:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            stop();
            return NO_ERROR;
        }

        case MEDIA_PAUSE:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            pause();
            return NO_ERROR;
        }

        case MEDIA_RESUME:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            resume();
            return NO_ERROR;
        }

        case MEDIA_SEEK:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int pos = data.readInt32();
            seek(pos); 
            return NO_ERROR;
        }

        case MEDIA_FAST:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int speed = data.readInt32();
            fast(speed); 
            return NO_ERROR;
        }

        case MEDIA_REWIND:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int speed = data.readInt32();
            rewind(speed);
            return NO_ERROR;
        }

        case MEDIA_GENONOLUME:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeInt32(getVolume());
            return NO_ERROR;
        }

        case MEDIA_SENONOLUME:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int volume = data.readInt32();
            setVolume(volume);
            return NO_ERROR;
        }

        case MEDIA_GETMUTE:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeInt32(getMute());
            return NO_ERROR;
        }

        case MEDIA_SETMUTE:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int mute = data.readInt32();
            setMute(mute);
            return NO_ERROR;
        }

        case MEDIA_SETRATIO:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            setRatio();
            return NO_ERROR;
        }

        case MEDIA_GETPLAYMODE:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeInt32(getPlayMode());
            return NO_ERROR;
        }

        case MEDIA_GETCURRENTPOS:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeInt32(getCurrentPos());
            return NO_ERROR;
        }

        case MEDIA_GENONIDEOPIXELS:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeInt32(getVideoPixels());
            return NO_ERROR;
        }

        case MEDIA_GETDURATION:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeInt32(getDuration());
            return NO_ERROR;
        }

        case MEDIA_GENONERSION:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeInt32(getVersion());
            return NO_ERROR;
        }

        case MEDIA_SENONIDEOWINDOW:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int x = data.readInt32();
            int y = data.readInt32();
            int width = data.readInt32();
            int height = data.readInt32();
            int mode = data.readInt32();
            setVideoWindow(x, y, width, height, mode);
            return NO_ERROR;
        }

        case MEDIA_GETPLAYERINSTACEID:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeInt32(getPlayerInstaceId());
            return NO_ERROR; 
        }

        case MEDIA_SETALPHA:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            setAlpha();
            return NO_ERROR;
        }
        
        //liubin add
        
        case MEDIA_SET:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            char* ioStr = const_cast<char *>(data.readCString());
            char* wrStr = const_cast<char *>(data.readCString());
            reply->writeCString(set(ioStr,wrStr));
            return NO_ERROR;
        }
        
        case MEDIA_GET:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            char* ioStr = const_cast<char *>(data.readCString());
            reply->writeCString(get(ioStr));
            return NO_ERROR;
        }
        
        case MEDIA_GETNATIVEPLAYERINSTANCEID:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeInt32(getNativePlayerInstanceID());
            return NO_ERROR;
        }
        
        case MEDIA_SETSINGLEORPLAYLISTMODE:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int mode = data.readInt32();
            setSingleOrPlaylistMode(mode);
            return NO_ERROR;
        }

        case MEDIA_GETSINGLEORPLAYLISTMODE:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeInt32(getSingleOrPlaylistMode());
            return NO_ERROR; 
        }
 
        case MEDIA_SENONIDEODISPLAYMODE:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int videoDisplayMode = data.readInt32();
            setVideoDisplayMode(videoDisplayMode);
            return NO_ERROR;
  
        }

        case MEDIA_GENONIDEODISPLAYMODE:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeInt32(getVideoDisplayMode());
            return NO_ERROR; 
        }   

        case MEDIA_SENONIDEODISPLAYAREA:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int x = data.readInt32();
            int y = data.readInt32();
            int width = data.readInt32();
            int height = data.readInt32();
            setVideoDisplayArea(x, y, width,height);
            return NO_ERROR;
        }

        case MEDIA_GENONIDEODISPLAYLEFT:
        {   
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeInt32(getVideoDisplayLeft());
            return NO_ERROR;
        }

        case MEDIA_GENONIDEODISPLAYTOP:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeInt32(getVideoDisplayTop());
            return NO_ERROR;
        }

        case MEDIA_GENONIDEODISPLAYWIDTH:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeInt32(getVideoDisplayWidth());
            return NO_ERROR;
        }

        case MEDIA_GENONIDEODISPLAYHEIGHT:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeInt32(getVideoDisplayHeight());
            return NO_ERROR;
        }
        
        case MEDIA_SETNATIVEUIFLAG:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int nativeUIFlag = data.readInt32();
            setNativeUIFlag(nativeUIFlag);
            return NO_ERROR;
  
        }
        
        case MEDIA_GETNATIVEUIFLAG:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeInt32(getNativeUIFlag());
            return NO_ERROR; 
        }
        
        case MEDIA_SETMUTEUIFLAG:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int muteUIFlag = data.readInt32();
            setMuteUIFlag(muteUIFlag);
            return NO_ERROR; 
        }

        case MEDIA_GETMUTEUIFLAG:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeInt32(getMuteUIFlag());
            return NO_ERROR;  
        }
        
        case MEDIA_SETAUDIOVOLUMEUIFLAG:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int audioVolumeUIFlag = data.readInt32();
            setAudioVolumeUIFlag(audioVolumeUIFlag);
            return NO_ERROR;
        }

        case MEDIA_GETAUDIOVOLUMEUIFLAG:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeInt32(getAudioVolumeUIFlag());
            return NO_ERROR;
        } 
        
        case MEDIA_SETAUDIOTRACKUIFLAG:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int audioTrackUIFlag = data.readInt32();
            setAudioTrackUIFlag(audioTrackUIFlag);
            return NO_ERROR;
        }        

        case MEDIA_GETAUDIOTRACKUIFLAG:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeInt32(getAudioTrackUIFlag());
            return NO_ERROR;
        }
        
        case MEDIA_SETPROGRESSBARUIFLAG:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int progressBarUIFlag = data.readInt32();
            setProgressBarUIFlag(progressBarUIFlag);
            return NO_ERROR; 
        }

        case MEDIA_GETPROGRESSBARUIFLAG:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeInt32(getProgressBarUIFlag());
            return NO_ERROR;
        }

        case MEDIA_SETCHANNELNOUIFLAG:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int channelNOUIFlag = data.readInt32();
            setChannelNoUIFlag(channelNOUIFlag);
            return NO_ERROR; 
        }

        case MEDIA_GETCHANNELNOUIFLAG:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeInt32(getChannelNoUIFlag());
            return NO_ERROR;
        }

        case MEDIA_SETSUBTITILEFLAG:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int subtitileFlag = data.readInt32();
            setSubtitileFlag(subtitileFlag);
            return NO_ERROR; 
        }

        case MEDIA_GETSUBTITILEFLAG:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeInt32(getSubtitileFlag());
            return NO_ERROR;
        }

        case MEDIA_SETALLOWTRICKMODEFLAG:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int allowTrickmodeFlag = data.readInt32();
            setAllowTrickmodeFlag(allowTrickmodeFlag);
            return NO_ERROR;
        }

        case MEDIA_GETALLOWTRICKMODEFLAG:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeInt32(getAllowTrickmodeFlag());
            return NO_ERROR;
        }

        case MEDIA_SETCYCLEFLAG:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int cycleFlag = data.readInt32();
            setCycleFlag(cycleFlag);
            return NO_ERROR;
        }

        case MEDIA_GETCYCLEFLAG:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeInt32(getCycleFlag());
            return NO_ERROR;
        }

        case MEDIA_SETRANDOMFLAG:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int randomFlag = data.readInt32();
            setRandomFlag(randomFlag);
            return NO_ERROR;
        }

        case MEDIA_GETRANDOWFLAG:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeInt32(getRandomFlag());
            return NO_ERROR;
        }

        case MEDIA_SENONENDORSPECIFICATTR:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            const char* vendorSpecificAttr = data.readCString();
            setVendorSpecificAttr(vendorSpecificAttr);
            return NO_ERROR;
        }

        case MEDIA_GENONENDORSPECIFICATTR:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeCString(getVendorSpecificAttr());
            return NO_ERROR;
        }
        
        case MEDIA_GETMEDIACODE:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeCString(getMediaCode());
            return NO_ERROR;
        }

        case MEDIA_GETCURRENTPLAYTIME:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeCString(getCurrentPlayTime());
            return NO_ERROR;  
        }

        case MEDIA_GETLASTERROR:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeInt32(GetLastError());
            return NO_ERROR;
        }

        case MEDIA_GETSUBTITLE:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeCString(getSubtitle());
            return NO_ERROR;
        }

        case MEDIA_GETMEDIACOUNT:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeInt32(getMediaCount());
            return NO_ERROR;
        }

        case MEDIA_GETCURRENTINDEX:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeInt32(getCurrentIndex());
            return NO_ERROR;
        }

        case MEDIA_GETENTRYID:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeCString(getEntryID());
            return NO_ERROR;
        }

        case MEDIA_GETPLAYLIST:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeCString(getPlaylist());
            return NO_ERROR;
        }

        case MEDIA_INITMEDIAPLAYER:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int nativePlayerInstanceID = data.readInt32();
            int playlistFlag = data.readInt32();
            int videoDisplayMode = data.readInt32();
            int height = data.readInt32();
            int width = data.readInt32();
            int left = data.readInt32();
            int top = data.readInt32();
            int muteFlag = data.readInt32();
            int useNativeUIFlag = data.readInt32();
            int subtitleFlag = data.readInt32();
            int videoAlpha = data.readInt32();
            int cycleFlag = data.readInt32();
            int randomFlag = data.readInt32();
            initMediaPlayer(nativePlayerInstanceID, playlistFlag, videoDisplayMode, height, width, left,
                    top, muteFlag, useNativeUIFlag, subtitleFlag, videoAlpha, cycleFlag, randomFlag);
            return NO_ERROR;
        }

        case MEDIA_ADDSINGLEMEDIA:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            const char* mediaStr = data.readCString();
            int index = data.readInt32();
            reply->writeInt32(addSingleMedia(index, mediaStr));
            return NO_ERROR;
        }

        case MEDIA_ADDBATCHMEDIA:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            const char* batchMediaStr = data.readCString();
            reply->writeInt32(addBatchMedia(batchMediaStr));
            return NO_ERROR;
        }

        case MEDIA_REMOVEMEDIABYENTRYID:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            const char* entryID = data.readCString();
            removeMediaByEntryID(entryID);
            return NO_ERROR;
        }

        case MEDIA_REMOVEMEDIABYINDEX:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int index = data.readInt32();
            removeMediaByIndex(index);
            return NO_ERROR;
        }

        case MEDIA_CLEARALLMEDIA:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            clearAllMedia();
            return NO_ERROR;
        }

        case MEDIA_MOVEMEDIABYINDEX:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            const char* entryID = data.readCString();
            int toIndex = data.readInt32();
            moveMediaByIndex(entryID,toIndex);
            return NO_ERROR;
        }

        case MEDIA_MOVEMEDIABYOFFSET:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            const char* entryID = data.readCString();
            int offset = data.readInt32();
            moveMediaByOffset(entryID,offset);
            return NO_ERROR;
        }

        case MEDIA_MOVEMEDIABYINDEX1:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int index = data.readInt32();
            int toIndex = data.readInt32();
            moveMediaByIndex1(index,toIndex);
            return NO_ERROR;
        }

        case MEDIA_MOVEMEDIABYOFFSET1:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int index = data.readInt32();
            int offset = data.readInt32();
            moveMediaByOffset1(index,offset);
            return NO_ERROR;
        }

        case MEDIA_MOVEMEDIATONEXT:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            const char* entryID = data.readCString();
            moveMediaToNext(entryID);
            return NO_ERROR;
        }

        case MEDIA_MOVEMEDIATOPREVIOUS:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            const char* entryID = data.readCString();
            moveMediaToPrevious(entryID);
            return NO_ERROR;
        }
        
        case MEDIA_MOVEMEDIATOFIRST:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            const char* entryID = data.readCString();
            moveMediaToFirst(entryID);
            return NO_ERROR;
        }

        case MEDIA_MOVEMEDIATOLAST:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            const char* entryID = data.readCString();
            moveMediaToLast(entryID);
            return NO_ERROR;
        }

        case MEDIA_MOVEMEDIATONEXT1:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int index = data.readInt32();
            moveMediaToNext1(index);
            return NO_ERROR;
        }

        case MEDIA_MOVEMEDIATOPREVIOUS1:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int index = data.readInt32();
            moveMediaToPrevious1(index);
            return NO_ERROR;
        }

        case MEDIA_MOVEMEDIATOFIRST1:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int index = data.readInt32();
            moveMediaToFirst1(index);
            return NO_ERROR;
        }

        case MEDIA_MOVEMEDIATOLAST1:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int index = data.readInt32();
            moveMediaToLast1(index);
            return NO_ERROR;
        }

        case MEDIA_SELECTMEDIABYINDEX:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int index = data.readInt32();
            selectMediaByIndex(index);
            return NO_ERROR;
        }

        case MEDIA_SELECTMEDIABYOFFSET:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int offset = data.readInt32();
            selectMediaByOffset(offset);
            return NO_ERROR;
        }

        case MEDIA_SELECTNEXT:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            selectNext();
            return NO_ERROR;
        }

        case MEDIA_SELECTPREVIOUS:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            selectPrevious();
            return NO_ERROR;
        }

        case MEDIA_SELECTFIRST:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            selectFirst();
            return NO_ERROR;
        }
        
        case MEDIA_SELECTLAST:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            selectLast();
            return NO_ERROR;
        }

        case MEDIA_SELECTMEDIABYENTRYID:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            const char* entryID = data.readCString();
            selectMediaByEntryID(entryID);
            return NO_ERROR;
        }
        
        case MEDIA_JOINCHANNEL:
        {
            CHECK_INTERFACE(INONMediaService,data,reply); 
            int userchannelid = data.readInt32();
            reply->writeInt32(joinChannel(userchannelid));
            return NO_ERROR;  
        }
        
        case MEDIA_LEAVECHANNEL:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            leaveChannel();
            return NO_ERROR;         
        }

        case MEDIA_PLAYFROMSTART:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            playFromStart();
            return NO_ERROR; 
        }

        case MEDIA_PLAYBYTIME:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int type = data.readInt32();
            char* timestamp = const_cast<char *>(data.readCString());
            int speed = data.readInt32();
            playByTime(type, timestamp, speed);
            return NO_ERROR;
        }

        case MEDIA_SWITCHSUBTITLE:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            switchSubtitle();
            return NO_ERROR;
        }

        case MEDIA_SENDVENDORSPECIFICCOMMAND:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            const char* xml = data.readCString();
            sendVendorSpecificCommand(xml);
            return NO_ERROR;
        }

        case MEDIA_GETAUDIOPID:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeInt32(getAudioPID());;
            return NO_ERROR;
        }

        case MEDIA_GETAUDIOPIDS:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeInt32(getAudioPIDs());;
            return NO_ERROR;
        }

        case MEDIA_SETAUDIOPID:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int pid = data.readInt32();
            setAudioPID(pid);
            return NO_ERROR;
        }

        case MEDIA_GETSUBTITLEPID:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeInt32(getSubtitlePID());
            return NO_ERROR;
        }

        case MEDIA_GETSUBTITLEPIDS:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeInt32(getSubtitlePIDs());
            return NO_ERROR;
        }
        
        case MEDIA_SETSUBTITLEPID:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int pid = data.readInt32();
            setSubtitlePID(pid);
            return NO_ERROR;
        }
        
        case MEDIA_DATA:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int start = data.readInt32();
            int end = data.readInt32();
            reply->writeInt32(Data(start, end));
            return NO_ERROR;
        }
        
        case MEDIA_VIDEOSHOW:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            videoshow();
            return NO_ERROR;
        }
        
        case MEDIA_VIDEOHIDE:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            videohide();
            return NO_ERROR;
        }
       
        case MEDIA_BINDNATIVEPLAYERINSTANCE:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int nativePlayerInstanceID = data.readInt32();
            reply->writeInt32(bindNativePlayerInstance(nativePlayerInstanceID));
            return NO_ERROR;
 
        }
        
        case MEDIA_RELEASEMEDIAPLAYER:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int nativePlayerInstanceID = data.readInt32();
            releaseMediaPlayer(nativePlayerInstanceID);
            return NO_ERROR;
        }

        case MEDIA_SETMUTEFLAG:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int muteFlag = data.readInt32();
            setMuteFlag(muteFlag);
            return NO_ERROR;
        }

        case MEDIA_GETMUTEFLAG:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeInt32(getMuteFlag());
            return NO_ERROR; 
        } 
          
        case MEDIA_SENONIDEOALPHA:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            int videoAlpha = data.readInt32();
            setVideoAlpha(videoAlpha);
            return NO_ERROR; 
        }

        case MEDIA_GENONIDEOALPHA:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeInt32(getVideoAlpha());
            return NO_ERROR;  
        }

        case MEDIA_GETPLAYBACKMODE:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeCString(getPlaybackMode());
            return NO_ERROR; 
        }

        case MEDIA_GETCHANNELNUM:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeInt32(getChannelNum());
            return NO_ERROR;  
        }
         
        case MEDIA_GETCURRENTAUDIOCHANNEL:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeCString(getCurrentAudioChannel());
            return NO_ERROR;         
        }
        
        case MEDIA_GETAUDIOTRACK:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            reply->writeCString(getAudioTrack());
            return NO_ERROR;         
        }

        case MEDIA_SETSINGLEMEDIA:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            leaveChannel();
            return NO_ERROR; 
        }

        case MEDIA_GOTOSTART:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            gotoStart();
            return NO_ERROR;
        }

        case MEDIA_GOTOEND:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            gotoEnd();
            return NO_ERROR;
        }

        case MEDIA_REFRESHVIDEODISPLAY:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            refreshVideoDisplay();
            return NO_ERROR;
        }
        
        case MEDIA_SWITCHAUDIOCHANNEL:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            switchAudioChannel();
            return NO_ERROR;
        }

        case MEDIA_SWITCHAUDIOTRACK:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            switchAudioTrack();
            return NO_ERROR;
        }

        case MEDIA_RUNGAME:
        {
            CHECK_INTERFACE(INONMediaService,data,reply);
            const char* values = data.readCString();
            runGame(values);
            return NO_ERROR;
        }

        default:{
            return BBinder::onTransact(code,data,reply,flags);
        }
    }
}
