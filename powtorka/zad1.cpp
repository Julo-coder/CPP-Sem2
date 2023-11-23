#include <iostream>

using namespace std;

class Product{
    string name;
    double priceN, grams;
    int vat;

public:
    Product(){};
    Product(string n, double pN, double g, int v) : name(n), priceN(pN), grams(g), vat(v){};
    double priceB = priceN + (priceN*(static_cast<double>(vat)/100));
    void showItem(){
        cout << "Nazwa=" << name << endl;
        cout << "Cena[PLN]=" << priceN << endl;
        cout << "Waga[g]=" << grams << endl;
        cout << "Vat[%]=" << vat << endl;
    }

    string getName(){
        return name;
    }

    double getpriceB(){
        return priceB;
    }

    double getGrams(){
        return grams;
    }

    double getPrice(){
        return priceN;
    }

    int getVat(){
        return vat;
    }
};

class Cart{
    static const int size = 10;
    Product arr[size];
    int count{10};

public:
    Cart(){};
    void showCart(){
        for(int i = size - 1; i >= count; i--){

            cout << arr[i].getName() << ", cena brutto=" << arr[i].getpriceB() << "PLN, waga=" << arr[i].getGrams() << "g" << endl;
        }
    }

    void addItem(Product& p){
        arr[count - 1] = p;
        count--;
    }

    double countWeight(){
        double sumWeight{0};
        for(int i = size - 1; i >= count; i--){
            sumWeight += arr[i].getGrams();
        }
        return sumWeight;
    }
};


int main(){
    Cart cart1;
    string nameP;
    double price, weight;
    int vatVal, items;


    cin >> items;
    cout << "N=" << items << endl;
    if(items < 0 or items > 10){
        cout << "Bledne dane wejsciowe.";
        return 0;
    }

    for(int p = 0; p < items; p++){
        cin >> nameP >> price >> weight >> vatVal;
        Product prod1(nameP, price, weight, vatVal);
        prod1.showItem();
        cart1.addItem(prod1);
    }


    cart1.showCart();
    cout << "Waga koszyka[g]=" << cart1.countWeight();

    return 0;
}
