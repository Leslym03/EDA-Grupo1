#include <iostream>
#include <sstream> 
#include <fstream>
#include <ctime> 
#include <string> 

using namespace std;

unsigned t0, t1;

ofstream fs("Salidas/CountSort/salida10cc.txt");

void countSort(int *array, int size) {
   int output[size+1];
   int max = array[0];

   for (int i = 1; i < size; i++) {
      if (array[i] > max)
         max = array[i];
   }
   int count[max+1];

   for (int i = 0; i <= max; ++i) {
      count[i] = 0;
   }

   for (int i = 0; i < size; i++) {
      count[array[i]]++;
   }

   for (int i = 1; i <= max; i++) {
      count[i] += count[i - 1];
   }

   for (int i = size - 1; i >= 0; i--) {
      output[count[array[i]] - 1] = array[i];
      count[array[i]]--;
   }
   
   for (int i = 0; i < size; i++) {
      array[i] = output[i];
   }
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
        countSort(A,tam[j]);
        t1 = clock();

        double time = (double(t1-t0)/CLOCKS_PER_SEC);
        fs << tam[j] << " " << time <<endl;
        delete[] A;
    }

	return 0;

} 