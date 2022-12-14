#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
	struct no * next;
	int n;
}NODE;

typedef struct fila
{
	NODE * begin,*final;
}FILA;

NODE * cria_no(int n);
void print_no(NODE * l);

NODE * insert_lista (NODE * l,int n);
NODE * delete_lista(NODE * l,int n);


NODE * insert_pilha (NODE * p,int n);
NODE * delete_pilha (NODE * p);

FILA * cria_fila(void);
FILA * insert_fila(FILA * f,int n);
FILA * delete_fila (FILA * f);


int main (){
	int n,i;

	/* **Main de Listas**
	NODE * lista = NULL;
	NODE * pilha = NULL;

	while(scanf("%d",&n)!=EOF){
		lista = insert_lista (lista,n);
		getchar();
	}

	printf("Numeros inseridos\n");
	print_no(lista);

	
	while(scanf("%d",&n)!=EOF){
		lista = delete_lista (lista,n);
		print_no(lista);
	}
	*/

	FILA * fila = cria_fila();
	while(scanf("%d",&n)!=EOF){
		fila = insert_fila(fila,n);
	}

	printf("OK\n");
	while(scanf("%d",&n)!=EOF){
		delete_fila(fila);
		print_no(fila->begin);
	}	
	
	return 0;
}


NODE * cria_no(int n){
	NODE * new = malloc(sizeof(NODE));
	if (new!= NULL){
		new->next = NULL;
		new->n = n;
		return new;
	}
	exit(1);
}

void print_no(NODE * l){
	if (l !=NULL){
		printf("%d ",l->n );
		print_no(l->next);
	}else {
		printf("\n");
	}
}

///***LISTA*****

NODE * insert_lista (NODE * l,int n){
	if (l == NULL) return cria_no(n);
	else{
		l->next = insert_lista(l->next,n);
	}
	return l;
}

NODE * delete_lista(NODE * l,int n){
	if (l == NULL) return NULL;
	else if (l->n == n){
		NODE * tmp = l;
		l = l->next;
		free(tmp);
	}else{
	 l->next = delete_lista(l->next,n);
	}
	return l;
}

///***PILHA*****

NODE * insert_pilha (NODE * p,int n){
	if (p == NULL) return cria_no(n);
	else{
		NODE * aux = cria_no(n);
		aux->next = p;
		return aux;
	}
}
NODE * delete_pilha (NODE * p){
	if (p!=NULL){
		NODE * aux = p;
		p = p->next;
		free(aux);
	}
}

///***FILAS*****

FILA * cria_fila(void){
	FILA * f = malloc(sizeof(FILA));
	if (f!=NULL){
		f->begin = f->final = NULL;
		return f;
	}
	exit(1);
}

FILA * insert_fila(FILA * f,int n){
	if (f->begin == NULL){
		f->begin = f->final = cria_no(n);
	}else{
		NODE * aux = cria_no(n);
		aux->next = f->begin;
		f->begin = aux;
	}
	return f;
}

FILA * delete_fila (FILA * f) {
	if (f->begin == NULL) return f;
	else{
		if (f->begin == f->final){
			NODE * aux = f->begin;
			f->begin = f->final = NULL;
			free(aux);
		}else{
			NODE * aux = f->begin;
			while(aux->next!=f->final){
				aux = aux->next; 
			}
			f->final = aux;
			aux = aux->next;
			free(aux);
			f->final->next = NULL;
		}
	}
	return f;
}