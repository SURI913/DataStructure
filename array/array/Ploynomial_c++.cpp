#include "Ploynomial.h"
int main() {
	Polynomial a, b, c;
	a.read();
	b.read();
	c.add(a, b); //c=a+b
	a.dispaly("A = "); // a���׽� ���
	b.dispaly("B = "); //b���׽� ���
	c.dispaly("A+B = ");	//c=a+b ���׽� ���
	c.trim();
	return 0;
}