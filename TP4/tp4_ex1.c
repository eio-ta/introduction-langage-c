#include<stdio.h>
#include<stdlib.h>

int main () {
	int t[] = {1, 2, 3}, *pt;
	pt = t;
	
	int t1[3] = {1, 2, 3}, *pt1;
	pt1 = &t1[0];
	
	int t2[] = {1, 2, 3}, *pt2;
	// t2 = pt2; // ERREUR À LA COMPILATION
	
	int t3[3] = {1, 2, 3}, *pt3;
	pt3 = t3 + 1;
	
	int t4[3] = {1, 2, 3}, *pt4;
	pt4 = &t4[1];
	
	int t5[3], *pt5;
	pt5 = malloc (5 * sizeof (int));
	pt5 = t5;
	
	// int t6[5] = malloc (5 * sizeof (int)); // ERREUR À LA COMPILATION
	
	int *pt6;
	pt6 = malloc (5 * sizeof (int));
	*pt6 = 10;
	*(pt6 + 1) = 20;
	*(pt6 + 12) = 30;
	
	int *pt7;
	pt7 = malloc (5 * sizeof (int));
	pt7[0] = 10;
	pt7[1] = 20;
	pt7[12] = 30;
	
	
}
