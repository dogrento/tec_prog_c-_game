#include "Personagem.hpp"
Personagem::Personagem(const float x_, const float y_, const float largura, const float altura) : Entidade(x_, y_, largura, altura), Num_Vidas(0) {
	
}
Personagem::Personagem():Entidade(), Num_Vidas(0) {

}
Personagem:: ~Personagem() {
	
}
void Personagem::Salva_DataBuffer() {
	
}
void Personagem::mover(const float x_, const float y_) {
	
}
const int Personagem::getNum_Vidas() const {
	return Num_Vidas;
}



