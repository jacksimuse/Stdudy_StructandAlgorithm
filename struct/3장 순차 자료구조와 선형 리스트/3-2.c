#include <stdio.h>

void main() {
	int i, n = 0, * ptr;
	int sale[2][4] = { {63, 84, 140, 130},
					   {157, 209, 251, 312} };
	ptr = &sale[0][0];
	int(*pptr)[4] = &sale;
	int** pptr2 = sale;
	for (i = 0; i < 8; i++)
	{
		printf("\n address : %u sale %d = %d", ptr, i, *ptr); // 2���� �迭�ε� �Ϲ� �����͸� ����ؼ� 
		ptr++;
	}
	printf("\n");
	printf("%d\n", pptr[1][1]); // 2���� �迭�� ����� �ȵ�
	printf("%u\n", pptr+1); // pptr = [0][0] pptr +1 = [1][0]
	printf("%u\n", *pptr2); // pptr2 ->sale, *pptr2 -> sale[0]
	printf("%d\n", pptr2); // ���������Ͱ� �迭 �����ʹ� ����
	printf("%d\n", pptr2+1);
	/*printf("%u\n", **pptr2);
	printf("%u\n", **pptr2);*/
	//printf("%d\n", pptr[1][1]);
	getchar();

}