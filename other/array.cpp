#include <iostream>
using namespace std;


int main(){
    int del;
    cin >> del ;
    int arr[] = {1,2,3,4,5,6};
    int arr_size = sizeof(arr)/sizeof(int);

    if(del == 6){
        arr_size--;
    }else{
        arr[del] = arr[arr_size - 1];
        arr_size--;
    }

    for(int i = 0; i < arr_size; i++){
        cout << arr[i];
    }
}