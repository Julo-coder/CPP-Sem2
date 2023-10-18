#pragma once
#include <iostream>
using namespace std;
enum types {B, D, E, H};

class Cars {
    string Number;
    int Power;
    double Weigth;
    types Type;

    public:
    Cars();
    Cars(string n, int p, double w, types t);
    string getNumber();
    int getPower();
};