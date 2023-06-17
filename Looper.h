//
// Created by xshx on 2023/6/17.
//

#ifndef SERVICEMANAGER_LOOPER_H
#define SERVICEMANAGER_LOOPER_H

#include "RefBase.h"
#include "StrongPointer.h"
class Looper : public RefBase {

public:
    Looper(bool allowNonCallbacks);


    int pollAll(int timeoutMillis, int* outFd, int* outEvents, void** outData);
    inline int pollAll(int timeoutMillis) {
        return pollAll(timeoutMillis, nullptr, nullptr, nullptr);
    }
    static sp<Looper> prepare(int opts);

    static void setForThread(const sp<Looper>& looper);

    static sp<Looper> getForThread();

    static void initTLSKey();
    static void threadDestructor(void *st);

private:
    const bool mAllowNonCallbacks; // immutable

};
#endif //SERVICEMANAGER_LOOPER_H
