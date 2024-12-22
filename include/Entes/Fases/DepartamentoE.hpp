#pragma once

#include <iostream>
using namespace std;

#include "Entes/Fase.hpp"

class DepartamentoE: public Fase{
private:
    const int maxInimMedios;
public:
    DepartamentoE();
    ~DepartamentoE(){};
    void executar(){};
    void criarInimigos(){};
    void criarInimMedios(){};
    void criarObstMedios(){};
    void criarObstaculos(){};
};