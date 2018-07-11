// Subscription
// Yelp
/*
Given a binary tree, count the number of uni-value subtrees.

A Uni-value subtree means all nodes of the subtree have the same value.

Example :

Input:  root = [5,1,5,5,5,null,5]

              5
             / \
            1   5
           / \   \
          5   5   5

Output: 4
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isUnivalue(struct TreeNode* root, int* count) {
    if (!root) {
        return false;
    }
    if (!root->left && !root->right) {
        (*count)++;
        return true;
    }
    if (!root->left && root->right) {
        if (isUnivalue(root->right, count) && root->val == root->right->val) {
            (*count)++;
            return true;
        } else {
            return false;
        }
    }
    if (root->left && !root->right) {
        if (isUnivalue(root->left, count) && root->val == root->left->val) {
            (*count)++;
            return true;
        } else {
            return false;
        }
    }
    if (root->left && root->right) {
        int isLeftUni = isUnivalue(root->left, count);
        int isRightUni = isUnivalue(root->right, count);
        if (isLeftUni && isRightUni && root->left->val == root->val && root->right->val == root->val) {
            (*count)++;
            return true;
        } else {
            return false;
        }
    }
    return false;
}

int countUnivalSubtrees(struct TreeNode* root) {
    if (!root) {
        return 0;
    }
    int* count = (int*) malloc (sizeof(int));
    *count = 0;
    isUnivalue(root, count);
    int ret = *count;
    free(count);
    return ret;
}
