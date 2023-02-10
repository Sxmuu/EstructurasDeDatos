#include "defs.h"
#include <iostream>


using namespace std;

void agregarUsuario() //Funcion para agregar usuarios
{
    cout<<"Ingrese el número de usuarios que desea agregar: "<<endl;
    cin>>numUsuarios; //Se lee la cantidad de usuarios a registrar
    persona = new personas[numUsuarios]; //Se crea el vector de usuarios
            for (int i = 0; i < numUsuarios; i++) //Ciclo para la captura de datos de los usuarios
            {
                cout<<endl<<"Usuario "<<i+1<<endl<<endl;
                cout<<"Ingrese el nombre del usuario: "<<endl;
                cin.ignore(); //Se ignora el salto de linea
                getline(cin, persona[i].nombre); //Se lee el nombre del usuario
                cin.clear(); //Se limpia el buffer
                cout<<"Ingrese la edad del usuario: "<<endl;
                cin>>persona[i].edad;
                if(persona[i].edad<15){ 
                    cout<<"Error, los menores de 15 años no pueden ser registrados"<<endl; 
                    //Se valida que la edad del usuario sea mayor a 15 años
                    exit(1);
                }
                if(persona[i].edad > 100){
                    cout<<"Error, los mayores de 100 años no pueden ser registrados"<<endl; 
                    //Se valida que la edad del usuario sea menor a 100 años
                    exit(1);
                }
                cout<<"Ingrese el documento del usuario: "<<endl;
                cin>>persona[i].documento;
                cout<<"Ingrese el teléfono del usuario: "<<endl;
                fflush(stdin);
                cin>>persona[i].telefono;
                fflush(stdin);
                cout<<"Ingrese el correo del usuario: "<<endl;
                getline(cin, persona[i].correo);
                cout<<"Ingrese el género del usuario: "<<endl;
                fflush(stdin);
                cin>>persona[i].genero;
                cout<<"Ingrese el peso del usuario (kg): "<<endl;
                cin.ignore();
                cin>>persona[i].peso;
                cin.clear();
                if(persona[i].peso>200){
                    cout<<"Error, el peso del usuario no puede ser mayor a 200 kg"<<endl; 
                    //Se valida que el peso del usuario sea menor a 200 kg
                    exit(1);
                }
                cout<<"Ingrese la altura del usuario (cm): "<<endl;
                cin.ignore();
                cin>>persona[i].altura;
                cin.clear();
                if(persona[i].altura>250){
                    cout<<"Error, la altura del usuario no puede ser mayor a 200 cm"<<endl; 
                    //Se valida que la altura del usuario sea menor a 250 cm
                    exit(1);
                }
                cout<<"Ingrese la dirección del usuario: "<<endl;
                cin.ignore();
                getline(cin, persona[i].direccion);
                cin.clear();
                int rep;
                cout<<"¿Desea agregar hijos al usuario? (1= Sí, 0=No)"<<endl; 
                //Se pregunta si el usuario desea agregar hijos
                cin>>rep;
                if(rep==0){
                    persona[i].hijo = NULL; //Si el usuario no desea agregar hijos, se asigna NULL al vector de hijos
                }
                
                if (rep==1){ //Si el usuario desea agregar hijos, se procede a registrarlos
                    cout<<"Ingrese el número de hijos del usuario: "<<endl; 
                    cin.ignore();
                    cin>>persona[i].numHijos; //Se lee el número de hijos del usuario
                    cin.clear();
                    persona[i].hijo = new hijos[persona[i].numHijos]; //Se crea el vector de hijos
                for (int j = 0; j < persona[i].numHijos; j++) //Ciclo para la captura de datos de los hijos
                {
                    cout<<endl<<persona[i].nombre<<" | Hijo "<<j+1<<endl<<endl;
                    cin.clear();
                    cout<<"Ingrese el nombre del hijo: "<<endl;
                    cin.ignore();
                    getline(cin, persona[i].hijo[j].nombre);
                    cin.clear();
                    cout<<"Ingrese la edad del hijo: "<<endl;
                    cin>>persona[i].hijo[j].edad;
                    if(persona[i].hijo[j].edad>persona[i].edad){
                        cout<<"Error, el hijo no puede ser mayor que el padre"<<endl; 
                        //Se valida que la edad del hijo sea menor a la del padre
                        exit(1);
                    }
                    if(persona[i].hijo[j].edad<15){
                        cout<<"Error, los menores de 15 años no pueden ser registrados"<<endl; 
                        //Se valida que la edad del hijo sea mayor a 15 años
                        exit(1);
                    }
                    cout<<"Ingrese el documento del hijo: "<<endl;
                    cin>>persona[i].hijo[j].documento;
                    cout<<"Ingrese el teléfono del hijo: "<<endl;
                    fflush(stdin);
                    cin>>persona[i].hijo[j].telefono;
                    fflush(stdin);
                    cout<<"Ingrese el correo del hijo: "<<endl;
                    getline(cin, persona[i].hijo[j].correo);
                    cout<<"Ingrese el género del hijo: "<<endl;
                    fflush(stdin);
                    cin>>persona[i].hijo[j].genero;
                    cout<<"Ingrese el peso del hijo: "<<endl;
                    cin.ignore();
                    cin>>persona[i].hijo[j].peso;
                    cin.clear();
                    cout<<"Ingrese la altura del hijo: "<<endl;
                    cin.ignore();
                    cin>>persona[i].hijo[j].altura;
                    cin.clear();
                }  
                }       
            }
}

