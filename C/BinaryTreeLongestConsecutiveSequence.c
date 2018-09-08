// Subscription
// 298. Binary Tree Longest Consecutive Sequence
/*
Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

Example 1:

Input:

   1
    \
     3
    / \
   2   4
        \
         5

Output: 3

Explanation: Longest consecutive sequence path is 3-4-5, so return 3.
Example 2:

Input:

   2
    \
     3
    /
   2
  /
 1

Output: 2

Explanation: Longest consecutive sequence path is 2-3, not 3-2-1, so return 2.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void dfs(struct TreeNode* root, int val, int out, int* res) {
    if (!root) {
        return;
    }
    if (root->val == val + 1) {
        out++;
    } else {
        out = 1;
    }
    *res = *res > out ? *res : out;
    dfs(root->left, root->val, out, res);
    dfs(root->right, root->val, out, res);
}
int longestConsecutive(struct TreeNode* root) {
    if (!root) {
        return 0;
    }
    int* res = (int*) malloc (sizeof(int));
    *res = 0;
    dfs(root, root->val, 0, res);
    int ret = *res;
    free(res);
    return ret;
}
