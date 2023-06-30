//
// Created by xshx on 2023/6/30.
//

#ifndef SERVICEMANAGER_BNHELLOSERVICE_H
#define SERVICEMANAGER_BNHELLOSERVICE_H

#include "../include/binder/IInterface.h"
#include <stdio.h>
class IHelloService: public IInterface {

public:
//    DECLARE_META_INTERFACE(HelloService);
    virtual void sayHello() = 0;
    virtual int sayHelloTo(const char *name) = 0;

};

//服务端
class BnHelloService: public BnInterface<IHelloService> {

public:
//    status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags = 0);
    void sayHello();
    int sayHelloTo(const char *name);
};

//客户端
class BpHelloService: public BpInterface<IHelloService> {
public:
//    BpHelloService(const sp<IBinder>& impl);
    void sayHello();
    int sayHelloTo(const char *name);
};

#endif //SERVICEMANAGER_BNHELLOSERVICE_H
