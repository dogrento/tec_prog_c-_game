#pragma once

#include "Entidade.hpp"

class Obstaculo: public Entidade{
private:
    bool danoso;

public:
    Obstaculo(sf::Vector2f tamanho, sf::Vector2f pos): 
        Entidade(tamanho, pos),
        danoso(false)
    {};
    ~Obstaculo(){};
    void exec(){
        desenhar();
    };
    bool getDanoso()const{return danoso;}
    void setDanoso(){danoso = !danoso;}
};