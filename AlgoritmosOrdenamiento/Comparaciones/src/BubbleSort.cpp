#include <iostream>
#include <sstream> 
#include <fstream>
#include <ctime> 
#include <string> 

using namespace std;

unsigned t0, t1;

ofstream fs("Salidas/BubbleSort/salida1cc.txt");

template < typename Type >
void Swap( Type &a, Type &b ) {
    
    Type temp = a;
    a = b;
    b = temp;
}

template < typename Type >
void BubbleSort( Type *arr, int size ) {

    for ( int i = size - 1; i > 0; i-- )       
        for ( int j = 0; j < i; j++ )
            if( arr[ j ] > arr[ j + 1 ]) 
                Swap( arr[ j ], arr[ j + 1 ]); 
}

int main(){
	int tam [] = {100000, 300000, 500000, 700000, 1000000}; 

    for(int j=0;j<5;j++){
        int *A = new int[tam[j]];

        ifstream file;
        string num;
        int num_int=0;
        file.open("Entradas/aleatorio1.txt",ios::in);
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
        BubbleSort(A,tam[j]);
        t1 = clock();

        double time = (double(t1-t0)/CLOCKS_PER_SEC);
        fs << tam[j] << " " << time <<endl;
        delete[] A;
    }

	return 0;

} 