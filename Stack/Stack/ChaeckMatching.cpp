#include "ArrayStack.h"
#include <string>
#define __CRT_SECURE_NO_WARNINGS



bool checkMatching(const char* filename) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) error ("Error: ������ �������� �ʽ��ϴ�.\n");
	int nLine = 1; //���� ������ ����
	int nChar = 0; //���� ���� ����

	ArrayStack stack; //���� ��ü
	char ch;

	while ( (ch == getc(fp)) != EOF ) {
		if (ch == '\n') nLine++;
		nChar++;
		if (ch == '[' || ch == '(' || ch == '{') stack.push(ch);
		else if (ch == '}' || ch == ')' || ch == ']') {
			int prev = stack.pop();
			if ((ch == ']' && prev != '[') || (ch == ')' && prev != '(') || (ch == '}' && prev != '{')) break;
		}
	}
	fclose(fp);
	printf("[%s] ���� �˻���:\n", filename);
	if (!stack.isEmpty())
		printf("Error: �����߰�!(���μ� = %d, ���ڼ� = %d)\n\n", nLine, nChar);
	else
		printf("OK: ��ȣ�ݱ�����(���μ� = %d, ���ڼ� = %d)\n\n", nLine, nChar);
	return stack.isEmpty();
}

void main() {
	checkMatching("�ҽ�.cpp");
	checkMatching("ChechMatching.cpp");
}