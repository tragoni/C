#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char str[256];
	int keyy=23;
	int enkey=0;


	printf("문자열을 입력하시오: ");
	gets(str);
	printf("암호화 키값을 입력하시오(0-255): ");
	scanf("%d", &keyy);
	printf("%d", keyy);
	for (int i = 0; i < strlen(str); i++)
	{
		str[i] ^= keyy;
	}
	printf("암호화된 문자열: %s\n",str);

	printf("복호화 키값을 입력하시오(0-255): ");
	getchar();
	scanf("%d", &enkey);
	for (int i = 0; i < strlen(str); i++)
	{
		str[i] ^= enkey;
	}
	printf("복호화된 문자열: %s\n", str);

	return 0;
}