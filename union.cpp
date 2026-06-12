#include <iostream>
#include <string>

using namespace std;

int main(){
    union alfanumerico {
        int numero;
        char letra;
    };

    alfanumerico x = {'w'};

    cout << "Como letra: " << x.letra << endl;
    cout << "Como número: " << x.numero << endl;

    typedef enum dias_semana{lunes = 'l', martes = 'm', miercoles = 'r'} wawa;

    wawa dia = martes;

    cout << (char) dia << endl;
}