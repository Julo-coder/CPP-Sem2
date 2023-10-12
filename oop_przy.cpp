#include<iostream>

using namespace std;

enum sztuki { gram, piece};

class Produkty{
    private:
        double brutto;
    
    
    public:
        Produkty(){}
        string nazwa;
        double netto;
        double waga;
        sztuki jedn;
        
        Produkty(string x, double y, double z, sztuki c, double bru){
        nazwa = x;
        netto = y;
        waga = z;
        jedn = c;
        brutto = bru;
        };
        
};

class Katalog{
    int licznik;
    Produkty tab[10];
    
    public:
    Katalog(){
        licznik = 0;
    }
    
    void wyswietl(){
        for(int i = 0; i < licznik; i++){
            cout << tab[i].nazwa << " ";
        }
    }
    
    void dodaj(Produkty &p){
        tab[licznik] = p;
        licznik++;
    }
};


int main() {
    Katalog kat;
    string nazwa, jednostka;
    double cenaNetto, waga, cenaBrutto;
    
    for(int i = 0; i < 4; i++){
        cin >> nazwa >> cenaNetto >> waga >> jednostka >> cenaBrutto;
        if(jednostka == "gram"){
            Produkty nowy(nazwa, cenaNetto, waga, sztuki::gram, cenaBrutto);
            kat.dodaj(nowy);
        }else{
            Produkty nowy(nazwa, cenaNetto, waga, sztuki::piece, cenaBrutto);
            kat.dodaj(nowy);
        }
    }
    
    kat.wyswietl();
    return 0;
}