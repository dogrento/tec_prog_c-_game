#pragma once

#include <iostream>
using namespace std;

#include "Entes/Entidade.hpp"

/*
    CLASSE ABSTRATA / DERIVADA DE ENTIDADE
*/
class Personagem: public Entidade{
protected:
    int num_vidas;

public:
    Personagem();
    ~Personagem();

    virtual void executar() = 0;
    virtual void atualizar(){};
    virtual void salvar() = 0;
    virtual void salvarBufferData();
    virtual void mover();

    void setVidas(int v);
    int getVidas() const;
};