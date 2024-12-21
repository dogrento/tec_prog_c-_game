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
    this->desenhar();
}

void Jao_Zika_Jogador::salvar()
{
    cout << "salvar(): Jao_Zika_Jogador" << endl;
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
