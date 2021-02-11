#include "stack.h"

#define STACK_SIZE_MIN 5

struct StackRecord
{
    int     capacity;                  //容量
    int     top;                         //栈顶指针
    ElementType *data;          //保存数据用的数组
};

Stack CreateStack(int size)
{
    Stack hdl = (Stack)malloc(sizeof(struct StackRecord));
    if (!hdl) return NULL;

    hdl->data = (ElementType *)calloc(size, sizeof(ElementType));
    if (!hdl->data) {
        free(hdl);
        return NULL;
    }

    hdl->capacity = size;
    hdl->top = 0;
    return hdl;
}

void DeleteStack(Stack hdl)
{
    free(hdl->data);
    free(hdl);
}


void StackDemon(void)
{
    int i = 0;
    for(i = 0; i < 1 <<20; ++i) {
        Stack hdl = CreateStack(1<<10);
        DeleteStack(hdl);
    }
}
