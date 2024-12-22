#pragma once 
#include <cstdio>
#include <iostream>
#include "Listas/Lista.hpp"
namespace Listas {
  class ListaEntidades {
	private:
		Lista<Entidade>	LObjE;
	public:
		ListaEntidades():LObjE() {   		}	
		~ListaEntidades() { 		}
		void incluir(Entidade *pE) { if(pE) {LObjE.incluir(pE);} }
		void percorrer() { Entidade *itr = LObjE.getPrimeiro(); if(!LObjE.listaVazia()) { while(itr != NULL) { itr->atualizar(); itr->desenhar(); itr = itr->getProximo(); }}}
		void desenhar() { Entidade *itr = LObjE.getPrimeiro(); if(!LObjE.listaVazia()) { while(itr != NULL) { itr->desenhar(); itr->desenhar(); itr = itr->getProximo(); }}}
		Entidade* operator++() { Entidade *itr = LObjE.getAtual(); Entidade *aux = itr; itr = itr->getProximo(); }

  };

}
