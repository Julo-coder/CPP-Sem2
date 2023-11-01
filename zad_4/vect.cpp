#include "vect.h"
#include <iostream>
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
      tab[z] = 0;
    }
};

double Wektor::podaj(int ind){
    return (ind >= 0 && ind < akt_rozm) ? tab[ind] : tab[0];
};

void Wektor::wpisz(int ind, double wart){
    if (ind >= 0 && ind < akt_rozm) {
      tab[ind] = wart;
    }
    //return (ind > 0 && ind < akt_rozm) ? tab[ind] = wart : 0;
};

int Wektor::rozmiar(){
    return akt_rozm;
};

void Wektor::dodaj(const Wektor& v){
    for(int c{0}; c < akt_rozm && c < v.akt_rozm; c++){
        tab[c] += v.tab[c];
    }
};

void Wektor::show(){
    for(int s = 0; s < akt_rozm; s++){
        cout << tab[s] << " " << s << endl;
    }
    cout << endl;
    cout << akt_rozm;
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

void Wektor::operator+=(const Wektor &v){
    for(int c{0}; c < akt_rozm && c < v.akt_rozm; c++){
        tab[c] += v.tab[c];
    }
}

void Wektor::operator-=(const Wektor &v){
    for(int c{0}; c < akt_rozm && c < v.akt_rozm; c++){
        tab[c] -= v.tab[c];
    }
}

void Wektor::operator=(const Wektor &v){
    for(int c{0}; c < akt_rozm && c < v.akt_rozm; c++){
        akt_rozm = v.akt_rozm;
        tab[c] = v.tab[c];
    }
}

void Wektor::operator[](const Wektor &v){
    for(int c{0}; c < akt_rozm && c < v.akt_rozm; c++){
        tab[c] += v.tab[c];
    }
}

