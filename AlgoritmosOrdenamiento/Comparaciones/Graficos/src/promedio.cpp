#include <iostream>
using namespace std;

int main(){
    int size, buff;
    size= 10;
    double temp;
    double arr[size];

    for(int j=0; j<size; j++){
        cin >> buff;
        cin >> arr[j];
    }

    for(int i=0; i<9; i++){
        for(int j=0; j<size; j++){
            cin >> buff;
            cin >> temp;
            arr[j]= temp + arr[j];
        }
    }
    buff =0;
    for(int i=0; i<size; i++){
        buff= buff +100000 ;
        cout << buff << " " << arr[i]/size << endl;
    }
    return 0;
}