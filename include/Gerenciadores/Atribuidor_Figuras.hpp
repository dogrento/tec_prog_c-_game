#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class Atribuidor_Figuras{
private:
    sf::RectangleShape* pCorpo;
public:
    Atribuidor_Figuras();
    ~Atribuidor_Figuras();
    void setCorpo(sf::Vector2f tamanho);
    sf::RectangleShape* getCorpo() const;
};