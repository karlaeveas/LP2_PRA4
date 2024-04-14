#include <iostream>
using namespace std;
// Clase Base
class Base {
public:
    int atributoBase;

    Base(int atributoBase) {
        this -> atributoBase = atributoBase;
    }
    void metodoBase() {
        cout << "Método base" << endl;
    }
};
// Clase Derivada
class Derivada : public Base {
public:
    int atributoDerivada;
    Derivada(int atributoBase, int atributoDerivada) 
    : Base(atributoBase), atributoDerivada(atributoDerivada) {}
    ~Derivada() {
        cout << "Destructor de la clase derivada" << endl;
    }
    void metodoDerivada() {
        cout << "Método derivada" << endl;
    }
};
int main() {
    Derivada objetoDerivada(1, 2);
    objetoDerivada.metodoBase();
    objetoDerivada.metodoDerivada();
    objetoDerivada.atributoBase = 3;
    objetoDerivada.atributoDerivada = 4;
    cout << "Atributo base: " << objetoDerivada.atributoBase << endl;
    cout << "Atributo derivada: " << objetoDerivada.atributoDerivada << endl;

    return 0;
}