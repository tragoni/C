#include <stdio.h>

int main(void)
{
	/*int one, two, three;
	printf("3���� ������ �Է��Ͻÿ� : ");
	scanf_s("%d %d %d", &one, &two, &three);
	printf("%d %d %d\n", one, two, three);*/

	/*char c = 'a';
	printf("%c\n", c);
	
	char str[256];
	scanf_s("%s", str,sizeof(str));*/

	// �̸� ���� ������ Ű �ϰ������
	char name[256];
	int age;
	float weight;
	double height;
	char comment[256];

	printf("�̸� ");
	scanf_s("%s", name, sizeof(name));
	printf("���� ");
	scanf_s("%d", &age);
	printf("������ ");
	scanf_s("%f", &weight);
	printf("Ű ");
	scanf_s("%lf", &height);
	printf("�ڸ�Ʈ ");
	scanf_s("%s", comment, sizeof(comment));

	printf("%s %d %f %.1lf %s\n", name, age, weight, height, comment);


	return 0;
}