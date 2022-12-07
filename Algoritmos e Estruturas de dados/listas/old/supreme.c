#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
	int info;
	struct no * next;
}NODE;

typedef struct lista
{
	int size;
	NODE * firt;
} LIST;

typedef struct fila
{
	int size;
	NODE * inicio;
	NODE * final;
	
}FILA;

NODE * cria_no(void);
LIST * cria_lista (void);
FILA * cria_fila(void);

void insert_node_inicio (LIST * lista,int x);

void insert_node_final (LIST * lista,int x);
void insert_node_2_final (LIST * lista,int x);

void print_lista(LIST * lista);


int main (){
	int i,n;
	LIST * p = cria_lista();
	NODE * coisas = NULL;
	for (i = 0;i < 3;i++){
		scanf("%d",&n);
		insert_node_2_final(p,n);
	}
	print_lista(p);

	return 0;
}


NODE * cria_no(void){
	NODE * novo;
	if ((novo = (NODE *)malloc (sizeof(NODE)))==NULL){
		printf("Erro!\n");
		exit(1);
	}
	novo->next = NULL;
	novo->info = 0;
	return novo;
}


LIST * cria_lista (void){
	LIST * lista;
	if ((lista = (LIST *) malloc (sizeof (LIST))) == NULL){
		printf("ERRO!\n");
		exit(1);
	}
	lista->size = 0;
	lista->firt = NULL;
	/**para lista circular
	lista->firt = firt;
	*/
}

FILA * cria_fila(void){
	FILA * novo;
	if ((FILA = (FILA * ) malloc(sizeof (FILA))) == NULL){
		printf("Erro!\n");
		exit(1);
	}
	novo->inicio = novo->final = NULL;
	novo->size = 0;
	return novo;
}
void insert_fila(FILA * fila, int x){
	NODE * novo = cria_no();
	NODE->info = x;
	if(fila->final == NULL){
		fila->inicio = no;
	}else {
		fila->final->next = no;
		//grudar o novo nó na ponta da fila
	}
	fila->final = no;
	//restabelecer o fim da fila, após a ultima mudança
	fila->size++;
}



//com ou sem cabeça
void insert_node_inicio (LIST * lista,int x){
	NODE * novo = cria_no();
	novo->info = x;
	novo->next = lista->firt;
	lista->firt = novo;
	lista->size++;
}

void insert_node_final (LIST * lista,int x) {
	if (lista->firt!=NULL) {
		if (lista->firt->next != NULL){
			LIST * t = cria_lista();
			t->firt = lista->firt->next;
			insert_node_final(t,x);
			free(t);
		}else {
			NODE * novo = cria_no();
			novo->info = x;
			lista->firt->next = novo;
		}
		
	}else {
		insert_node_inicio(lista,x);
	}
	lista->size++;
}
void insert_node_2_final (LIST * lista,int x){
	NODE * novo = cria_no();
	novo->info = x;
	if (lista->firt == NULL)
		lista->firt = novo;
	else{
		NODE * t = lista->firt;
		while (1){
			if(t->next == NULL){
			t->next = novo;
			break;
			}
			t = t->next;
		}
		lista->size++;
	}
}



void print_lista(LIST * lista){
	for (NODE * p = lista->firt ; p!=NULL; p = p->next)
		printf("%d ",p->info);
	printf("\n");
}

/* ****!!!!!
não esta funcionando !!?, sem cabeça
void comun_insert (NODE * firt,int x){
	NODE * novo = cria_no();
	novo->info = x;
	novo->next = firt;
	firt = novo;
}
*/

/* Função com ou sem cabeça funcional, usado ponteiro para ponteiro
void insert_node_inicio (NODE ** firt ,int x){
	NODE * novo;
	novo = cria_no();
	novo->info = x;
	novo->next = *firt;
	*firt = novo;
}
*/

/*void ancient_comun_insert (NODE * firt,int x){
	NODE * novo = cria_no();
	novo->info = x;
	novo->next = firt->next;
	firt-next = novo;
}

*/