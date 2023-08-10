#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 100
struct Stack {
    int arr[MAX_SIZE];
    int top;
};
void initialize(struct Stack* stack) {
    stack->top = -1;
}
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push %d\n", value);
        return;
    }
    stack->top++;
    stack->arr[stack->top] = value;
}
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop\n");
        return -1;
    }
    int value = stack->arr[stack->top];
    stack->top--;
    return value;
}
int evaluatePostfix(char* postfix) {
    struct Stack stack;
    initialize(&stack);
    int length = strlen(postfix);
    for (int i = 0; i < length; i++) {
        char token = postfix[i];
        if (isdigit(token)) {
            push(&stack, token - '0');
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            switch (token) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator: %c\n", token);
                    return -1;
            }
        }
    }
    return pop(&stack);
}
int main() {
    char postfixExpression[MAX_SIZE];
    printf("Enter a postfix expression: ");
    fgets(postfixExpression, sizeof(postfixExpression), stdin);
    postfixExpression[strcspn(postfixExpression, "\n")] = '\0'; // Remove newline
    int result = evaluatePostfix(postfixExpression);
    if (result != -1) {
        printf("Result: %d\n", result);
        return 0;
    }
}
