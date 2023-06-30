//
// Created by xshx on 2023/6/30.
//
#include "../include/binder/StrongPointer.h"
#include "../include/binder/ProcessState.h"
#include "../include/binder/IServiceManager.h"
#include "IHelloService.h"
#include "../include/binder/IPCThreadState.h"
int main(int argc, char const *argv[])
{
    sp<ProcessState> proc(ProcessState::self());
    sp<IServiceManager> sm = defaultServiceManager();
    sm->addService(string("hello"), new BnHelloService());

    ProcessState::self()->startThreadPool();
    IPCThreadState::self()->joinThreadPool();

    return 0;
}