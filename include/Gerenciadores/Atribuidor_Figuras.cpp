#include "Atribuidor_Figuras.hpp"

Atribuidor_Figuras::Atribuidor_Figuras():
pCorpo(nullptr)
{
}

Atribuidor_Figuras::~Atribuidor_Figuras()
{
}

void Atribuidor_Figuras::setCorpo(sf::Vector2f tamanho)
{
    pCorpo = new sf::RectangleShape(tamanho);
}

sf::RectangleShape *Atribuidor_Figuras::getCorpo() const
{
    return pCorpo;
}
