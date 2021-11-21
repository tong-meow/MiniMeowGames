//
//  funcs.hpp
//  MiniGame
//
//  Created by Tong Shen on 9/22/21.
//

#ifndef funcs_hpp
#define funcs_hpp

#include <stdio.h>
#include "ghost.hpp"
#include "rainbow.hpp"

std::vector<sf::Texture> TextureLoad ();

void RbGsCollision (std::vector<Rainbow> & rainbowVec, std::vector<Ghost> & ghostVec);
bool GsCollision (std::vector<Ghost> & ghostVec, sf::Sprite & meow);

#endif /* funcs_hpp */
