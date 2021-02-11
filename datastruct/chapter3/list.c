#include "stdlib.h"
#include "list.h"

/*
 * 本链表的实现采用哑结点的结构，实际应用中这样也有好处，
 * list.manager-在生成一个链表时，首先生成一个哑结点(链表头),
 * 同时将对应的地址转换成handler返回给调用者，后者对该List的所用的操作都以handler为标识符
 */

struct Node {
    ElementType element;
    Position         next;
    char               load[CNT_M];
};

//创建一个链表
List CreateList(void)
{
    List header = calloc(1, sizeof(struct Node));
    if (!header) return header;

    // TODO Initialization
    header->next = NULL;
    header->element = -1;

    return header;
}

//清空一个列表的数据(句柄保留)
void MakeEmpty(List hdl)
{
    //检查合法性
    if (!hdl) return;

    List tmp = NULL;
    //删除所有的尾巴
    while ((tmp = hdl->next)) {
        hdl->next = tmp->next;   //指到新的node
        free(tmp);                      //删除一个node
    }

    //free(hdl); 保留头部
}

//删除一个链表,传过来的是hdl
//这里清空数据和表头
void DeleteList(List hdl)
{
    //检查合法性
    if (!hdl) return;

    MakeEmpty(hdl);

    //删除头部
    free(hdl);
}

//是否为空,这里L是表头
int IsEmpty(List hdl)
{
    return ((hdl->next == NULL) ? 1 : 0);
}

//是否为最后一个元素
int IsLast(List hdl, Position pos)
{
    return (NULL == pos->next);
}

//将元素X插入到链表L中
Position Insert(List hdl, ElementType X)
{
    Position element = malloc(sizeof(struct Node));
    if (!element) return NULL;

    //插到队列头部即可，无需循环一遍插到最后(浪费CPU)
    element->element = X;
    element->next = hdl->next;
    hdl->next = element;

    return element;
}

//找出元素x在链表hdl中的位置
Position Find(List hdl, ElementType X)
{
    Position node = hdl;
    while ((node = node->next)) {
        if (X == node->element) return node;
    }

    //没找到就返回NULL
    return NULL;
}

// TODO 实现代码
//Returns:1:找到并删除了X,0:没有找到X
int Delete(List hdl, ElementType X)
{
    PtrToNode node = hdl;
    PtrToNode pre = hdl;
    while ((node = node->next)) {
        if (node->element == X) {   //找到该元素
            pre->next = node->next; //更新链表
            free(node); //释放节点
            node = NULL;
            return 1;
        } else {
            pre = node;
        }
    }

    return 0;
}


//找出元素X的前一个Node，第一个结算NULL
Position FindPrevious(List hdl, ElementType X)
{
    if (!hdl->next) return NULL;

    //头节点"不参与"
    if (hdl->next->element == X) return NULL;

    PtrToNode pre = hdl->next;
    PtrToNode node = NULL;

    while ((node = pre->next)) {
            if (node->element == X) return pre;
            pre = pre->next;
    }

    return NULL;
}

//打印List的所有元素
void PrintList(List hdl)
{
    Position node = hdl;
    while ((node = node->next)) {
        //printf("%d\n", node->element);
    }
}

//demonstrate
void ListDemon(void)
{
    List hdl = CreateList();
    if (!hdl) exit(1);

    //printf("list is null:%d\n", IsEmpty(hdl));

    ElementType x = 0;
    //printf("element.o.pos:%p\n", Find(hdl, x));
    // printf("element.o.pos:%p\n", Find(hdl, x));

    Insert(hdl, x);

    //插入0-99
    int i = 0;
    for(i = 1; i < 100; ++i) {
        ElementType x = i;
        Insert(hdl, x);
    }
    //printf("=1====================\n");
    PrintList(hdl);

    //删除奇数
    for(i = 1; i <100; i+=2) {
        ElementType x = i;
        Delete(hdl, x);
    }
    //printf("=2====================\n");
    PrintList(hdl);

    //清空队列
    MakeEmpty(hdl);
    //printf("=3====================\n");
    PrintList(hdl);

    //摧毁队列
    DeleteList(hdl);

    // printf("=4====================\n");
    // PrintList(hdl);
}


void ListDemon2(void)
{
    while (1) {
        List hdl = CreateList();
        if (!hdl) exit(1);

        //插入0-max
        int i = 0;
        int max = 0xffff;
        for(i = 0; i < max; ++i) {
            ElementType x = i;
            Insert(hdl, x);
        }

        PrintList(hdl);

        //删除[0,max+0xff]
        for(i = 0; i <max + 0xff; ++i) {
            ElementType x = i;
            Delete(hdl, x);
        }

        //摧毁队列
        DeleteList(hdl);
    }
}

struct Node2 {
    Position2       pre;
    Position2      next;
    ElementType element;
    char               load[CNT_K];
};

//创建一个链表
HdlLst2 CreateList2(void)
{
    PtrToNode2 p = (struct Node2*)calloc(1, sizeof(struct Node2));
    if (!p) return NULL;

   p->element = -1;
   p->pre = p->next = NULL;
   return p;
}

//删除链表L
void DeleteList2(HdlLst2 hdl)
{
    //删除body
    MakeEmpty2(hdl);

    //删除hdl
    free(hdl);
}


//删除链表L的Body
void MakeEmpty2(HdlLst2 hdl)
{
    //删除子节点
    PtrToNode2 node;
    while ((node = hdl->next)) {
        hdl->next = node->next;
        if (node->next) node->next->pre = hdl;
        free(node);
    }
}

//是否为空
int IsEmpty2(HdlLst2 hdl)
{
    return ((hdl->next == NULL) ? 1 : 0);
}

//是否为最后一个
int IsLast2(HdlLst2 hdl, Position2 pos)
{
    return ((pos->next == NULL) ? 1 : 0);
}

//将元素X插入到链表hdl中
Position2 Insert2(HdlLst2 hdl, ElementType X)
{
    PtrToNode2 node = (PtrToNode2*)malloc(sizeof(struct Node2));
    if (!node) return NULL;

    node->next = hdl->next;
    hdl->next = node;

    if (node->next) {
        node->next->pre = node;
    }
    node->pre = hdl;
}

void List2Demon2(void)
{
    HdlLst2 hdl= CreateList2();
    if (!hdl) return;

    int i = 0;
    for(i = 0; i < 0xffff; ++i) {
        ElementType x = 0;
        Insert2(hdl, x);
    }
    //MakeEmpty2(hdl);

    DeleteList2(hdl);
}


