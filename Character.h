#ifndef CHARACTER_H
#define CHARACTER_H
#include<iostream>

class Character
{
protected:
    sf::Texture runningImg, hittingImg;
    sf::Sprite charSprite;
public:
    virtual void crop() = 0;
    virtual void move() = 0;
    virtual void draw( sf::RenderWindow* winPointer ) = 0;
    virtual int getPrice() = 0;
};

#endif
