#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char str[256];
	int keyy=23;
	int enkey=0;


	printf("���ڿ��� �Է��Ͻÿ�: ");
	gets(str);
	printf("��ȣȭ Ű���� �Է��Ͻÿ�(0-255): ");
	scanf("%d", &keyy);
	printf("%d", keyy);
	for (int i = 0; i < strlen(str); i++)
	{
		str[i] ^= keyy;
	}
	printf("��ȣȭ�� ���ڿ�: %s\n",str);

	printf("��ȣȭ Ű���� �Է��Ͻÿ�(0-255): ");
	getchar();
	scanf("%d", &enkey);
	for (int i = 0; i < strlen(str); i++)
	{
		str[i] ^= enkey;
	}
	printf("��ȣȭ�� ���ڿ�: %s\n", str);

	return 0;
}