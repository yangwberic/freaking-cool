#include<stdio.h>
#include"PP.h"

void Attach(int c, int e, Polynomial* pRead)
{
	Polynomial p;
	p = (Polynomial)malloc(sizeof(struct PolyNode));
	p->coef = c;
	p->expon = e;
	p->link = NULL;
	(*pRead)->link = p;
	*pRead = p;
}

Polynomial ReadPloy() {
	Polynomial p, t, Rear;
	int N, c, e;
	p = (Polynomial)malloc(sizeof(struct PolyNode));
	p->link = NULL; 
	Rear = p;
	scanf_s("%d", &N);
	while (N--) {
		scanf_s("%d %d", &c, &e);
		Attach(c, e, &Rear);
	}
	t = p; p = p->link; free(t);
	return p;
}

Polynomial PolyAdd(Polynomial p1, Polynomial p2)
{
	Polynomial front, rear, temp;
	rear = (Polynomial)malloc(sizeof(struct PolyNode));
	front = rear;
	int sum;
	while (p1 && p2) {
		switch (Compare(p1->expon, p2->expon)) {
		case 1:
			Attach(p1->coef, p1->expon, &rear);
			p1 = p1->link;
			break;
		case -1:
			Attach(p2->coef, p2->expon, &rear);
			p2 = p2->link;
			break;
		case 0:
			sum = p1->coef + p2->coef;
			if (sum)Attach(sum, p1->expon, &rear);
			p1 = p1->link;
			p2 = p2->link;
			break;
		}
	}
	for (; p1; p1 = p1->link)Attach(p1->coef, p1->expon, &rear);
	for (; p2; p2 = p2->link)Attach(p2->coef, p2->expon, &rear);
	rear->link = NULL;
	temp = front;
	front = front->link;
	free(temp);
	return front;
}

Polynomial Mult(Polynomial p1, Polynomial p2) {
	Polynomial p, Rear, t1, t2, t;
	int c, e;

	if (!p1 || !p2) return NULL;

	t1 = p1; t2 = p2;
	p = (Polynomial)malloc(sizeof(struct PolyNode));
	Rear = p;
	while (t2) {
		Attach(t1->coef * t2->coef, t1->expon + t2->expon, &Rear);
		t2 = t2->link;
	}
	t1 = t1->link;
	while (t1) {
		t2 = p2; Rear = p;
		while (t2) {
			e = t1->expon + t2->expon;
			c = t1->coef * t2->coef;
			while (Rear->link && Rear->link->expon > e) {
				Rear = Rear->link;
			}
			if (Rear->link && Rear->link->expon == e) {
				if (Rear->link->coef + c) {
					Rear->link->coef += c;
				}
				else {
					t = Rear->link;
					Rear->link = t->link;
					free(t);
				}
			}
			else {
				t = (Polynomial)malloc(sizeof(struct PolyNode));
				t->coef = c; t->expon = e;
				t->link = Rear->link;
				Rear->link = t; Rear = Rear->link;
			}
			t2 = t2->link;
		}
		t1 = t1->link;
	}
	t2 = p; p = p->link; free(t2);
	return p;
}

void PrintPoly(Polynomial p) {
	int flag = 0;
	if (!p)printf("0 0\n"); return;
	while (p) {
		if (!flag)
			flag = 1;
		else
			printf(" ");
		printf("%d %d", p->coef, p->expon);
		p = p->link;
	}
}
