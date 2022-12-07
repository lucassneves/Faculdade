#include <stdio.h>
#include <stdlib.h>

int ** alocar_matriz (int linha, int colunas);
void preencher (int **matriz, int linhas, int colunas);
void imprimir (int **matriz, int linhas, int colunas);
void liberar_mem (int **matriz, int linhas);

int main () {
    int **matriz = NULL;
    int linhas,colunas;

    scanf("%d %d",&linhas,&colunas);

    matriz = alocar_matriz(linhas,colunas);
    preencher(matriz,  linhas, colunas);

    imprimir(matriz,  linhas, colunas);
    liberar_mem(matriz,linhas);
    matriz = NULL;
    return EXIT_SUCCESS;
}

int ** alocar_matriz (int linhas, int colunas){
    int **matriz = NULL;
    int i;
    // primeiro allocar um vetor de ponteiros
    matriz = (int **) malloc (linhas * sizeof (int *));
    if (matriz == NULL ) {
        exit (EXIT_FAILURE);
    }

    for (i = 0;i < linhas;i++){
        matriz[i] = (int *) malloc (colunas * sizeof (int));
        if (matriz[i] == NULL){
            exit (EXIT_FAILURE);
        }
    }

    return matriz;
}

void preencher (int **matriz, int linhas, int colunas){
    int i,j;

    for (i = 0 ; i < linhas ; i++){
        for (j = 0; j < colunas ; j++){
            matriz[i][j] = j;
        }
    }
}

void imprimir (int **matriz, int linhas, int colunas){
    int i,j;

    for (i = 0 ; i < linhas ; i++){
        for (j = 0; j < colunas ; j++){
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
}

void liberar_mem (int **matriz, int linhas){
    int i;

    for (i = 0 ; i < linhas ; i++){
          free(matriz[i]);
    }

    free(matriz);
}