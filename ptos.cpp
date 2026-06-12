#include <iostream>

using namespace std;

struct persona{
    string nombre;
    int edad;
};

int main(){
    persona p1 = persona();
    p1.nombre = "El pepe";
    p1.edad = 4;
    cout << p1.nombre << endl;
    cout << p1.edad << endl;
}