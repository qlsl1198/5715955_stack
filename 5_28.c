#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listNode {
    element data;
    struct listNode* link;
} ListNode;

ListNode* insert_first(ListNode* tail, element data) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if (tail == NULL) {
        tail = node;
        node->link = tail;
    }
    else {
        node->link = tail->link;
        tail->link = node;
    }
    return tail;
}

void print_list(ListNode* tail) {
    ListNode* p;
    if (tail == NULL) return;
    p = tail->link;
    /*do {
        printf("%2d -> ", p->data);
        p = p->link;
    } while (p != tail);*/
    while (p != tail) {
        printf("%2d -> ", p->data);
        p = p->link;
    }
    printf("%d", p->data);
    printf(" (head)");
    printf("\n");
}

ListNode* insert_last(ListNode* tail, element data) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode)); //<1>
    node->data = data; //<2>
    if (tail == NULL) {
        tail = node;
        node->link = tail;
    }
    else {
        node->link = tail->link; //<3>
        tail->link = node;
        tail = node; //<4>
    }
    return tail;
}

ListNode* delete_first(ListNode* tail) {
    if (tail == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    ListNode* removed = tail->link;
    if (tail == removed) {
        free(removed);
        return NULL;
    }
    tail->link = removed->link;
    free(removed);
    return tail;
}

ListNode* delete_last(ListNode* tail) {
    if (tail == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    ListNode* prev = tail;
    ListNode* curr = tail->link;
    if (tail == curr) {
        free(curr);
        return NULL;
    }
    while (curr->link != tail->link) {
        prev = curr;
        curr = curr->link;
    }
    prev->link = tail->link;
    free(tail);
    return prev;
}

void menu() {
    printf("Menu:\n");
    printf("1. Insert at the beginning\n");
    printf("2. Insert at the end\n");
    printf("3. Delete from the beginning\n");
    printf("4. Delete from the end\n");
    printf("5. Print the list\n");
    printf("6. Exit\n");
}

int main() {
    ListNode* tail = NULL;
    int choice, value;

    while (1) {
        menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter a number: ");
            scanf("%d", &value);
            tail = insert_first(tail, value);
            print_list(tail);
            break;
        case 2:
            printf("Enter a number: ");
            scanf("%d", &value);
            tail = insert_last(tail, value);
            print_list(tail);
            break;
        case 3:
            tail = delete_first(tail);
            print_list(tail);
            break;
        case 4:
            tail = delete_last(tail);
            print_list(tail);
            break;
        case 5:
            print_list(tail);
            break;
        case 6:
            while (tail != NULL) {
                tail = delete_first(tail);
            }
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
