#pragma once
#include <iostream>
#include "cars.h"
using namespace std;


class Catalog {
    Cars car[7];
    int count{0};

    public:
    Catalog();
    int minChild(int parent);
    void insertCar(Cars &c);
    void removeCar();
    void showCars();
};