#include<stdio.h>

/* TANG Elody MATH INFO 1
 * 21953199
 */

typedef struct {
	int x;
	int y;
} point;

// Fonction qui deplace le point dans la direction dir
void translate(point *p, int dist, char dir) {
	if(dir == 'x') p->x += dist;
	if(dir == 'y') p->y += dist;
}

// Fonction qui fait translate sur tous les points
void translate_tab(int len, point v[], int dist, char dir) {
	for(int i=0; i<len; i++) {
		translate(&v[i], dist, dir);
	}
}

// Afficher le point
void afficher_point(point q) {
	printf("(%d, %d)\n", q.x, q.y);
}

// Fonction MAIN
int main() {
	char pres[] = "CC2 de Langage C - Partie 2\0";
	printf("\n\n");
	printf("%s\n", pres);
	point p[] = {(point){.x = 3, .y = 4}, (point){.x = -2, .y = -5}, (point){.x = 4, .y = -8}};
	
	for(int i=0; i<3; i++) {
		afficher_point(p[i]);
	}
	
	printf("\n\n");
	
	translate(&p[0], 10, 'x');
	translate_tab(2, p, -50, 'y');
	
	for(int i=0; i<3; i++) {
		afficher_point(p[i]);
	}
}
