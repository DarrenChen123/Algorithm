// 1.使用两个最大栈
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


// 2.使用双端队列
typedef struct deque {
	int front;
	int rear;
	int items;
	int maxSize;
	int *arr;
} Deque;

void initializeDeque (Deque * pq, int maxSize) {
	pq->front = 0;
	pq->rear = -1;
	pq->items = 0;
	pq->maxSize = maxSize;
	pq->arr = (int *)malloc(sizeof(int) * maxSize);
	memset(pq->arr, 0, sizeof(int) * maxSize);
}

bool dequeIsFull (const Deque * pq) {
	if (pq->maxSize == pq->items) {
		return true;
	} else {
		return false;
	}
}

bool dequeIsEmpty (const Deque * pq) {
	return pq->items == 0;
}

int dequeItemCount (const Deque * pq) {
	return pq->items;
}

bool push_back (int item, Deque * pq) {
	if (dequeIsFull(pq)) {
		return false;
	} else {
		pq->rear = (pq->rear + 1) % (pq->maxSize);
		pq->items++;
		pq->arr[pq->rear] = item;
		return true; 
	}
}

bool push_front (int item, Deque * pq) {
	if (dequeIsFull(pq)) {
		return false;
	} else {
		pq->front = (pq->front - 1 + pq->maxSize) % (pq->maxSize);
		pq->items++;
		pq->arr[pq->front] = item;
		return true;
	}
}

bool pop_front(int* pitem, Deque * pq) {
	if (dequeIsEmpty(pq)) {
	   return false;
	}
	*pitem = pq->arr[pq->front];
	pq->front = (pq->front + 1) % (pq->maxSize);
	pq->items--;
	return true; 
}

bool pop_back(int* pitem, Deque * pq) {
	if (dequeIsEmpty(pq)) {
	   return false;
	}
	*pitem = pq->arr[pq->rear];
	pq->rear = (pq->rear - 1 + pq->maxSize) % (pq->maxSize);
	pq->items--;
	return true; 
}

int peek_front (const Deque * pq) {
	if (!dequeIsEmpty(pq)) {
		return pq->arr[pq->front];
	} else {
		return INT_MIN;
	}
}

int peek_back (const Deque * pq) {
	if (!dequeIsEmpty(pq)) {
		return pq->arr[pq->rear];
	} else {
		return INT_MIN;
	}
}

/** initialize your data structure here. */

typedef struct {
	Deque *deque;
	Deque *maxIndexDeque;
} MaxQueue;


MaxQueue* maxQueueCreate() {
	MaxQueue *maxQueue = (MaxQueue *) malloc (sizeof(MaxQueue));
	Deque *deque = (Deque *) malloc (sizeof(Deque));
	initializeDeque(deque, 1024);
	Deque *maxIndexDeque = (Deque *) malloc (sizeof(Deque));
	initializeDeque(maxIndexDeque, 1024);
	maxQueue->deque = deque;
	maxQueue->maxIndexDeque = maxIndexDeque;
	return maxQueue;
}

int maxQueueMax_value(MaxQueue* obj) {
	if (peek_front(obj->maxIndexDeque) >= 0) {
		return obj->deque->arr[peek_front(obj->maxIndexDeque)];
	} else {
		return -1;
	}
}

void maxQueuePush_back(MaxQueue* obj, int value) {
	while (!dequeIsEmpty(obj->maxIndexDeque) && obj->deque->arr[peek_back(obj->maxIndexDeque)] < value) {
		int i = 0;
		pop_back(&i, obj->maxIndexDeque);
	}
	if (!dequeIsFull(obj->deque)) {
		push_back(value, obj->deque);
	}
	if (!dequeIsFull(obj->maxIndexDeque)) {
		push_back((obj->deque->rear) % obj->deque->maxSize, obj->maxIndexDeque);
	}
}

int maxQueuePop_front(MaxQueue* obj) {
	if (peek_front(obj->maxIndexDeque) == obj->deque->front) {
		int i = 0;
		pop_front(&i, obj->maxIndexDeque);
	}
	int x = -1;
	if (!dequeIsEmpty(obj->deque)) {
		pop_front(&x, obj->deque);
	}
	return x;
}

void maxQueueFree(MaxQueue* obj) {    
	free(obj->deque->arr);
	free(obj->maxIndexDeque->arr);
	free(obj->deque);
	free(obj->maxIndexDeque);
	free(obj);
}