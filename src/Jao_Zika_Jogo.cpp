#include "Jao_Zika_Jogo.hpp"

Jao_Zika_Jogo::Jao_Zika_Jogo():
menu(nullptr),
pJZ(nullptr),
pGG(nullptr)
{
    cout << "Construtora: Jao_Zika_Jogo" << endl;
    init();
}

Jao_Zika_Jogo::~Jao_Zika_Jogo()
{
    cout << "Destrutora: Jao_Zika_Jogo" << endl;
    delete pJZ;
}

void Jao_Zika_Jogo::init(){
    menu = new MainMenu(this);
    pJZ = new Jao_Zika_Jogador;
    pGG = Gerenciador_Grafico::getInstancia();
}

void Jao_Zika_Jogo::executar()
{
    cout << "executar: Jao_Zika_Jogo" << endl;
    while (pGG->janelaAberta()) { // Enquanto a janela estiver aberta
        // Processar eventos
        sf::Event evento;
        menu->setEvento(&evento);
        while (pGG->getJanela()->pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                pGG->fecharJanela(); // Fecha a janela ao clicar no botão "fechar"
            }
        }

        // Limpar a janela
        pGG->getJanela()->clear(sf::Color::Black);
        menu->executar();

        // pE->executar();
        // pJZ->executar();
        // pGG->desenhar(pJZ);

        // // Desenhar o retângulo
        // pGG->janela.draw(*pE->getFig());
        // torreE.exec();

        // Atualizar a janela (trocar buffers)
        pGG->atualizar();
    }
}
