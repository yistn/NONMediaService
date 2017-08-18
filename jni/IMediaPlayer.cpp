#define TAG "IMediaPlayer"

#include "IMediaPlayer.h"
#include "NONMediaService.h"
//#include "CTCMediaServiceClient.h"
//#include "CTC_MediaControl.h"

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

//void IMediaPlayer::instantiate()
//{
//
//}


#ifdef ICLIENT_MEDIA
CTCMediaServiceClient *m_CTCMediaServiceClient = new CTCMediaServiceClient();
#endif

IMediaPlayer* IMediaPlayer::create(NONMediaService *service)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    return new IMediaPlayer(service);
}

IMediaPlayer::IMediaPlayer(NONMediaService *service)
{
    LOGD("%s line(%d);", __func__, __LINE__);
}

IMediaPlayer::~IMediaPlayer()
{
    LOGD("%s line(%d);", __func__, __LINE__);
}

void IMediaPlayer::MediaMsg(void *arg)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    NONMediaService::iptvMediaMsg(arg);
    LOGD("%s line(%d);", __func__, __LINE__);
}


int  IMediaPlayer::create(const char* url)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    //m_CTCMediaServiceClient->initCTCMediaPlayer();
    //android_iptvmplayer_CTC_IPNONPlayer_init(""); 
    //android_iptvmplayer_CTC_IPNONPlayer_stop();
    setVolume(50);    
    setVideoDisplayArea(0,0,1280,720);
    //playFromStart();
    //url = "rtsp://182.139.229.78/PLNON/88888893/224/3221227219/10000100000000060000000001366244_0.smil?rrsip=182.138.3.139&icpid=SSPID&accounttype=1&limitflux=-1&limitdur=-1&accountinfo=:20161115150204,DMTJDTTEST16@INONP,10.99.165.125,20161115150204,Umai:CHAN/1369029@BESNON.SMG.SMG,1C724E8FAEB479D39D4C1AA23C54852D,-1,1,1,,,7,,,,4,END";
    //android_iptvmplayer_CTC_IPNONPlayer_play(url);
    LOGD("%s line(%d) url=%s;", __func__, __LINE__, url);
    return 0;
}




void IMediaPlayer::reset()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->reset();
#endif
    
    return;
}

void IMediaPlayer::play()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->play();
#endif

    return;
}

void IMediaPlayer::stop()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->stop();
#endif

    return;
}

void IMediaPlayer::pause()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->pause();
#endif

    return;
}

void IMediaPlayer::resume()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->resume();
#endif

    return;
}

void IMediaPlayer::seek(int time)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  time = %d;", __func__, __LINE__, time);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->seek(time);
#endif

    return;
}

void IMediaPlayer::fast(int speed)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  speed = %d;", __func__, __LINE__, speed);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->fast(speed);
#endif

    return;
}

void IMediaPlayer::rewind(int speed)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  speed = %d;", __func__, __LINE__, speed);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->rewind(speed);
#endif

    return;
}

int  IMediaPlayer::getVolume()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getVolume();
#endif

    return -1;
}
void IMediaPlayer::setVolume(int volume)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  volume = %d;", __func__, __LINE__, volume);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setVolume(volume);
#endif

    return;
}

int  IMediaPlayer::getMute()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getMute();
#endif
    
    return -1;
}

void IMediaPlayer::setMute(int volume)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  volume = %d;", __func__, __LINE__, volume);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setMute(volume);
#endif

    return;
}

void IMediaPlayer::setRatio()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setRatio();
#endif

    return;
}

int  IMediaPlayer::getPlayMode()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getPlayMode();
#endif
    
    return -1;
}

int  IMediaPlayer::getCurrentPos()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getCurrentPos();
#endif

    return -1;
}

int  IMediaPlayer::getVideoPixels()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getVideoPixels();
#endif

    return -1;
}

int  IMediaPlayer::getDuration()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getDuration();
#endif

    return -1;
}

