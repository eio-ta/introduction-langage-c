#include<stdio.h>
#include <stdlib.h>

typedef struct element element;
struct element {
	int val;
	element *next;
	element *previous;
};


// Code une liste vide
element *cons_list() {
	element *e = malloc(sizeof(element) + 1);
	if(e == NULL) return NULL;
    e->previous = e;
    e->next = e;
    return e;
}

// Ajoute un élément en début de liste
void add_fst_list(element *L, int v) {
	if(L == NULL) return;
    element *debut = malloc(sizeof(element) + 1);
    if(debut == NULL) return;
    debut->val = v;
    debut->next = L->next;
    debut->previous = L;
    L->next->previous = debut;
    L->next = debut;
}

// Ajoute un élément en fin de liste
void add_lst_list(element *L, int v) {
	if(L == NULL) return;
	element *fin = malloc(sizeof(element) + 1);
	if(fin == NULL) return;
	fin->val = v;
    fin->next = L;
    fin->previous = L->previous;
    L->previous->next = fin;
    L->previous = fin;
}

// Renvoie 1 si la liste L est vide sinon 0
int isempty_list(element *L) {
	if(L == NULL) return 0;
	return (L == L->next);
}

// Renvoie la longueur de la liste
int len_list(element *L) {
	if(L == NULL) return 0;
	int t = 0;
    for (element *aux = L->next; aux != L; aux = aux->next) {
        t++;
    }
    return t;
}

// Afficher la liste
void print_list(element *L) {
	if(L == NULL) return;
    for(element *aux = L->next; aux != L; aux = aux->next) {
        printf("%d ", aux->val);
    }
    printf("\n");
}

// Supprime le premier élément de la liste
int del_fst_list(element *L) {
	if(L == NULL) return 0;
    if(isempty_list(L)) {
		printf("La liste est vide\n");
        return 0;
    }
    int valeur = L->next->val;
    element *elemRemove;
    elemRemove = L->next;
    element *tmp;
    tmp = L->next->next;
    L->next = tmp;
    tmp->previous = L;
    free(elemRemove);
    return valeur;
}

// Supprime le dernier element de la liste
int del_lst_list(element *L) {
	if(L == NULL) return 0;
    if(isempty_list(L)) {
		printf("La liste est vide\n");
        return 0;
    }
    int valeur = L->previous->val;
    element *elemRemove;
    elemRemove = L->previous;
    element *tmp;
    tmp = L->previous->previous;
    L->previous = tmp;
    tmp->next = L;
    free(elemRemove);
    return valeur;
}

// Libère toute la mémoire allouée
void free_list(element *L) {
    if(L == NULL) return;
    element *aux = L->next, *tmp;
    while (aux != L) {
        tmp = aux->next;
        free(aux);
        aux = tmp;
    }
    free(L);
}

// Copie une liste
element *copy_list(element *L) {
	element *copy = cons_list();
	for(element *aux = L->next; aux != L; aux = aux->next) {
		add_lst_list(copy, aux->val);
	}
	return copy;
}

// Insert un element avant le maillon p
void insert_prev_list(element *p, int v) {
    add_fst_list(p, v);
}

// Insert un element avant le maillon p
void insert_next_list(element *p, int v) {
    add_lst_list(p, v);
}

// Detruit le maillon pointé par p
void del_list(element *p) {
	p->previous->next = p->next;
	p->next->previous = p->previous;
	free(p);
}

// Cherche si la valeur v est contenue dans la liste L
element* get_elet_list(element* L, int v) {
	element *tmp;
	tmp = L->next;
	while(tmp->val != L->val) {
		if(tmp->val == v) return tmp;
		tmp = tmp->next;
	}
	return NULL;
}

// Concatenation de listes
void concat_list(element *l1, element *l2) {
	element *first1;
	first1 = l1->next;
	
	l1->next = l2->next;
	l2->previous->next = first1;
	first1->previous = l2->previous;
	l2->next->previous = l1;
}

// Cherche la valeur v dans ieme indice dans la liste L
element* get_val_list(element* L, int i) {
	element *tmp;
	tmp = L;
	while(i != 0) {
		tmp = tmp->next;
		i--;
	}
	return tmp;
}

// Fonction Main
int main(int argc, char *argv[]) {
	element *liste = cons_list();
    print_list(liste);
	// On ajoute les éléments
    for(int i=1; i<argc-1; i++) {
		add_fst_list(liste, atoi(argv[i]));
	}
	add_lst_list(liste, atoi(argv[argc-1]));
	
	// On vérifie si la liste est vide
    if (isempty_list(liste)) printf("La liste est vide\n");
    else printf("La liste n'est pas vide\n");
    printf("Taille de la liste : %d\n", len_list(liste));
    print_list(liste);
    
    // On supprime le premier element
    printf("Valeur supprimée : %d\n", del_fst_list(liste));
    print_list(liste);
    printf("Taille de la liste : %d\n", len_list(liste));
    
    // On supprime le premier element
    printf("Valeur supprimée : %d\n", del_lst_list(liste));
    print_list(liste);
    printf("Taille de la liste : %d\n", len_list(liste));
    
    // COpie d'une liste
    element *copy;
    copy = copy_list(liste);
    print_list(copy);
    
    // On ajoute après la première valeur
    //insert_prev_list(liste+2, 10);
    //print_list(liste);
    //printf("Taille de la liste : %d\n", len_list(liste));
    
    
    // On essaie de récupérer le maillon d'une valeur
    element *tmp;
    tmp = get_elet_list(copy, 2);
    printf("Valeur récupéré : %d\n", tmp->val);
    
    // On essaie de récupérer le maillon de la ieme place
    tmp = get_val_list(copy, 3);
    printf("Valeur récupéré : %d\n", tmp->val);
    
    // On essaie de récupérer le maillon de la ieme place
    concat_list(liste, copy);
    print_list(liste);
    
    
}
