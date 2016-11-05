#include "Menu.hpp"
#include "Snake.hpp"
#include "Game.hpp"
#include "Welcomescreen.hpp"

sf::Font Welcomescreen::font;

Welcomescreen::Welcomescreen()
: mWindow(sf::VideoMode(Game::width, Game::height), "Snake v.1.0")
{
    mWindow.setFramerateLimit(60);
    mWindow.setKeyRepeatEnabled(false);

    font.loadFromFile("./fonts/moj1.ttf");
}
void Welcomescreen::loadText()
{
    text[0].setFont(font);
    text[0].setColor(sf::Color(Game::fontColor[0],Game::fontColor[1],Game::fontColor[2], Game::fontColor[3]));
    text[0].setString(std::wstring(L"MAREK MADEŁA & DAMIAN ŁYŻWA"));
    text[0].setScale(0.8, 0.8);
    text[0].setPosition(150, 100);

    text[1].setFont(font);
    text[1].setColor(sf::Color(Game::fontColor[0],Game::fontColor[1],Game::fontColor[2], Game::fontColor[3]));
    text[1].setString("present");
    text[1].setScale(0.6, 0.6);
    text[1].setPosition(350, 140);

    text[2].setFont(font);
    text[2].setColor(sf::Color(Game::fontColor[0],Game::fontColor[1],Game::fontColor[2], Game::fontColor[3]));
    text[2].setString("WONSZ");
    text[2].setScale(1.6, 1.6);
    text[2].setStyle(sf::Text::Bold);
    text[2].setPosition(280, 200);

    text[3].setFont(font);
    text[3].setColor(sf::Color(Game::fontColor[0],Game::fontColor[1],Game::fontColor[2], Game::fontColor[3]));
    text[3].setString("press [enter] to continue");
    text[3].setScale(0.6, 0.6);
    text[3].setPosition(260, 360);
}
void Welcomescreen::handleInputs()
{
    sf::Event event;
    while(mWindow.pollEvent(event))
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
        {
            Menu menu(&mWindow, &font);
            menu.render();
        }
        if(event.type == sf::Event::Closed)
            mWindow.close();
    }
}
void Welcomescreen::render()
{
    loadText();
    while(mWindow.isOpen())
    {
        mWindow.clear(sf::Color(Game::backgroundColor[0],Game::backgroundColor[1],Game::backgroundColor[2], Game::backgroundColor[3]));

        mWindow.draw(text[0]);
        mWindow.draw(text[1]);
        mWindow.draw(text[2]);
        mWindow.draw(text[3]);
        handleInputs();
        mWindow.display();
    }
}
