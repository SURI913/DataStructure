#include <cstdio>
using namespace std;
class Complex {
	int real;
	int imag;
public:
	Complex (int r = 0, int i = 0) : real{r}, imag{i} { }
	int getReal() { return real; }
	int getImag() { return imag; }
	void setReal(int r) { real = r; }
	void setImag(int i) { imag = i; }

	friend void display(Complex other);
	
	Complex operator+ (const Complex& other) { return Complex(this -> real + other.real, this-> imag + other.imag); }
	Complex operator- (const Complex& other) { return Complex( this -> real - other.real, this-> imag - other.imag); }
};

inline void display(Complex other) {
	if (other.real < 0 || other.imag < 0) {
		if (other.real < 0) {
			printf("(%d)+%d+i\n", other.real, other.imag);
		}
		else if (other.getImag() < 0) {
			printf("%d+(%d)+i\n", other.real, other.imag);
		}
		else {
			printf("(%d)+(%d)+i\n", other.real, other.imag);
		}
	}
	else {
		printf("%d+%d+i\n", other.real, other.imag);
	}
}