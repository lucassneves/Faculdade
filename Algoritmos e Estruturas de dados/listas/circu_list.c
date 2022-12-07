#include <stdio.h>
#include <stdlib.h>
    
typedef struct no {
    int id; //identificador do dispositivo
    int p; //prioridade do dispositivo
    struct no *next; //ponteiro para próximo elemento
} NO;
    
NO * cria_lista();
int push (NO ** l,int id,int pri);
int pop (NO ** l, int n);
void sort (NO * lista,int n);
void swap(NO * t,NO * s);
    
int mm;
int main () {
    int n,i,k,m = 0,id,pri;
    NO * lista = NULL;
    scanf ("%d",&n);
    mm = 0;
    for (i = 0;i<n;i++){
        scanf("%d",&k);
        if (k == 1){
            scanf ("%d %d",&id,&pri);
            if (mm >= 10){
                printf("Overflow\n");
            }else {
                if (push(&lista,id,pri) == 1){
                    mm++;
                    sort(lista,mm);    
                }
                
            }
        } else{
            scanf("%d",&id);
            if (pop(&lista,id) == 1)
                mm--;
        }
    }
    
    // pri_l(lista);
    return 0;
}
    
    
NO * cria_lista(){
    NO * p = malloc (sizeof (NO));
    if (p!= NULL){
        p->id = 0;
        p->p = 0;
        p->next =NULL; 
        return p;
    }
    exit(1);
}
    
int  push (NO ** l,int id,int pri){
    NO * new = cria_lista();
    new->id = id;
    new->p = pri;
    if (*l == NULL){
        *l = new;
        new->next = new;
        return 1;
    }else {
        NO * t,*s;
        int i = 0;
        // pri_l(*l);
        for (s = (*l);i < mm;i++,s=s->next)
            if (s->id == id){
                printf("%d\n",i+1);
                return 0;
            }
    
        new->next = *l;
        for (t = *l;t->next != *l;t = t->next){}
        t->next = new;
        return 1;
    }
}
    
int pop (NO ** l, int n) {
    NO * t = *l;
    if (*l == NULL){
        printf("Underflow\n");
        return 0;
    }
    NO * s;
    int i = 1,j = 0;
    for (s = *l,t = s->next;j < mm;i++,j++,s = t,t = t->next){
        if (t->id == n){
            if (t == s)
                *l = NULL;
            else if (t == *l)
                *l = t->next;
            s->next = t->next;
            free(t);
            if (i > mm)
                i = 0;
            printf("%d\n",i+1);
            return 1;
        }
    }
    printf("RProID\n");
    return 0;
}
void sort (NO * lista,int n){
    int aux,i,j;
    NO * t,*s;
    for (t = lista,i = 0;i < n-1;t = t->next,i++){
        for (s = lista,j=0;j < n-1;j++,s = s->next){
            // printf(" %d %d > %d %d\n",i,j,s->id,s->next->id);
            if (s->id > s->next->id){
                swap(s,s->next);
            }
            // printf(" %d %d < %d %d\n",i,j,s->id,s->next->id);
        }
    }
    
}
    
void swap(NO * t,NO * s){
    int aux;
    aux = t->id;
    t->id = s->id;
    s->id = aux;
    aux = t->p;
    t->p = s->p;
    s->p = aux;
}