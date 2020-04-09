//#include<iostream>
#include <SFML/Graphics.hpp>
#include <string>
//#include <iostream>
#include<SFML/Audio.hpp>
#include "Character.h"
//#include<SFML/Graphics.hpp>
class L2CharR: public Character
{
int imageSelector, animationDelay;
    //sf::RenderWindow* winPointer;

    bool isColliding();
public:
    L2CharR();
    void crop();
    void move();
    void draw( sf::RenderWindow* winPointer );
    sf::Sprite getSprite();
    int getPrice();
};
