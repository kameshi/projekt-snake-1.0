#include "Menu.hpp"
#include "Snake.hpp"
#include "Game.hpp"

sf::Time Game::TimePerFrame = sf::seconds(Game::playerSpeed);
float Game::playerSpeed = 1.f/10.f;
int Game::pause = 0;
const uint8_t Game::backgroundColor[4] = {165, 204, 107, 255};
const uint8_t Game::fontColor[4] = {51, 49, 56, 255};

Game::Game(sf::RenderWindow *gWindow, sf::Font *font)
{
    mWindow = gWindow;
    Game::font = font;
    //ustawiamy parametry jedzonka
    fd.loadFromFile("./img/food01.png");
    food.setTexture(fd);
    fd02.loadFromFile("./img/food02.png");
    food02.setTexture(fd02);
    fd03.loadFromFile("./img/food03.png");
    food03.setTexture(fd03);
    //wskaznik na jedzonko
    Food = &food;
    Food->setPosition(400, 400);
    amountOfPoints = 1;


    point.setPosition(width-140,height-30);
    point.setScale(0.8, 0.8);
    point.setColor(sf::Color(Game::fontColor[0],Game::fontColor[1],Game::fontColor[2], Game::fontColor[3]));
    point.setFont(*font);
    pauseText.setPosition(5, 5);
    pauseText.setScale(0.8, 0.8);
    pauseText.setColor(sf::Color(Game::fontColor[0],Game::fontColor[1],Game::fontColor[2], Game::fontColor[3]));
    pauseText.setFont(*font);
    pauseText.setString("Press P to play.");

}
int Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while(mWindow->isOpen())
    {
        if(!pause)
            timeSinceLastUpdate += clock.restart();
        else
            clock.restart();
        handlePlayerInput();
        while(timeSinceLastUpdate > Game::TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            if(!update())
            {
                return points;
            }
        }
        render();
    }
    return 0;
}

void Game::handlePlayerInput()
{
    sf::Event event;
    while(mWindow->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            mWindow->close();
        else if(event.type == sf::Event::KeyReleased) {
            if(event.key.code == sf::Keyboard::P) {
                if(!pause) {
                    pause = 1;
                }
                else {
                    pause = 0;
                }
            }
        }
    }
    snake.handlePlayerInput();
}
bool Game::update() {
    if(snake.FoodColision(Food, amountOfPoints)) //jezeli wonsz zjadl jedzonko to if bedzie true
    {
        //
        Game::TimePerFrame = sf::seconds(Game::playerSpeed);
        //
        points += amountOfPoints;
        pointsos.str( "" );
        pointsos << points;
        pointss = "";
        pointss = pointsos.str();
        //
        std::default_random_engine engine;     // only used once to initialise (seed) engine
        engine.seed(time(NULL));
        //
        std::uniform_int_distribution<int> p(0, 100);
        std::uniform_int_distribution<int> n(-2, 5);
        int perc;
        for(int i = 0; i < 4; ++i)
            perc = p(engine);
        //
        if(perc < 70) {
            Food = &food;
            amountOfPoints = 1;
            playerSpeed = 1.f/10.f;
        }
        else if(perc > 85) {
            Food = &food02;
            for(int i = 0; i < 4; ++i)
                amountOfPoints = n(engine);
            playerSpeed = 1.f/10.f;
        }
        else {
            Food = &food03;
            amountOfPoints = 2;
            playerSpeed = 1.f/7.f;
        }
        //
        sf::Vector2f movement; //przmieszczenie
        sf::Sprite tmp;
        tmp.setTexture(fd);

        do //losujemy nowe wspolrzedne dla jedzonka, dopoty dopoki przestana sie one pokrywac z pozycja wensza
        {
            std::uniform_int_distribution<int> x(0, Game::width/Snake::Width-1);
            std::uniform_int_distribution<int> y(0, Game::height/Snake::Height-1);
            movement.x = x(engine) * 20;
            movement.y = y(engine) * 20;

            tmp.setPosition(movement);
        }while(snake.isFoodOnBody(tmp.getGlobalBounds()));
        //przypisujemy jedzonku nowa, wylosowana pozycje
        Food->setPosition(movement);
    }
    return (snake.update()) ? true : false;
}
void Game::render() {
    mWindow->clear(sf::Color(Game::backgroundColor[0],Game::backgroundColor[1],Game::backgroundColor[2], Game::backgroundColor[3]));
    point.setString("Score: " + pointss);
    mWindow->draw(*Food);
    mWindow->draw(point);
    if(pause)
        mWindow->draw(pauseText);
    snake.render(mWindow);
    mWindow->display();
}
