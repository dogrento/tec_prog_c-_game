#pragma once

#include "Ente.hpp"
#include "Obstaculo.hpp"

class Fase:public Ente{
private:
    // Obstaculo obstaculo;

public:
    Fase(){};
    ~Fase(){};
    void criarObstaculo(){}; // futuramente, virtual puro
};