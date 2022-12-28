#include<stdio.h>

#define LEN 12

// Echange les valeurs aux adresses pa et pb - EXO 1
void swap(int *pa, int *pb) {
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

// Affiche les elements d'un tableau - EXO 1
void affiche_tab(int tab[], int len) {
	for(int i=0; i<len; i++) {
		printf("%d ", tab[i]);
	}
	printf("\n");
}

// Trie les entiers stockes entre les indices start (inclus) et end (exclus)
void sort(int tab[], int start, int end) {
	if(start < end) {
		for(int i=start; i<=end-2; i++) {
			if (tab[i] > tab[i+1]) swap(&tab[i], &tab[i+1]);
		}
		sort(tab, start, end-1);
	}
}

// Trie les entiers stockes entre les indices start (inclus) et end (exclus) avec des pointeurs
void sort_point(int tab[], int *start, int *end) {
	if(start < end) {
		for(int *i=start; i<=end-2; i++) {
			if (*i > *(i+1)) swap(i, i+1);
		}
		sort_point(tab, start, end-1);
	}
}

void opt_sort(int tab[], int *start, int *end) {
	// Reprenons le meme algorithme avec l'amelioration
	if(start < end) {
		int b_permu = 0;
		for(int *i=start; i<=end-2; i++) {
			if (*i > *(i+1)) {
				swap(i, i+1);
				b_permu = 1;
			}
		}
		if(b_permu) opt_sort(tab, start, (end-1));
	}
}


int main(void) {
	int tab[] = {3,8,1,50,3,9,0,4,5,6,-7,9};
	affiche_tab(tab, LEN);
	opt_sort(tab,&tab[3], &tab[10]);
	affiche_tab(tab, LEN);
}
