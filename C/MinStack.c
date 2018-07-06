// Easy Collection
// Bloomberg
// Amazon
/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/

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
    Stack *stack;
    Stack *minIndexStack;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
    MinStack *minStack = (MinStack *) malloc (sizeof(MinStack));
    Stack *stack = (Stack *) malloc (sizeof(Stack));
    initializeStack(stack, maxSize);
    Stack *minIndexStack = (Stack *) malloc (sizeof(Stack));
    initializeStack(minIndexStack, maxSize);
    minStack->stack = stack;
    minStack->minIndexStack = minIndexStack;
    return minStack;
}

void minStackPush(MinStack* obj, int x) {
    if (!fullStack(obj->stack)) {
        push (x, obj->stack);
    }
    if (emptyStack(obj->minIndexStack) || x <= obj->stack->items[peek(obj->minIndexStack)]) {
        push (obj->stack->top - 1, obj->minIndexStack);
    }
}

void minStackPop(MinStack* obj) {
    if (peek(obj->minIndexStack) == obj->stack->top - 1) {
        int i = 0;
        pop(&i, obj->minIndexStack);
    }
    int x = 0;
    if (!emptyStack(obj->stack)) {
        pop(&x, obj->stack);
    }
}

int minStackTop(MinStack* obj) {
    return peek(obj->stack);
}

int minStackGetMin(MinStack* obj) {
    return obj->stack->items[peek(obj->minIndexStack)];
}

void minStackFree(MinStack* obj) {
    free(obj->stack->items);
    free(obj->minIndexStack->items);
    free(obj->stack);
    free(obj->minIndexStack);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */
