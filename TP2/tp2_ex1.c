#include<stdio.h>

int g(int n);

int f(int n) {
	return (n == 1)? 2 : 2*g(n-1);
}

int g(int n) {
	return (n == 1)? 1 : 3*f(n/2);
}

int main(void) {
	printf("f(20) : %d\n", f(20));
}
