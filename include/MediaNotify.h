#ifndef MEDIANOTIFY_NON_H
#define MEDIANOTIFY_NON_H
  
#include "IMediaNotify.h"  
#include "MediaNotify.h"  
#include "NONMediaPlayer.h"  
/**********************************************/  
/*! @class IMediaNotify 
  @brief NONMedia Service Proxy Interface class 
 ***********************************************/  
class MediaPlayer;

class MediaNotify : public BnMediaNotify
{ 
    public:  
        MediaNotify(NONMediaPlayer *iptvMClient);
        ~MediaNotify();

        static void instantiate();  
        void notify(int msg, int ext1, int ext2, const Parcel *obj = NULL);        
        void getUrl(int id);
        void mediaMsg(char *msg);

    private:
        NONMediaPlayer *m_iptvMClient;
}; 

#endif
