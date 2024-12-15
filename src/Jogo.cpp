#include <iostream>
using namespace std;
#include "Jogo.h"

void Jogo::exec()
{
    while (GG->janelaAberta()) { // Enquanto a janela estiver aberta
        // Processar eventos
        sf::Event evento;
        while (GG->getJanela()->pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                GG->fecharJanela(); // Fecha a janela ao clicar no botão "fechar"
            }
        }

        // Limpar a janela
        GG->getJanela()->clear(sf::Color::Black);

        // // Desenhar o retângulo
        // GG->desenhar(ret);
        // obstaculo.exec();
        // j.atualizar();
        // j.desenhar();
        // fase1.desenhar();
        // fase1.atualizar();
        fase1.exec();

        // Atualizar a janela (trocar buffers)
        GG->atualizar();
    }
}
