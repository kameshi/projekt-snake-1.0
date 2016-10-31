#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


enum class Buttons
{
    PLAY, SETTINGS, SCORE, CLOSE
};

class Menu
{
    private:

        void settings();
        void score();
        void loadTexture();
        void detectPressButton();

    private:

        Buttons button;

        int heightButtonPosition;
        int widthButtonPosition;

        sf::RenderWindow mWindow;
        sf::Sprite buttonsp[4]; //tablica przycisków
        sf::Texture buttontx[4];

        int points;

    public:

        Menu();
        void render();
        void takeNick();

};

#endif // MENU_HPP_INCLUDED
