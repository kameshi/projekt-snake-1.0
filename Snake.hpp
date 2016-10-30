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
        //metody dot. jedzenia
        bool FoodColision(sf::RectangleShape food);
        bool isFoodOnBody(sf::FloatRect fR);
        //wielkosci jednego snake-node
        static const int Height = 20;
        static const int Width = 20;

    private:

        sf::Texture mTexture;
        sf::Sprite mPlayer;
        std::vector<sf::Sprite> nodes;
        Directions direction;

        void moves(); //metoda przemiszczajaca weza
        void grow(); //metoda umozliwiajaca wzrost weza
        bool ownCollision() const; //czy wonsz zjada sam siebie

};

#endif // SNAKE_HPP_INCLUDED
