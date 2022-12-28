#include<stdio.h>

typedef struct {
	int x, y;
} paire;

int main() {
	int a = 2;
	void *pt = &a;
	*(int *) pt = 42;
	*(int *) pt = a * a;
	printf("%d\n", a);
	
	paire b = {.x = 1, .y = 2};
	pt = &b;
	((paire *) pt)->y ++;
	printf("%d\n", b.y);
}
