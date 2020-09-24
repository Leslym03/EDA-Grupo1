#include <iostream>
#include <sstream> 
#include <fstream>
#include <ctime> 
#include <string> 

using namespace std;

unsigned t0, t1;

ofstream fs("Salidas/QuickSort/salida10cc.txt");

template < typename Type >
void Swap( Type &a, Type &b ) {
    Type tmp = a;
    a = b;
    b = tmp;
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
void QuickSort( Type arr[], int size ) {
    QuickSort( arr, 0, size - 1 );
}

int main(){
	int tam [] = {100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000}; 

    for(int j=0;j<10;j++){
        int *A = new int[tam[j]];

        ifstream file;
        string num;
        int num_int=0;
        file.open("Entradas/aleatorio10.txt",ios::in);
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
        QuickSort(A,tam[j]);
        t1 = clock();

        double time = (double(t1-t0)/CLOCKS_PER_SEC);
        fs << tam[j] << " " << time <<endl;
        delete[] A;
    }

	return 0;

} 