void agregarHijos(){ //Función para agregar hijos a un usuario ya registrado
    cout<<"Ingrese el número de documento del usuario al que desea agregar hijos: "<<endl; 
    //Se lee el documento del usuario al que se le van a agregar hijos
    cin>>persona->documento; //Se asigna el documento a la variable documento del TDA persona
    for (int i = 0; i < numUsuarios; i++)
    {
        if(persona[i].documento==persona->documento){ //Se busca el usuario con el documento ingresado
            cout<<"Ingrese el número de hijos a agregar: "<<endl;
            cin>>persona[i].numHijos;
            int HijosActuales;
            if(persona[i].hijo!=NULL){ //Se valida si el usuario ya tiene hijos registrados
                HijosActuales = persona[i].numHijos; 
                //Si el usuario ya tiene hijos registrados, se asigna el número de hijos actuales a la variable HijosActuales
            }
            if(persona[i].hijo==NULL){
                persona[i].hijo = new hijos[persona[i].numHijos]; 
                //Si el usuario no tiene hijos registrados, se crea el vector de hijos
                HijosActuales = 0;
            }
            cout<<HijosActuales;
            for (int j = HijosActuales; j < persona[i].numHijos; j++) //Ciclo para la captura de datos de los hijos
            {
                cout<<endl<<persona[i].nombre<<" | Hijo "<<j+1<<endl<<endl;
                cout<<"Ingrese el nombre del hijo: "<<endl;
                cin.ignore();
                getline(cin, persona[i].hijo[j].nombre);
                cin.clear();
                cout<<"Ingrese la edad del hijo: "<<endl;
                cin>>persona[i].hijo[j].edad;
                cout<<"Ingrese el documento del hijo: "<<endl;
                cin>>persona[i].hijo[j].documento;
                cout<<"Ingrese el teléfono del hijo: "<<endl;
                fflush(stdin);
                cin>>persona[i].hijo[j].telefono;
                fflush(stdin);
                cout<<"Ingrese el correo del hijo: "<<endl;
                getline(cin, persona[i].hijo[j].correo);
                cout<<"Ingrese el género del hijo: "<<endl;
                fflush(stdin);
                cin>>persona[i].hijo[j].genero;
                cout<<"Ingrese el peso del hijo (kg): "<<endl;
                cin.ignore();
                cin>>persona[i].hijo[j].peso;
                cin.clear();
                cout<<"Ingrese la altura del hijo (cm): "<<endl;
                cin.ignore();
                cin>>persona[i].hijo[j].altura;
                cin.clear();
            }
        }
        if(persona[i].documento!=persona->documento){ //Si el usuario no existe, se muestra un mensaje de error
            cout<<"Error, el usuario no existe"<<endl;
        }
    }
}

