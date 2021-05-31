/* �������� : �ι�° �ڷ���� �� �ڷḦ ���Ͽ� �����Ѵ�.*/
#include <stdio.h>

void insertionSort(int*, int);
void print(int*, int);

int main()
{
	int ary[] = { 4, 2, 7, 5, 9, 1, 8, 3, 6 };
	int size = sizeof(ary) / sizeof(ary[0]);
	insertionSort(ary, size);
	return;
}

void insertionSort(int* pary, int sz)
{
	int temp;
	for (int i = 1; i < sz; i++) // �ι�°�ڸ����� ���ڸ��� ���ؼ� i = 1 �� ����
	{
		for (int j = i; j > 0; j--) // ����ǰ� �ִµ����� �� �ձ��� �񱳸� ����ߵǼ� j--,
		{						    // �ι�°���� �����ؼ� j - 1�� �����Ƿ� j > 0
			if (pary[j - 1] > pary[j]) { // ���ڸ��� ���ݺ��� ũ�� ����
				temp = pary[j];
				pary[j] = pary[j - 1];
				pary[j - 1] = temp;
			}
		}
		printf("\n%d�ܰ� : ", i);
		for (int k = 0; k < sz; k++)
		{
			printf("%d  ", pary[k]);
		}
	}
}
void print(int* pary, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("apr[%d] = %d  \n", i, pary[i]);
	}
}