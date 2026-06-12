#include <iostream>
#include <string>

using namespace std;

class persona{
    private:
        string nombre;
        int edad;
    public:
        static int numeropersonas;
        persona(string nombre, int edad);
        persona &gaga(){
            cout << edad << endl;
            return *this;
        }
        persona &hola(){
            cout << nombre << endl;
            return *this;
        }
        persona &cnombre(string nombre){
            this->nombre = nombre;
            return *this;
        }
        persona &cedad(int edad){
            this->edad = edad;
            return *this;
        }
        ~persona(){
            cout << "Destructor" << endl;
        }
};

int persona::numeropersonas = 0;
persona::persona(string nombre, int edad){
    this->edad = edad;
    this->nombre = nombre;
    numeropersonas++;
}

int main(){
    persona *p1 = new persona("El pepe", 13);
    p1 -> hola().gaga();
    p1->cnombre("Ete sech").cedad(67);
    p1 -> hola();
    p1 -> gaga();
    persona *p2 = new persona("Potaxio", 54);
    p2 -> hola().gaga();
    cout << "Número de personas:" << persona::numeropersonas <<endl;
    delete p1;
    delete p2;
}