#include "Menu.hpp"
#include "Snake.hpp"
#include "Game.hpp"

Menu::Menu()
: mWindow(sf::VideoMode(Game::width, Game::height), "Snake v.1.0")
{
    heightButtonPosition = Game::height / 4;
    widthButtonPosition = Game::width / 2 - 50;
}

void Menu::loadTexture()
{

    buttontx[0].loadFromFile("./img/PLAY.png");
    buttonsp[0].setTexture(buttontx[0]);
    buttonsp[0].setPosition(widthButtonPosition,heightButtonPosition);

    heightButtonPosition += 83;

    buttontx[1].loadFromFile("./img/SETTINGS.png");
    buttonsp[1].setTexture(buttontx[1]);
    buttonsp[1].setPosition(widthButtonPosition,heightButtonPosition);

    heightButtonPosition += 83;

    buttontx[2].loadFromFile("./img/SCORE.png");
    buttonsp[2].setTexture(buttontx[2]);
    buttonsp[2].setPosition(widthButtonPosition,heightButtonPosition);

    heightButtonPosition += 83;

    buttontx[3].loadFromFile("./img/CLOSE.png");
    buttonsp[3].setTexture(buttontx[3]);
    buttonsp[3].setPosition(widthButtonPosition,heightButtonPosition);
}

void Menu::settings()
{
    sf::Event event;
    bool close = true;
    while(!(mWindow.pollEvent(event)&& event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
    {
        mWindow.clear(sf::Color(237,246,125));
        mWindow.display();
    }
}

void Menu::score()
{
    sf::Event event;
    while(!(mWindow.pollEvent(event)&& event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
    {
        mWindow.clear(sf::Color(237,246,125));
        mWindow.display();
    }
}

void Menu::detectPressButton()
{
    sf::Event event;
    heightButtonPosition = Game::height / 4;
    sf::Vector2i coordinates;
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        coordinates = sf::Mouse::getPosition( mWindow );
        if(coordinates.x > widthButtonPosition && coordinates.x < widthButtonPosition + 100 && coordinates.y > heightButtonPosition && coordinates.y < heightButtonPosition + 50)
        {
            Game game;
            points = game.run();
            //takeNick();
        }
        heightButtonPosition += 83;
        if(coordinates.x > widthButtonPosition && coordinates.x < widthButtonPosition + 100 && coordinates.y > heightButtonPosition && coordinates.y < heightButtonPosition + 50)
        {
            settings();
        }
        heightButtonPosition += 83;
        if(coordinates.x > widthButtonPosition && coordinates.x < widthButtonPosition + 100 && coordinates.y > heightButtonPosition && coordinates.y < heightButtonPosition + 50)
        {
            score();
        }
        heightButtonPosition += 83;
        if(coordinates.x > widthButtonPosition && coordinates.x < widthButtonPosition + 100 && coordinates.y > heightButtonPosition && coordinates.y < heightButtonPosition + 50)
        {
            mWindow.close();
        }
        if(mWindow.pollEvent(event) && event.type == sf::Event::Closed)
        {
            mWindow.close();
        }
    }
}

void Menu::render()
{
    loadTexture();
    while(mWindow.isOpen())
    {
        mWindow.clear(sf::Color(237,246,125));

        mWindow.draw(buttonsp[0]);
        mWindow.draw(buttonsp[1]);
        mWindow.draw(buttonsp[2]);
        mWindow.draw(buttonsp[3]);
        detectPressButton();

        mWindow.display();
    }
}
