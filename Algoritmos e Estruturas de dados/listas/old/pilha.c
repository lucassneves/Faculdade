#include<stdio.h>
#include<stdlib.h>

typedef struct Caixinha{
	char cte;
	struct Caixinha *next;
}box;

typedef struct Pilha{
	box* top;
	int i;
}pilha;

pilha* cria_pilha();
box* cria_box();
void empilha(char c,pilha *p);
void demolidor (box * k);

int main(){
	int i,j,n;
	char c;
	pilha *pila;

	pila = cria_pilha();
	
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++){
		while(c!='\n'){
			scanf("%c",&c);
			empilha(c,pila);
		}
		c ='0';
		printf("%d\n",pila->i);
	}

	return 0;
}

pilha* cria_pilha(){
	pilha *p;
	p = (pilha *) malloc (sizeof(pilha));
	if(p!=NULL){
		p->top = NULL;
		p->i = 0;
		return p;
	}
	exit(1);	
}

box* cria_box(){
	box *b;
	b = (box *) malloc (sizeof(box));
	if(b!=NULL){
		b->next = NULL;
		b->cte = '0';
		return b;
	}
	exit(1);	
}

void empilha(char c,pilha *p){
	box *b = cria_box();
	b->cte = c;
	b->next = p->top;
	p->top = b;
	if (c == '>'){
		demolidor (p->top);	
		p->i++;
	}
		
}



void demolidor (box * k){
	if (k->cte != '<'){
		box * y =  k;
		k = k -> next;
		free(y);
		demolidor (k->next);
	}
	
}
