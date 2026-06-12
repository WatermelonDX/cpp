#include <iostream>

using namespace std;

int main(){
    int edad;
    cout << "How old are you" << endl;
    cin >> edad; 
    if(edad >= 18){
        cout << "Puedes votar" << endl;
    }else{
        if(edad == 14){
            cout << "Activa cam" << endl;
        }else{
            if(edad == 4){
                cout << "You are the youngest person EVER" << endl; 
            }else{
                cout << "No puedes votar" << endl;
            }
        }
    }
}