//
// Created by xshx on 2023/6/5.
// frameworks/native/libs/binder/include/binder/IInterface.h
//

#ifndef UNTITLED1_IINTERFACE_H
#define UNTITLED1_IINTERFACE_H

#include "Binder.h"

class IInterface : public virtual RefBase
{

};

template<typename INTERFACE>
class BnInterface : public INTERFACE, public  BBinder{
//    virtual sp<IInterface>      queryLocalInterface(const String& _descriptor);

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
