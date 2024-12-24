#include "Ente.hpp"

Ente::Ente():
id(-1),
pGG(nullptr)
{
    cout << "Construtora: Ente" << endl;
    getInstancia();
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

void Ente::setFig(sf::Vector2f tam)
{
    cout << "setFig(sf::Vector2f tam): Ente" << endl;
    // pFig = new sf::RectangleShape(tam);
    pFig = new Atribuidor_Figuras(sf::Vector2f(50.f, 50.f));
    pFig->setCorpo();
    // pFig->getCorpo()->setPosition(pos);
    // pFig->setPosition(pos);
}

Atribuidor_Figuras *Ente::getFig() const
{
    cout << "getFig(): Ente" << endl;
    return pFig;
}
