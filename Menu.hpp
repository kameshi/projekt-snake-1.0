#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>

class Menu
{
    private:

        void score();
        void loadText();
        void detectPressButton();
        void checkScore();
        void readingFile();
        std::string takeNick();

    private:

        sf::RenderWindow * mWindow;
        sf::Font * font;
        sf::Text button[3];
        sf::Text title;

        int points;

        std::fstream file;

        int i;
        int scorei[10];
        std::string nick[10];

    public:

        Menu(sf::RenderWindow * gWindow, sf::Font *font);
        void render();

};

#endif // MENU_HPP_INCLUDED
