#include <iostream>
using namespace std;
void hanoiTower(int n, char from, char tmp, char to) {
	if (n == 1) {
		cout << "���� 1�� " << from << "���� "
			<< to << "���� �ű��." << endl;
	}
	else {
		hanoiTower(n - 1, from, to, tmp);
		cout << "���� " << n << "�� " << from << "���� "
			<< to << "���� �ű��." << endl;
		hanoiTower(n - 1, tmp, from, to);
	}
}
int main() {
	hanoiTower(4, 'A', 'B', 'C');
	return 0;
}