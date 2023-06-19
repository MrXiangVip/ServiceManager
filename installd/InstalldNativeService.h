//
// Created by xshx on 2023/6/19.
//

#ifndef SERVICEMANAGER_INSTALLDNATIVESERVICE_H
#define SERVICEMANAGER_INSTALLDNATIVESERVICE_H

#include <stdio.h>
class InstalldNativeService {
public:
    static int start();

    static char const* getServiceName() { return "installd"; }

};
#endif //SERVICEMANAGER_INSTALLDNATIVESERVICE_H
