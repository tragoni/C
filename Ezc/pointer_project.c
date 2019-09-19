#include <stdio.h>
#include <time.h>

void interface(); //����� �������̽�
void initfish(); //����� ���� �ʱ�ȭ 100�ֱ�
void declineFish(int level); //�پ��� ����
void levelUp();
int interfish[6]; //����� ����
int deadfish();

long total = 0; //��ü�ð�
long pretotal = 0; //�����ð� -���ð����Ҷ� ���
long pre = 0;	//���ð�
int level = 1; //���ӷ���

int main(void)
{
	int answer; //����� �Է�
	int *point = interfish;
	initfish();
	while (1)
	{
		pretotal = total;
		total = clock();
		pre = total-pretotal;
		printf("\n\n");
		interface();
		printf("\n��ü����ð�: %3d\n", total/1000);
		printf("������ð�: %3d\n", pre/1000);
		levelUp(level);
		printf("��� ����⿡�� ���� �ֽðڽ��ϱ�?(1~6) ");
		scanf_s("%d", &answer);
		if (1 > answer || 6 < answer)
		{
			printf("\n�߸��Է��ϼ̽��ϴ�.\n");
			continue;
		}
		declineFish(level);
		//����⹰�ֱ�
		if (point[answer - 1] <= 0)
		{
			printf("�̹� ���� ������Դϴ�.\n");
		}
		else if (point[answer - 1] < 100)
		{
			printf("%d�� ����⿡�� ���� �ݴϴ�.\n", answer);
			point[answer - 1] += 10;

			if (point[answer - 1] >= 100)
			{
				point[answer - 1] = 100;
			}
		}
		//��� ����Ⱑ �׾����� Ȯ��endgame
		if (deadfish() == 1)
		{
			printf("��� ����Ⱑ �׾����ϴ�. ������ �����մϴ�\n\n");
			exit();
		}

	}
	return 0;
}

void interface()
{
	for (int i = 0; i < 6; i++)
	{
		printf(" [%d]",i+1);
	}
	printf("\n");

	for (int i = 0; i < 6; i++)
	{
		printf("%4d", interfish[i]);
	}
	printf("\n");
}

void initfish()
{
	for (int i = 0; i < 6; i++)
	{
		interfish[i] = 100;
	}
}

void declineFish(int level)
{
	for (int i = 0; i < 6; i++)
	{
		interfish[i] -= (pre/200)*level;
		if (interfish[i] <= 0)
		{
			interfish[i] = 0;
		}
	}
}

void levelUp()
{
	if (((total/1000) / 20) > level - 1)
	{
		level++;
		printf("%d������ ���׷��̵�!!\n", level);
	}
	if (level == 5)
	{
		exit();
		printf("��������\n\n");
	}
}

int deadfish()
{
	int count = 0;
	for (int i = 0; i < 6; i++)
	{
		if (interfish[i] == 0)
			count++;
	}
	if (count == 6)
		return 1;
	else
		return 0;

}

