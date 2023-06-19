//
// Created by xshx on 2023/6/19.
//

#include "IServiceManager.h"

static sp<IServiceManager> gDefaultServiceManager;
sp<IServiceManager> defaultServiceManager(){
    return gDefaultServiceManager;
}
