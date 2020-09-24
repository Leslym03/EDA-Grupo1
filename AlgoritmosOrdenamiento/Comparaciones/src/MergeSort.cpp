#include <iostream>
#include <sstream> 
#include <fstream>
#include <ctime> 
#include <string> 

using namespace std;

unsigned t0, t1;

ofstream fs("Salidas/MergeSort/salida6cc.txt");

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
void MergeSort( Type *arr, int left, int right ) {
    
    int mid = ( left + right ) / 2;

    if( left < right ) {
        MergeSort( arr, left, mid );
        MergeSort( arr, mid + 1, right );
        Merge( arr, left, mid, right );
    }
}

template < typename Type >
void MergeSort( Type *arr, int size ) {
 
    MergeSort( arr, 0, size - 1 );
} 

int main(){
	int tam [] = {100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000}; 

    for(int j=0;j<10;j++){
        int *A = new int[tam[j]];

        ifstream file;
        string num;
        int num_int=0;
        file.open("Entradas/aleatorio6.txt",ios::in);
        int i=0;
        while(!file.eof() && i<=tam[j]){
            getline(file,num);
            stringstream convert(num);
            convert>>num_int;
            A[i]=num_int;
            i++;
        }
        file.close();

        t0=clock();
        MergeSort(A,tam[j]);
        t1 = clock();

        double time = (double(t1-t0)/CLOCKS_PER_SEC);
        fs << tam[j] << " " << time <<endl;
        delete[] A;
    }

	return 0;

} 