#include "Ploynomial.h"
int main() {
	Polynomial a, b, c;
	a.read();
	b.read();
	c.add(a, b); //c=a+b
	a.dispaly("A = "); // a다항식 출력
	b.dispaly("B = "); //b다항식 출력
	c.dispaly("A+B = ");	//c=a+b 다항식 출력
	c.trim();
	return 0;
}