#include <iostream>
#include <vector>
using namespace std;
class Hijo {
private:
    string nombre;

public:
    Hijo(string nombre) {
        this -> nombre = nombre;
    }
    string getNombre() {
        return nombre;
    }
    void setNombre(string nombre) {
        this->nombre = nombre;
    }
};
class Padre {
private:
    string nombre;
    vector<Hijo> hijos;
    int numHijos;
public:
    Padre(string nombre) {
        this -> nombre = nombre;
        this -> numHijos = 0;
    }
    string getNombre() {
        return nombre;
    }
    void setNombre(string nombre) {
        this->nombre = nombre;
    }
    void agregarHijo(Hijo hijo) {
        hijos.push_back(hijo);
        numHijos++;
    }
    void imprimirInfo() {
        cout << "Nombre del padre: " << nombre << endl;
        cout << "Cantidad de hijos: " << numHijos << endl;
    }
};
int main() {
    Padre padre("Juan");
    Hijo hijo1("Pedro");
    Hijo hijo2("Maria");
    padre.agregarHijo(hijo1);
    padre.agregarHijo(hijo2);
    padre.imprimirInfo();
    return 0;
}