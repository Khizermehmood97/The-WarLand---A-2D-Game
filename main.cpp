#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include<SFML/Audio.hpp>
#include "Character.h"
#include "L1CharL.h"
#include "L1CharR.h"
#include "L2CharL.h"
#include "L2CharR.h"
#include "L3CharL.h"
#include "L3CharR.h"
using namespace std;

void screen1(sf::RenderWindow *win, sf::Sprite obj);
int main()
{
     sf::Music menuSound;
           if (!menuSound.openFromFile("Better-for-Menu.ogg"))
    {
        cout << "file not found..";
        return 0;
    }
       menuSound.play();

       sf::Texture img1;
       sf::Sprite start;
       img1.loadFromFile("START GAME.png");
       start.setTexture(img1);
        int screenNumber = 1;


      sf::Texture img3;
      sf::Sprite quit;
      img3.loadFromFile("QUIT GAME.png");
      quit.setTexture(img3);

      sf::RenderWindow win;
      win.create(sf::VideoMode(1280, 720), "The WarLand v6.9" , sf::Style::Titlebar | sf::Style::Close);
      screen1(&win,start);


      while( win.isOpen() &&  menuSound.getStatus()==sf::Music::Playing)
    {

        sf::Event ev;
        while( win.pollEvent(ev) )
        {
             if (ev.type == sf::Event::Closed)
                win.close();
            else if( ev.type == sf::Event::KeyPressed )
            {
                if( ev.key.code == sf::Keyboard::Escape)
                    win.close();
            }
          if( sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
          {
              if(screenNumber<2)
                screenNumber++;
          }
          else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
          {
              if(screenNumber<3 && screenNumber>1)
                screenNumber--;
          }
        }
        switch( screenNumber )
        {
        case 1:
            screen1(&win,start);
              if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
            {

    sf::RenderWindow win;
    win.create(sf::VideoMode(1280, 720), "The WarLand v6.9" , sf::Style::Titlebar | sf::Style::Close);
    //sf::VideoMode currentRes = sf::VideoMode::getDesktopMode();
    //sf::Vector2i centralPositionVector((currentRes.width-1280)/2, (currentRes.height-720)/2 );
    //win.setPosition(centralPosit/ionVector);

     sf::Texture winner1,winner2;
     sf::Sprite gameover1,gameover2;
     winner1.loadFromFile("player1win.png");
     winner2.loadFromFile("player2win.png");
     gameover1.setTexture(winner1);
     gameover2.setTexture(winner2);

    sf::Texture backImg;
    sf::Sprite background;
    //L2CharR x;
    //L1CharL y;
    Character* charArr[200] = {NULL};
    int charArrCount = 0;
    int LAmount = 200, RAmount = 200;
    int LPower = 0, RPower = 0;
    bool LPressed = false, RPressed = false;
    float LPressTime = 0 , RPressTime = 0;
    int Winner = 0;

    backImg.loadFromFile("images/background.png");//, sf::IntRect )
    background.setTexture(backImg);

    sf::Clock clock;
    sf::Clock FinalClock;

    float clockSum = 0;
    const float refreshRate = 0.0167f ; // because 1/60 or 60FPS is 0.0167


    while( win.isOpen() )
    {

        sf::Event ev;
        while( win.pollEvent(ev) )
        {

            if (ev.type == sf::Event::Closed)
                win.close();
            else if( ev.type == sf::Event::KeyPressed )
            {
                if( ev.key.code == sf::Keyboard::Escape)
                    win.close();
                if( ev.key.code == sf::Keyboard::A )
                {
                    /*
                    sourceX++;
                    if( sourceX * 56 >= charImg.getSize().x )
                        sourceX = 0;
                    character.move(5,0);
                    */
                }
            }

            if( sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                if( LAmount >= 20 )
                {
                    charArr[charArrCount] = new L1CharL;
                    charArrCount++;
                    LAmount -= 20;
                    LPower += 2;
                    if( LPressed == false )
                    {
                        LPressTime = FinalClock.getElapsedTime().asSeconds();
                        LPressed = true;
                    }
                }
            }
            else if( sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                if( LAmount >= 30 )
                {
                    charArr[charArrCount] = new L2CharL;
                    charArrCount++;
                    LAmount -= 30;
                    LPower += 5;
                    if( !LPressed )
                    {
                        LPressTime = FinalClock.getElapsedTime().asSeconds();
                        LPressed = true;
                    }
                }
            }
            else if( sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                if( LAmount >= 50 )
                {
                    charArr[charArrCount] = new L3CharL;
                    charArrCount++;
                    LAmount -= 50;
                    LPower += 7;
                    if( !LPressed )
                    {
                        LPressTime = FinalClock.getElapsedTime().asSeconds();
                        LPressed = true;
                    }
                }
            }
            else if( sf::Keyboard::isKeyPressed(sf::Keyboard::J))
            {
                if( RAmount >= 20 )
                {
                    charArr[charArrCount] = new L1CharR;
                    charArrCount++;
                    RAmount -= 20;
                    RPower += 2;
                    if( !RPressed )
                    {
                        RPressTime = FinalClock.getElapsedTime().asSeconds();
                        RPressed = true;
                    }
                }
            }
            else if( sf::Keyboard::isKeyPressed(sf::Keyboard::K))
            {
                if( RAmount >= 30 )
                {
                    charArr[charArrCount] = new L2CharR;
                    charArrCount++;
                    RAmount -= 30;
                    RPower += 5;
                    if( !RPressed )
                    {
                        RPressTime = FinalClock.getElapsedTime().asSeconds();
                        RPressed = true;
                    }
                }
            }
            else if( sf::Keyboard::isKeyPressed(sf::Keyboard::L))
            {
                if( RAmount >= 50 )
                {
                    charArr[charArrCount] = new L3CharR;
                    charArrCount++;
                    RAmount -= 50;
                    RPower += 7;
                    if( !RPressed )
                    {
                        RPressTime = FinalClock.getElapsedTime().asSeconds();
                        RPressed = true;
                    }
                }
            }
        }

        clockSum += clock.restart().asSeconds();

        if( clockSum >= refreshRate )
        {
            //cout << clockSum << endl;
            clockSum = 0;

            for( int i = 0 ; i < charArrCount ; i++ )
            {
                charArr[i]->crop();
                charArr[i]->move();
            }
            //x.crop();
            //x.move();
//            y.crop();
//            y.move();

        }

        for( int i = 0 ; i < charArrCount ; i++ )
            charArr[i]->draw( &win );



        if( FinalClock.getElapsedTime().asSeconds() >= 23 )
        {
            for( int i = 0 ; i < charArrCount ; i++ )
                charArr[i]->draw( &win );

            if( LPower > RPower )
            {
                Winner = 1;
            }
            else if( LPower < RPower )
            {
                Winner = 2;
            }
            else
            {
                if( LPressTime > RPressTime )
                    Winner = 1;
                else
                    Winner = 2;
            }
            cout << Winner << endl;
        }


        //x.draw(&win);
        //y.draw(&win);

        //win.clear(sf::Color::White);


        //win.draw(x.getSprite());
//        win.draw(character);
        win.display();
        win.clear();
        if(Winner==0){
        win.draw(background);
        }
        if(Winner==1){
          win.draw(gameover1);
        }
        if(Winner==2){
        win.draw(gameover2);
        }


    }
            }
            break;

        case 2:
            screen1(&win,quit);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
            win.close();
            break;
        }

    }

    return 0;

}

void screen1(sf::RenderWindow *win, sf::Sprite obj)
{

    win->draw(obj);
    win->display();
}
