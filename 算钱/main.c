#include<stdio.h>
#include<stdlib.h>
#include"lala.h"

int main(int argc, char* argv[])
{
	Date start, last;
	printf("�����뿪ʼʱ�䣺");
	scanf_s("%d %d %d", &start.year, &start.month,& start.day);
	printf("���������ʱ�䣺");
	scanf_s("%d %d %d", &last.year, &last.month, &last.day);

	printf("%d\n", income(start,last));
	system("pause");
	return 0;
}