#include "Entes/Entidade.hpp"

Entidade::Entidade():
pos(0.f, 0.f)
{
    cout << "Construtora: Entidade" << endl;
}

Entidade::~Entidade()
{
    cout << "Destrutora: Entidade" << endl;
}

void Entidade::salvarBufferData()
{
    cout << "salvarBufferData(): Entidade" << endl;
}

void Entidade::setPosicao(const sf::Vector2f pos_)
{
    cout << "setPosicao(): Entidade" << endl;
    pos = pos_;
}

sf::Vector2f Entidade::getPosicao() const
{
    cout << "getPosicao(): Entidade" << endl;
    return pos;
}
