#include "Snake.hpp"
#include "Game.hpp"

Snake::Snake() : direction(Directions::DOWN)
{
    nodes.push_back(mPlayer);
    nodes[0].setPosition(100, 100);
}
