#include<stdio.h>
#include<time.h>

int main_firewolf()
{
	srand(time(NULL));
	
	int c[10] = { 0 };
	int sum = 0;

	while (1)
	{
		int count = 1;
		printf("�� ");

		while (1)
		{
			int i = rand() % 3;
			if (i == 1)
			{
				printf("�� ");
				count++;
			}
			else
			{
				c[count - 1]++;
				break;
			}
		}
		printf("\n");
		sum++;
		if (count > 10)
		{
			count = 10;
		}
		for (int i = 0; i < 10; i++)
		{
			printf("%4dȸ",i + 1);
		}
		printf("\n");
		for (int i = 0; i < 10; i++)
		{
			printf("[%4d]", c[i]);
		}
		printf("\n");
		for (int i = 0; i < 10; i++)
		{

			printf("[%.1lf%%]",c[i]/(float)(sum)*100);
		}
		
		printf("\n\n��Ƚ�� : %d  %dȸ ����Ϸ��� �ƹ�Ű�� ��������.",sum,count);
		getchar();
	}

}