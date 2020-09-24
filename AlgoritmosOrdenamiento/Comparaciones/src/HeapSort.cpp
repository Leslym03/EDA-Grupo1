#include <iostream>
#include <sstream> 
#include <fstream>
#include <ctime> 
#include <string> 

using namespace std;

unsigned t0, t1;

ofstream fs("Salidas/HeapSort/salida1cc.txt");

template <typename Type>
void Swap(Type &a, Type &b){
	Type tmp = a;
	a = b;
	b = tmp;
}

template <typename Type>
void Heapify ( Type * array, int size, int indice){
	int largest = indice;
	int l = 2 * indice + 1;
	int r = 2 * indice + 2;

	if(l < size && array[l] > array[largest])
			largest = l;

	if(r < size && array[r] > array[largest])
			largest = r;

	if(largest != indice){
		swap<Type>(array[indice], array[largest]);
		Heapify<Type>(array, size, largest);
	}
}

template <typename Type>
void HeapSort(Type *array, int size){
	for(int i = size / 2 - 1; i >= 0; i--)
		Heapify<Type>(array, size, i);

	for(int i = size - 1; i > 0; i--){
		Swap<Type>(array[0], array[i]);
		Heapify<Type>(array, i, 0);
	}
}

int main(){
	int tam [] = {100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000}; 

    for(int j=0;j<10;j++){
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
        HeapSort(A,tam[j]);
        t1 = clock();

        double time = (double(t1-t0)/CLOCKS_PER_SEC);
        fs << tam[j] << " " << time <<endl;
        delete[] A;
    }

	return 0;

} 