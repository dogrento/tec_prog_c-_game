#include "Gerenciadores/Gerenciador_Grafico.hpp"

// // Inicializa o ponteiro da instância única
Gerenciador_Grafico* Gerenciador_Grafico::instancia = nullptr;

// Construtor privado
Gerenciador_Grafico::Gerenciador_Grafico():
    janela(sf::VideoMode(800, 600), "Jogo com SFML"), 
    view(sf::FloatRect(0, 0, 800, 600))
{
    janela.setFramerateLimit(60); // Limitar FPS a 60
}

// Retorna a instância única
Gerenciador_Grafico* Gerenciador_Grafico::getInstancia() {
    if (!instancia) {
        instancia = new Gerenciador_Grafico();
    }
    return instancia;
}

// Destrutor
Gerenciador_Grafico::~Gerenciador_Grafico() {
    if (janela.isOpen()) {
        janela.close();
    }
    delete instancia;
}

// Retorna um ponteiro para a janela
sf::RenderWindow* Gerenciador_Grafico::getJanela() {
    return &janela;
}

// Desenha um objeto na janela
void Gerenciador_Grafico::desenhar(Ente* pE) {

    // // Desenhar o retângulo
    janela.draw(*pE->getFig()->getCorpo());

}

// Atualiza a janela (troca de buffers)
void Gerenciador_Grafico::atualizar() {
    janela.display();
}

// Verifica se a janela está aberta
bool Gerenciador_Grafico::janelaAberta() {
    return janela.isOpen();
}

// Fecha a janela
void Gerenciador_Grafico::fecharJanela() {
    janela.close();
}