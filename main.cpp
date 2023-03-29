/**
    Estrutura inicial para um jogo de labirinto
    versão: 0.1 (Felski)
*/
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "projeto.cpp"

using namespace std;

int main()
{
    naoPisca();

    int m[10][10] = {0, 0, 0, 1, 1, 1, 1, 1, 0, 0,
                     1, 1, 1, 1, 0, 0, 0, 1, 0, 0,
                     1, 0, 0, 3, 5, 4, 0, 1, 0, 0,
                     1, 0, 0, 0, 0, 0, 1, 1, 0, 0,
                     1, 0, 0, 1, 1, 1, 1, 1, 0, 0,
                     1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // Posi��o inicial do personagem no console
    int x = 1, y = 4;
    // Vari�vel para tecla precionada
    char tecla;

    while (true)
    {
        /// Posiciona a escrita no início do console
        reposicionaCursor();

        imprimeMapaPersonagem(m, x, y);

        if (_kbhit())
        {
            tecla = getch();
            switch (tecla)
            {
            case 72:
            case 'w': /// cima
                switch (m[x - 1][y])
                {
                case 0:
                    x--;
                    break;

                case 3:
                    switch (m[x - 2][y]) // acima da caixa
                    {
                    case 0:
                        m[x - 1][y] = 0;
                        m[x - 2][y] = 3;
                        x--;
                        break;

                    case 4:
                        m[x - 1][y] = 0;
                        m[x - 2][y] = 5;
                        x--;
                        break;
                    }
                    break;

                case 4:
                    x--;
                    break;

                case 5:
                    switch (m[x - 2][y]) // acima do ponto certo com a caixa
                    {
                    case 0:
                        m[x - 1][y] = 4;
                        m[x - 2][y] = 3;
                        x--;
                        break;

                    case 4:
                        m[x - 1][y] = 4;
                        m[x - 2][y] = 5;
                        x--;
                        break;
                    }
                    break;
                }
                break;

            case 80:
            case 's': /// baixo
                switch (m[x + 1][y])
                {
                case 0:
                    x++;
                    break;

                case 3:
                    switch (m[x + 2][y]) // baixo da caixa
                    {
                    case 0:
                        m[x + 1][y] = 0;
                        m[x + 2][y] = 3;
                        x++;
                        break;

                    case 4:
                        m[x + 1][y] = 0;
                        m[x + 2][y] = 5;
                        x++;
                        break;
                    }
                    break;

                case 4:
                    x++;
                    break;

                case 5:
                    switch (m[x + 2][y]) // abaixo do ponto certo com a caixa
                    {
                    case 0:
                        m[x + 1][y] = 4;
                        m[x + 2][y] = 3;
                        x++;
                        break;

                    case 4:
                        m[x + 1][y] = 4;
                        m[x + 2][y] = 5;
                        x++;
                        break;
                    }
                    break;
                }
                break;

            case 75:
            case 'a': /// esquerda
                switch (m[x][y - 1])
                {
                case 0:
                    y--;
                    break;

                case 3:
                    switch (m[x][y - 2]) // esquerda da caixa
                    {
                    case 0:
                        m[x][y - 1] = 0;
                        m[x][y - 2] = 3;
                        y--;
                        break;

                    case 4:
                        m[x][y - 1] = 0;
                        m[x][y - 2] = 5;
                        y--;
                        break;
                    }
                    break;

                case 4:
                    y--;
                    break;

                case 5:
                    switch (m[x][y - 2]) // esquerda do ponto certo com a caixa
                    {
                    case 0:
                        m[x][y - 1] = 4;
                        m[x][y - 2] = 3;
                        y--;
                        break;

                    case 4:
                        m[x][y - 1] = 4;
                        m[x][y - 2] = 5;
                        y--;
                        break;
                    }
                    break;
                }
                break;

            case 77:
            case 'd': /// direita
                switch (m[x][y + 1])
                {
                case 0:
                    y++;
                    break;

                case 3:
                    switch (m[x][y + 2]) // direita da caixa
                    {
                    case 0:
                        m[x][y + 1] = 0;
                        m[x][y + 2] = 3;
                        y++;
                        break;

                    case 4:
                        m[x][y + 1] = 0;
                        m[x][y + 2] = 5;
                        y++;
                        break;
                    }
                    break;

                case 4:
                    y++;
                    break;

                case 5:
                    switch (m[x][y + 2]) // direita do ponto certo com a caixa
                    {
                    case 0:
                        m[x][y + 1] = 4;
                        m[x][y + 2] = 3;
                        y++;
                        break;

                    case 4:
                        m[x][y + 1] = 4;
                        m[x][y + 2] = 5;
                        y++;
                        break;
                    }
                    break;
                }
                break;
            }
        } // fim do if
    }
    return 0;
} // fim main
