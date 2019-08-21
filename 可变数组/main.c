#include<stdio.h>
#include"array.h"
#include<stdlib.h>


int main(int argc, char const* argv[])
{
	int size;
	int cnt = 0;
	int num = 0;
	Array a = array_create(10);
	size = array_size(&a);
	while (num != -1) {
		scanf_s("%d", &num);
		if (num != -1) {
			*array_at(&a, cnt) = num;
			printf("%d / %d", a.array[cnt],a.size);
			cnt++;
		}
	}
	array_free(&a);
	system("pause");
	return 0;
}