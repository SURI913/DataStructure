#include <stdio.h>
#include<stdlib.h>
//==== 원형큐 코드 시작 ====
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {	//큐타입
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

//오류함수
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//초기화
void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}

//공백 상태 검출 함수
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
	//인덱스 0은 사용하지 않았기 때문에 rear에 +1만큼 필요
	//front가 0이고 rear % 전체값이 0일 때
	//즉, rear에 인덱스 끝에 도달했을 때 포화상태라 출력
}

// 원형큐 출력 함수
void queue_print(QueueType* q) {
	printf("QUEUE( front = %d	rear = %d ) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d  |  ", q->data[i]); //front부터 rear까지 출력
			if (i == q->rear) break; //rear이 끝에 도달하면 반복문 종료
		} while (i != q->front);
	}
	printf("\n");
}

//삽입함수
void enqueue(QueueType* q, element item) {
	if (is_full(q)) error("큐가 포화상태입니다.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; //MAX % MAX = 0
	//원형큐는 배열이 꽉 차면 처음으로 다시 돌아가야하기 때문!
	//if문을 사용해 코드 길이를 길게잡기 보다 나머지 연산자를 사용하는게
	// 더 효율적이다
	q->data[q->rear] = item;
}

//삭제함수
element dequeu(QueueType* q) {
	if (is_empty(q)) error("큐가 공백상태입니다.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;	//큐는 스택과 다르게
	//가장 먼저 들어간 요소를 가장 먼저 빼내기 때문에 rear과 같은 방법으로 움직인다.
	return q->data[q->front];
}

//top 확인 함수
element peek(QueueType* q) {
	if (is_empty(q)) error("큐가 공백상태입니다.");
	return ((q->front + 1) % MAX_QUEUE_SIZE);
	//스택 마냥 접근할 수 없다 큐는 인덱스 0을 비워두기 때문
}
//==== 원형큐 코드 끝 ====
int main() {
	QueueType queue;
	int element = 0;

	init_queue(&queue);
	printf("--데이터 추가 단계--\n");
	while (!is_full(&queue)) {
		printf("정수를 입력하시오: ");
		scanf_s("%d", &element);
		enqueue(&queue, element);
		queue_print(&queue);
	}
	printf("큐는 포화상태입니다.\n\n");

	printf("--데이터 삭제 단계--\n");
	while (!is_empty(&queue)) {
		element = dequeu(&queue);
		printf("꺼내진 정수: %d \n", element);
		queue_print(&queue);
	}
	printf("큐는 공백상태입니다.\n");
	return 0;
}