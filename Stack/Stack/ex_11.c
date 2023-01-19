//11번문제 괄호의 번호를 출력하는 프로그램을 작성하라
#include <stdio.h>
#include<stdlib.h>

//===== 스택 코드의 시작 =====
#define MAX_STACK_SIZE 100

typedef char element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
	int count;
} StackType;

//스택 초기화 함수
void init_stack(StackType* s) {
	s->top = -1;
	s->count = 0;
}

//공백 상태 검출 함수
int is_empty(StackType* s) {
	return (s->top == -1);
}
//포화 상태 검출 함수
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

//삽입함수
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else {
		s->data[++(s->top)] = item;
		s->count++; //괄호 들어옴 체크
		printf("%d\n", s-> count);
	}
}

//삭제함수
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else {
		printf("%d\n", s->count);
		s->count--; //괄호가 빠져나감 체크
		return s->data[(s->top)--];
	}
}

//피크함수
element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}
//===== 스택 코드의 끝 ====

int main() {
	StackType b1, b2;

	printf("===== 첫번째 괄호 번호 출력 =====\n");
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

	printf("===== 두번째 괄호 번호 출력 =====\n");
	init_stack(&b2);
	push(&b2, '(');
	push(&b2, '(');
	push(&b2, '(');
	push(&b2, '(');
	push(&b2, '(');
	pop(&b2);
	return 0;
}