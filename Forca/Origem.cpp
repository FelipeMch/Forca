/*
* Programa: Jogo de adivinha��o para crian�as
* Data de cria��o: 05/10/2020
* Autor: Felipe Machado (https://github.com/FelipeMch) 
* Vers�o: 1.0
* 
*/

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

int main()
{

	setlocale(LC_ALL, "ptb");

	srand(time(0)); // zerando o random, se n�o fizer isso ele sempre vai dar o mesmo n�mero

	string lista[20] = { "jogar", "cometa", "mala", "polvo", "nariz", "lagarto", "limpo", "serpente", "frio", "carro", "caranguejo", "fino", "novo", "pulso", "vaca", "pele", "pimenta", "teto", "chuva", "cereja" }; // lista de palavras

	string listaC[20]; // lista de controle para comparar com a palavra que foi sorteada
	char letra[1];  // armazena a tentativa do jogador e compara com a listaC para saber se � igual ou n�o � letra do vetor 
	char opcao, // armazena a decis�o do jogador (quer ou n�o jogar de novo)
		nLetra; 

	// define alguns valores para o in�cio do jogo
	int chances = 5,
		acertos = 0,
		i = 0,
		tamanho = 0;

	bool acerto = false,
		l = false;

	string palavra = lista[rand() % 20];// sorteia uma palavra do vetor de 0 at� 20

	do {

		while (palavra[i] != '\0') // enquanto for diferente de ENTER (\0) segue o jogo
		{
			i++;
			tamanho++;
		}

		for (i = 0; i < 20; i++)
		{
			listaC[i] = '*'; // substitui as letras da palavra por "*"
		}

		while (chances > 0 && acertos < tamanho) // aqui come�a a interface interativa
		{


			cout << "Chances: " << chances << endl
				<< "Palavra: " << endl;
			for (i = 0; i < tamanho; i++)
			{
				cout << listaC[i];
			}

			do {
				cout << "\n-----------------"
					<< "\nDigite uma letra: ";
				cin >> letra[0];

				letra[0] = tolower(letra[0]);

				if (isalpha(letra[0]) != 0)
				{
					l = true;
				}
				else
				{
					cout << "\nTente uma letra ^_^ : ";
					cin >> nLetra;

					if (chances < 5)
					{
						chances++;
					}
					else
					{
						letra[0] = nLetra;
					}

				}
			} while (l == false);

			for (i = 0; i < tamanho; i++)
			{
				if (palavra[i] == letra[0])
				{
					acerto = true;
					listaC[i] = palavra[i];
					acertos++;
				}
			}
			if (!acerto)
			{
				chances--;
			}
			acerto = false;

			system("cls");
		}


		cout << "\n-------------------------------";

		if (acertos == tamanho)
		{
			cout << "\nVoc� acertou a palavra ";
		}
		else
		{
			cout << "\nVoc� errou a palavra ";
		}

		cout << "'" << palavra << "'" << endl;

		do
		{
			cout << "\nDeseja jogar de novo? (S/N)\n "; // menu para o jogador jogar de novo ou n�o
			cin >> opcao;

			opcao = toupper(opcao);

			if (opcao != 'S' && opcao != 'N')
			{
				cout << "\nDigite S ou N!\n";
			}

			// zera as op��es para o in�cio
			palavra = lista[rand() % 20];
			chances = 5;
			acertos = 0;
			i = 0;
			tamanho = 0;

		} while (opcao != 'S' && opcao != 'N');

		system("cls");

	} while (opcao == 'S');

	return 0;
}