int  IMediaPlayer::getVersion()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getVersion();
#endif

    return -1;
}

void IMediaPlayer::setVideoWindow(int x, int y, int width, int height, int mode)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setVideoWindow(x, y, width, height, mode);
#endif

    return;    
}

int IMediaPlayer::getPlayerInstaceId()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getPlayerInstaceId();
#endif

    return -1;
}

void IMediaPlayer::setAlpha()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setAlpha();
#endif

    return;
}

//liubin add 

char* IMediaPlayer::set(char* ioStr, char* wrStr)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if(m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->set(ioStr, wrStr);
#endif

    return "";
} 
    
char* IMediaPlayer::get(char* ioStr)                                                                                                
{ 
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->get(ioStr);
#endif

    return "";
}


int IMediaPlayer::getNativePlayerInstanceID()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getNativePlayerInstanceID();
#endif

    return -1;
}

void IMediaPlayer::setSingleOrPlaylistMode(int mode)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  mode = %d;", __func__, __LINE__, mode);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setSingleOrPlaylistMode(mode);
#endif

    return;
}

int IMediaPlayer::getSingleOrPlaylistMode()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getSingleOrPlaylistMode();
#endif

    return -1;
}

void IMediaPlayer::setVideoDisplayMode(int videoDisplayMode)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  videoDisplayMode = %d;", __func__, __LINE__, videoDisplayMode);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setVideoDisplayMode(videoDisplayMode);
#endif
    
    return;
}

int IMediaPlayer::getVideoDisplayMode()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getVideoDisplayMode();
#endif

    return -1;
}

void IMediaPlayer::setVideoDisplayArea(int x, int y, int width, int height)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setVideoDisplayArea(x, y, width, height);
#endif

    return;
}

int IMediaPlayer::getVideoDisplayLeft()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getVideoDisplayLeft();
#endif

    return -1;
}

int IMediaPlayer::getVideoDisplayTop()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getVideoDisplayTop();
#endif

    return -1;
}

int IMediaPlayer::getVideoDisplayWidth()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getVideoDisplayWidth();
#endif

    return -1;
}

int IMediaPlayer::getVideoDisplayHeight()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getVideoDisplayHeight();
#endif

    return -1;
}

void IMediaPlayer::setNativeUIFlag(int nativeUIFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  nativeUIFlag = %d;", __func__, __LINE__, nativeUIFlag);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setNativeUIFlag(nativeUIFlag);
#endif

    return;
}

int IMediaPlayer::getNativeUIFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getNativeUIFlag();
#endif

    return -1;
}

void IMediaPlayer::setMuteUIFlag(int muteUIFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  muteUIFlag = %d;", __func__, __LINE__, muteUIFlag);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setMuteUIFlag(muteUIFlag);
#endif
    
    return;
}

int IMediaPlayer::getMuteUIFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getMuteUIFlag();
#endif

    return -1;
}

void IMediaPlayer::setAudioVolumeUIFlag(int audioVolumeUIFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  audioVolumeUIFlag = %d;", __func__, __LINE__, audioVolumeUIFlag);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setAudioVolumeUIFlag(audioVolumeUIFlag);
#endif

    return; 
}

int IMediaPlayer::getAudioVolumeUIFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getAudioVolumeUIFlag();
#endif

    return -1;
}

void IMediaPlayer::setAudioTrackUIFlag(int audioTrackUIFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  audioTrackUIFlag = %d;", __func__, __LINE__, audioTrackUIFlag);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setAudioTrackUIFlag(audioTrackUIFlag);
#endif
    
    return;
}

int IMediaPlayer::getAudioTrackUIFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient>getAudioTrackUIFlag();
#endif

    return -1;
}

void IMediaPlayer::setProgressBarUIFlag(int progressBarUIFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  progressBarUIFlag = %d;", __func__, __LINE__, progressBarUIFlag);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setProgressBarUIFlag(progressBarUIFlag);
#endif
    
    return;
}

