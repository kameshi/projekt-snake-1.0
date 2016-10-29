#ifndef CLASSES_HPP_INCLUDED
#define CLASSES_HPP_INCLUDED

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Game
{
public:
    Game();
    void run();
private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
private:
    static const float PlayerSpeed;
    static const sf::Time TimePerFrame;

    sf::RenderWindow mWindow;
    sf::Texture mTexture;
    sf::Sprite mPlayer;

    bool mIsMovingUp;
    bool mIsMovingDown;
    bool mIsMovingRight;
    bool mIsMovingLeft;

};

#endif // CLASSES_HPP_INCLUDED
