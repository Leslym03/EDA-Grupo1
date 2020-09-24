#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){
    int num;
    srand(time(NULL));
    for(int i=0; i<1000000; i++){
        num = rand();
        cout << num << endl;
    }
    return 0;
}