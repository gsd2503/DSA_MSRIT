#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Stack structure for characters
struct Stack {
    char arr[MAX_SIZE];
    int top;
} charStack;

// Stack structure for integers (repeat counts)
struct IntStack {
    int arr[MAX_SIZE];
    int top;
} numStack;

// Function to initialize stacks
void initStacks() {
    charStack.top = -1;
    numStack.top = -1;
}

// Function to push a character onto the stack
void pushChar(char ch) {
    if (charStack.top < MAX_SIZE - 1) {
        charStack.arr[++charStack.top] = ch;
    }
}

// Function to push an integer onto the stack
void pushInt(int num) {
    if (numStack.top < MAX_SIZE - 1) {
        numStack.arr[++numStack.top] = num;
    }
}

// Function to pop a character from the stack
char popChar() {
    if (charStack.top >= 0) {
        return charStack.arr[charStack.top--];
    }
    return '\0';
}

// Function to pop an integer from the stack
int popInt() {
    if (numStack.top >= 0) {
        return numStack.arr[numStack.top--];
    }
    return 0;
}

// Function to decode an encoded string
char* decodeString(const char *s) {
    initStacks(); // Initialize stacks before use
    int i = 0;

    while (s[i] != '\0') {
        if (isdigit(s[i])) {
            // Extract full number
            int num = 0;
            while (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            pushInt(num);
        } else if (s[i] == '[') {
            pushChar(s[i]);
            i++;
        } else if (s[i] == ']') {
            // Pop characters until '[' is found
            char temp[MAX_SIZE];
            int index = 0;
            while (charStack.top >= 0 && charStack.arr[charStack.top] != '[') {
                temp[index++] = popChar();
            }
            temp[index] = '\0';
            popChar(); // Remove '['

            // Reverse temp since we popped in reverse order
            for (int j = 0; j < index / 2; j++) {
                char t = temp[j];
                temp[j] = temp[index - j - 1];
                temp[index - j - 1] = t;
            }

            // Get repeat count
            int repeat = popInt();

            // Repeat and push back to stack
            for (int j = 0; j < repeat; j++) {
                for (int k = 0; k < index; k++) {
                    pushChar(temp[k]);
                }
            }
            i++;
        } else {
            pushChar(s[i]);
            i++;
        }
    }

    // Extract final decoded string from stack
    char decoded[MAX_SIZE];
    int pos = 0;
    while (charStack.top >= 0) {
        decoded[pos++] = popChar();
    }
    decoded[pos] = '\0';

    // Reverse final output
    for (int j = 0; j < pos / 2; j++) {
        char t = decoded[j];
        decoded[j] = decoded[pos - j - 1];
        decoded[pos - j - 1] = t;
    }

    // Allocate memory for the result
    char *result = (char*)malloc((pos + 1) * sizeof(char));
    strcpy(result, decoded);
    return result;
}

// Driver function
int main() {
    char encodedString[MAX_SIZE];

    // Take user input
    printf("Enter the encoded string: ");
    scanf("%s", encodedString);

    // Decode the input string
    char *decoded = decodeString(encodedString);
    
    printf("Decoded String: %s\n", decoded);
    
    free(decoded);
    return 0;
}
