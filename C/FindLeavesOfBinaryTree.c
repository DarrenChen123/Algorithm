// Subscription
// LinkedIn
/*
Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.

Example:
Given binary tree
          1
         / \
        2   3
       / \
      4   5
Returns [4, 5, 3], [2], [1].

Explanation:
1. Removing the leaves [4, 5, 3] would result in this tree:

          1
         /
        2
2. Now removing the leaf [2] would result in this tree:

          1
3. Now removing the leaf [1] would result in the empty tree:

          []
Returns [4, 5, 3], [2], [1].
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

 int row = 0;
int count = 0;
struct TreeNode* recurse(struct TreeNode* root, int** result)
{
    if(!root)
    return NULL;

    struct TreeNode* left = recurse(root->left,result);
    struct TreeNode* right = recurse(root->right,result);

    if(!root->right && !root->left)
    {
       if(result[row])
          result[row] = realloc(result[row], (count+1)*sizeof(int));
       else
          result[row] = malloc((count+1)*sizeof(int));
       result[row][count] = root->val;
       count++;
       return root;
}

if(right||left)
{
   root->left = root->left==right?NULL:root->left;
   root->right = root->right==right?NULL:root->right;
   root->left = root->left==left?NULL:root->left;
   root->right=root->right==left?NULL:root->right;
}

return NULL;
}

int** findLeaves(struct TreeNode* root, int** columnSizes, int* returnSize) {
    int** result = malloc(100*sizeof(int*));
    result[0]=NULL;
    *columnSizes = malloc(sizeof(int));
    struct TreeNode* dummy = malloc(sizeof(struct TreeNode));

    dummy->right = root;
    dummy->left = NULL;
    while(dummy->right)
    {
        recurse(dummy,result);
        *columnSizes = realloc(*columnSizes,(row+1)*sizeof(int));
        columnSizes[0][row++]=count;
        result[row]=NULL;
        count = 0;

    }

    *returnSize = row;
    row = 0;
    count = 0;
    return result;
}
