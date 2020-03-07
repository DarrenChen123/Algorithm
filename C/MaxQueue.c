/*
请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。

若队列为空，pop_front 和 max_value 需要返回 -1

示例 1：

输入: 
["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
[[],[1],[2],[],[],[]]
输出: [null,null,null,2,1,2]
示例 2：

输入: 
["MaxQueue","pop_front","max_value"]
[[],[],[]]
输出: [null,-1,-1]
 

限制：

1 <= push_back,pop_front,max_value的总操作数 <= 10000
1 <= value <= 10^5
*/

//typedef struct queue {
//	int front;
//	int rear;
//	int items;
//	int maxSize;
//	int *arr;
//} Queue;
//
//void initializeQueue (Queue * pq, int maxSize) {
//	pq->front = 0;
//	pq->rear = 0;
//	pq->items = 0;
//	pq->maxSize = maxSize;
//	pq->arr = (int *)malloc(sizeof(int) * maxSize);
//	memset(pq->arr, 0, sizeof(int) * maxSize);
//}
//
//bool queueIsFull (const Queue * pq) {
//	if ((pq->rear + 1) % (pq->maxSize) == pq->front) {
//		return true;
//	} else {
//		return false;
//	}
//}
//
//bool queueIsEmpty (const Queue * pq) {
//	return pq->items == 0;
//}
//
//int queueItemCount (const Queue * pq) {
//	return pq->items;
//}
//
//bool enQueue (int item, Queue * pq) {
//	if (queueIsFull(pq)) {
//		return false;
//	} else {
//		pq->arr[pq->rear] = item;
//		pq->rear = (pq->rear + 1) % 10;
//		pq->items++;
//		return true; 
//	}
//}
//
//bool deQueue(int* pitem, Queue * pq) {
//	if (queueIsEmpty(pq)) {
//		return false;
//	}
//	*pitem = pq->arr[pq->front];
//	pq->front = (pq->front + 1) % (pq->maxSize);
//	pq->items--;
//	return true;
//}
//
//typedef struct stack {
//	int *items;
//	int maxSize;
//	int top;
//} Stack;
//
//void initializeStack (Stack * ps, int maxSize) {
//	int *items = (int *) malloc (sizeof(int) * maxSize);
//	memset(items, 0, sizeof(int) * maxSize);
//	ps->top = 0;
//	ps->maxSize = maxSize;
//	ps->items = items;
//}
//
//bool fullStack (const Stack * ps) {
//	return ps->top == ps->maxSize;
//}
//
//bool emptyStack (const Stack * ps) {
//	return ps->top == 0;
//}
//
//bool push (int item, Stack * ps) {
//	if (ps->top == ps->maxSize) {
//		return false;
//	} else {
//		ps->items[ps->top++] = item;
//		return true;
//	}
//}
//
//bool pop (int * pitem, Stack * ps) {
//	if (ps->top == 0) {
//		return false;
//	} else {
//		ps->top--;
//		*pitem = ps->items[ps->top];
//		return true;
//	}
//}
//
//int peek (const Stack * ps) {
//	if (ps->top > 0) {
//		return ps->items[ps->top - 1];
//	} else {
//		return INT_MIN;
//	}
//}
//
///** initialize your data structure here. */
//typedef struct {
//	Queue *queue;
//	Stack *maxIndexStack;
//} MaxQueue;
//
//
//MaxQueue* maxQueueCreate() {
//	MaxQueue *maxQueue = (MaxQueue *) malloc (sizeof(MaxQueue));
//	Queue *queue = (Queue *) malloc (sizeof(Queue));
//	initializeQueue(queue, 1024);
//	Stack *maxIndexStack = (Stack *) malloc (sizeof(Stack));
//	initializeStack(maxIndexStack, 1024);
//	maxQueue->queue = queue;
//	maxQueue->maxIndexStack = maxIndexStack;
//	return maxQueue;
//}
//
//int maxQueueMax_value(MaxQueue* obj) {
//	if (peek(obj->maxIndexStack) >= 0) {
//		return obj->queue->arr[peek(obj->maxIndexStack)];
//	} else {
//		return -1;
//	}
//}
//
//void maxQueuePush_back(MaxQueue* obj, int value) {
//	if (!queueIsFull(obj->queue)) {
//		enQueue(value, obj->queue);
//	}
//	if (emptyStack(obj->maxIndexStack) || value >= obj->queue->arr[peek(obj->maxIndexStack)]) {
//		push (obj->queue->rear - 1, obj->maxIndexStack);
//	}
//}
//
//int maxQueuePop_front(MaxQueue* obj) {
//	if (peek(obj->maxIndexStack) == obj->queue->front) {
//		int i = 0;
//		pop(&i, obj->maxIndexStack);
//	}
//	int x = -1;
//	if (!emptyStack(obj->queue)) {
//		deQueue(&x, obj->queue);
//	}
//	return x;
//}
//
//void maxQueueFree(MaxQueue* obj) {    
//	free(obj->queue->arr);
//	free(obj->maxIndexStack->items);
//	free(obj->queue);
//	free(obj->maxIndexStack);
//	free(obj);
//}
typedef struct stack {
	int *items;
	int maxSize;
	int top;
} Stack;

