/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


// Recursive
bool isMirror(struct TreeNode * tree1, struct TreeNode * tree2) {
    if (tree1 == NULL && tree2 == NULL) {
        return true;
    }
    if (tree1 == NULL || tree2 == NULL) {
        return false;
    }
    return (tree1->val == tree2->val) && isMirror(tree1->right, tree2->left) && isMirror(tree1->left, tree2->right);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    if (root->left == NULL && root->right == NULL) {
        return true;
    }
    return isMirror(root, root);
}

// Iterative
typedef struct node {
    struct TreeNode *item;
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

bool enQueue (struct TreeNode * item, Queue * pq) {
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

bool deQueue(struct TreeNode ** pitem, Queue * pq) {
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

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    if (root->left == NULL && root->right == NULL) {
        return true;
    }
    Queue * queue = (Queue *) malloc (sizeof(Queue));
    initializeQueue(queue);
    enQueue(root, queue);
    enQueue(root, queue);
    while (!queueIsEmpty(queue)) {
        struct TreeNode * tree1 = (struct TreeNode *) malloc (sizeof(struct TreeNode));
        struct TreeNode * tree2 = (struct TreeNode *) malloc (sizeof(struct TreeNode));
        deQueue(&tree1, queue);
        deQueue(&tree2, queue);
        if (tree1 == NULL && tree2 == NULL) {
            continue;
        }
        if (tree1 == NULL || tree2 == NULL) {
            return false;
        }
        if (tree1->val != tree2->val) {
            return false;
        }
        enQueue(tree1->left, queue);
        enQueue(tree2->right, queue);
        enQueue(tree1->right, queue);
        enQueue(tree2->left, queue);
    }
    return true;
}
