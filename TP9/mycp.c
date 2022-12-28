#include<stdio.h>
#include <assert.h>

int copie(FILE *fsrc, FILE *fdst) {
	rewind(fsrc);
	assert(fsrc);
	int i = 0;
	while((i = fgetc(fsrc)) != EOF) {
		fputc(i, fdst);
	}
	return 1;
}

int main(int argc, char *argv[]) {
	FILE *f1 = fopen(argv[1], "r");
	FILE *f2 = fopen(argv[2], "w");
	copie(f1, f2);
}
