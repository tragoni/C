#include <stdio.h>

#define MAX	 10000

int main(void)
{
	//fprintf fscanf
	int num[6] = { 1,2,3,4,5,6 };
	int snum = 7;
	char str1[MAX];
	char str2[MAX];

	FILE *file = fopen("C:\\Users\\USER\\Desktop\\연습\\연습파일.txt", "rb");

	/*fprintf(file,"%s %d %d %d %d %d %d\n", "당첨번호", num[0], num[1], num[2], num[3], num[4], num[5]);
	fprintf(file,"%s %d", "스페셜번호", snum);*/

	fscanf(file, "%s %d %d %d %d %d %d", str1, &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);
	printf("%s %d %d %d %d %d %d\n",str1 ,num[0], num[1], num[2], num[3], num[4], num[5]);

	fscanf(file, "%s %d", str2, &snum);
	printf("%s %d\n", str2, snum);

	fclose(file);

	return 0;
}