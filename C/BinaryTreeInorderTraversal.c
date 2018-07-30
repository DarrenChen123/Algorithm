// Medium Collection
// Microsoft
// Queue & Stack
/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

 // Recursive
void inorder(struct TreeNode* root, int* returnSize, int* arr) {
    if (!root) {
        return;
    }
    inorder(root->left, returnSize, arr);
    arr[(*returnSize)++] = root->val;
    inorder(root->right, returnSize, arr);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ret = (int*) malloc (sizeof(int) * 1024);
    *returnSize = 0;
    inorder(root, returnSize, ret);
    return ret;
}

// Iterative
typedef struct stack {
    struct TreeNode **items;
    int maxSize;
    int top;
} Stack;

void initializeStack (Stack * ps, int maxSize) {
    struct TreeNode **items = (struct TreeNode **) malloc (sizeof(struct TreeNode*) * maxSize);
    ps->top = 0;
    ps->maxSize = maxSize;
    ps->items = items;
}

int fullStack (const Stack * ps) {
    return ps->top == ps->maxSize;
}

int emptyStack (const Stack * ps) {
    return ps->top == 0;
}

int push (struct TreeNode * item, Stack * ps) {
    if (ps->top == ps->maxSize) {
        return 0;
    } else {
        ps->items[ps->top++] = item;
        return 1;
    }
}

struct TreeNode * pop(Stack * ps) {
    if (ps->top == 0) {
        return NULL;
    } else {
        ps->top--;
        return ps->items[ps->top];
    }
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ret = (int*) malloc (sizeof(int) * 1024);
    *returnSize = 0;
    Stack* stack = (Stack *) malloc (sizeof(Stack));
    initializeStack(stack, 1024);
    struct TreeNode* node = root;
    while (node != NULL || !emptyStack(stack)) {
        while (node != NULL) {
            push (node, stack);
            node = node->left;
        }
        if (!emptyStack(stack)) {
            node = pop(stack);
            ret[(*returnSize)++] = node->val;
            node = node->right;
        }
    }
    return ret;
}
