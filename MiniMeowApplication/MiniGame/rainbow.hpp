//
//  rainbow.hpp
//  MiniGame
//
//  Created by Tong Shen on 9/22/21.
//

#ifndef rainbow_hpp
#define rainbow_hpp

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "ghost.hpp"


class Rainbow{
    
// private members
private:
    float rainbowPosX;
    float rainbowPosY;
    float velocity;
    sf::Sprite rainbowPic;
    
// public methods
public:
    Rainbow(sf::Sprite & meow, std::vector<sf::Texture> & textureVec);
    
    void RainbowMove();
    float GetRainbowPosX();
    float GetRainbowPosY();
    void DrawRainbow(sf::RenderWindow & window);
};

#endif /* rainbow_hpp */
