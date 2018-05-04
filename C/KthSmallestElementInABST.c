/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
*/

void inorder(struct TreeNode* root, int* pk, int* pret, int* flag) {
    if (!root || *flag) {
        return;
    }
    if (root->left) {
        inorder(root->left, pk, pret, flag);
    }
    if (--(*pk) == 0) {
        *pret = root->val;
        *flag = 1;
        return;
    }
    if (root->right) {
        inorder(root->right, pk, pret, flag);
    }
}

int kthSmallest(struct TreeNode* root, int k) {
    if (!root) {
        return -INT_MAX;
    }
    int* pret = (int* )malloc(sizeof(int));
    int* flag = (int* )malloc(sizeof(int));
    *flag = 0;
    inorder(root, &k, pret, flag);
    free(flag);
    int ret = *pret;
    free(pret);
    return ret;
}
