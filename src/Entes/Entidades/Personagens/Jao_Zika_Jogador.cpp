#include "Entes/Entidades/Personagens/Jao_Zika_Jogador.hpp"

Jao_Zika_Jogador::Jao_Zika_Jogador():
    pontos(0)
{
    cout << "Construtora: Jao_Zika_Jogador" << endl;
}
Jao_Zika_Jogador::~Jao_Zika_Jogador()
{
    cout << "Destrutora: Jao_Zika_Jogador" << endl;
}

void Jao_Zika_Jogador::executar()
{
    cout << "executar(): Jao_Zika_Jogador" << endl;
    mover();
    atualizar();
    // Ente::desenhar();
    Ente::desenhar();
}

void Jao_Zika_Jogador::atualizar()
{
    cout << "atualizar(): Jao_Zika_Jogador" << endl;
    // mover();
    Entidade::atualizar();
    // Ente::desenhar();
}
void Jao_Zika_Jogador::salvar()
{
    cout << "salvar(): Jao_Zika_Jogador" << endl;
}

void Jao_Zika_Jogador::mover()
{
    cout << "mover(): Jao_Zika_Jogador" << endl;
    // velocidade = sf::Vector2f(0.f, 0.f);
    this->setVelocidade(sf::Vector2f(0.f, 0.f));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        velocidade.y = -5.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        velocidade.y = 5.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        velocidade.x = -5.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        velocidade.x = 5.f;
    }
}
void Jao_Zika_Jogador::setPontos(const int p)
{
    cout << "setPontos(const int p): Jao_Zika_Jogador" << endl;
    operator=(p);
}

int Jao_Zika_Jogador::getPontos() const
{
    cout << "getPontos(): Jao_Zika_Jogador" << endl;
    return 0;
}

void Jao_Zika_Jogador::operator=(int p)
{
    cout << "operator=(int p): Jao_Zika_Jogador" << endl;
    pontos = p;
}
