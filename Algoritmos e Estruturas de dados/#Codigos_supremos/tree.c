#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
	struct no *left,*right;
	int n,nivel;
}NODE;

NODE * cria_no (int n,int nivel);
NODE * insert (NODE * t,int n,int nivel);
NODE * delete (NODE * t,int n);
NODE * find_min (NODE * t);
void pre_ordem (NODE * t);
void printTree( NODE * p, int h);

void height(NODE * t,int n,int *max);
void em_nivel (NODE * t);
void print_nivel (NODE * t,int nivel);

int main() {
	int x = 1,max = 0;
	NODE * tree = NULL;

	while( scanf("%d",&x)!=EOF){
		tree = insert (tree,x,1);
	}
	em_nivel(tree);

	return 0;
}



NODE * cria_no (int n,int nivel){
	NODE * new = malloc (sizeof(NODE));
	if (new != NULL){
		new->right = new->left = NULL;
		new->n = n;
		new->nivel = nivel;
		return new;
	}
	exit(1);
}

NODE * insert (NODE * t,int n,int nivel) {
	if (t == NULL) return cria_no(n,nivel);
	else if (n > t->n ) t->right = insert (t->right,n,nivel+1);
	else if (n < t->n ) t->left = insert (t->left,n,nivel+1);
	return t; 
}

NODE * delete (NODE * t , int n) {
	if (t == NULL) return NULL;
	else if (n > t->n ) t->right = delete (t->right,n);
	else if (n < t->n ) t-> left = delete (t->left,n);
	else{
		if (t->left == NULL){
			NODE * tmp = t->right;
			free(t);
			return tmp;
		} else if (t->right == NULL){
			NODE * tmp = t->left;
			free(t);
			return tmp;
		}
		NODE * tmp = find_min(t->right);
		t->n = tmp->n;
		t->right = delete (t->right,t->n); 
	}
	return t;
}

NODE * find_min (NODE * t){
	NODE * p = t;
	while(p->left != NULL){
		p = p->left;
	}
	return p;
}

void pre_ordem (NODE * t){
	if (t!=NULL){
		pre_ordem(t->left);
		printf("%d ",t->n);
		pre_ordem(t->right);
	}
}


void height(NODE * t,int n,int *max){
	if (t!=NULL){
		height(t->right,n+1,max);
		height (t->left,n+1,max);
		if (n > *max)
			*max = n;
	}
}


void printTree( NODE * t, int h){
	if (t!=NULL){
		printTree(t->right,h+1);
		printf("%*d \n",h*5,t->n);
		printTree(t->left,h+1);
	}
}

void print_nivel(NODE * t,int nivel){
	if (t!=NULL){
		if (nivel == 1){
			printf("%d ", t->n);
		}else{
			print_nivel(t->left,nivel -1);
			print_nivel(t->right,nivel -1);
		}
	}
}


void em_nivel (NODE * t){
	int h,n = 1;
	height (t,1,&max)
	while (n <= h){
		print_nivel(t,n);
		printf("\n");
		n++;
	}
}