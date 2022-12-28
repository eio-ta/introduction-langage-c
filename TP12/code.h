#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct node node;
typedef node* mset;

mset new_node(int val, unsigned num);
mset add_val(int val, unsigned num, mset m);
mset build(int *values, size_t size);
void print_mset(mset m, short verbose);
mset remove_val(int val, unsigned num, mset m, unsigned *num_rm);
