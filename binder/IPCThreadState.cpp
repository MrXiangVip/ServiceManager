//
// Created by xshx on 2023/6/30.
//
#include "../include/binder/IPCThreadState.h"
#include <stdio.h>
IPCThreadState* IPCThreadState::self()
{

}


void IPCThreadState::joinThreadPool(bool isMain)
{
    printf("joinThreadPool \n");

}