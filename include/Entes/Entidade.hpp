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
#include <cmath>
#define GRAVITY 6.6743e-11f
#include <SFML/Graphics.hpp>

class Entidade : public Ente {
protected:
    sf::Vector2f posicao;   // Posição da entidade
    const float massa;
    sf::Vector2f velocidade; // Velocidade da entidade
    sf::RectangleShape* corpo; // Forma da entidade para desenhar	
public:
    Entidade(const sf::Vector2f& tamanho, sf::Vector2f pos): 
		corpo(nullptr),
		posicao(pos), Ente(), massa(80.0)  
	{
        // posicao = sf::Vector2f(0.f, 0.f);
        velocidade = sf::Vector2f(0.f, 0.f);
        setTamanho(tamanho);
        corpo->setPosition(posicao);
    }

    virtual ~Entidade() {}
    virtual void atualizar() override {
        // Atualizar posição com base na velocidad
        posicao += velocidade;
        corpo->setPosition(posicao);
    }

    virtual void desenhar() override {
        GG->desenhar(*getCorpo());
    }
    virtual void exec() override {	}
    // Métodos para definir posição e velocidade
    void setPosicao(const sf::Vector2f& pos) {posicao = pos; corpo->setPosition(posicao);}
    void setVelocidade(const sf::Vector2f& vel) { 
        cout << "Atualizando velocidade:" << velocidade.y << "para" << vel.y << endl;
        velocidade = vel; 
    }
    void setGravidade(float g) { //void operator++(float g) {
	cout << "Velocidade adicionada em g: " << g << endl;
	velocidade.y += -(g);	
    }
    void setTamanho(const sf::Vector2f& tam) {
    	corpo = new sf::RectangleShape(tam);
    }
    //void setTamanho(const sf::Vector2f& tam) { corpo.; }
    sf::Vector2f getPosicao() const { return posicao; }
    sf::Vector2f getVelocidade() const { return velocidade; }
    sf::RectangleShape* getCorpo() const { return corpo; }
    float getDistancia(Entidade *e1, Entidade *e2) {
	    float dx = e2->getPosicao().x - e1->getPosicao().x;
	    float dy = e2->getPosicao().y - e1->getPosicao().y;	
	    return std::sqrt ((dx*dx) + (dy*dy));
    }
    const float getMassa() const {
	return massa;
    }
};
