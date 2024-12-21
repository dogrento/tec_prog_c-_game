#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

#include "Ente.hpp"

class Ente;

class Gerenciador_Grafico {
private:
    static Gerenciador_Grafico* instancia; // Ponteiro para a instância única
    sf::RenderWindow janela;              // Janela de renderização
    sf::View view;                        // View para controlar a câmera

    // Construtor privado para o Singleton
    Gerenciador_Grafico();

public:
    // Desabilitar cópia e atribuição <<Delete>>
    Gerenciador_Grafico(const Gerenciador_Grafico&) = delete;
    Gerenciador_Grafico& operator=(const Gerenciador_Grafico&) = delete;

    // Método estático para acessar a instância única
    static Gerenciador_Grafico* getInstancia();

    // Destrutor
    ~Gerenciador_Grafico();

    // Métodos públicos
    sf::RenderWindow* getJanela();
    void desenhar(Ente* pE);
    void atualizar();
    bool janelaAberta();
    void fecharJanela();
};
