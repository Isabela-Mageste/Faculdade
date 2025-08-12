#include <iostream>
#include <stdio.h>
#include <time.h>
const int decoNum = 40;
const int SIZE = 20;
using namespace std;

void decorate(int x)
{
    cout << endl;
    for (int i = 0; i < x; i++)
    {
        cout << "=-=";
    }
    cout << endl;
}
int generateNumber()
{
    int x;
    x = 1 + rand() % 10;

    return x;
}

void print(int *vector, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "\t" << vector[i];
    }
    cout << endl;
}
void copy(int *A, int *B, int size)
{ //(to be copied, receptor,size)
    for (int i = 0; i < size; i++)
    {
        B[i] = A[i];
    }
}

int main()
{
    int vector[SIZE];
    int vectorBackup[SIZE];
    int vectorSorted[SIZE];
    srand(time(0));
    //------------------------------------------------//------------------------------------------------//
    for (int i = 0; i < SIZE; i++)
    {
        vector[i] = generateNumber();
        vectorBackup[i] = 0;
        vectorSorted[i] = 0;
        cout << "\t" << vector[i];
    }
    //------------------------------------------------//------------------------------------------------//
    decorate(decoNum);
    cout << "\t EXERCICIOS DE VETORES \t" << endl;
    cout << "Ordem: " << endl;
    cout << "[1]backup sem repetições" << endl;
    cout << "[2]backup ordenado" << endl;

    int usableSpace = 0;
    for (int i = 0; i < SIZE; i++)
    {
        bool repetido = false;
        for (int j = 0; j < usableSpace; j++)
        {
            if (vector[i] == vectorBackup[j])
            {
                repetido = true;
                break;
            }
        }
        if (!repetido)
        {
            vectorBackup[usableSpace++] = vector[i];
        }
    }
    print(vectorBackup, usableSpace);

    int aux;
    for (int i = 0; i < usableSpace; i++)
    {
        vectorSorted[i] = vectorBackup[i];
    }

    for (int i = 0; i < usableSpace - 1; i++)
    {
        for (int j = i + 1; j < usableSpace; j++)
        {
            if (vectorSorted[j] < vectorSorted[i])
            {
                aux = vectorSorted[i];
                vectorSorted[i] = vectorSorted[j];
                vectorSorted[j] = aux;
            }
        }
    }

    cout << "Vetor Após sorteamento" << endl;
    print(vectorSorted, usableSpace);

    cout << "FIM" << endl;

    decorate(decoNum);
}
