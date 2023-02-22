#ifndef DEFS_H
#define DEFS_H
#include <iostream>
#include <string>
#include <locale.h>
#include <list>
#include <set>
#include <fstream>
#include <cstring>

using namespace std;

struct canciones{
    string nombre;
    string artista;
    string genero;
    string album;
    short int anno;
};

typedef struct canciones canciones;

list<canciones> cancionesList;
int numCanciones;

void agregarCancion();
void mostrarCanciones();
void mostrarAlbumes();
void mostrarCancionesPorAutor();
void mostrarCancionesPorAlbum();
void eliminarCancion();
void cargarCanciones();
void guardarCanciones();
#endif