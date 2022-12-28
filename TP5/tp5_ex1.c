#include<stdio.h>
#include<stdlib.h>

typedef struct pile_amortie {
	int occupation;
	int capacite;
	int *elements;
} pile_amortie;


pile_amortie *alloue_pile_amortie() {
	pile_amortie m;
	pile_amortie *p = &m;
	p->occupation = 0;
	p->capacite = 1;
	p->elements = (int *) malloc(sizeof(int));
	if(p->elements != NULL) return NULL;
	return p;
}

void libere_pile_amortie(pile_amortie *pile) {
	free(pile->elements);
}

int emplile_pile_amortie(pile_amortie *pile, int n) {
	pile->occupation++;
	int *tab;
	if(pile->capacite >= pile->occupation) {
		tab = realloc(pile->elements, pile->capacite*2);
		if(tab == NULL) return 0;
		int i = 0;
		for(i=0; i<pile->occupation-1; i++) {
			 tab[i] = pile->elements[i];
		}
		tab[i+1] = n;
		pile->elements = tab;
		pile->capacite = pile->capacite*2;
		return 1;
	} else {
		tab = malloc((pile->capacite+1) * sizeof(int));
		if(tab == NULL) return 0;
		int i = 0;
		for(i=0; i<pile->occupation-1; i++) {
			 tab[i] = pile->elements[i];
		}
		tab[i+1] = n;
		pile->elements = tab;
		return 1;
	}
}

int depile_pile_amortie(pile_amortie *pile, int *e) {
	pile->occupation--;
	int *tab;
	tab = malloc((pile->capacite-1) * sizeof(int));
	if(tab == NULL) return 0;
	for(int i=0; i<pile->occupation; i++) {
		 tab[i] = pile->elements[i];
	}
	pile->elements = tab;
	return 1;
}

pile_amortie *copie_pile_amortie(pile_amortie *pile) {
	pile_amortie m;
	pile_amortie *copy = &m;
	copy->capacite = pile->capacite;
	copy->occupation = pile->occupation;
	copy->elements = malloc(pile->capacite * sizeof(int));
	if(copy->elements == NULL) return NULL;
	for(int i=0; i<pile->occupation; i++) {
		 copy->elements[i] = pile->elements[i];
	}
	return copy;
}

void afficher_pile(pile_amortie *pile) {
	printf("Occupation : %d\n", pile->occupation);
	printf("Capacite : %d\n", pile->capacite);
	for(int i=0; i<pile->capacite; i++) {
        printf("%d ", pile->elements[i]);
    }
}

int main() {
	pile_amortie *p;
	p = alloue_pile_amortie();
	afficher_pile(p);
}
