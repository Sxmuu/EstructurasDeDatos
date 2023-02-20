#include <iostream>

int main() {
    int array[10];      //Creación de un arreglo con 10 elementos
    int *puntero = array;   //Creación y asignación de un puntero al arreglo

    //Llenado del arreglo
    for (int i = 0; i < 10; i++) {
        array[i] = rand() % 26;   //Se genera un número aleatorio entre 0 y 25 y se asigna al elemento del arreglo en la posición i
    }

    //Impresión del arreglo con el puntero
    std::cout << "Valores del arreglo: "<<std::endl;
    for (int i = 0; i < 10; i++) {    
        std::cout<<"Posicion "<<i+1<<": ";
        std::cout << puntero[i] << std::endl;   //Se imprime el valor del elemento del arreglo en la posición i utilizando el puntero
    }

    //Impresión de las direcciones de memoria
    std::cout <<std::endl << "Direcciones de memoria: "<<std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout <<"Posicion "<<i+1<<": ";
        std::cout << puntero + i << " "<<std::endl;   //Se imprime la dirección de memoria del elemento del arreglo en la posición i utilizando el puntero
    }

    return 0;   //El programa finaliza con éxito
}
