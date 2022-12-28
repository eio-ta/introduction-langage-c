#include<stdio.h>
#include <assert.h>
#include<string.h>
#include <ctype.h>
#include<stdlib.h>

/* TANG Elody MATH INFO 1
 * 21953199
 */
 
// Fonction auxilaire qui recupere le nombre de lettres dans le mot sans x
 int combien_de_lettres_sans_x(const char *s, char x) {
	assert(s[strlen(s)-1] != '\0');
	int cmp = 0;
	for(int i=0; i<strlen(s); i++) {
		if(s[i] == x) cmp++;
	}
	return strlen(s)-cmp;
}

// Fonction auxiliaire qui inverse le mot
char *inverse(const char *s) {
	assert(s[strlen(s)-1] != '\0');
	char *c = malloc((strlen(s)+1)* sizeof(char));
	if(c == NULL) return NULL;
	int cmp = 0;
	for(int i=strlen(s)-1; i>=0; i--) {
		c[cmp] = s[i];
		cmp++;
	}
	c[strlen(s)] = '\0';
	
	return c;
}
 
// Fonction qui enleve toutes les x du mot
char *sans_lettre(const char *s, char x) {
	if(strlen(s) == 0) {
		char *c = malloc(1*sizeof(char));
		c[0] = '\0';
		return c;
	}
	assert(s[strlen(s)-1] != '\0');
	int str = combien_de_lettres_sans_x(s, x);
	char *c = malloc((str+1)*sizeof(char));
	if(c == NULL) return NULL;
	int cmp = 0;
	for(int i=0; i<strlen(s); i++) {
		if(s[i] != x) {
			c[cmp] = s[i];
			cmp++;
		}
	}
	return inverse(c);
}



// Fonction MAIN
int main() {
	char pres[] = "CC2 de Langage C - Partie 1\0";
	printf("%s\n", pres);
	char *q;
	q = "ala ma kota\0";
	printf("%s\n", sans_lettre(q, 'a'));
	q = "aaaaaaaaa \0";
	printf("%s\n", sans_lettre(q, 'a'));
	q = "\0";
	printf("%s\n", sans_lettre(q, 'a'));
}
