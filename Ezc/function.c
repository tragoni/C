#include<stdio.h>
#include<time.h>

int getrandNumber(int level);
void showQuestion(level, num1, num2);
void success();
void fail();

int main(void)
{
	srand(time(NULL));
	int count = 0;
	for (int i = 1; i <= 5; i++)
	{
		int num1 = getrandNumber(i);
		int num2 = getrandNumber(i);
		showQuestion(i, num1, num2);

		int answer = -1;
		scanf_s("%d", &answer);
		if (answer == -1)
		{
			printf("���α׷��� �����մϴ�\n");
			exit(0);
		}
		else if (answer == num1 * num2)
		{
			success();
			count++;
		}
		else
		{
			fail();
		};
	}
	printf("%d���� ����.", count);

	return 0;
}

int getrandNumber(int level)
{
	return rand() % (level*7) + 1;
}

void showQuestion(level, num1, num2)
{
	printf("\n%d��° ���� : %d X %d ?\n",level, num1, num2);
}

void success()
{
	printf("�����Դϴ�.\n");
}

void fail()
{
	printf("�����̾ƴմϴ�.\n");
}
