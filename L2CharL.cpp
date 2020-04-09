#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include<SFML/Audio.hpp>
#include "L2CharL.h"
bool L2CharL::isColliding()
    {
        return ( charSprite.getPosition().x + 100 > 1220 );
    }

L2CharL::L2CharL():imageSelector(0), animationDelay(0)//, winPointer( winP )`
    {
        runningImg.loadFromFile("images/L2 run.png");
        hittingImg.loadFromFile("images/L2 hit.png");
        charSprite.setTexture(runningImg);
        charSprite.move(60,395);
    }
    void L2CharL::crop()
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
    void L2CharL::move()
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
    void L2CharL::draw( sf::RenderWindow* winPointer )
    {
        winPointer->draw(charSprite);
    }
    sf::Sprite L2CharL::getSprite()
    {
        return charSprite;
    }
    int L2CharL::getPrice()
    {
        return 30;
    }
