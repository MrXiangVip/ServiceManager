//
// Created by xshx on 2023/6/30.
//
#include "IHelloService.h"
void BnHelloService::sayHello() {
    static int count = 0;
    printf("say hello :%d\n ", ++count);
}

int BnHelloService::sayHelloTo(const char *name) {
    static int cnt = 0;
    printf("say hello to %s : %d\n", name, ++cnt);
    return cnt;
}
