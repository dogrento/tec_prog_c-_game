#pragma once

#include <SFML/Graphics.hpp>

// include de Gerenciadores
#include "Gerenciador_Grafico.hpp"
#include "Gerenciador_Entradas.hpp"

// include de Entes
#include "Jogador.hpp"
#include "Obstaculo.hpp"

/*
    Classe Principal.
*/
class Jogo{
private:
    Gerenciador_Grafico* GG;
    // sf::RectangleShape ret; // possivelmente o objeto entidades estariam aqui.
    Jogador j;
    Obstaculo obstaculo;

public:
    Jogo(): 
        GG(nullptr),
        j(),
        obstaculo(sf::Vector2f(50.f, 50.f))
    {
        GG = Gerenciador_Grafico::getInstancia();
    };
    ~Jogo(){};
    void exec();
};