#include "headers.hpp"

int main()
{
    RenderWindow appWindow( VideoMode( 1280, 640, 32), "Proba nr1");
    appWindow.setFramerateLimit(300);
    ekranStartowy(&appWindow);
    return 0;
}
