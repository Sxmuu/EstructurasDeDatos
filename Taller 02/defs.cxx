#include "defs.h"

using namespace std;

void agregarCancion(){
    cout << "Numero de canciones a agregar: ";
    cin >> numCanciones;
    for(int i = 0; i < numCanciones; i++){
        cout <<endl<< "Canción " << i + 1 << endl<<endl;
        canciones cancion;
        cout << "Nombre: ";
        cin.ignore();
        getline(cin, cancion.nombre);
        cout << "Artista: ";
        fflush(stdin);
        getline(cin, cancion.artista);
        cout << "Género: ";
        cin.ignore();
        getline(cin, cancion.genero);
        cout << "Álbum: ";
        getline(cin, cancion.album);
        cout << "Año: ";
        cin >> cancion.anno;
        if(cancion.anno < 0 || cancion.anno > 2023){
            cerr << "Error, el año digitado no es válido" << endl;
            exit(1);
        }
        cancionesList.push_back(cancion); // Agregar la canción a la lista
    }
}

void mostrarAutores(){
    set<string> autores; // conjunto para almacenar autores únicos
    for(const auto& cancion : cancionesList){
        autores.insert(cancion.artista); // agregar autor al conjunto
    }
    cout<<endl<<endl<<"Lista de autores: "<<endl<<endl;
    for(const auto& autor : autores){ // imprimir autores únicos en orden alfabético
        cout << autor << endl;
    }
}

void mostrarCancionesPorAutor() {
    string autor;
    cout << "Ingrese el nombre del autor: ";
    cin.ignore();
    getline(cin, autor);

    set<string> cancionesAutor; // conjunto para almacenar canciones del autor

    for (auto& cancion : cancionesList) {
        if (cancion.artista == autor) {
            cancionesAutor.insert(cancion.nombre); // agregar canción al conjunto
        }
    }

    if (cancionesAutor.empty()) {
        cerr << "Error, no se encontraron canciones del autor " << autor << endl;
    } else {
        cout << "Canciones de " << autor << ":" << endl;
        for (const auto& cancion : cancionesAutor) {
            cout << "- " << cancion << endl;
        }
    }
}

void mostrarAlbumes() {
    // Paso 1: crear un conjunto para almacenar álbumes únicos
    set<string> albumes;

    // Paso 2: agregar álbumes únicos al conjunto
    for (const auto& cancion : cancionesList) {
        albumes.insert(cancion.album);
    }

    // Paso 3: ordenar el conjunto de álbumes cronológicamente
    auto cmp = [](const string& a, const string& b) {
        // Buscar los años de lanzamiento de los álbumes a través de la lista de canciones
        int annoA = -1, annoB = -1;
        for (const auto& cancion : cancionesList) {
            if (cancion.album == a) {
                annoA = cancion.anno;
            } else if (cancion.album == b) {
                annoB = cancion.anno;
            }
        }
        return annoA > annoB;
    };
    set<string, decltype(cmp)> albumesOrdenados(cmp);
    albumesOrdenados.insert(albumes.begin(), albumes.end());

    // Paso 4: imprimir el nombre de cada álbum con su autor y año de lanzamiento
    for (const auto& album : albumesOrdenados) {
    // Buscar el autor y el año de lanzamiento de este álbum a través de la lista de canciones
    string autor;
    int anno = -1;
    for (const auto& cancion : cancionesList) {
        if (cancion.album == album) {
            autor = cancion.artista;
            anno = cancion.anno;
            break;
        }
    }
    cout << autor << " - " << album << " (" << anno << ")" << endl;
    }
}

void mostrarCancionesPorAlbum() {
    string album;
    cout << "Ingrese el nombre del album: ";
    cin.ignore();
    getline(cin, album);

    set<string> cancionesAlbum; // conjunto para almacenar canciones del álbum

    for (auto& cancion : cancionesList) {
        if (cancion.album == album) {
            cancionesAlbum.insert(cancion.nombre); // agregar canción al conjunto
        }
    }

    if (cancionesAlbum.empty()) {
        cerr << "Error, no se encontraron canciones del álbum " << album << endl;
    } else {
        cout << "Canciones del álbum " << album << ":" << endl;
        for (const auto& cancion : cancionesAlbum) {
            cout << "- " << cancion << endl;
        }
    }
}


