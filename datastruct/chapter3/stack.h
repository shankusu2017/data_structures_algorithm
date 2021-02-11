#ifndef STACK_H_20180811_0925
#define STACK_H_20180811_0925

#include "define.h"
#include "typedef.h"

struct StackRecord;
typedef struct StackRecord *Stack;

//创建堆栈
Stack CreateStack(int size);

//销毁堆栈
void DeleteStack(Stack hdl);

//堆栈是否为空
int IsEmpty(Stack hdl);

//堆栈是否满
int IsFull(Stack hdl);

//清空堆栈
void MakeEmpty(Stack hdl);

//入栈
void Push(Stack hdl, ElementType x);

//出栈
ElementType Pop(Stack hdl);

void StackDemon(void);

#endif  //STACK_H_20180811_0925
