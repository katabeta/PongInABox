#pragma once
#include <Arduino.h>
#include <Player.h>
//#include <Button.h> ???


class Game{
private:
  Player* p1;
  Player* p2;
  Button* confirmButton;
  uint8_t difficulty;

public:
  Game(Player* player1, Player* player2, Button* button);
  bool ready(void);
  uint8_t chooseDifficulty(void);
  void countdown(void);
  void displayScore(void); // s1 : s2
  void drawWinAnim(void);
  void drawLoseAnim(void);
  bool playAgain(void);
};
