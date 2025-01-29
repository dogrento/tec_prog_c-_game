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
protected:
    Gerenciador_Colisoes gerenciadorColisoes;
    ListaEntidades LEs; 
    //vector<Obstaculo*> lOsbtaculo;
    int totalEntidades;
    //Jogador* pJogador; // futuramente sera um lista 

public:
    Fase(int totalEntidades_):
        gerenciadorColisoes(),
        // pObstaculo(nullptr),
	LEs(), totalEntidades(totalEntidades_),  Ente()
    {

    };
    virtual ~Fase(){
     
    };
    // vector<Obstaculo*> getObstaculoList()const{return lOsbtaculo;};
    void addObstaculo(Obstaculo* obstaculo_){
        //lOsbtaculo.push_back(obstaculo_);
    };
 
    virtual void criarInimFaceis() = 0; 
    virtual void criarPlataformas() {
		Plataforma *p = new Plataforma(sf::Vector2f(400.f, 20.f), sf::Vector2f(50.f, 400.f));
		LEs.incluir(p);
		gerenciadorColisoes.adicionarObstaculo(p);	 

		Plataforma *p1 = new Plataforma(sf::Vector2f(300.f, 20.f), sf::Vector2f(500.f, 300.f));;		
		LEs.incluir(p1);
		gerenciadorColisoes.adicionarObstaculo(p1);
    } 
    virtual void criarObstaculos() = 0;
    virtual void set_Jogador(Jogador *j) = 0;
    virtual void init() = 0;
    virtual void atualizar() = 0;
    virtual void desenhar() = 0;
    virtual void exec()  {
	LEs.percorrer();
	gerenciadorColisoes.exec();
	
    }
};
