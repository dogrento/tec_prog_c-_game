#pragma once 
#include <cstdio>
#include <iostream>
#include "Listas/Lista.hpp"
#include "../include/Entes/Entidade.hpp"
namespace Listas {
  class ListaEntidades {
	private:
		Lista<Entidade>	LObjE;
		Elemento<Entidade> *itr;
	public:
		ListaEntidades():LObjE(), itr(NULL) {   }	
		~ListaEntidades() { LObjE.limpar(); }
		void incluir(Entidade *pE) { if(pE) { LObjE.incluir(pE); } }
		void percorrer() { itr = LObjE.getPrimeiro();  while(itr != NULL) {Entidade *e = itr->getAtual(); if(e){ e->atualizar(); e->desenhar(); } itr = itr->getProximo(); }}
		void desenhar() {  itr = LObjE.getPrimeiro();  while(itr != NULL) { Entidade *e = itr->getAtual(); if(e) { e->desenhar(); } itr = itr->getProximo(); }}
		Entidade* operator++() { if(itr == NULL) { return NULL; } Entidade *aux = itr->getAtual(); itr = itr->getProximo(); return aux; }
		Elemento<Entidade>*getPrimeiro() { return LObjE.getPrimeiro(); }
		Elemento<Entidade>*getUltimo() { return LObjE.getUltimo(); }
  };
}
