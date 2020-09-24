#include<iostream>
#include<algorithm>
using namespace std;

// PROTOTIPOS DE LAS FUNCIONES

template < typename Type >
void Imprimir( Type *, int );
void countSort(int *array, int size);

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

void countSort(int *array, int size) {
   int output[size+1];
   int count[size+1];
   int max = array[0];

   for (int i = 1; i < size; i++) {
      if (array[i] > max)
         max = array[i];
   }

   for (int i = 0; i <= max; ++i) {
      count[i] = 0;
   }

   for (int i = 0; i < size; i++) {
      count[array[i]]++;
   }

   for (int i = 1; i <= max; i++) {
      count[i] += count[i - 1];
   }

   for (int i = size - 1; i >= 0; i--) {
      output[count[array[i]] - 1] = array[i];
      count[array[i]]--;
   }
   
   for (int i = 0; i < size; i++) {
      array[i] = output[i];
   }
}