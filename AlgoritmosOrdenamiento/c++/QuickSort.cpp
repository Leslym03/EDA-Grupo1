#include <iostream>
using namespace std;

// PROTOTIPOS DE LAS FUNCIONES

int Lenght( char * );
template < typename Type >
void Imprimir( Type *, int );
template < typename Type >
void QuickSort( Type *, int );
template < typename Type >
void QuickSort( Type *, int, int );
template < typename Type >
void Swap( Type &, Type & );

// FUNCION PRINCIPAL

int main() {

    int A[] = { 1, 3, 5, 2, 4 };
    int tam1 = sizeof( A ) / sizeof( A[ 0 ]);

    QuickSort( A, tam1 );
    Imprimir( A, tam1 );

    char B[] = { 'z', 'm', 'r', 'a', 'i' };
    int tam2 = Lenght( B );

    QuickSort( B, tam2 );
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
void QuickSort( Type arr[], int size ) {

    QuickSort( arr, 0, size - 1 );
}

template < typename Type >
void QuickSort( Type arr[], int left, int right ) {

    int i = left, j = right;
    int pivot = arr[( left + right ) / 2 ];

    while( i <= j ) {
        while ( arr[ i ] < pivot )
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            Swap( arr[ i ], arr[ j ]);
                i++;
                j--;
        }
    }

    if (left < j)
        QuickSort( arr, left, j );
    if (i < right)
        QuickSort( arr, i, right );
}

template < typename Type >
void Swap( Type &a, Type &b ) {

    Type tmp = a;
    a = b;
    b = tmp;
}