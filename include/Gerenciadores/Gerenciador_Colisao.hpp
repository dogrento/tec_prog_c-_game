#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include "Entes/Entidade.hpp"
#include "Entes/Entidades/Jogador.hpp"
#include "Entes/Fase.hpp"

/*
Classe Gerenciadora
Design Pattern: Mediator
*/
class Gerenciador_Colisoes {
private:
    //std::vector<Entidade*> entidades; // Lista de entidades a serem monitoradas
      std::vector<Inimigo*> LIs;
      std::vector<Inimigo*>::iterator itIs;     
      std::list<Obstaculo*> LOs;
      std::list<Obstaculo*>::iterator itOs;
      std::set<Projetil*> LPs;
      std::set<Projetil*>::iterator itPs;

      Jogador* pJog1; 
public:
    Gerenciador_Colisoes(): LIs(), LOs(), LPs(), pJog1(NULL) { LIs.clear(); LOs.erase(); LPs.clear(); }
    ~Gerenciador_Colisoes() { LIs.clear(); LOs.clear(); LPs.clear(); }

    // Adiciona uma entidade para ser monitorada
    void adicionarInimigo(Inimigo* inimigo) {
	if(inimigo != NULL) {
           LIs.push_back(inimigo);
	}
    }
    void adicionarObstaculo(Obstaculo *obstaculo) {
	if(obstaculo != NULL) {
           LOs.push_back(obstaculo);
	}
    }
    void adicionarProjetil(Projetil *projetil) {
	if(projetil != NULL) {
           LPs.insert(projetil);
	}
    }

    // Remove uma entidade da lista
    void removerEntidade(Entidade* entidade) {
        entidades.erase(std::remove(entidades.begin(), entidades.end(), entidade), entidades.end());
    }
    void removeInimigo(Inimigo *inimigo) {
	if(inimigo != NULL) { 
		itIs = LIs.find(inimigo); 
	   	delete(*itIs);
		LIs.erase(itIs);
	 }	
    }
    void removeObstaculo(Obstaculo *obstaculo) {
 	if(obstaculo != NULL) { 
		itIs = LOs.find(obstaculo); 
		delete(*itOs);
		LIs.erase(itOs);
    	}   	
	
    }
    void removeProjetil(Projetil *projetil) {
 	if(inimigo != NULL) { 
		itIs = LPs.find(projetil);
		delete *itPs;
      		LIs.erase(itPs);		
    	}   
    }
    void removeListaInimigos() { 
	   itIs = LIs.begin(); 
	   while(itIs != LIs.end()) {
		delete(*itIs);
		itIs++;
	   }
    	   	
    }
    void removeListaObstaculos() {
           itOs = LOs.begin(); 
	   while(itOs != LOs.end()) {
		delete(*itOs);
		itOs++;
	   }
    	}
    }
    void removeListaProjeteis() {
           itPs = LPs.begin(); 
	   while(itPs != LPs.end()) {
		delete(*itPs);
		itPs++;
	   }
    	}
    }

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
    void tratarColisaoHorizontal(Entidade* p1, Entidade* p2) {	
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
      }
    }

    // Trata colisões verticais
    void tratarColisaoVertical(Entidade* p1, Entidade* p2) {
     sf::FloatRect boundsp1 = p1->getCorpo()->getGlobalBounds();
     sf::FloatRect boundsp2 = p2->getCorpo()->getGlobalBounds();
     if(verificarColisoes(p1, p2)) {
 
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
};
