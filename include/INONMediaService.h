#ifndef INONMEDIASERVICE_NON_H
#define INONMEDIASERVICE_NON_H


#include <binder/Parcel.h>
#include <binder/IInterface.h>
#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <cutils/properties.h>
#include <utils/Log.h>
#include <unistd.h>

#include <binder/IBinder.h>
#include <binder/IInterface.h>
 
#include <utils/Log.h>
#include <utils/String16.h> 

#define SERVICE_NAME "NONMediaService"
//#define META_INTERFACE_NAME "android.binder.example.IDemoAPI"
#include "IMediaNotify.h"

//using namespace android;
/**********************************************/
/*! @class INONMediaService
  @brief NONMedia Service Proxy Interface class
 ***********************************************/
class INONMediaService: public IInterface {
    public:
        DECLARE_META_INTERFACE(NONMediaService);
        virtual void init(const sp<IMediaNotify>& client) = 0;
        virtual int  create(const char* url, int id) = 0;
        virtual void reset() = 0;
        virtual void play() = 0;
        virtual void stop() = 0;
        virtual void pause() = 0;
        virtual void resume() = 0;
        virtual void seek(int time) = 0; 
        virtual void fast(int speed) = 0; 
        virtual void rewind(int speed) = 0; 
        virtual int  getVolume() = 0;
        virtual void setVolume(int volume) = 0;
        virtual int  getMute() = 0;
        virtual void setMute(int volume) = 0;
        virtual void setRatio() = 0; 
        virtual int  getPlayMode() = 0;
        virtual int  getCurrentPos() = 0;
        virtual int  getVideoPixels() = 0;
        virtual int  getDuration() = 0;
        virtual int  getVersion() = 0;
        virtual void setVideoWindow(int x, int y, int width, int height, int mode) = 0;
        virtual int  getPlayerInstaceId() = 0;
        virtual void setAlpha() = 0;

        //liubin add 

        virtual char* set(char* ioStr, char* wrStr) = 0;
        virtual char* get(char* ioStr) = 0;

        virtual int getNativePlayerInstanceID() = 0;

        virtual void setSingleOrPlaylistMode(int mode) = 0;                                                                                          
        virtual int getSingleOrPlaylistMode() = 0;

        virtual void setVideoDisplayMode(int videoDisplayMode) = 0;
        virtual int getVideoDisplayMode() = 0;

        virtual void setVideoDisplayArea(int x, int y, int width, int height) = 0;
        
        virtual int getVideoDisplayLeft() = 0;
        virtual int getVideoDisplayTop() = 0;
        virtual int getVideoDisplayWidth() = 0;
        virtual int getVideoDisplayHeight() = 0;


        virtual void setNativeUIFlag(int nativeUIFlag) = 0;
        virtual int getNativeUIFlag() = 0;

        virtual void setMuteUIFlag(int muteUIFlag) = 0;
        virtual int getMuteUIFlag() = 0;

        virtual void setAudioVolumeUIFlag(int audioVolumeUIFlag) = 0;
        virtual int getAudioVolumeUIFlag() = 0;

        virtual void setAudioTrackUIFlag(int audioTrackUIFlag) = 0;
        virtual int getAudioTrackUIFlag() = 0;

        virtual void setProgressBarUIFlag(int progressBarUIFlag) = 0;
        virtual int getProgressBarUIFlag() = 0;

        virtual void setChannelNoUIFlag(int channelNOUIFlag) = 0;
        virtual int getChannelNoUIFlag() = 0;

        virtual void setSubtitileFlag(int subtitileFlag) = 0;
        virtual int getSubtitileFlag() = 0;

        virtual void setAllowTrickmodeFlag(int allowTrickmodeFlag) = 0;
        virtual int getAllowTrickmodeFlag() = 0;

        virtual void setCycleFlag(int cycleFlag) = 0;
        virtual int getCycleFlag() = 0;

        virtual void setRandomFlag(int randomFlag) = 0;
        virtual int getRandomFlag() = 0;

        virtual void setVendorSpecificAttr(const char* vendorSpecificAttr) = 0;
        virtual char* getVendorSpecificAttr() = 0;

        virtual char* getMediaCode() = 0;

        //String getCurrentPlayTime();
        virtual char* getCurrentPlayTime() = 0;
        
        virtual int GetLastError() = 0;

        virtual char* getSubtitle() = 0;

        virtual int getMediaCount() = 0;

        virtual int getCurrentIndex() = 0;

        virtual char* getEntryID() = 0;

        virtual char* getPlaylist() = 0;

        virtual void initMediaPlayer(int nativePlayerInstanceID, 
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
                int randomFlag) = 0;

        virtual int addSingleMedia(int index, const char* mediaStr) = 0;                                                                           

        virtual int addBatchMedia(const char* batchMediaStr) = 0;

        virtual void removeMediaByEntryID(const char* entryID) = 0;

