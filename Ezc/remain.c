
#include <stdio.h>
#include <ctype.h>

void swap(int *a, int *b);

int main(void)
{
	int a = 10, b = 20, c;
	int A[3][2] = { 1,2,3,4,5,6 };
	int *Pa, Pb;
	Pa = &a;
	Pb = &b;
	printf("a = %d\nb= %d\n", a, b);
	swap(Pa, Pb);
	printf("a = %d\nb= %d\n", a, b);

	printf("A[1][0] = %d\n", *(*(A + 1) + 0));
	printf("A[1][1] = %d\n", *(A[1] + 1));
	printf("A[2][1] = %d\n", (*(A + 2))[1]);

	while ((c = getchar()) != EOF)
	{
		if (islower(c))
			c = toupper(c);
		putchar(c);
	}

	return 0;
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}