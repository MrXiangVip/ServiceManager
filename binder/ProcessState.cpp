//
// Created by xshx on 2023/6/17.
// 源码路径: frameworks/native/libs/binder/ProcessState.cpp
//
#include "../include/binder/ProcessState.h"
#include "../include/binder/Static.h"
sp<ProcessState> ProcessState::self()
{
    gProcess = new ProcessState("");
    return gProcess;
}


ProcessState::ProcessState(const char *driver) : mDriverName(string(driver))
{

}
sp<ProcessState> ProcessState::initWithDriver(const char* driver)
{
    gProcess = new ProcessState(driver);
    return gProcess;
}


int ProcessState::setThreadPoolMaxThreadCount(size_t maxThreads) {

    mMaxThreads = maxThreads;

    return 0;
}

bool ProcessState::becomeContextManager(context_check_func checkFunc, void* userData)
{
    printf("becomeContextManager\n");
    return  mManagesContexts;
}

void ProcessState::startThreadPool()
{

}