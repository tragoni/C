#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char bin[20];
	char nbin[20];
	int shift;
	int vec;

	printf("�������� �Է��ϼ���: ");
	scanf("%s", bin);
	printf("ȸ�� ��Ʈ���� �Է��Ͻÿ�: ");
	scanf("%d", &shift);
	printf("ȸ�� ������ �Է��Ͻÿ�(����:-1, ������:1): ");
	scanf("%d", &vec);

	switch (vec)
	{
	//�������� ȸ��
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
		printf("���� ȸ���� ����� %s\n", nbin);
		break;
	//���������� ȸ��
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
		printf("���� ȸ���� ����� %s\n", nbin);
		break;
	default:
		puts("�߸��Է��ϼ̽��ϴ�.");
		break;
	}

}