#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
class Gerenciador_Grafico;
class Figura;
class Ente {
	protected:
		const int id;
		static int cont;
		Gerenciador_Grafico* pGG;
		Figura* pFig;
	public:
		Ente();
		virtual ~Ente();
		virtual void executar() = 0;
		void desenhar();
};
