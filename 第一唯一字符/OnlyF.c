#include<stdio.h>
#include<stdlib.h>

int OnlyFirst(char* ch, int size ) {
	int i;
	char poss[256] = { 0 };
	for (i = 0; i < size; i++) {
		poss[ch[i]]++;
	}
	for (i = 0; i < size; i++) {
		if (poss[ch[i]]==1) {
			return i;
		}
	}
}

int main()
{
	char ch[100];
	gets(ch);
	printf("%d\n", OnlyFirst(ch,sizeof(ch)));
	system("pause");
	return 0;
}