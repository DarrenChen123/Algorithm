/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


// Recursive
bool isMirror(struct TreeNode * tree1, struct TreeNode * tree2) {
    if (tree1 == NULL && tree2 == NULL) {
        return true;
    }
    if (tree1 == NULL || tree2 == NULL) {
        return false;
    }
    return (tree1->val == tree2->val) && isMirror(tree1->right, tree2->left) && isMirror(tree1->left, tree2->right);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    if (root->left == NULL && root->right == NULL) {
        return true;
    }
    return isMirror(root, root);
}
