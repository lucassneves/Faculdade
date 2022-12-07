#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	char cte;
	struct NODE * next;
}NODE;

typedef struct PILHA {
	NODE * top;
	int cout;
}PILHA;

PILHA * cria_pilha(void);
NODE * cria_no(void );
void empilha (char info,PILHA * pila);
void demolidor_power(PILHA * pila);

int main () {
	int n,i;
	char k;

	PILHA * pila = cria_pilha();
	

	scanf ("%d",&n);
	getchar();
	for (i = 0;i < n;i++){
		
		while (k!= '\n'){
			
			scanf ("%c",&k);
			empilha(k,pila);
		}
		k = '0';
		if (pila->top == NULL)
			printf("S\n");
		else
			printf("N\n");
		pila->cout = 0;
	}
		
	return 0;
}


PILHA * cria_pilha(void){
	PILHA * nova;
	if ((nova = (PILHA *) malloc (sizeof(PILHA))) == NULL){
		exit(1);
	}
	nova->top = NULL;
	nova->cout = 0;
	return nova;
}

NODE * cria_no(void ){
	NODE * nova;
	if ((nova = malloc (sizeof (NODE))) == NULL){
		exit(1);	
	}
	nova->cte = '0';
	nova->next = NULL;
	return nova;
}


void empilha (char info,PILHA * pila){
	NODE * caixa = cria_no();
	caixa->cte = info;
	caixa->next = pila->top;
	pila->top = caixa;
	if ((info == ')' && pila->top->next->cte == '(') || (info == '}' && pila->top->next->cte == '{') ||( info == ']' && pila->top->next->cte == '[')  ){
		demolidor_power(pila);
	} else if ((info == '(' && pila->top->next->cte == ')') || (info == '{' && pila->top->next->cte == '}') || (info == '[' && pila->top->next->cte == ']')) 	{
		demolidor_power(pila);
	}

}

void demolidor_power(PILHA * pila) {
	NODE * t, * k;
	t = pila->top;
	k = t->next;
	pila->top = k->next;
	free(k);
	free(t);
}















