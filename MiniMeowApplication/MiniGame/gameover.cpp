//
//  gameover.cpp
//  MiniGame
//
//  Created by Ang Zhang on 9/22/21.
//

#include "gameover.hpp"

void gameOverWindow( sf::RenderWindow & window){
  sf::RectangleShape gameOverWindow;//setup game over window
  gameOverWindow.setFillColor(sf::Color::Black);
  gameOverWindow.setOutlineColor(sf::Color::Black);
  gameOverWindow.setSize(sf::Vector2<float> (900, 700));
  gameOverWindow.setPosition(500, 200);
  window.draw(gameOverWindow);
    
  sf::Text text; //setup game over message
  sf::Font font;
  std::string fontPath = "AlexBrush-Regular.ttf";
  font.loadFromFile(fontPath);
  text.setFont(font);
  text.setString("Game Over");
  text.setCharacterSize(170);
  text.setFillColor(sf::Color(52,192,235));
  text.setStyle(sf::Text::Bold);
  text.setPosition(590, 400);
  window.draw(text);
}
