#pragma once

#include "Entes/Entidades/Obstaculo.hpp"

class Plataforma : public Obstaculo {
public:
    Plataforma(sf::Vector2f tamanho, sf::Vector2f pos)
        : Obstaculo(tamanho, pos, false) {} // Inicializa como não danosa

    ~Plataforma(){};

    // Implementação do método abstrato
    void exec() override {
        desenhar();
    }
};