void mostrarUsuarios(){ //Función para mostrar los usuarios registrados
    cout<<endl<<endl<<"Seleccione una opción de visualización: "<<endl; //Menú de opciones
    cout<<"1. Todos los usuarios"<<endl;
    cout<<"2. Usuarios con hijos"<<endl;
    cout<<"3. Usuarios sin hijos"<<endl;
    cout<<"4. Selección personalizada (Mostrar o no hijos de un usuario)"<<endl;
    int opcion; //Variable para la opción seleccionada
    cin>>opcion; //Se lee la opción seleccionada
    switch (opcion) //Switch para la selección de la opción
    {
        case 1: //Opción 1: Mostrar todos los usuarios
            cout<<endl<<"Todos los usuarios registrados: "<<endl<<endl;
            for (int i = 0; i < numUsuarios; i++) //Se recorre el arreglo de usuarios
            {
                cout<<endl<<"Usuario "<<i+1<<endl<<endl;
                cout<<"Nombre: "<<persona[i].nombre<<endl;
                cout<<"Edad: "<<persona[i].edad<<endl;
                cout<<"Documento: "<<persona[i].documento<<endl;
                cout<<"Teléfono: "<<persona[i].telefono<<endl;
                cout<<"Correo: "<<persona[i].correo<<endl;
                cout<<"Género: "<<persona[i].genero<<endl;
                cout<<"Peso: "<<persona[i].peso<<endl;
                cout<<"Altura: "<<persona[i].altura<<endl;
                cout<<"Índice de masa corporal: "<<persona[i].IMC<<endl;
                cout<<"Dirección: "<<persona[i].direccion<<endl<<endl<<endl;
                if(persona[i].hijo!=NULL){ 
                    //Se valida si el usuario tiene hijos registrados, de no tenerlos, no se muestra ninguna información
                    for (int j = 0; j < persona[i].numHijos; j++)
                        {
                        cout<<endl<<persona[i].nombre<<" | Hijo "<<j+1<<endl<<endl;
                        cout<<"Nombre: "<<persona[i].hijo[j].nombre<<endl;
                        cout<<"Edad: "<<persona[i].hijo[j].edad<<endl;
                        cout<<"Documento: "<<persona[i].hijo[j].documento<<endl;
                        cout<<"Teléfono: "<<persona[i].hijo[j].telefono<<endl;
                        cout<<"Correo: "<<persona[i].hijo[j].correo<<endl;
                        cout<<"Género: "<<persona[i].hijo[j].genero<<endl;
                        cout<<"Peso: "<<persona[i].hijo[j].peso<<endl;
                        cout<<"Altura: "<<persona[i].hijo[j].altura<<endl<<endl<<endl;
                        }
                }
            }
        break;
        case 2: //Opción 2: Mostrar usuarios con hijos registrados
            cout<<endl<<endl<<"Seleccione una opción de visualización: "<<endl; //Menú de opciones
            cout<<"1. Usuarios con hijos registrados (Se muestran los hijos)"<<endl;
            cout<<"2. Usuarios con hijos registrados (No se muestran los hijos)"<<endl;
            cout<<"3. Usuarios con hijos menores de 18 años registrados (Se muestran los hijos)"<<endl;
            cout<<"4. Usuarios con hijos menores de 18 años registrados (No se muestran los hijos)"<<endl;
            int opcion2; //Variable para la opción seleccionada
            cin>>opcion2; //Se lee la opción seleccionada
            switch(opcion2){ //Switch para la selección de la opción
                case 1: //Opción 1: Mostrar usuarios con hijos registrados (Se muestran los hijos)
                    cout<<endl<<"Usuarios con hijos registrados (Se muestran los hijos): "<<endl<<endl;
                    for (int i = 0; i < numUsuarios; i++) //Se recorre el arreglo de usuarios
                    {
                        if(persona[i].hijo!=NULL) //Se valida si el usuario tiene hijos
                        {
                        cout<<endl<<"Usuario "<<i+1<<endl<<endl;
                        cout<<"Nombre: "<<persona[i].nombre<<endl;
                        cout<<"Edad: "<<persona[i].edad<<endl;
                        cout<<"Documento: "<<persona[i].documento<<endl;
                        cout<<"Teléfono: "<<persona[i].telefono<<endl;
                        cout<<"Correo: "<<persona[i].correo<<endl;
                        cout<<"Género: "<<persona[i].genero<<endl;
                        cout<<"Peso: "<<persona[i].peso<<endl;
                        cout<<"Altura: "<<persona[i].altura<<endl;
                        cout<<"Dirección: "<<persona[i].direccion<<endl<<endl<<endl;
                        for (int j = 0; j < persona[i].numHijos; j++) //Se recorre el arreglo de hijos y se imprimen los datos
                        {
                            cout<<endl<<persona[i].nombre<<" | Hijo "<<j+1<<endl<<endl;
                            cout<<"Nombre: "<<persona[i].hijo[j].nombre<<endl;
                            cout<<"Edad: "<<persona[i].hijo[j].edad<<endl;
                            cout<<"Documento: "<<persona[i].hijo[j].documento<<endl;
                            cout<<"Teléfono: "<<persona[i].hijo[j].telefono<<endl;
                            cout<<"Correo: "<<persona[i].hijo[j].correo<<endl;
                            cout<<"Género: "<<persona[i].hijo[j].genero<<endl;
                            cout<<"Peso: "<<persona[i].hijo[j].peso<<endl;
                            cout<<"Altura: "<<persona[i].hijo[j].altura<<endl<<endl<<endl;
                        }
                        }
                    }
                break;
                case 2: //Opción 2: Mostrar usuarios con hijos registrados (No se muestran los hijos)
                    cout<<endl<<"Usuarios con hijos registrados (No se muestran los hijos): "<<endl<<endl;
                    for (int i = 0; i < numUsuarios; i++) //Se recorre el arreglo de usuarios
                    {
                        if(persona[i].hijo!=NULL) //Se valida si el usuario tiene hijos
                        {
                        cout<<endl<<"Usuario "<<i+1<<endl<<endl;
                        cout<<"Nombre: "<<persona[i].nombre<<endl;
                        cout<<"Edad: "<<persona[i].edad<<endl;
                        cout<<"Documento: "<<persona[i].documento<<endl;
                        cout<<"Teléfono: "<<persona[i].telefono<<endl;
                        cout<<"Correo: "<<persona[i].correo<<endl;
                        cout<<"Género: "<<persona[i].genero<<endl;
                        cout<<"Peso: "<<persona[i].peso<<endl;
                        cout<<"Altura: "<<persona[i].altura<<endl;
                        cout<<"Dirección: "<<persona[i].direccion<<endl<<endl<<endl;
                        }
                    }
                break;
                case 3:
                    cout<<endl<<"Usuarios con hijos menores de 18 años registrados (Se muestran los hijos): "<<endl<<endl;
                    bool hayMenores; //Variable para validar si hay hijos menores de 18 años
                    for (int i = 0; i < numUsuarios; i++) //Se recorre el arreglo de usuarios
                    {
                        for (int j = 0; j < persona[i].numHijos; j++) //Se recoore el arreglo de hijos
                        {
                            if(persona[i].hijo[j].edad<18){ //Se valida si el hijo es menor de 18 años
                                hayMenores=true; //Se cambia el valor de la variable a true en el caso de que haya un hijo menor de 18 años
                            }
                        }
                        if(persona[i].hijo!=NULL && hayMenores==true)
                        //En caso de que el usuario tenga hijos y haya un hijo menor de 18 años se muestran los datos
                        {
                        cout<<endl<<"Usuario "<<i+1<<endl<<endl;
                        cout<<"Nombre: "<<persona[i].nombre<<endl;
                        cout<<"Edad: "<<persona[i].edad<<endl;
                        cout<<"Documento: "<<persona[i].documento<<endl;
                        cout<<"Teléfono: "<<persona[i].telefono<<endl;
                        cout<<"Correo: "<<persona[i].correo<<endl;
                        cout<<"Género: "<<persona[i].genero<<endl;
                        cout<<"Peso: "<<persona[i].peso<<endl;
                        cout<<"Altura: "<<persona[i].altura<<endl;
                        cout<<"Dirección: "<<persona[i].direccion<<endl<<endl<<endl;
                        for (int j = 0; j < persona[i].numHijos; j++) //Se recorre el arreglo de hijos y se imprimen los datos
                        {
                            if(persona[i].hijo[j].edad<18){
                            cout<<endl<<persona[i].nombre<<" | Hijo "<<j+1<<endl<<endl;
                            cout<<"Nombre: "<<persona[i].hijo[j].nombre<<endl;
                            cout<<"Edad: "<<persona[i].hijo[j].edad<<endl;
                            cout<<"Documento: "<<persona[i].hijo[j].documento<<endl;
                            cout<<"Teléfono: "<<persona[i].hijo[j].telefono<<endl;
                            cout<<"Correo: "<<persona[i].hijo[j].correo<<endl;
                            cout<<"Género: "<<persona[i].hijo[j].genero<<endl;
                            cout<<"Peso: "<<persona[i].hijo[j].peso<<endl;
                            cout<<"Altura: "<<persona[i].hijo[j].altura<<endl<<endl<<endl;
                            }
                        }
                        }
                    }
                break;
                case 4: //Opción 4: Mostrar usuarios con hijos menores de 18 años registrados (No se muestran los hijos)
                    cout<<endl<<"Usuarios con hijos menores de 18 años registrados (No se muestran los hijos): "<<endl<<endl;
                    bool hayMayores; //Variable para validar si hay hijos menores de 18 años
                    for (int i = 0; i < numUsuarios; i++)
                    {
                        for (int j = 0; j < persona[i].numHijos; j++) //Se recorre el arreglo de hijos
                        {
                            if(persona[i].hijo[j].edad<18){ //Se valida si el hijo es menor de 18 años
                                hayMayores=true; //Se cambia el valor de la variable a true en el caso de que haya un hijo menor de 18 años
                            }
                        }
                        if(persona[i].hijo!=NULL && hayMayores==true)
                         //En caso de que el usuario tenga hijos y haya un hijo menor de 18 años se muestran los datos
                        {
                        cout<<endl<<"Usuario "<<i+1<<endl<<endl;
                        cout<<"Nombre: "<<persona[i].nombre<<endl;
                        cout<<"Edad: "<<persona[i].edad<<endl;
                        cout<<"Documento: "<<persona[i].documento<<endl;
                        cout<<"Teléfono: "<<persona[i].telefono<<endl;
                        cout<<"Correo: "<<persona[i].correo<<endl;
                        cout<<"Género: "<<persona[i].genero<<endl;
                        cout<<"Peso: "<<persona[i].peso<<endl;
                        cout<<"Altura: "<<persona[i].altura<<endl;
                        cout<<"Dirección: "<<persona[i].direccion<<endl<<endl<<endl;
                        }
                    }
                break;
                default:
                    cout<<"Error, la opción seleccionada es inválida"<<endl;
                    //En caso de que la opción seleccionada no sea válida se muestra un mensaje de error
                    exit(1);
                break;
            }
            
        break;
        case 3: //Opción 3: Mostrar usuarios sin hijos registrados
            cout<<endl<<"Usuarios sin hijos registrados: "<<endl<<endl;
            for (int i = 0; i < numUsuarios; i++) //Se recorre el arreglo de usuarios
            {
                if(persona[i].hijo==NULL) //Se valida si el usuario no tiene hijos y se imprimen los datos
                {
                    cout<<endl<<"Usuario "<<i+1<<endl<<endl;
                    cout<<"Nombre: "<<persona[i].nombre<<endl;
                    cout<<"Edad: "<<persona[i].edad<<endl;
                    cout<<"Documento: "<<persona[i].documento<<endl;
                    cout<<"Teléfono: "<<persona[i].telefono<<endl;
                    cout<<"Correo: "<<persona[i].correo<<endl;
                    cout<<"Género: "<<persona[i].genero<<endl;
                    cout<<"Peso: "<<persona[i].peso<<endl;
                    cout<<"Altura: "<<persona[i].altura<<endl;
                    cout<<"Dirección: "<<persona[i].direccion<<endl<<endl<<endl;
                }
            }
        break;
        case 4: //Opción 4: Mostrar usuarios con hijos registrados
            cout<<endl<<"Selección personalizada (Mostrar o no hijos de un usuario): "<<endl<<endl; 
            int option; //Variable para almacenar la opción seleccionada (Mostrar o no hijos)
            for (int i = 0; i < numUsuarios; i++) //Se recorre el arreglo de usuarios
            {
                cout<<endl<<"Usuario "<<i+1<<endl<<endl;
                cout<<"Nombre: "<<persona[i].nombre<<endl;
                cout<<"Edad: "<<persona[i].edad<<endl;
                cout<<"Documento: "<<persona[i].documento<<endl;
                cout<<"Teléfono: "<<persona[i].telefono<<endl;
                cout<<"Correo: "<<persona[i].correo<<endl;
                cout<<"Género: "<<persona[i].genero<<endl;
                cout<<"Peso: "<<persona[i].peso<<endl;
                cout<<"Altura: "<<persona[i].altura<<endl;
                cout<<"Dirección: "<<persona[i].direccion<<endl<<endl<<endl;
                cout<<endl<<"¿Desea mostrar los hijos de este usuario? (1=Si 0=No): "; 
                //Se pregunta si se desea mostrar los hijos del usuario
                cin>>option;
                if(option==1){ //En caso de que la opción sea 1 se muestran los hijos del usuario
                    if(persona[i].hijo!=NULL){ //Se valida si el usuario tiene hijos
                        for (int j = 0; j < persona[i].numHijos; j++)
                        {
                        cout<<endl<<persona[i].nombre<<" | Hijo "<<j+1<<endl<<endl;
                        cout<<"Nombre: "<<persona[i].hijo[j].nombre<<endl;
                        cout<<"Edad: "<<persona[i].hijo[j].edad<<endl;
                        cout<<"Documento: "<<persona[i].hijo[j].documento<<endl;
                        cout<<"Teléfono: "<<persona[i].hijo[j].telefono<<endl;
                        cout<<"Correo: "<<persona[i].hijo[j].correo<<endl;
                        cout<<"Género: "<<persona[i].hijo[j].genero<<endl;
                        cout<<"Peso: "<<persona[i].hijo[j].peso<<endl;
                        cout<<"Altura: "<<persona[i].hijo[j].altura<<endl;
                        cout<<"Índice de masa corporal: "<<persona[i].hijo[j].IMC<<endl<<endl<<endl;
                        }
                    }
                    if(persona[i].hijo==NULL){ //En caso de que el usuario no tenga hijos se muestra un mensaje de error
                        cout<<endl<<"Este usuario no tiene hijos registrados"<<endl;
                    }
                }
            }
        break;
        default:
            cout<<"Error, la opción seleccionada es inválida"<<endl;
            exit(1);
        break;
    }
}

