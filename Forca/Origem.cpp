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
	  
	string listas[10];
	char letra[1];

	int chances = 5, 
		acertos = 0, 
		i = 0,
		tamanho = 0;

	bool acerto = false;
	
	string palavra = lista[rand() % 10];
	
	while (palavra[i] != '\0')
	{
		i++;
		tamanho++;
	}

	for (i = 0; i < 10; i++)
	{
		listas[i] = '*';
	}

	while (chances > 0 && acertos < tamanho)
	{
		cout << "Chances: " << chances << endl
			<< "Palavra: " << endl;
		for (i = 0; i < tamanho; i++)
		{
			cout << listas[i];
		}
		cout << "\n-----------------"
			<<"\nDigite uma letra: ";
		cin >> letra[0];

		for (i = 0; i < tamanho; i++)
		{
			if (palavra[i] == letra[0])
			{
				acerto = true;
				listas[i] = palavra[i];
				acertos++;
			}
		}
		if (!acerto)
		{
			chances--;
		}
		acerto = false;
	}
	
	if (acertos == tamanho)
	{
		cout << "\n-----------------------"
			<< "\nVocê acertou a palavra." << endl;
	}
	else
	{
		cout << "\n----------------------"
			<< "\nVocê errou a palavra." << endl;
	}

	return 0;
}