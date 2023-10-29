#include <iostream>
using namespace std;

/*
Klasa przedstawiająca samochód powinna zawierać:

Cztery atrybuty opisujące samochód: numer rejestracyjny, moc silnika w KM, waga w tonach oraz rodzaj silnika (B jako benzynowy, D jako Diesel, E jako elektryczny, H jako hybryda).
Konstruktor inicjalizujący powyższe atrybuty w kolejności podanej powyżej.
Numer rejestracyjny jest ciągiem 4 znaków (liter lub cyfr) bez spacji. Moc jest liczbą całkowitą, a waga jest liczbą zmiennoprzecinkową.
Wszystkie atrybuty powinny być zadeklarowane jako zmienne prywatne, a jakikolwiek dostęp spoza klasy powinien się odbywać poprzez odpowiednie funkcje dostępowe.
*/

enum types {B, D, E, H};

class Cars {
    string Number;
    int Power;
    double Weigth;
    types Type;

    public:
    Cars(){};
    Cars(string n, int p, double w, types t){
        Number = n;
        Power = p;
        Weigth = w;
        Type = t;
    }

    string getNumber(){
        return Number;
    }

    int getPower(){
        return Power;
    }

    double getWeigth(){
        return Weigth;
    }

    types getType(){
        return Type;
    }
};

/*
Klasa przedstawiająca katalog samochodów powinna zawierać:

Tablicę o rozmiarze 6 przechowującą samochody w kolejności ich dodania.
Funkcję wyświetlającą numery rejestracyjne i moce silników wszystkich samochodów z katalogu (oddzielone spacjami) zgodnie i z ich miejscem w tablicy.
Funkcję dodającą do katalogu samochód podany jako argument funkcji.
Funkcję usuwającą z katalogu samochód podany jako argument funkcji. W przypadku, gdy usunięty element nie jest ostatnim w tablicy, w puste miejsce wstawiany jest ostatni element z tablicy.
*/

class Catalog {
    Cars car[6];
    int count{0};

    public:
    Catalog(){};
    void show(){
        for(int i = 0; i < count; i++){
            cout << car[i].getNumber() << " " << car[i].getPower() << " "; 
        }
    }

    void add(Cars &c){
        car[count] = c;
        count++;
    }

    void del(int d){
       if(d == 6){
            count--;
        }else{
            count--;
            car[d] = car[count];
        }
        
    }
};

int main(){
    Catalog cat;
    string number, kind;
    int power, rem;
    double weigth;
    
    for(int i = 0; i < 6; i++){
        bool isNotGood = true;
        while(isNotGood){
            cin >> number;
            if(number.length() > 4){
                
            }else{
                bool valid = true;
                for(int i = 0; i < number.length(); i++){
                    int ascii_letter = (int)number[i];
                    if(!((ascii_letter >= 48 and ascii_letter <= 57) or (ascii_letter >= 65 and ascii_letter <= 90) or (ascii_letter >= 97 and ascii_letter <= 122))){
                        valid = false;
                        break;
                    }
                }
                if(valid){
                    isNotGood = false;
                }
            }
        }
        cin >> power >> weigth >> kind;
        if(kind == "B"){
            Cars car(number, power, weigth, types::B);
            cat.add(car);
        }
        if(kind == "D"){
            Cars car(number, power, weigth, types::D);
            cat.add(car);
        }
        if(kind == "E"){
            Cars car(number, power, weigth, types::E);
            cat.add(car);
        }
        if(kind == "H"){
            Cars car(number, power, weigth, types::H);
            cat.add(car);
        }
        
    }
    cin >> rem;
    cat.del(rem);
    cat.show();

    return 0;
}