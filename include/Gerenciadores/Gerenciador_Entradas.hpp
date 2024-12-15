#pragma once
#include <iostream>
#include <fstream>
#include <cstdio>
#include <SFML/Window/Keyboard.hpp>
#include "Entes/Entidades/Personagem.hpp"

// MUDAR PARA GERENCIADOR DE EVENTOS

class Gerenciador_Entradas {
	private:
		//Movimento_Peculiar *comandoW;
		//Movimento_Peculiar *comandoA;
		//Movimento_Peculiar *comandoD;
		//Movimento_Peculiar *comandoS;
	public:
		Gerenciador_Entradas(){};
		~Gerenciador_Entradas(){};
		//Movimento_Peculiar* Conecta_Comandos();
		Personagem* Lidar_Entrada(Personagem *p){return p;};
};
