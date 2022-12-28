#include<stdio.h>
#include<stdlib.h>


// Affiche tous les éléments entre a et b dans le tableau 
void affiche (int t[], int a, int b) {
	for (int i = a; i < b - 1; i++) {
		printf ("%d, ", t[i]);
	}
	printf("%d\n", t[b - 1]);
}


// Créer un tableau de taille n et remplit en fonction de a
int  *build_tab (int a, int n) {
	//int t[n];
	int *t;
	t = malloc (n * sizeof (int));
	for (int i = 0; i < n; i++) {
		t[i] = a + i;
	}
	printf ("t : %p : ", t); // TEST
	affiche (t, 0, 15); // TEST
	return t; // WARNING!
}


int main () {
	// Pas d'erreur de compilation, ni d'erreur d'éxécution
	int t[] = {1, 2, 3, 4};
	affiche (t, 0, 4);
	affiche (t, 0, 6);
	affiche (t, -2, 4);
	
	// ERREUR AFFICHÉ : warning: function returns address of local variable [-Wreturn-local-addr]
	printf ("\nbuild tab\n");
	int *tab = build_tab (0, 15);
	printf ("tab : %p\n", tab);
	// affiche (tab, 0, 15); // SEG_FAULT!
	
	return 0;
}
