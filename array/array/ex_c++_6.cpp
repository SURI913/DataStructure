#include <iostream>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;

	//�࿭ �迭
	//2���� �迭 ���� �Ҵ� ���
	int** array1 = new int* [N] { 0 }; //2���� �迭�� ���� ����ŭ ���� �Ҵ�
	for (int i = 0; i < N; i++) { //���� ����ŭ ���� �Ҵ�.
		array1[i] = new int[M]; //������ �� �ε����� �ุŭ �����Ҵ��Ѵ�
	}

	//�����࿭�迭 �����Ҵ�
	int** array2 = new int* [N] { 0 };
	for (int i = 0; i < N; i++) {
		array2[i] = new int[M];
	}

	//�迭 �� input �޾� �࿭ �迭 �ʱ�ȭ
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

	//�迭 �Ҵ� ����
	for (int i = 0; i < N; i++) { //�� ����
		delete[] array1[i];
	}
	delete[] array1; //�� ����

	for (int i = 0; i < N; i++) {
		delete[] array2[i];
	}
	delete[] array2;
	return 0;
}