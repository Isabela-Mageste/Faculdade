#include <iostream>
using namespace std;
const int SIZE = 10;
int generateNumber()
{
    return 1 + rand() % 100;
}
void fillVector(int *vector)
{
    for (int i = 0; i < SIZE; i++)
    {
        vector[i] = generateNumber();
    }
}
void printVector(int *vector)
{ // imprime em duas linhas para facilitar leitura
    cout << endl;
    for (int i = 0; i < SIZE / 2; i++)
    {
        cout << "\t\033[1;34m[\033[0m" << vector[i] << "\033[1;34m]\033[0m";
    }
    cout << endl;
    for (int i = SIZE / 2; i < SIZE; i++)
    {
        cout << "\t\033[1;34m[\033[0m" << vector[i] << "\033[1;34m]\033[0m";
    }
    cout << endl;
}
void bubbleSort(int *fvector)
{
    int i, j, aux;
    for (i = 0; i < SIZE - 1; i++)
    {
        for (j = 0; j < SIZE - i - 1; j++)
        {
            if (fvector[j] > fvector[j + 1])
            { // se vector[0] > vector[1], troca ambos
                aux = fvector[j];
                fvector[j] = fvector[j + 1];
                fvector[j + 1] = aux;
            }
        }
    }
}