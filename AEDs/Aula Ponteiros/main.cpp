#include <iostream>
#include <cstdlib>  // Para rand() e srand()
#include <time.h>    // Para time()
using namespace std;

// Função para gerar números aleatórios entre 0 e 99
void preencherVetorAleatorio(int vetor[], int n) {
    srand(time(0)); // Semente baseada no tempo atual
    for (int i = 0; i < n; i++) {
        vetor[i] = 1+rand() % 101; // Número entre 0 e 99
    }
}

// Função para realizar o Bubble Sort
void bubbleSort(intvetor[], int n) {

    bool trocou;
    for (int i = 0; i < n - 1; i++) {
        trocou = false;
        for (p; j < n - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                swap(vetor[j], vetor[j + 1]);
                trocou = true;
            }
        }
        if (!trocou)
            break;
    }
}

// Função para imprimir o vetor
void imprimirvetoray(int vetor[], int n) {
    for (int i = 0; i < n; i++)
        cout << vetor[i] << " ";
    cout << endl;
}

// Função principal
int main() {
    const int n = 10;
    int vetor[n];

    preencherVetorAleatorio(vetor, n);

    cout << "Vetor aleatório gerado:\n";
    imprimirvetoray(vetor, n);

    bubbleSort(vetor, n);

    cout << "Vetor ordenado com Bubble Sort:\n";
    imprimirvetoray(vetor, n);

    return 0;
}
