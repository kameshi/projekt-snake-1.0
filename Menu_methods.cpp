#include "Menu.hpp"
#include "Snake.hpp"
#include "Game.hpp"

Menu::Menu()
: mWindow(sf::VideoMode(Game::width, Game::height), "Snake v.1.0")
{
    mWindow.setFramerateLimit(60);

    heightButtonPosition = Game::height / 4;
    widthButtonPosition = Game::width / 2 - 50;

    font.loadFromFile("./fonts/moj1.ttf");
    file.open("./file/punkty.txt",  std::ios::app | std::ios::out );

}

void Menu::loadText()
{

    button[0].setFont(font);
    button[0].setString("PLAY");
    button[0].setPosition(widthButtonPosition,heightButtonPosition);

    heightButtonPosition += 83;

    button[1].setFont(font);
    button[1].setString("SETTINGS");
    button[1].setPosition(widthButtonPosition,heightButtonPosition);

    heightButtonPosition += 83;

    button[2].setFont(font);
    button[2].setString("SCORE");
    button[2].setPosition(widthButtonPosition,heightButtonPosition);

    heightButtonPosition += 83;

    button[3].setFont(font);
    button[3].setString("CLOSE");
    button[3].setPosition(widthButtonPosition,heightButtonPosition);
}

void Menu::settings()
{
    sf::Event event;
    while(!(mWindow.pollEvent(event)&& event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
    {
        mWindow.clear(sf::Color(237,246,125));
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
        mWindow.clear(sf::Color(237,246,125));
        //for(int j = 0; j < i; j++)
        //{
            textn.setFont(font);
            textn.setString(nick[0]);
            textn.setPosition(xn,y);
            mWindow.draw(textn);
            /*
            os.str( "" );
            os << scorei[i];
            scores[i] = "";
            scores[i] = os.str();
            texts.setFont(font);
            texts.setString(scores[0]);
            texts.setPosition(xs,y);
            mWindow.draw(texts);
            y += 20;
        }*/
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
            Game game(&mWindow);
            points = game.run();
            file << scorei[0] << points << std::endl;
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
    //readingFile();
    loadText();
    while(mWindow.isOpen())
    {
        mWindow.clear(sf::Color(237,246,125));

        mWindow.draw(button[0]);
        mWindow.draw(button[1]);
        mWindow.draw(button[2]);
        mWindow.draw(button[3]);
        detectPressButton();

        mWindow.display();
    }
}
