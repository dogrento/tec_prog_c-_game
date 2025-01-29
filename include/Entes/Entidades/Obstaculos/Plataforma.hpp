#pragma once
#include "Entes/Entidades/Obstaculo.hpp"

class Plataforma : public Obstaculo {
	private:
	   float massa;
	
	public:
    Plataforma(sf::Vector2f tamanho, sf::Vector2f pos)
        : Obstaculo(tamanho, pos, false), // Inicializa como não danosa
        massa(400.0f) {
	
	}

    ~Plataforma(){};	
};
