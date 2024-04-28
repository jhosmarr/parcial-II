#include <iostream>
#include <stdlib.h>

using namespace std;

// Estructura para almacenar datos de un estudiante
struct Estudiante {
  int id;
  char nombre[50];
  char apellidos[50];
  float notas[4];
  float promedio;
};

int main() {
  // Declaración de variables
  int numEstudiantes;
  Estudiante *estudiantes;

  // Solicitud de la cantidad de estudiantes
  cout << "Ingrese la cantidad de estudiantes: ";
  cin >> numEstudiantes;

  // Reserva de memoria para el arreglo de estudiantes
  estudiantes = (Estudiante *) malloc(numEstudiantes * sizeof(Estudiante));
  if (!estudiantes) {
    cout << "Error al reservar memoria para los estudiantes" << endl;
    exit(1);
  }

  // Ingreso de datos de los estudiantes
  for (int i = 0; i < numEstudiantes; i++) {
    cout << "\nEstudiante " << i + 1 << ":" << endl;
    cout << "ID: ";
    cin >> estudiantes[i].id;
    cout << "Nombre: ";
    cin >> estudiantes[i].nombre;
    cout << "Apellidos: ";
    cin >> estudiantes[i].apellidos;

    for (int j = 0; j < 4; j++) {
      cout << "Nota " << j + 1 << ": ";
      cin >> estudiantes[i].notas[j];
    }

    // Cálculo del promedio
    estudiantes[i].promedio = 0;
    for (int j = 0; j < 4; j++) {
      estudiantes[i].promedio += estudiantes[i].notas[j];
    }
    estudiantes[i].promedio /= 4;
  }

  // Mostrar datos de los estudiantes
  cout << "\nDatos de los estudiantes:\n";
  for (int i = 0; i < numEstudiantes; i++) {
    cout << "\nEstudiante " << i + 1 << ":" << endl;
    cout << "ID: " << estudiantes[i].id << endl;
    cout << "Nombre: " << estudiantes[i].nombre << endl;
    cout << "Apellidos: " << estudiantes[i].apellidos << endl;

    for (int j = 0; j < 4; j++) {
      cout << "Nota " << j + 1 << ": " << estudiantes[i].notas[j] << endl;
    }

    cout << "Promedio: " << estudiantes[i].promedio << endl;

    if (estudiantes[i].promedio >= 60) {
      cout << "APROBADO" << endl;
    } else {
      cout << "REPROBADO" << endl;
    }
  }

  // Liberación de memoria
  free(estudiantes);

  return 0;
}

