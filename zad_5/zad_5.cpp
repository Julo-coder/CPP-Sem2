#include<iostream>

using namespace std;

enum plci{
    K, M
};

class Osoba{
    string imie;
    string nazwisko;
    float waga;
    float wzrost;
    int wiek;
protected:
    plci plec;

public:
    Osoba(){}
    Osoba(string imie, string nazwisko, float waga, float wzrost, int wiek, plci plec)
            : imie(imie), nazwisko(nazwisko), waga(waga), wzrost(wzrost), wiek(wiek), plec(plec){}

    void pokazDane(){
        cout << imie << " " << nazwisko;
    }

    float obliczBmi(){
        return waga/((wzrost/100)*(wzrost/100));
    }

    int dajWiek(){
        return wiek;
    }

    string wysImie(){
        return imie;
    }

    string wysNaz(){
        return nazwisko;
    }
};



class Student : public Osoba{
    string indeks;
    int rok;
    double oceny[10];

public:
    Student(){}
    Student(string imie, string nazwisko, float waga, float wzrost, int wiek, plci plec, string nr, int r)
            : Osoba(imie, nazwisko, waga, wzrost, wiek, plec), indeks(nr), rok(r){}

    double srednia(){
        double suma{0};
        for(int i = 0; i < 5; i++){
            suma += oceny[i];
        }
        return suma/5;
    }

    void wstawOcen(int ind, double ocena){
        oceny[ind] = ocena;
    }

    string wysInd(){
        return indeks;
    }
};




class Pracownik : public Osoba{
    string praca;
    string stanowisko;
    float wynagr;
    float lataPracy;

public:
    Pracownik(){}
    Pracownik(string imie, string nazwisko, float waga, float wzrost, int wiek, plci plec, string prac, string stan, float wy, float lata) :
            Osoba(imie, nazwisko, waga, wzrost, wiek, plec), praca(prac), stanowisko(stan), wynagr(wy), lataPracy(lata){};

    int wiekEmerytura(int wiek){
        return (plec == M) ? 65 - wiek : 60 - wiek;
    }

};



class Kierunek{
    string nazwa;
    Student tab[5][10];
    int liczbaStd;

    int liczbaStd1 = 0;
    int liczbaStd2 = 0;
    int liczbaStd3 = 0;
    int liczbaStd4 = 0;
    int liczbaStd5 = 0;
public:

    Kierunek(string nazwaK) : nazwa(nazwaK){ liczbaStd = 0;}

    void dodajStd(int rok, Student& osoba){
        switch(rok){
            case 1:{
                if(liczbaStd1 < 10){
                    tab[0][liczbaStd1] = osoba;
                    liczbaStd1++;
                    liczbaStd++;
                }
                break;
            }
            case 2:{
                if(liczbaStd2 < 10){
                    tab[1][liczbaStd2] = osoba;
                    liczbaStd2++;
                    liczbaStd++;
                }
                break;
            }
            case 3:{
                if(liczbaStd3 < 10){
                    tab[2][liczbaStd3] = osoba;
                    liczbaStd3++;
                    liczbaStd++;
                }
                break;
            }
            case 4:{
                if(liczbaStd4 < 10){
                    tab[3][liczbaStd4] = osoba;
                    liczbaStd4++;
                    liczbaStd++;
                }
                break;
            }
            case 5:{
                if(liczbaStd5 < 10){
                    tab[4][liczbaStd5] = osoba;
                    liczbaStd5++;
                    liczbaStd++;
                }
                break;
            }
        }
    }


    void usunStd(int rok, int ind){
        switch(rok){
            case 1:{
                if(ind < liczbaStd1 - 1){
                    tab[rok][ind] = tab[rok][liczbaStd1 - 1];
                    liczbaStd1--;
                    liczbaStd--;
                }
            }
            case 2:{
                if(ind < liczbaStd2 - 1){
                    tab[rok][ind] = tab[rok][liczbaStd2 - 1];
                    liczbaStd2--;
                    liczbaStd--;
                }
            }
            case 3:{
                if(ind < liczbaStd3 - 1){
                    tab[rok][ind] = tab[rok][liczbaStd3 - 1];
                    liczbaStd3--;
                    liczbaStd--;
                }
            }
            case 4:{
                if(ind < liczbaStd5 - 1){
                    tab[rok][ind] = tab[rok][liczbaStd5 - 1];
                    liczbaStd5--;
                    liczbaStd--;
                }
            }
            case 5:{
                if(ind < liczbaStd5 - 1){
                    tab[rok][ind] = tab[rok][liczbaStd5 - 1];
                    liczbaStd5--;
                    liczbaStd--;
                }
            }
        }
    }

