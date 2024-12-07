#pragma once
#include "Personagem.hpp"
class Jogador : public Personagem {
	private:
		int pontos;
	public:
		Jogador(const float x_, const float y_, const float largura, const float altura);
		Jogador();
		~Jogador();
		void mover(const float x_, const float y_);
		void executar() override;
		void salvar() override;
		void Set_Posicao(const float x_, const float y_);		
		void Set_Tamanho(const float largura, const float altura);
		void Set_Velocidade(const float x_, const float y_);
		void Set_Pontos(int p);	
		
			
};
