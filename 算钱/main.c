#include<stdio.h>
#include<stdlib.h>
#include"lala.h"

int main(int argc, char* argv[])
{
	Date start, last;
	printf("请输入开始时间：");
	scanf_s("%d %d %d", &start.year, &start.month,& start.day);
	printf("请输入结束时间：");
	scanf_s("%d %d %d", &last.year, &last.month, &last.day);

	printf("%d\n", income(start,last));
	system("pause");
	return 0;
}