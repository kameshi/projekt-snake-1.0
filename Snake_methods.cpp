#include "Snake.hpp"
#include "Game.hpp"

Snake::Snake() : direction(Directions::DOWN)
{
    mTexture.loadFromFile("./img/snake.png");
    mPlayer.setTexture(mTexture);
    nodes.push_back(mPlayer);
    nodes[0].setPosition(100, 100);
}
void Snake::moves()
{
    for(int i = nodes.size()-1; i > 0; --i) {
        nodes[i].setPosition(nodes[i-1].getPosition());
    }
    switch(direction)
    {
        case Directions::UP:
            nodes[0].move(0, -Snake::Width);
            break;
        case Directions::DOWN:
            nodes[0].move(0, Snake::Width);
            break;
        case Directions::LEFT:
            nodes[0].move(-Snake::Height, 0);
            break;
        case Directions::RIGHT:
            nodes[0].move(Snake::Height, 0);
            break;
    }
}
void Snake::handlePlayerInput()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && direction != Directions::DOWN)
    {
        direction = Directions::UP;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && direction != Directions::UP)
    {
        direction = Directions::DOWN;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && direction != Directions::LEFT)
    {
        direction = Directions::RIGHT;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && direction != Directions::RIGHT)
    {
        direction = Directions::LEFT;
    }
}
bool Snake::update()
{
    moves();
    return true;
}
void Snake::render(sf::RenderWindow &window)
{
    for(auto node : nodes)
    {
        window.draw(node);
    }
}
