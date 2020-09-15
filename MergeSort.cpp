#include <iostream>
using namespace std;

// PROTOTIPOS DE LAS FUNCIONES

int Lenght( char * );
template < typename Type >
void Imprimir( Type *, int );
template < typename Type >
void Merge( Type *, int, int, int );
template < typename Type >
void MergeSort( Type *, int );
template < typename Type >
void MergeSort( Type *, int, int );

// FUNCION PRINCIPAL

int main() {

    int A[] = { 1, 3, 5, 2, 4 };
    int tam1 = sizeof( A ) / sizeof( A[ 0 ]);

    MergeSort( A, tam1 );
    Imprimir( A, tam1 );

    char B[] = { 'z', 'm', 'r', 'a', 'i'};
    int tam2 = Lenght( B );

    MergeSort( B, tam2 );
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
void Merge( Type *arr, int left, int mid, int right ) {

    Type *temp = new Type[ right - left + 1 ];
    int i = left;
    int j = mid + 1;
    int k = 0;

    while( i <= mid && j <= right ) {
        if( arr[ i ] <= arr[ j ])
            temp[ k++ ] = arr[ i++ ];
        else
            temp[ k++ ] = arr[ j++ ];
    }

    while( i <= mid )
        temp[ k++ ] = arr[ i++ ];
    while( j <= right )
        temp[ k++ ] = arr[ j++ ];
    for( k = 0, i = left; i <= right; ++i, ++k )
        arr[ i ] = temp[ k ];
 
    delete[] temp;
}

template < typename Type >
void MergeSort( Type *arr, int size ) {
    
    MergeSort( arr, 0, size - 1 );
}


template < typename Type >
void MergeSort( Type *arr, int left, int right ) {
    
    int mid = ( left + right ) / 2;

    if( left < right ) {
        MergeSort( arr, left, mid );
        MergeSort( arr, mid + 1, right );
        Merge( arr, left, mid, right );
    }
}



