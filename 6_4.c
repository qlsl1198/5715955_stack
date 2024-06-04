#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
    element data;
    struct DListNode* llink;
    struct DListNode* rlink;
} DListNode;

// 이중 원형 리스트 초기화
void init(DListNode* phead) {
    phead->llink = phead->rlink = phead;
}

// 리스트가 비어있는지 확인
int is_empty(DListNode* head) {
    return head->rlink == head;
}

// 리스트의 처음에 삽입
void insert_first(DListNode* head, element data) {
    DListNode* node = (DListNode*)malloc(sizeof(DListNode));
    node->data = data;
    node->llink = head;
    node->rlink = head->rlink;
    head->rlink->llink = node;
    head->rlink = node;
}

// 리스트의 마지막에 삽입
void insert_last(DListNode* head, element data) {
    DListNode* node = (DListNode*)malloc(sizeof(DListNode));
    node->data = data;
    node->rlink = head;
    node->llink = head->llink;
    head->llink->rlink = node;
    head->llink = node;
}

// 리스트의 첫 번째 노드 삭제
void delete_first(DListNode* head) {
    if (!is_empty(head)) {
        DListNode* removed = head->rlink;
        head->rlink = removed->rlink;
        removed->rlink->llink = head;
        free(removed);
    }
    else {
        printf("List is empty.\n");
    }
}

// 리스트의 마지막 노드 삭제
void delete_last(DListNode* head) {
    if (!is_empty(head)) {
        DListNode* removed = head->llink;
        head->llink = removed->llink;
        removed->llink->rlink = head;
        free(removed);
    }
    else {
        printf("List is empty.\n");
    }
}

// 리스트 출력
void print_list(DListNode* phead) {
    DListNode* p;
    for (p = phead->rlink; p != phead; p = p->rlink) {
        printf(" %d ->", p->data);
    }
    printf("(head)\n");
}

void menu() {
    printf("\nMenu:\n");
    printf("1. Insert at the beginning\n");
    printf("2. Insert at the end\n");
    printf("3. Delete from the beginning\n");
    printf("4. Delete from the end\n");
    printf("5. Print the list\n");
    printf("6. Exit\n");
}

int main() {
    DListNode* head = (DListNode*)malloc(sizeof(DListNode));
    init(head);
    int choice, value;

    while (1) {
        menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter a number: ");
            scanf("%d", &value);
            insert_first(head, value);
            print_list(head);
            break;
        case 2:
            printf("Enter a number: ");
            scanf("%d", &value);
            insert_last(head, value);
            print_list(head);
            break;
        case 3:
            delete_first(head);
            print_list(head);
            break;
        case 4:
            delete_last(head);
            print_list(head);
            break;
        case 5:
            print_list(head);
            break;
        case 6:
            while (!is_empty(head)) {
                delete_first(head);
            }
            free(head);
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
