// Subscription
// 272. Closest Binary Search Tree Value II
/*
Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.

Note:

Given target value is a floating point.
You may assume k is always valid, that is: k ≤ total nodes.
You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
Example:

Input: root = [4,2,5,1,3], target = 3.714286, and k = 2

    4
   / \
  2   5
 / \
1   3

Output: [4,3]
Follow up:
Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?
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
void inorder(struct TreeNode* root, double target, int k, int* res, int* begin, int* end) {
    if (!root) {
        return;
    }
    inorder(root->left, target, k, res, begin, end);
    if (*end - *begin + 1 < k) {
        res[++(*end)] = root->val;
    } else if (fabs(root->val - target) < fabs(res[*begin] - target)) {
        (*begin)++;
        res[++(*end)] = root->val;
    } else {
        return;
    }
    inorder(root->right, target, k, res, begin, end);
}
int* closestKValues(struct TreeNode* root, double target, int k, int* returnSize) {
    int* res = (int*) malloc (sizeof(int) * 50000);
    int* begin = (int*) malloc (sizeof(int));
    int* end = (int*) malloc (sizeof(int));
    *begin = 0;
    *end = -1;
    inorder(root, target, k, res, begin, end);
    *returnSize = *end - *begin + 1;
    int* ret = (int*) malloc (sizeof(int) * *returnSize);
    memcpy(ret, res + *begin, sizeof(int) * *returnSize);
    free(end);
    free(begin);
    free(res);
    return ret;
}
