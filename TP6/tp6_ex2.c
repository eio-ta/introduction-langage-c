#include<stdio.h>
#include <assert.h>
#include<string.h>
#include <ctype.h>
#include<stdlib.h>

// Fonction renvoyant le nombre de mots de la chaîne d'adresse s
int nbr_words(const char *s) {
	assert(s[strlen(s)-2] != '\0');
	
	int cmp = 0;
	for(int i=0; i < strlen(s); i++) {
		if(!(isspace(s[i])) && (isspace(s[i+1]) || s[i+1] == '\0')) {
			cmp++;
		}
	}
	
	return cmp;
}

// Fonction qui compte le nombre de caractère du mot
int word_len(const char *w) {
	int cmp = 0;
	for(int i=0; *(w+i) != '\0'; i++) {
		if(isspace(*(w+i))) return cmp;
		cmp++;
	}
	return cmp;
}

// Fonction pour extraire un mot 
char *extract_word(const char *w, int *pl) {
	int l = word_len(w);
	char *c = malloc((l+1) * sizeof(char));
	if(c == NULL) return NULL;
	for(int i=0; i<l; i++) {
		c[i] = *(w+i);
	}
	c[l] = '\0';
	*pl = l;
	return c;
}


int main() {
	char *s;
	s = "a aa ba a bbb\0";
	printf("Nombre mots dans 'a aa ba a bbb' : %d\n", nbr_words(s));
	printf("Nombre mots dans 'bbb' : %d\n", word_len(s+2));
	int pl;
	char *res;
	res = extract_word(s+2, &pl);
	printf("%s", res);
	
}
