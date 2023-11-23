#include <iostream>

using namespace std;

enum fuels{B,D,E,H};

class Car{
    string plateNum;
    int power;
    float weight;
    fuels fuel;

public:
    Car(){};
    Car(string pN, int p, float w, fuels f) : plateNum(pN), power(p), weight(w), fuel(f){};

    string getPlateNum(){
        return plateNum;
    }

    int getPower(){
        return power;
    }
};

class Catalog{
    Car car[10];
    int count{0};

public:
    Catalog(){}
    void showCars(){
        for(int i = 0; i < count; i++) {
            cout << car[i].getPlateNum() << " " << car[i].getPower() << "||";
        }
    }

    void addCar(Car& c){
        car[count] = c;
        count++;
    }

    void deleteCar(int ind){
        if(ind == 10){
            count--;
        }
        car[ind] = car[count - 1];
        count--;
    }
};




int main(){
    Catalog cat1;
    string carNum, fuel;
    float weight;

    int n{0}, carPower{0};
    cin >> n;

    if(n < 0 or n > 10){
        cout << "Bledne wprowadzenie danych.";
        return 0;
    }else{
        for(int i{0}; i < n; i++) {
            cin >> carNum >> carPower >> weight >> fuel;
            if (fuel == "B") {
                Car car(carNum, carPower, weight, fuels::B);
                cat1.addCar(car);
            }
            if (fuel == "D") {
                Car car(carNum, carPower, weight, fuels::D);
                cat1.addCar(car);
            }
            if (fuel == "E") {
                Car car(carNum, carPower, weight, fuels::E);
                cat1.addCar(car);
            }
            if (fuel == "H") {
                Car car(carNum, carPower, weight, fuels::H);
                cat1.addCar(car);
            }
        }
    }
    int ind;
    cin >> ind;
    while(ind < 0 or ind > 10){
        cin >> ind;
    }
    cat1.deleteCar(ind);
    cat1.showCars();
    return 0;
}