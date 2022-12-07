#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
void print_vet(int * v,int n);


int main (){

	return 0;
}
void swap(int *a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
}
void print_vet(int *v,int n){
	int i;
	for (i = 0;i < n;i++){
		printf("%d ",v[i]);
	}
	printf("\n");
}

void bubble_sort (int * v,int n){
	int i,j,aux;
	for (i = 0;i<n-1;i++){
		for (j = 0,aux = 0;j < n-1-i;j++){
			if (v[j] > v[j+1]){
				aux = 1;
				swap(&v[j],&v[j+1]);
			}
		}
		if (aux == 0)
			break;
	}
}
void bubble_recursive(int *v,int n){
	if (n <= 1)
		return;
	for (int i = 0;i < n -1;i++){
		if (v[i]> v[i+1])
			swap(&v[i],&v[i+1]);
	}
	bubble_recursive(v,n-1);	
}

void selection_sort (int * v,int n){
	int i,j,aux;
	for (i = 0;i < n-1;i++){
		aux = i
		for (j = i+1;j < n;j++){
			if (v[j] < v[aux])
				aux = i;
		}
		swap(&v[aux],&v[i]);
	}
}

void selection_recursive(int * v,int n,int ini){
	if (ini == n -1)
		return;
	int aux,i;
	for (i = ini+1,aux = ini;i < n-1;i++)
		if (v[i] < v[aux])
			aux = i; 
	swap(&v[aux],&v[i]);

	selection_recursive(v,n,ini+1);	
}

void insertion_sort(int * v,int n){
	int i,j,aux;
	for (i = 1;i < n;i++){
		aux = v[i];
		j = i-1;
		while(j>=0 && v[j] > aux){
			v[j+1] = v[j]; 
			j--;
		}
		v[j+1] = aux;
	}
}

int binary_search(int * v,int min,int max,int x){
	int n = (max+min)/2;
	if (v[n] == x) return x;
	else if (x > v[n]) return binary_search (v,n+1,max,x);
	else if (x < v[n]) return binary_search (v,min,n-1,x);
	return -1;
}
int sequencial_search(int * v,int n,int x){
	if (v[n-1] == x) return x;
	else if (n > 0){
		return sequencial_search(v,n-1,x);
	}
	return -1;
}

void quick_sort(int * v,int low ,int high){
	if (high > low){
		int q = partition(v,low,high);
		quick_sort(v,low,q-1);
		quick_sort(v,n+1,high);
	}
}

int partition(int *v,int low,int high){
	int i = low-1;
	int pivo = v[high];
	int j;

	for ( j = low ; j < high ; j++){
		if (v[j] <= pivo){
			i++;
			swap(&v[j],&v[i]);
		}
	}
	swap(&v[i+1],&v[high]);
	return i+1;
}

void radix_sort(int *v,int n){
	int max = max_vet(v,n);
	for (int exp = 1;max/exp > 0;){
		exp*=10;
		bubble_exp(v,n,exp);
	}
} 

int max_vet(int * v, int n){
	int aux,i;
	aux = v[0];
	for (i = 1;i< n;i++)
		if (v[i] < aux)
			aux = v[i];
	return aux;
}

void bubble_exp(int * v,int n,int exp){
	int i,j;
	for (i = 0; i < n-1;i++){
		for (j= 0;j < n -i -1;j++){
			if (v[j]%exp > v[j+1]%exp){
				swap(&v[j],&v[j+1]);
			}
		}
	}
}

