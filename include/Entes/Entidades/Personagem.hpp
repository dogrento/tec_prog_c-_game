#pragma once
// #include "Entidade.hpp"
// class Personagem : public Entidade {
// 	protected:
// 		int Num_Vidas;
// 	public:
// 		Personagem(const float x_, const float y_, const float largura, const float altura);
// 		Personagem();
// 		virtual ~Personagem();
// 		void Salva_DataBuffer();
// 		virtual void salvar() = 0;
// 		virtual void mover(const float x_, const float y_);
// 		virtual void executar() = 0;
// 		const int getNum_Vidas() const;
			
// };
#include "Entes/Entidade.hpp"

class Personagem : public Entidade {
protected:
    int vida; // Quantidade de vida do personagem

public:
    Personagem(const sf::Vector2f& tamanho, const sf::Vector2f& pos): 
		Entidade(tamanho, pos), 
		vida(100) 
		{}

    virtual ~Personagem() {}

    // Métodos para manipular a vida
    void reduzirVida(int dano) { vida -= dano; if (vida < 0) vida = 0; } // sobrecarga de operador
    void aumentarVida(int cura) { vida += cura; }
    int getVida() const { return vida; }

    // Métodos abstratos para movimentação
    virtual void movimentar() = 0;
};
