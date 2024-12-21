#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

#include "Ente.hpp"

/*
    CLASSE ABSTRATA / DERIVADA DE ENTE
*/
class Entidade: public Ente{
protected:
    sf::Vector2f posicao; // attr -> pos.x pos.y
    sf::Vector2f velocidade; // attr -> pos.x pos.y
    // ostream buffer;
public:
    Entidade();
    virtual ~Entidade();

    virtual void executar() = 0; // DEVE SER DEFINIDA EM SUAS DERIVADAS
    virtual void atualizar();
    virtual void salvar()   = 0; // DEVE SER DEFINIDA EM SUAS DERIVADAS
    virtual void salvarBufferData(); 

    void         setPosicao(const sf::Vector2f pos_);
    sf::Vector2f getPosicao()const;
    void         setVelocidade(const sf::Vector2f vel_);
    sf::Vector2f getVelocidade()const;
};
