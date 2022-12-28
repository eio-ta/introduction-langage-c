#include<stdio.h>
#include<stdlib.h>
#include <assert.h>

void *memmove(void *dst, const void *src, size_t n);

typedef struct array {
    int *ptr;
    int size;
} array;


// Affiche les éléments d'un tableau dynamique
void array_print(array *p) {
    for(int i = 0; i < p->size; i++) {
        printf ("%d ", p->ptr[i]);
    }
}

// Alloue et retroune l'adresse d'un array de taille n
array *array_init(int n) {
	array m = {NULL, 0};
	array *p = &m;
    p->size = n;
    p->ptr = (int *)malloc((n+1)* sizeof(int));

	if(p->ptr == NULL) {
		return NULL;
	}	
	
    return p;
}

// Libère la zone-mémoire allouée d'un tableau dynamique
void array_destroy(array *t) {
    free(t);
}


// Retourne la valeur à l'indice index
int array_get(array *t, int index) {
	return t->ptr[index];
}

// Change la valeur de la valeur à l'indice index
void array_set(array *t, int index, int valeur) {
	assert(index >= 0 && index <= t->size);
	t->ptr[index] = valeur;
}

// Ajoute un élément à l'indice index dans le tableau t
int array_insert(array *t, int index, int valeur) {
    assert(index >= 0 && index <= t->size);
    int *t1 = t->ptr;
    if(t1 == NULL) return 0;
    memmove(&t1[index+1], &t1[index], (t->size - index) * sizeof(int));
    t1[index] = valeur;


    array_destroy(t);
    t->ptr = t1;
    t-> size++;

    return 1;
}

// Supprime un élément à l'indice index
int array_erase(array *t, int index) {
    assert(index >= 0 && index < t->size);
    int *t1 = t->ptr;
    if(t1 == NULL) return 0;

    memmove(&t1[index], &t1[index+1], (t->size - index -1) *sizeof(int));
    array_destroy(t);

    t->ptr = t1;
    t-> size--;

    return 1;
}


int main() {
    array *t;
    t = array_init (10);
    array_print (t); // 10 valeurs aleatoires, mais exactement 10.
    printf("\n");
    
    for (int i = 0; i < t->size; i++) {
		array_set (t, i, i);
	}
	array_print (t);
	printf("\n"); // 0 1 2 3 4 5 6 7 8 9
	
	
	for (int i = 0; i < t->size; i++) {
		printf ("%d ", array_get (t, i));
	}
	printf ("\n"); // 0 1 2 3 4 5 6 7 8 9
	
	array_insert (t, 3, 42);
	array_print (t);
	printf("\n"); // 0 1 2 42 3 4 5 6 7 8 9
	
	array_insert (t, 11, 43);
	array_print (t);
	printf("\n"); // 0 1 2 42 3 4 5 6 7 8 9 43
	
	array_erase (t, 11);
	array_print (t);
	printf("\n"); // 0 1 2 42 3 4 5 6 7 8 9
	
	array_erase (t, 3);
	array_print (t);
	printf("\n"); // 0 1 2 3 4 5 6 7 8 9
	
	array_erase (t, 0);
	array_print (t);
	printf("\n"); // 1 2 3 4 5 6 7 8 9
	
	return 0;
}


