#include<iostream>
#include<algorithm>
using namespace std;

// PROTOTIPOS DE LAS FUNCIONES

template < typename Type >
void Imprimir( Type *, int );

template < typename Type >
Type getMax(Type array[], int size);

template < typename Type >
void countSort(Type *array, int size);

// FUNCION PRINCIPAL

int main() {
    int A[] = { 1, 3, 5, 2, 4 };
    int tam1 = sizeof( A ) / sizeof( A[ 0 ]);

    countSort(A, tam1);
    Imprimir( A, tam1 );

   return 0;
}

// DESARROLLO DE LAS FUNCIONES

template < typename Type >
void Imprimir( Type *arr, int size ) {

    for( int i = 0; i < size; ++i ) {
        cout << *( arr + i ) << " ";
    }
    cout << endl;
}

template < typename Type >
Type getMax(Type array[], int size) {
   Type max = array[1];
   for(int i = 2; i<=size; i++) {
      if(array[i] > max)
         max = array[i];
   }
   return max; 
}

template < typename Type >
void countSort(Type *array, int size) {
   Type output[size+1];
   Type max = getMax(array, size);
   Type count[max+1];     
   for(int i = 0; i<=max; i++)
      count[i] = 0;     
   for(int i = 1; i <=size; i++)
      count[array[i]]++;     
   for(int i = 1; i<=max; i++)
      count[i] += count[i-1];    
   for(int i = size; i>=1; i--) {
      output[count[array[i]]] = array[i];
      count[array[i]] -= 1; 
   }
   for(int i = 1; i<=size; i++) {
      array[i] = output[i]; 
    }
}