#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node node;
struct node {
  int val;
  node *left;
  node *right;
};

void print_head (int depth, int addr) {
    if (depth > 1) {
	int pre = addr / 2;
	print_head (depth - 1, pre);
	printf ("%s", (pre % 2) != (addr % 2) ? "|    " : "     ");
	return;
    }
    if (depth == 1)
	printf ("     ");
}

void pretty_rec (node *t, int depth, int addr) {
    if (t == NULL) {
	print_head (depth, addr);
	printf ("|----N\n");
	return;
    }
    pretty_rec (t -> right, depth + 1, 2 * addr  + 1);
    print_head (depth, addr);
    char c =
	(depth == 0) ? '-' : '|';
    printf ("%c----%d\n", c, t -> val);
    pretty_rec (t -> left, depth + 1, 2 * addr);
}

// fonction principale d'affichage.
void pretty_print (node *t) {
    pretty_rec (t, 0, 0);
}

node *cons_tree(int val, node *left, node *right) {
	node *res = malloc(1+sizeof(node));
	assert(res != NULL);
	res->val = val;
	res->left = left;
	res->right = right;
	return res;
}

void free_tree(node *t) {
	if(t != NULL) {
		free_tree(t->left);
		free_tree(t->right);
		free(t);
	}
}

int size_tree(node *t) {
	if(t != NULL) {
		int gauche = size_tree(t -> left);
		int droite = size_tree(t -> right);
		return 1 + gauche + droite;
	}
	return 0;
}

int sum_tree(node *t) {
	if(t != NULL) {
		int gauche = sum_tree(t->left);
		int droite = sum_tree(t->right);
		return (t->val) + gauche + droite;
	}
	return 0;
}

int depth_tree(node *t) {
	if(t != NULL) {
		int gauche = depth_tree(t->left);
		int droite = depth_tree(t->right);
		if(gauche > droite) return gauche+1;
		else return droite+1;
	}
	return 0;
}

void print_abr(node *t) {
	if(t != NULL) {
		print_abr(t->left);
		printf("%d ", t->val);
		print_abr(t->right);
	}
}

node *insert_abr(node *t, int val) {
	if(t == NULL) {
		return cons_tree(val, NULL, NULL);
	} else {
		if(val < t->val) t->left = insert_abr(t->left, val);
		if(val > t->val) t->right = insert_abr(t->right, val);
		return t;
	}
}

node *search_abr(node *t, int val) {
	if(t != NULL) {
		if(val == t->val) return t;
		else if(val < t->val) return search_abr(t->left, val);
		else return search_abr(t->right, val);
	}
	return NULL;
}

node *max_abr(node *t) {
	if(t != NULL) {
		if(t->right != NULL) return max_abr(t->right);
		else return t;
	}
	return NULL;
}

node *min_abr(node *t) {
	if(t != NULL) {
		if(t->left != NULL) return min_abr(t->left);
		else return t;
	}
	return NULL;
}

int check_abr(node *t) {
	if (t == NULL) return 1;
	if (t->left != NULL && t->val < min_abr(t->left)->val &&  t->val < t->left->val) return 0;
	if (t->right != NULL && t->val > max_abr(t->right)->val &&  t->val > t->right->val) return 0;
	return (check_abr(t->left) && check_abr(t->right));
}

node *delete_abr(node *t, int val) {
	if(t == NULL) return NULL;
	if(val < t->val) t->left = delete_abr(t->left, val);
	if(val > t->val) t->right = delete_abr(t->right, val);
	if(val == t->val && t->left == NULL && t->right == NULL) {
		free(t);
		return NULL;
	}
	if(val == t->val && t->left == NULL && t->right != NULL) {
		node *tmp;
		tmp = t;
		free(t);
		return tmp->right;
	}
	if(val == t->val && t->right == NULL && t->left != NULL) {
		node *tmp;
		tmp = t;
		free(t);
		return tmp->left;
	}
	if(val == t->val && t->left != NULL && t->right != NULL) {
		node *tmp;
		tmp = max_abr(t->left);
		t->val = tmp->val;
		tmp->val = val;
		t->left = delete_abr(t->left, val);
		return t;
	}
	return t;
}


int main() {
	node *t;
	t = cons_tree (1, cons_tree (3, NULL, NULL), cons_tree (6, cons_tree (4, NULL, NULL), NULL));
	pretty_print(t);
	// free_tree(t);
	printf("Taille de l'arbre : %d\n", size_tree(t));
	printf("Somme des étiquettes : %d\n", sum_tree(t));
	printf("Profondeur de l'arbre : %d\n", depth_tree(t));
	print_abr(t);
	printf("\n\n");
	
	node *t1 = NULL;
	int vals[10] = {8, 3, 1, 2, 6, 4, 7, 10, 14, 13};
	for (int i = 0; i < 10; i++) {
		t1 = insert_abr (t1, vals[i]);
	}
	// pretty_print(t1);
	// pretty_print(search_abr(t1, 15));
	// pretty_print(max_abr(t1));
	// pretty_print(min_abr(t1));
	// printf("Arbre abr : %d\n", check_abr(t1));
	delete_abr(t1, 8);
	pretty_print(t1);
}
