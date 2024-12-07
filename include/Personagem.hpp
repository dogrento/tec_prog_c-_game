#pragma once
#include "Entidade.hpp"
class Personagem : public Entidade {
	protected:
		int Num_Vidas;
	public:
		Personagem(const float x_, const float y_, const float largura, const float altura);
		Personagem();
		virtual ~Personagem();
		void Salva_DataBuffer();
		virtual void salvar() = 0;
		virtual void mover(const float x_, const float y_);
		virtual void executar() = 0;
		const int getNum_Vidas() const;
			
};
