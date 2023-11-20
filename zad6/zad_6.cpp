#include<iostream>
using namespace std;

class Animal{
    string name, id;
    float weight;
    int birthYear;

public:
    Animal(){}
    Animal(string name, float weight, int birthYear, string id) : name(name), weight(weight), birthYear(birthYear), id(id){}

    void showAnimal(){
        cout << name << " " << weight << " " << birthYear << " " << id;
    }

    int getbirthYear(){
        return birthYear;
    }

    float getWeight(){
        return weight;
    }
};

class Build{
    string name;
    float x,y,height;
public:
    Build(){}
    Build(string name, float x, float y, float height) : name(name), x(x), y(y), height(height){}

    void showBuilding(){
        cout << name << " " << x << " " << y << " " << height;
    }

    float addGPS(){
        return x + y;
    }
};


template <class Type> class Main{
    static const int MAX_IND = 10;
    Type arr[MAX_IND];
    int arrInd{0};
    int logicSize;

public:
    Main(int size) : logicSize(size){}
    void addValue(const Type& o){
        arr[arrInd] = o;
        arrInd++;
    }

    void removeValue(int index) {
        if (index >= 0 && index < arrInd) {
            arr[index] = arr[arrInd - 1];
            arrInd--;
        }
    }

    void sortAnimal(){
        for(int a = 0; a < arrInd - 1; a++){
            int instant = a;
            for(int j = a + 1; j < arrInd; j++){
                if(arr[instant].getbirthYear() < arr[j].getbirthYear()){
                    instant = j;
                }else if(arr[instant].getbirthYear() == arr[j].getbirthYear()){
                    if(arr[instant].getWeight() > arr[j].getWeight()){
                        instant = j;
                    }
                }
            }
            swap(arr[a], arr[instant]);
        }
    }

    void sortCord(){
        for(int c = 0; c < arrInd - 1; c++){
            int instant = c;
            for(int j = c + 1; j < arrInd; j++){
                if(arr[instant].addGPS() > arr[j].addGPS()){
                    instant = j;
                }
            }
            swap(arr[c], arr[instant]);
        }
    }


    void displayAnimal() {
        for (int i = 0; i < arrInd; i++) {
            arr[i].showAnimal();
            cout << " ";
        }
    }

    void displayBuildings(){
        for (int i = 0; i < arrInd; i++) {
            arr[i].showBuilding();
            cout << " ";
        }
    }

};

bool detectSpace(const string& s){
    for(char ch : s){
        if(ch == ' '){
            return true;
        }
    }
    return false;
}


int main() {
    Main <Animal> animals(6);
    Main <Build> buildings(6);

    string name, id;
    float height, weight, x_cord, y_cord;
    int year, delete_index;

    for(int a = 0; a < 4; a++){
        do{
            cin >> name;
        }while(detectSpace(name));
        cin >> weight;

        while(weight <= 0){
            cin >> weight;
        }

        cin >> year;

        while(year <= 0){
            cin >> year;
        }
        cin >> id;
        Animal animal(name, weight, year, id);
        animals.addValue(animal);
    }

    for(int b = 0; b < 4; b++){
        do{
            cin >> name;
        }while(detectSpace(name));
        cin >> x_cord >> y_cord;
        cin >> height;
        while(height <= 0){
            cin >> height;
        }
        Build building(name, x_cord, y_cord, height);
        buildings.addValue(building);
    }

    cin >> delete_index;
    animals.removeValue(delete_index);
    animals.sortAnimal();
    buildings.sortCord();

    animals.displayAnimal();
    buildings.displayBuildings();
    return 0;
}