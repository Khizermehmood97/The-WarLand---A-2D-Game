#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include<SFML/Audio.hpp>
#include "L2CharR.h"

    bool L2CharR::isColliding()
    {
        return ( charSprite.getPosition().x < 60 );
    }
    L2CharR::L2CharR():imageSelector(0), animationDelay(0)//, winPointer( winP )`
    {
        runningImg.loadFromFile("images/L2 run R.png");
        hittingImg.loadFromFile("images/L2 hit R.png");
        charSprite.setTexture(runningImg);
        charSprite.move(1120,395);
    }
    void L2CharR::crop()
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
    void L2CharR::move()
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
    void L2CharR::draw( sf::RenderWindow* winPointer )
    {
        winPointer->draw(charSprite);
    }
    sf::Sprite L2CharR::getSprite()
    {
        return charSprite;
    }
    int L2CharR::getPrice()
    {
        return 30;
    }
