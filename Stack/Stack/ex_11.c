//11������ ��ȣ�� ��ȣ�� ����ϴ� ���α׷��� �ۼ��϶�
#include <stdio.h>
#include<stdlib.h>

//===== ���� �ڵ��� ���� =====
#define MAX_STACK_SIZE 100

typedef char element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
	int count;
} StackType;

//���� �ʱ�ȭ �Լ�
void init_stack(StackType* s) {
	s->top = -1;
	s->count = 0;
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
	else {
		s->data[++(s->top)] = item;
		s->count++; //��ȣ ���� üũ
		printf("%d\n", s-> count);
	}
}

//�����Լ�
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else {
		printf("%d\n", s->count);
		s->count--; //��ȣ�� �������� üũ
		return s->data[(s->top)--];
	}
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
	StackType b1, b2;

	printf("===== ù��° ��ȣ ��ȣ ��� =====\n");
	init_stack(&b1);
	push(&b1, '(');
	push(&b1, '(');
	push(&b1, '(');
	pop(&b1);
	pop(&b1);
	push(&b1, '(');
	push(&b1, '(');
	pop(&b1);
	pop(&b1);
	pop(&b1);

	printf("===== �ι�° ��ȣ ��ȣ ��� =====\n");
	init_stack(&b2);
	push(&b2, '(');
	push(&b2, '(');
	push(&b2, '(');
	push(&b2, '(');
	push(&b2, '(');
	pop(&b2);
	return 0;
}