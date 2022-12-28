#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define N 10
#define M 15

void aff_tab(int nb, int tab[]){
  for(int i=0; i < nb; i++){
    printf("%d ",tab[i]);
  }
}

int max(int tab[]) {
	int m = -1, i;
	for(i = 0; i<M; i++) {
		if(m<tab[i]) m = tab[i];
	}
	return m;
}

int main(void) {
	srand(time(NULL));
	int tab[M], i;
	for(i = 0; i < M; i++) {
		tab[i] = rand()%N;
	}
	aff_tab(M, tab);
	printf("\nNombre le plus grand du tableau : %d\n", max(tab));
}


