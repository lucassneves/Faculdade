#include <stdio.h>
#include <stdlib.h>

typedef struct info {
	int valor;
}infor;

typedef struct celula 
{
	infor info;
	struct celula * next;
}celula;

typedef struct lista
{
	celula * head;
	int size;
}list;

celula * cria_celula(void);
list * cria_lista(void );
void insert_no_inicio(list * lista,int n);
void insert_no_final(list * lista,int n);
void print_lista(list * lista);

int main (){
	int i,n,k;
	list * lista;
	lista = cria_lista();
	scanf ("%d",&n);
	for (i = 0;i < n;i++){
		scanf("%d",&k);
		insert_no_inicio(lista,k);
	}

	print_lista(lista);

	return 0;
}

 list * cria_lista(void ){
 	list * nova;
 	if ((nova =(list *) malloc (sizeof (list))) == NULL){
 		printf("erro!\n");
 		exit (1);
 	}
 	nova->head = cria_celula();
 	nova->size = 0;
 	return nova;
}

celula * cria_celula(void){
	celula * nova;
	if ((nova =(celula *) malloc (sizeof (celula))) == NULL){
 		printf("erro!\n");
 		exit (1);
 	}
 	nova->info.valor = 0;
 	nova->next = NULL;
 	return nova;
}

void insert_no_inicio(list * lista,int n){
	celula * nova;
	nova = cria_celula();
	nova->info.valor = n;
	nova->next = lista->head->next;
	lista->head->next = nova;
}

void insert_no_final(list * lista,int n){
	celula * t,*nova;
	for (t = lista->head ; t->next != NULL ;t = t->next) 		{
	}
	nova = cria_celula();
	nova->info.valor = n;
	t->next = nova;
}

void print_lista(list * lista){
	celula * t;
	for (t = lista->head->next ; t!= NULL ; t=t->next){
		printf("%d ",t->info.valor);
	}
	printf("\n");
}

/****Inserção alternativa no Final

void incert_alternative_incert_final(list * lista, int n){
	insert_celula_final(lista->head,n);
}
void insert_celula_final (celula * head,int n){
	if (head->next !=NULL){
		insert_celula_final(head->next,n);
	}else{
		celula * nova;
		nova = cria_celula();
		head->next = nova;
	}
}
*/
