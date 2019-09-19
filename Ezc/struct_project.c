/*고양이 뽑기*/

#include <stdio.h>
#include <time.h>

typedef struct {
	char *name;
	int age;
	char *character;
	int level;
}CAT;

void initCat(); //고양이 정보를 초기화
void printCat(int gacha); //고양이를 뽑으면 정보를 출력해줌
int checkCollection(); //모든 고양이를 다모았는지 확인, 현재 모든 고양이를 출력

CAT cats[5];
int checkCat[5] = { 0 }; //모든 고양이를 다 모았는지 확인

//5마리의 고양이가 있다
//아무 키나 눌러서 랜덤으로 고양이를 뽑되,
//5마리 모두 다 수집 해서 열심히  키우면 됨
//중복가능

//이름, 나이, 성격, 키우기 난이도(레벨)
int main_struct_project()
{
	srand(time(NULL));
	initCat();
	

	while (1)
	{
		printf("\n어떤 고양이가 나올까요? \n아무키나 눌러서 확인하세요!");
		getchar();
		int gacha = rand() % 5;
		checkCat[gacha] = 1;
		int allCat = checkCollection();
		if (allCat == 1)
		{
			printf("\n축하합니다!! 모든 고양이의 주인이 되었어요!\n");
			break;
		}
	}

	return 0;
}

void initCat()
{
	cats[0].name = "깜냥이";
	cats[0].age = 3;
	cats[0].character = "검은색임";
	cats[0].level = 4;

	cats[1].name = "돼냥이";
	cats[1].age = 1;
	cats[1].character = "잘먹음";
	cats[1].level = 1;

	cats[2].name = "삼색냥이";
	cats[2].age = 2;
	cats[2].character = "암컷임";
	cats[2].level = 2;

	cats[3].name = "수염냥이";
	cats[3].age = 6;
	cats[3].character = "흰수염임";
	cats[3].level = 3;

	cats[4].name = "갈냥이";
	cats[4].age = 4;
	cats[4].character = "은신을잘함";
	cats[4].level = 5;
}

void printCat(int gacha)
{
	printf("\n\n===당신은 이고양이의 주인이 되었어요!===\n\n");
	printf("이름        : %s\n", cats[gacha].name);
	printf("나이        : %d살\n", cats[gacha].age);
	printf("성격(특징)  : %s\n", cats[gacha].character);
	printf("레벨        : ");
	
	for (int i = 0; i < cats[gacha].level; i++)
	{
		printf("★");
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
			printf("%10s", "(빈 박스)");
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