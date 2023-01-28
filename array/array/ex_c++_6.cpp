#include <iostream>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;

	//Çà¿­ ¹è¿­
	//2Â÷¿ø ¹è¿­ µ¿Àû ÇÒ´ç ¹æ¹ý
	int** array1 = new int* [N] { 0 }; //2Â÷¿ø ¹è¿­ÀÇ ¿­ÀÇ ¼ö¸¸Å­ µ¿Àû ÇÒ´ç
	for (int i = 0; i < N; i++) { //¿­ÀÇ ¼ö¸¸Å­ µ¿Àû ÇÒ´ç.
		array1[i] = new int[M]; //ÇàÀ¸·Î ¾µ ÀÎµ¦½º¿¡ Çà¸¸Å­ µ¿ÀûÇÒ´çÇÑ´Ù
	}

	//Àü¯†Çà¿­¹è¿­ µ¿ÀûÇÒ´ç
	int** array2 = new int* [N] { 0 };
	for (int i = 0; i < N; i++) {
		array2[i] = new int[M];
	}

	//¹è¿­ °ª input ¹Þ¾Æ Çà¿­ ¹è¿­ ÃÊ±âÈ­
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> array1[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			array2[j][i] = array1[i][j];
			cout << array2[j][i] << " ";
		}
		cout << endl;
	}

	//¹è¿­ ÇÒ´ç ÇØÁ¦
	for (int i = 0; i < N; i++) { //¿­ ÇØÁ¦
		delete[] array1[i];
	}
	delete[] array1; //Çà ÇØÁ¦

	for (int i = 0; i < N; i++) {
		delete[] array2[i];
	}
	delete[] array2;
	return 0;
}