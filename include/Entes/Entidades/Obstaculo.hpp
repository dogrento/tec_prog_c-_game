#pragma once

#include "Entes/Entidade.hpp"

// o principio estou contruindo considerando uma plataforma que é
// lidada pela Fase
// classe obstaculo deve ser abstrata
class Obstaculo: public Entidade{
protected:
    bool danoso; // attr para classe abstrata
    sf::Vector2f tam; // attr 

public:
    Obstaculo(sf::Vector2f tamanho, sf::Vector2f pos, bool danoso_): 
        Entidade(tamanho, pos),
        danoso(danoso_)
    {};
    ~Obstaculo(){};
    virtual void exec() = 0; 
    // void exec(){
    //     desenhar();
    // };
    bool getDanoso()const{return danoso;}
    void setDanoso(){danoso = !danoso;}
};
