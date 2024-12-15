#pragma once

#include <iostream>
using namespace std;

#include "Ente.hpp"
#include "Entidades/Jogador.hpp"
#include "Entidades/Obstaculo.hpp"

class Fase:public Ente{
private:
    Obstaculo* pObstaculo; // futuramente sera um lista 
    Jogador* pJogador; // futuramente sera um lista 

public:
    Fase():
        pObstaculo(nullptr),
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
    void setObstaculos(){
        cout << "Setting Obstaculo na fase." << endl;
        pObstaculo = new Obstaculo(sf::Vector2f(500.f, 50.f), sf::Vector2f(0.f, 500.f));
        // setInicialPosObstaculos();
    };
    void atualizar(){pJogador->atualizar();pObstaculo->atualizar();};
    void desenhar(){pJogador->desenhar();pObstaculo->desenhar();};
    void exec(){atualizar();desenhar();}
    void setInicialPosJogadores(){pJogador->setPosicao(sf::Vector2f(0.f, 200.f));};
    // void setInicialPosObstaculos(){pObstaculo->setPosicao(sf::Vector2f(0.f, 500.f));};
    void initObstaculos(){}; // futuramente, virtual puro
};