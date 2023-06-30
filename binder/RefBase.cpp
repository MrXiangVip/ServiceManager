//
// Created by xshx on 2023/6/17.
//
#include "../include/binder/RefBase.h"
#include <stdio.h>
void RefBase::incStrong(const void* id) const
{
    printf("incStrong");
}

void RefBase::decStrong(const void* id) const
{
    printf("decStrong");

}