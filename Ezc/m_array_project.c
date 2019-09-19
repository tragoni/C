#include <stdio.h>
#include <time.h>

//10������ ���� �ٸ� ���� (�� ī�� 2�徿)
//����ڷκ��� 2���� �Է°��� �޾Ƽ� -> ���� ���� ã���� ī�� ������
//��� ���� ���� ã���� ���� ����
// �� ���� Ƚ�� �˷��ֱ�

int arrayAnimal[4][5]; //�����迭 20���� ī��
int checkAnimal[4][5] = { 0 }; //���������� ���� Ȯ��
char *strAnimal[10];  // �����̸� 

void initAnimalArray();
void initAnimalName(); 
void shuffleAnimal(); 
int getEmptyPosition(); 
void printfAnimal(); 
void printQuestion();
int endGame();

int main(void)
{
	srand(time(NULL));
	initAnimalArray();
	initAnimalName();
	shuffleAnimal();
	
	printf("\n\n");

	int failCount = 0; //����Ƚ��
	while (1)
	{
		int select1; // ������Է°�1
		int select2; // ������Է°�2

		printfAnimal();
		printQuestion();
		printf("������ ī�带 2�� ������ : ");
		scanf_s("%d %d", &select1, &select2);

		if (select1 == select2) //���� ī�� ���ý� ��ȿ
			continue;
		
		//������ ������ ��ǥ��ȯ ���� 1,2
		int select1_x = select1 / 5;
		int select1_y = select1 % 5;
		int select2_x = select2 / 5;
		int select2_y = select2 % 5;

		//������ ī������ Ȯ��
		if ((checkAnimal[select1_x][select1_y] == 0 
			&& checkAnimal[select2_x][select2_y] == 0)

			&&

			(arrayAnimal[select1_x][select1_y] 
			== arrayAnimal[select2_x][select2_y])
			)
		{
			//������������ ..�´ٸ� ���, Ʋ���� �����̸� ��� 
			printf("\n�����Դϴ�!! �߰��� ���� : %s\n\n", arrayAnimal[select1_x][select1_y]);
			checkAnimal[select1_x][select1_y] = 1;
			checkAnimal[select2_x][select2_y] = 1;
		}
		else
		{
			printf("��!! �����̰ų� �̹� ������ ī���Դϴ�.\n");
			printf("%d�� ī�� : %s\n", select1, arrayAnimal[select1_x][select1_y]);
			printf("%d�� ī�� : %s\n", select2, arrayAnimal[select2_x][select2_y]);
			failCount++;
		}

		//��� ī�尡 �������ٸ� ������ ����
		if (endGame() == 1)
		{
			printf("Ʋ�� Ƚ���� %d�� �Դϴ�.\n", failCount);
			exit();
		}
	}

	return 0;
}

//�����迭 �����
void initAnimalArray()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arrayAnimal[i][j] = -1;
		}
	}
}

//�����̸��ʱ�ȭ
void initAnimalName()
{
	strAnimal[0] = "�䳢";
	strAnimal[1] = "������";
	strAnimal[2] = "�����";
	strAnimal[3] = "������";
	strAnimal[4] = "�Ǿ�";
	strAnimal[5] = "����";
	strAnimal[6] = "ȣ����";
	strAnimal[7] = "�⸰";
	strAnimal[8] = "�ϸ�";
	strAnimal[9] = "�޹���";
}

//�����̸��� 2�徿 ���� �������
void shuffleAnimal()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int num = getEmptyPosition(); //0~19 ����ִ� ���� ������
			int x = num / 5; //�������� x��ǥ������ ��ȯ
			int y = num % 5; //�������� y��ǥ������ ��ȯ

			arrayAnimal[x][y] = strAnimal[i]; //���� �̸��� ��ǥ���� ����
		}
	}
}

//����ִ� ��ǥ���� ã��
int getEmptyPosition()
{
	while (1)
	{
		int i = rand() % 20;
		int x = i / 5; // x��ǥ��
		int y = i % 5; // y��ǥ��

		if (arrayAnimal[x][y] == -1)
		{
			return i;
		}
	}
}

//����ī�带 ���
void printfAnimal()
{
	printf("\n==================����====================\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%8s", arrayAnimal[i][j]);
		}
		printf("\n");
	}
	printf("============================================\n");
}

//���� ���
void printQuestion()
{
	printf("\n\n(����)\n");
	int seq = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			//ī�������� ���������
			if (checkAnimal[i][j] != 0)
			{
				printf("%8s", arrayAnimal[i][j]);
			}

			//������ ���������
			else
			{
				printf("%8d", seq);
			}
			seq++;
		}
		printf("\n");
	}
}

// ��� ī�尡 ���������� Ȯ��
int endGame()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (checkAnimal[i][j] == 0)
				return 0;
		}
	}
	return 1;
}