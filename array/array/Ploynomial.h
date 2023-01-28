//파일명: Polynomial.h
#include <cstdio> //iostream이 적용이 안되는가?

#define MAX_DEGREE 80 //다항식의 처리 가능한 최대 차수 +1
class Polynomial {
	int degree;	//다항식 최고 차수
	float coef[MAX_DEGREE]; //각 항에 대한 계수
public:
	Polynomial() { degree = 0; }	//생성자: 최대 차수를 0으로 초기화

	// 다항식의 내용을 입력받는 멤버함수
	void read() {
		printf("다항식의 최고 차수를 입력하시오: ");
		scanf_s("%d", &degree);
		printf("각 항의 계수를 입력하시오 (총 %d개): ", degree + 1);
		for (int i = 0; i <= degree; i++) {
			scanf_s("%f", coef + i);
		}
	}
	// 다항식의 내용을 화면에 출력하는 함수
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

	//다항식 a와 b를 더하는 함수. a와 b를 더해 자신의 다항식 설정.
	void add(Polynomial a, Polynomial b) {
		if (a.degree > b.degree) { //a항  > b항
			*this = a;	//a 다항식을 자기 객체에 복사
			for (int i = 0; i <= b.degree; i++)
				coef[i + (degree - b.degree)] += b.coef[i];
		}
		else {	//a항 <= b항
			*this = b;	//b 다항식을 자신에 복사
			for (int i = 0; i <= a.degree; i++)
				coef[i + (degree - a.degree)] += a.coef[i];
		}
	}

	//다항식 a와 b를 빼는 함수. a와 b를 빼 자신의 다항식 설정.
	void sub(Polynomial a, Polynomial b) {
		if (a.degree > b.degree) { //a항  > b항
			*this = a;	//a 다항식을 자기 객체에 복사
			for (int i = 0; i <= b.degree; i++)
				coef[i + (degree - b.degree)] -= b.coef[i];
		}
		else {	//a항 <= b항
			*this = b;	//b 다항식을 자신에 복사
			for (int i = 0; i <= a.degree; i++)
				coef[i + (degree - a.degree)] -= a.coef[i];
		}
	}

	//다항식 a와 b를 곱하는 함수. a와 b를 곱해 자신의 다항식 설정.
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

	bool isZero() { return degree == 0; }	//최고차수가 0인가?
	void negate() {	//모든 계수의 부호를 바꿈
		for (int i = 0; i < degree; i++)
			coef[i] = -coef[i]; //계수의 부호를 바꿈
	}
};
