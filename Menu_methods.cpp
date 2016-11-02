#include "Menu.hpp"
#include "Snake.hpp"
#include "Game.hpp"

Menu::Menu(sf::RenderWindow * gWindow)
{
    Menu::mWindow = gWindow;

    font.loadFromFile("./fonts/moj1.ttf");

}

void Menu::loadText()
{
    title.setFont(font);
    title.setColor(sf::Color(Game::fontColor[0],Game::fontColor[1],Game::fontColor[2], Game::fontColor[3]));
    title.setString("WONSZ");
    title.setStyle(sf::Text::Bold);
    title.setPosition(311, 42);

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
    while(!(mWindow->pollEvent(event)&& event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
    {
        mWindow->clear(sf::Color(Game::backgroundColor[0],Game::backgroundColor[1],Game::backgroundColor[2], Game::backgroundColor[3]));
        mWindow->display();
    }
}

void Menu::score()
{
    std::ostringstream os;
    sf::Text textn;
    textn.setFont(font);
    int y = 100;
    int xn = 100;
    int xs = xn + 500;
    sf::Event event;
    std::string srore;
<<<<<<< HEAD
    title.setString("WYNIKI");
    while(!(mWindow.pollEvent(event)&& event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
    {
        mWindow.clear(sf::Color(Game::backgroundColor[0],Game::backgroundColor[1],Game::backgroundColor[2], Game::backgroundColor[3]));
        y = 100;
        for(int j = 0; j <= i; j++)
=======
    i = 10;
    while(!(mWindow->pollEvent(event)&& event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
    {
        mWindow->clear(sf::Color(Game::backgroundColor[0],Game::backgroundColor[1],Game::backgroundColor[2], Game::backgroundColor[3]));
        y = 200;
        for(int j = 0; j < i; j++)
>>>>>>> origin/master
        {
            textn.setString(nick[j]);
            textn.setPosition(xn,y);
            mWindow.draw(textn);
            os.str( "" );
            os << scorei[j];
            srore = os.str();
<<<<<<< HEAD
            textn.setString(srore);
            textn.setPosition(xs,y);
            mWindow.draw(textn);
=======
            texts.setFont(font);
            texts.setString(srore);
            texts.setPosition(xs,y);
            mWindow->draw(texts);

            mWindow->draw(textn);

>>>>>>> origin/master
            y += 30;
        }
        mWindow.draw(title);
        mWindow.display();
    }
}

<<<<<<< HEAD
void Menu::takeNick()
{
    sf::Text textn;
    textn.setFont(font);
    sf::Event event;
    std::string nickn;
    sf::String nickS;
    int z;
    while(!(mWindow.pollEvent(event)&& event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return))
    {
        mWindow.clear(sf::Color(Game::backgroundColor[0],Game::backgroundColor[1],Game::backgroundColor[2], Game::backgroundColor[3]));
            if( event.type == sf::Event::TextEntered )
            {
                if( event.text.unicode < 128 && nickn.size() < 10)
                {
                    nickn += static_cast < char >( event.text.unicode );
                    textn.setString(nickn);
                }
            }
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::BackSpace)
            {
                nickn.erase(nickn.size() - 1, 1);
                textn.setString(nickn);
            }
            textn.setPosition(200,200);
            mWindow.draw(textn);
        mWindow.display();
=======
            //texts.setFont(font);
            //texts.setString(nick[2]);
            //texts.setPosition(xn,y+30);



        mWindow->display();
>>>>>>> origin/master
    }
    nick[i] = nickn;
}
void Menu::checkScore(){
    int help;
    if(i < 10)
    {
        i++;
        takeNick();
        scorei[i]=points;

    }
    if(scorei[i] < points)
    {
        takeNick();
        scorei[i] = points;
       // while()
    }
}

void Menu::detectPressButton()
{
    sf::Event event;
    sf::Vector2i coordinates;
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        coordinates = sf::Mouse::getPosition( *mWindow );
        if(coordinates.x > 340 && coordinates.x < 470 && coordinates.y > 125 && coordinates.y < 160)
        {
            Game game(mWindow);
            points = game.run();
            checkScore();
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
            mWindow->close();
        }
        if(mWindow->pollEvent(event) && event.type == sf::Event::Closed)
        {
            file.open("./file/punkty.txt", std::ios::out | std::ios::trunc );
            for(int j = 0; j <= i; j++)
            {
              // file << nick[j] << "  " << scorei[j] << std::endl;
            }
            file.close();
<<<<<<< HEAD

            mWindow.close();
=======
            mWindow->close();
>>>>>>> origin/master
        }
    }
}

void Menu::readingFile(){
    i = 0;
    file.open("./file/punkty.txt", std::ios::in );
    while(file.good() && i < 11)
    {
        file >> nick[i] >> scorei[i];
        i++;
    }
    i--;
    file.close();
    file.clear();
}

void Menu::render()
{
    readingFile();
    loadText();
    while(mWindow->isOpen())
    {
        mWindow->clear(sf::Color(Game::backgroundColor[0],Game::backgroundColor[1],Game::backgroundColor[2], Game::backgroundColor[3]));

        mWindow->draw(title);
        mWindow->draw(button[0]);
        mWindow->draw(button[1]);
        mWindow->draw(button[2]);
        mWindow->draw(button[3]);
        detectPressButton();

        mWindow->display();
    }
}
