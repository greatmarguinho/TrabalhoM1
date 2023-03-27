#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

void naoPisca()
{
	/// ALERTA: N�O MODIFICAR O TRECHO DE C�DIGO, A SEGUIR.
	// INICIO: COMANDOS PARA QUE O CURSOR N�O FIQUE PISCANDO NA TELA
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
	// FIM: COMANDOS PARA QUE O CURSOR N�O FIQUE PISCANDO NA TELA
}

void reposicionaCursor()
{
	// IN�CIO: COMANDOS PARA REPOSICIONAR O CURSOR NO IN�CIO DA TELA
	short int CX = 0, CY = 0;
	COORD coord;
	coord.X = CX;
	coord.Y = CY;
	// FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO IN�CIO DA TELA
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void mapaMicrobaniv()
{
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
}

void imprimeMapaPersonagem(int m[10][10], int x, int y)
{
	/// Imprime o jogo: mapa e personagem.
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i == x && j == y)
			{
				cout << char(2); // personagem
			}
			else
			{
				switch (m[i][j])
				{
				case 0:
					cout << " ";
					break; // caminho
				case 1:
					cout << char(219);
					break; // parede
				case 3:
					cout << char(67);
					break; // caixa
				case 4:
					cout << char(79);
					break; // posicao final
				case 5:
					cout << char(88);
					break; // caixa na posicao final
						   // default: cout<<"-"; //erro
				}		   // fim switch
			}
		}
		cout << "\n";
	} // fim for mapa
}

int executaMovimentos(char tecla, int m[10][10], int x, int y)
{
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
	return x, y;
}

/*void funcaoWhile(int m[10][10], int x, int y)
{
	while (true)
	{
		/// Posiciona a escrita no início do console
		reposicionaCursor();

		/// Imprime o jogo: mapa e personagem.
		imprimeMapaPersonagem(m, x, y);

		executaMovimentos(m, x, y);

	} // fim main
}*/