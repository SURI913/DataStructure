//����ü�� ���� ����

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define MAX_SIZE 100

typedef struct {
	int num[MAX_SIZE];
	char bracket[MAX_SIZE];
}element;

element stack[MAX_STACK_SIZE];
int top = -1;

//���� ���� ���� �Լ�
int is_empty() {
	return (top == -1);
}

//��ȭ���� ���� �Լ�
int is_full() {
	return (top == (MAX_STACK_SIZE - 1));
}

//�����Լ�
void push(element item) {
	if (is_full()) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else {
		stack[++top] = item;
	}
}

//�����Լ�
element pop() {
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else {
		return stack[top--];
	}
}

// ��ũ�Լ�
element peek() {
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return stack[top];
}

int main() {
	element b1;
	element b2;
}