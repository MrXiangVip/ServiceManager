#include <vector>
#include <stdio.h>
#include <iostream>
#include "ServiceManager.h"
int main()
{

    ServiceManager   *pServiceManager = new ServiceManager();
    sp<ServiceManager> manager = pServiceManager;

    manager->addService("manager", manager, false,0);
    return 0;
}
