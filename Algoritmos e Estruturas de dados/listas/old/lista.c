#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
	int info;
	struct lista * next;
}celula;

celula * create_list (void );
void push_info(celula * p,int info);
void print_info(celula * p);

void printf_recusion(celula * p);

int main () {
	int i,n,k;
	celula *p = create_list();
 
	scanf ("%d",&n);
	for (i = 0;i < n;i++){
		scanf("%d",&k);
		push_info(p,k);
	}
	// printf("%d %d %d %d\n",p->info,p->next->info,p->next->next->info,p->next->next->next->info);

	printf_recusion(p->next);
	printf("\n");

	print_info(p);

	return 0;
}

celula * create_list (void ){
	celula * p;

	if ((p = malloc (sizeof (celula))) == NULL){
		printf("Erro de allocação\n");
		exit (1);
	}else {
		printf("sucesso\n");
		p->info = 0;
		p->next = NULL;
		return p;
	}
	
}
void push_info(celula * p,int info){
	celula * novo = create_list ();
	novo->info = info;
	novo->next = p->next;
	p->next = novo;
}

void print_info(celula * p){
	celula * t;

	for (t = p->next;t!= NULL;t = t->next){
		printf("%d ",t->info);
	}
	printf("\n");
}

void printf_recusion(celula * p){
	if (p!= NULL){
		printf_recusion(p->next);
		printf("%d ",p->info);
	}
}
/*pesquisar mais
void free_all(celula * p){
	if (p != NUlL){
		free_all(p->next);
	}
	free(p);

}

*/