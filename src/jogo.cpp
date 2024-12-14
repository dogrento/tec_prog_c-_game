#include "jogo.h"

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

        // Desenhar o retângulo
        GG->desenhar(ret);

        // Atualizar a janela (trocar buffers)
        GG->atualizar();
    }
}
