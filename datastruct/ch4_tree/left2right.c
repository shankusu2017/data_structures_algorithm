//先序遍历

typedef struct tagNode {
    int value;
    struct tagNode *left, *right;
}Node;

void PreNode(const Node *root)
{
    printf("%d\n", root->value);
    if (root->left)
        PreNode(root->left);
    if (root->right)
        PreNode(root->right);
}