        virtual void removeMediaByIndex (int index) = 0;

        virtual void clearAllMedia() = 0;

        virtual void moveMediaByIndex(const char* entryID, int toIndex) = 0;
        virtual void moveMediaByOffset(const char* entryID, int offset) = 0;
        virtual void moveMediaByIndex1(int index, int toIndex) = 0;
        virtual void moveMediaByOffset1(int index, int offset) = 0;
        virtual void moveMediaToNext(const char* entryID) = 0;
        virtual void moveMediaToPrevious(const char* entryID) = 0;
        virtual void moveMediaToFirst(const char* entryID) = 0;
        virtual void moveMediaToLast(const char* entryID) = 0;
        virtual void moveMediaToNext1(int index) = 0;
        virtual void moveMediaToPrevious1(int index) = 0;
        virtual void moveMediaToFirst1(int index) = 0;
        virtual void moveMediaToLast1(int index) = 0;

        virtual void selectMediaByIndex(int index) = 0;
        virtual void selectMediaByOffset(int offset) = 0;
        virtual void selectNext() = 0;
        virtual void selectPrevious() = 0;
        virtual void selectFirst() = 0;
        virtual void selectLast() = 0;
        virtual void selectMediaByEntryID(const char* entryID)= 0;

        virtual int joinChannel(int userchannelid) = 0;
//        virtual void joinChannel(char *url, char* channelname, int channelid);
        virtual void leaveChannel() = 0;

        virtual void playFromStart() = 0;                                                                                                            
        //virtual void playFromStart(char* mediaStr);

        virtual void playByTime(int type, char* timestamp, int speed) = 0;

        virtual void switchSubtitle() = 0;

        virtual void sendVendorSpecificCommand(const char* xml) = 0;

        virtual int getAudioPID() = 0;
        virtual int getAudioPIDs() = 0;

        virtual void setAudioPID(int pid) = 0;

        virtual int getSubtitlePID() = 0;
        virtual int getSubtitlePIDs() = 0;
        virtual void setSubtitlePID(int pid) = 0;

        virtual int Data(int start, int end) = 0;

        virtual void videoshow() = 0;
        virtual void videohide() = 0;

        virtual int bindNativePlayerInstance(int nativePlayerInstanceID) = 0;

        virtual void releaseMediaPlayer(int nativePlayerInstanceID) = 0;
                
        virtual void setMuteFlag(int muteFlag) = 0;
        virtual int getMuteFlag() = 0;

        virtual void setVideoAlpha(int videoAlpha) = 0;
        virtual int getVideoAlpha() = 0;
        
        virtual char* getPlaybackMode() = 0;

        virtual int getChannelNum() = 0; 

        virtual char* getCurrentAudioChannel() = 0;
        virtual char* getAudioTrack() = 0;

        virtual void setSingleMedia(char* mediaStr) = 0;
        
        virtual void gotoStart() = 0;
        virtual void gotoEnd() = 0;
        virtual void refreshVideoDisplay() = 0;
        
        virtual void switchAudioChannel() = 0;
        virtual void switchAudioTrack() = 0;

        //game call function                                                                                                                 
        virtual void runGame(const char* values) = 0;

