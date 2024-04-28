#include <iostream>

using namespace std;

struct Estudiante {
  int id;
  string nombre;
  string apellidos;
  float nota1;
  float nota2;
  float nota3;
  float nota4;
  float promedio;
  string estado; // "Aprobado" o "Reprobado"
};

int main() {
  // Se define la cantidad de estudiantes
  int nEstudiantes;
  cout << "Ingrese la cantidad de estudiantes: ";
  cin >> nEstudiantes;

  // Se crea un arreglo de estructuras Estudiante
  Estudiante estudiantes[nEstudiantes];

  // Se ingresa la información de cada estudiante
  for (int i = 0; i < nEstudiantes; i++) {
    cout << "\nEstudiante " << i + 1 << ":" << endl;
    cout << "ID: ";
    cin >> estudiantes[i].id;

    cout << "Nombre: ";
    cin.ignore(); // Limpia el buffer de entrada
    getline(cin, estudiantes[i].nombre);

    cout << "Apellidos: ";
    getline(cin, estudiantes[i].apellidos);

    cout << "Nota 1: ";
    cin >> estudiantes[i].nota1;

    cout << "Nota 2: ";
    cin >> estudiantes[i].nota2;

    cout << "Nota 3: ";
    cin >> estudiantes[i].nota3;

    cout << "Nota 4: ";
    cin >> estudiantes[i].nota4;
  }

  // Se calcula el promedio y se determina si aprueba/reprueba cada estudiante
  for (int i = 0; i < nEstudiantes; i++) {
    estudiantes[i].promedio = (estudiantes[i].nota1 + estudiantes[i].nota2 + estudiantes[i].nota3 + estudiantes[i].nota4) / 4;

    if (estudiantes[i].promedio >= 60) {
      estudiantes[i].estado = "Aprobado";
    } else {
      estudiantes[i].estado = "Reprobado";
    }
  }

  // Se muestra la información de cada estudiante con su promedio y estado
  cout << "\nResultados de los estudiantes:\n";
  for (int i = 0; i < nEstudiantes; i++) {
    cout << "\nEstudiante " << i + 1 << ":" << endl;
    cout << "ID: " << estudiantes[i].id << endl;
    cout << "Nombre: " << estudiantes[i].nombre << " " << estudiantes[i].apellidos << endl;
    cout << "Promedio: " << estudiantes[i].promedio << endl;
    cout << "Estado: " << estudiantes[i].estado << endl;
  }

  return 0;
}

