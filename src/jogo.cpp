#include "jogo.h"

void Jogo::initVars()
{
}

void Jogo::initWindow()
{
    videoMode.height = 200;
    videoMode.width = 200;
    window = new sf::RenderWindow(videoMode, "SFML works!");
    forma.setFillColor(sf::Color::Green);
}

Jogo::Jogo() : 
window(nullptr),
videoMode(),
event(),
jogador(0.1f, 0.1f, 30.0f, 30.0f)
{
    initWindow();
}

Jogo::~Jogo()
{
    delete window;
}

void Jogo::exec()
{
    while(isRunning()){
        update();
        render();
    }
}

const bool Jogo::isRunning() const
{
    return window->isOpen();
}

void Jogo::pollEvents()
{
    while(window->pollEvent(event)){
        if (event.type == sf::Event::Closed) {
            window->close();
    	}
	Jogador *pj = NULL;
	pj =(Jogador*)GE->Lidar_Entrada(&jogador);


    }
}

void Jogo::update()
{
    pollEvents();
}

void Jogo::render()
{
    window->clear();
    //jogador.mover(0.0f, 0.0f);
    
    window->draw(jogador.Get_Corpo());
    window->display();
}
