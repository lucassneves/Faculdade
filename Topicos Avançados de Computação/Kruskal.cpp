/*
 *  UnionFind.cpp
 *  
 *
 *  Created by Thierson Rosa on 24/11/11.
 *  Copyright 2011 Instituto de Informatica - UFG. All rights reserved.
 *
 */
// Estrutura de dados para representar um no da arvore de florestas que representara os conjuntos disjuntos
#include<list>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int V; //Numero de nos do grafo
int A; // Quantidade de arestas



class ConjuntoConjuntosDijuntos  {
	//Implementa o conjunto de conjunto disjuntos para ser utilzado com operaçoes Union-find.
	
private:
	struct no {
		int pai;
		int rank;
	};
	typedef struct no Tnodo;
	int z;
	vector<Tnodo> conjConjDis;
	void Link(int x, int y){
		if(conjConjDis[x].rank > conjConjDis[y].rank)
			conjConjDis[y].pai=x;
		else{
			conjConjDis[x].pai=y;
			if(conjConjDis[x].rank==conjConjDis[y].rank)
				conjConjDis[y].rank=conjConjDis[y].rank+1;
		}
	}
	
public: 
	 ConjuntoConjuntosDijuntos(int N){
		conjConjDis.resize(N);
		//Gerar N conjuntos disjuntos unitarios. O próprio elemento é o representante de seu conjunto
		for(int i=0;i<N;i++){   
			conjConjDis[i].pai=i;
			conjConjDis[i].rank=0;
		}
	}	
	int findSet(int x){
		if(conjConjDis[x].pai != x)
			conjConjDis[x].pai =  findSet(conjConjDis[x].pai);
		return(conjConjDis[x].pai);	
	}
	void Union(int x, int y){
		Link(findSet(x), findSet(y));
	}
	int rank(int i){
		return(conjConjDis[i].rank);
	}
};

typedef struct aresta {
	int de, para, peso;
} Taresta;
bool operator<(const Taresta& a, const Taresta b) {
    return (a.peso < b.peso);
}

int main(){
	int de, para, peso;
	cin >> V >> A; //Leitura do número de vertices V e do numero de arestas A
	
	vector <Taresta> grafo(A); //grafo de entrada representado como um conjunto de arestas		
	vector <Taresta> agm; // arvore geradora mínima;
	
	for(int i=0;i<A;i++){
		cin >> de >> para >> peso;
		grafo[i].de=de;
		grafo[i].para=para;
		grafo[i].peso=peso;	
	}
	//Ordenar as arestas do grafo em ordem crescente de peso
	sort(grafo.begin(), grafo.begin()+A); 
	//Cria e iniciar colecao de conjuntos disjuntos que conterá a floresta de arvores necessarias para o algoritmo de Kruskal
	ConjuntoConjuntosDijuntos arvsPof(V);
	
	vector<Taresta>::iterator it;
	for(it=grafo.begin();it!=grafo.end();it++){
		cout << it->de  << " " << it->para << " " << it->peso << endl;
		if(arvsPof.findSet(it->de)!=arvsPof.findSet(it->para)){ //A aresta de menor peso no momento e uma aresta segura?
			arvsPof.Union(it->de, it->para); //Fazer a uniao dos subarvores que contem os dois vertices - formando a arvore geradora minima
			//inserir a aresta na árvore geradora minima
			Taresta aux;
			aux.de=it->de;
			aux.para = it->para;
			aux.peso =it->peso;
			agm.push_back(aux);
			
		}
		
		
	}
	// No final, se ha uma arvore geradora minima, deve haver um unico conjunto com todos os vertices na colecao de conjuntos disjuntos.
	//Alem disso, o rank do elemento representante do conjunto deve ser igual ao número de vertices menos 1

		cout << "Arfore geradora minima: " << endl;
		for(it=agm.begin(); it!=agm.end(); it++)
			cout << "de : " << it->de << " para: " << it->para << " peso: " << it->peso << endl;

	return(1);
}
	 
	
