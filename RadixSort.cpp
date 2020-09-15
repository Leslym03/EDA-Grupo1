#include <iostream>
using namespace std;

// PROTOTIPOS DE LAS FUNCIONES

int Lenght( char * );
template < typename Type >
void Imprimir( Type *, int );
template < typename Type >
int GetMax( Type *, int );
template < typename Type >
void RadixSort( Type *, int );
template < typename Type >  
void CountSort( Type *, int, int );

// FUNCION PRINCIPAL

int main() {

    int A[] = { 5,10,15,20,25,50,40,30,20,10,9524,878,17,1,99,18785,3649,164,94,
        123,432,654,3123,654,2123,543,131,653,123,533,1141,532,213,2241,824,1124,42,134,411,
        491,341,1234,527,388,245,1992,654,243,987 };
    int tam = sizeof( A ) / sizeof( *A );
    int a = GetMax( A, tam );
    RadixSort( A, tam );
    Imprimir( A, tam );

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
int GetMax( Type *arr, int size ) { 

    int max = arr[ 0 ];

    for( int i = 1; i < size; ++i ) 
        if ( arr[ i ] > max) 
            max = arr[ i ]; 
    return max; 
}

template < typename Type >  
void CountSort( Type *arr, int size, int n_dig ) {

    int out[ size ];
    int count[ 10 ] = { 0 }; 
  
    for( int i = 0; i < size; i++ )
        count[( arr[ i ] / n_dig ) % 10 ]++; 

    for( int i = 1; i < 10; i++ ) 
        count[ i ] += count[ i - 1 ]; 
  
    for( int i = size - 1; i >= 0; i-- ) { 
        out[ count[( arr[ i ] / n_dig ) % 10 ] - 1 ] = arr[ i ]; 
        count[( arr[ i ] / n_dig ) % 10 ]--; 
    } 
  
    for ( int i = 0; i < size; i++ ) 
        arr[ i ] = out[ i ]; 
} 

template < typename Type >
void RadixSort( Type *arr, int size ) { 
    int max = GetMax( arr, size ); 
    for( int n_dig = 1; max / n_dig > 0; n_dig *= 10 ) 
        CountSort( arr, size, n_dig ); 
} 