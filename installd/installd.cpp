//
// Created by xshx on 2023/6/19.
//
#include <stdio.h>
#include <stdlib.h>
#include "InstalldNativeService.h"

static int installd_main(const int argc, char *argv[]) {
    printf("installd_main \n");
    int ret;
    if ((ret = InstalldNativeService::start()) != 0) {
        printf("Unable to start InstalldNativeService: %d\n", ret);
        exit(1);
    }
    return 0;
}
int main(const int argc, char *argv[]) {
    return installd_main(argc, argv);
}
