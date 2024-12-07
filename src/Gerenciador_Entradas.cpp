#include "Gerenciador_Entradas.hpp"

Gerenciador_Entradas::Gerenciador_Entradas() {
	Personagem *p = NULL;
	//Movimento_Peculiar *comandoW = NULL;
	//Movimento_Peculiar Personagem *comandoA = NULL;
	//Movimento_Peculiar *comandoD = NULL;
	//Movimento_Peculiar *comandoS = NULL;
	
}
Gerenciador_Entradas::~Gerenciador_Entradas() {
	Personagem *p = NULL;
	//Movimento_Peculiar *comandoW = NULL;
	//Movimento_Peculiar *comandoA = NULL;
	//Movimento_Peculiar *comandoD = NULL;
	//Movimento_Peculiar *comandoS = NULL;

}
Personagem* Gerenciador_Entradas::Lidar_Entrada(sf::Keyboard::Key comando, Personagem *p) {
if(p) { 
	
 if((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) == comando) {
 	 p->mover(0.0f, 0.1f);
	 //return comandoW;
 }
 if((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) == comando)) {
	 p->mover(-0.1f, 0.0f);
	 //return comandoA; 
 }
 if((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) == comando)) {
	 p->mover(0.1f, 0.0f);
	 //return comandoD;
 }
 if((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) == comando) {
         p->mover(0.0, -0.1f);
          //return comandoS;
 }

}else{
	std::cout << "Personagem não existe" << std::endl;
}	
 return NULL;
}
