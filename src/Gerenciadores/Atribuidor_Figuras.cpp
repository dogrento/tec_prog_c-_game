#include "Gerenciadores/Atribuidor_Figuras.hpp"

Atribuidor_Figuras::Atribuidor_Figuras(sf::Vector2f tamanho_):
pCorpo(nullptr),
tamanho(tamanho_)
{
}

Atribuidor_Figuras::~Atribuidor_Figuras()
{
}

void Atribuidor_Figuras::setTamanho(sf::Vector2f tamanho)
{
}

sf::Vector2f Atribuidor_Figuras::getTamanho() const
{
    return tamanho;
}

void Atribuidor_Figuras::setCorpo()
{
    pCorpo = new sf::RectangleShape(getTamanho());
}

sf::RectangleShape *Atribuidor_Figuras::getCorpo() const
{
    return pCorpo;
}
