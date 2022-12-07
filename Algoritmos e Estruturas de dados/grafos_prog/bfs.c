#include <stdio.h>
#include <stdlib.h>

/* Busca em matrizes
	>>obs: utilizar vetores de listas, não é necessário,
	pois a matriz carrega essa informção, organizada já
*/

typedef struct no
{
	int vert;
	struct no * next;
	
}NODE;

typedef struct fila
{
	NODE * begin;
	NODE * final;
}FILA;


FILA * cria_fila();
NODE * cria_no();
void push_fila (int n,FILA * fila);
void pop_fila(FILA * fila);
void BFS(int vert,int * v,int **matriz,int m);
void BFS(int vert,int * v,int **matriz,int m);

void vv(int n , int * v);

int main ( ) {
	int n,f,i,j,**m;
	scanf ("%d %d",&n,&f);
	int * v = malloc (n * sizeof (int));
	m = malloc(n*sizeof(int *));
	for (i = 0;i<n;i++)
		m[i] = malloc(n*sizeof (int ));

	for (i = 0;i < n;i++){
		for (j = 0;j < n;j++){
			scanf("%d",&m[i][j]);
		}
		v[i] = -1;
	}



	BFS(f+1,v,m,n);
	vv(n,v);

	free(v);
	for (i = 0;i<n;i++)
		free(m[i]);
	free(m);
	return 0;
}

FILA * cria_fila(){
	FILA * fila = malloc(sizeof(FILA));
	if (fila!= NULL){
		fila->begin = NULL;
		fila->final = NULL;
		return fila;
	}
	printf("erros\n");
	exit(1);
}

NODE * cria_no(){
	NODE * new = malloc(sizeof(NODE));
	if (new != NULL){
		new->next = NULL;
		new->vert = 0;
		return new;
	}
	printf("erros\n");
	exit(1);
}

void push_fila (int n,FILA * fila){
	NODE * no = cria_no();
	no->vert = n;
	if (fila->begin == NULL){
		fila->begin = fila->final = no;
	} else{
		fila->final->next = no;
		fila->final = no;
	}
}

void pop_fila(FILA * fila){
	NODE * no =  fila->begin;
	if (fila->begin == fila->final)
		fila->final = NULL;
	fila->begin = no->next;
	free(no);
}


void BFS(int vert,int * v,int **matriz,int m){
	int n,i;
	FILA * fila = cria_fila();
	push_fila(vert,fila);
	v[vert -1] = 0;

	while (fila->begin!=NULL){

		n = fila->begin->vert;
		// printf("%d\n",n);
		pop_fila(fila);

		for (i = 0;i < m;i++)
			if (matriz[n-1][i] == 1)
				if (v[i] == -1) {
					push_fila(i+1,fila);
					v[i] = v[n-1] + 1;

				}
	}
}

/*
6 3
0 1 0 0 0 0
0 0 1 0 0 0
0 0 0 0 1 0
0 0 1 0 1 0
1 0 0 0 0 0
0 1 0 0 0 0
*/

void vv(int n , int * v){
	int i;
	for (i = 0;i < n;i++){
		if (i+1 == n){
			printf("%d\n",v[i]);
			break;
		}
		printf("%d ",v[i]);
	}

}