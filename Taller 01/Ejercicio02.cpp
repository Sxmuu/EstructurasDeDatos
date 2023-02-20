#include <iostream>
#include <string>
#include <fstream>

struct persona //TDA para la captura de datos del cliente
{
    std::string nombre; //Nombre del usuario
    char documento[10]; //Documento del usuario
    char telefono[10]; //Telefono del usuario
    std::string departamento; //Departamento del usuario
    std::string ciudad; //Direccion del usuario
    std::string direccion; //Direccion del usuario
    std::string correo; //Correo del usuario
};

typedef struct persona personas; //Definicion de tipo de dato persona

int numUsuarios; //Variable global para el numero de usuarios
personas *puntero; //Creación de un puntero

void agregarUsuario();
void mostrarUsuarios();
void eliminarUsuario();
void guardarUsuarios();

int main(){
    int opcion;
    do{
        std::cout << "1. Agregar usuario" << std::endl;
        std::cout << "2. Mostrar usuarios" << std::endl;
        std::cout << "3. Eliminar usuario" << std::endl;
        std::cout << "4. Guardar usuarios" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;
        switch (opcion)
        {
        case 1:
            agregarUsuario();
            break;
        case 2:
            mostrarUsuarios();
            break;
        case 3:
            eliminarUsuario();
            break;
        case 4:
            guardarUsuarios();
            break;
        case 5:
            exit(0);
            break;
        default:
            std::cout << "Opcion invalida" << std::endl;
            break;
        }
    }while(opcion != 6);
    return 0;
}

void agregarUsuario(){
    std::cout << "Ingrese el numero de usuarios a agregar: ";
    std::cin >> numUsuarios;
    puntero = new personas[numUsuarios]; //Asignación del puntero al arreglo
    for (int i = 0; i < numUsuarios; i++) {
        std::cout << "Ingrese el nombre del usuario " << i+1 << ": ";
        std::cin.ignore();
        std::getline(std::cin, puntero[i].nombre);
        std::cout << "Ingrese el documento del usuario " << i+1 << ": ";
        std::cin >> puntero[i].documento;
        std::cout << "Ingrese el telefono del usuario " << i+1 << ": ";
        std::cin >> puntero[i].telefono;
        std::cout << "Ingrese el departamento del usuario " << i+1 << ": ";
        std::cin.ignore();
        std::getline(std::cin, puntero[i].departamento);
        std::cout << "Ingrese la ciudad del usuario " << i+1 << ": ";
        std::cin.ignore();
        std::getline(std::cin, puntero[i].ciudad);
        std::cout << "Ingrese la direccion del usuario " << i+1 << ": ";
        std::cin.ignore();
        std::getline(std::cin, puntero[i].direccion);
        std::cout << "Ingrese el correo del usuario " << i+1 << ": ";
        std::cin.ignore();
        std::getline(std::cin, puntero[i].correo);
    }
}

void mostrarUsuarios(){
    for (int i = 0; i < numUsuarios; i++) {
        std::cout << "Nombre: " << puntero[i].nombre << std::endl;
        std::cout << "Documento: " << puntero[i].documento << std::endl;
        std::cout << "Telefono: " << puntero[i].telefono << std::endl;
        std::cout << "Departamento: " << puntero[i].departamento << std::endl;
        std::cout << "Ciudad: " << puntero[i].ciudad << std::endl;
        std::cout << "Direccion: " << puntero[i].direccion << std::endl;
        std::cout << "Correo: " << puntero[i].correo << std::endl;
    }
}

void eliminarUsuario(){
    int posicion;
    int option;
    std::cout<<std::endl<<"¿Desea eliminar un usuario por nombre o por documento? (1=Nombre 2=Documento): ";
    std::cin>>option;
    switch (option)
    {
    case 1:
        std::cout<<std::endl<<"Ingrese el nombre del usuario a eliminar: ";
        std::cin.ignore();
        std::getline(std::cin, puntero->nombre);
        for (int i = 0; i < numUsuarios; i++) {
            if (puntero->nombre == puntero[i].nombre) {
                puntero[i] = puntero[i+1];
            }
        }
        numUsuarios--;
        break;
    case 2:
        std::cout<<std::endl<<"Ingrese el documento del usuario a eliminar: ";
        std::cin, puntero->documento;
        for (int i = 0; i < numUsuarios; i++) {
            if (puntero->documento == puntero[i].documento) {
                puntero[i] = puntero[i+1];
            }
        }
        numUsuarios--;
        break;
    default:
        std::cout << "Opcion invalida" << std::endl;
        break;
    }
}

void guardarUsuarios(){
    std::ofstream archivo;
    archivo.open("usuarios.txt", std::ios::out);
    if (archivo.fail()) {
        std::cout << "No se pudo abrir el archivo" << std::endl;
        exit(1);
    }
    for (int i = 0; i < numUsuarios; i++) {
        archivo << "Nombre: " << puntero[i].nombre << std::endl;
        archivo << "Documento: " << puntero[i].documento << std::endl;
        archivo << "Telefono: " << puntero[i].telefono << std::endl;
        archivo << "Departamento: " << puntero[i].departamento << std::endl;
        archivo << "Ciudad: " << puntero[i].ciudad << std::endl;
        archivo << "Direccion: " << puntero[i].direccion << std::endl;
        archivo << "Correo: " << puntero[i].correo << std::endl;
    }
    archivo.close();
}


