#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char bin[20];
	char nbin[20];
	int shift;
	int vec;

	printf("이진수를 입력하세오: ");
	scanf("%s", bin);
	printf("회전 비트수를 입력하시오: ");
	scanf("%d", &shift);
	printf("회전 방향을 입력하시오(왼쪽:-1, 오른쪽:1): ");
	scanf("%d", &vec);

	switch (vec)
	{
	//왼쪽으로 회전
	case -1:
		for (int i = 0; i < strlen(bin)-shift; i++)
		{
			nbin[i] = bin[i + shift];
		}
		for (int i = 0; i < shift; i++)
		{
			nbin[strlen(bin) - shift+i] = bin[i];
		}
		nbin[strlen(bin)] = NULL;
		printf("원형 회전한 결과는 %s\n", nbin);
		break;
	//오른쪽으로 회전
	case 1:
		for (int i = 0; i < strlen(bin)-shift; i++)
		{
			nbin[i+shift] = bin[i];
		}
		for (int i = 0; i < shift; i++)
		{
			nbin[i] = bin[strlen(bin) - shift+i];
		}
		nbin[strlen(bin)] = NULL;
		printf("원형 회전한 결과는 %s\n", nbin);
		break;
	default:
		puts("잘못입력하셨습니다.");
		break;
	}

}