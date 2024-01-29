#include <iostream>
#include <omp.h>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()

int main() {
    const int size = 1000;
    int A[size], B[size], C[size];

    // Inicializar la semilla de números aleatorios
    srand(time(NULL));

    // Inicializar los arreglos A y B con valores aleatorios
    for (int i = 0; i < size; ++i) {
        A[i] = rand() % 100;  // Números aleatorios entre 0 y 99
        B[i] = rand() % 100;
    }

    // Suma paralela de los arreglos utilizando OpenMP
    #pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        C[i] = A[i] + B[i];
    }

    // Imprimir algunos de los resultados para verificar
    std::cout << "Primeros 10 resultados de la suma:" << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << A[i] << " + " << B[i] << " = " << C[i] << std::endl;
    }

    return 0;
}
