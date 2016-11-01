#ifndef CLASSES_HPP_INCLUDED
#define CLASSES_HPP_INCLUDED

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>

#include "Snake.hpp"

class Game
{
    public:

        Game(sf::RenderWindow *gWindow);
        int run();

        //szerokosc i wysokosc okna
        static const int width = 800;
        static const int height = 600;

        //kolory w grze
        static const uint8_t backgroundColor[4];
        static const uint8_t fontColor[4];

    private:

        bool update();                                // aktualizuje gre
        void render();                                                  //Tworzy obraz w oknie i wyswietla go
        void handlePlayerInput();  //obsluguje dane wejsciowe od uzytkownika

    private:
        static const float playerSpeed;
        static const sf::Time TimePerFrame;

        sf::Font font;

        sf::RenderWindow * mWindow;
        //jedzonko
        sf::Texture fd;
        sf::Sprite food;

        //dodajemy Snake'a
        Snake snake;

        int points = 0;//zlicza punkty
        std::ostringstream pointsos;//strumieñ pomocny przy zamianie int na sting
        std::string pointss;//string z iloœciami punktów wypisywany na ekran
        sf::Text point;

};

#endif // CLASSES_HPP_INCLUDED
