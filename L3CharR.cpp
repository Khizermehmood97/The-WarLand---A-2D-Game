#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include<SFML/Audio.hpp>
#include "L3CharR.h"

bool L3CharR::isColliding()
    {
        return ( charSprite.getPosition().x < 60 );
    }
    L3CharR::L3CharR():imageSelector(0), animationDelay(0)//, winPointer( winP )`
    {
        runningImg.loadFromFile("images/L3 run R.png");
        hittingImg.loadFromFile("images/L3 hit R.png");
        charSprite.setTexture(runningImg);
        charSprite.move(1120,395);
    }
    void L3CharR::crop()
    {
        animationDelay++;
        if( animationDelay%5 == 0 )
        {
            imageSelector++;
            if( imageSelector > 7 )
                imageSelector = 0;
            charSprite.setTextureRect(sf::IntRect(imageSelector*100, 0, 100, 150));
        }
    }
    void L3CharR::move()
    {
        if( !isColliding() )
        {
            charSprite.move(-3,0);
        }
        else
        {
            charSprite.setTexture(hittingImg);
        }
    }
    void L3CharR::draw( sf::RenderWindow* winPointer )
    {
        winPointer->draw(charSprite);
    }
    sf::Sprite L3CharR::getSprite()
    {
        return charSprite;
    }
    int L3CharR::getPrice()
    {
        return 50;
    }
