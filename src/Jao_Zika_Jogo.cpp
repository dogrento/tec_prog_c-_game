#include "Jao_Zika_Jogo.hpp"

Jao_Zika_Jogo::Jao_Zika_Jogo():
pJZ(nullptr)
{
    cout << "Construtora: Jao_Zika_Jogo" << endl;
}

Jao_Zika_Jogo::~Jao_Zika_Jogo()
{
    cout << "Destrutora: Jao_Zika_Jogo" << endl;
    delete pJZ;
}

void Jao_Zika_Jogo::executar()
{
    cout << "executar: Jao_Zika_Jogo" << endl;
    pJZ = new Jao_Zika_Jogador;
    pJZ->executar();
}
