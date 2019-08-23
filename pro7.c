/*���� ���� ���α׷�*/

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

	struct poemManager P[SIZE] = {
		{1, "�ֳ��ϸ� �츮�� �츮�� �𸣰�", "������"},
		{2, "�ϴð� �ٶ��� ���� ��", "������"},
		{3, "���޷���", "��ҿ�"}
	};
	int count = 3;// ����Ʈ ����
	FILE *fp = NULL;

	if ((fp = fopen("poem.dat", "rb") == NULL))
	{
		puts("������ �� �� �����ϴ�.\n");
		init(P, &count);
		exit(1);
	}



	while (1)
	{
		menu(P, &count);
	}
	return 0;
}

//�޴� ȣ��
void menu(struct poemManager *P, int *c) {
	int num;

	puts("�޴�\n1. �Է�\n2. Ž��\n3. ����\n4. ����");
	printf("��ȣ�� �Է��Ͻÿ�: ");
	scanf("%d", &num);

	if (num == 1)
		input(P, c);
	else if (num == 2)
		search(P,c);
	else if (num == 3)
		dele(P,c);
	else if (num == 4)
	{
		puts("���α׷��� �����մϴ�.");
		exit();
	}
	else
	{
		gets();
		puts("\n�޴��� �ٽ� �������ּ���.");
		menu(P, c);
	}
}

//�ʱⰪ ����
void init(struct poemManager *P, int *c) {
	
	P->num = 1, strcpy(P->fname, "�ֳ��ϸ� �츮�� �츮�� �𸣰�", strcpy(P->author, "������");
	P->num = 2, strcpy(P->fname, "�ϴð� �ٶ��� ���� ��", strcpy(P->author, "������");
	P->num = 3, strcpy(P->fname, "���޷���", strcpy(P->author, "��ҿ�");
		{2, "�ϴð� �ٶ��� ���� ��", "������"}
		{3, "���޷���", "��ҿ�"}
	int count = 3;// ����Ʈ ����
}

//1���޴� �Է�
void input(struct poemManager *P, int *c) {
	(*c)++;
	printf("������ �Է����ּ��� : ");
	scanf("%s", P[*c-1].fname);
	printf("������ �Է����ּ��� : ");
	scanf("%s", P[*c-1].author);
	P[*c-1].num = *c;
}

//2���޴� Ž��
void search(struct poemManager *P, int *c) {
	for(int i=1;i<=*c;i++)
	printf("%d. [%s], %s\n", P[i-1].num, P[i-1].fname, P[i-1].author);
}

//3���޴� ����
void dele(struct poemManager *P, int *c) {
	int s;

	search(P, c);

	printf("\n������������ �����ϼ���.");
	scanf("%d", &s);
	if ((s<1) || (s>*c))
	{
		gets();
		puts("\n�ٽü����ϼ���.");
		dele(P, c);
	}

	//������ ��ȣ ����
	for (int n = s; n < *c; n++)
	{
		strcpy(P[n].fname, P[n + 1].fname);
		strcpy(P[n].author, P[n + 1].author);
	}
	printf("%d���� �����Ͽ����ϴ�.\n", s);
	(*c)--;
}