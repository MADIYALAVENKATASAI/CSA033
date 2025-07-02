#include <stdio.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if(top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = c;
}

char pop() {
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char c) {
    if(c == '(')
        return 0;
    if(c == '+' || c == '-')
        return 1;
    if(c == '*' || c == '/')
        return 2;
    return -1;
}

int main() {
    char exp[100], *e, x;
    printf("Enter infix expression: ");
    scanf("%s", exp);

    e = exp;
    printf("Postfix expression: ");
    while(*e != '\0') {
        if(isalnum(*e))
            printf("%c", *e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')') {
            while((x = pop()) != '(')
                printf("%c", x);
        }
        else {
            while(priority(stack[top]) >= priority(*e))
                printf("%c", pop());
            push(*e);
        }
        e++;
    }

    while(top != -1) {
        printf("%c", pop());
    }

    printf("\n");
    return 0;
}

