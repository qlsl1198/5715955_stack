#include <stdio.h>

#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {
	element array[MAX_LIST_SIZE];
	int size;
} ArrayListType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
}

void init(ArrayListType* L) {
	L->size = 0;
}

int is_full(ArrayListType* L) {
	return (L->size == MAX_LIST_SIZE);
}

void insert(ArrayListType* L, int pos, element item) {
	int move_count = 0;
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
		for (int i = L->size - 1; i >= pos; i--) {
			L->array[i + 1] = L->array[i];
			move_count++;
		}
		L->array[pos] = item;
		L->size++;

		printf("이동 횟수: %d\n", move_count);
	}
}

void insert_last(ArrayListType* L, element item) {
	if (L->size == MAX_LIST_SIZE) {
		error("list overflow.");
	}
	L->array[L->size++] = item;
}

void insert_first(ArrayListType* L, element item) {
	insert(L, 0, item);
}

void clear(ArrayListType* L) {
	init(L);
}

element get_entry(ArrayListType* L, int pos) {
	if (pos >= 0 && pos < L->size)
		return L->array[pos];
	else
		error("place error");
}

int get_length(ArrayListType* L) {
	return L->size;
}

int is_empty(ArrayListType* L) {
	return (L->size == 0);
}

void print_list(ArrayListType* L) {
	printf("[List]");
	for (int i = 0; i < L->size; i++)
		printf("%2d -> ", L->array[i]);
	//printf("\n");
}

element delete(ArrayListType* L, int pos) {
	if (pos < 0 || pos >= L->size)
		error("place error.");
	else {
		element item = L->array[pos];
		for (int i = pos; i < L->size - 1; i++)
			L->array[i] = L->array[i + 1];
		L->size--;
		return item;
	}
}

int main() {
	ArrayListType list;
	int menu;
	int pos, num;

	init(&list);

	while (1) {
		printf("\n(1) 리스트에 추가\n(2) 리스트에서 삭제\n(3) 리스트 출력\n(0) 종료\n");
		printf("메뉴를 선택하세요: ");
		scanf_s("%d", &menu);

		switch (menu) {
		case 1:
			printf("추가할 숫자와 위치를 입력하세요: ");
			scanf_s("%d %d", &num, &pos);
			insert(&list, pos, num);
			break;
		case 2:
			printf("삭제할 위치를 입력하세요: ");
			scanf_s("%d", &pos);
			delete(&list, pos);
			break;
		case 3:
			print_list(&list);
			printf(" NULL\n");
			break;
		case 0:
			printf("프로그램을 종료합니다.\n");
			return 0;
		default:
			printf("잘못된 입력입니다. 다시 선택하세요.\n");
		}
	}

	return 0;
}
