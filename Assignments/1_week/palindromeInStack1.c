// Write a C code to check for palindrome using Stacks
// Method 1: with using structures
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

// Stack structure
struct Stack {
    char arr[MAX];
    int top;
};

// Function to initialize the stack
void initStack(struct Stack *s) {
    s->top = -1;
}

// Function to check if the stack is full
bool isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

// Function to check if the stack is empty
bool isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack *s, char c) {
    if (!isFull(s)) {
        s->arr[++(s->top)] = c;
    } else {
        printf("Stack Overflow\n");
    }
}

// Function to pop an element from the stack
char pop(struct Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[(s->top)--];
    } else {
        printf("Stack Underflow\n");
        return '\0';
    }
}

// Function to check if a string is a palindrome
bool isPalindrome(char *str) {
    int len = strlen(str);
    struct Stack s;
    initStack(&s);

    // Push all characters onto the stack
    for (int i = 0; i < len; i++) {
        push(&s, str[i]);
    }

    // Check if the string is the same when reversed
    for (int i = 0; i < len; i++) {
        if (str[i] != pop(&s)) {
            return false;
        }
    }

    return true;
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
