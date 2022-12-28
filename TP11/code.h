#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct file {
	void *first;
	void *last;
	size_t te;
	void *occupe;
	void *libre;
};

typedef struct file *fifo;

void* decale(void* f, ssize_t d);

void delete_fifo(fifo f);
int empty_fifo(fifo f);
void *get_fifo(fifo f, void *element);
void *put_fifo_no_shift(fifo f, void *pelem);
