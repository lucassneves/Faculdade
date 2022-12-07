#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*  Utilizando Vector
    >> vector <int> vetor; //cria um vetor com zero espaços
    >> vetor.push_back(10)//add no final do vetor o numero 10
    >> vetor.resize(10); oferece mais 10 elementos ao vetor
    >> vetor.pop_back(); //retira o ultimo elemento do vetor
    >> vetor.clear(); // apaga todos os elementos do vetor
    >> sort (vetor.begin(),vetor.end()); // organiza todos os elementos do vetor em ordem crescentes
            >> este sort, prescisa da biblioteca #include <algorithm>
*/

void pinr (int n,vector<int> v);

int main () 
{
    int u = 1,t = 1,n,m,i,j,aux,k,count;
    vector <int> v;
    vector <int> f;

    cin>>n>>m;

    count = 0;
    while (u != 0 && t!= 0){
            v.resize(n);

        for (i = 0;i < m;i++){
            cin>>u>>t;
            if (u == 0 && t == 0){
                break;
            }
            v[u-1]++;
            v[t-1]++;
           // pinr(n,v);
        }
        for (i = 1,aux = v[0];i < n;i++){
            if (aux < v[i]){
                aux = v[i];
            }
        }
        for (i = 0,j = 0;i < n;i++){
            if (aux == v[i]){
                f.push_back(i+1);
                j++;
            }
        }
        sort(f.begin(), f.end());
        cout<<"Teste "<<count + 1<<"\n";

        for (i = 0 ; i < j;i++){
            
            if (j >  1 && (i + 1 != j)) {
                cout<<f[i]<<" ";
            }
            else {
                cout<<f[i]<<"\n";
            }
        }
        f.clear();
        v.clear();

        if (u == 0 && t == 0){
            break;
        }
        count++;
    }

    return 0;
}

void pinr (int n,vector<int> v){
    int i;
    for (i = 0;i < n;i++)
        cout<<v[i]<<" ";
    cout<<"\n";
}