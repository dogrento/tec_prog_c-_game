#pragma once

#include <iostream>
#include <vector>
#include "Entes/Entidade.hpp"
#include "Entes/Entidades/Jogador.hpp"
#include "Entes/Fase.hpp"

/*
Classe Gerenciadora
Design Pattern: Mediator
*/
class Gerenciador_Colisoes {
private:
    std::vector<Entidade*> entidades; // Lista de entidades a serem monitoradas

public:
    Gerenciador_Colisoes(): entidades() {}
    ~Gerenciador_Colisoes() {}

    // Adiciona uma entidade para ser monitorada
    void adicionarEntidade(Entidade* entidade) {
        entidades.push_back(entidade);
    }

    // Remove uma entidade da lista
    void removerEntidade(Entidade* entidade) {
        entidades.erase(std::remove(entidades.begin(), entidades.end(), entidade), entidades.end());
    }

    // Verifica e resolve colisões entre entidades
    void verificarColisoes() {
        for (size_t i = 0; i < entidades.size(); ++i) {
            for (size_t j = i + 1; j < entidades.size(); ++j) {
                if (entidades[i]->getCorpo()->getGlobalBounds().intersects(entidades[j]->getCorpo()->getGlobalBounds())) {
                    resolverColisao(entidades[i], entidades[j]);
                }
            }
        }
    }

private:
    void resolverColisao(Entidade* e1, Entidade* e2) {
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

    // Trata colisões horizontais
    void tratarColisaoHorizontal(Jogador* jogador, Obstaculo* plataforma) {
        sf::FloatRect boundsJogador = jogador->getCorpo()->getGlobalBounds();
        sf::FloatRect boundsPlataforma = plataforma->getCorpo()->getGlobalBounds();

        // Verifica colisão horizontal
        if (boundsJogador.intersects(boundsPlataforma)) {
            if (boundsJogador.left + boundsJogador.width > boundsPlataforma.left &&
                boundsJogador.left < boundsPlataforma.left) {
                // Jogador colidiu com o lado esquerdo da plataforma
                jogador->setPosicao(sf::Vector2f(
                    boundsPlataforma.left - boundsJogador.width,
                    jogador->getPosicao().y
                ));
            } else if (boundsJogador.left < boundsPlataforma.left + boundsPlataforma.width &&
                    boundsJogador.left + boundsJogador.width > boundsPlataforma.left + boundsPlataforma.width) {
                // Jogador colidiu com o lado direito da plataforma
                jogador->setPosicao(sf::Vector2f(
                    boundsPlataforma.left + boundsPlataforma.width,
                    jogador->getPosicao().y
                ));
            }

            // Zera a velocidade horizontal
            jogador->setVelocidade(sf::Vector2f(0.f, jogador->getVelocidade().y));
        }
    }

    // Trata colisões verticais
    void tratarColisaoVertical(Jogador* jogador, Obstaculo* plataforma) {
        sf::FloatRect boundsJogador = jogador->getCorpo()->getGlobalBounds();
        sf::FloatRect boundsPlataforma = plataforma->getCorpo()->getGlobalBounds();

        // Verifica colisão vertical
        if (boundsJogador.intersects(boundsPlataforma)) {
            if (boundsJogador.top + boundsJogador.height > boundsPlataforma.top &&
                boundsJogador.top + boundsJogador.height <= boundsPlataforma.top + 5.f &&
                jogador->getVelocidade().y > 0.f) {
                // Jogador colidiu na parte superior da plataforma
                jogador->setPosicao(sf::Vector2f(
                    jogador->getPosicao().x,
                    boundsPlataforma.top - boundsJogador.height
                ));

                // Para o movimento vertical
                jogador->setVelocidade(sf::Vector2f(jogador->getVelocidade().x, 0.f));
            } else if (boundsJogador.top < boundsPlataforma.top + boundsPlataforma.height &&
                    boundsJogador.top >= boundsPlataforma.top + boundsPlataforma.height - 5.f &&
                    jogador->getVelocidade().y < 0.f) {
                // Jogador colidiu na parte inferior da plataforma
                jogador->setPosicao(sf::Vector2f(
                    jogador->getPosicao().x,
                    boundsPlataforma.top + boundsPlataforma.height
                ));

                // Para o movimento vertical
                jogador->setVelocidade(sf::Vector2f(jogador->getVelocidade().x, 0.f));
            }
        }
    }
};