//
// Created by xshx on 2023/6/5.
// frameworks/native/include/binder/Binder.h
//

#ifndef UNTITLED1_BINDER_H
#define UNTITLED1_BINDER_H

#include "IBinder.h"
class BBinder : public IBinder
{
//public:
//    BBinder();
//
//    virtual const String16& getInterfaceDescriptor() const;
//    virtual bool        isBinderAlive() const;
//    virtual status_t    pingBinder();
//    virtual status_t    dump(int fd, const Vector<String16>& args);
//
//    // NOLINTNEXTLINE(google-default-arguments)
//    virtual status_t    transact(   uint32_t code,
//                                    const Parcel& data,
//                                    Parcel* reply,
//                                    uint32_t flags = 0) final;
//
//    // NOLINTNEXTLINE(google-default-arguments)
//    virtual status_t    linkToDeath(const sp<DeathRecipient>& recipient,
//                                    void* cookie = nullptr,
//                                    uint32_t flags = 0);
//
//    // NOLINTNEXTLINE(google-default-arguments)
//    virtual status_t    unlinkToDeath(  const wp<DeathRecipient>& recipient,
//                                        void* cookie = nullptr,
//                                        uint32_t flags = 0,
//                                        wp<DeathRecipient>* outRecipient = nullptr);
//
//    virtual void        attachObject(   const void* objectID,
//                                        void* object,
//                                        void* cleanupCookie,
//                                        object_cleanup_func func) final;
//    virtual void*       findObject(const void* objectID) const final;
//    virtual void        detachObject(const void* objectID) final;
//
//    virtual BBinder*    localBinder();
//
//    bool                isRequestingSid();
//    // This must be called before the object is sent to another process. Not thread safe.
//    void                setRequestingSid(bool requestSid);
//
//    sp<IBinder>         getExtension();
//    // This must be called before the object is sent to another process. Not thread safe.
//    void                setExtension(const sp<IBinder>& extension);
//
//    pid_t               getDebugPid();
//
//protected:
//    virtual             ~BBinder();
//
//    // NOLINTNEXTLINE(google-default-arguments)
//    virtual status_t    onTransact( uint32_t code,
//                                    const Parcel& data,
//                                    Parcel* reply,
//                                    uint32_t flags = 0);
//
//private:
//    BBinder(const BBinder& o);
//    BBinder&    operator=(const BBinder& o);
//
//    class Extras;
//
//    Extras*             getOrCreateExtras();
//
//    std::atomic<Extras*> mExtras;
//
//    friend ::android::internal::Stability;
//    union {
//        int32_t mStability;
//        void* mReserved0;
//    };
};

class BpRefBase : public virtual RefBase
{
//protected:
//    explicit                BpRefBase(const sp<IBinder>& o);
//    virtual                 ~BpRefBase();
//    virtual void            onFirstRef();
//    virtual void            onLastStrongRef(const void* id);
//    virtual bool            onIncStrongAttempted(uint32_t flags, const void* id);
//
//    inline  IBinder*        remote()                { return mRemote; }
//    inline  IBinder*        remote() const          { return mRemote; }
//
//private:
//    BpRefBase(const BpRefBase& o);
//    BpRefBase&              operator=(const BpRefBase& o);
//
//    IBinder* const          mRemote;
//    RefBase::weakref_type*  mRefs;
//    std::atomic<int32_t>    mState;
};

#endif //UNTITLED1_BINDER_H
