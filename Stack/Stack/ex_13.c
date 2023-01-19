#include<stdio.h>
#include<stdlib.h>

//===== ���� �ڵ��� ���� =====
#define MAX_STACK_SIZE 100

typedef char element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

//���� �ʱ�ȭ �Լ�
void init_stack(StackType* s) {
	s->top = -1;
}

//���� ���� ���� �Լ�
int is_empty(StackType* s) {
	return (s->top == -1);
}
//��ȭ ���� ���� �Լ�
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

//�����Լ�
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

//�����Լ�
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

//��ũ�Լ�
element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[s->top];
}
//===== ���� �ڵ��� �� ====

int main() {
	StackType n;
	init_stack(&n);

	char input[100] ="";

	printf("������ �Է��Ͻÿ�: ");
	scanf_s("%s", input, 100);

	for (int i = 0; input[i] != '\0'; i++) {
		push(&n, input[i]);

		if (peek(&n) != input[i + 1]) {
			printf("%c ", peek(&n));
		}
	}
	return 0;
}