typedef struct TreeNode *PtrNode;
typedef struct PtrNode Tree;

typedef int ElementType;

struct TreeNode
{
    ElementType element;
    Tree left;
    Tree right;
};

//2叉数搜索算法
static PtrNode find(Tree tree, int x)
{
    if (!tree)
        return NULL;

    if (x  < tree->element)
        find(tree->left, x);
    else if (x > tree->element)
        find(tree->right, x);
    else
        return tree;
}
