#pragma once

#include <SFML/Graphics.hpp>
#include "Gerenciador_Grafico.hpp"
#include "Jogador.hpp"
#include "Gerenciador_Entradas.hpp"

/*
    Classe Principal.
*/
class Jogo{
    private:
        Gerenciador_Grafico* GG;
        sf::RectangleShape ret; // possivelmente o objeto entidades estariam aqui.
    
    public:
        Jogo(): 
        GG(nullptr), 
        ret(sf::Vector2f(50.f, 50.f)) { 
            GG = Gerenciador_Grafico::getInstancia(); // Inicializa o Singleton
            ret.setFillColor(sf::Color::Green);       // Define a cor do retângulo
            ret.setPosition(200.f, 200.f);            // Define a posição inicial
        }
        ~Jogo(){};
        void exec();
};