int IMediaPlayer::getProgressBarUIFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getProgressBarUIFlag();
#endif

    return -1;
}

void IMediaPlayer::setChannelNoUIFlag(int channelNOUIFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  channelNOUIFlag = %d;", __func__, __LINE__, channelNOUIFlag);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setChannelNoUIFlag(channelNOUIFlag);
#endif

    return; 
}

int IMediaPlayer::getChannelNoUIFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getChannelNoUIFlag();
#endif

    return -1;
}

void IMediaPlayer::setSubtitileFlag(int subtitileFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  subtitileFlag = %d;", __func__, __LINE__, subtitileFlag);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setSubtitileFlag(subtitileFlag);
#endif

    return;
}

int IMediaPlayer::getSubtitileFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getSubtitileFlag();
#endif

    return -1;
}

void IMediaPlayer::setAllowTrickmodeFlag(int allowTrickmodeFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  allowTrickmodeFlag = %d;", __func__, __LINE__, allowTrickmodeFlag);
#ifdef ICLIENT_MEDIA
    if(m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setAllowTrickmodeFlag(allowTrickmodeFlag);
#endif

    return;   
}

int IMediaPlayer::getAllowTrickmodeFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getAllowTrickmodeFlag();
#endif

    return -1;
}

void IMediaPlayer::setCycleFlag(int cycleFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  cycleFlag = %d;", __func__, __LINE__, cycleFlag);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setCycleFlag(cycleFlag);
#endif
   
    return;
}

int IMediaPlayer::getCycleFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getCycleFlag();
#endif

    return -1;
}

void IMediaPlayer::setRandomFlag(int randomFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  randomFlag = %d;", __func__, __LINE__, randomFlag);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setRandomFlag(randomFlag);
#endif
   
    return;
}

int IMediaPlayer::getRandomFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getRandomFlag();
#endif

    return -1;
}

void IMediaPlayer::setVendorSpecificAttr(const char* vendorSpecificAttr)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  vendorSpecificAttr = %s;", __func__, __LINE__, vendorSpecificAttr);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setVendorSpecificAttr(vendorSpecificAttr);
#endif

    return; 
}

char* IMediaPlayer::getVendorSpecificAttr()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getVendorSpecificAttr();
#endif

    return "";
}

char* IMediaPlayer::getMediaCode()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getMediaCode();
#endif

    return "";
}

char* IMediaPlayer::getCurrentPlayTime()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getCurrentPlayTime();
#endif

    return "";
}

int IMediaPlayer::GetLastError()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->GetLastError();
#endif

    return -1;
}

char* IMediaPlayer::getSubtitle()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getSubtitle();
#endif

    return "";
}

int IMediaPlayer::getMediaCount()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getMediaCount();
#endif

    return -1;
}

int IMediaPlayer::getCurrentIndex()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getCurrentIndex();
#endif

    return -1;
}

char* IMediaPlayer::getEntryID()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getEntryID();
#endif

    return "";
}

char* IMediaPlayer::getPlaylist()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getPlaylist();
#endif

    return "";
}

void IMediaPlayer::initMediaPlayer(int nativePlayerInstanceID,
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
    /*if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->initMediaPlayer(nativePlayerInstanceID, playlistFlag, videoDisplayMode, height, width,
                left, top, muteFlag, useNativeUIFlag, subtitleFlag, videoAlpha, cycleFlag, randomFlag);

    return;*/

}

int IMediaPlayer::addSingleMedia(int index, const char* mediaStr)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->addSingleMedia(index, mediaStr);
#endif

    return -1;
}

int IMediaPlayer::addBatchMedia(const char* batchMediaStr)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->addBatchMedia(batchMediaStr);
#endif

    return -1;
}

void IMediaPlayer::removeMediaByEntryID(const char* entryID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->removeMediaByEntryID(entryID);
#endif

    return;
}

void IMediaPlayer::removeMediaByIndex(int index)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->removeMediaByIndex(index);
#endif
    
    return;
}

