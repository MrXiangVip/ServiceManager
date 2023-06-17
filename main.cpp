#include <vector>
#include <stdio.h>
#include <iostream>
#include "ServiceManager.h"
#include "ProcessState.h"
int main()
{

    const char* driver =  "/dev/binder";

    sp<ProcessState> ps = ProcessState::initWithDriver(driver);
    ps->setThreadPoolMaxThreadCount(0);


    ServiceManager   *pServiceManager = new ServiceManager();
    sp<ServiceManager> manager = pServiceManager;

    manager->addService("manager", manager, false,0);

    ps->becomeContextManager(nullptr, nullptr);


    return 0;
}
