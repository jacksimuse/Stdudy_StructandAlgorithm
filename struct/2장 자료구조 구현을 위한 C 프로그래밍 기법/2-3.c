#include <stdio.h>

void main()
{
	int i = 0, n;
	
	while (1) {

		printf("\n1~9�� ������ �Է��ϼ��� : ");

		scanf("%d", &n);

		for (i = 0; i < 9; i++)
		{
			printf("%d x %d = %d\n", n, i + 1, n * (i + 1));
		}

		printf("��� / ������ : 1 / 2 �߿� �����ּ���");

		scanf("%d", &n);

		if (n == 2) break;
	}
}