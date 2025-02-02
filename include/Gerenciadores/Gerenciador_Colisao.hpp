<<<<<<< HEAD
<<<<<<< HEAD
#pragma oncew
=======
#pragma onc
>>>>>>> d57b9fd (altera)
=======
#pragma once
>>>>>>> fb00894 (k)
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <cmath>
#include "Entes/Entidade.hpp"
#include "Entes/Entidades/Jogador.hpp"
#include "Entes/Fase.hpp"
#include <algorithm>
/*
Classe Gerenciadora
Design Pattern: Mediator
*/
using namespace std;
class Gerenciador_Colisoes {
private:
    //std::vector<Entidade*> entidades; // Lista de entidades a serem monitoradas
      //std::vector<Inimigo*> LIs;
      //std::vector<Inimigo*>::iterator itIs;     
      std::list<Obstaculo*> LOs;
      std::list<Obstaculo*>::iterator itOs;
      //std::set<Projetil*> LPs;
      //std::set<Projetil*>::iterator itPs;
      Jogador* pJog1; 
public:
    Gerenciador_Colisoes(): /*LIs(),*/ LOs(), /*LPs(),*/ pJog1(NULL) { /*LIs.clear();*/ LOs.clear(); /*LPs.clear();*/ }  
    ~Gerenciador_Colisoes() { 
	    //removeListaInimigos();
	    removeListaObstaculos();
	    //removeListaProjetil();

	    //LIs.clear(); 
	    LOs.clear(); 
	    //LPs.clear();
    }
    // Adiciona uma entidade para ser monitorada
   /* void adicionarInimigo(Inimigo* inimigo) {
	if(inimigo != NULL) {
           LIs.push_back(inimigo);
	}
    }*/
    void adicionarObstaculo(Obstaculo *obstaculo) {
	if(obstaculo != NULL) {
           LOs.push_back(obstaculo);
	}
    }/*
    void adicionarProjetil(Projetil *projetil) {
	if(projetil != NULL) {
           LPs.insert(projetil);
	}
    }*/
    void adicionarJogador(Jogador *jogador) {
	if(jogador != NULL) {
	   pJog1 = jogador;	
	}
    }
    // Remove uma entidade da lista
    void removerEntidade(Entidade* entidade) {
        //entidades.erase(std::remove(entidades.begin(), entidades.end(), entidade), entidades.end());
    }/*
    void removeInimigo(Inimigo *inimigo) {
	if(inimigo != NULL) { 
		itIs = LIs.find(inimigo); 
	   	delete(*itIs);
		LIs.erase(itIs);
	 }	
    }*/
    void removeObstaculo(Obstaculo *obstaculo) {
 	if(obstaculo != NULL) { 
		itOs = find(LOs.begin(), LOs.end(), obstaculo); 
		delete(*itOs);
		LOs.erase(itOs);
    	}   	
    }/*
    void removeProjetil(Projetil *projetil) {
 	if(inimigo != NULL) { 
		itIs = LPs.std::find(LPs.begin(), LPs.end(), projetil);
		delete *itPs;
      		LPs.erase(itPs);		
    	}   
    }*//*
    void removeListaInimigos() { 
	   itIs = LIs.begin(); 
	   while(itIs != LIs.end()) {
		delete(*itIs);
		itIs++;
	   }
    }*/
    void removeListaObstaculos() {
           itOs = LOs.begin(); 
	   while(itOs != LOs.end()) {
		delete(*itOs);
		itOs++;
	   }
    }
    /*
    void removeListaProjeteis() {
           itPs = LPs.begin(); 
	   while(itPs != LPs.end()) {
		delete(*itPs);
		itPs++;
	   }
    	}
    }*/
    // Verifica e resolve colisões entre entidades
    const bool verificarColisoes(Entidade *p1, Entidade *p2) {
        //for (size_t i = 0; i < entidades.size(); ++i) {
          //  for (size_t j = i + 1; j < entidades.size(); ++j) {
                if (p1->getCorpo()->getGlobalBounds().intersects(p2->getCorpo()->getGlobalBounds())) {
                   // resolverColisao(entidades[i], entidades[j]);
                   return true;
		}
            //}
        //}
	return false;
    }
    void exec() {
	    itOs = LOs.begin();
		while(itOs != LOs.end()) {
			float g = tratarGravidade((Entidade*)pJog1, (Entidade*)*itOs);
			cout << "gravidade em exec da class gerenciadoraColisao:" << g  << endl;
			((Entidade*)pJog1)->setGravidade(g); //itera velocidade +=
		        ((Entidade*)*itOs)->setGravidade(g);

			tratarColisao((Entidade*)pJog1, (Entidade*)*itOs);
			itOs++;
		}   
    }
private:
    /*void resolverColisao(Entidade* e1, Entidade* e2) {
        std::cout << "Colisão detectada entre entidades!" << std::endl;

        // Verifica os tipos de entidade
        Jogador* jogador = dynamic_cast<Jogador*>(e1);
        Obstaculo* plataforma = dynamic_cast<Obstaculo*>(e2);

        if (!jogador) {
            // Inverte as entidades caso a ordem seja trocada
            jogador = dynamic_cast<Jogador*>(e2);
            plataforma = dynamic_cast<Obstaculo*>(e1);
        }

        if (jogador && plataforma) {
            std::cout << "Jogador e plataforma colidiram" << std::endl;

            // Divide a lógica entre colisões horizontais e verticais
            tratarColisaoHorizontal(jogador, plataforma);
            tratarColisaoVertical(jogador, plataforma);
        }
    }
    */

