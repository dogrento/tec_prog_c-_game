#pragma once

#include <SFML/Window.hpp>
#include "Personagem.hpp"


class Jogador : public Personagem {
private:
	int pontos;
public:
    Jogador(sf::Vector2f tam, sf::Vector2f pos): 
	pontos(-1),
	Personagem(tam, pos) 
	{
        corpo.setFillColor(sf::Color::Blue); // Define a cor do jogador
    }

    virtual ~Jogador() {}

    // Implementa movimentação controlada por teclado
    void movimentar() override {
        velocidade = sf::Vector2f(0.f, 0.f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            velocidade.y = -5.f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            velocidade.y = 5.f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            velocidade.x = -5.f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            velocidade.x = 5.f;
        }
    }

    // Atualiza o jogador (movimentação + posição)
    void atualizar() override {
        movimentar();
        Entidade::atualizar(); // Atualiza a posição com base na velocidade
    }
};