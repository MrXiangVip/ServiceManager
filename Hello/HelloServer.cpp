//
// Created by xshx on 2023/6/30.
//
#include "../StrongPointer.h"
#include "../ProcessState.h"
#include "../IServiceManager.h"
#include "IHelloService.h"
#include "../IPCThreadState.h"
int main(int argc, char const *argv[])
{
    sp<ProcessState> proc(ProcessState::self());
    sp<IServiceManager> sm = defaultServiceManager();
    sm->addService(string("hello"), new BnHelloService());

    ProcessState::self()->startThreadPool();
    IPCThreadState::self()->joinThreadPool();

    return 0;
}