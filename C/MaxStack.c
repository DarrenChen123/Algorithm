// Subscription
// LinkedIn
/*
Design a max stack that supports push, pop, top, peekMax and popMax.

push(x) -- Push element x onto stack.
pop() -- Remove the element on top of the stack and return it.
top() -- Get the element on the top.
peekMax() -- Retrieve the maximum element in the stack.
popMax() -- Retrieve the maximum element in the stack, and remove it. If you find more than one maximum elements, only remove the top-most one.
Example 1:
MaxStack stack = new MaxStack();
stack.push(5);
stack.push(1);
stack.push(5);
stack.top(); -> 5
stack.popMax(); -> 5
stack.top(); -> 1
stack.peekMax(); -> 5
stack.pop(); -> 1
stack.top(); -> 5
Note:
-1e7 <= x <= 1e7
Number of operations won't exceed 10000.
The last four operations won't be called when stack is empty.
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

/**
 * Your MaxStack struct will be instantiated and called as such:
 * struct MaxStack* obj = maxStackCreate(maxSize);
 * maxStackPush(obj, x);
 * int param_2 = maxStackPop(obj);
 * int param_3 = maxStackTop(obj);
 * int param_4 = maxStackPeekMax(obj);
 * int param_5 = maxStackPopMax(obj);
 * maxStackFree(obj);
 */
