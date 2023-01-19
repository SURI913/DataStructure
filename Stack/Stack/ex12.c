//12�� ���� ������ ����
#include <stdio.h>
#include<stdlib.h>
#include <ctype.h>

//===== ���� �ڵ��� ���� =====
#define MAX_STACK_SIZE 26 //���ĺ� ���̸�ŭ

typedef char element;
typedef struct {
	element alpha[MAX_STACK_SIZE];
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
	else {
		s->alpha[++(s->top)] = item;
	}
}

//�����Լ�
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else {
		return s->alpha[(s->top)--];
	}
}

//��ũ�Լ�
element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else {
		return s->alpha[s->top];
	}
}
//===== ���� �ڵ��� �� ====

int main() {
	printf("���ڿ��� �Է��Ͻÿ�: ");
	char input[100];
	int n = sizeof(input);
	scanf_s("%s", input, n);

	StackType r;
	init_stack(&r);

	int alpha[26] = { 0, }; //���ĺ� üũ�� �迭

	for (int i = 0; input[i] != '\0'; i++) { //���ڿ� ��ŭ �ڸ���
		input[i] = tolower(input[i]);// ���ڿ��� ��� �����ڸ� �ҹ��ڷ� ��ȯ��. 
		push(&r, input[i]); //���ÿ� ����
		alpha[(int)peek(&r) - 97]++;
	}
	
	//���
	for (int i = 0; i < 26; i++) {
		if (alpha[i] > 0) {
			printf("%d%c",alpha[i], i + 97);
		}
	}
	return 0;
}
