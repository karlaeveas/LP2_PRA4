#include <iostream>
#include <vector>
using namespace std;
class Estudiante {
public:
    string nombre;
    string apellido;
    int id;
    vector<Curso*> cursos;
    Estudiante(string nombre, string apellido, int id) {
        this->nombre = nombre;
        this->apellido = apellido;
        this->id = id;
    }
    void agregarCurso(Curso* curso) {
        cursos.push_back(curso);
    }
    void eliminarCurso(Curso* curso) {
        for (int i = 0; i < cursos.size(); i++) {
            if (cursos[i] == curso) {
                cursos.erase(cursos.begin() + i);
                break;
            }
        }
    }
};
class Curso {
public:
    string nombre;
    string codigo;
    string descripcion;
    int id;
    vector<Estudiante*> estudiantes;
    Curso(string nombre, string codigo, string descripcion, int id) {
        this->nombre = nombre;
        this->codigo = codigo;
        this->descripcion = descripcion;
        this->id = id;
    }
    void agregarEstudiante(Estudiante* estudiante) {
        estudiantes.push_back(estudiante);
    }
    void eliminarEstudiante(Estudiante* estudiante) {
        for (int i = 0; i < estudiantes.size(); i++) {
            if (estudiantes[i] == estudiante) {
                estudiantes.erase(estudiantes.begin() + i);
                break;
            }
        }
    }
};
int main() {
    Estudiante estudiante1("Juan", "Pérez", 1);
    Estudiante estudiante2("María", "González", 2);
    Estudiante estudiante3("Pedro", "López", 3);
    Curso curso1("Programación", "PROG", "Introducción a la programación", 1);
    Curso curso2("Matemáticas", "MAT", "Álgebra y geometría", 2);
    Curso curso3("Física", "FIS", "Mecánica y termodinámica", 3);
    estudiante1.agregarCurso(&curso1);
    estudiante1.agregarCurso(&curso2);
    estudiante2.agregarCurso(&curso1);
    estudiante2.agregarCurso(&curso3);
    estudiante3.agregarCurso(&curso2);
    estudiante3.agregarCurso(&curso3);
    curso1.agregarEstudiante(&estudiante1);
    curso1.agregarEstudiante(&estudiante2);
    curso2.agregarEstudiante(&estudiante1);
    curso2.agregarEstudiante(&estudiante3);
    curso3.agregarEstudiante(&estudiante2);
    curso3.agregarEstudiante(&estudiante3);
    cout << "Estudiantes del curso 1:" << endl;
    for (int i = 0; i < curso1.estudiantes.size(); i++) {
        cout << curso1.estudiantes[i]->nombre << " " << curso1.estudiantes[i]->apellido << endl;
    }
    cout << "Cursos del estudiante 1:" << endl;
    for (int i = 0; i < estudiante1.cursos.size(); i++) {
        cout << estudiante1.cursos[i]->nombre << " (" << estudiante1.cursos[i]->codigo << ")" << endl;
    }
    estudiante1.eliminarCurso(&curso1);
    curso1.eliminarEstudiante(&estudiante1);
    cout << "Estudiantes del curso 1 después de eliminar al estudiante 1:" << endl;
    for (int i = 0; i < curso1.estudiantes.size(); i++) {
        cout << curso1.estudiantes[i]->nombre << " " << curso1.estudiantes[i]->apellido << endl;
    }
    cout << "Cursos del estudiante 1 después de eliminar el curso 1:" << endl;
    for (int i = 0; i < estudiante1.cursos.size(); i++) {
        cout << estudiante1.cursos[i]->nombre << " (" << estudiante1.cursos[i]->codigo << ")" << endl;
    }
    return 0;
}