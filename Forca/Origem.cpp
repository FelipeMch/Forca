/*
* Programa: Jogo de adivinha��o para crian�as
* Data de cria��o: 05/10/2020
* Autor: Felipe Machado (https://github.com/FelipeMch)
* Vers�o: 2.0
*/

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <ctype.h>
#include "Jogo.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ptb");

	Jogo jogo;

	jogo.menu();

	return 0;
}