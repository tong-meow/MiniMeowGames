//
//  ghost.cpp
//  MiniGame
//
//  Created by Tong Shen on 9/22/21.
//

#include <SFML/Graphics.hpp>
#include "ghost.hpp"


Ghost::Ghost(std::vector<sf::Texture> & textureVec){
    ghostPosX = 1820.f;
    ghostPosY = rand()%700 + 100;
    velocity = -5.f;

    ghostPic.setTexture(textureVec[3]);
    ghostPic.setPosition(ghostPosX, ghostPosY);
}


void Ghost::GhostMove(){
    ghostPosX += velocity;
    ghostPic.setPosition(ghostPosX, ghostPosY);
}

float Ghost::GetGhostPosX(){
    return ghostPosX;
}

float Ghost::GetGhostPosY(){
    return ghostPosY;
}

void Ghost::DrawGhost(sf::RenderWindow & window){
    window.draw(ghostPic);
}
