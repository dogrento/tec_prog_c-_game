#pragma once

#include <iostream>
using namespace std;

#include "Entes/Entidades/Personagens/Jao_Zika_Jogador.hpp"

#include "Gerenciadores/Gerenciador_Grafico.hpp"

/* 
    CLASSE PRINCIPAL.
*/
class Jao_Zika_Jogo{
private:
    Jao_Zika_Jogador* pJZ; // Jogador 1
    Gerenciador_Grafico* pGG; 

public:
    Jao_Zika_Jogo();
    ~Jao_Zika_Jogo();
    void executar();
};

