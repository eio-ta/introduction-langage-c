#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>



char *palindrome(const char *s) {
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


char *motLePlusGrand(char *s) {
    // On essaie de reprérer le premier espace !
    int indiceAncienEspace = -2;
    // Il n'y a pas d'espace à s[0]
    if(isalpha(s[0])) indiceAncienEspace = -1;
    char *res;
    char *tmp; // Curseur qui va trouver tous les mots
    int cmpMot = 0;
    
    // On parcourt la liste
    for(int i=0; i<strlen(s); i++) {
        // On repère le 1r espace
        if(isspace(s[i]) && indiceAncienEspace == -2) {
            indiceAncienEspace = (indiceAncienEspace == -1 ? -1 : i);
        // On trouve le 2e espace
        } else if(isspace(s[i]) && indiceAncienEspace != -2) {
            // d = Taille du mot
            int d = i-indiceAncienEspace+1;
            // On réécrit le mot
            tmp = malloc((d+1)* sizeof(char));
            assert(tmp);
            int cmp = 0;
            for(int j=indiceAncienEspace+1; j<i; j++) {
                tmp[cmp] = s[j];
                cmp++;
            }
            
            // On cherche quel mot est mieux
            // c'est le premier mot
            if(cmpMot == 0) {
                res = malloc((d+1)* sizeof(char));
                assert(res);
                int cmp = 0;
                for(int j=indiceAncienEspace+1; j<i; j++) {
                    res[cmp] = s[j];
                    cmp++;
                }
                cmpMot++;
            // Sinon on compare avec la solution
            } else {
                // Si tmp est mieux que le résultat, alors on change la solution
                if(strcmp(tmp, res) > 0) {
                    res = malloc((d+1)* sizeof(char));
                    assert(res);
                    int cmp = 0;
                    for(int j=indiceAncienEspace+1; j<i; j++) {
                        res[cmp] = s[j];
                        cmp++;
                    }
                    cmpMot++;
                }
			}
            indiceAncienEspace = i;
            free(tmp);
        }
    }
    return res;
}

int main(void) {
	char phrase[] = "anemarie\0";
	char p2[] = "ala ma psa i kota \0";
	printf("%s\n", palindrome(phrase));
	printf("%s\n", motLePlusGrand(p2));
}
