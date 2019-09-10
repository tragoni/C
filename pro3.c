#include <stdio.h>

typedef struct LinkedList {
	int i;
	struct LinkedList *link;
}Node;

int main_pro3(void)
{
	int input; //�Է°�
	Node *list = NULL, *pd, *prev, *next, *chd;


	while (1)
	{
		printf("���� ������ �Է��ϼ���(����: -1): ");
		scanf("%d", &input);
		if (input == -1)
		{
			break;
		}
		pd = (Node *)malloc(sizeof(Node));	//���� �޸� �Ҵ�
		pd->i = input;
		pd->link = NULL;
		//ù��° ����
		if (list == NULL)
			list = pd;
		else
		{
			//��� ���� ����
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
	//���Ḯ��Ʈ ���
	pd = list;
	while (pd != NULL)
	{
		printf("%d->", pd->i);
		pd = pd->link;
	}
	printf("NULL\n");

	//���� �޸� �ݳ�
	pd = list;
	while (pd != NULL)
	{
		next = pd->link;
		free(pd);
		pd = next;
	}

	return 0;
}