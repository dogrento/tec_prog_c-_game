#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class Atribuidor_Figuras{
private:
    sf::RectangleShape* pCorpo;
    sf::Vector2f tamanho;
public:
    Atribuidor_Figuras(sf::Vector2f tamanho_);
    ~Atribuidor_Figuras();
    void setTamanho(sf::Vector2f tamanho_);
    sf::Vector2f getTamanho() const;
    void setCorpo();
    sf::RectangleShape* getCorpo() const;
};