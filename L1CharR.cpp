#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include<SFML/Audio.hpp>
#include "L1CharR.h"

    bool L1CharR::isColliding()
    {
        return ( charSprite.getPosition().x < 60 );
    }
    L1CharR::L1CharR()//, winPointer( winP )`
    {
        imageSelector = 0;
        animationDelay = 0;
        runningImg.loadFromFile("images/L1 run R.png");
        hittingImg.loadFromFile("images/L1 hit R.png");
        charSprite.setTexture(runningImg);
        charSprite.move(1120,395);
    }
    void L1CharR::crop()
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
    void L1CharR::move()
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
    void L1CharR::draw( sf::RenderWindow* winPointer )
    {
        winPointer->draw(charSprite);
    }
    sf::Sprite L1CharR::getSprite()
    {
        return charSprite;
    }
    int L1CharR::getPrice()
    {
        return 20;
    }
