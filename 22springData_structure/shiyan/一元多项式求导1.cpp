#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef int Status;
typedef int Elemtype;
typedef struct Node *List;

typedef struct Node {
	Elemtype coef;
	Elemtype expon;
	struct Node *next;
} Node, *linkNode;

Status initlist(linkNode &L) {
	L = new Node;
	L->next = NULL;
	return 1;
}

int Length(linkNode &L) {
	int len = 0;
	Node *p;
	p = L->next;

	while (p) {
		len++;
		p = p->next;
	}

	return len;
}

void readlist(linkNode &L) {
	L = new Node;
	L->next = NULL;
	Node *r, *p;
	r = L;
	p = new Node;
	Elemtype c, x;

	while ( scanf("%d%d", &c, &x) != EOF ) {
//	while (cin >> c >> x) {
//		if (c == '\n')
//			break;

		p = new Node;
		p->coef = c;
		p->expon = x;
		p->next = NULL;
		r->next = p;
		r = p;
	}
}

void derivelist(linkNode &L1, linkNode &L2) {
	Node *p;
	p = L1->next;
	Node *cur, *rear;
	cur = L2;
	rear = new Node;

	while (p) {
		if (p->coef != 0 && p->expon != 0) {
			rear = new Node;
			rear->coef = (p->coef) * (p->expon);
			rear->expon = p->expon - 1;
			rear->next = NULL;
			cur->next = rear;
			cur = rear;
		}

		p = p->next;
	}
}

void printlist(linkNode &L) {
	if (!Length(L))
		cout << "0 0";
	else {
		Node *p;
		p = L->next;

		while (p) {
			if (p->next != NULL)
				cout << p->coef << " " << p->expon << " ";
			else
				cout << p->coef << " " << p->expon << endl;

			p = p->next;
		}
	}
}

int main() {
	linkNode L1, L2;
	initlist(L1);
	initlist(L2);

	readlist(L1);
	derivelist(L1, L2);
	printlist(L2);
	return 0;
}