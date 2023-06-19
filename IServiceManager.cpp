//
// Created by xshx on 2023/6/19.
//
#include <stdio.h>
#include "IServiceManager.h"
#include "ServiceManager.h"
static sp<IServiceManager> gDefaultServiceManager;
sp<IServiceManager> defaultServiceManager(){
    printf("defaultServiceManager\n");
    gDefaultServiceManager = new ServiceManager();
    return gDefaultServiceManager;
}
