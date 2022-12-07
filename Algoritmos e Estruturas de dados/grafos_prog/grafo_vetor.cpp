#include <iostream>

using namespace std;

/* Alocação em C++
    isso depois de escanear o numero de alocação necessária
    int * v = new int[numTests]; 
    delete (v);
*/

typedef struct lista
{
    int v1,v2;
    
}LIST;

int main (){
    int i,n,m,a,b,c,j,count = 0;
    cin>>n>>m;
    /*como eu tenho a quantidade de termos que serão escaneados, e que não será necessario
    remover em momento algum, fazer uma lista estatica faz mais sentido*/
    LIST * lista = new LIST[n];

    for (i = 0;i < m;i++){
        cin>>a>>b>>c;
        if (a == 0){
            for (j = 0; j < count;j++){
                if (lista[j].v1 == b && lista[j].v2 == c){
                    cout<<1<<"\n";
                    break;
                } else if (lista[j].v1 == c && lista[j].v2 == b){
                    cout<<1<<"\n";
                    break;
                }
            }
            if (j == count)
                cout<<0<<"\n";
        }else{
            lista[count].v1 = b;
            lista[count].v2 = c;
            count++;
        }
    }
    
    delete (lista);
    return 0;
}

/*
for (j = 0;j < n;){
    if (lista[j].v1 != 0 && lista[j].v2 != 0)
        j++;
    else{
        lista[j].v1 = b;
        lista[j].v2 = c;
        break;
    }
}

*/