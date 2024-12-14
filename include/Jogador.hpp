#pragma once
// #include "Personagem.hpp"
// class Jogador : public Personagem {
// 	private:
// 		int pontos;
// 	public:
// 		Jogador(const float x_, const float y_, const float largura, const float altura);
// 		Jogador();
// 		~Jogador();
// 		void mover(const float x_, const float y_);
// 		void executar() override;
// 		void salvar() override;
// 		void Set_Posicao(const float x_, const float y_);		
// 		void Set_Tamanho(const float largura, const float altura);
// 		void Set_Velocidade(const float x_, const float y_);
// 		void Set_Pontos(int p);	
		
			
// };
#include "Personagem.hpp"
#include <SFML/Window.hpp>

class Jogador : public Personagem {
public:
    Jogador() : Personagem(sf::Vector2f(50.f, 50.f)) {
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