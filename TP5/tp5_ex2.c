#include<stdio.h>

// affiche un numbre entier (addresse en memoire en hexa et en decimale)
#define affiche_nbr(a) printf("%p (%lu)\n", a, (unsigned long) a)

char c1 = 'a';
char c2 = 'z';
int i1 = 0;
int i2 = 0;
int *p1;
int *p2;

void f() {
	char ch1 = 'e';
	char ch2 = 'r';
	int in1 = 0;
	int in2 = 3;
	int *po1;
	int *po2;
	
	affiche_nbr(&ch1);
	affiche_nbr(&ch2);
	affiche_nbr(&in1);
	affiche_nbr(&in2);
	affiche_nbr(po1);
	affiche_nbr(po2);
}

void f1(int *p) {
	int i = 7;
	char a = 'A';
	affiche_nbr(p);
	printf("%d\n", i);
	affiche_nbr(&i);
	printf("%c\n", a);
	affiche_nbr(&a);
	p = NULL;
}

void f2(int *p) {
	int i;
	char c;
	
	affiche_nbr(p);
	affiche_nbr(&i);
	affiche_nbr(&c);
	printf("%d\n", i);
	printf("%c\n", c);
}


int main() {
	f();
	printf("\n");
	affiche_nbr(&c1);
	affiche_nbr(&c2);
	affiche_nbr(&i1);
	affiche_nbr(&i2);
	affiche_nbr(p1);
	affiche_nbr(p2);
	printf("\n");
	printf("\%zu\n", sizeof(int));
	printf("\%zu\n", sizeof(char));
	printf("\%zu\n", sizeof(int *));
	printf("\n");
	p1 = &i1;
	f1(p1);
	f2(p1);
}

