#include <stdio.h>

int main(void)
{
	/*  기본적인 반복문 종류
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
		printf("첫반 : %d\n", i);

		for (int j = 1; j <= 5; j++)
		{
			printf("	두반 : %d\n", j);
		}

	}*/

	/*ex)구구단
	for (int i = 2; i <= 9; i++)
	{
		printf("%d 단\n", i);
		for (int j = 1; j <= 9; j++)
		{
			printf("%d x %d = %d\n", i, j, i*j);
		}
	}*/

	/*	피라미드 출력
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");

	}*/

	/*오른쪽 정렬 피라미드
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



	/* 거꾸로
	for (int i = 5; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	*/

	/*탑쌓기*/
	int floor;
	printf("몇 층 : ");
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