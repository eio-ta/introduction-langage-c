#include<stdio.h>

// Affiche les elements d'un tableau - EXO 1
void affiche_tab(int tab[], int len) {
	for(int i=0; i<len; i++) {
		printf("%d ", tab[i]);
	}
}

// Renvoie les indices des plus petits et plus grand éléments du tableau tab de taille n
void minmax(int n, int tab[], int *pmin, int *pmax) {
	for(int i=0; i<n; i++) {
		*pmin = (tab[i]<tab[*pmin])? i : *pmin;
		*pmax = (tab[i]>tab[*pmax])? i : *pmax;
	}
}

// Donne le nombre d'occurence de e et l'indice de sa premiere occurence
void occurences(int n, int tab[], int e, int *pocc, int *first) {
	for(int i=0; i<n; i++) {
		*pocc += (tab[i] == e)? 1 : 0;
		*first = (tab[i] == e && *first == -1)? i : *first; 
	}
}

// Renvoie l'adresse de la case du tableau qui contient cette premiere occurence
void occurences_bis(int n, int tab[], int e, int *pocc, int **first) {
	int ind = -1;
	occurences(n, tab, e, pocc, &ind);
	int *f = &tab[ind];
	first = &f;
}


int main(void) {
	int tab[] = {0, 1, 1, 3, 3, 5, 6, 7, -2};
	int n = 9;
	int min = 0;
	int max = 0;
	minmax(n, tab, &min, &max);
	affiche_tab(tab, n);
	printf("\n\nValeur de pmin : %d\n", min); // attendu 8 
	printf("Valeur de pmax : %d\n\n", max); // attendu 7
	
	int first = -1;
	int nb_occ = 0;
	occurences(n, tab, 3, &nb_occ, &first);
	printf("Nombre d'occurence de 3 : %d\n", nb_occ); // attendu 2 
	printf("Premier indice de 3 : %d\n\n", first); // attendu 3
	
	int **f;
	nb_occ = 0;
	occurences_bis(n, tab, 3, &nb_occ, f);
	printf("Adresse de la premiere case du tableau qui contient : %p", &f);
	
	
}
