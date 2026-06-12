#include <iostream>
#include <string>

using namespace std;

class animal{
    protected:
        string alimento;
        static int animalcount; 
        string getfood(){
            return alimento;
        }
    public:
        static int getcount();
        animal();
        ~animal();
        void comer(){
            cout << "Este animal está comiendo "<< getfood() << endl;
        }
};
int animal::animalcount = 0;
animal::animal(){
    cout << "Creando nuevo" << endl;
    animalcount++;
}
animal::~animal(){
    cout << ":'v" << endl;
    animalcount--;
}

int animal::getcount(){
    return animalcount;
};

class carnivoro:public animal{
    public:
        carnivoro():animal(){
        this->alimento = "carne";
        }
        void tragar(){
            cout << "Y se la come" << endl;
        }
};
class herbivoro:public animal{
    public:
        herbivoro():animal(){
        this->alimento = "planta";
        }
        void pastar(){
            cout << "Y se la traga" << endl;
        }
};
class omnivoro:public herbivoro, public carnivoro{
    public:
        omnivoro():herbivoro(), carnivoro(){}
};


int main(){
    carnivoro *a1 = new carnivoro();
    herbivoro *a2 = new herbivoro();
    omnivoro *a3 = new omnivoro();
    a2->comer();
    a1->comer();
    a3->herbivoro::comer();
    a1->tragar();
    a2->pastar();
    a3->carnivoro::comer();
}