/* �������� : 0������ �ּҰ��̶�� �����Ѵ�.*/
#include <stdio.h>

void selectSort(int*, int);
int main()
{
	int ary[] = { 4, 2, 7, 5, 9, 1, 8, 3, 6 };
	int size = sizeof(ary) / sizeof(ary[0]);
	selectSort(ary, size);
	return 0;
}
void selectSort(int* pary, int size)
{
	int i,j,min,temp;
	for (i = 0; i < size - 1; i++) // size -1 ? 0 ~ size������ �迭�� ���
	{
		min = i; // �ּڰ���°�� i��°�� ��
		for (j = i + 1; j < size; j++) { // �ι�°���� ���ϴ� i + 1
			if (pary[min] > pary[j]) min = j; // �۴ٰ� �����Ѱ� j��°���� ũ�� j��°�� ���� ��°�� ��
		}
		temp = pary[min]; // �ش��° ��Ҹ� ����
		pary[min] = pary[i];
		pary[i] = temp;
		printf("\n%d �ܰ� : ", i + 1);
		for (int k = 0; k < size; k++)
		{
			printf("%d  ", pary[k]);
		}
	}
}