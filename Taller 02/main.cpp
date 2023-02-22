#include "defs.h"
#include "defs.cxx"

using namespace std;

int main()
{
    setlocale(LC_ALL, "es_ES.utf8");
    int opcion;
    do{
        cout<<endl<<endl;
        cout << "1. Agregar canción" << endl;
        cout << "2. Mostrar álbumes y canciones" << endl;
        cout << "3. Mostrar álbumes en orden cronológico"<<endl;
        cout << "4. Mostrar canciones por autor" << endl;
        cout << "5. Mostrar canciones por album" << endl;
        cout << "6. Eliminar cancion" << endl;
        cout << "7. Cargar canciones" << endl;
        cout << "8. Guardar canciones" << endl;
        cout << "9. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        switch(opcion){
            case 1:
                agregarCancion();
                break;
            case 2:
                mostrarCanciones();
                break;
            case 3:
                mostrarAlbumes();
                break;
            case 4:
                mostrarCancionesPorAutor();
                break;
            case 5:
                mostrarCancionesPorAlbum();
                break;
            case 6: 
                eliminarCancion();
                break;
            case 7:
                cargarCanciones();
                break;
            case 8:
                guardarCanciones();
                break;
            case 9:
                cout << "Saliendo..." << endl;
                exit(0);
                break;
            default:
                cout << "Opción no valida" << endl;
                break;
        }
    }while(opcion != 9);
    return 0;
}
