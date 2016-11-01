#include "Menu.hpp"
#include "Snake.hpp"
#include "Game.hpp"

Menu::Menu()
: mWindow(sf::VideoMode(Game::width, Game::height), "Snake v.1.0")
{
    mWindow.setFramerateLimit(60);

    font.loadFromFile("./fonts/moj1.ttf");
    file.open("./file/punkty.txt", std::ios::out | std::ios::app | std::ios::in );

}

void Menu::loadText()
{

    button[0].setFont(font);
    button[0].setColor(sf::Color(Game::fontColor[0],Game::fontColor[1],Game::fontColor[2], Game::fontColor[3]));
    button[0].setString("PLAY");
    button[0].setPosition(340,125);

    button[1].setFont(font);
    button[1].setColor(sf::Color(Game::fontColor[0],Game::fontColor[1],Game::fontColor[2], Game::fontColor[3]));
    button[1].setString("SETTINGS");
    button[1].setPosition(290,225);

    button[2].setFont(font);
    button[2].setColor(sf::Color(Game::fontColor[0],Game::fontColor[1],Game::fontColor[2], Game::fontColor[3]));
    button[2].setString("SCORE");
    button[2].setPosition(320,325);

    button[3].setFont(font);
    button[3].setColor(sf::Color(Game::fontColor[0],Game::fontColor[1],Game::fontColor[2], Game::fontColor[3]));
    button[3].setString("CLOSE");
    button[3].setPosition(322,425);
}

void Menu::settings()
{
    sf::Event event;
    while(!(mWindow.pollEvent(event)&& event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
    {
        mWindow.clear(sf::Color(Game::backgroundColor[0],Game::backgroundColor[1],Game::backgroundColor[2], Game::backgroundColor[3]));
        mWindow.display();
    }
}

void Menu::score()
{
    std::ostringstream os;
    sf::Text textn;
    sf::Text texts;
    int y = 200;
    int xn = 200;
    int xs = xn + 200;
    sf::Event event;
    while(!(mWindow.pollEvent(event)&& event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
    {
        mWindow.clear(sf::Color(Game::backgroundColor[0],Game::backgroundColor[1],Game::backgroundColor[2], Game::backgroundColor[3]));
        //for(int j = 0; j < i; j++)
        //{
            textn.setFont(font);
            textn.setString(nick[4]);
            textn.setPosition(xn,y);
            os.str( "" );
            os << scorei[i];
            scores[i] = "";
            scores[i] = os.str();
            texts.setFont(font);
            texts.setString(scores[4]);
            texts.setPosition(xs,y);
            mWindow.draw(textn);
            mWindow.draw(texts);
            //y += 20;
        //}
        mWindow.display();
    }
}

void Menu::detectPressButton()
{
    sf::Event event;
    sf::Vector2i coordinates;
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        coordinates = sf::Mouse::getPosition( mWindow );
        if(coordinates.x > 340 && coordinates.x < 470 && coordinates.y > 125 && coordinates.y < 160)
        {
            Game game(&mWindow);
            points = game.run();
        }
        if(coordinates.x > 290 && coordinates.x < 510 && coordinates.y > 225 && coordinates.y < 260)
        {
            settings();
        }
        if(coordinates.x > 320 && coordinates.x < 483 && coordinates.y > 325 && coordinates.y < 360)
        {
            score();
        }
        if(coordinates.x > 322 && coordinates.x < 480 && coordinates.y > 425 && coordinates.y < 460)
        {
            mWindow.close();
        }
        if(mWindow.pollEvent(event) && event.type == sf::Event::Closed)
        {
            file << nick[2] << points << std::endl;
            file.close();
            mWindow.close();
        }
    }
}

void Menu::readingFile(){
    int i = 0;
    while(i < 10)
    {
        file >> (nick[i]);
        file >> (scorei[i]);
        i++;
    }
}

void Menu::render()
{
    readingFile();
    loadText();
    while(mWindow.isOpen())
    {
        mWindow.clear(sf::Color(Game::backgroundColor[0],Game::backgroundColor[1],Game::backgroundColor[2], Game::backgroundColor[3]));

        mWindow.draw(button[0]);
        mWindow.draw(button[1]);
        mWindow.draw(button[2]);
        mWindow.draw(button[3]);
        detectPressButton();

        mWindow.display();
    }
}
