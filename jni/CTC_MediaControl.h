#ifndef _CTC_MEDIACONTROL_H_
#define _CTC_MEDIACONTROL_H_

#ifdef  __android_namespace
namespace android {
#endif

typedef int (*mplayer_event_handler)(void* arg);
struct mplayer_status
{
    int volume;
    int mute;
    char* last_igmp;
    mplayer_event_handler event_report;
};

void android_iptvmplayer_CTC_IPTVPlayer_init(void *arg);

void android_iptvmplayer_CTC_IPTVPlayer_deinit();

void android_iptvmplayer_CTC_IPTVPlayer_reset();

void android_iptvmplayer_CTC_IPTVPlayer_join(char* url, int channel_num);

void android_iptvmplayer_CTC_IPTVPlayer_play(char* url);

void android_iptvmplayer_CTC_IPTVPlayer_stop();

void android_iptvmplayer_CTC_IPTVPlayer_pause();

void android_iptvmplayer_CTC_IPTVPlayer_resume();

void android_iptvmplayer_CTC_IPTVPlayer_seek(char* seektime);

void android_iptvmplayer_CTC_IPTVPlayer_videoshow();

void android_iptvmplayer_CTC_IPTVPlayer_videohide();

void android_iptvmplayer_CTC_IPTVPlayer_gotostart();

void android_iptvmplayer_CTC_IPTVPlayer_gotoend();

void android_iptvmplayer_CTC_IPTVPlayer_ff(int speed);

void android_iptvmplayer_CTC_IPTVPlayer_fb(int speed);

void android_iptvmplayer_CTC_IPTVPlayer_stopfast();

void android_iptvmplayer_CTC_IPTVPlayer_setepgsize();

int android_iptvmplayer_CTC_IPTVPlayer_getvolume();

void android_iptvmplayer_CTC_IPTVPlayer_setvolume(int volume);

int android_iptvmplayer_CTC_IPTVPlayer_getmute();

void android_iptvmplayer_CTC_IPTVPlayer_setmute(int mute);

void android_iptvmplayer_CTC_IPTVPlayer_setratio();

int android_iptvmplayer_CTC_IPTVPlayer_getaudiobalance();

void android_iptvmplayer_CTC_IPTVPlayer_setaudiobalance(int audiobanlance);

void android_iptvmplayer_CTC_IPTVPlayer_switchaudiotrack();

void android_iptvmplayer_CTC_IPTVPlayer_switchaudiobalance();

int android_iptvmplayer_CTC_IPTVPlayer_getvideopixels();

int android_iptvmplayer_CTC_IPTVPlayer_getplaymode( char* play_mode_ptr);

int android_iptvmplayer_CTC_IPTVPlayer_getcurpos();

int android_iptvmplayer_CTC_IPTVPlayer_getduration();

int android_iptvmplayer_CTC_IPTVPlayer_mpisrunning();

void android_iptvmplayer_CTC_IPTVPlayer_gettmversion();

void android_iptvmplayer_CTC_IPTVPlayer_setvideowin(int x, int y, int w, int h, int mode);

int android_iptvmplayer_CTC_IPTVPlayer_getplayerinstaceID();

void android_iptvmplayer_CTC_IPTVPlayer_setalpha(int alpha );

void android_iptvmplayer_CTC_IPTVPlayer_cfgdatatomplayer(int volume, int mute );

int android_iptvmplayer_CTC_IPTVPlayer_getversion();

#ifdef __android_namespace
}
#endif

#endif

