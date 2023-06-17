//
// Created by xshx on 2023/6/17.
//
#include "Looper.h"
#include <pthread.h>


static pthread_once_t gTLSOnce = PTHREAD_ONCE_INIT;
static pthread_key_t gTLSKey = 0;
Looper::Looper(bool allowNonCallbacks)    : mAllowNonCallbacks(allowNonCallbacks)
{

}

void Looper::initTLSKey() {
    int error = pthread_key_create(&gTLSKey, threadDestructor);
//    LOG_ALWAYS_FATAL_IF(error != 0, "Could not allocate TLS key: %s", strerror(error));
}

void Looper::threadDestructor(void *st) {
    Looper* const self = static_cast<Looper*>(st);
    if (self != nullptr) {
        self->decStrong((void*)threadDestructor);
    }
}

sp<Looper> Looper::getForThread() {
    printf("getForThread\n");
    int result = pthread_once(& gTLSOnce, initTLSKey);
//    LOG_ALWAYS_FATAL_IF(result != 0, "pthread_once failed");

    return (Looper*)pthread_getspecific(gTLSKey);
}

sp<Looper> Looper::prepare(int opts) {
    printf("prepare\n");
    bool allowNonCallbacks = opts ;
    sp<Looper> looper = Looper::getForThread();
    if (looper == nullptr) {
        looper = new Looper(allowNonCallbacks);
        Looper::setForThread(looper);
    }
    return looper;

}


void Looper::setForThread(const sp<Looper>& looper) {
    printf("setForThread\n");
    pthread_setspecific(gTLSKey, looper.get());

}

int Looper::pollAll(int timeoutMillis, int* outFd, int* outEvents, void** outData) {
    printf("pollAll \n");
    return 0;
}