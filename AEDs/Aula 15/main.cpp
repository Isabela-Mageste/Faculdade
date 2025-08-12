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
class VectorOperator
{
public:
    VectorOperator()
    {
        srand(time(0));
        for (int i = 0; i < SIZE; i++)
        {
            this->vector[i] = generateNumber();
        }
    }
    void print()
    {
        for (int i = 0; i < (SIZE / 4); i++)
        {
            cout << "\t" << vector[i] << "\t" << vector[i + (SIZE / 4)] << "\t" << vector[i + ((SIZE / 4) * 2)] << "\t" << vector[i + ((SIZE / 4) * 3)] << endl;
        }
    }
    void howMany(int x)
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
    void searchInterval(int max, int min)
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
    void searchFirst(int x)
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
    void searchAll(int x)
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (vector[i] == x)
            {
                cout << x << " aparece na posição " << i << " do vetor!" << endl;
            }
        }
    }
    void advancedSearch()
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
    void invert()
    {
        for (int i = 0; i < SIZE / 2; i++)
        {
            int aux;
            aux = vector[i];
            vector[i] = vector[SIZE - i - 1];
            vector[SIZE - i - 1] = aux;
        }
    }
    void changeValues(int value)
    {
        for (int i = 0; i < SIZE; i++)
        {
            vector[i] += value;
        }
    }
    void alterByDivisor(int divisor, int value)
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (vector[i] % divisor != 0)
            {
                vector[i] += value;
            }
        }
    }
    void removeFirst(int value)
    {
        bool removeu = false;
        for (int i = 0; i < SIZE; i++)
        {
            if (removeu == false)
            {
                if (vector[i] == value)
                {
                    vector[i] = 0;
                    removeu = true;
                }
            }
            else
            {
                break;
            }
        }
    }
    void removeAll(int value)
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (vector[i] == value)
            {
                vector[i] = 0;
            }
        }
    }

private:
    int vector[SIZE];
    int generateNumber()
    {
        int x;
        x = 1 + rand() % 10;

        return x;
    }
};

int main()
{

    decorate(decoNum);
    VectorOperator vector;
    int choice, value, max, min, x;
    choice = 0;
    cout << "-\t-\t-\t VETOR\t-\t-\t-" << endl;
    vector.print();
    while (choice != -1)
    {
        decorate(decoNum);
        cout << "\t Digite o numero correspondente à tarefa a ser executada " << endl;
        cout << "\t [1]- buscar quantas ocorrencias de um valor no vetor " << endl;
        cout << "\t [2]- buscar quantas ocorrencias em um intervalo no vetor " << endl;
        cout << "\t [3]- encontrar primeira posição de um valor no vetor " << endl;
        cout << "\t [4]- encontrar todas as posições de um valor no vetor " << endl;
        cout << "\t [5]- Pesquisa avançada " << endl;
        cout << "\t [6]- Inversão dos valores " << endl;
        cout << "\t [7]- aumentar valores" << endl;
        cout << "\t [8]- alterar valores não divisiveis por x " << endl;
        cout << "\t [9]- remover primeira ocorrencia" << endl;
        cout << "\t [10]- remover toda ocorrencia" << endl;
        cout << "\t [11]- Imprimir Vetor" << endl;
        cout << "\t [outra]- finalizar programa " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Digite um valor de 1 a 10 a ser procurado no vetor" << endl;
            cin >> value;
            vector.howMany(value);
            break;

        case 2:
            cout << "Digite o menor valor a ser procurado" << endl;
            cin >> min;
            cout << "Digite o maior valor a ser procurado" << endl;
            cin >> max;
            vector.searchInterval(max, min);
            break;
        case 3:
            cout << "Digite um valor de 1 a 10 a ser procurado no vetor" << endl;
            cin >> value;
            vector.searchFirst(value);
            break;
        case 4:
            cout << "Digite um valor de 1 a 10 a ser procurado no vetor" << endl;
            cin >> value;
            vector.searchAll(value);
            break;
        case 5:
            cout << "buscando ocorrências de uma numero em que a diferença entre ele e seu sucessor e ele e seu antecessor tem mesmo módulo! " << endl;
            vector.advancedSearch();
            break;
        case 6:
            cout << "Vetor antes da inversao: " << endl;
            vector.print();
            cout << "Invertendo os valores do vetor" << endl;
            vector.invert();
            vector.print();
            break;
        case 7:
            cout << "Digite o valor a ser adicionado aos elementos: " << endl;
            cin >> value;
            cout << "Vetor antes da alteração: " << endl;
            vector.print();
            cout << "Vetor aumentado em " << value << endl;
            vector.changeValues(value);
            vector.print();
            break;
        case 8:
            cout << "Digite o divisor a ser buscado: " << endl;
            cin >> x;
            cout << "Digite o valor a ser adicionado aos elementos: " << endl;
            cin >> value;
            cout << "Vetor antes da alteração: " << endl;
            vector.print();
            cout << "Vetor alterado " << endl;
            vector.alterByDivisor(x, value);
            vector.print();
            break;
        case 9:
            cout << "Digite o valor a ser removido: " << endl;
            cin >> value;
            cout << "Vetor antes da alteração: " << endl;
            vector.print();
            cout << "Vetor alterado" << endl;
            vector.removeFirst(value);
            vector.print();
            break;
        case 10:
            cout << "Digite o valor a ser removido: " << endl;
            cin >> value;
            cout << "Vetor antes da alteração: " << endl;
            vector.print();
            cout << "Vetor aumentado em " << value << endl;
            vector.removeAll(value);
            vector.print();
            break;
        case 11:
            cout << "-\t-\t-\t VETOR\t-\t-\t-" << endl;
            vector.print();
            break;
        default:
            cout << "FIM!";
            choice = -1;
            break;
        }
    }
    decorate(decoNum);
}