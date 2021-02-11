/*
 * 2叉查找树
 */

#include <stdio.h>

#ifndef LEAF2_H_20180821_1954
#define LEAF2_H_20180821_1954

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
typedef int Element;

#ifndef NULL
#define NULL 0
#endif

SearchTree MakeEmpty(SearchTree T);

Position Find(Element x, SearchTree T);

Position FindMax(SearchTree T);

Position FindMin(SearchTree T);

SearchTree Insert(Element e, SearchTree T);

SearchTree Delete(Element e, SearchTree T);

Element Retrieve(Position p);


typedef struct
{
    Element           element;
    SearchTree      left;
    SearchTree      right;
}TreeNode;

SearchTree MakeEmpty(SearchTree T)
{
    if (T) {
        MakeEmpty(T->left);
        MakeEmpty(T->right);
        free(T);
    }

    return NULL;
}

Position Find(Element x, SearchTree T)
{
    if (!T) return NULL;

    if (x < T->element)   {
        Find(x, T->left);
    } else if (x > T->element) {
        Find(x, T->right);
    } else {
        return T;
    }
}

Position FindMax(SearchTree T)
{
    if (NULL == T) return NULL;

    if (T->right) {
        FindMax(T->right);
    } else {
        return T;
    }
}

Position FindMin(SearchTree T)
{
    if (NULL == T) return NULL;

    while(T->left) {
        T = T->left;
    }

    return T;
}

//插入树中s
SearchTree Insert(Element e, SearchTree T)
{
    if (NULL == T) {
        T = (SearchTree)malloc(sizeof(TreeNode));
        if (NULL == T) {
            return NULL;
        } else {
            T->element = e;
            T->left = T->right = NULL;
        }
    } else if (e < T->element) {
        T->left =  Insert(e, T->left);
    } else if (e > T->element) {
        T->right =  Insert(e, T->right);
    }

    return T;
}






#endif  /* LEAF2_H_20180821_1954 */

