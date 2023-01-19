//12번 문제 런길이 압축
#include <stdio.h>
#include<stdlib.h>
#include <ctype.h>

//===== 스택 코드의 시작 =====
#define MAX_STACK_SIZE 26 //알파벳 길이만큼

typedef char element;
typedef struct {
	element alpha[MAX_STACK_SIZE];
	int top;
} StackType;

//스택 초기화 함수
void init_stack(StackType* s) {
	s->top = -1;
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
		s->alpha[++(s->top)] = item;
	}
}

//삭제함수
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else {
		return s->alpha[(s->top)--];
	}
}

//피크함수
element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else {
		return s->alpha[s->top];
	}
}
//===== 스택 코드의 끝 ====

int main() {
	printf("문자열을 입력하시오: ");
	char input[100];
	int n = sizeof(input);
	scanf_s("%s", input, n);

	StackType r;
	init_stack(&r);

	int alpha[26] = { 0, }; //알파벳 체크할 배열

	for (int i = 0; input[i] != '\0'; i++) { //문자열 만큼 자르기
		input[i] = tolower(input[i]);// 문자열의 모든 영문자를 소문자로 변환함. 
		push(&r, input[i]); //스택에 저장
		alpha[(int)peek(&r) - 97]++;
	}
	
	//출력
	for (int i = 0; i < 26; i++) {
		if (alpha[i] > 0) {
			printf("%d%c",alpha[i], i + 97);
		}
	}
	return 0;
}
