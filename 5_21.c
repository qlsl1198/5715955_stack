#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 30

typedef char element[MAX_NAME_LENGTH];

typedef struct listnode {
    element data;
    struct listnode* link;
} ListNode;

ListNode* insert_first(ListNode* h, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    if (p == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }
    strcpy(p->data, value);
    p->link = h;
    h = p;
    return h;
}

ListNode* insert(ListNode* head, ListNode* pre, element value) {
    if (pre == NULL) {
        fprintf(stderr, "pre cannot be NULL\n");
        return head;
    }
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    if (p == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }
    strcpy(p->data, value);
    p->link = pre->link;  //<1>
    pre->link = p;        //<2>
    return head;
}

ListNode* insert_last(ListNode* head, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    if (p == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }
    strcpy(p->data, value);
    p->link = NULL;

    if (head == NULL) {
        return p;
    }
    else {
        ListNode* temp = head;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = p;
        return head;
    }
}

ListNode* delete_node(ListNode* head, element value, ListNode** deleted_list) {
    ListNode* p = head;
    ListNode* prev = NULL;

    while (p != NULL) {
        if (strcmp(p->data, value) == 0) {
            if (prev == NULL) {
                head = p->link;
            }
            else {
                prev->link = p->link;
            }
            p->link = *deleted_list;
            *deleted_list = p;
            return head;
        }
        prev = p;
        p = p->link;
    }

    printf("해당 과일이 없습니다.\n");
    return head;
}

void print_list(ListNode* head) {
    ListNode* p = head;
    while (p != NULL) {
        printf("%s ", p->data);
        p = p->link;
    }
    printf("\n");
}

ListNode* reverse(ListNode* h) {
    ListNode* r, * q, * p;

    q = NULL;
    p = h;
    while (p != NULL) {
        r = q;
        q = p;
        p = p->link;
        q->link = r;
    }
    return q;
}

int find_fruit(ListNode* head, element value) {
    ListNode* p = head;
    while (p != NULL) {
        if (strcmp(p->data, value) == 0) {
            return 1;
        }
        p = p->link;
    }
    return 0;
}

void print_menu() {
    printf("1. 리스트의 매 마지막에 새로운 과일 추가\n");
    printf("2. 리스트에 있는 과일 삭제\n");
    printf("3. 삭제된 과일 목록 출력\n");
    printf("4. 종료\n");
}

int main() {
    ListNode* head = NULL;
    ListNode* deleted_list = NULL;

    // 초기 과일 리스트
    element fruits[10] = { "Mango", "Orange", "Apple", "Grape", "Cherry",
                          "Plum", "Guava", "Raspberry", "Banana", "Peach" };
    for (int i = 0; i < 10; i++) {
        head = insert_last(head, fruits[i]);
    }

    int choice;
    element fruit_name;

    while (1) {
        print_menu();
        printf("메뉴를 선택하세요: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
        case 1:
            printf("추가할 과일 이름을 입력하세요: ");
            fgets(fruit_name, MAX_NAME_LENGTH, stdin);
            fruit_name[strcspn(fruit_name, "\n")] = '\0';  // Remove newline character

            if (find_fruit(head, fruit_name)) {
                printf("이미 존재하는 과일입니다.\n");
            }
            else {
                head = insert_last(head, fruit_name);
                printf("과일이 추가되었습니다.\n");
            }
            break;
        case 2:
            printf("삭제할 과일 이름을 입력하세요: ");
            fgets(fruit_name, MAX_NAME_LENGTH, stdin);
            fruit_name[strcspn(fruit_name, "\n")] = '\0';  // Remove newline character

            head = delete_node(head, fruit_name, &deleted_list);
            break;
        case 3:
            printf("삭제된 과일 목록:\n");
            print_list(deleted_list);
            break;
        case 4:
            printf("프로그램을 종료합니다.\n");
            // 메모리 해제
            ListNode* temp;
            while (head != NULL) {
                temp = head;
                head = head->link;
                free(temp);
            }
            while (deleted_list != NULL) {
                temp = deleted_list;
                deleted_list = deleted_list->link;
                free(temp);
            }
            return 0;
        default:
            printf("잘못된 선택입니다. 다시 시도하세요.\n");
        }
    }

    return 0;
}
