//
// Created by xshx on 2023/6/5.
// frameworks/native/cmds/servicemanager/ServiceManager.h
//

#ifndef UNTITLED1_SERVICEMANAGER_H
#define UNTITLED1_SERVICEMANAGER_H

#include <map>
#include "IBinder.h"
#include "BnServiceManager.h"
#include "StrongPointer.h"
#include <vector>
using namespace std;
class ServiceManager :public BnServiceManager{

public:
    int getService(const std::string& name, sp<IBinder>* outBinder) ;
    int checkService(const std::string& name, sp<IBinder>* outBinder) ;
    int addService(const std::string& name, const sp<IBinder>& binder,
                              bool allowIsolated, int32_t dumpPriority) ;
    int listServices(int32_t dumpPriority, std::vector<std::string>* outList) ;
private:
    struct Service {
        sp<IBinder>     binder; // not null
        bool            allowIsolated;
        int32_t         dumpPriority;
        bool            hasClients = false; // notifications sent on true -> false.
        bool            guaranteeClient = false; // forces the client check to true
        pid_t           debugPid = 0; // the process in which this service runs

        // the number of clients of the service, including servicemanager itself
        ssize_t         getNodeStrongRefCount();

    };
    using ServiceMap = std::map<std::string, Service>;
    sp<IBinder> tryGetService(const std::string& name, bool startIfNotFound);

    ServiceMap mNameToService;

};

#endif //UNTITLED1_SERVICEMANAGER_H
