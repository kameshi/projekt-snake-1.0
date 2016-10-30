#include "Game.hpp"


const sf::Time Game::TimePerFrame = sf::seconds(1.f/10.f);

Game::Game()
: mWindow(sf::VideoMode(width, height), "Snake v.1.0")
{
    mWindow.setFramerateLimit(60);

    //ustawiamy parametry jedzonka
    food.setSize(sf::Vector2f(20, 20));
    food.setPosition(400, 400);
    food.setFillColor(sf::Color::Red);
}
void Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while(mWindow.isOpen())
    {
        timeSinceLastUpdate += clock.restart();
        handlePlayerInput();
        while(timeSinceLastUpdate > Game::TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            if(!update())
                mWindow.close();
        }
        render();
    }
}

void Game::handlePlayerInput()
{
    sf::Event event;
    while(mWindow.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            mWindow.close();
    }
    snake.handlePlayerInput();
}
bool Game::update() {
    if(snake.FoodColision(food)) //jezeli wonsz zjadl jedzonko to if bedzie true
    {
        sf::Vector2f movement; //przmieszczenie
        sf::RectangleShape tmp(sf::Vector2f(Snake::Width, Snake::Height));
        std::default_random_engine engine; //inicjowanie generatora liczb pseudolosowych
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
    mWindow.clear(sf::Color(237,246,125));
    mWindow.draw(food);
    snake.render(mWindow);
    mWindow.display();
}
