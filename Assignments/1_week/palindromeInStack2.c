// Write a C code to check for palindrome using Stacks
// Method 2: with out using structures
#include <stdio.h>
#include <string.h>

#define MAX 100  // Maximum size of the stack

// Global stack variables
char stack[MAX];
int top = -1;

// Function to push an element onto the stack
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack overflow.\n");
        return;
    }
    stack[++top] = c;
}

// Function to pop an element from the stack
char pop() {
    if (top == -1) {
        printf("Stack underflow.\n");
        return '\0';
    }
    return stack[top--];
}

// Function to check if a string is a palindrome using stack
int isPalindrome(char *str) {
    int length = strlen(str);
    int i;

    // Push all characters onto the stack
    for (i = 0; i < length; i++) {
        push(str[i]);
    }

    // Compare popped characters with the original string
    for (i = 0; i < length; i++) {
        if (str[i] != pop()) {
            return 0;  // Not a palindrome
        }
    }

    return 1;  // String is a palindrome
}

int main() {
    char str[MAX];

    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str)) {
        printf("The string \"%s\" is a palindrome.\n", str);
    } else {
        printf("The string \"%s\" is not a palindrome.\n", str);
    }

    return 0;
}
