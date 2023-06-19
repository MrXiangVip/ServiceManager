//
// Created by xshx on 2023/6/7.
//

#ifndef UNTITLED1_ISERVICEMANAGER_H
#define UNTITLED1_ISERVICEMANAGER_H

#include "IInterface.h"
#include "StrongPointer.h"
#include <string>
using namespace std;
class IServiceManager : public IInterface{

public:
//    virtual int addService(const string& name, const sp<IBinder>& service,
//                                bool allowIsolated = false,
//                                int dumpsysFlags = 0) = 0;
};
sp<IServiceManager> defaultServiceManager();

#endif //UNTITLED1_ISERVICEMANAGER_H
