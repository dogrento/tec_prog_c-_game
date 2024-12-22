#pragma once

#include <vector>
#include <iostream>
using namespace std;

#include "Gerenciadores/Gerenciador_Colisao.hpp"
#include "Listas/ListaEntidades.hpp"
#include "Ente.hpp"
#include "Entes/Entidades/Jogador.hpp"
#include "Entes/Entidades/Obstaculo.hpp"
#include "Entes/Entidades/Obstaculos/Plataforma.hpp"

class Fase:public Ente{
private:
    Gerenciador_Colisoes gerenciadorColisoes;
    ListaEntidades LEs; 
    //vector<Obstaculo*> lOsbtaculo;
    Jogador* pJogador; // futuramente sera um lista 

public:
    Fase(int totalEntidades):
        gerenciadorColisoes(),
        // pObstaculo(nullptr),
	LEs(),
        pJogador(nullptr)
    {
	    init();
    };
    ~Fase(){
     // 
    };
    // vector<Obstaculo*> getObstaculoList()const{return lOsbtaculo;};
    void addObstaculo(Obstaculo* obstaculo_){
        lOsbtaculo.push_back(obstaculo_);
    };
 
    void criarInimFaceis() = 0; 
    void criarPlataformas(Plataforma *plataforma) = 0; 
    void criarObstaculos(Obstaculo *obstacul) = 0;
    virtual void init(){
        cout << "Inicializando fase" << endl;
        //--atual//gerenciadorColisoes.adicionarEntidade(pJogador);
        //--comentario mais antigo// pObstaculo.push_back(pObstaculo);
	    for(int i = 0; i < totalEntidades; i++) {
		Entidade *pEntidade = new Ente();
		if(pEntidade != NULL) {
			LEs.incluir(pEntidade);
		}
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
    void atualizar() = 0;
    void desenhar() = 0;
    void exec() = 0;
    void setInicialPosJogadores(){pJogador->setPosicao(sf::Vector2f(0.f, 200.f));};
    // void setInicialPosObstaculos(){pObstaculo->setPosicao(sf::Vector2f(0.f, 500.f));};
    void initObstaculos(){}; //futuramente, virtual puro
};
