#pragma once

#include <iostream>
using namespace std;

/*
    CLASSE ABSTRATA.
*/
class Ente{
protected:
    int id;
    // static Gerenciador_Grafico* pGG; // Seguindo Singleton, nao sera necessario que seja static??
    // Figura* pFIg;

public:
    Ente();
    ~Ente();
    virtual void executar() = 0; // virtual puro. DEVE SER DEFINIDA EM SUAS DERIVADAS
    void desenhar();

    void setID(const int id_);
    int getID() const;
};