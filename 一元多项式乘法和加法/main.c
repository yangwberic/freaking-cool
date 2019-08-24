#include<stdio.h>
#include"PP.h"

int main()
{
	Polynomial p1, p2, pp, ps;
	p1 = ReadPoly();
	p2 = ReadPoly();
	pp = Mult(p1, p2);
	ps = AddPoly(p1, p2);
	PrintPoly(pp);
	PrintPoly(ps);
	return 0;

}