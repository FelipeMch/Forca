#pragma once
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

class Jogo
{
private:
	string lista[20] = { "jogar", "cometa", "mala", "polvo", "nariz", "lagarto", "limpo", "serpente", "frio", "carro", "caranguejo", "fino", "novo", "pulso", "vaca", "pele", "pimenta", "teto", "chuva", "cereja" }; // lista de palavras

	string listaC[20]; // lista de controle para comparar com a palavra que foi sorteada
	char letra[1];  // armazena a tentativa do jogador e compara com a listaC para saber se � igual ou n�o � letra do vetor 
	char opcao,
		cre,
		nLetra; // armazena a decis�o do jogador (quer ou n�o jogar de novo)

	// define alguns valores para o in�cio do jogo
	int chances = 5,
		acertos = 0,
		i = 0,
		tamanho = 0,
		menuJ,
		pontos = 0,
		menuV[13][7];

	bool acerto = false,
		l = false;

public:
	void menu();
	void jogo();
	void encerrar();
	void creditos();

};

