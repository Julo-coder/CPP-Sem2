#include <iostream>
using namespace std;

int main(){
    string number;
    bool isNotGood = true;
    while(isNotGood){
        cin >> number;
        if(number.length() > 4){
            cout << "Try again" << endl;
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
                cout << "This word is good " << number ;
                isNotGood = false;
            }else{
                cout << "Try again" << endl;
            }
        }
    }
}
