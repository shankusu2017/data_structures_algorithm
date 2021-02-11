#include "property.h"

//函数被调用次数
static unsigned long call_times;
void addCalTimes(void)
{
    ++call_times;
}
unsigned long callTimes(void)
{
    return call_times;
}

//算法运行的最大深度
static unsigned call_depth;
void addCallDepth(unsigned depth)
{
    if (depth > call_depth) {
        call_depth = depth;
    }
}
unsigned callDepth(void)
{
    return call_depth;
}


//CPU比对的次数
static unsigned long cpuTimes;
void addCPUTimes(void)
{
    ++cpuTimes;
}
unsigned long CPUTimes(void)
{
    return cpuTimes;
}
