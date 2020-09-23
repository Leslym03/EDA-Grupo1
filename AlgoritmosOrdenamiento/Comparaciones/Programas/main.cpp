#include "func.h"
#include <iostream>
#include <ctime> 
using namespace std;

unsigned t0, t1;

int main(){
    int tam[] = {100000, 300000, 500000, 700000, 900000, 1000000};
    for(int j=0;j<6;j++){
        int *A = new int[tam[j]];

        for(int k=0; k< tam[j]; k++){
            cin >> A[k];
        }

        t0=clock();
        // Algoritmos de ordenacion
        /**
        BubbleSort( A, tam[j] );
        countSort(A, tam[j]);
        HeapSort(A, tam[j]);
        InsertionSort( A, tam[j] );
        MergeSort( A, tam[j] );
        QuickSort( A, tam[j] );
        selectionSort(A, tam[j]);  
        **/

        t1 = clock();
        
        double time = (double(t1-t0)/CLOCKS_PER_SEC);
        cout << tam[j] << " " << time << endl;
        delete[] A;
    }
    return 0;
}