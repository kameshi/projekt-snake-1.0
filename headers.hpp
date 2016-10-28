#ifndef HEADERS_HPP_INCLUDED
#define HEADERS_HPP_INCLUDED

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

void ruch(int &i, int &j, int &kierunek, int &poruszenie);
void ekranGry(RenderWindow * appWindow);
void ekranMenu(RenderWindow * appWindow, Font * font);
void ekranStartowy(RenderWindow * appWindow);

#endif // HEADERS_HPP_INCLUDED
