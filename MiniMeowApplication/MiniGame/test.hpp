//
//  test.hpp
//  MiniGame
//
//  Created by Ang Zhang on 9/22/21.
//

#ifndef test_hpp
#define test_hpp

#include <stdio.h>

void RbGsCollisionTest (std::vector<Rainbow> & rainbowVec, std::vector<Ghost> & ghostVec);
bool GsCollisionTest (std::vector<Ghost> & ghostVec, sf::Sprite & meow);

#endif /* test_hpp */
