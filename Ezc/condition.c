#include <stdio.h>
#include <time.h>

int main(VOID)
{
	/*int i = 1;

	switch (i)
	{
	case 0: printf("가위\n"); break;
	case 1: printf("바위\n"); break;
	case 2: printf("보\n"); break;
	default : printf("몰라요\n"); break;

	}*/

	srand(time(NULL));
	int num = rand() % 100 + 1;
	int answer;
	int chance = 5;
	while (chance > 0)
	{
		printf("남은 기회 %d 번 \n", chance--);
		printf("숫자를 맞혀보세요 (1~100) : ");
		scanf_s("%d", &answer);

		if (answer > num) {
			printf("Down ↓\n\n ");
		}
		else if (answer < num) {
			printf("Up ↑\n\n ");
		}
		else if (answer == num) {
			printf("정답입니다\n\n"); break;
		}
		else {
			printf("오류\n\n");
		}

		if (chance == 0) {
			printf("모든기회를 다사용하셨습니다.\n\n");
		} 
	}
	return 0;

}