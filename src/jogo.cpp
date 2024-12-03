#include "jogo.h"

void Jogo::initVars()
{
}

void Jogo::initWindow()
{
    videoMode.height = 200;
    videoMode.width = 200;
    window = new sf::RenderWindow(videoMode, "SFML works!");
}

Jogo::Jogo() : 
window(nullptr),
videoMode(),
event()
{
    initWindow();
}

Jogo::~Jogo()
{
    delete window;
}

void Jogo::exec()
{
}

const bool Jogo::isRunning() const
{
    return window->isOpen();
}

void Jogo::pollEvents()
{
    while(window->pollEvent(event)){
        if (event.type == sf::Event::Closed)
            window->close();
    }
}

void Jogo::update()
{

}

void Jogo::render()
{
}
