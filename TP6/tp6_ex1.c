#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

/*
void f1 (const char *s) {
	for(int i = 0; s[i] != "\0"; i++)
	printf ("%c", s[i]);
}
*/

void f2 (const char *s) {
	for(; *s; s++)
	printf("%c", *s);
}

/*
char *g1 (const char *s) {
	char *t;
	strcpy (t, s);
	return t;
}
*/

char *g2 (const char *s) {
	char *t = malloc (strlen (s));
	if(t == NULL) return NULL;
	strcpy (t, s);
	return t;
}


char *g3 (const char *s) {
	char *t = malloc (strlen (s) + 1);
	if(t == NULL) return NULL;
	strcpy (t, s);
	return t;
}


int main() {
	char *s;
	s = " a aa ba a bbb\0";
	f2(s);
	f2(g3(s));
	
}
