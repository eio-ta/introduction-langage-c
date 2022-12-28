#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int nbr;
	char **words;
} w_index;



// Libère l'espace mémoire
void free_index(w_index *pi) {
	free(pi->words);
	free(pi);
}

int size_words(w_index *pi) {
	int cmp = 0;
	printf("test");
	for(int i=0; i<pi->nbr; i++) {
		// cmp += strlen(pi->words[i]);
		printf("test");
	}
	return cmp;
}



int main() {
	w_index *def;
	def->nbr = 3;
	size_words(def);
	// printf("%d", size_words(def));
	
}
