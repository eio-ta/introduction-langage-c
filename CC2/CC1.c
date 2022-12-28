#include<stdio.h>

/* Elody TANG
 * Numero etudiant : 21953199
 * Groupe de TD : Math Info 1
*/

#define DEG 6

typedef struct {
	int degre;
	int coef[DEG];
} poly;


// Fonction pour afficher un monome - EXO 2
void print_monome(int coeff, int degre) {
	printf("%+dx^%d", coeff, degre);
}


// Fonction pour afficher un polynome
void print_poly(poly p) {
	if(p.degre == 0) {
		print_monome(p.coef[0], 0);
	} else {
		for(int i=0; i<p.degre+1; i++) {
			if(p.coef[i] != 0) {
				print_monome(p.coef[i], i);
			}
		}
	}
	printf("\n");
}

// Fonction qui retourne la somme de deux polynomes p et q
poly add(poly p, poly q) {
	
	// Calcul des coefficients
	int somme_coef[DEG];
	
	for(int i=0; i<DEG; i++) {
		somme_coef[i] = p.coef[i] + q.coef[i];
	}
	
	// Recherche du plus grand degre
	int somme_degre = 0;
	for(int i=DEG-1; i>0; i--) {
		if(somme_coef[i] == 0 && somme_coef[i-1] != 0) {
			somme_degre = i-1;
			break;
		}
	}
	
	poly s = {.degre = somme_degre, .coef = {somme_coef[0], somme_coef[1], somme_coef[2], somme_coef[3], somme_coef[4], somme_coef[5]}};
	return s;
}


// Fonction MAIN
int main(void) {
	
	// EXERCICE 1
	poly p = {.degre = 4, .coef = {2, 0, -3, 0, 7, 0}};
	poly q = {.degre = 4, .coef = {-3, 1, 0, -6, -7}};
	poly test = {.degre = 0, .coef = {0, 0, 0, 0, 0, 0}};
	
	// EXERCICE 2
	print_poly(p);
	print_poly(q);
	print_poly(test);
	
	// EXERCICE 3
	print_poly(add(p, q));
	int test_degre = add(p, q).degre;
	printf("Degre de l'addition entre p et q : %d\n", test_degre);
	
}
