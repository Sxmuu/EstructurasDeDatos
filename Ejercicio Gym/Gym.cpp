#include "defs.h"
#include "defs.cxx"
#include <iostream>

using namespace std;

/* 
version beta_0002v
Autor: Samuel Peña
Problema:
    Se tiene un gym en el cual desean automatizar el registro de usuarios.
    Se sugiere que los datos  solicitados sean exhaustivos
    Se requiere saber la cantidad de hijos y los datos de edad de los hijos
    Se requiere que se imprima los nombres de los usuarios registrados
    satisfactoriamente.

Solución:
    *Se pregunta primero la cantidad de usuarios a registrar
    *Se hara un TDA para la captura de datos de los usuarios
    *Se crea un vector de tda general para la captura de datos
    *Se hara un TDA anidado para la captura de datos de los hijos
    *Se anunciara explicitamente cada accion/operacion a realizar.
*/

int main()
{  
    setlocale(LC_ALL, "spanish"); //Para que se muestren los acentos
    int opcion=0; //Variable para el menu
    while(opcion!=4){ //Ciclo para el menu
    cout<<"Bienvenido, por favor seleccione una de las opciones del menú: "<<endl; 
    cout<<"1. Agregar usuario"<<endl;
    cout<<"2. Agregar hijos a un usuario existente"<<endl;
    cout<<"3. Mostrar usuarios"<<endl;
    cout<<"4. Buscar usuario"<<endl;
    cout<<"5. Eliminar usuario"<<endl;
    cout<<"6. Guardar usuarios"<<endl;
    cout<<"7. Cargar usuarios"<<endl;
    cout<<"8. Salir"<<endl;
    cin>>opcion; //Se lee la opcion del menu

    switch (opcion) //Switch para el menu
    {
        case 0:
        break;
        case 1: //Se llama a la funcion para agregar usuarios
        {
            agregarUsuario();
        }
        break;
        case 2: //Se llama a la funcion para agregar hijos a un usuario existente
        {
            agregarHijos();
        }
        break;
        case 3: //Se llama a la funcion para mostrar los usuarios registrados
        {
            mostrarUsuarios();
        }
        break;
        case 4: //Se llama a la funcion para buscar un usuario en especifico
        {
            buscarUsuario();
        }
        break;
        case 5: //Se llama a la funcion para eliminar un usuario en especifico
        {
            eliminarUsuario();
        }
        case 6: //Se llama a la funcion para guardar los datos de los usuarios en un archivo de texto
        {
            guardarUsuarios();
        }
        case 7: //Se llama a la funcion para cargar los datos de los usuarios desde un archivo de texto
        {
            //cargarUsuarios();
        }
        case 8: //Se sale del programa
        exit(0);
        default:
        cout<<"Error, opción no válida"<<endl<<endl;
        exit(1);
        break;
    }
    }
    return 0;
}