void IMediaPlayer::clearAllMedia()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->clearAllMedia();
#endif

    return;
}

void IMediaPlayer::moveMediaByIndex(const char* entryID, int toIndex)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->moveMediaByIndex(entryID, toIndex);
#endif

    return;
}

void IMediaPlayer::moveMediaByOffset(const char* entryID, int offset)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->moveMediaByOffset(entryID, offset);
#endif

    return;
}

void IMediaPlayer::moveMediaByIndex1(int index, int toIndex)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->moveMediaByIndex1(index, toIndex);
#endif

    return;
}

void IMediaPlayer::moveMediaByOffset1(int index, int offset)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->moveMediaByOffset1(index, offset);
#endif
    
    return;
}

void IMediaPlayer::moveMediaToNext(const char* entryID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->moveMediaToNext(entryID);
#endif
    
    return;
}

void IMediaPlayer::moveMediaToPrevious(const char* entryID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->moveMediaToPrevious(entryID);
#endif
    
    return;
}

void IMediaPlayer::moveMediaToFirst(const char* entryID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->moveMediaToFirst(entryID);
#endif
    
    return;
}

void IMediaPlayer::moveMediaToLast(const char* entryID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->moveMediaToLast(entryID);
#endif

    return;
}

void IMediaPlayer::moveMediaToNext1(int index)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
       m_CTCMediaServiceClient->moveMediaToNext1(index);
#endif

    return;
}

void IMediaPlayer::moveMediaToPrevious1(int index)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
       m_CTCMediaServiceClient->moveMediaToPrevious1(index);
#endif
    
    return; 
}

void IMediaPlayer::moveMediaToFirst1(int index)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->moveMediaToFirst1(index);
#endif
    
    return;
}

void IMediaPlayer::moveMediaToLast1(int index)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->moveMediaToLast1(index);    
#endif

    return;
}

void IMediaPlayer::selectMediaByIndex(int index)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
       m_CTCMediaServiceClient->selectMediaByIndex(index);
#endif

    return; 
}

void IMediaPlayer::selectMediaByOffset(int offset)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
       m_CTCMediaServiceClient->selectMediaByOffset(offset);
#endif

    return;
}

void IMediaPlayer::selectNext()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
       m_CTCMediaServiceClient->selectNext();
#endif

    return; 
}

void IMediaPlayer::selectPrevious()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
       m_CTCMediaServiceClient->selectPrevious();
#endif
    
    return; 
}

void IMediaPlayer::selectFirst()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
       m_CTCMediaServiceClient->selectFirst();
#endif

    return;
}

void IMediaPlayer::selectLast()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->selectLast();
#endif

    return;
}

void IMediaPlayer::selectMediaByEntryID(const char* entryID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
       m_CTCMediaServiceClient->selectMediaByEntryID(entryID);
#endif

    return;
}

int IMediaPlayer::joinChannel(int userchannelid)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  userchannelid = %d;", __func__, __LINE__, userchannelid);
    //临时初始化
    int x = 0;
    int y = 0;
    int width = 1280;
    int height =720;
    setVideoDisplayArea(x,y,width,height);
    
    char* url = ""; 
    char* channelname = "";
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
    {
        m_CTCMediaServiceClient->joinChannel(url, channelname, userchannelid);
        return 0;
    }
#endif

    return -1;
}

void IMediaPlayer::leaveChannel()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->leaveChannel();
#endif

    return;
}

void IMediaPlayer::playFromStart()
{
    LOGD("%s line(%d);", __func__, __LINE__);
    //临时初始化
    int x = 0;
    int y = 0;
    int width = 1280;
    int height =720;
    setVideoDisplayArea(x,y,width,height);
    
     
    char* url = "";
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->playFromStart(url);
#endif

    return;
}

void IMediaPlayer::playByTime(int type, char* timestamp, int speed)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    
    //临时初始化
    int x = 0;
    int y = 0;
    int width = 1280;
    int height =720;
    setVideoDisplayArea(x,y,width,height);
    
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->playByTime(type, timestamp, speed);
#endif

    return;
}

