#pragma once

#include "Entes/Fase.hpp"

class TorreE : public Fase {
public:
    TorreE() {
        std::cout << "Fase1 criada!" << std::endl;
    }

    ~TorreE() {
        // Libera os recursos alocados, se necessário
        std::cout << "Fase1 destruída!" << std::endl;
    }

    // Sobrescreve métodos da classe base
    void init() override {
        std::cout << "Inicializando Fase1!" << std::endl;
        
        // Configura o jogador
        Jogador* jogador = new Jogador(sf::Vector2f(50.f, 50.f), sf::Vector2f(100.f, 100.f)); // Tamanho e posição inicial
        setJogadores(jogador);

        // Configura obstáculos específicos da Fase1
        initObstaculos();
        
        // Finaliza inicialização
        Fase::init(); // Chama init da classe base para adicionar entidades no gerenciador de colisões
    }

    void setObstaculos() {
        // std::cout << "Adicionando obstáculos específicos para Fase1!" << std::endl;

        // // Adiciona uma plataforma
        // Plataforma* plataforma = new Plataforma(sf::Vector2f(400.f, 20.f), sf::Vector2f(50.f, 400.f));
        // lOsbtaculo.push_back(plataforma);

        // // Adiciona outra plataforma ou obstáculos, se necessário
        // Plataforma* outraPlataforma = new Plataforma(sf::Vector2f(300.f, 20.f), sf::Vector2f(500.f, 300.f));
        // lOsbtaculo.push_back(outraPlataforma);

        // // Aqui você pode adicionar mais obstáculos, como inimigos, armadilhas, etc.
    }

    void exec() override {
        std::cout << "Executando lógica de Fase1!" << std::endl;
        Fase::exec(); // Usa a lógica padrão da fase (atualizar, desenhar, verificar colisões)
    }
};