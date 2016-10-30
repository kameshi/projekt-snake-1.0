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

    //szerokosc i wysokosc okna
    static const int width = 800;
    static const int height = 600;
private:
    bool update();                                // aktualizuje gre
    void render();                                                  //Tworzy obraz w oknie i wyswietla go
    void handlePlayerInput();  //obsluguje dane wejsciowe od uzytkownika
private:

    static const sf::Time TimePerFrame;

    sf::RenderWindow mWindow;
    //jedzonko
    sf::RectangleShape food;

    //dodajemy Snake'a
    Snake snake;

};

#endif // CLASSES_HPP_INCLUDED