void buscarUsuario(){
    int option; //Variable para almacenar la opción seleccionada
    cout<<endl<<"Seleccione el tipo de búsqueda: "<<endl;
    cout<<"1. Búsqueda por nombre"<<endl;
    cout<<"2. Búsqueda por documento"<<endl;
    cin>>option;
    switch (option)
    {
        case 1: //Opción 1: Búsqueda por nombre
            cout<<endl<<"Ingrese el nombre a buscar: ";
            cin>>persona->nombre;
            for (int i = 0; i < numUsuarios; i++) //Se recorre el arreglo de usuarios
            {
                if(persona[i].nombre==persona->nombre){ //Se valida si el nombre del usuario es igual al nombre a buscar
                    cout<<endl<<"Usuario "<<i+1<<endl<<endl;
                    cout<<"Nombre: "<<persona[i].nombre<<endl;
                    cout<<"Edad: "<<persona[i].edad<<endl;
                    cout<<"Documento: "<<persona[i].documento<<endl;
                    cout<<"Teléfono: "<<persona[i].telefono<<endl;
                    cout<<"Correo: "<<persona[i].correo<<endl;
                    cout<<"Género: "<<persona[i].genero<<endl;
                    cout<<"Peso: "<<persona[i].peso<<endl;
                    cout<<"Altura: "<<persona[i].altura<<endl;
                    cout<<"Dirección: "<<persona[i].direccion<<endl<<endl<<endl;
                    cout<<endl<<"¿Desea mostrar los hijos de este usuario? (1=Si 0=No): "; 
                    //Se pregunta si se desea mostrar los hijos del usuario
                    cin>>option;
                    if(option==1){ //En caso de que la opción sea 1 se muestran los hijos del usuario
                        if(persona[i].hijo!=NULL){ //Se valida si el usuario tiene hijos
                            for (int j = 0; j < persona[i].numHijos; j++)
                            {
                            cout<<endl<<persona[i].nombre<<" | Hijo "<<j+1<<endl<<endl;
                            cout<<"Nombre: "<<persona[i].hijo[j].nombre<<endl;
                            cout<<"Edad: "<<persona[i].hijo[j].edad<<endl;
                            cout<<"Documento: "<<persona[i].hijo[j].documento<<endl;
                            cout<<"Teléfono: "<<persona[i].hijo[j].telefono<<endl;
                            cout<<"Correo: "<<persona[i].hijo[j].correo<<endl;
                            cout<<"Género: "<<persona[i].hijo[j].genero<<endl;
                            cout<<"Peso: "<<persona[i].hijo[j].peso<<endl;
                            cout<<"Altura: "<<persona[i].hijo[j].altura<<endl;
                            cout<<"Índice de masa corporal: "<<persona[i].hijo[j].IMC<<endl<<endl<<endl;
                            }
                        }
                    if(persona[i].hijo==NULL){ //En caso de que el usuario no tenga hijos se muestra un mensaje de error
                        cout<<endl<<"Este usuario no tiene hijos registrados"<<endl;
                    }
                    }
                }
                else if(persona[i].nombre!=persona->nombre){ //En caso de que el nombre del usuario no sea igual al nombre a buscar se muestra un mensaje de error
                    cout<<endl<<"El nombre ingresado no se encuentra registrado"<<endl;
                }
            }
        break;
        case 2: //Opción 2: Búsqueda por documento 
            cout<<endl<<"Ingrese el número de documento a buscar: ";
            cin>>persona->documento;
            for (int i = 0; i < numUsuarios; i++) //Se recorre el arreglo de usuarios
            {
                if(persona[i].documento==persona->documento){ //Se valida si el nombre del usuario es igual al nombre a buscar
                    cout<<endl<<"Usuario "<<i+1<<endl<<endl;
                    cout<<"Nombre: "<<persona[i].nombre<<endl;
                    cout<<"Edad: "<<persona[i].edad<<endl;
                    cout<<"Documento: "<<persona[i].documento<<endl;
                    cout<<"Teléfono: "<<persona[i].telefono<<endl;
                    cout<<"Correo: "<<persona[i].correo<<endl;
                    cout<<"Género: "<<persona[i].genero<<endl;
                    cout<<"Peso: "<<persona[i].peso<<endl;
                    cout<<"Altura: "<<persona[i].altura<<endl;
                    cout<<"Dirección: "<<persona[i].direccion<<endl<<endl<<endl;
                    cout<<endl<<"¿Desea mostrar los hijos de este usuario? (1=Si 0=No): "; 
                    //Se pregunta si se desea mostrar los hijos del usuario
                    cin>>option;
                    if(option==1){ //En caso de que la opción sea 1 se muestran los hijos del usuario
                        if(persona[i].hijo!=NULL){ //Se valida si el usuario tiene hijos
                            for (int j = 0; j < persona[i].numHijos; j++)
                            {
                            cout<<endl<<persona[i].nombre<<" | Hijo "<<j+1<<endl<<endl;
                            cout<<"Nombre: "<<persona[i].hijo[j].nombre<<endl;
                            cout<<"Edad: "<<persona[i].hijo[j].edad<<endl;
                            cout<<"Documento: "<<persona[i].hijo[j].documento<<endl;
                            cout<<"Teléfono: "<<persona[i].hijo[j].telefono<<endl;
                            cout<<"Correo: "<<persona[i].hijo[j].correo<<endl;
                            cout<<"Género: "<<persona[i].hijo[j].genero<<endl;
                            cout<<"Peso: "<<persona[i].hijo[j].peso<<endl;
                            cout<<"Altura: "<<persona[i].hijo[j].altura<<endl;
                            cout<<"Índice de masa corporal: "<<persona[i].hijo[j].IMC<<endl<<endl<<endl;
                            }
                        }
                    if(persona[i].hijo==NULL){ //En caso de que el usuario no tenga hijos se muestra un mensaje de error
                        cout<<endl<<"Este usuario no tiene hijos registrados"<<endl;
                    }
                    }
                }
                else if(persona[i].documento!=persona->documento){ //En caso de que el nombre del usuario no sea igual al nombre a buscar se muestra un mensaje de error
                    cout<<endl<<"El número de documento ingresado no se encuentra registrado"<<endl;
                }
            }
        break;
        default: //En caso de que la opción ingresada no sea válida se muestra un mensaje de error
            cout<<endl<<"La opción digitada no es válida"<<endl;
            exit(1);
    }
}

