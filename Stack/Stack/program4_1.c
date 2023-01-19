//전역 변수로 스택 구현 + 11번 문제 풀이
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef char element;
element stack[MAX_STACK_SIZE];
int top = -1;
int count = 0; //괄호 push, pop만큼 카운트

//공백 상태 검출 함수
int is_empty() {
	return (top == -1);
}

//포화상태 검출 함수
int is_full() {
	return (top == (MAX_STACK_SIZE - 1));
}

//삽입함수
void push(element item) {
	if (is_full()) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else {
		stack[++top] = item;
		count++;
		printf("%d\n", count);
	}
}

//삭제함수
element pop() {
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else {
		printf("%d\n", count);
		count--;
		return stack[top--];
	}
}

// 피크함수
element peek() {
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
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