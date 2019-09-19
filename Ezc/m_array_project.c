#include <stdio.h>
#include <time.h>

//10마리의 서로 다른 동물 (각 카드 2장씩)
//사용자로부터 2개의 입력값을 받아서 -> 같은 동물 찾으면 카드 뒤집기
//모든 동물 쌍을 찾으면 게임 종료
// 총 실패 횟수 알려주기

int arrayAnimal[4][5]; //동물배열 20장의 카드
int checkAnimal[4][5] = { 0 }; //뒤집혔는지 여부 확인
char *strAnimal[10];  // 동물이름 

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

	int failCount = 0; //실패횟수
	while (1)
	{
		int select1; // 사용자입력값1
		int select2; // 사용자입력값2

		printfAnimal();
		printQuestion();
		printf("뒤집을 카드를 2개 고르세요 : ");
		scanf_s("%d %d", &select1, &select2);

		if (select1 == select2) //같은 카드 선택시 무효
			continue;
		
		//선택한 숫자의 좌표변환 각각 1,2
		int select1_x = select1 / 5;
		int select1_y = select1 % 5;
		int select2_x = select2 / 5;
		int select2_y = select2 % 5;

		//뒤집힌 카드인지 확인
		if ((checkAnimal[select1_x][select1_y] == 0 
			&& checkAnimal[select2_x][select2_y] == 0)

			&&

			(arrayAnimal[select1_x][select1_y] 
			== arrayAnimal[select2_x][select2_y])
			)
		{
			//같은동물인지 ..맞다면 출력, 틀리면 동물이름 출력 
			printf("\n정답입니다!! 발견한 동물 : %s\n\n", arrayAnimal[select1_x][select1_y]);
			checkAnimal[select1_x][select1_y] = 1;
			checkAnimal[select2_x][select2_y] = 1;
		}
		else
		{
			printf("땡!! 오답이거나 이미 뒤집힌 카드입니다.\n");
			printf("%d번 카드 : %s\n", select1, arrayAnimal[select1_x][select1_y]);
			printf("%d번 카드 : %s\n", select2, arrayAnimal[select2_x][select2_y]);
			failCount++;
		}

		//모든 카드가 뒤집혔다면 게임을 종료
		if (endGame() == 1)
		{
			printf("틀린 횟수는 %d번 입니다.\n", failCount);
			exit();
		}
	}

	return 0;
}

//동물배열 만들기
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

//동물이름초기화
void initAnimalName()
{
	strAnimal[0] = "토끼";
	strAnimal[1] = "원숭이";
	strAnimal[2] = "고양이";
	strAnimal[3] = "강아지";
	strAnimal[4] = "악어";
	strAnimal[5] = "사자";
	strAnimal[6] = "호랑이";
	strAnimal[7] = "기린";
	strAnimal[8] = "하마";
	strAnimal[9] = "앵무새";
}

//동물이름을 2장씩 각각 섞어넣음
void shuffleAnimal()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int num = getEmptyPosition(); //0~19 비어있는 값을 가져옴
			int x = num / 5; //난수값을 x좌표값으로 변환
			int y = num % 5; //난수값을 y좌표값으로 변환

			arrayAnimal[x][y] = strAnimal[i]; //동물 이름을 좌표값에 대입
		}
	}
}

//비어있는 좌표값을 찾음
int getEmptyPosition()
{
	while (1)
	{
		int i = rand() % 20;
		int x = i / 5; // x좌표값
		int y = i % 5; // y좌표값

		if (arrayAnimal[x][y] == -1)
		{
			return i;
		}
	}
}

//동물카드를 출력
void printfAnimal()
{
	printf("\n==================정답====================\n");
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

//문제 출력
void printQuestion()
{
	printf("\n\n(문제)\n");
	int seq = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			//카드정답을 맞췄을경우
			if (checkAnimal[i][j] != 0)
			{
				printf("%8s", arrayAnimal[i][j]);
			}

			//맞추지 못했을경우
			else
			{
				printf("%8d", seq);
			}
			seq++;
		}
		printf("\n");
	}
}

// 모든 카드가 뒤집혔는지 확인
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