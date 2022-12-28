#include<stdio.h>

#define N 8
#define m 27

int tmp_vol(int nb) {
	int tab[N], i = 0;
	tab[0] = nb;
	while(tab[i] != 1) {
		if(tab[i]%2 == 0) {
			tab[i+1] = tab[i]/2;
		} else {
			tab[i+1] = (3*tab[i])+1;
		}
		i++;
	}
	return i;
}

void aff_tab(int nb, int tab[]){
  for(int i=0; i < nb; i++){
    printf("%d : %d \n",tab[i], tmp_vol(tab[i]));
  }
}

void aff_1_A_N() {
	int i;
	for(i=1; i<N; i++) {
		printf("%d : %d\n", i, tmp_vol(i));
	}
}


int main(void) {
	/*int tab[N], i;
	tab[0] = m;
	for(i = 0; i < (N-1); i++) {
		if(tab[i]%2 == 0) {
			tab[i+1] = tab[i]/2;
		} else {
			tab[i+1] = (3*tab[i])+1;
		}
	}
	aff_tab(N, tab);*/
	aff_1_A_N();
}
