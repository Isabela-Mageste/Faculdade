#include <stdio.h>
#include <iostream>

using namespace std;

void decorate(int x)
{
    cout << endl;
    for (int i = 0; i < x; i++)
    {
        cout << "-=-";
    }
    cout << endl;
}
int main()
{
    int decoNum = 20;
    char nome[16], sobrenome[16], nomeCompleto[32];

    { // nome
        nome[0] = 'I';
        nome[1] = 's';
        nome[2] = 'a';
    }
    { // sobrenome
        sobrenome[0] = 'M';
        sobrenome[1] = 'a';
        sobrenome[2] = 'g';
        sobrenome[3] = 'e';
        sobrenome[4] = 's';
        sobrenome[5] = 't';
        sobrenome[6] = 'e';
    }
    for (int i = 0; i < 3; i++)
    {
        nomeCompleto[i] = nome[i];
    }
    nomeCompleto[3] = ' ';
    for (int i = 0; i < 7; i++)
    {
        nomeCompleto[i + 4] = sobrenome[i];
    }
    decorate(decoNum);
    cout << nome << endl;
    cout << sobrenome << endl;
    cout << nomeCompleto << endl;

    for (int i = 0; i < 32; i++)
    {
        nomeCompleto[i] = toupper(nomeCompleto[i]);
    }
    cout << nomeCompleto << endl;
    for (int i = 0; i < 32; i++)
    {
        nomeCompleto[i] = tolower(nomeCompleto[i]);
    }

    for (int i = 0; i < 32; i++)
    {
        if (nomeCompleto[i] == ' ')
        {
            nomeCompleto[i] = nomeCompleto[i + 1];
            nomeCompleto[i + 1] = ' ';
        }
    }
    // procurar nome em nome

    for (int i = 0; i < 32; i++)
    {
        if (nomeCompleto[i] == 'e')
        {
            if (nomeCompleto[i+1] == 's')
            {
                if (nomeCompleto[i+2] == 't')
                {
                    if (nomeCompleto[i+3] == 'e')
                    {
                        cout << " ENCONTRADO" << endl;
                    }
                }
            }
        }
    }

    return 0;
}