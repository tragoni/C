#include <stdio.h>

int main(void)
{
	/*  �⺻���� �ݺ��� ����
	for (int i = 1; i <= 10; i++)
	{
		printf("for %d\n",i);
	}

	int i = 1;
	while (i <= 10)
	{
		printf("while %d\n", i);
		i++;
	}

	do {
		printf("do while %d\n", i);
		i++;
	} while (i <= 20);

	for (int i = 1; i <= 3; i++)
	{
		printf("ù�� : %d\n", i);

		for (int j = 1; j <= 5; j++)
		{
			printf("	�ι� : %d\n", j);
		}

	}*/

	/*ex)������
	for (int i = 2; i <= 9; i++)
	{
		printf("%d ��\n", i);
		for (int j = 1; j <= 9; j++)
		{
			printf("%d x %d = %d\n", i, j, i*j);
		}
	}*/

	/*	�Ƕ�̵� ���
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");

	}*/

	/*������ ���� �Ƕ�̵�
	for (int i = 0; i < 5; i++)
	{
		for (int j = 1; j < 5 - i; j++)
		{
			printf(" ");
		}

		for (int j = 0; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");

	}*/



	/* �Ųٷ�
	for (int i = 5; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	*/

	/*ž�ױ�*/
	int floor;
	printf("�� �� : ");
	scanf("%d", &floor);

	for (int i = 0; i < floor; i++)
	{
		for (int k = i; k < floor; k++)
		{
			printf(" ");
		}
		for (int j = 0; j<2*i+1; j++)
		{
			printf("*");	
		}
		printf("\n");
	}


	return 0;
}