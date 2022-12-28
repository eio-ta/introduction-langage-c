#include<stdio.h>
#include <assert.h>
#include <math.h>

struct fraction {
	long int num;
	long int den;
};

typedef struct fraction fraction;

struct point {
	fraction x;
	fraction y;
};

typedef struct point point;

/*Construit une fraction*/
fraction build(long int n, long int d) {
	assert(d != 0);
	fraction f = {.num = n, .den = d};
	return f;
}

/*Renvoie 1 si les deux fractions sont egales sinon 0*/ 
int eq(fraction f, fraction g) {
	return f.num*g.den == f.den*g.num;
}

/*Renvoie 1 si la fraction est un entier*/
int isInteger(fraction f) {
	return eq(f, build(f.num/f.den, 1));
}

/*Renvoie la somme entre 2 fractions*/
fraction sum(fraction f, fraction g) {
	fraction f_dem_commun = build(f.num*g.den, f.den*g.den);
	fraction g_dem_commun = build(g.num*f.den, g.den*f.den);
	return build(f_dem_commun.num + g_dem_commun.num, f.den*g.den);
}

/*Renvoie la multiplication entre 2 fractions*/
fraction mul(fraction f, fraction g) {
	return build(f.num *g.num, f.den*g.den);
}

/*Renvoie la division entre 2 fractions*/
fraction sub(fraction f, fraction g) {
	return mul(f, build(g.den, g.num));
}

/*Algo d'Euclide, calcul du pgcd*/
long pgcd(long a, long b) {
	long x = a;
	long y = b;
	while (y != 0) {
		long r = x%y;
		x = y;
		y = r;
	}
	return x;
}

/*Renvoie la fraction f sous forme irréductible*/
fraction reduce(fraction f) {
	long p = pgcd(f.num,f.den);
	return build(f.num/p, f.den/p);
}

/*Renvoie 1 si les deux points ont les mêmes coordonnées*/
int eqp(point p1, point p2) {
	return eq(p1.x, p2.x) && eq(p1.y, p2.y);
}

/*Renvoie la distance euclidienne de deux points*/
double dist(point p1, point p2) {
	if(eqp(p1, p2)) return 0;
	fraction x1 = {.num = -p1.x.num, .den = p1.x.den};
	fraction y1 = {.num = -p1.y.num, .den = p1.y.den};
	fraction x2 = p2.x;
	fraction y2 = p2.y;
	fraction mul1 = mul(sum(x2,x1),sum(x2,x1));
	fraction mul2 = mul(sum(y2, y1),sum(y2,y1));
	fraction res = sum(mul1, mul2);
	return (double) sqrt(res.num/res.den);
}



int main(void) {
	/*fraction f1 = build(3, 0);
	printf("num = %ld, dem = %ld\n", f1.num, f1.den);*/
	
	fraction ex_fractions[] = {build(1, 1), build(1, 2), build(2, 4), build(-9, 3), build(8, -20), build(-5, -1), build(1, -3)};
	
	/*printf("Verification de eq avec 1/2 et 2/4 : %d\n", eq(ex_fractions[1], ex_fractions[2]));
	printf("Verification de eq avec 1/1 et 1/1 : %d\n", eq(ex_fractions[1], ex_fractions[0]));
	
	
	printf("%d\n", isInteger(ex_fractions[0]));
	printf("%d\n", isInteger(ex_fractions[1]));*/
	
	printf("Somme de 1/1 et 1/2 : %ld / %ld\n", sum(ex_fractions[0], ex_fractions[1]).num, sum(ex_fractions[0], ex_fractions[1]).den);
	printf("Multiplication de 1/1 et 1/2 : %ld / %ld\n", mul(ex_fractions[0], ex_fractions[1]).num, mul(ex_fractions[0], ex_fractions[1]).den);
	printf("Division de 1/1 et 1/2 : %ld / %ld\n\n\n", sub(ex_fractions[0], ex_fractions[1]).num, sub(ex_fractions[0], ex_fractions[1]).den);

	for(int i=0; i<7; i++) {
		printf("%ld/%ld = %ld/%ld\n", ex_fractions[i].num, ex_fractions[i].den, reduce(ex_fractions[i]).num, reduce(ex_fractions[i]).den);
	}
	
	printf("\n\n");
	
	point p1 = {.x = ex_fractions[0], .y = ex_fractions[3]};
	point p2 = {.x = ex_fractions[0], .y = ex_fractions[1]};
	
	printf("Vérification de eqp avec p1 = (1, -9/3) et p2 = (1, -9/3) : %d\n", eqp(p1,p1));
	printf("Vérification de eqp avec p1 = (1, -9/3) et p2 = (1, 1/2) : %lf\n", dist(p1,p2));
	
	
	
	
}
