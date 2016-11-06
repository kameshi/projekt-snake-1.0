#include "Menu.hpp"
#include "Snake.hpp"
#include "Game.hpp"

Menu::Menu(sf::RenderWindow * gWindow, sf::Font *font)
{
    Menu::mWindow = gWindow;
    Menu::font = font;

}

void Menu::loadText()
{
    title.setFont(*font);
    title.setColor(sf::Color(Game::fontColor[0],Game::fontColor[1],Game::fontColor[2], Game::fontColor[3]));
    title.setString("WONSZ");
    title.setScale(1.5, 1.5);
    title.setStyle(sf::Text::Bold);
    title.setPosition(290, 42);

    button[0].setFont(*font);
    button[0].setColor(sf::Color(Game::fontColor[0],Game::fontColor[1],Game::fontColor[2], Game::fontColor[3]));
    button[0].setString("PLAY");
    button[0].setPosition(340,200);

    button[1].setFont(*font);
    button[1].setColor(sf::Color(Game::fontColor[0],Game::fontColor[1],Game::fontColor[2], Game::fontColor[3]));
    button[1].setString("SCORE");
    button[1].setPosition(330,275);

    button[2].setFont(*font);
    button[2].setColor(sf::Color(Game::fontColor[0],Game::fontColor[1],Game::fontColor[2], Game::fontColor[3]));
    button[2].setString("CLOSE");
    button[2].setPosition(332,350);
}

void Menu::score()
{
    std::ostringstream os;
    sf::Text textn;
    textn.setFont(*font);
    int y = 100;
    int xn = 100;
    int xs = xn + 500;
    sf::Event event;
    std::string srore;

    int j;

    sf::Text title2;
    title2.setFont(*font);
    title2.setColor(sf::Color(Game::fontColor[0],Game::fontColor[1],Game::fontColor[2], Game::fontColor[3]));
    title2.setString("WYNIKI");
    title2.setScale(1.5, 1.5);
    title2.setStyle(sf::Text::Bold);
    title2.setPosition(290, 42);

    while(!(mWindow->pollEvent(event)&& event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
    {
        mWindow->clear(sf::Color(Game::backgroundColor[0],Game::backgroundColor[1],Game::backgroundColor[2], Game::backgroundColor[3]));
        y = 100;
        j = 0;
        do
        {
            std::cout << j << std::endl;
            textn.setString(nick[j]);
            textn.setPosition(xn,y);
            mWindow->draw(textn);
            os.str( "" );
            os << scorei[j];
            srore = os.str();
            textn.setString(srore);
            textn.setPosition(xs,y);
            textn.setFont(*font);
            textn.setString(srore);
            textn.setPosition(xs,y);
            mWindow->draw(textn);

            y += 40;
            j++;
        }while(j<10);
        mWindow->draw(title2);
        mWindow->display();
    }
}

std::string Menu::takeNick()
{
    std::string nickn;

    sf::RectangleShape rectangle(sf::Vector2f(500, 40));
    rectangle.setFillColor(sf::Color(Game::fontColor[0],Game::fontColor[1],Game::fontColor[2], Game::fontColor[3]));
    rectangle.setPosition(180, 200);

    sf::Text textn;
    textn.setFont(*font);
    textn.setColor(sf::Color(Game::backgroundColor[0],Game::backgroundColor[1],Game::backgroundColor[2], Game::backgroundColor[3]));

    sf::Text text;
    text.setFont(*font);
    text.setColor(sf::Color(Game::fontColor[0],Game::fontColor[1],Game::fontColor[2], Game::fontColor[3]));
    text.setString(std::wstring(L"You reached max of name's length."));
    text.setScale(0.5, 0.5);

    sf::Text title2;
    title2.setFont(*font);
    title2.setColor(sf::Color(Game::fontColor[0],Game::fontColor[1],Game::fontColor[2], Game::fontColor[3]));
    title2.setString("Type in your name:");
    title2.setScale(1, 1);
    title2.setStyle(sf::Text::Bold);
    title2.setPosition(260, 42);

    sf::Event event;
    text.setPosition(200,250);
    textn.setPosition(200,200);
    while(true)
    {
        mWindow->clear(sf::Color(Game::backgroundColor[0],Game::backgroundColor[1],Game::backgroundColor[2], Game::backgroundColor[3]));
        if( event.type == sf::Event::TextEntered )
        {
            if( event.text.unicode < 123 && event.text.unicode > 47)
            {
                nickn = nickn + static_cast<char>(event.text.unicode);
            }
        }
        if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::BackSpace && nickn.size() !=0)
        {
            nickn = nickn.erase(nickn.length()-1,1);
        }
        while(nickn.size() == 10)
        {
            mWindow->clear(sf::Color(Game::backgroundColor[0],Game::backgroundColor[1],Game::backgroundColor[2], Game::backgroundColor[3]));
            if(mWindow->pollEvent(event)&& event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
            {
                return nickn;
            }
            if( event.type == sf::Event::TextEntered && event.text.unicode == 8)
            {
                nickn.pop_back();
            }
            mWindow->draw(text);
            textn.setString(nickn);
            mWindow->draw(rectangle);
            mWindow->draw(textn);
            mWindow->draw(title2);
            mWindow->display();
        }
        textn.setString(nickn);
        mWindow->draw(rectangle);
        mWindow->draw(textn);
        mWindow->draw(title2);
        mWindow->display();
        if(mWindow->pollEvent(event)&& event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return && nickn.size() != 0)
        {
            return nickn;
        }
    }
}

void Menu::checkScore()
{
    int help;
    std::string helpn;
    int help2;
    std::string helpn2;
    int z = i-1;
    std::string nickn;
    if(scorei[z] < points)
    {
        while(scorei[z] < points && z != -1)
        {
            z--;
        }
        z++;
        nickn = takeNick();
        help = scorei[z];
        helpn = nick[z];
        scorei[z] = points;
        nick[z] = nickn;
        for(int j = z+1; j < i ; j++ )
        {
            help2 = scorei[j];
            helpn2 = nick[j];
            scorei[j] = help;
            nick[j] = helpn;
            help = help2;
            helpn = helpn2;
        }
    }
}

void Menu::detectPressButton()
{
    int j=0;
    sf::Event event;
    sf::Vector2i coordinates;
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        coordinates = sf::Mouse::getPosition( *mWindow );
        if(coordinates.x > 340 && coordinates.x < 470 && coordinates.y > 200 && coordinates.y < 235)
        {
            Game game(mWindow, font);
            points = game.run();
            checkScore();
        }
        if(coordinates.x > 320 && coordinates.x < 483 && coordinates.y > 275 && coordinates.y < 310)
        {
            score();
        }
        if((coordinates.x > 322 && coordinates.x < 480 && coordinates.y > 350 && coordinates.y < 385) || (mWindow->pollEvent(event) && event.type == sf::Event::Closed))
        {
            file.open("./file/punkty.txt", std::ios::out | std::ios::trunc);
            do
            {
                file << nick[j] << "  " << scorei[j] << std::endl;
                j++;
            }while(j<10);
            file.clear();
            file.flush();
            file.close();
            mWindow->close();
        }
    }
}

void Menu::readingFile()
{
    file.open("./file/punkty.txt", std::ios::in);
    if(file.good()){
        for(;i < 10;i++)
        {
            file >> nick[i] >> scorei[i];
        }
    }
    else
    {
       for(;i < 10;i++)
        {
            nick[i] = "----------";
            scorei[i] = 0;
        }
    }
    file.close();
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
        detectPressButton();

        mWindow->display();
    }
}
