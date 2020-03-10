// Facebook
/*
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \
      4   5
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
*/
int depth(struct TreeNode* root, int *diameter) {
  if (!root) {
    return 0;
  }
  int left = depth(root->left, diameter);
  int right = depth(root->right, diameter);
  int current = left + right + 1;
  *diameter = (*diameter) > current ? (*diameter) : current;
  return (left > right ? left : right) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root){
  if (!root) {
    return 0;
  }
  int *diameter = (int *)malloc(sizeof(int));
  *diameter = 1;
  depth(root, diameter);
  int ret = *diameter - 1;
  return ret;
}