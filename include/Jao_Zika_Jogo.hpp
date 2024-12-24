#pragma once

#include <iostream>
using namespace std;

#include "Entes/Menu.hpp"
#include "Entes/Entidades/Personagens/Jao_Zika_Jogador.hpp"
#include "Gerenciadores/Gerenciador_Grafico.hpp"

/* 
    CLASSE PRINCIPAL.
*/
class Jao_Zika_Jogo{
private:
    MainMenu* menu;
    Jao_Zika_Jogador* pJZ; // Jogador 1
    Gerenciador_Grafico* pGG; 

public:
    Jao_Zika_Jogo();
    ~Jao_Zika_Jogo();
    void init();
    void executar();
};

