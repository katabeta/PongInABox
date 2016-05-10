#pragma once
#include <Arduino.h>
#include <Player.h>
#include <Game.h>
//#include <Button.h> ???


class Pong : Game{
private:
  void drawField(void);
public:
  Pong(Player* player1, Player* player2, Button* button);
  void start(void);
};
