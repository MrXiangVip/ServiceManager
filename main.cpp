#include <vector>
#include <stdio.h>
#include <iostream>
#include "ServiceManager.h"
#include "ProcessState.h"
#include "Looper.h"
#include <unistd.h>

int main()
{

    const char* driver =  "/dev/binder";

    sp<ProcessState> ps = ProcessState::initWithDriver(driver);
    ps->setThreadPoolMaxThreadCount(0);


    ServiceManager   *pServiceManager = new ServiceManager();
    sp<ServiceManager> manager = pServiceManager;

    manager->addService("manager", manager, false,0);

    ps->becomeContextManager(nullptr, nullptr);

    sp<Looper> looper = Looper::prepare(false /*allowNonCallbacks*/);
    while(true) {
        looper->pollAll(-1);
        sleep(1);
    }
    return 0;
}
