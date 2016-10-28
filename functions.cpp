#include "headers.hpp"

void ruch(int &i, int &j, int &kierunek, int &poruszenie){
    if(kierunek == 1){
        if(Keyboard::isKeyPressed(Keyboard::Down)){
            j++;
            kierunek = 3;
        }
        else if(Keyboard::isKeyPressed(Keyboard::Up)){
            j--;
            kierunek = 4;
        }
        else if(Keyboard::isKeyPressed(Keyboard::Right)){
            i++;
            kierunek = 1;
        }
    }
    else if(kierunek == 2){
        if(Keyboard::isKeyPressed(Keyboard::Down)){
            j++;
            kierunek = 3;
        }
        else if(Keyboard::isKeyPressed(Keyboard::Up)){
            j--;
            kierunek = 4;
        }
        else if(Keyboard::isKeyPressed(Keyboard::Left)){
            i--;
            kierunek = 2;
        }
    }
    else if(kierunek == 3){
        if(Keyboard::isKeyPressed((Keyboard::Right))){
            i++;
            kierunek = 1;
        }
        else if(Keyboard::isKeyPressed(Keyboard::Left)){
            i--;
            kierunek = 2;
        }
        else if(Keyboard::isKeyPressed(Keyboard::Down)){
            j++;
            kierunek = 3;
        }
    }
    else if(kierunek == 4){
        if(Keyboard::isKeyPressed((Keyboard::Right))){
            i++;
            kierunek = 1;
        }
        else if(Keyboard::isKeyPressed(Keyboard::Left)){
            i--;
            kierunek = 2;
        }
        else if(Keyboard::isKeyPressed(Keyboard::Up)){
            j--;
            kierunek = 4;
        }
    }
    else if(kierunek == 0){
        if(Keyboard::isKeyPressed((Keyboard::Right))){
            i++;
            kierunek = 1;
        }
        else if(Keyboard::isKeyPressed(Keyboard::Left)){
            i--;
            kierunek = 2;
        }
        else if(Keyboard::isKeyPressed(Keyboard::Down)){
            j++;
            kierunek = 3;
        }
        else if(Keyboard::isKeyPressed(Keyboard::Up)){
            j--;
            kierunek = 4;
        }

    }
    if(poruszenie){
        if(kierunek == 1){
            i++;
        }
        else if(kierunek == 2){
            i--;
        }
        else if(kierunek == 3){
            j++;
        }
        else if(kierunek == 4){
            j--;
        }
    }
}

void ekranGry(RenderWindow * appWindow){
    Event zdarzenie;
    int i=10;
    int j=10;
    int kierunek=0;
    int poruszenie=0;
    Texture tekstura;
    tekstura.loadFromFile("./img/snake.png");
    Sprite obrazek;
    obrazek.setPosition(i,j);
    obrazek.setTexture(tekstura);
    while(appWindow->isOpen()){
        appWindow->clear(Color(237,246,125));
        ruch(i,j,kierunek,poruszenie);
        while(appWindow->pollEvent(zdarzenie)){
            if(zdarzenie.type == Event::Closed){
                appWindow->close();
            }
            else if(zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::Escape){
                appWindow->close();
            }
        }
        if(i == 0 || i == 1260 || j == 0 || j == 620){
            appWindow->close();
        }
        obrazek.setPosition(i,j);
        if(kierunek){
            appWindow->draw(obrazek);
        }
        poruszenie = 1;
        appWindow->display();
    }
}

void ekranMenu(RenderWindow * appWindow, Font * font){
    Vector2i punkty;
    RectangleShape przycisk(Vector2f(100,50));
    przycisk.setFillColor(Color(237,246,125));
    przycisk.setPosition(550,200);
    Event zdarzenie;
    Text tekst("Graj",*font,50);
    tekst.setColor(Color(19,27,35));
    tekst.setPosition(555,190);
    while(appWindow->isOpen()){
        appWindow->clear(Color(237,246,125));
        appWindow->draw(przycisk);
        appWindow->draw(tekst);
        appWindow->display();
        if(Mouse::isButtonPressed(Mouse::Left)){
            punkty = Mouse::getPosition( *appWindow );
             if(punkty.x > 550 && punkty.x < 650 && punkty.y > 200 && punkty.y < 250){
                przycisk.setFillColor(Color(19,27,35));
                ekranGry(appWindow);
            }
        }
    }
}

void ekranStartowy(RenderWindow * appWindow){
    Event zdarzenie;
    Font font;
    font.loadFromFile("./fonts/moj.ttf");
    Text tekst("WITAM",font,50);
    tekst.setColor(Color(19,27,35));
    tekst.setPosition(550,270);
    //Music muza;
    //muza.openFromFile("./music/muza.ogg");
    //muza.play();
    //muza.setVolume(100);
    //tekst.setStyle(sf::Text::Bold | sf::Text::Underlined);
    while(appWindow->isOpen()){
        appWindow->clear(Color(237,246,125));
        appWindow->draw(tekst);
        appWindow->display();
        if(appWindow->pollEvent(zdarzenie) && zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::Return){
            //ekranGry(appWindow);
            ekranMenu(appWindow, &font);
        }
    }
}
