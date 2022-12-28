#include"code.h"


void* decale(void* f, ssize_t d) {
	return (char *) f+d;
}

/*fifo create_fifo(size_t capacite_init, size_t taille_elem) {
	fifo f;
	fifo *pt = f;
	pt->te = taille_elem;
}*/

void delete_fifo(fifo f) {
	free(f->first);
	free(f);
}


int empty_fifo(fifo f) {
	if(f->occupe == f->libre) {
		return 1;
	}
	return 0;
}

void *get_fifo(fifo f, void *element) {
	if(empty_fifo == 0) {
		memmove(element, f->occupe, f->te);
		f->occupe += 1;
		return element;
	}
	return NULL;
}

void *put_fifo_no_shift(fifo f, void *pelem) {
	if(f->libre == f->last) {
		return NULL;
	} else {
		f->last = pelem;
		f->last++;
	}
}
















