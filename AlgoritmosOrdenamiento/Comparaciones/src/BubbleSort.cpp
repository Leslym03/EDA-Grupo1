#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <string>

using namespace std;

unsigned t0, t1;

void bubbleSort( int *arr, int size ) {
    for ( int i = size - 1; i > 0; i-- ) {    
        for ( int j = 0; j < i; j++ ) {
            if( arr[ j ] > arr[ j + 1 ]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    } 
}

int main() {

    char caracter;
    std::string path, name = "aleatorio";
    std::string pathS, out = "salida";

    int tam[] = {10000, 30000, 50000, 70000, 100000};

    for( int i = 0; i < 10; ++i ) {
        path = "Entradas/" + name + std::to_string(i + 1) + ".txt";
        pathS = "Salidas/BubbleSort/" + out + std::to_string(i + 1) + "cc.txt";
        cout << pathS << endl;
        ofstream fs( pathS );

        char* in = const_cast<char*>( path.c_str());
        
        for(int j = 0; j < 5; ++j ) {
            int *A = new int[tam[j]];
            ifstream file;
            string num;
            int num_int = 0;
            file.open( in, ios::in);
            int c = 0;
            while(!file.eof() && c <=tam[j]){
                getline(file, num);
                stringstream convert(num);
                convert >> num_int;
                A[c] = num_int;
                c++;
            }

            file.close();
            
            t0=clock();
            bubbleSort(A,tam[j]);
            t1 = clock();

            double time = (double( t1 - t0 ) / CLOCKS_PER_SEC);
            fs << tam[j] << " " << time <<endl;
            
            delete[] A;
        }
        fs.close();
    }
}