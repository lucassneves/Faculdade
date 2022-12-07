#include <stdio.h>
#include <stdlib.h>

int binary_search(int *v,int low,int high ,int x,int b_count);
void printf_vet(int *v,int n);
int sequencial_search (int *v,int low,int high,int x,int q_count);
int quaternary (int *v,int low,int high,int x,int q_count);

int main () {
    int i,j,*v,n,m,*u,x,b_count = 0,q_count;
    //int k[] = {1,2,3,4,5,6,7,8,9,10};

    scanf ("%d %d",&n,&m);
    v = malloc (m*sizeof (int));

    for (i = 0;i < n;i++){
        scanf("%d",&x);
        for (j = 0; j < m;j++){
            scanf("%d",&v[j]);
        }
       printf("%d %d\n",binary_search(v,0,m,x,0),quaternary(v,0,m,x,0));
    }

    free(v);
    return 0;
}

void printf_vet(int *v,int n) {
    int i;
    for (i = 0;i < n;i++)
        printf("%d ",v[i]);
    printf("\n");
}

int binary_search(int *v,int low,int high ,int x,int b_count) {
    int n = (high + low)/2;
    if(n-1 < 0 ){
         return -1;
    }
    if (v[n -1] == x){
        b_count++;
        return b_count;
    }else if (x > v[n -1]){
        b_count++;
        return binary_search (v,n,high,x,b_count);
    }else if (x < v[n -1]){
        b_count++;
        return binary_search (v,low,n,x,b_count);
    }
    
}

int sequencial_search (int *v,int low,int high,int x,int q_count) {
    if (low > high -1){
        return -1;
    }
    if (v[low] == x){
        q_count++;
        return q_count;
    }
    else{
        q_count++;
        return sequencial_search (v,low+1,high,x,q_count);
    }
}

int quaternary (int *v,int low,int high,int x,int q_count){
    int n =  (high + low);
   if ((high - low)/4 < 4) {
        q_count++;
        return sequencial_search(v,low,high,x,q_count);
   } else if (v[n/4 -1] == x){
       q_count++;
        return q_count;
   } else if (v[n/2 -1] == x){
       q_count++;
        return q_count;
   } else if (v[(3*n)/2 -1] == x){
       q_count++;
        return q_count;

   }else if (v[high] == x){
       q_count++;
        return q_count;
   }else if (v[low] == x){
       q_count++;
        return q_count;
   }

    else if (x > v[low] && x <= v[n/4 -1]){
        q_count++;
        return quaternary (v,low,n/4,x,q_count);
    }
    else if (x > v[n/4] && x <= v[n/2 -1]){
        q_count++;
        return quaternary (v,n/4,n/2,x,q_count);
    }
    else if (x > v[n/2] && x <= v[(3*n)/2 -1]){
        q_count++;
        return quaternary (v,n/2,(3*n)/2,x,q_count);
    }
    else if (x > v[(3 * n)/2] && x <= v[high -1]){
        q_count++;
        return quaternary (v,(3 * n)/2,high,x,q_count);
    }

    return -1;
}

