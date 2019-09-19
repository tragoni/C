#include <stdio.h>                                           // "stdio.h" 헤더파일 선언
#define PI 3.14f                                             // 매크로 상수 정의

int main(void)                                               // main 함수, 프로그램의 본체
{
	char c = 'A';
	int n = 5;
	double d = 5.0;
	float f = 1.1f;
	long int lnData = 10L;
	unsigned int unData = 1U;
	unsigned long int ulnData = 1UL;

	printf("%c is character\n", c);                       // %c는 문자출력 Conversion Specification
	printf("%d is integer\n", n);                         // %d는 정수출력 Conversion Specification
	printf("%f is decimal\n", d);                         // %f는 소수출력 conversion Specification
	printf("%p is address\n", &n);                        // %p는 주소출력 conversion Sepcification
	printf("%d, %d, %d\n\n", 10, 010, 0x10);              // 진수 표기법

	printf("\'  \"  \\  \?  \n");                         // Escape Sequence
	printf("%d %d\n", '\177', '\x7F');                    // Escape Sequence
	printf("Helloa\b \teveryone \vHi\n");                 // Escape Sequence
	printf("ABCD\rEFGH\n\n");                             // Escape Sequence

	return 0;                                             // main 함수 종료
}

