#pragma once
#include "Entes/Fase.hpp"

class TorreE : public Fase {
public:
    TorreE(int tam):Fase(tam) {
        std::cout << "Fase1 criada!" << std::endl;
    }
    ~TorreE() {
        // Libera os recursos alocados, se necessário
        std::cout << "Fase1 destruída!" << std::endl;
    }

    void criarInimFaceis() {
	        //Inimigo *i = static_cast<Inimigo*>(LEs.operator++());
		//i->setPosicao(sf::Vector2f(50.f, 50.f), sf::Vector2f(70.f, 70.f));
		//gerenciadorColisoes.adicionarInimigo(i);	
    }
    void criarPlataformas() {

	    Fase::criarPlataformas();
	
    }
    void criarObstaculos() {

    }
    void set_Jogador(Jogador *j) {	
		LEs.incluir(j);
		gerenciadorColisoes.adicionarJogador(j);	
    }
    //Sobrescreve métodos da classe base
    void init() {
        std::cout << "Inicializando Fase1!" << std::endl;
        //Configura o jogador
	criarPlataformas();

        // Configura obstáculos específicos da Fase1
        //initObstaculos();
        
        // Finaliza inicialização
        //Fase::init(); // Chama init da classe base para adicionar entidades no gerenciador de colisões
    }
/*
void setObstaculos() {
        std::cout << "Adicionando obstáculos específicos para Fase1!" << std::endl;
        // Adiciona uma plataforma
        Plataforma* plataforma = new Plataforma(sf::Vector2f(400.f, 20.f), sf::Vector2f(50.f, 400.f));
        // lOsbtaculo.push_back(plataforma);
        // this->getObstaculoList().push_back(plataforma);
        addObstaculo(plataforma);

        // Adiciona outra plataforma ou obstáculos, se necessário
        Plataforma* outraPlataforma = new Plataforma(sf::Vector2f(300.f, 20.f), sf::Vector2f(500.f, 300.f));
        // this->getObstaculoList().push_back(outraPlataforma);
        addObstaculo(outraPlataforma);

        // Aqui você pode adicionar mais obstáculos, como inimigos, armadilhas, etc.
    }
*/
    void exec() {
        // std::cout << "Executando lógica de Fase1!" << std::endl;
        //Fase::exec(); // Usa a lógica padrão da fase (atualizar, desenhar, verificar colisões)
	Fase::exec();
	//desenhar();
	//Elemento<Entidade> *itr = LEs.getPrimeiro();

	/*while(itr != NULL) {	
		gerenciadorColisoes.tratarColisao(p1, p2);

		itr = itr->getProximo();
    	}*/
    }

void atualizar() {
        //atualiza fase, coesao
        //pJogador->atualizar();// JaoZika atualiza no JOGO
        // pObstaculo->atualizar();
        /*for(int i = 0; i < LEs.size(); i++){
            lOsbtaculo[i]->atualizar();
        }*/
		
}
void desenhar() {
        //LEs.desenhar();
        return;
}
};
