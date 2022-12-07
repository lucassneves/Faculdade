#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    struct no * next;
}NODE;

typedef struct list {
    int size;
    NODE * first;
}LIST;


NODE * cria_no(void);
LIST * cria_lista(void);
void insert_no_inicio (LIST * check , int info);

void search_list_to_kill (LIST * lista, int x) ;
void printt_list (LIST * lista);

void start_final_incert(LIST * check,int info);
void insert_no_final (NODE * shary , int info);
void start_free_list (LIST * lista);
void free_list (NODE * no);

int main () {
    int i,k;
    LIST * lista = cria_lista();

    for (i = 0;i < 3;i++){
        scanf ("%d",&k);
        start_final_incert(lista,k);
    }
    printt_list(lista);
    search_list_to_kill (lista, 2);
    printt_list(lista);
    start_free_list(lista);
    return 0;
}



NODE * cria_no(void){
    NODE * novo;
    if ((novo = (NODE *) malloc(sizeof(NODE)))== NULL){
        printf("erro\n");
        exit (1);
    }
    novo->next = NULL;
    novo->info = 0;
    return novo;
}

LIST * cria_lista(void){
    LIST * novo;
    if ((novo = (LIST *) malloc(sizeof(LIST)))== NULL){
        printf("erro\n");
        exit (1);
    }
    novo->first = NULL;
    novo->size = 0;
    return novo;
}

void insert_no_inicio (LIST * check , int info){
    NODE * novo = cria_no();
    novo->info = info;
    novo->next = check->first;
    check->first = novo;
}

void start_final_incert(LIST * check,int info){
    if (check->first == NULL){
        insert_no_inicio(check,info);
    } else{
        insert_no_final(check->first,info);
    }
    
}
void insert_no_final (NODE * berry , int info){
    if (berry->next != NULL){
        insert_no_final(berry->next,info);
    } else {
        NODE * novo =  cria_no();
        novo->info = info;
        berry->next = novo;
    }
}

void search_list_to_kill (LIST * lista, int x) {
    NODE * t;
    if (lista->first->info == x){
        t = lista->first;
        lista->first = lista->first->next;
        free (t);
    }else {
        NODE * q;
        for (t = lista->first->next,q = lista->first;t!=NULL;q = t,t=t->next){
            if (t->info == x){
                q->next = t->next;
                free(t);
            }
        }

    }
}

void printt_list (LIST * lista){
    NODE * t = lista->first;
    while (t!=NULL){
        printf("%d ",t->info);
        t=t->next;
    }
    printf("\n");
}

void start_free_list (LIST * lista){
    free_list(lista->first);
}

void free_list (NODE * no){
    if (no !=NULL){
        free_list(no->next);
        no->next = NULL;
    }
    free(no);
}