void eliminarUsuario(){
    int option;
    cout<<endl<<"¿Desea eliminar un usuario por nombre o por documento? (1=Nombre 2=Documento): ";
    cin>>option;
    switch (option)
    {
        case 1: //Opción 1: Eliminación por nombre
            cout<<endl<<"Ingrese el nombre del usuario a eliminar: ";
            cin>>persona->nombre;
            for (int i = 0; i < numUsuarios; i++) //Se recorre el arreglo de usuarios
            {
                if(persona[i].nombre==persona->nombre){ //Se valida si el nombre del usuario es igual al nombre a buscar
                    for (int j = i; j < numUsuarios; j++) //Se recorre el arreglo de usuarios desde el usuario a eliminar hasta el final
                    {
                        persona[j]=persona[j+1]; //Se mueven los usuarios hacia la izquierda
                    }
                    numUsuarios--; //Se disminuye el número de usuarios
                    cout<<endl<<"Usuario eliminado con éxito"<<endl;
                }
                else if(persona[i].nombre!=persona->nombre){ //En caso de que el nombre del usuario no sea igual al nombre a buscar se muestra un mensaje de error
                    cout<<endl<<"El nombre ingresado no se encuentra registrado"<<endl;
                }
            }
        break;
        case 2: //Opción 2: Eliminación por documento
            cout<<endl<<"Ingrese el número de documento del usuario a eliminar: ";
            cin>>persona->documento;
            for (int i = 0; i < numUsuarios; i++) //Se recorre el arreglo de usuarios
            {
                if(persona[i].documento==persona->documento){ //Se valida si el nombre del usuario es igual al nombre a buscar
                    for (int j = i; j < numUsuarios; j++) //Se recorre el arreglo de usuarios desde el usuario a eliminar hasta el final
                    {
                        persona[j]=persona[j+1]; //Se mueven los usuarios hacia la izquierda
                    }
                    numUsuarios--; //Se disminuye el número de usuarios
                    cout<<endl<<"Usuario eliminado con éxito"<<endl;
                }
                else if(persona[i].documento!=persona->documento){ //En caso de que el nombre del usuario no sea igual al nombre a buscar se muestra un mensaje de error
                    cout<<endl<<"El número de documento ingresado no se encuentra registrado"<<endl;
                }
            }
        break;
        default: //En caso de que la opción ingresada no sea válida se muestra un mensaje de error
            cout<<endl<<"La opción digitada no es válida"<<endl;
            exit(1);
        break;
    }
}

