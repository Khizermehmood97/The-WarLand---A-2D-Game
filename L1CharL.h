//#include<iostream>
#include <SFML/Graphics.hpp>
#include <string>
//#include <iostream>
#include<SFML/Audio.hpp>
#include "Character.h"
//#include<SFML/Graphics.hpp>

using namespace std;

class L1CharL: public Character
{
    int imageSelector;
    long long animationDelay;
    //sf::RenderWindow* winPointer;

    bool isColliding();
public:
        L1CharL();//, winPointer( winP )`//, winPointer( winP )`
        void crop();
        void move();
        void draw( sf::RenderWindow* winPointer );
        sf::Sprite getSprite();
        int getPrice();
};
