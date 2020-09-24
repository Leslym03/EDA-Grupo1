#include <bits/stdc++.h> 
using namespace std; 

// PROTOTIPOS DE LAS FUNCIONES

int Lenght( char * );

template < typename Type >
void Imprimir( Type *, int );

template < typename Type >
void Swap( Type &a, Type &b );

template < typename Type >
void selectionSort(Type arr[], int n);

// FUNCION PRINCIPAL
int main(){  
    int A[] = {64, 25, 12, 22, 11};  
    int tam1 = sizeof(A)/sizeof(A[0]);  
    selectionSort(A, tam1);  
    Imprimir(A, tam1);  
    return 0;  
}  

// DESARROLLO DE LAS FUNCIONES

int Lenght( char *arr ) {

    int c = 0;

    while( *( arr + c )) c++;
    return c;
}

template < typename Type >
void Imprimir( Type *arr, int size ) {

    for( int i = 0; i < size; ++i ) {
        cout << *( arr + i ) << " ";
    }
    cout << endl;
}

template < typename Type >
void Swap( Type &a, Type &b ) {
    Type temp = a;
    a = b;
    b = temp;
}

template < typename Type >
void selectionSort(Type *arr, int n) {  
    int i, j, min_idx;  
  
    for (i = 0; i < n-1; i++) {  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
  
        swap(arr[min_idx], arr[i]);  
    }  
}  
  