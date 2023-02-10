#ifndef STRUCT_HEADER
#define STRUCT_HEADER
#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <fstream>

using namespace std;

struct hijo //TDA para la captura de datos de los hijos del usuario
{
    string nombre; //Nombre del hijo
    int edad; //Edad del hijo
    char documento[10]; //Documento del hijo
    char telefono[10]; //Telefono del hijo
    string correo; //Correo del hijo
    string genero; //Genero del hijo
    int peso; //Peso del hijo
    int altura; //Altura del hijo
    float alturaM = (altura/100); //Altura en metros del hijo
    float IMC = peso/(pow(alturaM,2)); //Indice de masa corporal del hijo
    // (Cabe aclarar que el hijo del usuario no tiene direcci�n propia teniendo en cuenta que es la misma que la del usuario)
};

typedef struct hijo hijos; //Definicion de tipo de dato hijo

struct persona //TDA para la captura de datos de los usuarios
{
    string nombre; //Nombre del usuario
    int edad; //Edad del usuario
    char documento[10]; //Documento del usuario
    char telefono[10]; //Telefono del usuario
    string correo; //Correo del usuario
    string genero; //Genero del usuario
    int peso; //Peso del usuario
    int altura; //Altura del usuario
    float alturaM = (altura/100); //Altura en metros del usuario
    float IMC = peso/(pow(alturaM,2)); //Indice de masa corporal del usuario
    string direccion; //Direccion del usuario 
    int numHijos; //Numero de hijos del usuario
    hijos *hijo; //Vector de hijos del usuario
};

typedef struct persona personas; //Definicion de tipo de dato persona

int numUsuarios; //Variable global para la cantidad de usuarios
personas *persona; //Vector de usuarios

void agregarUsuario(); //Funcion para agregar usuarios
void agregarHijos(); //Funcion para agregar hijos a un usuario existente
void mostrarUsuarios(); //Funcion para mostrar los usuarios registrados
void buscarUsuario(); //Funcion para buscar un usuario en especifico
void eliminarUsuario(); //Funcion para eliminar un usuario en especifico
void guardarUsuarios(); //Funcion para guardar los datos de los usuarios en un archivo de texto
void cargarUsuarios(); //Funcion para cargar los datos de los usuarios desde un archivo de texto

#endif