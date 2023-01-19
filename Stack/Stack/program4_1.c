//���� ������ ���� ���� + 11�� ���� Ǯ��
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef char element;
element stack[MAX_STACK_SIZE];
int top = -1;
int count = 0; //��ȣ push, pop��ŭ ī��Ʈ

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
		count++;
		printf("%d\n", count);
	}
}

//�����Լ�
element pop() {
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else {
		printf("%d\n", count);
		count--;
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
	push('(');
	push('(');
	push('(');
	pop();
	pop();
	push('(');
	push('(');
	pop();
	pop();
	return 0;
}