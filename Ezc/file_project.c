#include <stdio.h>
#define MAX	 10000

int main(void)
{
	char line[MAX]; // �޸��忡�� �޾ƿ� ����
	char contents[MAX]; // �޸��忡 �Է��ҳ���
	char password[MAX]; // ��й�ȣ

	printf("����ϱ���\n");
	printf("��й�ȣ�� �Է��ϼ��� : ");

	int i = 0;

	//��й�ȣ�� �Է¹���
	while (1)
	{
		password[i] = getch();
		if (password[i] == 13) //13�� �ƽ�Ű�ڵ�� ����. ���͸� �Է¹����� �����Է³�
		{
			printf("\n��й�ȣ�� �Է��ϼ̽��ϴ�.\n");
			password[i] = '\0';
			break;
		}
		printf("*");
		i++;
	}

	printf("�Է��Ͻ� ��й�ȣ�� : %s �Դϴ�.\n", password); //Ȯ�ο�

	//��й�ȣ ��ġ����Ȯ��
	if (strcmp(password, "trueheart") == 0)
	{
		printf("��й�ȣ�� Ȯ�εǾ����ϴ�.\n");
	}
	else
	{
		printf("��й�ȣ�� ��ġ�����ʽ��ϴ�. ���α׷��� �����մϴ�\n");
		exit();
	}

	FILE *file = fopen("c:\\��и޸�.txt", "a+b");
	
	if (file == NULL)
	{
		printf("�����̾����!\n");
		exit();
	
	}

	//���� ���
	printf("���ϳ����� ����մϴ�\n\n");
	
	while (fgets(line, MAX, file) != NULL)
	{
		printf("%s", line);
	}

	//�޸� �ۼ� - �̾��
	printf("�޸� �ۼ��ϼ���. (exit�� �Է��ϸ� �Է�����)\n");
	
	while (1)
	{
		scanf("%[^\n]", contents);

		if (strcmp(contents, "exit") == 0)
		{
			printf("�Է��� �����մϴ�\n");
			exit();
		}
		fputs(contents, file);
		getchar();
		fputs("\n", file);
	}

	fclose(file);

	

	return 0;
}