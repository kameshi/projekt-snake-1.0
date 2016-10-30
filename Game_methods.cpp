#include "Game.hpp"


const sf::Time Game::TimePerFrame = sf::seconds(1.f/10.f);

Game::Game()
: mWindow(sf::VideoMode(640, 480), "Snake v.1.0")
{
    mWindow.setFramerateLimit(60);
}
void Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while(mWindow.isOpen())
    {
        timeSinceLastUpdate += clock.restart();

        handlePlayerInput();
        while(timeSinceLastUpdate > Game::TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            update();
        }
        render();
    }
}

void Game::handlePlayerInput()
{
    sf::Event event;
    while(mWindow.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            mWindow.close();
    }
    snake.handlePlayerInput();
}
void Game::update() {
    snake.update();
}
void Game::render() {
    mWindow.clear(sf::Color(237,246,125));
    snake.render(mWindow);
    mWindow.display();
}
