//���ϸ�: Polynomial.h
#include <cstdio> //iostream�� ������ �ȵǴ°�?

#define MAX_DEGREE 80 //���׽��� ó�� ������ �ִ� ���� +1
class Polynomial {
	int degree;	//���׽� �ְ� ����
	float coef[MAX_DEGREE]; //�� �׿� ���� ���
public:
	Polynomial() { degree = 0; }	//������: �ִ� ������ 0���� �ʱ�ȭ

	// ���׽��� ������ �Է¹޴� ����Լ�
	void read() {
		printf("���׽��� �ְ� ������ �Է��Ͻÿ�: ");
		scanf_s("%d", &degree);
		printf("�� ���� ����� �Է��Ͻÿ� (�� %d��): ", degree + 1);
		for (int i = 0; i <= degree; i++) {
			scanf_s("%f", coef + i);
		}
	}
	// ���׽��� ������ ȭ�鿡 ����ϴ� �Լ�
	void dispaly(const char* str = " Poly = ") {
		printf("\t%s", str);
		for (int i = 0; i < degree-1; i++) {
			if (coef[i] == 0) {
				continue;
			}
			else {
				printf("%5.1f x^%d + ", coef[i], degree - i);
			}
		}
		printf("%5.1f x^0 + ", coef[degree - 1], degree);
		printf("%4.1f\n", coef[degree]);
	}

	//���׽� a�� b�� ���ϴ� �Լ�. a�� b�� ���� �ڽ��� ���׽� ����.
	void add(Polynomial a, Polynomial b) {
		if (a.degree > b.degree) { //a��  > b��
			*this = a;	//a ���׽��� �ڱ� ��ü�� ����
			for (int i = 0; i <= b.degree; i++)
				coef[i + (degree - b.degree)] += b.coef[i];
		}
		else {	//a�� <= b��
			*this = b;	//b ���׽��� �ڽſ� ����
			for (int i = 0; i <= a.degree; i++)
				coef[i + (degree - a.degree)] += a.coef[i];
		}
	}

	//���׽� a�� b�� ���� �Լ�. a�� b�� �� �ڽ��� ���׽� ����.
	void sub(Polynomial a, Polynomial b) {
		if (a.degree > b.degree) { //a��  > b��
			*this = a;	//a ���׽��� �ڱ� ��ü�� ����
			for (int i = 0; i <= b.degree; i++)
				coef[i + (degree - b.degree)] -= b.coef[i];
		}
		else {	//a�� <= b��
			*this = b;	//b ���׽��� �ڽſ� ����
			for (int i = 0; i <= a.degree; i++)
				coef[i + (degree - a.degree)] -= a.coef[i];
		}
	}

	//���׽� a�� b�� ���ϴ� �Լ�. a�� b�� ���� �ڽ��� ���׽� ����.
	void mult(Polynomial a, Polynomial b) {
		for (int i = 0; i <= b.degree; i++)
			coef[i + (degree - b.degree)] *= b.coef[i];
	}

	void trim() {
		printf("A + B = ");
		for (int i = 0; i < degree-1; i++) {
			if (coef[i] == 0) {
				continue;
			}
			else {
				printf("%5.1f x^%d + ", coef[i], degree - i);
			}
		}
		printf("%5.1f x^0 + ", coef[degree-1]);
		printf("%4.1f\n", coef[degree]);

	}

	bool isZero() { return degree == 0; }	//�ְ������� 0�ΰ�?
	void negate() {	//��� ����� ��ȣ�� �ٲ�
		for (int i = 0; i < degree; i++)
			coef[i] = -coef[i]; //����� ��ȣ�� �ٲ�
	}
};
