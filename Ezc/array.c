#include<stdio.h>

int main(void)
{
	int subway_array[3];
	subway_array[0] = 30;
	subway_array[1] = 40;
	subway_array[2] = 50;
	
	for (int i = 0; i < 3; i++)
	{
		printf("%d\n",subway_array[i]);
	}
	
	for (int i = 0; i < 128; i++)
	{
		printf("아스키코드 정수 %d : %c\n", i, i);
	}
	
	
	
	return 0;
}