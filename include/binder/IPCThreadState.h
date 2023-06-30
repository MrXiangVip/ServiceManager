//
// Created by xshx on 2023/6/30.
//

#ifndef SERVICEMANAGER_IPCTHREADSTATE_H
#define SERVICEMANAGER_IPCTHREADSTATE_H
class IPCThreadState {
public:
    static             IPCThreadState *self();
    void               joinThreadPool(bool isMain = true);

};
#endif //SERVICEMANAGER_IPCTHREADSTATE_H
