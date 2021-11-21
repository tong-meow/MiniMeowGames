//
//  ghost.hpp
//  MiniGame
//
//  Created by Tong Shen on 9/22/21.
//

#ifndef ghost_hpp
#define ghost_hpp

#include <SFML/Graphics.hpp>
#include <stdio.h>

class Ghost{
    
// private members
private:
    float ghostPosX;
    float ghostPosY;
    float velocity;
    sf::Sprite ghostPic;

public:
    Ghost(std::vector<sf::Texture> & textureVec);
    
    void GhostMove();
    float GetGhostPosX();
    float GetGhostPosY();
    void DrawGhost(sf::RenderWindow & window);
};



#endif /* ghost_hpp */
