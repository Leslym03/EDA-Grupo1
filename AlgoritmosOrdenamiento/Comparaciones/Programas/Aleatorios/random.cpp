#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){
    int num;
    srand(time(NULL));
    for(int i=0; i<5500000; i++){
        num = 1 + rand() % (10000);
        cout << num<< " ";
    }
    return 0;
}