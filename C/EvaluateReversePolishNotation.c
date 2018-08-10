// Medium Collection
// Google
// Queue & Stack
// LinkedIn
/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Note:

Division between two integers should truncate toward zero.
The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.
Example 1:

Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation:
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
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

int evalRPN(char** tokens, int tokensSize) {
    if (tokensSize <= 0) {
        return 0;
    }
    Stack* stack = (Stack *) malloc (sizeof(Stack));
    initializeStack(stack, tokensSize);
    for (int i = 0; i < tokensSize; i++) {
        if (!(strlen(tokens[i]) == 1 && !isdigit(tokens[i][0]))) {
            push(atoi(tokens[i]), stack);
        } else {
            int* first = (int*) malloc (sizeof(int));
            int* second = (int*) malloc (sizeof(int));
            pop(first, stack);
            pop(second, stack);
            int result = 0;
            switch(tokens[i][0]) {
                case '+':
                    result = *second + *first;
                    break;
                case '-':
                    result = *second - *first;
                    break;
                case '*':
                    result = *second * *first;
                    break;
                case '/':
                    result = *second / *first;
                    break;
            }
            push(result, stack);
            free(second);
            free(first);
        }
    }
    int* result = (int *) malloc (sizeof(int));
    pop(result, stack);
    int ret = *result;
    free(stack);
    return ret;
}
