#include <stdio.h>

typedef struct LinkedList {
	int i;
	struct LinkedList *link;
}Node;

int main_pro3(void)
{
	int input; //입력값
	Node *list = NULL, *pd, *prev, *next, *chd;


	while (1)
	{
		printf("양의 정수를 입력하세요(종료: -1): ");
		scanf("%d", &input);
		if (input == -1)
		{
			break;
		}
		pd = (Node *)malloc(sizeof(Node));	//동적 메모리 할당
		pd->i = input;
		pd->link = NULL;
		//첫번째 노드시
		if (list == NULL)
			list = pd;
		else
		{
			//대소 비교후 삽입
			chd = pd;
			pd = list;
			if (pd->i > chd->i)
			{
				chd->link = pd;
				list = chd;
			}
			else if (pd->link == NULL)
			{
				pd->link = chd;
			}
			else
			{
				while (pd != NULL)
				{
					prev = pd;
					pd = pd->link;
					if (pd->i >= chd->i)
					{
						chd->link = pd;
						prev->link = chd;
						break;
					}
					if (pd->link == NULL)
					{
						pd->link = chd;
						break;
					}
				}
			}
		}

	}
	//연결리스트 출력
	pd = list;
	while (pd != NULL)
	{
		printf("%d->", pd->i);
		pd = pd->link;
	}
	printf("NULL\n");

	//동적 메모리 반납
	pd = list;
	while (pd != NULL)
	{
		next = pd->link;
		free(pd);
		pd = next;
	}

	return 0;
}