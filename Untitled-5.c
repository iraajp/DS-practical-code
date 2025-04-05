// Program to evaluate Postfix expression                                   27/03/25
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 100
int stack[MAX], top = -1;
void push(int val) { stack[++top] = val; }
int pop() { return stack[top--]; }
int evaluatePostfix(char *exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        } else {
            int val2 = pop();
            int val1 = pop();
            switch (exp[i]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }
    return pop();
}
int main() {
    char postfix[] = "231*+9-";
    printf("Result: %d\n", evaluatePostfix(postfix));
    return 0;
}
