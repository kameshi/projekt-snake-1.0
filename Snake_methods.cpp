#include "Menu.hpp"
#include "Snake.hpp"
#include "Game.hpp"

bool Snake::haveTurned = false;

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
    if(!haveTurned) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && direction != Directions::DOWN)
        {
            direction = Directions::UP;
            haveTurned = true;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && direction != Directions::UP)
        {
            direction = Directions::DOWN;
            haveTurned = true;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && direction != Directions::LEFT)
        {
            direction = Directions::RIGHT;
            haveTurned = true;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && direction != Directions::RIGHT)
        {
            direction = Directions::LEFT;
            haveTurned = true;
        }
    }
}
bool Snake::update()
{
    if(ownCollision() || wallCollision())
        return false;
    haveTurned = false;
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
void Snake::grow(const int n)
{
    if(n >= 0) {
        for(int i = 0; i < n; ++i) {
            nodes.push_back(mPlayer);
            if(nodes.size() > 2)
                nodes[nodes.size()-1].setPosition(nodes[nodes.size()-2].getPosition());
        }
    }
    else {
        for(int i = n; i < 0; ++i)
            nodes.pop_back();
    }
}
bool Snake::FoodColision(sf::Sprite * food, const int n)
{
    sf::Sprite head = nodes[0];
    sf::FloatRect headPosition = head.getGlobalBounds();
    sf::FloatRect foodPosition = food->getGlobalBounds();
    if(headPosition.intersects(foodPosition))
    {
        grow(n);
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
