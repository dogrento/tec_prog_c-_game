#pragma once

#include <iostream>
using namespace std;

#include "Entes/Entidades/Personagem.hpp"

/*
    CLASSE ABSTRATA / DERIVADA DE PERSONAGEM
*/
class Jao_Zika_Jogador: public Personagem{
private: 
    int pontos;

public:
    Jao_Zika_Jogador();
    ~Jao_Zika_Jogador();
    void executar();
    void salvar();
    void setPontos(const int p);
    int getPontos() const;
    void operator=(int p);
};