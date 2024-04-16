//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define MAX_STACK_SIZE 100
//
//typedef int element;
//typedef struct Stacktype {
//    element* data;
//    int top;
//    int capacity;
//} StackType;
//
//void init(StackType* sptr, int ofs) {
//    sptr->data = (element*)malloc(sizeof(element) * ofs);
//    sptr->top = -1;
//    sptr->capacity = ofs;
//}
//
//int is_full(StackType* sptr) {
//    return (sptr->top == sptr->capacity - 1);
//}
//
//int is_empty(StackType* sptr) {
//    return (sptr->top == -1);
//}
//
//void push(StackType* sptr, element item) {
//    if (is_full(sptr)) {
//        fprintf(stderr, "Stack is full\n");
//        return;
//    }
//    else {
//        sptr->top++;
//        sptr->data[sptr->top] = item;
//    }
//}
//
//element pop(StackType* sptr) {
//    if (is_empty(sptr)) {
//        fprintf(stderr, "Stack is empty\n");
//        return -1;
//    }
//    else {
//        return sptr->data[(sptr->top)--];
//    }
//}
//
//void stack_print(StackType* sptr) {
//    for (int i = 0; i <= sptr->top; i++) {
//        printf("[%d] ", sptr->data[i]);
//    }
//    printf("\n");
//}
//
//int eval(char expr[]) {
//    int len;
//    StackType s;
//
//    len = strlen(expr);
//    init(&s, len);
//
//    for (int i = 0; i < len; i++) {
//        int ch = expr[i];
//        int value;
//        int op1, op2;
//
//        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
//            op1 = pop(&s);
//            op2 = pop(&s);
//            switch (ch) {
//            case '+':
//                push(&s, op2 + op1);
//                break;
//            case '-':
//                push(&s, op2 - op1);
//                break;
//            case '*':
//                push(&s, op2 * op1);
//                break;
//            case '/':
//                push(&s, op2 / op1);
//                break;
//            default:
//                break;
//            }
//        }
//        else if (ch >= '0' && ch <= '9') {
//            value = ch - '0';
//            push(&s, value);
//        }
//        else {
//            //printf(" Abnormal character in expression\n");
//        }
//    }
//    return (pop(&s));
//}
//
//int main() {
//    char expression[MAX_STACK_SIZE];
//
//    printf("postfix expression: ");
//    fgets(expression, sizeof(expression), stdin);
//    expression[strcspn(expression, "\n")] = '\0'; // remove newline character
//
//    int result = eval(expression);
//
//    printf("Result: %d\n", result);
//
//    return 0;
//}
