#include <stdio.h>
#include <iostream>
#include "ordenacao.h"

const int SIZE = 10;
using namespace std;
/*
tema: ordenacao
*/
void decorate()
{
    cout << endl;
    for (int i = 0; i < 20; i++)
    {
        cout << "=-=";
    }
    cout << endl;
}

int main()
{
    //--------------------Variaveis---------------------//
    srand(time(0));
    int fvector[SIZE];                                   // caso medio
    int bvector[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // melhor caso
    int wvector[SIZE] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; // pior caso
    fillVector(fvector);
    //----------------------Exibir------------------------//
    decorate();
    cout << "\t\033[1;33mVetor medio antes da ordenacao: \033[0m " << endl;
    printVector(fvector);
    cout << endl;
    cout << "\t\033[1;32mMelhor vetor antes da ordenacao: \033[0m" << endl;
    printVector(bvector);
    cout << endl;
    cout << "\t\033[1;31mPior vetor antes da ordenacao: \033[0m " << endl;
    printVector(wvector);
    decorate();
    //-----------------------Ordenar---------------------//
    bubbleSort(fvector);
    bubbleSort(bvector);
    bubbleSort(wvector);
    //-----------------------Exibir----------------------//
    cout << "\t\033[1;33mVetor medio antes da ordenacao: \033[0m" << endl;
    printVector(fvector);
    cout << endl;
    cout << "\t\033[1;32mMelhor vetor depois da ordenacao: \033[0m" << endl;
    printVector(bvector);
    cout << endl;
    cout << "\t\033[1;31mPior vetor depois da ordenacao: \033[0m" << endl;
    printVector(wvector);
    decorate();
    return 0;
}