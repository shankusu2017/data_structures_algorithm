#ifndef PROPERTY_H
#define PROPERTY_H

//函数被调用的次数
unsigned long callTimes(void);
//上述调用的最大调用深度
unsigned callDepth(void);
//CPU"对比"次数
unsigned long CPUTimes(void);

//尝试更新调用深度，增加函数调用次数和CPU对比次数
void addCallDepth(unsigned depth);
void addCalTimes(void);
void addCPUTimes(void);


#endif // PROPERTY_H
