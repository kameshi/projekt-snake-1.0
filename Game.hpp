#ifndef CLASSES_HPP_INCLUDED
#define CLASSES_HPP_INCLUDED

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Snake.hpp"

class Game
{
public:
    Game();
    void run();
private:
    void update();                                // aktualizuje gre
    void render();                                                  //Tworzy obraz w oknie i wyswietla go
    void handlePlayerInput();  //obsluguje dane wejsciowe od uzytkownika
private:

    static const sf::Time TimePerFrame;

    sf::RenderWindow mWindow;

    //dodajemy Snake'a
    Snake snake;

};

#endif // CLASSES_HPP_INCLUDED
