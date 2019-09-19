#include <stdio.h>
#include<time.h>
#include <stdlib.h>

// 4개의 변수를 선언 그중 1개가 정답
// 4개의 변수중 2 ~ 3 가지를 같이 보여주면서 정답유추- 2가지로
// 총 3번 보여줌 보여주는 가지수는 전에 보여준 가짓수와 같으면안됨-
// 

int main(void)
{
	srand(time(NULL)); //난수 초기화
	int answer; //사용자 정답
	int treatment = rand() % 4; //치료제 번호 (0~3)
	int ncntbottle = 0; //보여줄 물약 갯수
	int cntbottle = 0;//보여준 물약 갯수

	printf("---------- 시작 ----------\n\n");
	for (int i = 1; i <= 3; i++) //총 시행횟수 3회
	{
		int bottle[4] = { 0 };  //4개의 물약 선언 + 0으로 초기화

		do {
			ncntbottle = rand() % 2 + 2;	//보여줄 물약갯수 
		} while (ncntbottle == cntbottle);
		cntbottle = ncntbottle;

		int bottlenum = 0; //갯수만큼 물약을 보여주기위한 변수

		do {
			int randbottle = rand() % 4; // 보여줄 물약 번호를 선별 0~3
				if (bottle[randbottle] == 0)
				{
					bottle[randbottle] = 1;
					bottlenum++;
				}
		} while (bottlenum<ncntbottle);

		printf("===================\n");
		printf(" >> ");
		for (int k = 0; k < sizeof(bottle) / 4; k++) //물약 보여줌
		{
			if (bottle[k] == 1)
			{
				printf("%d번 ",k+1);
			}
		}
		printf("을 복용.\n");
		if (bottle[treatment] == 1)		//물약중 치료제 포함 여부
		{
			printf("효과있음!!\n\n");
		}
		else
		{
			printf("효과없음 ㅜㅜ\n\n");
		}
		printf("계속하려면 아무키나 누르세요\n\n"); //pause
		getchar();
	}

	printf("치료제는 몇번? >> "); //정답맞추기
	scanf_s("%d", &answer);

	if (treatment + 1 == answer) //정답확인
	{
		printf("정답입니다!!!\n\n");
	}
	else
	{
		printf("정답이 아닙니다...\n\n");
	}

	return 0;
}