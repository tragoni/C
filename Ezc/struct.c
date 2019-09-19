#include <stdio.h>

struct GameInfo {
	char *name;
	int year;
	int price;
	char *company;
	struct GameInfo *friendGame; //연관업체 소개
};

typedef struct GameInformation {
	char *name;
	int year;
	int price;
	char *company;
	struct GameInfo *friendGame; //연관업체 소개
} GAME_INFO;


int main_struct()
{
	// [게임 출시]
	// 이름 : 나도게임
	// 발매년도 : 2017 년
	// 가격 : 50원
	// 제작사 : 나도회사

	char *name = "나도게임";
	int year = 2017;
	int price = 50;
	char *company = "나도회사";

	//구조체 사용

	struct GameInfo gameInfo1;
	gameInfo1.name = "나도게임";
	gameInfo1.year = 2017;
	gameInfo1.price = 50;
	gameInfo1.company = "나도회사";

	//구조체 출력
	printf("-- 게임 출시 정보 --\n");
	printf(" 게임명		:%s\n",gameInfo1.name);
	printf(" 출시년도	:%d\n",gameInfo1.year);
	printf(" 가격		:%d\n",gameInfo1.price);
	printf(" 제작사		:%s\n",gameInfo1.company);

	//구조체를 배열처럼 초기화
	struct GameInfo gameInfo2 = { "너도게임",2017,100,"너도회사" };
	printf("-- 또다른 게임 출시 정보 --\n");
	printf(" 게임명		:%s\n", gameInfo2.name);
	printf(" 출시년도	:%d\n", gameInfo2.year);
	printf(" 가격		:%d\n", gameInfo2.price);
	printf(" 제작사		:%s\n", gameInfo2.company);

	//구조체 배열
	struct GameInfo GameArray[2] = {
		{ "나도게임",2017,50,"나도회사" },
		{ "너도게임",2017,100,"너도회사" }
	};

	//구조체 포인터
	struct GameInfo *gameptr;
	gameptr = &gameInfo1;
	printf("-- 게임 출시 정보 --\n");
	printf(" 출시년도	:%d\n", (*gameptr).year);
	printf(" 게임명		:%s\n", (*gameptr).name);
	printf(" 가격		:%d\n", (*gameptr).price);
	printf(" 제작사		:%s\n", (*gameptr).company);

	printf(" 출시년도	:%d\n", gameptr->year);
	printf(" 게임명		:%s\n", gameptr->name);
	printf(" 가격		:%d\n", gameptr->price);
	printf(" 제작사		:%s\n", gameptr->company);

	//연관업체 게임소개
	gameInfo1.friendGame = &gameInfo2;
	printf("-- 연관업체 게임 출시 정보 --\n");
	printf(" 출시년도	:%d\n", gameInfo1.friendGame->year);
	printf(" 가격		:%d\n", gameInfo1.friendGame->price);
	printf(" 제작사		:%s\n", gameInfo1.friendGame->company);
	printf(" 게임명		:%s\n", gameInfo1.friendGame->name);

	//typedef
	//자료형에 별명 지정
	typedef struct GameInfo 게임정보;
	게임정보 game1;
	
	game1.name = "한글게임";
	game1.year = 2017;

	GAME_INFO game2;
	game2.company = "한글회사";
	game2.name = "훈글게임";


	return 0;
}