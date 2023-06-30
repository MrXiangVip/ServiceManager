//
// Created by xshx on 2023/6/19.
//

#ifndef SERVICEMANAGER_INSTALLDNATIVESERVICE_H
#define SERVICEMANAGER_INSTALLDNATIVESERVICE_H

#include <stdio.h>
#include "../include/binder/BinderService.h"
#include "BnInstalld.h"
class InstalldNativeService : public BinderService<InstalldNativeService>, public BnInstalld{
public:
    static int start();

    static char const* getServiceName() { return "installd"; }

};
#endif //SERVICEMANAGER_INSTALLDNATIVESERVICE_H
