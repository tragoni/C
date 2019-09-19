#include <stdio.h>

int main(void)
{
	/*int one, two, three;
	printf("3개의 정수를 입력하시오 : ");
	scanf_s("%d %d %d", &one, &two, &three);
	printf("%d %d %d\n", one, two, three);*/

	/*char c = 'a';
	printf("%c\n", c);
	
	char str[256];
	scanf_s("%s", str,sizeof(str));*/

	// 이름 나이 몸무게 키 하고싶은말
	char name[256];
	int age;
	float weight;
	double height;
	char comment[256];

	printf("이름 ");
	scanf_s("%s", name, sizeof(name));
	printf("나이 ");
	scanf_s("%d", &age);
	printf("몸무게 ");
	scanf_s("%f", &weight);
	printf("키 ");
	scanf_s("%lf", &height);
	printf("코멘트 ");
	scanf_s("%s", comment, sizeof(comment));

	printf("%s %d %f %.1lf %s\n", name, age, weight, height, comment);


	return 0;
}