#include "Entes/Entidade.hpp"

Entidade::Entidade():
posicao(0.f, 0.f),
velocidade(0.f, 0.f)
{
    cout << "Construtora: Entidade" << endl;
}

Entidade::~Entidade()
{
    cout << "Destrutora: Entidade" << endl;
}
void Entidade::atualizar(){
        // Atualizar posição com base na velocidade
    // posicao += velocidade;
    setPosicao(getPosicao()+getVelocidade());
    cout << getPosicao().x << " " << getPosicao().y << endl;
    pFig->setPosition(posicao);
}
void Entidade::salvarBufferData() 
{
    cout << "salvarBufferData(): Entidade" << endl;
}

void Entidade::setPosicao(const sf::Vector2f pos_)
{
    cout << "setPosicao(): Entidade" << endl;
    posicao = pos_;
}

sf::Vector2f Entidade::getPosicao() const
{
    cout << "getPosicao(): Entidade" << endl;
    return posicao;
}

void Entidade::setVelocidade(const sf::Vector2f vel_)
{
    cout << "setVelocidade(const sf::Vector2f vel_): Entidade" << endl;
    velocidade = vel_;
}

sf::Vector2f Entidade::getVelocidade() const
{
    cout << "getVelocidade(): Entidade" << endl;
    return velocidade;
}
