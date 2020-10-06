#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdlib.h>

using namespace std;

int main()
{

	setlocale(LC_ALL, "ptb");

	srand(time(0));

	string lista[10] = { "jogar", "cometa", "mala", "polvo", "nariz", "lagarto", "limpo", "serpente", "frio", "carro" }; // palavra que deve ser adivinhada

	string listaC[10];
	char letra[1];
	char opcao;

	int chances = 5,
		acertos = 0,
		i = 0,
		tamanho = 0;

	bool acerto = false;
	
	string palavra = lista[rand() % 10];

	do {

		while (palavra[i] != '\0')
		{
			i++;
			tamanho++;
		}

		for (i = 0; i < 10; i++)
		{
			listaC[i] = '*';
		}

		while (chances > 0 && acertos < tamanho)
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
			cout << "\nVocê acertou a palavra ";
		}
		else
		{
			cout << "\nVocê errou a palavra ";
		}

		cout << "'" << palavra << "'" << endl;

	do
	{
		cout << "\nDeseja jogar de novo? (S/N) ";
		cin >> opcao;

		opcao = toupper(opcao);

		if (opcao != 'S' && opcao != 'N')
		{
			cout << "\nOpção inválida!\n";
		}

		palavra = lista[rand() % 10];
		chances = 5;
		acertos = 0;
		i = 0;
		tamanho = 0;

	} while (opcao != 'S' && opcao != 'N');
	
	} while (opcao == 'S');

	return 0;
}