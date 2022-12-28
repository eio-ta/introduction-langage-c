#include<stdio.h>

#define N 100

void aff_tab(int nb, int tab[]){
  for(int i=0; i < nb; i++){
	  if(tab[i] != 0) printf("%d ",tab[i]);
  }
}

int main(void) {
	int tab[N], i, j;
	tab[0] = tab[1] = 0;
	for(i = 2; i<N; i++) {
		tab[i] = i;
		for(j = 2; j<i; j++) {
			if(i%j == 0) tab[i] = 0;
		}
	}
	aff_tab(N, tab);
	
}
