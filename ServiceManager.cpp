//
// Created by xshx on 2023/6/5.
// frameworks/native/cmds/servicemanager/ServiceManager.cpp
//
#include <iostream>
#include "ServiceManager.h"
int ServiceManager::getService(const std::string& name, sp<IBinder>* outBinder) {
    cout << "getService " << name;
    *outBinder = tryGetService(name, true);
    // returns ok regardless of result for legacy reasons
    return 0;
}

int ServiceManager::checkService(const std::string& name, sp<IBinder>* outBinder) {
    cout << "checkService " << name;
    *outBinder = tryGetService(name, false);
    // returns ok regardless of result for legacy reasons
    return 0;
}

sp<IBinder> ServiceManager::tryGetService(const std::string& name, bool startIfNotFound) {
    cout << "tryGetService " << name;
    sp<IBinder> out;
    Service* service = nullptr;
    if (auto it = mNameToService.find(name); it != mNameToService.end()) {
        service = &(it->second);


        out = service->binder;
    }



    return out;
}

int ServiceManager::addService(const std::string& name, const sp<IBinder>& binder, bool allowIsolated, int32_t dumpPriority) {
    cout << "addService " << name;
    auto entry = mNameToService.emplace(name, Service {
            .binder = binder,
            .allowIsolated = allowIsolated,
            .dumpPriority = dumpPriority,
            .debugPid = 0,
    });

    return 0;

}

int ServiceManager::listServices(int32_t dumpPriority, std::vector<std::string>* outList) {


    size_t toReserve = 0;
    for (auto const& [name, service] : mNameToService) {
        (void) name;

        if (service.dumpPriority & dumpPriority) ++toReserve;
    }


    outList->reserve(toReserve);
    for (auto const& [name, service] : mNameToService) {
        (void) service;

        if (service.dumpPriority & dumpPriority) {
            outList->push_back(name);
        }
    }

    return 0;
}