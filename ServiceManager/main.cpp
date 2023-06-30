/*
 * frameworks/native/cmds/servicemanager/main.cpp
 * 参考： https://blog.csdn.net/qq_40587575/article/details/130329844
 * */

#include <vector>
#include <stdio.h>
#include <iostream>
#include "ServiceManager.h"
#include "../include/binder/ProcessState.h"
#include "Looper.h"
#include <unistd.h>

int main()
{

    const char* driver =  "/dev/binder";

    sp<ProcessState> ps = ProcessState::initWithDriver(driver);
    ps->setThreadPoolMaxThreadCount(0);

// 注册自己的服务 ServiceManager，将name 和service 保存到map 中
    ServiceManager   *pServiceManager = new ServiceManager();
    sp<ServiceManager> manager = pServiceManager;

    manager->addService("manager", manager, false,0);

    ps->becomeContextManager(nullptr, nullptr);

    sp<Looper> looper = Looper::prepare(false /*allowNonCallbacks*/);
//     6）执行死循环，等待客户端消息
    while(true) {
        looper->pollAll(-1);
        sleep(1);
    }
    return 0;
}
