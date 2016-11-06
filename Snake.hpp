#ifndef SNAKE_HPP_INCLUDED
#define SNAKE_HPP_INCLUDED

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

enum class Directions
{
        LEFT, RIGHT, UP, DOWN
};

class Snake
{
    public:
        Snake();
        void render(sf::RenderWindow *window);
        bool update();
        void handlePlayerInput();
        //metody dot. jedzenia
        bool FoodColision(sf::Sprite * food, const int n);
        bool isFoodOnBody(sf::FloatRect fR);
        //wielkosci jednego snake-node
        static const int Height = 20;
        static const int Width = 20;

        void moves(); //metoda przemiszczajaca weza

    private:
        static bool haveTurned;
        sf::Texture mTexture;
        sf::Sprite mPlayer;
        std::vector<sf::Sprite> nodes;
        Directions direction;


        void grow(const int n); //metoda umozliwiajaca wzrost weza
        bool ownCollision() const; //czy wonsz zjada sam siebie
        bool wallCollision(); //czy uderzyl w sciane

};

#endif // SNAKE_HPP_INCLUDED