void mostrarCanciones() {
    set<string> albumes;

    // Paso 2: agregar álbumes únicos al conjunto
    for (const auto& cancion : cancionesList) {
        albumes.insert(cancion.album);
    }

    for (const auto& album : albumes) {
        string autor;
        set<string> cancionesAlbum; // conjunto para almacenar canciones del álbum como cadenas
        for (const auto& cancion : cancionesList) {
            if (cancion.album == album) {
                autor = cancion.artista;
                cancionesAlbum.insert(cancion.nombre); // agregar canción al conjunto
            }
        }
        cout << endl << "Álbum: " << album << " - Autor: " << autor << endl;
        for (const auto& cancion : cancionesAlbum) {
            cout << "- " << cancion << endl;
        }
    }
}


void eliminarCancion() {
    string cancion;
    cout << "Ingrese el nombre de la canción a eliminar: ";
    cin.ignore();
    getline(cin, cancion);
    bool existe = false; // Declarar la variable una vez y asignarle false
    for (auto it = cancionesList.begin(); it != cancionesList.end(); it++) {
        if (it->nombre == cancion) {
            cancionesList.erase(it);
            cout << "Canción eliminada" << endl;
            existe = true; // Cambiar el valor de la variable original
            break; // Agregar break para salir del bucle al encontrar la canción
        }
    }
    if (!existe){
        cerr << "Error, no se encontró la canción " << cancion << endl;
    }
}


void cargarCanciones() {
    ifstream archivo("datos.txt");
    if (!archivo.is_open()) {
        cerr << "Error, no se pudo abrir el archivo" << endl;
        exit(1);
    }

    string linea;
    bool primeraLinea = true;
    while (getline(archivo, linea)) {
        if (primeraLinea) { // saltar primera línea
            primeraLinea = false;
            continue;
        }
        canciones cancion;
        char* token = strtok(const_cast<char*>(linea.c_str()), "|");
        int i = 0;
        while (token != NULL) {
            switch (i) {
                case 0:
                    cancion.nombre = token;
                    break;
                case 1:
                    cancion.artista = token;
                    break;
                case 2:
                    cancion.genero = token;
                    break;
                case 3:
                    cancion.album = token;
                    break;
                case 4:
                    cancion.anno = stoi(token);
                    if (cancion.anno < 0 || cancion.anno > 2023) {
                        cerr << "Error, el año digitado no es válido" << endl;
                        exit(1);
                    }
                    break;
                default:
                    break;
            }
            i++;
            token = strtok(NULL, "|");
        }
        cancionesList.push_back(cancion); // Agregar la canción a la lista
    }
    cout<<endl<<endl<<"Canciones cargadas exitosamente"<<endl;
    archivo.close();
}

void guardarCanciones(){
    ofstream archivo("datos.txt", ios::out); // Abrir el archivo en modo escritura
    if (!archivo.is_open()) {
        cerr << "Error, no se pudo abrir el archivo" << endl;
        exit(1);
    }
    archivo << cancionesList.size() << endl; // Guardar la cantidad de canciones en la primera línea del archivo
    archivo.close(); // Cerrar el archivo
    ofstream archivo2("datos.txt", ios::app); // Abrir el archivo en modo adición
    if (!archivo2.is_open()) {
        cerr << "Error, no se pudo abrir el archivo" << endl;
        exit(1);
    }
    for(auto const& cancion : cancionesList){ // Recorrer la lista de canciones
        archivo2 << cancion.nombre << '|' << cancion.artista << '|' << cancion.genero << '|' << cancion.album << '|' << cancion.anno << endl; // Escribir la información de la canción en el archivo separada por comas
    }
    archivo2.close();
    cout <<endl<<endl<< "Canciones guardadas en el archivo 'datos.txt'" << endl;
}
