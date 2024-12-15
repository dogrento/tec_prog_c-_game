#pragma once

#include "Entes/Entidade.hpp"

// o principio estou contruindo considerando uma plataforma que é
// lidada pela Fase
// classe obstaculo deve ser abstrata
class Obstaculo: public Entidade{
private:
    bool danoso; // attr para classe abstrata
    sf::Vector2f tam; // attr 

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