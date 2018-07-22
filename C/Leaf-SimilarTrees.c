// Weekly Contest 94
/*
Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.



For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.



Note:

Both of the given trees will have between 1 and 100 nodes.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void inorder(struct TreeNode* root, int* leavesArr, int* leavesArrSize) {
    if (!root) {
        return;
    }
    inorder(root->left, leavesArr, leavesArrSize);
    if (!root->left && !root->right) {
        leavesArr[(*leavesArrSize)++] = root->val;
    }
    inorder(root->right, leavesArr, leavesArrSize);
}

bool isSimilar(int* leaves1, int leavesSize1, int* leaves2, int leavesSize2) {
    if (leavesSize1 != leavesSize2) {
        return false;
    }
    for (int i = 0; i < leavesSize1; i++) {
        if (leaves1[i] != leaves2[i]) {
            return false;
        }
    }
    return true;
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    int* leaves1 = (int*) malloc (sizeof(int) * 100);
    int* leaves2 = (int*) malloc (sizeof(int) * 100);
    int* leavesArrSize1 = (int*) malloc (sizeof(int));
    int* leavesArrSize2 = (int*) malloc (sizeof(int));
    *leavesArrSize1 = 0;
    *leavesArrSize2 = 0;
    inorder(root1, leaves1, leavesArrSize1);
    inorder(root2, leaves2, leavesArrSize2);
    bool ret = isSimilar(leaves1, *leavesArrSize1, leaves2, *leavesArrSize2);
    free(leavesArrSize2);
    free(leavesArrSize1);
    free(leaves2);
    free(leaves1);
    return ret;
}
