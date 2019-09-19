/*����� �̱�*/

#include <stdio.h>
#include <time.h>

typedef struct {
	char *name;
	int age;
	char *character;
	int level;
}CAT;

void initCat(); //����� ������ �ʱ�ȭ
void printCat(int gacha); //����̸� ������ ������ �������
int checkCollection(); //��� ����̸� �ٸ�Ҵ��� Ȯ��, ���� ��� ����̸� ���

CAT cats[5];
int checkCat[5] = { 0 }; //��� ����̸� �� ��Ҵ��� Ȯ��

//5������ ����̰� �ִ�
//�ƹ� Ű�� ������ �������� ����̸� �̵�,
//5���� ��� �� ���� �ؼ� ������  Ű��� ��
//�ߺ�����

//�̸�, ����, ����, Ű��� ���̵�(����)
int main_struct_project()
{
	srand(time(NULL));
	initCat();
	

	while (1)
	{
		printf("\n� ����̰� ���ñ��? \n�ƹ�Ű�� ������ Ȯ���ϼ���!");
		getchar();
		int gacha = rand() % 5;
		checkCat[gacha] = 1;
		int allCat = checkCollection();
		if (allCat == 1)
		{
			printf("\n�����մϴ�!! ��� ������� ������ �Ǿ����!\n");
			break;
		}
	}

	return 0;
}

void initCat()
{
	cats[0].name = "������";
	cats[0].age = 3;
	cats[0].character = "��������";
	cats[0].level = 4;

	cats[1].name = "�ų���";
	cats[1].age = 1;
	cats[1].character = "�߸���";
	cats[1].level = 1;

	cats[2].name = "�������";
	cats[2].age = 2;
	cats[2].character = "������";
	cats[2].level = 2;

	cats[3].name = "��������";
	cats[3].age = 6;
	cats[3].character = "�������";
	cats[3].level = 3;

	cats[4].name = "������";
	cats[4].age = 4;
	cats[4].character = "����������";
	cats[4].level = 5;
}

void printCat(int gacha)
{
	printf("\n\n===����� �̰������ ������ �Ǿ����!===\n\n");
	printf("�̸�        : %s\n", cats[gacha].name);
	printf("����        : %d��\n", cats[gacha].age);
	printf("����(Ư¡)  : %s\n", cats[gacha].character);
	printf("����        : ");
	
	for (int i = 0; i < cats[gacha].level; i++)
	{
		printf("��");
	}
	printf("\n");
}

int checkCollection()
{
	int allcollect = 1;

	for (int i = 0; i < 5; i++)
	{
		if (checkCat[i] == 0)
		{
			printf("%10s", "(�� �ڽ�)");
			allcollect = 0;
		}
		else
		{
			printf("%10s", cats[i].name);
		}
	}
	printf("\n");
	return allcollect;
}