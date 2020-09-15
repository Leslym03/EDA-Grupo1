#include <iostream>
using namespace std;

// PROTOTIPOS DE LAS FUNCIONES

int Lenght( char * );
template < typename Type >
void Imprimir( Type *, int );
template < typename Type >
void InsertionSort( Type *, int );


// FUNCION PRINCIPAL

int main() {

    int A[] = { 1, 3, 5, 2, 4 };
    int tam1 = sizeof( A ) / sizeof( A[ 0 ]);

    InsertionSort( A, tam1 );
    Imprimir( A, tam1 );

    char B[] = { 'z', 'm', 'r', 'a', 'i' };
    int tam2 = Lenght( B );

    InsertionSort( B, tam2 );
    Imprimir( B, tam2 );

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
void InsertionSort( Type *arr, int size ) { 

    for ( int i = 1, j, k; i < size; i++ ) { 
        k = arr[ i ]; 
        j = i - 1; 

        while ( j >= 0 && arr[ j ] > k ) { 
            arr[ j + 1 ] = arr[ j ]; 
            j--; 
        } 
        arr[ j + 1 ] = k; 
    } 
}