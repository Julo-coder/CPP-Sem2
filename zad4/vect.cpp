#include <iostream>
#include "vect.h"
using namespace std;
/*
podaj - zwracającą element tablicy znajdujący się pod indeksem „indeks” przekazanym jako argument funkcji (w przypadku wyjścia poza zakres wektora, funkcja zwraca jego pierwszy element)

wpisz - przyjmującą w argumencie liczbę naturalną „indeks” oraz liczbę rzeczywistą „wartosc” i ustawiającą wartość elementu tablicy o indeksie „indeks”.
Jeśli podany indeks wychodzi poza zakres wektora to funkcja nie robi nic.

rozmiar - zwracającą rozmiar wektora

dodaj - przyjmującą w argumencie referencję do obiektu typu Wektor, dodającą do tablicy z klasy Wektor wartości tablicy z argumentu funkcji (jeśli jest ich mniej to dodajemy wszystkie,
a jeśli jest ich więcej to dodajemy tylko tyle elementów ile jest w tablicy należącej do obiektu, na którym wywoływana jest metoda).
*/
Wektor::Wektor(int rozm) : akt_rozm(rozm){
    for (int z = 0; z < akt_rozm; z++) {
        tab[z] = 0.0;
    }
}

double Wektor::podaj(int ind) const{
    return (ind >= 0 && ind < akt_rozm) ? tab[ind] : tab[0];
}

void Wektor::wpisz(int ind, double wart){
    if (ind >= 0 && ind < akt_rozm) {
        tab[ind] = wart;
    }
    //return (ind > 0 && ind < akt_rozm) ? tab[ind] = wart : 0;
}

int Wektor::rozmiar() const{
    return akt_rozm;
}

void Wektor::dodaj(const Wektor& v){
    for(int c{0}; c < akt_rozm && c < v.akt_rozm; c++){
        tab[c] += v.tab[c];
    }
}

void Wektor::show(){
    for(int s = 0; s < akt_rozm; s++){
        cout << tab[s] << " " << s << endl;
    }
}


/*
opeartor += -> przeciążenie za pomocą metody w klasie -> realizuje dodawanie dwóch wektorów - działanie analogiczne do funkcji dodaj.
Rozmiar wektora na którym przeprowadzane jest dodawanie nie zmienia się.

operator -= -> przeciążenie za pomocą metody w klasie -> realizuje odejmowanie dwóch wektorów.
Odejmowanie wykonywane jest tyle razy ile elementów posiada mniejszy wektor z odjemnej i odjemnika.
Rozmiar wektora na którym przeprowadzane jest odejmowanie nie zmienia się.

opearator = ->przeciążenie za pomocą metody w klasie -> przepisanie wartości z wektora drugiego do pierwszego.
Po wykonaniu przypisania wektor nadpisywany będzie miał rozmiar i wartości wektora z prawej strony przypisania.

operator [] -> przeciążenie za pomocą metody w klasie -> dostęp do i-tego elementu wektora z możliwością jego nadpisania
(w przypadku wyjścia poza zakres tablicy, funkcja zwraca jej pierwszy element).

operator + -> przeciążenie za pomocą metody globalnej -> realizuje dodawanie dwóch wektorów - działanie analogiczne do funkcji dodaj i operatora +=.
Rozmiar wektora wynikowego jest taki sam jak rozmiar pierwszego składnika sumy.

operator << -> przeciążenie za pomocą metody globalnej -> wypisujący zawartość wektora w postaci: [1 4 7  … 2]

operator ! -> przeciążenie za pomocą metody globalnej -> zwracający wektor liczb o przeciwnych znakach

operator - -> przeciążenie za pomocą metody globalnej -> realizuje odejmowanie dwóch wektorów.
Wektor wynikowy przyjmuje rozmiar wektora będącego odjemną w przeprowadzanej operacji odejmowania.
Działanie analogiczne do operatora -=.
*/

Wektor& Wektor::operator+=(const Wektor &v){
    for(int c{0}; c < akt_rozm && c < v.akt_rozm; c++){
        tab[c] += v.tab[c];
    }
    return *this;
}

Wektor& Wektor::operator-=(const Wektor &v){
    for(int c{0}; c < akt_rozm && c < v.akt_rozm; c++){
        tab[c] -= v.tab[c];
    }
    return *this;
}

Wektor& Wektor::operator=(const Wektor& v) {
    akt_rozm = v.akt_rozm;
    for (int i = 0; i < akt_rozm; i++) {
        tab[i] = v.tab[i];
    }
    return *this;
}

double& Wektor::operator[](int ind) {
    if (ind < 0 || ind >= akt_rozm) {
        return tab[0];
    }
    return tab[ind];
}

Wektor operator+(const Wektor& pier, const Wektor& dru){
    int wiekszyRozm = (pier.rozmiar() > dru.rozmiar()) ? pier.rozmiar() : dru.rozmiar();
    Wektor wynik(wiekszyRozm);

    for (int c = 0; c < wiekszyRozm; c++) {
        double wart1 = (c < pier.rozmiar()) ? pier.podaj(c) : 0;
        double wart2 = (c < dru.rozmiar()) ? dru.podaj(c) : 0;
        wynik.wpisz(c, wart1 + wart2);
    }

    return wynik;
}


Wektor operator-(const Wektor& pier, const Wektor& dru){
    int wiekszyRozm = (pier.rozmiar() > dru.rozmiar()) ? pier.rozmiar() : dru.rozmiar();
    Wektor wynik(wiekszyRozm);

    for (int c = 0; c < wiekszyRozm; c++) {
        double wart1 = (c < pier.rozmiar()) ? pier.podaj(c) : 0;
        double wart2 = (c < dru.rozmiar()) ? dru.podaj(c) : 0;
        wynik.wpisz(c, wart1 - wart2);
    }

    return wynik;
}

Wektor operator!(Wektor& v){
    int rozm= v.rozmiar();
    Wektor wynik(rozm);
    for (int i = 0; i < rozm; i++) {
        wynik.wpisz(i, -v.podaj(i));
    }
    return wynik;
}

ostream& operator<<(ostream& z,const Wektor& v ){
    z << "[";
    for(int s = 0; s < v.rozmiar(); s++){
        z << v.podaj(s);
        if (s < v.rozmiar() - 1) {
            z << " ";
        }
    }
    z << "]";
    return z;
}

