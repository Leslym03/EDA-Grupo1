#include <iostream>
using namespace std;

// PROTOTIPOS DE LAS FUNCIONES

template < typename Type>
int Length (Type *);

template < typename Type>
void Imprimir (Type *, int); // array, tamanho

template < typename Type>
void Swap( Type &, Type &);

template < typename Type>
void Heapify ( Type *, int , int );// array, indice de un nodo y tamanho del heap

template < typename Type>
void HeapSort ( Type *, int ); //array , tamanho

// FUNCION PRINCIPAL

int main () {
	int array[] = {12, 11, 13, 5, 6, 7};
	int n = sizeof(array)/sizeof(array[0]);

	HeapSort<int>(array, n);
	Imprimir<int>(array,n);
	return 0;
}

// DESARROLLO DE LAS FUNCIONES

template <typename Type>
int Length ( Type * array){
	int c = 0;
	while( *(array + c)) c++;
	return c;
}

template <typename Type>
void Imprimir( Type * array, int size){
	for ( int i = 0; i < size; ++i){
		cout << *(array + i) << " ";
	}
	cout << endl;
}

template <typename Type>
void Swap(Type &a, Type &b){
	Type tmp = a;
	a = b;
	b = tmp;
}

template <typename Type>
void Heapify ( Type * array, int size, int indice){
	int largest = indice;
	int l = 2 * indice + 1;
	int r = 2 * indice + 2;

	if(l < size && array[l] > array[largest])
			largest = l;

	if(r < size && array[r] > array[largest])
			largest = r;

	if(largest != indice){
		swap<Type>(array[indice], array[largest]);
		Heapify<Type>(array, size, largest);
	}
}

template <typename Type>
void HeapSort(Type *array, int size){
	for(int i = size / 2 - 1; i >= 0; i--)
		Heapify<Type>(array, size, i);

	for(int i = size - 1; i > 0; i--){
		Swap<Type>(array[0], array[i]);
		Heapify<Type>(array, i, 0);
	}
}
