#include <iostream>
#include <vector>
using namespace std;
// Clase Trabajador
class Trabajador {
public:
    string nombre;
    string apellido;
    int edad;
    vector<Trabajador*> companeros;
    Trabajador(string nombre, string apellido, int edad) {
        this -> nombre = nombre;
        this -> apellido = apellido;
        this -> edad = edad;
    }
    void agregarCompanero(Trabajador* companero) {
        companeros.push_back(companero);
    }
    void imprimirCompaneros() {
        for (auto companero : companeros) {
            cout << "Nombre: " << companero->nombre << endl;
            cout << "Apellido: " << companero->apellido << endl;
            cout << "Edad: " << companero->edad << endl;
            cout << endl;
        }
    }
};
// Clase Gerente
class Gerente : public Trabajador {
public:
    static const int TAMANIO_MAXIMO = 10;
    Trabajador* trabajadores[TAMANIO_MAXIMO];
    Gerente(string nombre, string apellido, int edad) : Trabajador(nombre, apellido, edad) {}
    void agregarTrabajador(Trabajador* trabajador) {
        for (int i = 0; i < TAMANIO_MAXIMO; i++) {
            if (trabajadores[i] == nullptr) {
                trabajadores[i] = trabajador;
                break;
            }
        }
    }
    void imprimirTrabajadores() {
        for (int i = 0; i < TAMANIO_MAXIMO; i++) {
            if (trabajadores[i]!= nullptr) {
                cout << "Nombre: " << trabajadores[i]->nombre << endl;
                cout << "Apellido: " << trabajadores[i]->apellido << endl;
                cout << "Edad: " << trabajadores[i]->edad << endl;
                cout << endl;
            }
        }
    }
};
int main() {
    Trabajador trabajador1("Juan", "Pérez", 30);
    Trabajador trabajador2("María", "González", 25);
    Trabajador trabajador3("Pedro", "López", 35);
    Gerente gerente("Carlos", "Rodríguez", 40);
    trabajador1.agregarCompanero(&trabajador2);
    trabajador1.agregarCompanero(&trabajador3);
    trabajador2.agregarCompanero(&trabajador1);
    trabajador2.agregarCompanero(&trabajador3);
    trabajador3.agregarCompanero(&trabajador1);
    trabajador3.agregarCompanero(&trabajador2);
    gerente.agregarTrabajador(&trabajador1);
    gerente.agregarTrabajador(&trabajador2);
    gerente.agregarTrabajador(&trabajador3);
    trabajador1.imprimirCompaneros();
    trabajador2.imprimirCompaneros();
    trabajador3.imprimirCompaneros();
    gerente.imprimirTrabajadores();
    return 0;
}