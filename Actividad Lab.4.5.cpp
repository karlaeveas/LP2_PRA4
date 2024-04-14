#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Prenda {
private:
    string nombre;
    string tipo;
public:
    Prenda(string nombre, string tipo) {
      this -> nombre = nombre;
      this -> tipo = tipo;
    }

    string getNombre() const {
        return nombre;
    }

    string getTipo() const {
        return tipo;
    }
};
class TiendaRopa {
private:
    vector<Prenda*> prendas;
public:
    void agregarPrenda(Prenda* prenda) {
        prendas.push_back(prenda);
    }
    void eliminarPrenda(Prenda* prenda) {
        for (auto it = prendas.begin(); it != prendas.end(); ++it) {
            if (*it == prenda) {
                prendas.erase(it);
                break;
            }
        }
    }
    Prenda* obtenerPrenda(string nombre) const {
        for (auto& prenda : prendas) {
            if (prenda->getNombre() == nombre) {
                return prenda;
            }
        }
        return nullptr;
    }
    void mostrarPrendas() const {
        cout << "Prendas en la tienda:" << endl;
        for (const auto& prenda : prendas) {
            cout << "- " << prenda->getNombre() << " (" << prenda->getTipo() << ")" << endl;
        }
    }
};
int main() {
    TiendaRopa tienda;
    Prenda* prenda1 = new Prenda("Camisa", "Camiseta");
    Prenda* prenda2 = new Prenda("Pantalón", "Pantalón");
    Prenda* prenda3 = new Prenda("Abrigo", "Chaquetas");
    tienda.agregarPrenda(prenda1);
    tienda.agregarPrenda(prenda2);
    tienda.agregarPrenda(prenda3);
    tienda.mostrarPrendas();
    tienda.eliminarPrenda(prenda2);
    tienda.mostrarPrendas();
    return 0;
}