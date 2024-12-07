#pragma once
#include <iostream>
#include <fstream>
#include <cstdio>
#include <SFML/Window/Keyboard.hpp>
#include "Personagem.hpp"


class Gerenciador_Entradas {
	private:
		//Movimento_Peculiar *comandoW;
		//Movimento_Peculiar *comandoA;
		//Movimento_Peculiar *comandoD;
		//Movimento_Peculiar *comandoS;
	public:
		Gerenciador_Entradas();
		~Gerenciador_Entradas();
		//Movimento_Peculiar* Conecta_Comandos();
		Personagem* Lidar_Entrada(sf::Keyboard::Key comando, Personagem *p);
};
