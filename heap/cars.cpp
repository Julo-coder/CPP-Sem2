#include "../heap/cars.h"

Cars::Cars(){};

Cars::Cars(string n, int p, double w, types t){
    Number = n;
    Power = p;
    Weigth = w;
    Type = t;
}

string Cars::getNumber(){
    return Number;
}
int Cars::getPower(){
    return Power;
}
