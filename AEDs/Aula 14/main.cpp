#include <stdio.h>
#include <iostream>
#include <time.h>
const int SIZE = 100;
const int decoNum = 20;
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
float generateNumber()
{
    float x;
    x = 1 + /*100 +*/ rand() % 11;
    // x = x / 10;
    return x;
}
void searchQuantity(int x, int *vector)
{
    int counter = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (vector[i] == x)
        {
            counter++;
        }
    }
    cout << "O numero " << x << " aparece " << counter << " vezes no vetor! " << endl;
}
void searchInterval(int max, int min, int *vector)
{
    int counter = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (vector[i] >= min && vector[i] <= max)
        {
            counter++;
        }
    }
    cout << counter << " numeros estão no intervalo!" << endl;
}
void searchOccurance(int x, int *vector)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (vector[i] == x)
        {
            cout << " A primeira ocorrencia de " << x << " aparece na posição " << i + 1 << " do vetor!" << endl;
            break;
        }
    }
}
void searchAllOccurance(int x, int *vector)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (vector[i] == x)
        {
            cout << x << " aparece na posição " << i << " do vetor!" << endl;
        }
    }
}
void advancedSearch(int *vector)
{
    for (int i = 1; i < SIZE - 1; i++)
    {
        if (abs(vector[i] - vector[i - 1]) == abs(vector[i] - vector[i + 1]))
        {
            {
                cout << "Resultado na casa " << i << " com valor " << vector[i] << " e anterior " << vector[i - 1] << " e sucessor " << vector[i + 1] << endl;
            }
        }
    }
}

int main()
{

    srand(time(0));

    decorate(decoNum);
    int vector[SIZE];
    for (int i = 0; i < SIZE; i++)
    {

        vector[i] = generateNumber();
    }

    int choice, value, max, min;
    choice = 0;

    for (int i = 0; i < (SIZE / 4); i++)
    {
        // int aux = SIZE / 4;
        cout << "\t" << vector[i] << "\t" << vector[i + (SIZE / 4)] << "\t" << vector[i + ((SIZE / 4) * 2)] << "\t" << vector[i + ((SIZE / 4) * 3)] << endl;
        // cout << "\t" << i << "\t" << i + aux << "\t" << i + aux*2 << "\t" << i + aux * 3<< i + aux*4 << "\t" << i + aux * 5 << "\t" << i + aux * 6<< i + aux * 7 << endl;
    }
    while (choice != -1)
    {
        decorate(decoNum);
        cout << "\t Digite o numero correspondente à tarefa a ser executada " << endl;
        cout << "\t [1]- buscar quantas ocorrencias de um valor no vetor " << endl;
        cout << "\t [2]- buscar quantas ocorrencias em um intervalo no vetor " << endl;
        cout << "\t [3]- encontrar primeira posição de um valor no vetor " << endl;
        cout << "\t [4]- encontrar todas as posições de um valor no vetor " << endl;
        cout << "\t [5]- Pesquisa avançada " << endl;
        cout << "\t [outra]- finalizar programa " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Digite um valor de 1 a 10 a ser procurado no vetor" << endl;
            cin >> value;
            searchQuantity(value, vector);
            break;

        case 2:
            cout << "Digite o menor valor a ser procurado" << endl;
            cin >> min;
            cout << "Digite o maior valor a ser procurado" << endl;
            cin >> max;
            searchInterval(max, min, vector);
            break;
        case 3:
            cout << "Digite um valor de 1 a 10 a ser procurado no vetor" << endl;
            cin >> value;
            searchOccurance(value, vector);
            break;
        case 4:
            cout << "Digite um valor de 1 a 10 a ser procurado no vetor" << endl;
            cin >> value;
            searchAllOccurance(value, vector);
            break;
        case 5:
            cout << "buscando ocorrências de uma numero em que a diferença entre ele e seu sucessor e ele e seu antecessor tem mesmo módulo! " << endl;
            advancedSearch(vector);
            break;

        default:
            cout << "FIM!";
            choice = -1;
            break;
        }
    }

    decorate(decoNum);
}