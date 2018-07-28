// Subscription
// Amazon
// Google
/*
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

For example,
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
*/

typedef struct node {
    int item;
    struct node *next;
} Node;

typedef struct queue {
    Node * front;
    Node * rear;
    int size;
    int items;
} Queue;

void initializeQueue (Queue * pq, int size) {
    pq->front = NULL;
    pq->rear = NULL;
    pq->size = size;
    pq->items = 0;
}

bool queueIsFull (const Queue * pq) {
    return pq->items == pq->size;
}

bool queueIsEmpty (const Queue * pq) {
    return pq->items == 0;
}

int queueItemCount (const Queue * pq) {
    return pq->items;
}

bool enQueue (int item, Queue * pq) {
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

bool deQueue(int *pitem, Queue * pq) {
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

typedef struct {
    Queue *queue;
    int size;
    int total;
    double avr;
} MovingAverage;

/** Initialize your data structure here. */
MovingAverage* movingAverageCreate(int size) {
    MovingAverage *obj = (MovingAverage *) malloc (sizeof(MovingAverage));
    obj->queue = (Queue *) malloc (sizeof(Queue));
    initializeQueue(obj->queue, size);
    obj->size = size;
    obj->avr = 0;
    return obj;
}

double movingAverageNext(MovingAverage* obj, int val) {
    if (queueIsFull(obj->queue)) {
        int* temp = (int*) malloc (sizeof(int));
        deQueue(temp, obj->queue);
        obj->total -= *temp;
    }
    enQueue(val, obj->queue);
    obj->total += val;
    obj->avr = (double)(obj->total) / queueItemCount(obj->queue);
    return obj->avr;
}

void movingAverageFree(MovingAverage* obj) {
    free(obj->queue);
    free(obj);
}

/**
 * Your MovingAverage struct will be instantiated and called as such:
 * struct MovingAverage* obj = movingAverageCreate(size);
 * double param_1 = movingAverageNext(obj, val);
 * movingAverageFree(obj);
 */
