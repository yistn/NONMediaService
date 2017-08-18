#ifndef TVCTCMEDIASERVICECLIENT_H 
#define TVCTCMEDIASERVICECLIENT_H 

struct TVMediaPlayerRect {                                                                                                                              
    int x;
    int y;
    int width;
    int height;
    int mode;
};

class CTCMediaServiceClient
{
    public:

        CTCMediaServiceClient();
        virtual ~CTCMediaServiceClient();
        static void MediaMsg(void *arg);
        static int EventMsg(void *arg);

        virtual void initCTCMediaPlayer();
//        virtual int  create(const char* url);
        virtual void reset();
        virtual void play();
        virtual void stop();
        virtual void pause();
        virtual void resume();
        virtual void seek(int time); 
        virtual void fast(int speed); 
        virtual void rewind(int speed); 
        virtual int  getVolume();
        virtual void setVolume(int volume);
        virtual int  getMute();
        virtual void setMute(int volume);
        virtual void setRatio(); 
        virtual int  getPlayMode();
        virtual int  getCurrentPos();
        virtual int  getVideoPixels();
        virtual int  getDuration();
        virtual int  getVersion();
        virtual void setVideoWindow(int x, int y, int width, int height, int mode);
        virtual int  getPlayerInstaceId();
        virtual void setAlpha();

        //liubin add 

        virtual char* set(char*& ioStr, char*& wrStr);
        virtual char* get(char* ioStr);

        virtual int getNativePlayerInstanceID();

        virtual void setSingleOrPlaylistMode(int mode);                                                                                          
        virtual int getSingleOrPlaylistMode();

        virtual void setVideoDisplayMode(int videoDisplayMode);
        virtual int getVideoDisplayMode();

        virtual void setVideoDisplayArea(int x, int y, int width, int height);
        
        virtual int getVideoDisplayLeft();
        virtual int getVideoDisplayTop();
        virtual int getVideoDisplayWidth();
        virtual int getVideoDisplayHeight();


        virtual void setNativeUIFlag(int nativeUIFlag);
        virtual int getNativeUIFlag();

        virtual void setMuteUIFlag(int muteUIFlag);
        virtual int getMuteUIFlag();

        virtual void setAudioVolumeUIFlag(int audioVolumeUIFlag);
        virtual int getAudioVolumeUIFlag();

        virtual void setAudioTrackUIFlag(int audioTrackUIFlag);
        virtual int getAudioTrackUIFlag();

        virtual void setProgressBarUIFlag(int progressBarUIFlag);
        virtual int getProgressBarUIFlag();

        virtual void setChannelNoUIFlag(int channelNOUIFlag);
        virtual int getChannelNoUIFlag();

        virtual void setSubtitileFlag(int subtitileFlag);
        virtual int getSubtitileFlag();

        virtual void setAllowTrickmodeFlag(int allowTrickmodeFlag);
        virtual int getAllowTrickmodeFlag();

        virtual void setCycleFlag(int cycleFlag);
        virtual int getCycleFlag();

        virtual void setRandomFlag(int randomFlag);
        virtual int getRandomFlag();

        virtual void setVendorSpecificAttr(const char*& vendorSpecificAttr);
        virtual char* getVendorSpecificAttr();

        virtual char* getMediaCode();

        //String getCurrentPlayTime();
        //virtual char* getCurrentPlayTime();
        virtual int getCurrentPlayTime();

        virtual int GetLastError();

        virtual char* getSubtitle();

        virtual int getMediaCount();

        virtual int getCurrentIndex();

        virtual char* getEntryID();

        virtual char* getPlaylist();

        void initMediaPlayer(int nativePlayerInstanceID, 
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
                int randomFlag);

        virtual int addSingleMedia(int index, const char*& mediaStr);                                                                           

        virtual int addBatchMedia(const char*& batchMediaStr);

        virtual void removeMediaByEntryID(const char*& entryID);

        virtual void removeMediaByIndex (int index);

        virtual void clearAllMedia();

        virtual void moveMediaByIndex(const char*& entryID, int toIndex);
        virtual void moveMediaByOffset(const char*& entryID, int offset);
        virtual void moveMediaByIndex1(int index, int toIndex);
        virtual void moveMediaByOffset1(int index, int offset);
        virtual void moveMediaToNext(const char*& entryID);
        virtual void moveMediaToPrevious(const char*& entryID);
        virtual void moveMediaToFirst(const char*& entryID);
        virtual void moveMediaToLast(const char*& entryID);
        virtual void moveMediaToNext1(int index);
        virtual void moveMediaToPrevious1(int index);
        virtual void moveMediaToFirst1(int index);
        virtual void moveMediaToLast1(int index);

        virtual void selectMediaByIndex(int index);
        virtual void selectMediaByOffset(int offset);
        virtual void selectNext();
        virtual void selectPrevious();
        virtual void selectFirst();
        virtual void selectLast();
        virtual void selectMediaByEntryID(const char*& entryID);

        //virtual int joinChannel(int userchannelid);
        virtual void joinChannel(char *url, char* channelname, int channelid);
       
        virtual void leaveChannel();

        //virtual void playFromStart();                                                                                                            
        virtual void playFromStart(char*& mediaStr);

        virtual void playByTime(int type, char*& timestamp, int speed);

        virtual void switchSubtitle();

        virtual void sendVendorSpecificCommand(const char*& xml);

        virtual int getAudioPID();
        virtual int getAudioPIDs();

        virtual void setAudioPID(int pid);

        virtual int getSubtitlePID();
        virtual int getSubtitlePIDs();
        virtual void setSubtitlePID(int pid);

        virtual int Data(int start, int end);

        virtual void videoshow();
        virtual void videohide();

        virtual int bindNativePlayerInstance(int nativePlayerInstanceID);

        virtual void releaseMediaPlayer(int nativePlayerInstanceID);
                
        virtual void setMuteFlag(int muteFlag);
        virtual int getMuteFlag();

        virtual void setVideoAlpha(int videoAlpha);
        virtual int getVideoAlpha();
        
        virtual char* getPlaybackMode();

        virtual int getChannelNum(); 

        virtual char* getCurrentAudioChannel();
        virtual char* getAudioTrack();

        virtual void setSingleMedia(char*& mediaStr);
        
        virtual void gotoStart();
        virtual void gotoEnd();
        virtual void refreshVideoDisplay();
        
        virtual void switchAudioChannel();
        virtual void switchAudioTrack();

        //game call function                                                                                                                 
        virtual void runGame(const char* values);

    private:
        TVMediaPlayerRect m_TVMediaPlayerRect;

};

#endif
