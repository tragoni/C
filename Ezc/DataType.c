#include <stdio.h>                                           // "stdio.h" ������� ����
#define PI 3.14f                                             // ��ũ�� ��� ����

int main(void)                                               // main �Լ�, ���α׷��� ��ü
{
	char c = 'A';
	int n = 5;
	double d = 5.0;
	float f = 1.1f;
	long int lnData = 10L;
	unsigned int unData = 1U;
	unsigned long int ulnData = 1UL;

	printf("%c is character\n", c);                       // %c�� ������� Conversion Specification
	printf("%d is integer\n", n);                         // %d�� ������� Conversion Specification
	printf("%f is decimal\n", d);                         // %f�� �Ҽ���� conversion Specification
	printf("%p is address\n", &n);                        // %p�� �ּ���� conversion Sepcification
	printf("%d, %d, %d\n\n", 10, 010, 0x10);              // ���� ǥ���

	printf("\'  \"  \\  \?  \n");                         // Escape Sequence
	printf("%d %d\n", '\177', '\x7F');                    // Escape Sequence
	printf("Helloa\b \teveryone \vHi\n");                 // Escape Sequence
	printf("ABCD\rEFGH\n\n");                             // Escape Sequence

	return 0;                                             // main �Լ� ����
}

