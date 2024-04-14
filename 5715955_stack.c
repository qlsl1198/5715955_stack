#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 5

typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

int is_full() {
    return (top == MAX_STACK_SIZE - 1);
}

int is_empty() {
    return (top == -1);
}

void push(element item) {
    if (is_full()) {
        fprintf(stderr, "Stack is full\n");
        return;
    }
    else {
        top = top + 1;
        stack[top] = item;
    }
}

element pop() {
    element r;
    if (is_empty()) {
        fprintf(stderr, "Stack is empty\n");
        return -1; // 스택이 비어있는 경우에도 -1을 반환하도록 수정
    }
    else {
        r = stack[top];
        top = top - 1;
        return r;
    }
}

element peek() {
    if (is_empty()) {
        fprintf(stderr, "Stack is empty\n");
        return -1; // 스택이 비어있는 경우에도 -1을 반환하도록 수정
    }
    else {
        return stack[top];
    }
}

int main() {
    element e;

    srand(time(NULL));

    for (int i = 0; i < 30; ++i) {
        e = (rand() % 100) + 1;

        if (e % 2 == 0) {
            printf("current rand_num : %d | Even\n", e);
            if (!is_full()) {
                push(e);
                printf("Push : %d\n", e);
            }
            else {
                printf("Stack Overflow\n");
            }
        }
        else {
            printf("current rand_num : %d | Odd\n", e);
            if (!is_empty()) {
                e = pop();
                printf("Pop : %d\n", e);
            }
            else {
                printf("Stack Underflow\n");
            }
        }

        // 스택의 상태 출력
        printf("Stack elements: ");
        if (is_empty()) {
            printf("Stack is empty");
        }
        else {
            for (int j = 0; j <= top; ++j) {
                printf("%d ", stack[j]);
            }
        }
        printf("\n\n");
    }

    return 0;
}
