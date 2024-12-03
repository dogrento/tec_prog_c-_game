#pragma once

#include <SFML/Graphics.hpp>
#include "src/jogo.h"

/*
    Classe Principal.
*/
class Jogo{
private:
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event event;
    // sf::CircleShape shape;

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