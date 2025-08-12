#include <stdio.h>
#include <iostream>
using namespace std;

void decorate(int x){
    cout<<endl;
    for(int i = 0; i<x;i++){
        cout<<"=-=";
    }
    cout<<endl;
}

int main(){
    int decoNum = 20;
    decorate(decoNum);
    int questao;

    cout<<"\tDigite uma questão de 1 a 15 a ser executada\t"<<endl;
    cin>>questao;


    if(questao==1){
    //QUESTAO 1
        int num, soma, i;
        soma = 0;
        num = 0;
        i=0;

        while(num >=0){
            soma = soma + num;
            i++;
            cout<<"digite um numero inteiro para ser somado ou um numero negativo para finalizar"<<endl;
            cin>>num;
        }
        cout<< i <<" numeros foram digitados"<<endl;
        cout<<"A soma dos numeros eh "<<soma<<endl;
    }else if(questao ==2){
//QUESTAO 2
        int num =0;
        int contadorDiv =0; //contador de divisores  
        int aux ;
        cout<<"Digite um numero inteiro positivo"<<endl;
        cin>>num;

        if(num <0){
            cout<<"numero invalido! ";
        }else{
            aux = num;
            while(aux >0){
                if(num%aux == 0){
                    contadorDiv +=1;
                }
                aux -=1;
            }
            if((contadorDiv-2) ==0){//exclui os numeros primos, pois eles sao divisiveis por 1 e eles mesmos
                cout<<"o numero "<<num<<" e primo!"<<endl;
            }else{
                cout<<"o numero "<<num<< " tem "<<contadorDiv<<" divisores";
            }
        }
    }else if(questao ==3){
//QUESTAO 3
        string senha ="algoritmo123";
        string chute = " ";
        int tentativas=3;
        while(tentativas >0){
            cout<<"qual e a senha?"<<endl;
            cin>>chute;
            if(chute == senha){
                cout<<"senha corrreta!"<<endl;
                return 0;
            }else{
                tentativas -=1;
                cout<<"senha Incorreta! "<<tentativas<<" tentativas restantes"<<endl;
            }
            cout<<"Acesso Negado!";

        }
    }else if(questao ==4){
//QUESTAO 4
        int num, fat;
        cout<<"digite um numero inteiro e maior que 0"<<endl;
        cin>>num;
        if(num ==0 || num <0){
            cout<<"Numero invalido!!!"<<endl;
        }else{
            cout<<num<<"! = ";
            fat = 1;
            while(num>1){
                fat = fat * num;
                cout<<num<<" * ";
                num -=1;
            }
            cout<<num<<" = "<<fat;
        }

    }else if(questao == 5){
//QUESTAO 5
        int num,soma,aux;
        cout<<"digite um numero inteiro ";
        cin>>num;
        cout<<"Soma = ";
        aux = num;
        while(aux > 0){
            if(aux % 2 == 0){
                soma -=aux;
                cout<<" - "<<num - aux+1;
            }if(aux % 2 != 0){
                soma +=aux;
                cout<<" + "<<num - aux+1;
            }
            aux-=1;
        }
        cout<<"\nSOMA = "<<soma<<endl;
    } else if(questao ==6){
//QUESTAO 6
        int num ;
        cout<<"Digite a quantidade de termos da serie "<<endl;
        cin>>num;
        while(num = 0){

        }

    }

    return 0;
}