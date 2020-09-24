#include <iostream>
#include <sstream> 
#include <fstream>
#include <ctime> 
#include <string> 

using namespace std;

unsigned t0, t1;

ofstream fs("Salidas/CountSort/salida1cc.txt");

template < typename Type >
Type getMax(Type array[], int size) {
   Type max = array[1];
   for(int i = 2; i<=size; i++) {
      if(array[i] > max)
         max = array[i];
   }
   return max; 
}

template < typename Type >
void countSort(Type *array, int size) {
   Type output[size+1];
   Type max = getMax(array, size);
   Type count[max+1];     
   for(int i = 0; i<=max; i++)
      count[i] = 0;     
   for(int i = 1; i <=size; i++)
      count[array[i]]++;     
   for(int i = 1; i<=max; i++)
      count[i] += count[i-1];    
   for(int i = size; i>=1; i--) {
      output[count[array[i]]] = array[i];
      count[array[i]] -= 1; 
   }
   for(int i = 1; i<=size; i++) {
      array[i] = output[i]; 
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
        countSort(A,tam[j]);
        t1 = clock();

        double time = (double(t1-t0)/CLOCKS_PER_SEC);
        fs << tam[j] << " " << time <<endl;
        delete[] A;
    }

	return 0;

} 