    protected:
        enum{
            MEDIA_INIT = IBinder::FIRST_CALL_TRANSACTION,
            MEDIA_CREATE,
            MEDIA_RESET,
            MEDIA_PLAY,
            MEDIA_STOP,
            MEDIA_PAUSE,
            MEDIA_RESUME,
            MEDIA_SEEK, 
            MEDIA_FAST,
            MEDIA_REWIND,
            MEDIA_GENONOLUME,
            MEDIA_SENONOLUME,
            MEDIA_GETMUTE,
            MEDIA_SETMUTE,
            MEDIA_SETRATIO,
            MEDIA_GETPLAYMODE,
            MEDIA_GETCURRENTPOS,
            MEDIA_GENONIDEOPIXELS,
            MEDIA_GETDURATION,
            MEDIA_GENONERSION,
            MEDIA_SENONIDEOWINDOW,
            MEDIA_GETPLAYERINSTACEID,
            MEDIA_SETALPHA,
            //NON add
            MEDIA_SET,
            MEDIA_GET,
            MEDIA_GETNATIVEPLAYERINSTANCEID,
            MEDIA_SETSINGLEORPLAYLISTMODE,
            MEDIA_GETSINGLEORPLAYLISTMODE,
            MEDIA_SENONIDEODISPLAYMODE,
            MEDIA_GENONIDEODISPLAYMODE,
            MEDIA_SENONIDEODISPLAYAREA,
            MEDIA_GENONIDEODISPLAYLEFT,
            MEDIA_GENONIDEODISPLAYTOP,
            MEDIA_GENONIDEODISPLAYWIDTH,
            MEDIA_GENONIDEODISPLAYHEIGHT,
            MEDIA_SETNATIVEUIFLAG,
            MEDIA_GETNATIVEUIFLAG,
            MEDIA_SETMUTEUIFLAG,
            MEDIA_GETMUTEUIFLAG,
            MEDIA_SETAUDIOVOLUMEUIFLAG,
            MEDIA_GETAUDIOVOLUMEUIFLAG,
            MEDIA_SETAUDIOTRACKUIFLAG,
            MEDIA_GETAUDIOTRACKUIFLAG,
            MEDIA_SETPROGRESSBARUIFLAG,
            MEDIA_GETPROGRESSBARUIFLAG,
            MEDIA_SETCHANNELNOUIFLAG,
            MEDIA_GETCHANNELNOUIFLAG,
            MEDIA_SETSUBTITILEFLAG,
            MEDIA_GETSUBTITILEFLAG,
            MEDIA_SETALLOWTRICKMODEFLAG,
            MEDIA_GETALLOWTRICKMODEFLAG,
            MEDIA_SETCYCLEFLAG,
            MEDIA_GETCYCLEFLAG,
            MEDIA_SETRANDOMFLAG,
            MEDIA_GETRANDOWFLAG,
            MEDIA_SENONENDORSPECIFICATTR,
            MEDIA_GENONENDORSPECIFICATTR,
            MEDIA_GETMEDIACODE,
            MEDIA_GETCURRENTPLAYTIME,
            MEDIA_GETLASTERROR,
            MEDIA_GETSUBTITLE,
            MEDIA_GETMEDIACOUNT,
            MEDIA_GETCURRENTINDEX,
            MEDIA_GETENTRYID,
            MEDIA_GETPLAYLIST,
            MEDIA_INITMEDIAPLAYER,
            MEDIA_ADDSINGLEMEDIA,
            MEDIA_ADDBATCHMEDIA,
            MEDIA_REMOVEMEDIABYENTRYID,
            MEDIA_REMOVEMEDIABYINDEX,
            MEDIA_CLEARALLMEDIA,
            MEDIA_MOVEMEDIABYINDEX,
            MEDIA_MOVEMEDIABYOFFSET,
            MEDIA_MOVEMEDIABYINDEX1,
            MEDIA_MOVEMEDIABYOFFSET1,
            MEDIA_MOVEMEDIATONEXT,
            MEDIA_MOVEMEDIATOPREVIOUS,
            MEDIA_MOVEMEDIATOFIRST,
            MEDIA_MOVEMEDIATOLAST,
            MEDIA_MOVEMEDIATONEXT1,
            MEDIA_MOVEMEDIATOPREVIOUS1,
            MEDIA_MOVEMEDIATOFIRST1,
            MEDIA_MOVEMEDIATOLAST1,
            MEDIA_SELECTMEDIABYINDEX,
            MEDIA_SELECTMEDIABYOFFSET,
            MEDIA_SELECTNEXT,
            MEDIA_SELECTPREVIOUS,
            MEDIA_SELECTFIRST,
            MEDIA_SELECTLAST,
            MEDIA_SELECTMEDIABYENTRYID,
            MEDIA_JOINCHANNEL,
            MEDIA_LEAVECHANNEL,
            MEDIA_PLAYFROMSTART,
            MEDIA_PLAYBYTIME,
            MEDIA_SWITCHSUBTITLE,
            MEDIA_SENDVENDORSPECIFICCOMMAND,
            MEDIA_GETAUDIOPID,
            MEDIA_GETAUDIOPIDS,
            MEDIA_SETAUDIOPID,
            MEDIA_GETSUBTITLEPID,
            MEDIA_GETSUBTITLEPIDS,
            MEDIA_SETSUBTITLEPID,
            MEDIA_DATA,
            MEDIA_VIDEOSHOW,
            MEDIA_VIDEOHIDE,
            MEDIA_BINDNATIVEPLAYERINSTANCE,
            MEDIA_RELEASEMEDIAPLAYER,
            MEDIA_SETMUTEFLAG,
            MEDIA_GETMUTEFLAG,
            MEDIA_SENONIDEOALPHA,
            MEDIA_GENONIDEOALPHA,
            MEDIA_GETPLAYBACKMODE,
            MEDIA_GETCHANNELNUM,
            MEDIA_GETCURRENTAUDIOCHANNEL,
            MEDIA_GETAUDIOTRACK,
            MEDIA_SETSINGLEMEDIA,
            MEDIA_GOTOSTART,
            MEDIA_GOTOEND,
            MEDIA_REFRESHVIDEODISPLAY,
            MEDIA_SWITCHAUDIOCHANNEL,
            MEDIA_SWITCHAUDIOTRACK,
            //game call function                                                                                                                 
            MEDIA_RUNGAME,
 
            MEDIA_REGCB,
            MEDIA_UNREGCB,
        };
};
//声明并实现binder实体类BnInterface
class BnNONMediaService : public BnInterface<INONMediaService> {  
    public:  
        virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags);   
};  

#endif
