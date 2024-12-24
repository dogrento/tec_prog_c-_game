#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

#include "Gerenciadores/Atribuidor_Figuras.hpp"
#include "Gerenciadores/Gerenciador_Grafico.hpp"

class Gerenciador_Grafico;

/*
    CLASSE ABSTRATA.
*/
class Ente{
protected:
    int id;
    Gerenciador_Grafico* pGG; // Seguindo Singleton, nao sera necessario que seja static??
    Atribuidor_Figuras* pFig;
    // sf::RectangleShape* pFig;

public:
    Ente();
    ~Ente();
    virtual void executar() = 0; // virtual puro. DEVE SER DEFINIDA EM SUAS DERIVADAS
    virtual void atualizar() = 0;
    void desenhar();

    Gerenciador_Grafico* getInstancia(){
        return pGG;
    };

    void setID(const int id_);
    int getID() const;

    void setFig(sf::Vector2f tam = sf::Vector2f(50.f, 50.f));
    Atribuidor_Figuras* getFig()const;
};