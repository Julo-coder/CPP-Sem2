#pragma once
#include <iostream>
using namespace std;
/*
Napisz klasę Wektor, przechowującą tablicę liczb rzeczywistych o rozmiarze MAX_ROZMIAR równym 100 (zmienna prywatna) oraz zmienną prywatną przechowującą informację o aktualnej
liczbie elementów przechowywanych w tablicy. Klasa Wektor powinna udostępniać następujące metody:

Konstruktor - przyjmujący w argumencie rozmiar tworzonego wektora (liczba z przedziału od 1 do 100) i nadający tablicy początkowe wartości równe 0.
Rozmiar raz zainicjalizowanego wektora nie może ulec zmianie.

podaj - zwracającą element tablicy znajdujący się pod indeksem „indeks” przekazanym jako argument funkcji (w przypadku wyjścia poza zakres wektora, funkcja zwraca jego pierwszy element)

wpisz - przyjmującą w argumencie liczbę naturalną „indeks” oraz liczbę rzeczywistą „wartosc” i ustawiającą wartość elementu tablicy o indeksie „indeks”.
Jeśli podany indeks wychodzi poza zakres wektora to funkcja nie robi nic.

rozmiar - zwracającą rozmiar wektora

dodaj - przyjmującą w argumencie referencję do obiektu typu Wektor, dodającą do tablicy z klasy Wektor wartości tablicy z argumentu funkcji (jeśli jest ich mniej to dodajemy wszystkie,
a jeśli jest ich więcej to dodajemy tylko tyle elementów ile jest w tablicy należącej do obiektu, na którym wywoływana jest metoda).
*/

class Wektor{
    static const int MAX_ROZMIAR = 100;
    double tab[MAX_ROZMIAR];
    int akt_rozm;

public:
    Wektor(int rozm);
    double podaj(int indeks) const;
    void wpisz(int indeks, double wartosc);
    int rozmiar() const;
    void dodaj(const Wektor &v);
    void show();
    Wektor& operator+=(const Wektor &v);
    Wektor& operator-=(const Wektor &v);
    Wektor& operator=(const Wektor &v);
    double& operator[](int indeks);
};

ostream& operator<<(ostream& z,const Wektor& v );
Wektor operator-(const Wektor& pier, const Wektor& dru);
Wektor operator+(const Wektor& pier, const Wektor& dru);
Wektor operator!(Wektor& v);