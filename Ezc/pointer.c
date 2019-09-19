#include <stdio.h>

void swap(int a, int b);

int main(void)
{
	/*int 철수 = 1;
	int 영희 = 2;
	int 민수 = 3;

	int *미션맨;
	미션맨 = &철수;
	printf("미션맨이 방문한곳 주소 : %d, 암호 : %d\n", 미션맨, *미션맨);*/

	//swap 
	int a = 10;
	int b = 20;
	//a 와 b 의 값을 바꾼다.
	printf("Swap 함수전 -> a : %d, b : %d\n", a, b);
	swap(&a, &b);
	printf("Swap 함수후 -> a : %d, b : %d\n", a, b);
	return 0;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("Swap 함수내 -> a : %d, b : %d\n", a, b);
}