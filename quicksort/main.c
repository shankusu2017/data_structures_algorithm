#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "quick_sort.h"
#include "quick_sort_verify.h"

static int arrayData[1024*1024];

int main(int argc, char *argv[])
{
    printf("Hello World!\n");
    //int tmp[8];
    unsigned i = 0;
    srand(time(NULL));
    for(i = 0; i < arrayLen(arrayData); ++i) {
        arrayData[i] = rand();
    }
    quick_sort(arrayData, arrayData + arrayLen(arrayData) - 1, 0);
    printf("quick sort done, fun_times:%ld, depath:%d, cpuTimes:%ld\n", callTimes(), callDepth(), CPUTimes());
    int ret = check(arrayData, arrayData + arrayLen(arrayData) - 1);
    printf("check ret:%d\n", ret);
    return 0;
}

