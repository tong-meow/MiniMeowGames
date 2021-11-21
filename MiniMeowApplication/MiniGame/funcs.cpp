//
//  funcs.cpp
//  MiniGame
//
//  Created by Tong Shen on 9/22/21.
//

#include "funcs.hpp"

std::vector<sf::Texture> TextureLoad (){
    std::vector<sf::Texture> textureVec;
    
    sf::Texture backgroundTux;
    backgroundTux.loadFromFile("background.jpg");
    textureVec.push_back(backgroundTux);
    
    sf::Texture meowTux;
    meowTux.loadFromFile("nyancat.png");
    textureVec.push_back(meowTux);
    
    sf::Texture rainbowTux;
    rainbowTux.loadFromFile("nyan.png");
    textureVec.push_back(rainbowTux);
    
    sf::Texture ghostTux;
    ghostTux.loadFromFile("ghost.png");
    textureVec.push_back(ghostTux);

    return textureVec;
}


void RbGsCollision (std::vector<Rainbow> & rainbowVec, std::vector<Ghost> & ghostVec){
    for (int i=0; i<rainbowVec.size(); i++){
        float rainbowX = rainbowVec[i].GetRainbowPosX();
        float rainbowY = rainbowVec[i].GetRainbowPosY();
        for (int j=0; j<ghostVec.size(); j++){
            float ghostX = ghostVec[j].GetGhostPosX();
            float ghostY = ghostVec[j].GetGhostPosY();
            
            if (rainbowX >= ghostX && rainbowX <= (ghostX + 200)){
                if (rainbowY >= ghostY && rainbowY <= (ghostY + 200)){
                    ghostVec.erase(ghostVec.begin()+j);
                    rainbowVec.erase(rainbowVec.begin()+i);
                }
            }
        }
    }
}

bool GsCollision (std::vector<Ghost> & ghostVec, sf::Sprite & meow){
    bool collided = false;
    float meowX = meow.getPosition().x;
    float meowY = meow.getPosition().y;
    for (int i=0; i<ghostVec.size(); i++){
        float ghostX = ghostVec[i].GetGhostPosX();
        float ghostY = ghostVec[i].GetGhostPosY();
        if ( ghostX >= meowX && ghostX <= meowX + 200){
            if ( ghostY >= meowY-50 && ghostY <= meowY+200){
                collided = true;
            }
        }
    }
    return collided;
}
