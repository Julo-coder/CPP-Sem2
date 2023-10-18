#include <iostream>
#include "catalog.h"
using namespace std;

Catalog::Catalog(){}

void Catalog::insertCar(Cars &c) {
    int child = ++count;
    int parent = child/2;
    while (parent and car[parent].getPower() > c.getPower()){
        car[child] = car[parent];
        child = parent;
        parent /= 2;
    }
    car[child] = c;
}

int Catalog::minChild(int parent) {
    int left = 2*parent;
    int right = left + 1;
    if (left > count)return 0;
    if (right > count or car[left].getPower() < car[right].getPower())return left;
    return right;
}

void Catalog::removeCar() {
    Cars last = car[count--];
    int x {1}; int c = minChild(1);
    while (c and car[c].getPower() < last.getPower()){
        car[x] = car[c];
        x = c;
        c = minChild(c); 
    }
    car[x] = last;
}

void Catalog::showCars(){
	for (int i = 1; i < 6; i++){
		cout << car[1].getNumber() << " " << car[1].getPower() << " ";
		removeCar();
	}
	cout << car[1].getNumber() << " " << car[1].getPower() << " ";
}