    // Trata colisões horizontais
    void tratarColisao(Entidade* p1, Entidade* p2) {	
       sf::FloatRect boundsp1 = p1->getCorpo()->getGlobalBounds();
       sf::FloatRect boundsp2 = p2->getCorpo()->getGlobalBounds();
       if(verificarColisoes(p1, p2)) {
        // Verifica colisão horizontal
        if (boundsp1.intersects(boundsp2)) {
            if (boundsp1.left + boundsp1.width > boundsp2.left &&
                boundsp1.left < boundsp2.left) {
                // Jogador colidiu com o lado esquerdo da plataforma
                p1->setPosicao(sf::Vector2f(
                    boundsp2.left - boundsp1.width,
                    p1->getPosicao().y
                ));
            } else if (boundsp1.left < boundsp2.left + boundsp2.width &&
                    boundsp1.left + boundsp1.width > boundsp2.left + boundsp2.width) {
                // Jogador colidiu com o lado direito da plataforma
                p1->setPosicao(sf::Vector2f(
                    boundsp2.left + boundsp2.width,
                    p1->getPosicao().y
                ));
	    }
            // Zera a velocidade horizontal
            p1->setVelocidade(sf::Vector2f(0.f, p1->getVelocidade().y));
        }
	 // Verifica colisão vertical
        if (boundsp1.intersects(boundsp2)) {
            if (boundsp1.top + boundsp1.height > boundsp2.top &&
                boundsp1.top + boundsp1.height <= boundsp2.top + 5.f &&
                p1->getVelocidade().y > 0.f) {
                // p1 colidiu na parte superior da p2
                p1->setPosicao(sf::Vector2f(
                    p1->getPosicao().x,
                    boundsp2.top - boundsp1.height
                ));
                // Para o movimento vertical
                p1->setVelocidade(sf::Vector2f(p1->getVelocidade().x, 0.f));
            } else if (boundsp1.top < boundsp2.top + boundsp2.height &&
                    boundsp1.top >= boundsp2.top + boundsp2.height - 5.f &&
                    p1->getVelocidade().y < 0.f) {
                // p1 colidiu na parte inferior da p2
                p1->setPosicao(sf::Vector2f(
                    p1->getPosicao().x,
                    boundsp2.top + boundsp2.height
                ));
                // Para o movimento vertical
                p1->setVelocidade(sf::Vector2f(p1->getVelocidade().x, 0.f));
            }
         }	
      }
    }
float dot(Entidade *e1, Entidade *e2) {
	float modulo_e1 = e1->getDistancia(e1, e1);
	float modulo_e2 = e2->getDistancia(e2, e2);
	return ((modulo_e1 * modulo_e2) * std::acos(((e1->getPosicao().x * e2->getPosicao().x) + (e1->getPosicao().y * e2->getPosicao().y)) / (modulo_e1 * modulo_e2)));
}
float tratarGravidade(Entidade *e1, Entidade *e2) {
	float dist = e2->getDistancia(e1, e2);
        if (dist == 0.0f) {
        	throw std::runtime_error("Distância entre as entidades não pode ser zero.");
    	}
        return /* TESTE DA GRAVIDADE COM VALOR NUMERO 1 */ GRAVITY * ((e1->getMassa() * e2->getMassa()) / (dist * dist));	
}
};
