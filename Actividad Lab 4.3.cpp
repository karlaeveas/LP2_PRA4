#include <iostream>
using namespace std;
// Clase Estudiante
class Estudiante {
public:
    int id;
    Estudiante(int id) {
        this->id = id;
    }
};
// Clase Docente
class Docente {
public:
    int id;
    Docente(int id) {
        this->id = id;
    }
};
// Clase Curso
class Curso {
public:
    int id;
    Curso(int id) {
        this->id = id;
    }
};
// Clase Asociacion
class Asociacion {
public:
    Estudiante* estudiante;
    Docente* docente;
    Curso* curso;
    Asociacion(Estudiante* estudiante, Docente* docente, Curso* curso) {
        this->estudiante = estudiante;
        this->docente = docente;
        this->curso = curso;
    }
};
int main() {
    Estudiante estudiante1(1);
    Docente docente1(1);
    Curso curso1(1);
    Asociacion asociacion1(&estudiante1, &docente1, &curso1);
    cout << "Estudiante: " << asociacion1.estudiante->id << endl;
    cout << "Docente: " << asociacion1.docente->id << endl;
    cout << "Curso: " << asociacion1.curso->id << endl;
    delete asociacion1.estudiante;
    delete asociacion1.docente;
    delete asociacion1.curso;
    return 0;
}