#include <iostream>
using namespace std;

// PROTOTIPOS DE LAS FUNCIONES

int Lenght( char * );
template < typename Type >
void Imprimir( Type *, int );
template < typename Type >
void Swap( Type &a, Type &b );
template < typename Type >
void BubbleSort( Type *arr, int n );

// FUNCION PRINCIPAL

int main() {

    int A[] = { 1, 3, 5, 2, 4 };
    int tam1 = sizeof( A ) / sizeof( A[ 0 ]);

    BubbleSort( A, tam1 );
    Imprimir( A, tam1 );

    char B[] = { 'z', 'm', 'r', 'a', 'i' };
    int tam2 = Lenght( B );

    BubbleSort( B, tam2 );
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
void BubbleSort( Type *arr, int size ) {

    for ( int i = size - 1; i > 0; i-- )       
        for ( int j = 0; j < i; j++ )
            if( arr[ j ] > arr[ j + 1 ]) 
                Swap( arr[ j ], arr[ j + 1 ]); 
}

template < typename Type >
void Swap( Type &a, Type &b ) {
    
    Type temp = a;
    a = b;
    b = temp;
}


