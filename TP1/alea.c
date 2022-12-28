#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void stat(int m, int n){
    int x, i, j;
    if( m > n){
        printf("Erreur : m > n\n");
        return;
    }
    
    i = j = 0;
    x = rand() % (n + m/2);
    while(x <= n){
        if(x < m){
            i++;
        }
        else {
            j++;
        }
    x = rand() % (n + m/2);  
    }
    
    if (i + j == 0){
        printf("Aucun nombre aléatoire tiré\n");
    }
    else{
        printf("%d nombres aléatoires ont été tirés, %d sont dans l'intervalle [0, %d] (soit %.2f %%) et %d dans l'intervalle [%d, %d] (soit %.2f %%).\n", i + j, i, m, 100. * i / (i + j), j, m , n, 100. * j / (i + j));
    }
    return;
}

int main(void) {
	srand(time(NULL));
	int alea = rand();
	printf("%d", alea);
	if(alea%2 == 0) {
		printf(" est un entier pair.\n");
	} else {
		printf(" est un entier impair.\n");
	}
	stat(10, 13);
}
