#pragma once
#include "Ente.hpp"
class Entidade : public Ente {
	protected:
		const float x;
		const float y;
		sf::RectangleShape corpo;
		sf::Vector2f tam;
		sf::Vector2f pos;
		sf::Vector2f vel;
		std::ostream *buff;
	public:
		Entidade(const float x_ , const float y_, const float largura, const float altura);
		Entidade();
		virtual ~Entidade();
		virtual void executar() = 0;
		virtual void salvar()  = 0;
		void salvarDataBuffer();
		const sf::RectangleShape Get_Corpo() const;
		const sf::Vector2f Get_Tamanho() const;
		const sf::Vector2f Get_Posicao() const;
		const sf::Vector2f Get_Velocidade() const;
		const float getX() const;
		const float getY() const;
};
