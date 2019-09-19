#include <stdio.h>
#define MAX	 10000

int main(void)
{
	char line[MAX]; // 메모장에서 받아올 내용
	char contents[MAX]; // 메모장에 입력할내용
	char password[MAX]; // 비밀번호

	printf("비밀일기장\n");
	printf("비밀번호를 입력하세요 : ");

	int i = 0;

	//비밀번호를 입력받음
	while (1)
	{
		password[i] = getch();
		if (password[i] == 13) //13이 아스키코드로 엔터. 엔터를 입력받으면 문장입력끝
		{
			printf("\n비밀번호를 입력하셨습니다.\n");
			password[i] = '\0';
			break;
		}
		printf("*");
		i++;
	}

	printf("입력하신 비밀번호는 : %s 입니다.\n", password); //확인용

	//비밀번호 일치여부확인
	if (strcmp(password, "trueheart") == 0)
	{
		printf("비밀번호가 확인되었습니다.\n");
	}
	else
	{
		printf("비밀번호가 일치하지않습니다. 프로그램을 종료합니다\n");
		exit();
	}

	FILE *file = fopen("c:\\비밀메모.txt", "a+b");
	
	if (file == NULL)
	{
		printf("파일이없어요!\n");
		exit();
	
	}

	//내용 출력
	printf("파일내용을 출력합니다\n\n");
	
	while (fgets(line, MAX, file) != NULL)
	{
		printf("%s", line);
	}

	//메모 작성 - 이어쓰기
	printf("메모를 작성하세요. (exit를 입력하면 입력종료)\n");
	
	while (1)
	{
		scanf("%[^\n]", contents);

		if (strcmp(contents, "exit") == 0)
		{
			printf("입력을 종료합니다\n");
			exit();
		}
		fputs(contents, file);
		getchar();
		fputs("\n", file);
	}

	fclose(file);

	

	return 0;
}