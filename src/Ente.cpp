#include "Ente.hpp"

Ente::Ente():
id(-1)
{
    cout << "Construtora: Ente" << endl;
}

Ente::~Ente()
{
    cout << "Destrutora: Ente" << endl;
}

void Ente::desenhar()
{
    cout << "desenhar(): Ente" << endl;
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
