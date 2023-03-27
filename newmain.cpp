/**
    Estrutura inicial para um jogo de labirinto
    versão: 0.1 (Felski)
*/
#include <iostream>
#include<windows.h>
#include<conio.h>
#include "projeto.cpp"

using namespace std;



int main()
{
    naoPisca();

    int m[10][10]={ 0,0,0,1,1,1,1,1,0,0,
					1,1,1,1,0,0,0,1,0,0,
					1,0,0,3,5,4,0,1,0,0,
					1,0,0,0,0,0,1,1,0,0,
					1,0,0,1,1,1,1,1,0,0,
					1,1,1,1,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,0,0 };

    //Posi��o inicial do personagem no console
    int x=1, y=4;
    //Vari�vel para tecla precionada
    char tecla;

    while(true){
        ///Posiciona a escrita no início do console
        reposicionaCursor();

        imprimeMapaPersonagem(m,x,y);


		executaMovimentos(tecla, m ,x ,y );
    }
    return 0;
} //fim main

    
