#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define NBC 5

enum etat {VALIDEE, ENCOURS, EXPEDIEE};

struct comm {
	int numeroC;
	int prix_exp;
	int prix_prod;
	enum etat etatC;
};

typedef struct comm commande;

/*Renvoie une commande aléatoire*/
commande comAlea(int num) {
	commande c = { .numeroC = num, .prix_exp = rand()%20+1, .prix_prod = rand()%2000+1, .etatC = rand()%3};
	return c;
}

/*Affiche une commande c*/
void affCommande(commande c) {
	printf("Commande numero %d\n", c.numeroC);
	printf("Prix d'expedition : %d\n", c.prix_exp);
	printf("Prix du produit : %d\n", c.prix_prod);
	switch(c.etatC) {
		case 0 :
			printf("Etat : VALIDEE\n\n");
			break;
		case 1 :
			printf("Etat : EN COURS\n\n");
			break;
		default :
			printf("Etat : EXPEDIEE\n\n");
			break;
	}
}

/*Affiche les commandes expediees*/
void affExpediees(commande T[],int taille) {
	for(int i=0; i<taille; i++) {
		if(T[i].etatC == 2) {
			affCommande(T[i]);
		}
	}
}

/*Renvoie le nombre de commandes en cours*/
int nbCEC(commande T[],int taille) {
	int cmp = 0;
	for(int i=0; i<taille; i++) {
		if(T[i].etatC == 1) {
			cmp++;
		}
	}
	return cmp;
}

/*Renvoie le cout total d'expedition des commandes validees*/
int coutVal(commande T[],int taille) {
	int cost = 0;
	for(int i=0; i<taille; i++) {
		if(T[i].etatC == 0) {
			cost += T[i].prix_exp;
		}
	}
	return cost;
}

int main(void) {
	srand(time(NULL));
	commande tab[NBC] = {comAlea(1)};
	for(int i=0; i<NBC; i++) {
		tab[i] = comAlea(i);
	}
	affExpediees(tab,NBC);
	printf("Nombre de commande expediees : %d\n", nbCEC(tab, NBC));
	printf("Cout total d'expidition des commandes validees : %d\n", coutVal(tab, NBC));
}
