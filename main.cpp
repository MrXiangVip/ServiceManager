#include <vector>
#include <stdio.h>
#include <iostream>
#include "ServiceManager.h"
int main()
{

    sp<ServiceManager> manager = new ServiceManager();

    manager->addService("manager", nullptr, false,0);
//    manager->addService("manager", manager, false,0);
    return 0;
}
