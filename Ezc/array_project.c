#include <stdio.h>
#include<time.h>
#include <stdlib.h>

// 4���� ������ ���� ���� 1���� ����
// 4���� ������ 2 ~ 3 ������ ���� �����ָ鼭 ��������- 2������
// �� 3�� ������ �����ִ� �������� ���� ������ �������� ������ȵ�-
// 

int main(void)
{
	srand(time(NULL)); //���� �ʱ�ȭ
	int answer; //����� ����
	int treatment = rand() % 4; //ġ���� ��ȣ (0~3)
	int ncntbottle = 0; //������ ���� ����
	int cntbottle = 0;//������ ���� ����

	printf("---------- ���� ----------\n\n");
	for (int i = 1; i <= 3; i++) //�� ����Ƚ�� 3ȸ
	{
		int bottle[4] = { 0 };  //4���� ���� ���� + 0���� �ʱ�ȭ

		do {
			ncntbottle = rand() % 2 + 2;	//������ ���హ�� 
		} while (ncntbottle == cntbottle);
		cntbottle = ncntbottle;

		int bottlenum = 0; //������ŭ ������ �����ֱ����� ����

		do {
			int randbottle = rand() % 4; // ������ ���� ��ȣ�� ���� 0~3
				if (bottle[randbottle] == 0)
				{
					bottle[randbottle] = 1;
					bottlenum++;
				}
		} while (bottlenum<ncntbottle);

		printf("===================\n");
		printf(" >> ");
		for (int k = 0; k < sizeof(bottle) / 4; k++) //���� ������
		{
			if (bottle[k] == 1)
			{
				printf("%d�� ",k+1);
			}
		}
		printf("�� ����.\n");
		if (bottle[treatment] == 1)		//������ ġ���� ���� ����
		{
			printf("ȿ������!!\n\n");
		}
		else
		{
			printf("ȿ������ �̤�\n\n");
		}
		printf("����Ϸ��� �ƹ�Ű�� ��������\n\n"); //pause
		getchar();
	}

	printf("ġ������ ���? >> "); //������߱�
	scanf_s("%d", &answer);

	if (treatment + 1 == answer) //����Ȯ��
	{
		printf("�����Դϴ�!!!\n\n");
	}
	else
	{
		printf("������ �ƴմϴ�...\n\n");
	}

	return 0;
}