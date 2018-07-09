// Medium Collection
// Microsoft
/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5
as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.



Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/** Encodes a tree to a single string. */
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
    return pq->items == 65536;
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

int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int depth = 1;
    int leftMax = maxDepth(root->left);
    int rightMax = maxDepth(root->right);
    return depth + (leftMax > rightMax ? leftMax : rightMax);
}

char* serialize(struct TreeNode* root) {
    char* ret = (char*) malloc(sizeof(char) * 65536);
    ret[0] = '[';
    ret[1] = ']';
    ret[2] = '\0';
    if (root == NULL) {
        return ret;
    }
    Queue * queue = (Queue *) malloc(sizeof(Queue));
    initializeQueue(queue);
    enQueue(root, queue);
    int depth = maxDepth(root);
    int index = 0;
    int endIndex = 0;
    while (!queueIsEmpty(queue) && index < pow(2, depth) - 1) {
        int length = strlen(ret);
        ret[length - 1] = '\0';
        struct TreeNode * tree = (struct TreeNode *) malloc(sizeof(struct TreeNode));
        deQueue(&tree, queue);
        if (!tree) {
            strcat(ret, ",null]");
        } else {
            char* buffer = (char*) malloc (sizeof(char));
            if (index == 0) {
                sprintf(buffer, "%d", tree->val);
                strcat(ret, buffer);
                strcat(ret, "]");
            } else {
                strcat(ret, ",");
                sprintf(buffer, "%d", tree->val);
                strcat(ret, buffer);
                strcat(ret, "]");
            }
        }
        index++;
        if (tree) {
            endIndex = strlen(ret) - 1;
            enQueue(tree->left, queue);
            enQueue(tree->right, queue);
        }
    }
    ret[endIndex] = ']';
    ret[endIndex + 1] = '\0';
    return ret;
}

/** Decodes your encoded data to tree. */
struct TreeNode* nodeFromString(char* s) {
        if (strcmp(s, "null") == 0) {
            return NULL;
        } else {
            struct TreeNode* node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
            node->val = atoi(s);
            return node;
        }
}

struct TreeNode* deserialize(char* data) {
    char** separated = (char**) malloc(sizeof(char *) * 65536);
    long count = 0;
    char* separates = {"[, ]"};
    separated[count] = strtok(data, separates);
    if (separated[count] == NULL) {
        return NULL;
    }
    while (separated[count] != NULL) {
        count++;
        separated[count] = strtok(NULL, separates);
    }
    int index = 0;
    struct TreeNode* tree = nodeFromString(separated[index++]);
    Queue * queue = (Queue *) malloc(sizeof(Queue));
    initializeQueue(queue);
    if (tree) {
        enQueue(tree, queue);
    }
    struct TreeNode* current;
    while (!queueIsEmpty(queue)) {
        deQueue(&current, queue);

        if (index < count) {
            current->left = nodeFromString(separated[index++]);
        } else {
            current->left = NULL;
        }
        if (index < count) {
            current->right = nodeFromString(separated[index++]);
        } else {
            current->right = NULL;
        }

        if (current->left) {
            enQueue(current->left, queue);
        }
        if (current->right) {
            enQueue(current->right, queue);
        }
    }
    return tree;
}

// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);
