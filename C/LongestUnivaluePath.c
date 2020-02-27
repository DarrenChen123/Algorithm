// Google
/*
Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

Note: The length of path between two nodes is represented by the number of edges between them.

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output:

2
Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output:

2
Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int arrowLength(struct TreeNode* node, int *ans) {
  if (!node) {
   return 0;
  }
  int left = arrowLength(node->left, ans);
  int right = arrowLength(node->right, ans);
  int arrowLeft = 0;
  int arrowRight = 0;
  if (node->left && node->left->val == node->val) {
    arrowLeft += left + 1;
  }
  if (node->right && node->right->val == node->val) {
    arrowRight += right + 1;
  }
  *ans = (*ans) > (arrowLeft + arrowRight) ? (*ans) : (arrowLeft + arrowRight);
  return arrowLeft > arrowRight ? arrowLeft : arrowRight;
}

int longestUnivaluePath(struct TreeNode* root){
  int *ans = (int *)malloc(sizeof(int));
  *ans = 0;
  arrowLength(root, ans);
  int ret = *ans;
  free(ans);
  return ret;
}