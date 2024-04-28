#include <iostream>
#include <fstream> // Para trabajar con archivos binarios

using namespace std;

// Definición de la estructura para almacenar datos de los estudiantes
struct Estudiante {
    int id;
    string nombres;
    string apellidos;
    double notas[4]; // Arreglo para las 4 notas
    double promedio;
    string resultado;
};

// Función para calcular el promedio
double calcularPromedio(const Estudiante& estudiante) {
    double sumaNotas = 0;
    for (int i = 0; i < 4; ++i) {
        sumaNotas += estudiante.notas[i];
    }
    return sumaNotas / 4;
}

// Función para determinar si el estudiante aprobó o reprobó
string obtenerResultado(double promedio) {
    return (promedio > 60) ? "Aprobado" : "Reprobado";
}

// Función para ingresar datos de un estudiante
void ingresarEstudiante(Estudiante& estudiante) {
    cout << "Ingrese el ID del estudiante: ";
    cin >> estudiante.id;
    cout << "Ingrese los nombres del estudiante: ";
    cin.ignore(); // Limpiar el buffer
    getline(cin, estudiante.nombres);
    cout << "Ingrese los apellidos del estudiante: ";
    getline(cin, estudiante.apellidos);
    cout << "Ingrese las 4 notas del estudiante:\n";
    for (int i = 0; i < 4; ++i) {
        cout << "Nota " << i + 1 << ": ";
        cin >> estudiante.notas[i];
    }
    estudiante.promedio = calcularPromedio(estudiante);
    estudiante.resultado = obtenerResultado(estudiante.promedio);
}

// Función para guardar los datos en un archivo binario
void guardarEnArchivo(const Estudiante& estudiante) {
    ofstream archivo("notas.dat", ios::binary | ios::app);
    if (archivo.is_open()) {
        archivo.write(reinterpret_cast<const char*>(&estudiante), sizeof(Estudiante));
        archivo.close();
        cout << "Datos guardados correctamente en notas.dat\n";
    } else {
        cout << "Error al abrir el archivo para escritura\n";
    }
}

int main() {
    int n;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        Estudiante estudiante;
        ingresarEstudiante(estudiante);
        guardarEnArchivo(estudiante);
    }

    // Aquí puedes implementar las funciones para leer, actualizar y eliminar datos (CRUD)

    return 0;
}

