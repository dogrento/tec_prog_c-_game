#include "Jao_Zika_Jogo.hpp"

Jao_Zika_Jogo::Jao_Zika_Jogo():
pJZ(nullptr),
pGG(nullptr)
{
    cout << "Construtora: Jao_Zika_Jogo" << endl;
    pGG = Gerenciador_Grafico::getInstancia();
}

Jao_Zika_Jogo::~Jao_Zika_Jogo()
{
    cout << "Destrutora: Jao_Zika_Jogo" << endl;
    delete pJZ;
}

void Jao_Zika_Jogo::executar()
{
    cout << "executar: Jao_Zika_Jogo" << endl;
    pJZ = new Jao_Zika_Jogador;
    while (pGG->janelaAberta()) { // Enquanto a janela estiver aberta
        // Processar eventos
        sf::Event evento;
        while (pGG->getJanela()->pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                pGG->fecharJanela(); // Fecha a janela ao clicar no botão "fechar"
            }
        }

        // Limpar a janela
        pGG->getJanela()->clear(sf::Color::Black);

        // pE->executar();
        pJZ->executar();
        // pGG->desenhar(pJZ);

        // // Desenhar o retângulo
        // pGG->janela.draw(*pE->getFig());
        // torreE.exec();

        // Atualizar a janela (trocar buffers)
        pGG->atualizar();
    }
}
