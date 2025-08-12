#include <stdio.h>
#include <iostream>
#include <time.h>
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
float generateNumber(){
    float x;
    x = 10+ rand() %11;
    x= x/10;
    return x;
}
int main()
{
    const int SIZE = 100;
    int decoNum = 20;
    srand(time(0));
    
    decorate(decoNum);
    float alturas[SIZE];
    float soma = 0;
    float media = 0.0;
    int i = 0;
    int cont = 0;
    int contadorBusca = 0;
    int contadorIntervalo = 0;
    while (i < SIZE)
    {
       /* cout << "Digite a altura da pessoa " << i + 1 << " " << endl;
        cin >> alturas[i];*/
        alturas[i] = generateNumber();
        soma += alturas[i];
        i++;
    }
    decorate(decoNum);
    media = soma / SIZE;
    i = 0;
    cout << "A media das alturas e " << media << endl;
    while (i < SIZE)
    {
        
         if(alturas[i]>=1.7 && alturas[i]<=1.8){
            if( abs(alturas[i] - 1.7) < 0.00000001){
                contadorBusca ++;
            }
            contadorIntervalo ++;
        }
        if (alturas[i] > media)
        {
            cout << "\nA altura da pessoa " << i + 1 << "( " << alturas[i] << ") esta acima da media";
            cont++;
        }
        i++;
    }
    cout<<"\n"<<cont<<" pessoas estao acima da media"<<endl;
    cout<<contadorBusca<<" pessoas tem 1.7 m "<<endl;
    cout<<contadorIntervalo<<" pessoas tem entre 1.7 m e 1.8 m ";
    decorate(decoNum);
}