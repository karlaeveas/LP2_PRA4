#include <iostream>
using namespace std;
class ObjetoCompuesto {
public:
    int identificador;
    ObjetoCompuesto(int identificador) {
        this->identificador = identificador;
    }
};
class Base {
private:
    ObjetoCompuesto* objeto;
public:
    Base(ObjetoCompuesto* objeto) {
        this->objeto = objeto;
    }
    ~Base() {
        delete objeto;
    }
    ObjetoCompuesto& obtenerObjeto() {
        return *objeto;
    }
};
int main() {
    ObjetoCompuesto* objetoCompuesto = new ObjetoCompuesto(1);
    Base base(objetoCompuesto);
    ObjetoCompuesto& objetoAccedido = base.obtenerObjeto();
    objetoAccedido.identificador = 2;
    cout << "Objeto modificado: " << objetoAccedido.identificador << endl;
    delete objetoCompuesto;
    return 0;
}