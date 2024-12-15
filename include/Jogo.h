#pragma once

#include <SFML/Graphics.hpp>

// include de Gerenciadores
#include "Gerenciadores/Gerenciador_Grafico.hpp"
#include "Gerenciadores/Gerenciador_Entradas.hpp"

// include de Entes
#include "Entes/Entidades/Jogador.hpp"
#include "Entes/Entidades/Obstaculo.hpp"
#include "Entes/Fase.hpp"

/*
    Classe Principal.
*/
class Jogo{
private:
    Gerenciador_Grafico* GG;
    // sf::RectangleShape ret; // possivelmente o objeto entidades estariam aqui.
    Fase fase1;
    Jogador j;
    // Obstaculo obstaculo;

public:
    Jogo(): 
        GG(nullptr),
        fase1(),
        j(sf::Vector2f(50.f, 50.f), sf::Vector2f(10.f, 10.f))
        // obstaculo(sf::Vector2f(50.f, 50.f), sf::Vector2f(500.f, 500.f))
    {
        GG = Gerenciador_Grafico::getInstancia();
        fase1.setJogadores(&j);
        fase1.setObstaculos();
        fase1.init();
    };
    ~Jogo(){};
    void exec();
};