//
// Created by xshx on 2023/6/17.
//

#ifndef SERVICEMANAGER_PROCESSSTATE_H
#define SERVICEMANAGER_PROCESSSTATE_H

#include <cstring>
#include <string>
#include "StrongPointer.h"
#include "IBinder.h"
using namespace std;
class ProcessState : public virtual RefBase
{

public:
    static  sp<ProcessState>    initWithDriver(const char *driver);


    int            setThreadPoolMaxThreadCount(size_t maxThreads);

    typedef bool (*context_check_func)(const string& name,
                                       const sp<IBinder>& caller,
                                       void* userData);
    bool                becomeContextManager(
            context_check_func checkFunc,
            void* userData);

private:
    explicit            ProcessState(const char* driver);
                        ~ProcessState();


    size_t              mMaxThreads;
    bool                mManagesContexts;
    string              mDriverName;


};

#endif //SERVICEMANAGER_PROCESSSTATE_H
