//
// Created by xshx on 2023/6/19.
//
#include <stdio.h>
#include "../include/binder/IServiceManager.h"
#include "../ServiceManager/ServiceManager.h"
static sp<IServiceManager> gDefaultServiceManager;
sp<IServiceManager> defaultServiceManager(){
    printf("defaultServiceManager\n");
    gDefaultServiceManager = new ServiceManager();
    return gDefaultServiceManager;
}
