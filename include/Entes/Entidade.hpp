#pragma once
// #include "Ente.hpp"
// class Entidade : public Ente {
// 	protected:
// 		const float x;
// 		const float y;
// 		sf::RectangleShape corpo;
// 		sf::Vector2f tam;
// 		sf::Vector2f pos;
// 		sf::Vector2f vel;
// 		std::ostream *buff;
// 	public:
// 		Entidade(const float x_ , const float y_, const float largura, const float altura);
// 		Entidade();
// 		virtual ~Entidade();
// 		virtual void executar() = 0;
// 		virtual void salvar()  = 0;
// 		void salvarDataBuffer();
// 		const sf::RectangleShape Get_Corpo() const;
// 		const sf::Vector2f Get_Tamanho() const;
// 		const sf::Vector2f Get_Posicao() const;
// 		const sf::Vector2f Get_Velocidade() const;
// 		const float getX() const;
// 		const float getY() const;
// };
#include <iostream>
using namespace std;
#include "Ente.hpp"
#include <SFML/Graphics.hpp>

class Entidade : public Ente {
protected:
    sf::Vector2f posicao;   // Posição da entidade
    sf::Vector2f velocidade; // Velocidade da entidade
    sf::RectangleShape* corpo; // Forma da entidade para desenhar

public:
    Entidade(const sf::Vector2f& tamanho, sf::Vector2f pos): 
		corpo(nullptr),
		posicao(pos)  
	{
        // posicao = sf::Vector2f(0.f, 0.f);
        velocidade = sf::Vector2f(0.f, 0.f);
        corpo = new sf::RectangleShape(tamanho);
        corpo->setPosition(posicao);
    }

    virtual ~Entidade() {}

    virtual void atualizar() override {
        // Atualizar posição com base na velocidade
        posicao += velocidade;
        corpo->setPosition(posicao);
    }

    virtual void desenhar() override {
        GG->desenhar(*getCorpo());
    }

    // Métodos para definir posição e velocidade
    void setPosicao(const sf::Vector2f& pos) { posicao = pos; corpo->setPosition(posicao);}
    void setVelocidade(const sf::Vector2f& vel) { 
        cout << "Atualizando velocidade:" << velocidade.y << "para" << vel.y << endl;
        velocidade = vel; 
    }
    // void setTamanho(const sf::Vector2f& tam) { corpo.; }
    sf::Vector2f getPosicao() const { return posicao; }
    sf::Vector2f getVelocidade() const { return velocidade; }
    sf::RectangleShape* getCorpo() const { return corpo; }
};
