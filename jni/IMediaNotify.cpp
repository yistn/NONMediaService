#define TAG "IMediaNotify"

#include "IMediaNotify.h"

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

enum{
    NOTIFY = IBinder::FIRST_CALL_TRANSACTION,
    GETURL,
    MEDIAMSG
};

class BpMediaNotify: public BpInterface<IMediaNotify>                                                                                   
{
    public:
        BpMediaNotify(const sp<IBinder>& impl)
            : BpInterface<IMediaNotify>(impl)
        {
        }
        
        virtual void notify(int msg, int ext1, int ext2, const Parcel *obj)
        {                                                                                                                                               
            LOGD("%s line(%d);", __func__, __LINE__);
            LOGD("IMediaNotify::notify start");
            Parcel data, reply;
            //data.writeInterfaceToken(IMediaPlayerClient::getInterfaceDescriptor());
            data.writeInt32(msg);
            data.writeInt32(ext1);        
            data.writeInt32(ext2);        
            if (obj && obj->dataSize() > 0) {
                data.appendFrom(const_cast<Parcel *>(obj), 0, obj->dataSize());
            }
            remote()->transact(NOTIFY, data, &reply, IBinder::FLAG_ONEWAY);
            LOGD("IMediaNotify::notify end");
            LOGD("%s line(%d);", __func__, __LINE__);
        }


        virtual void getUrl(int id)
        {
            LOGD("%s line(%d);", __func__, __LINE__);
            LOGD("IMediaNotify::getUrl start id=%d", id);
            Parcel data, reply;
            data.writeInterfaceToken(IMediaNotify::getInterfaceDescriptor());
            data.writeInt32(id);
            status_t status = remote()->transact(GETURL, data, &reply, IBinder::FLAG_ONEWAY);
            LOGD("IMediaNotify::getUrl end");
            LOGD("%s line(%d);", __func__, __LINE__);
            return; 
        }

        virtual void mediaMsg(const char *msg)
        {
            LOGD("%s line(%d);", __func__, __LINE__);
            LOGD("IMediaNotify::mediaMsg start msg=%s", msg);
            Parcel data, reply;
            data.writeInterfaceToken(IMediaNotify::getInterfaceDescriptor());
            data.writeCString(msg);
            remote()->transact(MEDIAMSG, data, &reply, IBinder::FLAG_ONEWAY);
            LOGD("IMediaNotify::mediaMsg end");
            LOGD("%s line(%d);", __func__, __LINE__);
            return; 
        }
};

IMPLEMENT_META_INTERFACE(MediaNotify, "com.iptvmedia.IMediaNotify");
// ----------------------------------------------------------------------

status_t BnMediaNotify::onTransact(
        uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{
    LOGD("%s line(%d);", __func__, __LINE__);
    LOGD("BnMediaNotify::onTransact");
    switch (code) {
        case NOTIFY: 
            {                                                                                                                              
                //CHECK_INTERFACE(IMediaPlayerClient, data, reply);
                int msg = data.readInt32();
                int ext1 = data.readInt32();
                int ext2 = data.readInt32();
                Parcel obj;
                if (data.dataAvail() > 0) {
                    obj.appendFrom(const_cast<Parcel *>(&data), data.dataPosition(), data.dataAvail());
                }

                notify(msg, ext1, ext2, &obj);
                return NO_ERROR;
            } break;

        case GETURL: 
            {
                CHECK_INTERFACE(IMediaNotify, data, reply);
                getUrl(data.readInt32()); 
                return NO_ERROR;
            } break;

        case MEDIAMSG:
            {
                CHECK_INTERFACE(IMediaNotify, data, reply);
                mediaMsg(const_cast<char *>(data.readCString()));
                return NO_ERROR;
            } break;

        default:
             return BBinder::onTransact(code, data, reply, flags);
    }
}
