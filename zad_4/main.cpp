#include <iostream>
#include "vect.h"
using namespace std;


int main(){
    int n1, n2;
    cout << "n1="; cin >> n1;
    Wektor w1(n1);
    cout << "w1=";
    double x;
    for (int i = 0; i < n1; ++i){    
        cin >> x;
        w1.wpisz(i, x);
    }
   
    cout << "n2="; cin >> n2;
    Wektor w2(n2);
    cout << "w2=";
    for (int i = 0; i < n2; ++i){
        cin >> x;
        w2.wpisz(i,x);
    }

    w1 = w2;
    //w2.show();
    w1.show();

}