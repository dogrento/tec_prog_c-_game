#include "Entidade.hpp"
Entidade::Entidade(const float x_ , const float y_, const float largura, const float altura) : Ente(), x(x_), y(y_), pos(x_, y_), vel(0.1f, 0.1f), corpo(sf::Vector2f(largura, altura)){
	
}
Entidade::Entidade(): Ente(), x(0.0f), y(0.0f), corpo(sf::Vector2f(0.0f, 0.0f)), vel(0.1f, 0.1f){
	
}
Entidade:: ~Entidade() {
		
}
void Entidade::salvarDataBuffer() {
	
}
const sf::RectangleShape Entidade::Get_Corpo() const {
	return corpo;
}
const sf::Vector2f Entidade::Get_Tamanho() const {
	return corpo.getSize();
}
const sf::Vector2f Entidade::Get_Posicao() const {
	return pos;
}
const sf::Vector2f Entidade::Get_Velocidade() const {
	return vel;
}
const float Entidade::getX() const {
	return x;
}
const float Entidade::getY() const {
	return y;
}
