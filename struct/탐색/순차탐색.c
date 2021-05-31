#include <stdio.h>

int LSearch(int* pary, int sz, int tg)
{
	for (int i = 0; i < sz; i++) {
		if (pary[i] == tg) return i + 1;
	}
	return -1;
}
int main()
{
	int ary[] = { 3, 5, 8, 2, 7, 6, 1 };
	int size = sizeof(ary) / sizeof(ary[0]); // intũ�� X ��� / int ��ĭ ũ�� = 4 X 7 / 4 = 7
	int index;
	index = LSearch(ary, size, 2);
	if (index == -1) printf("ã�� ����!!\n");
	else printf("�˻���� %d��°�� �ֽ��ϴ�.\n", index);
	return 0;
}