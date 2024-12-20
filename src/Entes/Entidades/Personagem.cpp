#include "Entes/Entidades/Personagem.hpp"

Personagem::Personagem():
    num_vidas(-1)
{
    cout << "Construtora: Personagem" << endl;
}

Personagem::~Personagem()
{
    cout << "Destrutora: Personagem" << endl;
}

void Personagem::salvarBufferData()
{
    cout << "salvarBufferData(): Personagem" << endl;
}

void Personagem::mover()
{
    cout << "mover(): Personagem" << endl;
}

void Personagem::setVidas(int v)
{
    cout << "setVidas(int v): Personagem" << endl;
    num_vidas = v;
}

int Personagem::getVidas() const
{
    cout << "getVidas(): Personagem" << endl;
    return 0;
}
