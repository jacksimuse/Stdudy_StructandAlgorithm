#include <stdio.h>

int BSearch(int* pary, int sz, int tg)
{
	for (int i = 0; i < sz; i++)
	{
		int first = 0;
		int last = sz - 1;
		int mid;
		while (first <= last) { // ��� ������ ������ ���ҰŶ� ù��°�� �������� ������������ �ݺ���
			mid = (first + last) / 2; // �߰����� mid�� ����
			if (tg == pary[mid]) return mid; // �˻����� �߰���ġ�� �߰� ��ġ ��ȯ
			else {
				if (tg > pary[mid]) first = mid + 1; // �˻����� �߰���ġ���� ũ�� �˻������� ������ ������ ù��°�� �߰� �ں��� ������
				else last = mid - 1; // �˻����� �߰���ġ���� ������ ������ ������ �ǵڴ� �߰� ���ڸ��� ������
			}
		}
	}
	return -1;
}

int main()
{
	int ary[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int size = sizeof(ary) / sizeof(ary[0]);
	int index;

	index = BSearch(ary, size, 1);
	if (index == -1) printf("Ž�� ����!!\n");
	else printf("ã�� ���� %d��° �ֽ��ϴ�.\n", index + 1);

	return 0;
}