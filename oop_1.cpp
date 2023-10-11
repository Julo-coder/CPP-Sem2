#include <iostream>
using namespace std;

/*
Klasa przedstawiająca samochód powinna zawierać:

Cztery atrybuty opisujące samochód: numer rejestracyjny, moc silnika w KM, waga w tonach oraz rodzaj silnika (B jako benzynowy, D jako Diesel, E jako elektryczny, H jako hybryda).
Konstruktor inicjalizujący powyższe atrybuty w kolejności podanej powyżej.
Numer rejestracyjny jest ciągiem 4 znaków (liter lub cyfr) bez spacji. Moc jest liczbą całkowitą, a waga jest liczbą zmiennoprzecinkową.
Wszystkie atrybuty powinny być zadeklarowane jako zmienne prywatne, a jakikolwiek dostęp spoza klasy powinien się odbywać poprzez odpowiednie funkcje dostępowe.
*/

enum types { B, D, E, H};


class Car {
    string Number;
    int Power;
    double Weigth;
    types Type;

    public:
    Car (string number, int power, double weigth, types type){
        Number = number;
        Power = power;
        Weigth = weigth;
        Type = type;
    }
    void showClass(){
        cout << Number << endl;
        cout << Power << endl;
        cout << Weigth << endl;
        cout << Type << endl;
    }
    
};


int main(){
    
    return 0;
}