void guardarUsuarios(){
    ofstream archivo;
    archivo.open("usuarios.txt",ios::out); //Se abre el archivo usuarios.txt
    if(archivo.fail()){ //Se valida si el archivo se abrió correctamente
        cout<<endl<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }
    for (int i = 0; i < numUsuarios; i++) //Se recorre el arreglo de usuarios
    {
        archivo<<persona[i].nombre<<endl; //Se escribe el nombre del usuario
        archivo<<persona[i].edad<<endl; //Se escribe la edad del usuario
        archivo<<persona[i].documento<<endl; //Se escribe el documento del usuario
        archivo<<persona[i].telefono<<endl; //Se escribe el teléfono del usuario
        archivo<<persona[i].correo<<endl; //Se escribe el correo del usuario
        archivo<<persona[i].genero<<endl; //Se escribe el género del usuario
        archivo<<persona[i].peso<<endl; //Se escribe el peso del usuario
        archivo<<persona[i].altura<<endl; //Se escribe la altura del usuario
        archivo<<persona[i].IMC<<endl; //Se escribe el índice de masa corporal del usuario
        archivo<<persona[i].numHijos<<endl; //Se escribe el número de hijos del usuario
        for (int j = 0; j < persona[i].numHijos; j++) //Se recorre el arreglo de hijos del usuario
        {
            archivo<<persona[i].hijo[j].nombre<<endl; //Se escribe el nombre del hijo
            archivo<<persona[i].hijo[j].edad<<endl; //Se escribe la edad del hijo
            archivo<<persona[i].hijo[j].documento<<endl; //Se escribe el documento del hijo
            archivo<<persona[i].hijo[j].telefono<<endl; //Se escribe el teléfono del hijo
            archivo<<persona[i].hijo[j].correo<<endl; //Se escribe el correo del hijo
            archivo<<persona[i].hijo[j].genero<<endl; //Se escribe el género del hijo
            archivo<<persona[i].hijo[j].peso<<endl; //Se escribe el peso del hijo
            archivo<<persona[i].hijo[j].altura<<endl; //Se escribe la altura del hijo
            archivo<<persona[i].hijo[j].IMC<<endl; //Se escribe el índice de masa corporal del hijo
        }
    }
}

