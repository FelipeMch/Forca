#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdlib.h>

using namespace std;

int main()
{

	setlocale(LC_ALL, "ptb");

	srand(time(0)); // zerando o random, se n�o fizer isso ele sempre vai dar o mesmo n�mero

	string lista[10] = { "jogar", "cometa", "mala", "polvo", "nariz", "lagarto", "limpo", "serpente", "frio", "carro" }; // palavra que deve ser adivinhada

	string listaC[10]; // lista de controle para comparar com a palavra que foi sorteada
	char letra[1];  // armazena a tentativa do jogador e compara com a listaC para saber se � igual ou n�o � letra do vetor 
	char opcao; // armazena a decis�o do jogador (quer ou n�o jogar de novo)

	// define alguns valores para o in�cio do jogo
	int chances = 5,
		acertos = 0,
		i = 0,
		tamanho = 0;

	bool acerto = false;
	
	string palavra = lista[rand() % 10];// sorteia uma palavra do vetor de 0 at� 10

	do {

		while (palavra[i] != '\0') // enquanto for diferente de ENTER (\0) segue o jogo
		{
			i++;
			tamanho++;
		}

		for (i = 0; i < 10; i++)
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
			cout << "\n-----------------"
				<< "\nDigite uma letra: ";
			cin >> letra[0];

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
			cout << "\nOp��o inv�lida!\n";
		}

		// zera as op��es para o in�cio
		palavra = lista[rand() % 10];
		chances = 5;
		acertos = 0;
		i = 0;
		tamanho = 0;

	} while (opcao != 'S' && opcao != 'N');
	
	} while (opcao == 'S');

	return 0;
}