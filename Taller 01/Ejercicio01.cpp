#include <iostream>

int main() {
    int array[10]; //Creación de un arreglo con 10 elementos
    int *puntero; //Creación de un puntero
    puntero = array; //Asignación del puntero al arreglo

    //Llenado del arreglo
    for (int i = 0; i < 10; i++) {
        array[i] = rand() % 26;
    }
    //Impresión del arreglo con el puntero
    std::cout << "Valores del arreglo: "<<std::endl;
    for (int i = 0; i < 10; i++) {    
        std::cout<<"Posicion "<<i+1<<": ";
        std::cout << puntero[i] << std::endl;
    }
    //Impresión de las direcciones de memoria
    std::cout <<std::endl << "Direcciones de memoria: "<<std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout <<"Posicion "<<i+1<<": ";
        std::cout << puntero + i << " "<<std::endl;
    }
}
