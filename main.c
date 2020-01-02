//
// Created by myzin on 2019/7/15.
//

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>

#include "MD5/md5.h"
#include "UDP/udpCtl.h"
#include "Others/others.h"

int main(){
    pthread_t pid_1,pid_init;
    int err;
    void *tret;
    err = pthread_create(&pid_1, NULL, udpRec, NULL);
    if(err != 0)
        perror("后台线程创建失败，请检查！\n");
    while(1){
        printf("请选择操作：\n");
        printf("1. 显示所有服务器文件\n");
        printf("2. 管理本地存储的服务器文件\n");
        printf("3. 记录本地文件到服务器\n");
        printf("0. 退出程序\n");

        int a;
        scanf("%d", &a);
        switch (a)
        {
            case 1:
                pthread_create(&pid_init, NULL, init, NULL);
                pthread_join(pid_init, &tret);
                printf("\n");
                break;
            case 2:
                ls(FILE_DIR);
                manFile();
                break;
            case 3:
                uploadFile();
                break;
            case 0:
                exit(0);
            default:
                printf("请输入正确的指令！\n");
                break;
        }
    }
    return 0;
}