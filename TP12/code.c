#include"code.h"

struct node {
	int val;
	unsigned num;
	struct node *next;
};

mset new_node(int val, unsigned num) {
	node n;
	node *p = &n;
	p->val = val;
	p->num = num;
	p->next = NULL;
	assert(num != 0);
	return p;
}

mset add_val(int val, unsigned num, mset m) {
	node *p = m;
	while(p->next != NULL && p->next->val > p->val) {
		if(p->val == val) {
			p->num += num;
			return m;
		}
		p = p->next;
	}
	
	node *tmp = p->next; 
	p->next = new_node(val, num);
	p->next->next = tmp;
	return m;
}

mset build(int *values, size_t size) {
	mset m = new_node(values[0], 1);
	for(int i=1; i<size; i++) {
		m = add_val(values[i], 1, m);
	}
	return m;
}

void print_mset(mset m, short verbose) {
	node *p = m;
	if(verbose == 0) {
		if(p != NULL) {
			printf("%d(%d) ", p->val, p->num);
			print_mset(p->next, verbose);
		}
	} else {
		if(p != NULL) {
			for(int i=0; i<p->num; i++) {
				printf("%d ", p->val);
			}
			print_mset(p->next, verbose);
		}
	}
}

mset remove_val(int val, unsigned num, mset m, unsigned *num_rm) {
	node *p = m;
	while(p->next != NULL) {
		if(p->next->val == val) {
			if(p->next->num > num) {
				p->next->num -= num;
				return m;
			} else {
				node *tmp = p->next;
				p->next = p->next->next;
				free(tmp);
			}
		}
	}
}

mset mplus(mset m, mset n) {

}


