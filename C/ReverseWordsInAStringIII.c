// Array and String
/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.
*/

typedef struct stack {
	char *word;
	int maxSize;
	int top;
} Stack;

void initializeStack (Stack * ps, int maxSize) {
	char *word = (char *) malloc (sizeof(char) * maxSize);
	ps->top = 0;
	ps->maxSize = maxSize;
	ps->word = word;
}

int fullStack (Stack * ps) {
	return ps->top == ps->maxSize;
}

int emptyStack (const Stack * ps) {
	return ps->top == 0;
}

int push (char item, Stack * ps) {
	if (ps->top == ps->maxSize) {
		return 0;
	} else {
		ps->word[ps->top++] = item;
		return 1;
	}
}

char pop(Stack * ps) {
	if (ps->top == 0) {
		return 0;
	} else {
		ps->top--;
		return ps->word[ps->top];
	}
}

char * reverseWords(char * s){
	int length = strlen(s);
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	initializeStack(stack, 1024);
	int index = 0;
	for (int i = 0;i < length;i++) {
		if (s[i] != ' ' && s[i] != '\0') {
			push(s[i], stack);
		} else {
			while (!emptyStack(stack)) {
				s[index++] = pop(stack);
			}
			s[index++] = ' ';
		}
	}
    while (!emptyStack(stack)) {
		s[index++] = pop(stack);
	}
	s[index] = '\0';
	free(stack);
	return s;
}