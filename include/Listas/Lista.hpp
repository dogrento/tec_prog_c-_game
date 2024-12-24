#pragma once
#include <cstdio>
#include <iostream>
namespace Listas {
	template <class T>
	class Elemento {
				private:
					Elemento<T> *pnext;
					T *pInfo;
				public:
					Elemento():pInfo(NULL), pnext(NULL) { 	}
					~Elemento() { pInfo = NULL;   }
					void incluir(T *pInfo) { this->pInfo = pInfo; }
					void setProximo(Elemento<T> *pE) { if(pE != NULL) { (this->pnext = pE);} }
					Elemento<T>* getProximo() const { return (this->pnext);}
					T* getAtual() const { if(pInfo == NULL) {std::cout << "getAtual() NULL" << std::endl; }  return pInfo; }
	};	
	template <class T>
	class Lista {
		private:             	      
			Elemento<T> *pPrimeiro;
			Elemento<T> *pUltimo;
		public:			
			Lista(): pPrimeiro(NULL), pUltimo(NULL) { 	}
			~Lista() { pPrimeiro = NULL; pUltimo = NULL; }
			void incluir(T *pE) { if(pE != NULL) { Elemento<T> *e = new Elemento<T>(); e->incluir(pE);   if(pPrimeiro != NULL) { pUltimo->setProximo(e); }else{pPrimeiro = e;} pUltimo = e; e->setProximo(NULL); }}
			void limpar() { Elemento<T> *itr = getPrimeiro(); while(itr != NULL) { Elemento<T> *pAux = itr; itr = itr->getProximo(); delete (pAux); }}      
			Elemento<T>* getPrimeiro() const { return (pPrimeiro); }
			Elemento<T>* getUltimo() const { return (pUltimo); }
			bool listaVazia () const { return (!getPrimeiro()); }
	};	
}
using namespace Listas;
