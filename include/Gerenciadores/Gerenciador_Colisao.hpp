#pragma once

#include <iostream>
#include <vector>
#include "Entes/Entidade.hpp"

/*
Classe Gerenciadora
Design Pattern: Mediator
*/
class Gerenciador_Colisoes {
private:
    std::vector<Entidade*> entidades; // Lista de entidades a serem monitoradas

public:
    Gerenciador_Colisoes(): entidades() {}
    ~Gerenciador_Colisoes() {}

    // Adiciona uma entidade para ser monitorada
    void adicionarEntidade(Entidade* entidade) {
        entidades.push_back(entidade);
    }

    // Remove uma entidade da lista
    void removerEntidade(Entidade* entidade) {
        entidades.erase(std::remove(entidades.begin(), entidades.end(), entidade), entidades.end());
    }

    // Verifica e resolve colisões entre entidades
    void verificarColisoes() {
        for (size_t i = 0; i < entidades.size(); ++i) {
            for (size_t j = i + 1; j < entidades.size(); ++j) {
                if (entidades[i]->getCorpo()->getGlobalBounds().intersects(entidades[j]->getCorpo()->getGlobalBounds())) {
                    resolverColisao(entidades[i], entidades[j]);
                }
            }
        }
    }

private:
    // Método de resolução de colisão (pode ser estendido)
    void resolverColisao(Entidade* e1, Entidade* e2) {
        // Exemplo simples: imprime no log
        std::cout << "Colisão detectada entre entidades!" << std::endl;

        // Adicione lógica de resposta à colisão aqui
        // Exemplo: ajustar posições, causar dano, etc.
    }
};