#ifndef _LIST_H_20180809_2055
#define _LIST_H_20180809_2055

#include "typedef.h"
#include "define.h"

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

//传递给调用者当做handler类型来用，避免调用者申明一种新的数据类型
typedef List HdlLst;

//创建一个链表
List CreateList(void);

//删除链表L
void DeleteList(List hdl);

//清空链表，保留header
void MakeEmpty(List hdl);

//是否为空
int IsEmpty(List hdl);

//是否为最后一个
int IsLast(List hdl, Position pos);

//将元素X插入到链表L中
Position Insert(List hdl, ElementType X);

//找出元素x在链表L中的位置
Position Find(List hdl, ElementType X);

//删除链表L中第一个元素为X的值
int Delete(List hdl, ElementType X);

//找出链表L中第一个元素为X的前一个节点
Position FindPrevious(List hdl, ElementType X);

//返回链表的头
Position Header(List hdl);

//返回链表的首元素
Position First(List hdl);

Position Advance(Position P);

ElementType Retrieve(Position p);

//打印List的所有元素
void PrintList(List hdl);

void ListDemon(void);
void ListDemon2(void);


/****************双向链表************************/
struct Node2;
typedef struct Node2 *PtrToNode2;
typedef PtrToNode2 Position2;
typedef PtrToNode2 HdlLst2;

//传递给调用者当做handler类型来用，避免调用者申明一种新的数据类型

//创建一个链表
HdlLst2 CreateList2(void);

//删除链表L
void DeleteList2(HdlLst2 hdl);

//清空链表，保留header
void MakeEmpty2(HdlLst2 hdl);

//是否为空
int IsEmpty2(HdlLst2 hdl);

//是否为最后一个
int IsLast2(HdlLst2 hdl, Position2 pos);

//将元素X插入到链表hdl中
Position2 Insert2(HdlLst2 hdl, ElementType X);

//找出元素x在链表L中的位置
Position2 Find2(HdlLst2 hdl, ElementType X);

//删除链表L中第一个元素为X的值
int Delete2(HdlLst2 hdl, ElementType X);

//找出链表L中第一个元素为X的前一个节点
Position2 FindPrevious2(HdlLst2 hdl, ElementType X);

//返回链表的头
Position2 Heade2(HdlLst2 hdl);

//返回链表的首元素
Position2 First2(HdlLst2 hdl);

//打印List的所有元素
void PrintList2(HdlLst2 hdl);

void List2Demon(void);
void List2Demon2(void);


#endif  /* _LIST_H_20180809_2055 */

