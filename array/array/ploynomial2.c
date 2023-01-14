#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101
typedef struct {
	float coef;
	int expon;
}polynomial;

polynomial terms[MAX_TERMS] = { {8, 3}, {7, 1}, {1, 0}, {10, 3}, {3, 2}, {1, 0} };
int avail = 6; //다항식이 끝나는 지점 인덱스, 비어있다.
//A = 8x^3 + 7x+ 1
//B = 10x^3 + 3x^2 + 1

//두 개의 정수를 비교
char compare(int a, int b) {
	if (a > b) return '>';
	else if (a == b) return '=';
	else return '<';
}

//새로운 항을 다항식에 추가한다
void attach(float coef, int expon) {
	if (avail > MAX_TERMS) {//배열 갯수보다 항 오버
		fprintf(stderr, "항의 개수가 너무 많음\n");
		exit(1);
	}
	//여기서 버퍼 오버런 생김. 해결 방법?
	terms[avail].coef = coef; //끝 지점부터
	terms[avail].expon = expon;
	avail++;
}

//C=A+B
void poly_add2(int As, int Ae, int Bs, int Be, int* Cs, int* Ce) {
	float tempcoef;
	*Cs = avail;
	while (As <= Ae && Bs <= Be)
	{
		switch (compare(terms[As].expon, terms[Bs].expon)) { //차수 비교
		case '>':	//A의 차수 > B의 차수
			attach(terms[As].coef, terms[As].expon);
			As++;
			break;

		case '=':	//A의 차수 == B의 차수
			tempcoef = terms[As].coef + terms[Bs].coef; //항이 같으면 더한다
			if (tempcoef) {
				attach(tempcoef, terms[As].expon);
			}
			As++;
			Bs++;
			break;

		case '<':	//A의 차수 < B의 차수
			attach(terms[Bs].coef, terms[Bs].expon);
			Bs++;
			break;
		}
	}
	//나머지 항들을 이동함
	for (; As <= Ae; As++) {
		attach(terms[As].coef, terms[As].expon);
	}
	for (; Bs <= Be; Bs++) {
		attach(terms[Bs].coef, terms[Bs].expon);
	}
	*Ce = avail - 1;
	//더한 차수가 4개라서??
	// 1, x^1, x^2, x^3
}

void print_poly(int s, int e) {
	for (int i = s; i < e; i++) {
		printf("%3.1fx%d + ", terms[i].coef, terms[i].expon);
	}
	printf("%3.1fx%d\n", terms[e].coef, terms[e].expon);
}

int main(void) {
	int As = 0, Ae = 2, Bs = 3, Be = 5, Cs, Ce; //인덱스 위치
	poly_add2(As, Ae, Bs, Be, &Cs, &Ce);
	print_poly(As, Ae);
	print_poly(Bs, Be);
	printf("-----------------------------------------------------------------------------------\n");
	print_poly(Cs, Ce);
	return 0;
}