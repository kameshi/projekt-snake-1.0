#include "Menu.hpp"
#include "Snake.hpp"
#include "Game.hpp"

const float Game::playerSpeed = 1.f/10.f;
const sf::Time Game::TimePerFrame = sf::seconds(Game::playerSpeed);
const uint8_t Game::backgroundColor[4] = {165, 204, 107, 255};
const uint8_t Game::fontColor[4] = {51, 49, 56, 255};

Game::Game(sf::RenderWindow *gWindow)
{
    mWindow = gWindow;
    //ustawiamy parametry jedzonka
    fd.loadFromFile("./img/food01.png");
    food.setTexture(fd);
    food.setPosition(400, 400);

    font.loadFromFile("./fonts/moj1.ttf");

    point.setPosition(width-250,height-50);
    point.setColor(sf::Color(Game::fontColor[0],Game::fontColor[1],Game::fontColor[2], Game::fontColor[3]));
    point.setFont(font);

}
int Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while(mWindow->isOpen())
    {
        timeSinceLastUpdate += clock.restart();
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
    }
    snake.handlePlayerInput();
}
bool Game::update() {
    if(snake.FoodColision(food)) //jezeli wonsz zjadl jedzonko to if bedzie true
    {
        points++;
        pointsos.str( "" );
        pointsos << points;
        pointss = "";
        pointss = pointsos.str();
        sf::Vector2f movement; //przmieszczenie
        sf::Sprite tmp;
        tmp.setTexture(fd);
        std::default_random_engine engine;     // only used once to initialise (seed) engine
        engine.seed(time(NULL));
        do //losujemy nowe wspolrzedne dla jedzonka, dopoty dopoki przestana sie one pokrywac z pozycja wensza
        {
            std::uniform_int_distribution<int> x(0, Game::width/Snake::Width-1);
            std::uniform_int_distribution<int> y(0, Game::height/Snake::Height-1);
            movement.x = x(engine) * 20;
            movement.y = y(engine) * 20;

            tmp.setPosition(movement);
        }while(snake.isFoodOnBody(tmp.getGlobalBounds()));
        //przypisujemy jedzonku nowa, wylosowana pozycje
        food.setPosition(movement);
    }
    return (snake.update()) ? true : false;
}
void Game::render() {
    mWindow->clear(sf::Color(Game::backgroundColor[0],Game::backgroundColor[1],Game::backgroundColor[2], Game::backgroundColor[3]));
    point.setString("Score: " + pointss);
    mWindow->draw(food);
    mWindow->draw(point);
    snake.render(mWindow);
    mWindow->display();
}