void cargarUsuarios(){
    ifstream archivo;
    archivo.open("usuarios.txt",ios::in); //Se abre el archivo usuarios.txt
    if(archivo.fail()){ //Se valida si el archivo se abrió correctamente
        cout<<endl<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }
    while(!archivo.eof()){ //Se recorre el archivo hasta el final
        archivo>>persona[numUsuarios].nombre; //Se lee el nombre del usuario
        archivo>>persona[numUsuarios].edad; //Se lee la edad del usuario
        archivo>>persona[numUsuarios].documento; //Se lee el documento del usuario
        archivo>>persona[numUsuarios].telefono; //Se lee el teléfono del usuario
        archivo>>persona[numUsuarios].correo; //Se lee el correo del usuario
        archivo>>persona[numUsuarios].genero; //Se lee el género del usuario
        archivo>>persona[numUsuarios].peso; //Se lee el peso del usuario
        archivo>>persona[numUsuarios].altura; //Se lee la altura del usuario
        archivo>>persona[numUsuarios].IMC; //Se lee el índice de masa corporal del usuario
        archivo>>persona[numUsuarios].numHijos; //Se lee el número de hijos del usuario
        for (int i = 0; i < persona[numUsuarios].numHijos; i++) //Se recorre el arreglo de hijos del usuario
        {
            archivo>>persona[numUsuarios].hijo[i].nombre; //Se lee el nombre del hijo
            archivo>>persona[numUsuarios].hijo[i].edad; //Se lee la edad del hijo
            archivo>>persona[numUsuarios].hijo[i].documento; //Se lee el documento del hijo
            archivo>>persona[numUsuarios].hijo[i].telefono; //Se lee el teléfono del hijo
            archivo>>persona[numUsuarios].hijo[i].correo; //Se lee el correo del hijo
            archivo>>persona[numUsuarios].hijo[i].genero; //Se lee el género del hijo
            archivo>>persona[numUsuarios].hijo[i].peso; //Se lee el peso del hijo
            archivo>>persona[numUsuarios].hijo[i].altura; //Se lee la altura del hijo
            archivo>>persona[numUsuarios].hijo[i].IMC; //Se lee el índice de masa corporal del hijo
        }
        numUsuarios++; //Se incrementa el número de usuarios
    }
    archivo.close(); //Se cierra el archivo
}