    void operator<(int rok){
        switch(rok){
            case 1:{
                for (int i = 0; i < liczbaStd1 - 1; i++) {
                    int wzor = i;
                    for (int j = i + 1; j < liczbaStd1; j++) {
                        if (tab[0][wzor].srednia() < tab[0][j].srednia()) {
                            wzor = j;
                        }
                    }
                    swap(tab[0][i], tab[0][wzor]);
                }
                break;

            }
            case 2:{
                for(int i = 0; i < liczbaStd2 - 1; i++){
                    int wzor = i;
                    for(int j = i + 1; j < liczbaStd2; j++){
                        if(tab[1][wzor].srednia() < tab[1][j].srednia()){
                            wzor = j;

                        }
                    }
                    swap(tab[1][i], tab[1][wzor]);
                }
                break;
            }
            case 3:{
                for(int i = 0; i < liczbaStd3 - 1; i++){
                    int wzor = i;
                    for(int j = i + 1; j < liczbaStd3; j++){
                        if(tab[2][wzor].srednia() < tab[2][j].srednia()){
                            wzor = j;
                        }
                    }
                    swap(tab[2][i], tab[2][wzor]);
                }
                break;
            }
            case 4:{
                for(int i = 0; i < liczbaStd4 - 1; i++){
                    int wzor = i;
                    for(int j = i + 1; j < liczbaStd4; j++){
                        if(tab[3][wzor].srednia() < tab[3][j].srednia()){
                            wzor = j;

                        }
                    }
                    swap(tab[3][i], tab[3][wzor]);
                }
                break;
            }
            case 5:{
                for(int i = 0; i < liczbaStd5 - 1; i++){
                    int wzor = i;
                    for(int j = i + 1; j < liczbaStd5; j++){
                        if(tab[4][wzor].srednia() < tab[4][j].srednia()){
                            wzor = j;

                        }

                    }
                    swap(tab[4][i], tab[4][wzor]);
                }
                break;
            }

        }
    }

    void wyswietlTrzy(int rok){
        for(int i = 0; i < 3; i++){
            cout << tab[rok - 1][i].wysInd() << " " << tab[rok - 1][i].wysImie() << " " << tab[rok - 1][i].wysNaz() << " ";
        }
    }


};


int main() {
    string nazwaKierunku, imie, nazwisko, plec, nrIndeksu, nazwaFirmy, stanowisko;
    float waga, wzrost, wynagrodzenie, stazPracy;
    int wiek, rokStudiow, jakiRok;
    double ocena;

    Pracownik tablicaPracownikow[2];

    cin >> nazwaKierunku;
    Kierunek kierunek(nazwaKierunku);

    for(int s = 0; s < 10; s++){
        cin >> imie >> nazwisko >> waga >> wzrost >> wiek >> plec >> nrIndeksu >> rokStudiow;

        if(plec == "M"){
            Student student(imie, nazwisko, waga, wzrost, wiek, plci::M, nrIndeksu, rokStudiow);
            for(int j = 0; j < 5; j++){
                cin >> ocena;
                student.wstawOcen(j, ocena);
            }
            kierunek.dodajStd(rokStudiow, student);
        }else if(plec == "K"){
            Student student(imie, nazwisko, waga, wzrost, wiek, plci::M, nrIndeksu, rokStudiow);
            for(int j = 0; j < 5; j++){
                cin >> ocena;
                student.wstawOcen(j, ocena);
            }
            kierunek.dodajStd(rokStudiow, student);
        }

    }

    cin >> jakiRok;
    kierunek < jakiRok;
    kierunek.wyswietlTrzy(jakiRok);


    for (int i = 0; i < 2; i++) {
        cin >> imie >> nazwisko >> waga >> wzrost >> wiek >> plec >> nazwaFirmy >> stanowisko >> wynagrodzenie >> stazPracy;
        if (plec == "M") {
            Pracownik pracownik(imie, nazwisko, waga, wzrost, wiek, plci::M, nazwaFirmy, stanowisko, wynagrodzenie, stazPracy);
            tablicaPracownikow[i] = pracownik;
            cout << tablicaPracownikow[i].wiekEmerytura(wiek);
            cout << " ";
        } else if (plec == "K") {
            Pracownik pracownik(imie, nazwisko, waga, wzrost, wiek, plci::K, nazwaFirmy, stanowisko, wynagrodzenie, stazPracy);
            tablicaPracownikow[i] = pracownik;
            cout << tablicaPracownikow[i].wiekEmerytura(wiek);
            cout << " ";
        }
    }


    return 0;
}