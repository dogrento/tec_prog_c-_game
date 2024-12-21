#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

#include "Gerenciadores/Gerenciador_Grafico.hpp"

class Gerenciador_Grafico;

/*
    CLASSE ABSTRATA.
*/
class Ente{
protected:
    int id;
    Gerenciador_Grafico* pGG; // Seguindo Singleton, nao sera necessario que seja static??
    // Figura* pFIg;
    sf::RectangleShape* pFig;

public:
    Ente();
    ~Ente();
    virtual void executar() = 0; // virtual puro. DEVE SER DEFINIDA EM SUAS DERIVADAS
    virtual void atualizar() = 0;
    void desenhar();

    void setID(const int id_);
    int getID() const;

    void setFig(sf::Vector2f tam = sf::Vector2f(50.f, 50.f), sf::Vector2f pos = sf::Vector2f(0.f, 0.f));
    sf::RectangleShape* getFig()const;
};