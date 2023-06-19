//
// Created by xshx on 2023/6/19.
//
#ifndef ANDROID_BINDER_SERVICE_H
#define ANDROID_BINDER_SERVICE_H

#include "StrongPointer.h"
#include "IServiceManager.h"
using namespace std;

template<typename SERVICE>
class BinderService {
public:
    static int publish(bool allowIsolated = false,
                            int dumpFlags=0 ) {
        sp <IServiceManager> sm(defaultServiceManager());
        return sm->addService(string(SERVICE::getServiceName()), new SERVICE(), allowIsolated,
                              dumpFlags);
    }

};

#endif // ANDROID_BINDER_SERVICE_H