void IMediaPlayer::switchSubtitle()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->switchSubtitle();
#endif

    return;
}

void IMediaPlayer::sendVendorSpecificCommand(const char* xml)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->sendVendorSpecificCommand(xml);
#endif

    return;
}

int IMediaPlayer::getAudioPID()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getAudioPID();
#endif

    return -1;
}

int IMediaPlayer::getAudioPIDs()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getAudioPIDs();
#endif

    return -1;
}

void IMediaPlayer::setAudioPID(int pid)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setAudioPID(pid);
#endif

    return;
}

int IMediaPlayer::getSubtitlePID()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getSubtitlePID();
#endif

    return -1;
}

int IMediaPlayer::getSubtitlePIDs()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getSubtitlePIDs();
#endif

    return -1;
}

void IMediaPlayer::setSubtitlePID(int pid)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setSubtitlePID(pid);
#endif

    return;
}

int IMediaPlayer::Data(int start, int end)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->Data(start, end);
#endif

    return -1;
}

void IMediaPlayer::videoshow()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->videoshow();
#endif

    return;
}

void IMediaPlayer::videohide()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->videohide();
#endif

    return; 
}

int IMediaPlayer::bindNativePlayerInstance(int nativePlayerInstanceID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  nativePlayerInstanceID = %d;", __func__, __LINE__, nativePlayerInstanceID);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->bindNativePlayerInstance(nativePlayerInstanceID);
#endif

    return -1;
}

void IMediaPlayer::releaseMediaPlayer(int nativePlayerInstanceID)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  nativePlayerInstanceID = %d;", __func__, __LINE__, nativePlayerInstanceID);
    stop();
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->releaseMediaPlayer(nativePlayerInstanceID);
#endif

    return;
}


void IMediaPlayer::setMuteFlag(int muteFlag)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  muteFlag = %d;", __func__, __LINE__, muteFlag);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setMuteFlag(muteFlag);
#endif

    return;
}

int IMediaPlayer::getMuteFlag()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getMuteFlag();
#endif

    return -1;
}

void IMediaPlayer::setVideoAlpha(int videoAlpha)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  videoAlpha = %d;", __func__, __LINE__, videoAlpha);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setVideoAlpha(videoAlpha);
#endif

    return;
}

int IMediaPlayer::getVideoAlpha()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getVideoAlpha();
#endif

    return -1;    
}
    
char* IMediaPlayer::getPlaybackMode()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getPlaybackMode();
#endif

    return "";
}

int IMediaPlayer::getChannelNum()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getChannelNum();
#endif

    return 0;
}

char* IMediaPlayer::getCurrentAudioChannel()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getCurrentAudioChannel();
#endif

    return "";
}

char* IMediaPlayer::getAudioTrack()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        return m_CTCMediaServiceClient->getAudioTrack();
#endif

    return "";
}

void IMediaPlayer::setSingleMedia(char* mediaStr)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("%s line(%d)  mediaStr = %s;", __func__, __LINE__, mediaStr);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->setSingleMedia(mediaStr);
#endif

    return;
}

void IMediaPlayer::gotoStart()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->gotoStart();
#endif

    return;
}

void IMediaPlayer::gotoEnd()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->gotoEnd();
#endif

    return;
}

void IMediaPlayer::refreshVideoDisplay()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->refreshVideoDisplay();
#endif

    return;
}

void IMediaPlayer::switchAudioChannel()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->switchAudioChannel();
#endif

    return;
}
void IMediaPlayer::switchAudioTrack()
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->switchAudioTrack();
#endif

    return;
}

//game call function                                                                                                                 
void IMediaPlayer::runGame(const char* values)
{
    LOGD("%s line(%d);", __func__, __LINE__);
#ifdef ICLIENT_MEDIA
    if (m_CTCMediaServiceClient)
        m_CTCMediaServiceClient->runGame(values);
#endif

    return;
}
