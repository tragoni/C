#include <stdio.h>

void swap(int a, int b);

int main(void)
{
	/*int ö�� = 1;
	int ���� = 2;
	int �μ� = 3;

	int *�̼Ǹ�;
	�̼Ǹ� = &ö��;
	printf("�̼Ǹ��� �湮�Ѱ� �ּ� : %d, ��ȣ : %d\n", �̼Ǹ�, *�̼Ǹ�);*/

	//swap 
	int a = 10;
	int b = 20;
	//a �� b �� ���� �ٲ۴�.
	printf("Swap �Լ��� -> a : %d, b : %d\n", a, b);
	swap(&a, &b);
	printf("Swap �Լ��� -> a : %d, b : %d\n", a, b);
	return 0;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("Swap �Լ��� -> a : %d, b : %d\n", a, b);
}