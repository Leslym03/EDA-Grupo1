#include <iostream>
#include <sstream> 
#include <fstream>
#include <ctime> 
#include <string> 

using namespace std;

unsigned t0, t1;

ofstream fs("Salidas/SelectionSort/salida1cc.txt");

template < typename Type >
void Swap( Type &a, Type &b ) {
    Type tmp = a;
    a = b;
    b = tmp;
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
        selectionSort(A,tam[j]);
        t1 = clock();

        double time = (double(t1-t0)/CLOCKS_PER_SEC);
        fs << tam[j] << " " << time <<endl;
        delete[] A;
    }

	return 0;

} 