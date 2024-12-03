#include <iostream>
// #include <SFML/Graphics.hpp>
#include "src/jogo.h"
using namespace std;

int main()
{
    Jogo jogo;
    // sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    // sf::CircleShape shape(50.f); // Diâmetro será 100, ajustado ao seu tamanho inicial
    // shape.setFillColor(sf::Color::Red);
    // shape.setPosition(50.f, 50.f); // Posição inicial

    // // Velocidade de movimento
    // float moveSpeed = 2.0f;

    // while (window.isOpen())
    // {
    //     sf::Event event;
    //     while (window.pollEvent(event))
    //     {
    //         if (event.type == sf::Event::Closed)
    //             window.close();
    //     }

    //     // Captura a entrada do teclado
    //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    //     {
    //         cout << "<-" << endl;
    //         shape.move(-moveSpeed, 0); // Move para a esquerda
    //     }
    //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    //     {
    //         cout << "->" << endl;
    //         shape.move(moveSpeed, 0); // Move para a direita
    //     }
    //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    //     {
    //         cout << "^" << endl;
    //         shape.move(0, -moveSpeed); // Move para cima
    //     }
    //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    //     {
    //         cout << "v" << endl;
    //         shape.move(0, moveSpeed); // Move para baixo
    //     }

    //     window.clear();
    //     window.draw(shape);
    //     window.display();
    // }

    return 0;
}
