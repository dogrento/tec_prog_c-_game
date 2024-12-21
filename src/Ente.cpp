#include "Ente.hpp"

Ente::Ente():
id(-1),
pGG(Gerenciador_Grafico::getInstancia())
{
    cout << "Construtora: Ente" << endl;
    setFig();
}

Ente::~Ente()
{
    cout << "Destrutora: Ente" << endl;
}

void Ente::desenhar()
{
    cout << "desenhar(): Ente" << endl;
    pGG->desenhar(this);
}

void Ente::setID(int id_)
{
    cout << "setID(): Ente" << endl;
    id = id_;
}

int Ente::getID() const
{
    cout << "getID(): Ente" << endl;
    return 0;
}

void Ente::setFig(sf::Vector2f tam, sf::Vector2f pos)
{
    cout << "setFig(sf::Vector2f tam): Ente" << endl;
    pFig = new sf::RectangleShape(tam);
    pFig->setPosition(pos);
}

sf::RectangleShape *Ente::getFig() const
{
    cout << "getFig(): Ente" << endl;
    return pFig;
}
