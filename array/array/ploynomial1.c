/// <summary>
/// 다항식 덧셈 프로그램 #1
/// 차수의 계수값을 배열에 저장하는 방식
/// </summary>

#include <stdio.h>
#define MAX(a,b)	a>b?a:b
#define MAX_DEGREE 101

typedef struct {
	int degree;	//다항식의 차수
	float coef[MAX_DEGREE];
} polynomial;

// C = A+B 여기서 A와 B는 다항식이다. 구조체가 반환된다
polynomial poly_add1(polynomial A, polynomial B) {
	polynomial C;	//결과 다항식 저장 다른 방식으로는 return을 쓰는 방법이 있을까?
	//MAX비교 하려면 필요하다.
	int Apos = 0, Bpos = 0, Cpos = 0; //배열 인덱스 변수
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree); //결과 다항식 차수
	//둘 중 가장 큰 차수 찾기

	while (Apos <= A.degree && Bpos <= B.degree){ //A항 > B항
		if (degree_a > degree_b) {
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--; //차수를 줄여나간다
		}
		else if (degree_a == degree_b) { //A항 == B항
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++]; //같은 항끼리 더하기
			degree_a--;
			degree_b--;
		}
		else {
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
}

void print_poly(polynomial p) {
	for (int i = p.degree; i > 0; i--) {
		printf("%3.1fx^%d + ", p.coef[p.degree - i], i); //%3.1f  3=오른쪽 정렬을 위한 숫자, 0.1은 소수점 1자리 출력을 위한 숫자
	}
	printf("%3.1f \n", p.coef[p.degree]);
}

int main() {
	polynomial a = { 5, { 3, 6, 0, 0, 0, 10 } };
	polynomial b = { 4, { 7, 0, 5, 0, 1 } };

	print_poly(a);
	print_poly(b);
	polynomial c = poly_add1(a, b);
	printf("-------------------------------------------\n");
	print_poly(c);
	return 0;
}