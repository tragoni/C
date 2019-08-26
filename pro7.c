/*시집 관리 프로그램
내용읽기 추가는 나중에
*/

#include <stdio.h>
#include <string.h>
#define SIZE 20

void menu(struct poemManager *p, int *c);
void input(struct poemManager *p, int *c);
void search(struct poemManager *p, int *c);
void dele(struct poemManager *p, int *c);
void init(struct poemManager *p, int *c);

struct poemManager {
	int num;
	char fname[128];
	char author[128];
};


int main(void)
{
	struct poemManager P[SIZE] = { 0 };
	int count=0;
	FILE *fp = NULL;

	if ((fp = fopen("poem.dat", "rb")) == NULL)
	{
		init(P, &count);
		if ((fp = fopen("poem.dat", "wb")) == NULL)
		{
			puts("파일을 열 수 없습니다.\n");
			exit(1);
		}
		fwrite(P, sizeof(struct poemManager), SIZE, fp);
		fwrite(&count, sizeof(int), 1, fp);
		fclose(fp);
	}
	else
	{
		fread(P, sizeof(struct poemManager), SIZE, fp);
		fread(&count, sizeof(int), 1, fp);
		fclose(fp);
	}

	while (1)
	{
		printf("%d\n", count);
		menu(P, &count);
	}

	if ((fp = fopen("poem.dat", "wb")) == NULL)
	{
		puts("파일을 열 수 없습니다.\n");
		exit(1);
	}
	return 0;
}

//메뉴 호출
void menu(struct poemManager *P, int *c) {
	int num;

	puts("메뉴\n1. 입력\n2. 탐색\n3. 삭제\n4. 종료");
	printf("번호를 입력하시오: ");
	scanf("%d", &num);

	if (num == 1)
		input(P, c);
	else if (num == 2)
		search(P,c);
	else if (num == 3)
		dele(P,c);
	else if (num == 4)
	{
		puts("프로그램을 종료합니다.");
		FILE *fp2;
		fp2 = fopen("poem.dat", "wb");
		fwrite(P, sizeof(struct poemManager), SIZE, fp2);
		fwrite(c, sizeof(int), 1, fp2);
		fclose(fp2);
		exit(1);
	}
	else
	{
		gets();
		puts("\n메뉴를 다시 선택해주세요.");
		menu(P, c);
	}
}

//초기값 설정
void init(struct poemManager *P, int *c) {
	
	P->num = 1, strcpy(P->fname, "왜냐하면 우리는 우리를 모르고", strcpy(P->author, "이제나"));
	(P + 1)->num = 2, strcpy((P + 1)->fname, "하늘과 바람과 별과 시", strcpy((P + 1)->author, "윤동주"));
	(P + 2)->num = 3, strcpy((P + 2)->fname, "진달래꽃", strcpy((P + 2)->author, "김소월"));
	 *c = 3;//리스트 갯수
}

//1번메뉴 입력
void input(struct poemManager *P, int *c) {
	P[*c - 1].num = ++(*c);
	printf("제목을 입력해주세요 : ");
	scanf("%s", P[*c-1].fname);
	printf("저자을 입력해주세요 : ");
	scanf("%s", P[*c-1].author);
}

//2번메뉴 탐색
void search(struct poemManager *P, int *c) {
	for(int i=1;i<=*c;i++)
	printf("%d. [%s], %s\n", P[i-1].num, P[i-1].fname, P[i-1].author);
}

//3번메뉴 삭제
void dele(struct poemManager *P, int *c) {
	int s;

	search(P, c);

	printf("\n제거할파일을 선택하세요.");
	scanf("%d", &s);
	if ((s<1) || (s>*c))
	{
		gets();
		puts("\n다시선택하세요.");
		dele(P, c);
	}

	//선택한 번호 제거
	for (int n = s; n < *c; n++)
	{
		strcpy(P[n].fname, P[n + 1].fname);
		strcpy(P[n].author, P[n + 1].author);
	}
	printf("%d번을 삭제하였습니다.\n", s);
	(*c)--;
}