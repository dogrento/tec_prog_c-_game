#include "Jogador.hpp"
Jogador::Jogador(const float x_, const float y_, const float largura, const float altura) : Personagem(x_ , y_, largura, altura), pontos(0) {
         Set_Posicao(x_, y_);

        // executar();   
}
Jogador::Jogador():Personagem(), pontos(0) {

}
Jogador::~Jogador() {

}
void Jogador::mover(const float x_, const float y_) {
        corpo.move(x_, y_);
	vel += Get_Posicao();
}
void Jogador::executar() {
		
}
void Jogador::salvar() {

}
void Jogador::Set_Posicao(const float x_, const float y_) {
	pos = sf::Vector2f(x_, y_);
}	
void Jogador::Set_Tamanho(const float largura, const float altura) {
	corpo.setSize(sf::Vector2f(largura, altura));	
}
void Jogador::Set_Velocidade(const float x_, const float y_) {
	vel += sf::Vector2f(x_, y_);
}
void Jogador::Set_Pontos(int p) {
	pontos = p;
}
