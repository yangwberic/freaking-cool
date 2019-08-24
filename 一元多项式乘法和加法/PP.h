#ifndef _PP_
#define _PP_
typedef struct PolyNode {
	int coef;
	int expon;
	struct PolyNode* link;
}*Polynomial;
void Attach(int c, int e, Polynomial* pRead);
Polynomial ReadPloy();
Polynomial PolyAdd(Polynomial p1, Polynomial p2);
Polynomial Mult(Polynomial p1, Polynomial p2);
void PrintPoly(Polynomial p);


#endif

