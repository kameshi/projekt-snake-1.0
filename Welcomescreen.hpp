#ifndef WELCOMESCREEN_HPP_INCLUDED
#define WELCOMESCREEN_HPP_INCLUDED

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Welcomescreen
{
public:
    Welcomescreen();
    void render();

private:
    void loadText();
    void handleInputs();

private:
    sf::Text text[4];
    sf::Font font;
    sf::RenderWindow mWindow;
};

#endif // WELCOMESCREEN_HPP_INCLUDED
