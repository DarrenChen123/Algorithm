// Subscription
// Amazon
/*
Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Examples 1:

Input: [3,9,20,null,null,15,7]

   3
  /\
 /  \
 9  20
    /\
   /  \
  15   7

Output:

[
  [9],
  [3,15],
  [20],
  [7]
]
Examples 2:

Input: [3,9,8,4,0,1,7]

     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7

Output:

[
  [4],
  [9],
  [3,0,1],
  [8],
  [7]
]
Examples 3:

Input: [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5)

     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
    /\
   /  \
   5   2

Output:

[
  [4],
  [9,5],
  [3,0,1],
  [8,2],
  [7]
]
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
typedef struct doubleList {
    int* val;
    int count;
    struct doubleList *left;
    struct doubleList *right;
} DoubleList;

typedef struct tuple {
    struct TreeNode* first;
    DoubleList* second;
} Tuple;

typedef struct node {
    Tuple *item;
    struct node *next;
} Node;

typedef struct queue {
    Node * front;
    Node * rear;
    int items;
} Queue;

void initializeQueue (Queue * pq) {
    pq->front = NULL;
    pq->rear = NULL;
    pq->items = 0;
}

bool queueIsFull (const Queue * pq) {
    return pq->items == 1024;
}

bool queueIsEmpty (const Queue * pq) {
    return pq->items == 0;
}

int queueItemCount (const Queue * pq) {
    return pq->items;
}

bool enQueue (Tuple * item, Queue * pq) {
    Node * pnew;

    if (queueIsFull(pq)) {
        return false;
    }
    pnew = (Node *) malloc (sizeof(Node));
    if (pnew == NULL) {
        exit(1);
    }
    pnew->item = item;
    pnew->next = NULL;
    if (queueIsEmpty(pq)) {
        pq->front = pnew;
    } else {
        pq->rear->next = pnew;
    }
    pq->rear = pnew;
    pq->items++;
    return true;
}

bool deQueue(Tuple ** pitem, Queue * pq) {
    Node * pt;
    if (queueIsEmpty(pq)) {
        return false;
    }
    *pitem = pq->front->item;
    pq->front = pq->front->next;
    free(pt);
    pq->items--;
    if (pq->items == 0) {
        pq->rear =  NULL;
    }
    return true;
}

int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int depth = 1;
    int leftMax = maxDepth(root->left);
    int rightMax = maxDepth(root->right);
    return depth + (leftMax > rightMax ? leftMax : rightMax);
}
int** verticalOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    if(!root) {
        return NULL;
    }
    int depth = maxDepth(root);
    int maxLeafCount = 2 * depth - 1;
    int** ret = (int**) malloc (sizeof(int*) * maxLeafCount);
    *columnSizes = (int*) malloc (sizeof(int) * maxLeafCount);
    memset(ret, 0, sizeof(int*) * maxLeafCount);
    DoubleList *mid = (DoubleList *) malloc (sizeof(DoubleList));
    mid->val = (int*) malloc (sizeof(int*) * maxLeafCount);
    mid->count = 0;
    mid->left = NULL;
    mid->right = NULL;
    Queue * queue = (Queue *) malloc (sizeof(Queue));
    initializeQueue(queue);
    Tuple* tuple = (Tuple *) malloc (sizeof(Tuple));
    tuple->first = root;
    tuple->second = mid;
    enQueue(tuple, queue);
    DoubleList *leftBound = mid;
    while (!queueIsEmpty (queue)) {
        Tuple** node = (Tuple**) malloc (sizeof(Tuple*));
        deQueue(node, queue);
        (*node)->second->val[((*node)->second->count)++] = (*node)->first->val;
        if ((*node)->first->left) {
            if (!(*node)->second->left) {
                (*node)->second->left = (DoubleList *) malloc (sizeof(DoubleList));
                (*node)->second->left->val = (int*) malloc (sizeof(int*) * maxLeafCount);
                (*node)->second->left->count = 0;
                (*node)->second->left->right =  (*node)->second;
                (*node)->second->left->left = NULL;
                leftBound = (*node)->second->left;
            }
            Tuple* tuple = (Tuple *) malloc (sizeof(Tuple));
            tuple->first = (*node)->first->left;
            tuple->second = (*node)->second->left;
            enQueue(tuple, queue);
        }
        if ((*node)->first->right) {
            if (!(*node)->second->right) {
                (*node)->second->right = (DoubleList *) malloc (sizeof(DoubleList));
                (*node)->second->right->val = (int*) malloc (sizeof(int*) * maxLeafCount);
                (*node)->second->right->count = 0;
                (*node)->second->right->left =  (*node)->second;
                (*node)->second->right->right = NULL;
            }
            Tuple* tuple = (Tuple *) malloc (sizeof(Tuple));
            tuple->first = (*node)->first->right;
            tuple->second = (*node)->second->right;
            enQueue(tuple, queue);
        }
    }
    *returnSize = 0;
    while (leftBound) {
        ret[*returnSize] = leftBound->val;
        (*columnSizes)[*returnSize] = leftBound->count;
        (*returnSize)++;
        leftBound = leftBound->right;
    }
    free(mid);
    free(queue);
    return ret;
}
