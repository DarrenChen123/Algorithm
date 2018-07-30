// Easy Collection
// Bloomberg
// Microsoft
// Facebook
// Google
// Queue & Stack
/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/

typedef struct stack {
    char *items;
    int maxSize;
    int top;
} Stack;

void initializeStack (Stack * ps, int maxSize) {
    char *items = (char *) malloc (sizeof(char) * maxSize);
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

bool push (char item, Stack * ps) {
    if (ps->top == ps->maxSize) {
        return false;
    } else {
        ps->items[ps->top++] = item;
        return true;
    }
}

bool pop (char * pitem, Stack * ps) {
    if (ps->top == 0) {
        return false;
    } else {
        ps->top--;
        *pitem = ps->items[ps->top];
        return true;
    }
}

char peek (const Stack * ps) {
    if (ps->top > 0) {
        return ps->items[ps->top - 1];
    } else {
        return "";
    }
}

bool isValid(char* s) {
    if (!s) {
        return true;
    }
    int length = strlen(s);
    if (length == 0) {
        return true;
    }
    Stack * stack = (Stack *) malloc (sizeof(Stack));
    initializeStack(stack, length);
    for (int i = 0; i < length; i++) {
        switch (s[i]) {
            case '(':
            case '[':
            case '{':
                push(s[i], stack);
                break;
            case ')':
                if (peek(stack) != '(') {
                    return false;
                } else {
                    char current;
                    pop(&current, stack);
                }
                break;
            case ']':
                if (peek(stack) != '[') {
                    return false;
                } else {
                    char current;
                    pop(&current, stack);
                }
                break;
            case '}':
                if (peek(stack) != '{') {
                    return false;
                } else {
                    char current;
                    pop(&current, stack);
                }
                break;
            default:
                return false;
        }
    }
    if (emptyStack(stack)) {
        return true;
    } else {
        return false;
    }
}
