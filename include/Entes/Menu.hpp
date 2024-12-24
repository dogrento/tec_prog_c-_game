#pragma once

#include <string>
#include <iostream>
using namespace std;

#include "Ente.hpp"
// #include "Jao_Zika_Jogo.hpp"

class Jao_Zika_Jogo;

class MainMenu: public Ente{
private:
    Jao_Zika_Jogo* pJKJogo;

    sf::Font fonte;
    sf::Text opcao;                          // Fonte para os textos do menu
    std::vector<sf::Text> opcoes;            // Lista de opções
    sf::Event* evento;
    int indiceSelecionado;                   // Índice da opção selecionada
    // sf::RenderWindow* janela;                // Ponteiro para a janela (opcional)
    const float espacoEntreOpcoes = 50.f;    // Espaçamento entre as opções


public:
    MainMenu(Jao_Zika_Jogo* pJKJogo_):
    pJKJogo(nullptr),
    indiceSelecionado(0)
    {
        setAttrs(pJKJogo_);
    };
    ~MainMenu(){};

    void setAttrs(Jao_Zika_Jogo* pJKJogo_){
        if(pJKJogo_){
            pJKJogo = pJKJogo_;
        }else{
            cout << "setAttrs(): Ponteiro: pJKJogo_ esta nulo!" << endl;
        }
        if (!fonte.loadFromFile("../arquivos/Fontes/Squada_One/SquadaOne-Regular.ttf")) {  // Substitua pelo caminho da sua fonte
            std::cerr << "Erro ao carregar fonte!" << std::endl;
        }
        adicionarOpcao("Opcao jao");
        // setEvento(evento_);
    }
    
    void adicionarOpcao(const std::string& texto) {
        opcao.setFont(fonte);
        opcao.setString(texto);
        opcao.setCharacterSize(30);          // Tamanho da fonte
        opcao.setFillColor(sf::Color::White); // Cor inicial
        if (opcoes.empty()) {
            opcao.setPosition(100.f, 100.f); // Posição inicial
        } else {
            sf::Vector2f ultimaPosicao = opcoes.back().getPosition();
            opcao.setPosition(ultimaPosicao.x, ultimaPosicao.y + espacoEntreOpcoes);
        }
        opcoes.push_back(opcao);
    }

    void setEvento(sf::Event* evento_){
        if(evento_){
            evento = evento_;
        }else{
            cout << "setEvento(): Ponteiro: evento_ esta nulo!" << endl;
        }
    }
    void executar(){
        if (evento->type == sf::Event::Closed){
            // janela->close();
            this->pGG->fecharJanela();
        }

        if (evento->type == sf::Event::KeyPressed) {
            if (evento->key.code == sf::Keyboard::Up)
                moverParaCima();
            else if (evento->key.code == sf::Keyboard::Down)
                moverParaBaixo();
            else if (evento->key.code == sf::Keyboard::Enter)
                executarOpcao();
        }

        // Ente::desenhar();
        this->pGG->getJanela()->draw(opcao);
    };
    void atualizar(){};

    void moverParaCima() {
        if (indiceSelecionado > 0)
            indiceSelecionado--;
    }

    void moverParaBaixo() {
        if (indiceSelecionado < opcoes.size() - 1)
            indiceSelecionado++;
    }

    void executarOpcao() {
        std::cout << "Opção selecionada: " << opcoes[indiceSelecionado].getString().toAnsiString() << std::endl;
        // Execute lógica com base na opção escolhida
    }

    void setJogo(){};
};