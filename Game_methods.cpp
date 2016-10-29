#include "Game.hpp"

const float Game::PlayerSpeed = 100.f;
const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game()
: mWindow(sf::VideoMode(640, 480), "Snake v.1.0")
, mTexture()
, mPlayer()
, mIsMovingUp(false)
, mIsMovingDown(false)
, mIsMovingRight(false)
, mIsMovingLeft(false)
{
    if(!mTexture.loadFromFile("img/snake.png")) {
        //jezeli nie wczyta to obsluga bledu... tylko jaka????
    }
    mPlayer.setTexture(mTexture);
    mPlayer.setPosition(100.f, 100.f);
}
void Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while(mWindow.isOpen())
    {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while(timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render();
    }
}
void Game::processEvents() {
    sf::Event event;
    while(mWindow.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                mWindow.close();
                break;
        }
    }
}
void Game::update(sf::Time deltaTime) {
    sf::Vector2f movement(0.f, 0.f);
    if(mIsMovingUp)
        movement.y -= PlayerSpeed;
    if(mIsMovingDown)
        movement.y += PlayerSpeed;
    if(mIsMovingLeft)
        movement.x -= PlayerSpeed;
    if(mIsMovingRight)
        movement.x += PlayerSpeed;

    mPlayer.move(movement * deltaTime.asSeconds());
}
void Game::render() {
    mWindow.clear(sf::Color(237,246,125));
    mWindow.draw(mPlayer);
    mWindow.display();
}
void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    if(key == sf::Keyboard::Up)
        mIsMovingUp = isPressed;
    else if(key == sf::Keyboard::Down)
        mIsMovingDown = isPressed;
    else if(key == sf::Keyboard::Left)
        mIsMovingLeft = isPressed;
    else if(key == sf::Keyboard::Right)
        mIsMovingRight = isPressed;
}
