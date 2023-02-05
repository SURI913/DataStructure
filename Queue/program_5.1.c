#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
}QueueType;

//오류함수
void error(char* message) {
	fprintf(stderr, "% s\n", message);
	exit(1);
}

void init_queue(QueueType* q) { //큐 초기화
	q->front = -1;
	q->rear = -1;
}

void queue_print(QueueType* q) { //표 출력 함수
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (i <= q->front || i > q->rear)
			printf("   | "); //공백 표시 주의 3|1
		else
			printf("%d | ", q->data[i]); //공백 표시 주의 1|1
	}
	printf("\n");
}

int is_full(QueueType* q) {
	if (q->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	else
		return 0;
}

int is_empty(QueueType* q) {
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

void enqueue(QueueType* q, int item) {	//삽입
	if (is_full(q)) {
		error("큐가 포화상태입니다.");
		return;
	}
	q->data[++(q->rear)] = item;
}

int dequeue(QueueType* q) {	//삭제
	if (is_empty(q)) {
		error("큐가 공백상태입니다.");
		return -1;
	}
	int item = q->data[++(q->front)];
	return item;
}

int main() {
	int item = 0;
	QueueType q;
	init_queue(&q);

	enqueue(&q, 10);	
	queue_print(&q);
	enqueue(&q, 20);
	queue_print(&q);
	enqueue(&q, 30);
	queue_print(&q);

	item = dequeue(&q);
	queue_print(&q);
	item = dequeue(&q);
	queue_print(&q);
	item = dequeue(&q);

	return 0;
}