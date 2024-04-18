//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//#define INITIAL_CAPACITY 5
//#define MAX_SIZE 5
//
//typedef struct {
//    int* data;
//    int capacity;
//    int top;
//} Stack;
//
//void init(Stack* stack) {
//    stack->data = (int*)malloc(INITIAL_CAPACITY * sizeof(int));
//    stack->capacity = INITIAL_CAPACITY;
//    stack->top = -1;
//}
//
//int is_empty(Stack* stack) {
//    return (stack->top == -1);
//}
//
//void resize(Stack* stack) {
//    stack->capacity *= 2;
//    stack->data = (int*)realloc(stack->data, stack->capacity * sizeof(int));
//}
//
//void push(Stack* stack, int item) {
//    if (stack->top == stack->capacity - 1) {
//        resize(stack);
//    }
//    stack->data[++(stack->top)] = item;
//    printf("Pushed: %d\n", item);
//}
//
//int pop(Stack* stack) {
//    if (is_empty(stack)) {
//        printf("Stack is empty. Cannot pop.\n");
//        return -1;
//    }
//    int item = stack->data[(stack->top)--];
//    printf("Popped: %d\n", item);
//    return item;
//}
//
//int main() {
//    Stack stack;
//    init(&stack);
//    srand(time(NULL));
//
//    for (int i = 0; i < 30; i++) {
//        int rand_num = rand() % 100 + 1;
//        if (rand_num % 2 == 0) {
//            push(&stack, rand_num);
//        }
//        else {
//            pop(&stack);
//        }
//    }
//
//    free(stack.data);
//
//    return 0;
//}
