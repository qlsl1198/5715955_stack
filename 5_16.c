#include <stdio.h>
#include <stdlib.h>

typedef int element;
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
    p->data = value;
    p->link = h;
    return p;
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
    p->data = value;
    p->link = pre->link;
    pre->link = p;
    return head;
}

ListNode* delete(ListNode* head, ListNode* pre) {
    if (pre == NULL || pre->link == NULL) {
        fprintf(stderr, "Invalid delete position\n");
        return head;
    }
    ListNode* removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}

void print_list(ListNode* h) {
    while (h != NULL) {
        printf("[%d] ", h->data);
        h = h->link;
    }
    printf("\n");
}

int main() {
    ListNode* head = NULL;
    int choice, value, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a number into the list\n");
        printf("2. Delete a number from the list\n");
        printf("3. Print the list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the number to insert: ");
            scanf("%d", &value);
            printf("Enter the position to insert at (0 for first): ");
            scanf("%d", &position);

            if (position == 0) {
                head = insert_first(head, value);
            }
            else {
                ListNode* p = head;
                int count = 0;
                for (int i = 0; i < position - 1 && p != NULL; i++) {
                    p = p->link;
                    count++;
                }
                if (p != NULL) {
                    head = insert(head, p, value);
                    printf("Inserted after moving %d steps.\n", count + 1);
                }
                else {
                    printf("Position out of range\n");
                }
            }
            break;

        case 2:
            printf("Enter the position to delete from (1 for first): ");
            scanf("%d", &position);

            if (position == 1) {
                if (head != NULL) {
                    ListNode* removed = head;
                    head = head->link;
                    free(removed);
                    printf("Deleted the first node.\n");
                }
                else {
                    printf("List is empty\n");
                }
            }
            else {
                ListNode* p = head;
                int count = 0;
                for (int i = 0; i < position - 2 && p != NULL; i++) {
                    p = p->link;
                    count++;
                }
                if (p != NULL && p->link != NULL) {
                    head = delete(head, p);
                    printf("Deleted after moving %d steps.\n", count + 1);
                }
                else {
                    printf("Position out of range\n");
                }
            }
            break;

        case 3:
            print_list(head);
            break;

        case 0:
            // Free the allocated memory
            while (head != NULL) {
                ListNode* temp = head;
                head = head->link;
                free(temp);
            }
            return 0;

        default:
            printf("Invalid choice, try again.\n");
            break;
        }
    }
}
