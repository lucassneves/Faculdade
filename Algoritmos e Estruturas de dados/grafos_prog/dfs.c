#include <stdio.h>
#include <stdlib.h>

/*Vetores de Listas
	OBJETIVO: utilizar a busca em profundidade("DFS") de forma eficiente

	>> versão oficial usa vetores de vectors;
	>> usa uma representação de grafo,na forma de lista adjacente
	#ideia: na criação de uma lista sempre criamos 1 ponteiro, e alocamos uma vez apenas, a ideia é alocar vários;

	Representação do exemplo do grafo:

		vertice | vizinhos
			1 -> {2,3,6}
			2 -> {1,3}
			3 -> {2,1,4}
			4 -> {3}
			5 -> {}
			6 -> {1}

	
*/
typedef struct no
{
	int vert;
	struct no * next;

	// Distancia em relação ao vertice atual da lista
	int dist;
}NODE;


//É uma lista de vertices
typedef struct lista
{
	NODE * begin;
	int n_vi;

	//Verificar se já passamos por aquele vertece
	int verfi;
}LIST;

NODE * cria_no (void);
LIST * cria_listas(int n_lista);
void add_vert_dfs(LIST * lista,int vert,int vizi);
void DFS (LIST * lista,int vert);
void DFS_restart(LIST * lista,int n_verts);
int main () {
	LIST * lista;

	int n_verts,oper;
	int vert,vizi;
	int i,f;

	scanf ("%d %d %d",&n_verts,&oper,&f);
	lista = cria_listas(n_verts);

	for (i = 0;i < oper;i++) {
		scanf ("%d %d",&vert,&vizi);
		add_vert_dfs(lista,vert,vizi);
	}

	printf("Vetores Conexos a %d:\n",f);	
	DFS(lista,f);
	printf("\n");

	return 0;
}
//Vetores de Listas
LIST * cria_listas(int n_lista){
	LIST * nova = (LIST *) malloc(n_lista * sizeof (LIST));
	int i;
	for (i = 0;i < n_lista; i++){
		if (nova != NULL){
			nova[i].begin = NULL;
			nova[i].n_vi = 0;
			nova[i].verfi = -1;
		} else {
			printf("ERRO!\n");
			exit(1);
		}
	}
	return nova;
}

NODE * cria_no (void){
	NODE * no = (NODE *)malloc (sizeof(NODE));
	if (no != NULL){
		no->next = NULL;
		no->vert = 0;
		no->dist = 0;
		return no;
	}
	printf("ERRO!\n");
	exit(1);
}
/*Neste caso não faz diferença add no inicio ou no final
*/
void add_vert_dfs(LIST * lista,int vert,int vizi){
	NODE * no = cria_no();
	no->vert = vizi;
	no->next = lista[vert-1].begin;
	lista[vert-1].begin = no;
	lista[vert-1].n_vi++;
	//!?!Pode ser que seja necessario fazer algo reciproco aqui
}


/* função mestra1: ela busca recursivamente em Profundidade
 	>> busca os vizinhos de um determinado vertice em um grafo
*/
void DFS (LIST * lista,int vert){
	int i,v2;
	NODE * t;
	lista[vert-1].verfi = 1;

	for (t = lista[vert-1].begin ; t!=NULL ; t = t->next){
		
		v2 = t->vert;
		if (lista[v2-1].verfi == -1){
			DFS(lista,v2);
			printf("%d ",v2);
		}
	}
}
//Reseta as verificação, para uma nova verificação

void DFS_restart(LIST * lista,int n_verts){
	for (int i = 0;i < n_verts;i++){
		lista[i].verfi = -1;
	}
}
