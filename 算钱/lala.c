#include<stdio.h>
#include<stdlib.h>
#include"lala.h"

int Isnprime(int a)
{
	int ret = 0;
	int i;
	if (a == 1) {
		ret= 1;
	}
	else if (a == 2 || a == 3) {
		ret= 0;
	}
	else {
		for (i = 2; i < a; i++) {
			if (!(a % i)) {
				ret = 1;
			}
		}
	}
	return ret;
}

int Leap(int a) {
	int ret = 0;
	if (!(a % 4)) {
		if (!(a % 100)) {
			if (!(a % 400)) {
				ret = 1;
			}
		}
		ret = 1;
	}
	return ret;
}
int month[] = { 30,27,30,29,30,29,
				30,30,29,30,29,30, };
int day[] = { 1,2,3,4,5,6,7,8,9,10,
			11,12,13,14,15,16,17,18,19,20,
			21,22,23,24,25,26,27,28,29,30,31, };
int income(Date start, Date last)
{
	int ret = 0;
	for (start.day; start.day < day[month[start.month - 1]] + 2; start.day++) {
		if (Leap(start.year)) {
			month[1] = 28;
		}
		else {
			month[1] = 27;
		}
		if (start.day >= day[month[start.month - 1]] + 1) {
			start.month += 1;
			start.day = 1;
			if (start.month >= 13) {
				start.year += 1;
				start.month = 1;
			}
		}
		if (Isnprime(start.month)) {
			ret += 2;
		}
		else {
			ret += 1;
		}
		if (start.year == last.year && start.month == last.month && start.day == last.day) {
			break;
		}
	}
	return ret;
}