/* �� ���� : ��ǥ���� ���� ���� �˰���
	������ �Ǿ� �������� �������� ����ϸ� ������.
	1. ���ҵ� �߿��� pivot�� ����.
	2. �� pivot�� �������� �տ��� ���� ��, �ڿ��� ū ������ ��ġ��Ų��. (����)
	3. ���ҵ� ���� ����Ʈ�� ��������� ���� ��Ų��. (����)
	4. ���ĵ� ���� ����Ʈ���� �����Ѵ�. (����)
*/
#include <stdio.h>

void quickSort(int*, int, int);

int main() 
{
	int ary[] = { 4, 2, 7, 5, 9, 1, 8, 3, 6 };
	int size = sizeof(ary) / sizeof(ary[0]);
	quickSort(ary, 0, size - 1);
	
	return 0;
}
void quickSort(int* pary, int left, int right)
{
	int lidx = left, ridx = right;
	int temp;
	int pivot = (left + right) / 2;
	printf("pivot - index : %d, value : %d\n", pivot, pary[pivot]);
	while (lidx <= ridx)
	{
		while (pary[lidx] < pary[pivot]) lidx++;
		while (pary[ridx] > pary[pivot]) ridx--;
		if (lidx <= ridx) {
			temp = pary[ridx];
			pary[ridx] = pary[lidx];
			pary[lidx] = temp;
			printf("%d : %d\n", temp, pary[ridx]);
			lidx++;
			ridx--;
		}
	}
	for (int i = 0; i <= right; i++) printf("%3d", pary[i]);
	printf("\n");
	if (left < ridx) quickSort(pary, left, ridx);
	if (lidx < right) quickSort(pary, lidx, right);
	
}