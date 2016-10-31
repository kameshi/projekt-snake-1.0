#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>

class Menu
{
    private:

        void settings();
        void score();
        void loadText();
        void detectPressButton();
        void checkScore();
        void readingFile();

    private:

        int heightButtonPosition;
        int widthButtonPosition;

        sf::RenderWindow mWindow;
        //sf::Sprite buttonsp[4]; //tablica przycisków
        //sf::Texture buttontx[4];
        sf::Font font;
        sf::Text button[4];

        int points;

        std::fstream file;

        int i;
        int scorei[11];
        std::string nick[11];
        std::string scores[11];

    public:

        Menu();
        void render();
        void takeNick();

};

#endif // MENU_HPP_INCLUDED
