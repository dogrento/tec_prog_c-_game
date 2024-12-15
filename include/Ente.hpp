#pragma once
// #include "SFML/Graphics.hpp"
// #include <iostream>
// #include <fstream>
// #include <cstdio>
// #include <cstdlib>
// class Gerenciador_Grafico;
// class Figura;
// class Ente {
// 	protected:
// 		const int id;
// 		static int cont;
// 		Gerenciador_Grafico* pGG;
// 		Figura* pFig;
// 	public:
// 		Ente();
// 		virtual ~Ente();
// 		virtual void executar() = 0;
// 		void desenhar();
// };

#include "Gerenciador_Grafico.hpp"

class Ente {
protected:
	int id;
    Gerenciador_Grafico* GG; // Referência ao Gerenciador Gráfico

public:
    Ente()
	// GG(nullptr)
	{
        GG = Gerenciador_Grafico::getInstancia();
    }
    virtual ~Ente() {}

    virtual void atualizar() = 0; // Método virtual puro para atualizar o estado
    virtual void desenhar() = 0;  // Método virtual puro para desenhar na tela
};

