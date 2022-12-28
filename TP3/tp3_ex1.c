#include<stdio.h>

# define LEN 3

// Echange les valeurs aux adresses pa et pb
void swap(int *pa, int *pb) {
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

// Affiche les elements d'un tableau
void affiche_tab(int tab[]) {
	for(int i=0; i<LEN; i++) {
		printf("%d ", tab[i]);
	}
}

typedef struct {
	int x;
	int y;
} point;

point p = {.x=5, .y=20};

int main(void) {
	int x,y;
	x = 5;
	y = 6;
	printf("Valeur de x avant échange : %d\n", x);
	printf("Valeur y avant échange : %d\n", y);
	swap(&x, &y);
	printf("Valeur de x après échange : %d\n", x);
	printf("Valeur de y après échange : %d\n\n", y);
	
	int tab[] = {0, 1, 2};
	printf("Tableau avant échange : ");
	affiche_tab(tab);
	swap(&tab[0], &tab[LEN-1]);
	printf("\nTableau après échange : ");
	affiche_tab(tab);
	
	printf("\n\nValeur de p.x avant échange : %d\n", p.x);
	printf("Valeur p.y avant échange : %d\n", p.y);
	swap(&p.x, &p.y);
	printf("Valeur de p.x après échange : %d\n", p.x);
	printf("Valeur de p.y après échange : %d\n\n", p.y);
}
