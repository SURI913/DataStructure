//ArrayStack.h : 배열을 이용한 int 스택 클래스
#include <cstdio> /* C 헤더파일 <stdio.h>을 포함하는 것과 동일*/
#include <cstdlib>

//오류 처리 함수
inline void error(const char *message) {
	printf("%s\n", message);
	exit(1);
}

const int MAX_STACK_SIZE = 20; //스택의 최대 크기 설정
class ArrayStack {
	int top;	//요소의 개수
	int data[MAX_STACK_SIZE];	//요소의 배열
public:
	ArrayStack() { top = -1; } //스택 생성자 (ADT의 create()역할)
	~ArrayStack(){} //소멸자
	bool isEmpty() { return top == -1; }
	bool isFull() { return top == MAX_STACK_SIZE - 1; }

	void push(int e) {
		if ( isFull() ) error("스택 포화 에러");
		data[++top] = e;
	}

	int pop() {
		if (isEmpty()) error("스택 공백 에러");
		return data[top--];
	}

	int peek() {
		if (isEmpty()) error("스택 공백 에러");
		return data[top];
	}

	void display() { //스택의 내용을 화면에 출력
		printf("[스택 항목의 수 = %2d] ==> ", top + 1);
		for (int i = 0; i <= top; i++) {
			printf("<%2d>", data[i]);
		}
		printf("\n");
	}

	int size() { //스택의 top반환
		printf("[스택 항목의 수 = %2d] ==> ", top + 1);
	}

};