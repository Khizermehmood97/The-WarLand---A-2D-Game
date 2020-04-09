#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include<SFML/Audio.hpp>
#include "L3CharL.h"

    bool L3CharL::isColliding()
    {
        return ( charSprite.getPosition().x + 100 > 1220 );
    }
    L3CharL::L3CharL():imageSelector(0), animationDelay(0)//, winPointer( winP )`
    {
        runningImg.loadFromFile("images/L3 run.png");
        hittingImg.loadFromFile("images/L3 hit.png");
        charSprite.setTexture(runningImg);
        charSprite.move(60,395);
    }
    void L3CharL::crop()
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
    void L3CharL::move()
    {
        if( !isColliding() )
        {
            charSprite.move(3,0);
        }
        else
        {
            charSprite.setTexture(hittingImg);
        }
    }
    void L3CharL::draw( sf::RenderWindow* winPointer )
    {
        winPointer->draw(charSprite);
    }
    sf::Sprite L3CharL::getSprite()
    {
        return charSprite;
    }
    int L3CharL::getPrice()
    {
        return 50;
    }
