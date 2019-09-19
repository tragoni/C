#include <stdio.h>

struct GameInfo {
	char *name;
	int year;
	int price;
	char *company;
	struct GameInfo *friendGame; //������ü �Ұ�
};

typedef struct GameInformation {
	char *name;
	int year;
	int price;
	char *company;
	struct GameInfo *friendGame; //������ü �Ұ�
} GAME_INFO;


int main_struct()
{
	// [���� ���]
	// �̸� : ��������
	// �߸ų⵵ : 2017 ��
	// ���� : 50��
	// ���ۻ� : ����ȸ��

	char *name = "��������";
	int year = 2017;
	int price = 50;
	char *company = "����ȸ��";

	//����ü ���

	struct GameInfo gameInfo1;
	gameInfo1.name = "��������";
	gameInfo1.year = 2017;
	gameInfo1.price = 50;
	gameInfo1.company = "����ȸ��";

	//����ü ���
	printf("-- ���� ��� ���� --\n");
	printf(" ���Ӹ�		:%s\n",gameInfo1.name);
	printf(" ��ó⵵	:%d\n",gameInfo1.year);
	printf(" ����		:%d\n",gameInfo1.price);
	printf(" ���ۻ�		:%s\n",gameInfo1.company);

	//����ü�� �迭ó�� �ʱ�ȭ
	struct GameInfo gameInfo2 = { "�ʵ�����",2017,100,"�ʵ�ȸ��" };
	printf("-- �Ǵٸ� ���� ��� ���� --\n");
	printf(" ���Ӹ�		:%s\n", gameInfo2.name);
	printf(" ��ó⵵	:%d\n", gameInfo2.year);
	printf(" ����		:%d\n", gameInfo2.price);
	printf(" ���ۻ�		:%s\n", gameInfo2.company);

	//����ü �迭
	struct GameInfo GameArray[2] = {
		{ "��������",2017,50,"����ȸ��" },
		{ "�ʵ�����",2017,100,"�ʵ�ȸ��" }
	};

	//����ü ������
	struct GameInfo *gameptr;
	gameptr = &gameInfo1;
	printf("-- ���� ��� ���� --\n");
	printf(" ��ó⵵	:%d\n", (*gameptr).year);
	printf(" ���Ӹ�		:%s\n", (*gameptr).name);
	printf(" ����		:%d\n", (*gameptr).price);
	printf(" ���ۻ�		:%s\n", (*gameptr).company);

	printf(" ��ó⵵	:%d\n", gameptr->year);
	printf(" ���Ӹ�		:%s\n", gameptr->name);
	printf(" ����		:%d\n", gameptr->price);
	printf(" ���ۻ�		:%s\n", gameptr->company);

	//������ü ���ӼҰ�
	gameInfo1.friendGame = &gameInfo2;
	printf("-- ������ü ���� ��� ���� --\n");
	printf(" ��ó⵵	:%d\n", gameInfo1.friendGame->year);
	printf(" ����		:%d\n", gameInfo1.friendGame->price);
	printf(" ���ۻ�		:%s\n", gameInfo1.friendGame->company);
	printf(" ���Ӹ�		:%s\n", gameInfo1.friendGame->name);

	//typedef
	//�ڷ����� ���� ����
	typedef struct GameInfo ��������;
	�������� game1;
	
	game1.name = "�ѱ۰���";
	game1.year = 2017;

	GAME_INFO game2;
	game2.company = "�ѱ�ȸ��";
	game2.name = "�Ʊ۰���";


	return 0;
}