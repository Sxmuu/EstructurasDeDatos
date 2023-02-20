#include <iostream>  // Inclusión de la biblioteca iostream para entrada y salida estándar
#include <string>    // Inclusión de la biblioteca string para el uso de cadenas
#include <fstream>   // Inclusión de la biblioteca fstream para el uso de archivos

// Definición de una estructura para la captura de datos del cliente
struct persona {
    std::string nombre;     // Nombre del usuario
    char documento[10];     // Documento del usuario
    char telefono[10];      // Teléfono del usuario
    std::string departamento;  // Departamento del usuario
    std::string ciudad;         // Ciudad del usuario
    std::string direccion;      // Dirección del usuario
    std::string correo;         // Correo del usuario
};

typedef struct persona personas;  // Definición de tipo de dato persona

int numUsuarios;  // Variable global para el número de usuarios
personas *puntero;  // Creación de un puntero

// Declaración de funciones
void agregarUsuario();
void mostrarUsuarios();
void eliminarUsuario();
void guardarUsuarios();

int main(){
    int opcion;  // Variable para guardar la opción elegida por el usuario
    do {
        // Mostrar las opciones disponibles al usuario
        std::cout << "1. Agregar usuario" << std::endl;
        std::cout << "2. Mostrar usuarios" << std::endl;
        std::cout << "3. Eliminar usuario" << std::endl;
        std::cout << "4. Guardar usuarios" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;  // Leer la opción elegida por el usuario
        switch (opcion) {
            case 1:
                agregarUsuario();  // Llamar a la función agregarUsuario
                break;
            case 2:
                mostrarUsuarios();  // Llamar a la función mostrarUsuarios
                break;
            case 3:
                eliminarUsuario();  // Llamar a la función eliminarUsuario
                break;
            case 4:
                guardarUsuarios();  // Llamar a la función guardarUsuarios
                break;
            case 5:
                exit(0);  // Salir del programa
                break;
            default:
                std::cout << "Opcion invalida" << std::endl;
                break;
        }
    } while (opcion != 6);  // Repetir hasta que el usuario elija salir
    return 0;
}

// Función para agregar usuarios
void agregarUsuario() {
    std::cout << "Ingrese el numero de usuarios a agregar: ";
    std::cin >> numUsuarios;  // Leer el número de usuarios a agregar
    puntero = new personas[numUsuarios];  // Asignar el puntero al arreglo
    for (int i = 0; i < numUsuarios; i++) {
        std::cout << "Ingrese el nombre del usuario " << i+1 << ": ";
        std::cin.ignore();  // Ignorar el salto de línea anterior
        std::getline(std::cin, puntero[i].nombre);  // Leer el nombre del usuario
        std::cout << "Ingrese el documento del usuario " << i+1 << ": ";
        std::cin >> puntero[i].documento;  // Leer el documento del usuario
        std::cout << "Ingrese el telefono del usuario " <<
