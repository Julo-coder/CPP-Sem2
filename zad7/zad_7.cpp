#include <iostream>
#include <iomanip>

using namespace std;

class Okrag{
    string nazwa;
    float promien;
public:
    Okrag(){};
    Okrag(string n, float p) : nazwa(n), promien(p){}

    float obliczObwod(){
        return 2*3.14*promien;
    }

    void podajDane(){
        cin >> nazwa >> promien;
    }


    void wyswietlKolo(){
        cout << fixed << setprecision(2);
        cout << nazwa << " " << obliczObwod();
        cout << " ";
    }

};

class Ksztalt{
public:
    virtual float obw() = 0;
    virtual float pole() = 0;
    virtual void pokazKsztalt() = 0;
    virtual void wprowadzDane() = 0;
};

class Kolo : public Ksztalt{
    string  nazwa;
    float promien;
public:
    Kolo(){}
    float obw(){
        return 2*3.14*promien;
    }

    float pole(){
        return 3.14*promien*promien;
    }

    void pokazKsztalt(){
        cout << fixed << setprecision(2);
        cout << nazwa << " " << static_cast<int>(promien) << " " << pole() <<  " " << obw();
        cout << " ";
    }

    void wprowadzDane(){
        cin >> nazwa >> promien;
    }

};

class Prostokat : public Ksztalt{
    string nazwa;
    float bok_a, bok_b;
public:
    Prostokat(){}

    float obw(){
        return (2*bok_a) + (2*bok_b);
    }

    float pole(){
        return bok_b*bok_a;
    }

    void wprowadzDane(){
        cin >> nazwa >> bok_a >> bok_b;
    }

    void pokazKsztalt(){
        cout << fixed << setprecision(2);
        cout << nazwa << " " << static_cast<int>(bok_a) << " " << static_cast<int>(bok_b) << " " << pole() << " " << obw();
        cout << " ";
    }
};


int main()
{
    short int task;
    cin >> task;

    switch(task)
    {
        case(1):
        {
            int rozmiar{0};
            cin >> rozmiar;

            Okrag *kolo = new Okrag[rozmiar];

            for(int i = 0; i < rozmiar; i++){
                kolo[i].podajDane();
            }

            for(int j = 0; j < rozmiar -1; j++){
                int chwilowa = j;
                for(int z = j + 1; z < rozmiar; z++){
                    if(kolo[chwilowa].obliczObwod() < kolo[z].obliczObwod()){
                        chwilowa = z;
                    }
                }
                swap(kolo[j], kolo[chwilowa]);
            }

            for(int w = 0; w < rozmiar; w++){
                kolo[w].wyswietlKolo();
            }
            delete[] kolo;
            break;
        }
        case(2):
        {
            int wiersze, kolumny;
            cin >> wiersze >> kolumny;
            Ksztalt ***ksztalty = new Ksztalt **[wiersze];

            for(int w = 0; w < wiersze; w++){
                ksztalty[w] = new Ksztalt *[kolumny];
                for(int k = 0; k < kolumny; k++){
                    if (w % 2 == 0) {
                        ksztalty[w][k] = new Kolo();
                        ksztalty[w][k]->wprowadzDane();
                    }else{
                        ksztalty[w][k] = new Prostokat();
                        ksztalty[w][k]->wprowadzDane();
                    }

                }
            }

            int uzytWiersz, uzytKol;
            cin >> uzytWiersz >> uzytKol;

            ksztalty[uzytWiersz][uzytKol]->pokazKsztalt();
            for(int w = 0; w < wiersze; w++){
                for(int k = 0; k < kolumny; k++){
                    delete ksztalty[w][k];
                }
                delete ksztalty[w];
            }
            delete[] ksztalty;
            break;
        }
    }

    return 1;
}