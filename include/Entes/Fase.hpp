#pragma once

#include <iostream>
using namespace std;

#include "Ente.hpp"

class Fase: public Ente{
private:
    // Gerenciado_Colisao GC;
public:
    Fase();
    ~Fase();
    virtual void executar();
    void gerenciarColisoes();
    void criarInimigosFaceis(); // mudar nome
    void criarPlataformas();
    virtual void criarInimigos() = 0;
    virtual void criarObstaculos() = 0;
    void criarCenario();

};