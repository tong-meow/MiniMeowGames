//
//  rainbow.cpp
//  MiniGame
//
//  Created by Tong Shen on 9/22/21.
//

#include "rainbow.hpp"

Rainbow::Rainbow(sf::Sprite & meow, std::vector<sf::Texture> & textureVec){
    rainbowPosX = meow.getPosition().x + 220;
    rainbowPosY = meow.getPosition().y + 120;
    velocity = 15.0;
    
    rainbowPic.setTexture(textureVec[2]);
    rainbowPic.setPosition(rainbowPosX, rainbowPosY);
}

void Rainbow::RainbowMove(){
    rainbowPosX += velocity;
    rainbowPic.setPosition(rainbowPosX, rainbowPosY);
}

float Rainbow::GetRainbowPosX(){
    return rainbowPosX;
}

float Rainbow::GetRainbowPosY(){
    return rainbowPosY;
}

void Rainbow::DrawRainbow(sf::RenderWindow & window){
    window.draw(rainbowPic);
}

