// Medium Collection
// Microsoft
// Facebook
/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* build(int* preorder, int preorderBegin, int preorderEnd, int* inorder, int inorderBegin, int inorderEnd, int* preorderKeys, int* inorderKeys) {
    if (preorderBegin > preorderEnd || inorderBegin > inorderEnd) {
        return NULL;
    }
    struct TreeNode* root = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    root->val = preorder[preorderBegin];
    int index;
    if (preorder[preorderBegin] >= 0) {
        index = inorderKeys[preorder[preorderBegin]];
    } else {
        index = inorderKeys[10000 + preorder[preorderBegin]];
    }
    root->left = build(preorder, preorderBegin + 1, index - inorderBegin + preorderBegin, inorder, inorderBegin, index - 1, preorderKeys, inorderKeys);
    root->right = build(preorder, preorderBegin + index - inorderBegin + 1, preorderEnd, inorder, index + 1, inorderEnd, preorderKeys, inorderKeys);
    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if (preorderSize == 0 || inorderSize == 0 || preorderSize != inorderSize) {
        return NULL;
    }
    int* preorderKeys = (int *) malloc (sizeof(int) * 10000);
    memset(preorderKeys, -1, sizeof(int) * 10000);
    int* inorderKeys = (int *) malloc (sizeof(int) * 10000);
    memset(inorderKeys, -1, sizeof(int) * 10000);
    for (int i = 0; i < preorderSize; i++) {
        if (preorder[i] >= 0) {
            preorderKeys[preorder[i]] = i;
        } else {
            preorderKeys[preorder[i] + 10000] = i;
        }
        if (inorder[i] >= 0) {
            inorderKeys[inorder[i]] = i;
        } else {
            inorderKeys[inorder[i] + 10000] = i;
        }
    }
    return build(preorder, 0, preorderSize - 1, inorder, 0, inorderSize - 1, preorderKeys, inorderKeys);
}
