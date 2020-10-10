#include "Jogo.h"
void Jogo::menu()
{
	do {
		cout
			<< "\n--Bem-Vindo--" << endl
			<< "Jogo da forca" << endl
			<< "\n"
			<< "  1- Jogar" << endl
			<< "  2- Sair" << endl
			<< "  3- Créditos" << endl;
		cin >> menuJ;


		switch (menuJ)
		{
		case 1:
			system("cls");
			jogo();
			break;
		case 2:
			system("cls");
			encerrar();
			break;
		case 3:
			system("cls");
			creditos();
			break;
		default:
			system("cls");

			cout << "Selecione um item do menu!" << endl;
		}
	} while (menuJ != 1 && menuJ != 2 && menuJ != 3);
}

void Jogo::jogo()
{
	setlocale(LC_ALL, "ptb");

	srand(time(0)); // zerando o random, se não fizer isso ele sempre vai dar o mesmo número

	string palavra = lista[rand() % 20];// sorteia uma palavra do vetor de 0 até 20

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

		while (chances > 0 && acertos < tamanho) // aqui começa a interface interativa
		{


			cout << "Chances: " << chances << endl
				<< "Palavra: " << endl << endl;
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
					do {
						system("cls");
						cout << "\nTente uma letra ^_^ :";
						cin >> nLetra;

						if (chances < 5)
						{
							letra[0] = nLetra;
							chances++;

							if (isalpha(letra[0]) != 0)
							{
								l = true;
							}
						}
						else
						{
							letra[0] = nLetra;

							if (isalpha(letra[0]) != 0)
							{
								l = true;
							}

						}
					} while (l == false);

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
			cout << "\nVocê acertou a palavra ";
			pontos++;
		}
		else
		{
			cout << "\nA palavra era: ";
		}

		cout << "'" << palavra << "'" << endl;

		do
		{
			cout << "\nDeseja jogar de novo? (S/N)\n "; // menu para o jogador jogar de novo ou não
			cin >> opcao;

			opcao = toupper(opcao);

			if (opcao != 'S' && opcao != 'N')
			{
				cout << "\nDigite S ou N!\n";
			}
			else if (opcao == 'S') {

				pontos = pontos;
				// zera as opções para o início
				palavra = lista[rand() % 20];
				chances = 5;
				acertos = 0;
				i = 0;
				tamanho = 0;
			}
			else
			{
				system("cls");
				if (pontos > 1) {
					cout << "\nParabéns você acertou " << pontos << " Palavras!" << endl;
				}
				else if (pontos == 1)
				{
					cout << "\nParabéns você acertou " << pontos << " Palavra!" << endl;
				}
				else
				{
					cout << "\nHm mais sorte da próxima vez..." << endl;
				}
				encerrar();
			}

		} while (opcao != 'S' && opcao != 'N');

		system("cls");

	} while (opcao == 'S');

}

void Jogo::encerrar()
{
	exit(0);
}

void Jogo::creditos()
{
	cout << "\nJogo feito por Felipe Machado\n"
		<< "em seu tempo livre dos estudos e trabalho =)\n\n";

	do {
		cout << "Voltar ao menu? (S/N)";
		cin >> cre;

		cre = toupper(cre);
		if (cre == 'S')
		{
			system("cls");
			return menu();
		}
		else if (cre == 'N')
		{
			system("cls");
			encerrar();
		}
		else
		{
			cout << ("\nDigite S ou N!\n");
			system("cls");
		}
	} while (cre != 'S' && cre != 'N');
}
