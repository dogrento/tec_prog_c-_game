#pragma once

#include <iostream>
using namespace std;

#include "Ente.hpp"
#include "Entidades/Jogador.hpp"
#include "Entidades/Obstaculo.hpp"

class Fase:public Ente{
private:
    // Obstaculo obstaculo;
    Jogador* pJogador;

public:
    Fase():
        pJogador(nullptr)
    {};
    ~Fase(){};
    void setJogadores(Jogador* pJ){
        cout << "Setting Jogador na fase." << endl;
        if(pJ){
            pJogador = pJ;
            setInicialPosJogadores();
        }else{
            cerr << "Ponteiro para jogador NULO!" << endl;
        }
    };
    void atualizar(){pJogador->atualizar();};
    void desenhar(){pJogador->desenhar();};
    void setInicialPosJogadores(){pJogador->setPosicao(sf::Vector2f(0.f, 200.f));};
    void initObstaculos(){}; // futuramente, virtual puro
};