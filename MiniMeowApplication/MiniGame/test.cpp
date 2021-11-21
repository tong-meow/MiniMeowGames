//
//  test.cpp
//  MiniGame
//
//  Created by Ang Zhang on 9/22/21.
//

#include <SFML/Graphics.hpp>
#include "ghost.hpp"
#include "rainbow.hpp"
#include "test.hpp"

void RbGsCollisionTest (std::vector<Rainbow> & rainbowVec, std::vector<Ghost> & ghostVec){
    for (int i=0; i<rainbowVec.size(); i++){
        float rainbowX = rainbowVec[i].GetRainbowPosX();
        float rainbowY = rainbowVec[i].GetRainbowPosY();
        for (int j=0; j<ghostVec.size(); j++){
            float ghostX = ghostVec[j].GetGhostPosX();
            float ghostY = ghostVec[j].GetGhostPosY();
            
            if (rainbowX >= ghostX && rainbowX <= (ghostX + 200)){
                if (rainbowY >= ghostY && rainbowY <= (ghostY + 200)){
                    
                    /* TEST IF AFTER COLLISION THE GHOST WILL BE ERASED */
                    // ghostVec.erase(ghostVec.begin()+j);
                    
                    rainbowVec.erase(rainbowVec.begin()+i);
                }
            }
        }
    }
}

bool GsCollisionTest (std::vector<Ghost> & ghostVec, sf::Sprite & meow){
    bool collided = false;
    float meowX = meow.getPosition().x;
    float meowY = meow.getPosition().y;
    for (int i=0; i<ghostVec.size(); i++){
        float ghostX = ghostVec[i].GetGhostPosX();
        float ghostY = ghostVec[i].GetGhostPosY();
        
        /* TEST IF THE COLLISION RANGE IS REASONABLE */
        //if ( ghostX >= meowX && ghostX <= meowX + 200){
        if ( ghostX >= meowX && ghostX <= meowX + 600){
            //if ( ghostY >= meowY-50 && ghostY <= meowY+200){
            if ( ghostY >= meowY && ghostY <= meowY+500){
                collided = true;
            }
        }
    }
    return collided;
}