void initializeStack (Stack * ps, int maxSize) {
	int *items = (int *) malloc (sizeof(int) * maxSize);
	ps->top = 0;
	ps->maxSize = maxSize;
	ps->items = items;
}

bool fullStack (const Stack * ps) {
	return ps->top == ps->maxSize;
}

bool emptyStack (const Stack * ps) {
	return ps->top == 0;
}

bool push (int item, Stack * ps) {
	if (ps->top == ps->maxSize) {
		return false;
	} else {
		ps->items[ps->top++] = item;
		return true;
	}
}

bool pop (int * pitem, Stack * ps) {
	if (ps->top == 0) {
		return false;
	} else {
		ps->top--;
		*pitem = ps->items[ps->top];
		return true;
	}
}

int peek (const Stack * ps) {
	if (ps->top > 0) {
		return ps->items[ps->top - 1];
	} else {
		return INT_MIN;
	}
}

typedef struct {
	Stack* stack;
	Stack* maxIndexStack;
} MaxStack;

/** initialize your data structure here. */
MaxStack* maxStackCreate(int maxSize) {
	MaxStack *maxStack = (MaxStack*) malloc (sizeof(MaxStack));
	Stack *stack = (Stack*) malloc (sizeof(Stack));
	initializeStack(stack, maxSize);
	Stack *maxIndexStack = (Stack*) malloc (sizeof(Stack));
	initializeStack(maxIndexStack, maxSize);
	maxStack->stack = stack;
	maxStack->maxIndexStack = maxIndexStack;
	return maxStack;
}

void maxStackPush(MaxStack* obj, int x) {
	if (!fullStack(obj->stack)) {
		push (x, obj->stack);
	}
	if (emptyStack(obj->maxIndexStack) || x >= obj->stack->items[peek(obj->maxIndexStack)]) {
		push (obj->stack->top - 1, obj->maxIndexStack);
	}
}

int maxStackPop(MaxStack* obj) {
	if (peek(obj->maxIndexStack) == obj->stack->top - 1) {
		int i = 0;
		pop(&i, obj->maxIndexStack);
	}
	int x = 0;
	if (!emptyStack(obj->stack)) {
		pop(&x, obj->stack);
	}
	return x;
}

int maxStackTop(MaxStack* obj) {
	return peek(obj->stack);
}

int maxStackPeekMax(MaxStack* obj) {
	return obj->stack->items[peek(obj->maxIndexStack)];
}

int maxStackPopMax(MaxStack* obj) {
	int mx = maxStackPeekMax(obj);
	Stack* temp = (Stack*) malloc (sizeof(Stack));
	initializeStack(temp, obj->stack->maxSize);
	int x = 0;
	while (maxStackTop(obj) != maxStackPeekMax(obj)) {
		push(maxStackTop(obj), temp);
		pop(&x, obj->stack);
	}
	pop(&x, obj->stack);
	pop(&x, obj->maxIndexStack);
	while (!emptyStack(temp)) {
		maxStackPush(obj, peek(temp));
		pop(&x, temp);
	}
	free(temp);
	return mx;
}

void maxStackFree(MaxStack* obj) {
	free(obj->stack->items);
	free(obj->maxIndexStack->items);
	free(obj->stack);
	free(obj->maxIndexStack);
	free(obj);
}

typedef struct {
	MaxStack *s1;
	MaxStack *s2;
} MaxQueue;


MaxQueue* maxQueueCreate() {
	MaxQueue *maxQueue = (MaxQueue *) malloc (sizeof(MaxQueue));
	MaxStack *s1 = maxStackCreate(1024);
	MaxStack *s2 = maxStackCreate(1024);
	maxQueue->s1 = s1;
	maxQueue->s2 = s2;
	return maxQueue;
}

int maxQueueMax_value(MaxQueue* obj) {
	if (emptyStack(obj->s1->stack) && emptyStack(obj->s2->stack)) {
		return -1;
	} else {
		int max1 = INT_MIN;
		int max2 = INT_MIN;
		if (!emptyStack(obj->s1->stack)) {
			max1 = maxStackPeekMax(obj->s1);
		}
		if (!emptyStack(obj->s2->stack)) {
			max2 = maxStackPeekMax(obj->s2);
		}
		return max1 > max2 ? max1 : max2;
	}
}

void maxQueuePush_back(MaxQueue* obj, int value) {
	maxStackPush(obj->s1, value);
}

int maxQueuePop_front(MaxQueue* obj) {
	if (emptyStack(obj->s1->stack) && emptyStack(obj->s2->stack)) {
		return -1;
	} 
	if (emptyStack(obj->s2->stack)) {
		while (!emptyStack(obj->s1->stack)) {
			maxStackPush(obj->s2, maxStackPop(obj->s1));
		}
	}
	return maxStackPop(obj->s2);
}

void maxQueueFree(MaxQueue* obj) {    
	maxStackFree(obj->s1);
	maxStackFree(obj->s2);
	free(obj);
}