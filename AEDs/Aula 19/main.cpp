#include <iostream>
#include <stdio.h>
#include <fstream>
const int SIZE = 5;
using namespace std;
typedef struct
{
    string nome;
    string email;
    string cidade;
    string celular;

} TAmigo;
void print(TAmigo *agenda, int pos)
{
    if (pos == -1)
    {
        for (int i = 0; i < SIZE; i++)
        {
            cout << "CONTATO " << i + 1 << ": " << endl;
            cout << "nome: " << agenda[i].nome << endl;
            cout << "email: " << agenda[i].email << endl;
            cout << "cidade: " << agenda[i].cidade << endl;
            cout << "celular: " << agenda[i].celular << endl
                 << endl;
        }
    }
    else
    {
        cout << "CONTATO " << pos + 1 << ": " << endl;
        cout << "nome: " << agenda[pos].nome << endl;
        cout << "email: " << agenda[pos].email << endl;
        cout << "cidade: " << agenda[pos].cidade << endl;
        cout << "celular: " << agenda[pos].celular << endl
             << endl;
    }
}
int main()
{
    //--------------------------------------------VARIAVEIS--------------------------------------------//

    TAmigo agenda[SIZE];
    int choice, subChoice, pos;
    string change;
    bool isRunning = true;

    //---------------------------------------ABRINDO ARQUIVOS------------------------------------------//
    ifstream ArquivoEntrada("/home/2025.1.08.011/Documents/AEDs/Aula 19/data.txt");
    if (!ArquivoEntrada.is_open())
    {
        cerr << "Erro ao abrir o arquivo." << std::endl;
        return 1;
    }
    /*ofstream ArquivoSaida("/home/2025.1.08.011/Documents/AEDs/Aula 19/data.txt");
    if (!ArquivoSaida.is_open())
    {
        cerr << "Erro ao abrir o arquivo." << std::endl;
        return 1;
    }*/
    //--------------------------------------PREENCHENDO O VETOR----------------------------------------//
    for (int i = 0; i < SIZE; i++)
    {
        ArquivoEntrada >> agenda[i].nome;
        ArquivoEntrada >> agenda[i].email;
        ArquivoEntrada >> agenda[i].cidade;
        ArquivoEntrada >> agenda[i].celular;
    }
    ArquivoEntrada.close();

    //--------------------------------------------MENU--------------------------------------------//
    while (isRunning)
    {
        cout << "\t\t\tAGENDA" << endl;
        cout << "opções: " << endl;
        cout << "[1] vizualizar agenda" << endl;
        cout << "[2] editar agenda" << endl;
        cout << "[outro] sair" << endl;
        cin >> choice;
        system("clear");
        system("cls");
        switch (choice)
        {
        case 1:

            print(agenda, -1);

            break;
        case 2:
            while (subChoice != -1)
            {
                cout << "\t\t\tEDICAO" << endl;
                cout << "Escolha o contato a ser editado: " << endl;
                cin >> pos;
                print(agenda, pos - 1);
                cout << "O que deseja editar: " << endl;
                cout << "[1] nome" << endl;
                cout << "[2] email" << endl;
                cout << "[3] cidade" << endl;
                cout << "[4] telefone" << endl;
                cout << "[outro] retornar" << endl;
                cin >> subChoice;
                switch (subChoice)
                {
                case 1:
                    cout << "Digite o novo nome: " << endl;
                    cin >> change;
                    agenda[pos].nome = change;
                    break;
                case 2:
                    cout << "Digite o novo email: " << endl;
                    cin >> change;
                    agenda[pos].email = change;
                    break;
                case 3:
                    cout << "Digite o nova cidade: " << endl;
                    cin >> change;
                    agenda[pos].cidade = change;
                    break;
                case 4:
                    cout << "Digite o novo telefone: " << endl;
                    cin >> change;
                    agenda[pos].celular = change;
                    break;
                default:
                    subChoice = -1;
                    break;
                }
            }

            break;
        default:

            cout << "FIM";
            isRunning = false;

            break;
        }
    }

    //--------------------------------------------VARIAVEIS--------------------------------------------//

    return 0;
}