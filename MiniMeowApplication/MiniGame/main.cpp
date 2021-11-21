//
//  main.cpp
//  MiniGame
//
//  Created by Tong Shen & Ang Zhang on 9/21/21.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "rainbow.hpp"
#include "ghost.hpp"
#include "funcs.hpp"
#include "gameover.hpp"

// #include "test.hpp"

using namespace sf;
using namespace std;

int main() {

/* Load Textures */
    
    // texture of background
    vector<Texture> textureVec;
    textureVec = TextureLoad();
    Sprite background;
    background.setTexture(textureVec[0]);
    
    
/* Create a Window */
    
    RenderWindow window(VideoMode(1920, 1080), "Nyan Meow Battle");
    window.setFramerateLimit(60);
    
    
/* Generate a Cat Controlled By Player */
    
    Sprite meow;
    meow.setTexture(textureVec[1]);
    const int meowPosX = 50;
    int meowPosY = 490;
    meow.setPosition(meowPosX, meowPosY);

    
/* Game Losing Detector */
    
    bool isLose = false;
    int timeCount = 0;
    

/* Cat's Bullets & Cat's Enemies */
    
    // rainbows
    vector <Rainbow> rainbowVec;
    int shootCD = 0;    // controll the cooldown time of bullets
    
    // ghosts
    vector <Ghost> ghostVec;
    int ghostCD = 0;    // controll the appear time of enemies


/* Program Running */
    
    while (window.isOpen()){
        Event event;
        while (window.pollEvent(event)){
            if (event.type == Event::Closed){
                window.close();
            }
        }
        
        // player's keyboad inputting: cat moving
        if (Keyboard::isKeyPressed(Keyboard::Key::W) && meow.getPosition().y > 0){
                meow.move(0.0f, -15.f);
            // determine if the cat is gonna be out of the screen
            if (meow.getPosition().y < 0){
                meow.setPosition(50.f, 0.f);
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::S) && meow.getPosition().y < 1080){
                meow.move(0.0f, 15.f);
            // determine if the cat is gonna be out of the screen
            if (meow.getPosition().y > 820 ){
                meow.setPosition(50.f, 820.f);
            }
        }
        
        // shooting control
        if (shootCD < 15){
            shootCD++;
        }
        // shoot rainbows (bullets): create a rainbow
        if (Keyboard::isKeyPressed(Keyboard::Key::Return) && shootCD >= 15){
            Rainbow rainbowBullet(meow, textureVec);
            rainbowVec.push_back(rainbowBullet);
            shootCD = 0;
        }
        // shoot rainbows (bullets): move all the rainbows
        for (int i=0; i<rainbowVec.size(); i++){
            // determine if the bullet is gonna be out of the screen
            float rbPos = rainbowVec[i].GetRainbowPosX();
            if (rbPos > 1850){
                rainbowVec.erase(rainbowVec.begin()+i);
            }
            rainbowVec[i].RainbowMove();
        }
        
        
        // enemies control
        if (timeCount < 1000){
            if (ghostCD < 40){
                ghostCD++;
            }
            // ghosts appear (enemies): create a ghost
            if (ghostCD >= 40){
                Ghost ghost(textureVec);
                ghostVec.push_back(ghost);
                ghostCD = 0;
            }
        }else if (timeCount < 2000){
            if (ghostCD < 20){
                ghostCD++;
            }
            // ghosts appear (enemies): create a ghost
            if (ghostCD >= 20){
                Ghost ghost(textureVec);
                ghostVec.push_back(ghost);
                ghostCD = 0;
            }
        }else{
            if (ghostCD < 10){
                ghostCD++;
            }
            // ghosts appear (enemies): create a ghost
            if (ghostCD >= 10){
                Ghost ghost(textureVec);
                ghostVec.push_back(ghost);
                ghostCD = 0;
            }
        }
        
        // ghosts moving
        for (int i=0; i<ghostVec.size(); i++){
            // determine if a ghost is gonna be out of the screen
            float gsPos = ghostVec[i].GetGhostPosX();
            if (gsPos < 50){
                ghostVec.erase(ghostVec.begin()+i);
            }
            ghostVec[i].GhostMove();
            if (gsPos == 50){
                isLose = true;
            }
        }
        
        // if the rainbow hits the ghost
        RbGsCollision(rainbowVec, ghostVec);
        /* TEST */
        // RbGsCollisionTest(rainbowVec, ghostVec);
        
        
        // if the ghost hits the cat
        if (GsCollision(ghostVec, meow)){
            isLose = true;
        };
        /* TEST THE COLLISION RANGE */
        // if (GsCollisionTest(ghostVec, meow)){
        //    isLose = true;
        // };
    
        timeCount++;
        
        window.clear();
        window.draw(background);                    // draw the background
        window.draw(meow);                          // draw the cat
        for (int i=0; i<rainbowVec.size(); i++){    // draw every rainbow
            rainbowVec[i].DrawRainbow(window);
        }
        for (int i=0; i<ghostVec.size(); i++){      // draw every ghost
            ghostVec[i].DrawGhost(window);
        }
        
        // if the player lost the game
        if (isLose){
            window.clear();
            window.draw(background);
            window.draw(meow);
            gameOverWindow(window);
            
        }
        
        window.display();
    }
    
    return 0;
}
