#include <stdio.h>
#include<stdlib.h>
//==== ����ť �ڵ� ���� ====
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {	//ťŸ��
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

//�����Լ�
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//�ʱ�ȭ
void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}

//���� ���� ���� �Լ�
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

// ��ȭ ���� ���� �Լ�
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
	//�ε��� 0�� ������� �ʾұ� ������ rear�� +1��ŭ �ʿ�
	//front�� 0�̰� rear % ��ü���� 0�� ��
	//��, rear�� �ε��� ���� �������� �� ��ȭ���¶� ���
}

// ����ť ��� �Լ�
void queue_print(QueueType* q) {
	printf("QUEUE( front = %d	rear = %d ) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d  |  ", q->data[i]); //front���� rear���� ���
			if (i == q->rear) break; //rear�� ���� �����ϸ� �ݺ��� ����
		} while (i != q->front);
	}
	printf("\n");
}

//�����Լ�
void enqueue(QueueType* q, element item) {
	if (is_full(q)) error("ť�� ��ȭ�����Դϴ�.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; //MAX % MAX = 0
	//����ť�� �迭�� �� ���� ó������ �ٽ� ���ư����ϱ� ����!
	//if���� ����� �ڵ� ���̸� ������ ���� ������ �����ڸ� ����ϴ°�
	// �� ȿ�����̴�
	q->data[q->rear] = item;
}

//�����Լ�
element dequeu(QueueType* q) {
	if (is_empty(q)) error("ť�� ��������Դϴ�.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;	//ť�� ���ð� �ٸ���
	//���� ���� �� ��Ҹ� ���� ���� ������ ������ rear�� ���� ������� �����δ�.
	return q->data[q->front];
}

//top Ȯ�� �Լ�
element peek(QueueType* q) {
	if (is_empty(q)) error("ť�� ��������Դϴ�.");
	return ((q->front + 1) % MAX_QUEUE_SIZE);
	//���� ���� ������ �� ���� ť�� �ε��� 0�� ����α� ����
}
//==== ����ť �ڵ� �� ====
int main() {
	QueueType queue;
	int element = 0;

	init_queue(&queue);
	printf("--������ �߰� �ܰ�--\n");
	while (!is_full(&queue)) {
		printf("������ �Է��Ͻÿ�: ");
		scanf_s("%d", &element);
		enqueue(&queue, element);
		queue_print(&queue);
	}
	printf("ť�� ��ȭ�����Դϴ�.\n\n");

	printf("--������ ���� �ܰ�--\n");
	while (!is_empty(&queue)) {
		element = dequeu(&queue);
		printf("������ ����: %d \n", element);
		queue_print(&queue);
	}
	printf("ť�� ��������Դϴ�.\n");
	return 0;
}