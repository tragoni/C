#include <stdio.h>
#include <time.h>

int main(VOID)
{
	/*int i = 1;

	switch (i)
	{
	case 0: printf("����\n"); break;
	case 1: printf("����\n"); break;
	case 2: printf("��\n"); break;
	default : printf("�����\n"); break;

	}*/

	srand(time(NULL));
	int num = rand() % 100 + 1;
	int answer;
	int chance = 5;
	while (chance > 0)
	{
		printf("���� ��ȸ %d �� \n", chance--);
		printf("���ڸ� ���������� (1~100) : ");
		scanf_s("%d", &answer);

		if (answer > num) {
			printf("Down ��\n\n ");
		}
		else if (answer < num) {
			printf("Up ��\n\n ");
		}
		else if (answer == num) {
			printf("�����Դϴ�\n\n"); break;
		}
		else {
			printf("����\n\n");
		}

		if (chance == 0) {
			printf("����ȸ�� �ٻ���ϼ̽��ϴ�.\n\n");
		} 
	}
	return 0;

}