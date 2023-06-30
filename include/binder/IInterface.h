//
// Created by xshx on 2023/6/5.
// frameworks/native/libs/binder/include/binder/IInterface.h
//

#ifndef UNTITLED1_IINTERFACE_H
#define UNTITLED1_IINTERFACE_H

#include "Binder.h"

class IInterface : public virtual RefBase
{
//public:
//    IInterface();
//    static sp<IBinder>  asBinder(const IInterface*);
//    static sp<IBinder>  asBinder(const sp<IInterface>&);
//
//protected:
//    virtual                     ~IInterface();
//    virtual IBinder*            onAsBinder() = 0;
};

template<typename INTERFACE>
class BnInterface : public INTERFACE, public  BBinder{
public:
//    virtual sp<IInterface>      queryLocalInterface(const String16& _descriptor);
//    virtual const String16&     getInterfaceDescriptor() const;
//
protected:
//    typedef INTERFACE           BaseInterface;
//    virtual IBinder*            onAsBinder();

};

template<typename INTERFACE>
class BpInterface : public INTERFACE, public BpRefBase
{
public:
//    explicit                    BpInterface(const sp<IBinder>& remote);

protected:
//    typedef INTERFACE           BaseInterface;
//    virtual IBinder*            onAsBinder();
};
#endif //UNTITLED1_IINTERFACE_H
