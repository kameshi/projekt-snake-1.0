#include "Menu.hpp"
#include "Snake.hpp"
#include "Game.hpp"

Snake::Snake() : direction(Directions::DOWN)
{
    mTexture.loadFromFile("./img/snakeSkin02.png");
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
    if(ownCollision() || wallCollision())
        return false;
    moves();
    return true;
}
void Snake::render(sf::RenderWindow *window)
{
    for(auto node : nodes)
    {
        window->draw(node);
    }
}
void Snake::grow()
{
    nodes.push_back(mPlayer);
}
bool Snake::FoodColision(sf::Sprite food)
{
    sf::Sprite head = nodes[0];
    sf::FloatRect headPosition = head.getGlobalBounds();
    sf::FloatRect foodPosition = food.getGlobalBounds();
    if(headPosition.intersects(foodPosition))
    {
        grow();
        return true;
    }
    return false;
}
bool Snake::isFoodOnBody(sf::FloatRect fR)
{
    for(auto node : nodes)
    {
        sf::FloatRect tmp = node.getGlobalBounds();
        if(tmp == fR)
        {
            return true;
        }
    }
    return false;
}
bool Snake::ownCollision() const
{
    sf::Sprite head = nodes[0];
    sf::FloatRect headPosition = head.getGlobalBounds();
    sf::FloatRect tmp;
    for(int i = nodes.size()-1; i > 0; --i)
    {
        tmp = nodes[i].getGlobalBounds();
        if(headPosition.intersects(tmp))
            return true;
    }
    return false;
}
bool Snake::wallCollision()
{
    sf::FloatRect headPosition = nodes[0].getGlobalBounds();
    float x = headPosition.left;
    float y = headPosition.top;
    if(x == -20 || x == Game::width || y == -20 || y == Game::height)
        return true;
    return false;
}
