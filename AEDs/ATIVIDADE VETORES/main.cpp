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
        usableSpace = 0;
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

    void removeFirst(int value)
    {
        bool removeu = false;
        for (int i = 0; i < SIZE; i++)
        {
            if (removeu == false)
            {
                if (vector[i] == value)
                {
                    for (int j = i; j < SIZE; j++)
                    {
                        vector[j] = vector[j + 1];
                    }
                    removeu =true;
                    usableSpace +=1;
                }
            }
            else
            {
                break;
            }
        }
    }
    void insert(int value, int pos)
    {
        if (usableSpace > 0)
        {
            int aux;
            int support = value;
            for (int i = pos; i < (SIZE - pos); i++)
            {
                aux = vector[i];
                vector[i] = support;
                support = vector[i + 1];
                vector[i + 1] = aux;
                aux = support;
                
            }
            usableSpace -=1;
        }else{
            cout<<"Não há espaço!"<<endl;
        }
    }
    void removeRepeat()
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (vector[i] == vector[j])
                {
                    vector[j] = vector[j + 1];
                }
            }
        }
    }

private:
    int vector[SIZE];
    int usableSpace;
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
    int choice, value, max, min, pos;
    choice = 0;
    cout << "-\t-\t-\t VETOR\t-\t-\t-" << endl;
    vector.print();
    while (choice != -1)
    {
        decorate(decoNum);
        cout << "\t Digite o numero correspondente à tarefa a ser executada " << endl;
        cout << "\t [1]- buscar quantas ocorrencias de um valor no vetor " << endl;     // ok
        cout << "\t [2]- buscar quantas ocorrencias em um intervalo no vetor " << endl; // ok
        cout << "\t [3]- encontrar primeira posição de um valor no vetor " << endl;     // ok
        cout << "\t [4]- remover primeira ocorrencia" << endl;                          // ok
        cout << "\t [5]- inserir em posição" << endl;
        cout << "\t [6]- Retirar repetições" << endl;
        cout << "\t [7]- imprimir vetor" << endl;
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
            cout << "Digite o valor a ser removido: " << endl;
            cin >> value;
            cout << "Vetor antes da alteração: " << endl;
            vector.print();
            cout << "Vetor alterado" << endl;
            vector.removeFirst(value);
            vector.print();
            break;
        case 5:
            cout << "Digite o valor a ser inserido: " << endl;
            cin >> value;
            cout << "Digite o espaço a ser inserido: " << endl;
            cin >> pos;
            cout << "Vetor antes da alteração: " << endl;
            vector.print();
            cout << "Vetor após inserção " << value << endl;
            vector.insert(value, pos);
            vector.print();
            break;
        case 6:
            cout << "Removendo repetições" << endl;
            vector.removeRepeat();
            vector.print();
            break;
        case 7:
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