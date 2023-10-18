#include <iostream>
#include "./catalog.h"
using namespace std;


int main(){
    Catalog cat;
    string number, kind;
    int power, rem;
    double weigth;
    
    for(int i = 0; i < 6; i++){
        bool isNotGood = true;
        while(isNotGood){
            cin >> number;
            if(number.length() > 4){
                isNotGood = true;
            }else{
                bool valid = true;
                for(int i = 0; i < number.length(); i++){
                    int ascii_letter = (int)number[i];
                    if(!((ascii_letter >= 48 and ascii_letter <= 57) or (ascii_letter >= 65 and ascii_letter <= 90) or (ascii_letter >= 97 and ascii_letter <= 122))){
                        valid = false;
                        break;
                    }
                }
                if(valid){
                    isNotGood = false;
                }
            }
        }
        cin >> power >> weigth >> kind;
        if(kind == "B"){
            Cars car(number, power, weigth, types::B);
            cat.insertCar(car);
        }
        if(kind == "D"){
            Cars car(number, power, weigth, types::D);
            cat.insertCar(car);
        }
        if(kind == "E"){
            Cars car(number, power, weigth, types::E);
            cat.insertCar(car);
        }
        if(kind == "H"){
            Cars car(number, power, weigth, types::H);
            cat.insertCar(car);
        }
        
    };

    cat.showCars();
    return 0;
}