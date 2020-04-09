#include <SFML/Graphics.hpp>
//#include <string>
#include <iostream>
#include<SFML/Audio.hpp>
#include "Character.h"
#include "L1CharL.h"

bool L1CharL::isColliding()
    {
        return ( charSprite.getPosition().x + 100 > 1220 );
    }
L1CharL::L1CharL():imageSelector(0), animationDelay(0)//, winPointer( winP )`
    {
        runningImg.loadFromFile("images/L1 run.png");
        hittingImg.loadFromFile("images/L1 hit.png");
        charSprite.setTexture(runningImg);
        charSprite.move(60,395);
    }
    void L1CharL::crop()
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
    void L1CharL::move()
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
    void L1CharL::draw( sf::RenderWindow* winPointer )
    {
        winPointer->draw(charSprite);
    }
    sf::Sprite L1CharL::getSprite()
    {
        return charSprite;
    }
    int L1CharL::getPrice()
    {
        return 20;
    }

