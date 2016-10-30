#ifndef SNAKE_HPP_INCLUDED
#define SNAKE_HPP_INCLUDED

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

enum class Directions
{
        LEFT, RIGHT, UP, DOWN
};

class Snake
{
    public:
        Snake();
        void render(sf::RenderWindow &window);
        bool update();
        void handlePlayerInput();

        static const int Height = 20;
        static const int Width = 20;

    private:

        sf::Texture mTexture;
        sf::Sprite mPlayer;
        std::vector<sf::Sprite> nodes;
        Directions direction;

        void moves();

};

#endif // SNAKE_HPP_INCLUDED
