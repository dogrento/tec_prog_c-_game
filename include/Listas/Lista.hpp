#pragma once
#include <cstdio>
#include <iostream>
namespace Listas {
	template<class T>
	class Elemento;
	template <class T>
	class Lista {
		private:             	      
			Elemento<T> *pPrimeiro;
			Elemento<T> *pUltimo;
		public:			
			Lista(): pPrimeiro(NULL), pUltimo(NULL) { 	}
			~Lista() { limpar(); }
			void incluir(T *pE) { Elemento<T> *e = new Elemento<T>(pE) ; if(pPrimeiro != NULL && (pE != NULL)) { pUltimo->setProximo(pE);}else{pPrimeiro = pE;} pUltimo = pE;}
			void limpar() { Elemento<T> *itr = getPrimeiro(); while(itr != NULL) { Elemento<T> *pAux = itr; itr = itr->getProximo(); delete pAux; } }      
			T* getPrimeiro() const { return (pPrimeiro);}
			T* getUltimo() const { return (pUltimo);}
			T* getAtual() const { return (pUltimo->getAtual());}
			bool listaVazia () const { return (!getPrimeiro());}
	};

	template <class T>
	class Elemento {
				private:
					Elemento<T> *pnext;
					T *pInfo;
				public:
					Elemento():pInfo(NULL) { 	}
					~Elemento() { pInfo = NULL;   }
					void incluir(T *pInfo) { this->pInfo = pInfo; }
					void setProximo(Elemento<T> *pE) { if(pE != NULL) { (this->pnext = pE);} }
					Elemento<T>* getProximo() const { return (this->pnext);}
					T* getAtual() const { return pInfo; }
	};	
}

using namespace Listas;
