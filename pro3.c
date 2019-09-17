#include <stdio.h>

typedef struct LinkedList {
	int i;
	struct LinkedList *link;
}Node;

int main(void)
{
	int input; //�Է°�
	Node *list = NULL, *pd, *prev, *next, *chd;


	while (1)
	{
		//������
		printf("���� ������ �Է��ϼ���(����: -1): ");
		scanf("%d", &input);
		if (input == -1)
		{
			break;
		}
		pd = (Node *)malloc(sizeof(Node));	//���� �޸� �Ҵ�
		pd->i = input;
		pd->link = NULL;

		//����� ���ٸ�
		if (list == NULL)
			list = pd;
		else
		{
			//��� ���� ����
			chd = pd;
			pd = list;

			while (pd != NULL)
			{
				if (pd->i >= chd->i)
				{
					if (pd == list)
					{
						chd->link = pd;
						list = chd;
					}
					else
					{
						prev->link = chd;
						chd->link = pd;
					}
					break;
				}
				prev = pd;
				pd = pd->link;
			}
			if (pd == NULL)
				prev->link = chd;
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