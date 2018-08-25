// Subscription
// 255. Verify Preorder Sequence in Binary Search Tree
/*
Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.

You may assume each number in the sequence is unique.

Consider the following binary search tree:

     5
    / \
   2   6
  / \
 1   3
Example 1:

Input: [5,2,6,1,3]
Output: false
Example 2:

Input: [5,2,1,3,6]
Output: true
Follow up:
Could you do it using only constant space complexity?
*/

bool verifyPreorder(int* preorder, int preorderSize) {
    int low = INT_MIN;
    int j = -1;
    for (int i = 0; i < preorderSize; i++) {
        if (preorder[i] < low) {
            return false;
        }
        while (j >= 0 && preorder[i] > preorder[j]) {
            low = preorder[j--];
        }
        preorder[++j] = preorder[i];
    }
    return true;
}
