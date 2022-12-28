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

int main() {
	FILE *f1 = fopen("./src.txt", "r");
	FILE *f2 = fopen("./dst.txt", "w");
	copie(f1, f2);
	fclose(f1);
	fclose(f2);
}
