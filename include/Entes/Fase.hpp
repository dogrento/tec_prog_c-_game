#pragma once

#include <vector>
#include <iostream>
using namespace std;

#include "Gerenciadores/Gerenciador_Colisao.hpp"

#include "Ente.hpp"
#include "Entes/Entidades/Jogador.hpp"
#include "Entes/Entidades/Obstaculo.hpp"
#include "Entes/Entidades/Obstaculos/Plataforma.hpp"

class Fase:public Ente{
private:
    Gerenciador_Colisoes gerenciadorColisoes;
    // Obstaculo* pObstaculo; // futuramente sera um lista 
    vector<Obstaculo*> lOsbtaculo;
    Jogador* pJogador; // futuramente sera um lista 

public:
    Fase():
        gerenciadorColisoes(),
        // pObstaculo(nullptr),
        pJogador(nullptr)
    {};
    ~Fase(){};
    // vector<Obstaculo*> getObstaculoList()const{return lOsbtaculo;};
    void addObstaculo(Obstaculo* obstaculo_){
        lOsbtaculo.push_back(obstaculo_);
    };
    virtual void init(){
        cout << "Inicializando fase" << endl;
        gerenciadorColisoes.adicionarEntidade(pJogador);
        // pObstaculo.push_back(pObstaculo);
        for(int i = 0; i < lOsbtaculo.size(); i++){
            gerenciadorColisoes.adicionarEntidade(lOsbtaculo[i]);
        }

    };
    virtual void setJogadores(Jogador* pJ){
        cout << "Setting Jogador na fase." << endl;
        if(pJ){
            pJogador = pJ;
            setInicialPosJogadores();
        }else{
            cerr << "Ponteiro para jogador NULO!" << endl;
        }
    };
    virtual void setObstaculos() = 0;
    // virtual void setObstaculos(){
    //     cout << "Setting Obstaculo na fase." << endl;
    //     // pObstaculo = new Obstaculo(sf::Vector2f(500.f, 50.f), sf::Vector2f(0.f, 500.f));
    //     // setInicialPosObstaculos();
    //     Plataforma* plat = new Plataforma(sf::Vector2f(500.f, 50.f), sf::Vector2f(0.f, 500.f));
    //     lOsbtaculo.push_back(plat);
    // };
    void atualizar(){
        pJogador->atualizar();
        // pObstaculo->atualizar();
        for(int i = 0; i < lOsbtaculo.size(); i++){
            lOsbtaculo[i]->atualizar();
        }
    };
    void desenhar(){
        // cout << lOsbtaculo.size() << endl;
        pJogador->desenhar();
        for(int i = 0; i < lOsbtaculo.size(); i++){
            if(lOsbtaculo[i]){
                lOsbtaculo[i]->desenhar();
            }else{
                cout << "Obstaculo na lista nulo!" << endl;
            }
        }
    };
    void exec(){
        atualizar();
        desenhar();
        gerenciadorColisoes.verificarColisoes();
    }
    void setInicialPosJogadores(){pJogador->setPosicao(sf::Vector2f(0.f, 200.f));};
    // void setInicialPosObstaculos(){pObstaculo->setPosicao(sf::Vector2f(0.f, 500.f));};
    void initObstaculos(){}; // futuramente, virtual puro
};