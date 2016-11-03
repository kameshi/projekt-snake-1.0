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
        void takeNick(std::string * nickn);

    private:

        sf::RenderWindow * mWindow;
        //sf::Sprite buttonsp[4]; //tablica przycisków
        //sf::Texture buttontx[4];
        sf::Font font;
        sf::Text button[4];
        sf::Text title;

        int points;

        std::fstream file;

        int i;
        int scorei[11];
        std::string nick[11];
        std::string scores[11];

    public:

        Menu(sf::RenderWindow * gWindow);
        void render();

};

#endif // MENU_HPP_INCLUDED
