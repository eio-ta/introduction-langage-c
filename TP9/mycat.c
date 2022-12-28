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
	if(argc == 1) {
		
	} else {
		int nb = argc-1;
		FILE *res = fopen("./res.txt", "r");
		for(int i=1; i<=nb; i++) {
			FILE *f = fopen(argv[i], "r");
			copie(f, res);
		}
		rewind(res);
		int i = 0;
		while((i = fgetc(res)) != EOF) {
			printf("%c", i);
		}
	}
	return 1;
}
