/*
Given a balanced parentheses string S, compute the score of the string based on the following rule:

() has score 1
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.


Example 1:

Input: "()"
Output: 1
Example 2:

Input: "(())"
Output: 2
Example 3:

Input: "()()"
Output: 2
Example 4:

Input: "(()(()))"
Output: 6


Note:

S is a balanced parentheses string, containing only ( and ).
2 <= S.length <= 50
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
        return "";
    }
}

int scoreOfParentheses(char* S) {
    if (!S) {
        return 0;
    }
    int length = strlen(S);
    if (length == 0) {
        return 0;
    }
    int current = 0;
    int total = 0;
    int leftCount = 0;
    Stack* stack = (Stack *) malloc (sizeof(Stack));
    initializeStack(stack, length);
    for (int i = 0; i < length; i++) {
        if (S[i] == '(' && S[i + 1] == ')') {
            current++;
            i++;
        } else if (S[i] == '(' && S[i + 1] == '(') {
            push(current, stack);
            current = 0;
        } else if (S[i] == ')') {
            int* pre = (int*) malloc (sizeof(int));
            pop(pre, stack);
            current = current * 2 + *pre;
            free(pre);
        }
    }
    free(stack);
    return current;
}
