#include <stdio.h>
#include <time.h>

void interface(); //물고기 인터페이스
void initfish(); //물고기 상태 초기화 100넣기
void declineFish(int level); //줄어드는 수위
void levelUp();
int interfish[6]; //물고기 정보
int deadfish();

long total = 0; //전체시간
long pretotal = 0; //이전시간 -상대시간구할때 사용
long pre = 0;	//상대시간
int level = 1; //게임레벨

int main(void)
{
	int answer; //사용자 입력
	int *point = interfish;
	initfish();
	while (1)
	{
		pretotal = total;
		total = clock();
		pre = total-pretotal;
		printf("\n\n");
		interface();
		printf("\n전체경과시간: %3d\n", total/1000);
		printf("상대경과시간: %3d\n", pre/1000);
		levelUp(level);
		printf("어느 물고기에게 물을 주시겠습니까?(1~6) ");
		scanf_s("%d", &answer);
		if (1 > answer || 6 < answer)
		{
			printf("\n잘못입력하셨습니다.\n");
			continue;
		}
		declineFish(level);
		//물고기물주기
		if (point[answer - 1] <= 0)
		{
			printf("이미 죽은 물고기입니다.\n");
		}
		else if (point[answer - 1] < 100)
		{
			printf("%d번 물고기에게 물을 줍니다.\n", answer);
			point[answer - 1] += 10;

			if (point[answer - 1] >= 100)
			{
				point[answer - 1] = 100;
			}
		}
		//모든 물고기가 죽었는지 확인endgame
		if (deadfish() == 1)
		{
			printf("모든 물고기가 죽었습니다. 게임을 종료합니다\n\n");
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
		printf("%d레벨로 업그레이드!!\n", level);
	}
	if (level == 5)
	{
		exit();
		printf("게임종료\n\n");
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

