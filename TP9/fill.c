#include<stdio.h>
#include <stdlib.h>
#include <assert.h>

void ajout_lignes_1(int argc, char *argv[]) {
	FILE *f = fopen(argv[1], "w");
	assert(f);
	char *s = "BeaucoupDeLignes\n\0";
	int n = atoi(argv[2]);
	while(n != 0) {
		fputs(s, f);
		n--;
	}
	fclose(f);
}

void ajout_lignes_2(int argc, char *argv[]) {
	FILE *f = fopen(argv[1], "a");
	assert(f);
	char *s = "BeaucoupDeLignes\n\0";
	int n = atoi(argv[2]);
	while(n != 0) {
		fputs(s, f);
		n--;
	}
	fclose(f);
}

int main(int argc, char *argv[]) {
	// ajout_lignes_1(argc, argv);
	ajout_lignes_2(argc, argv);
}
