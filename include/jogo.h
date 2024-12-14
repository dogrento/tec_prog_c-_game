#pragma once

#include <SFML/Graphics.hpp>
// #include "src/jogo.h"

/*
    Classe Principal.
*/
#include "Jogador.hpp"
#include "Gerenciador_Entradas.hpp"
class Jogo{
private:
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event event;
    sf::CircleShape forma;
    Jogador jogador;
    Gerenciador_Entradas *GE;
    void initVars();
    void initWindow();
    const bool isRunning() const;
    void pollEvents();
    void update();
    void render();
public:
    Jogo();
    virtual ~Jogo();

    void exec();

};