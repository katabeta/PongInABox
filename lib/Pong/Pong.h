#pragma once
#include <Arduino.h>
#include <Player.h>
#include <Game.h>
#include <Ball.h>
//#include <Button.h> ???


class Pong : Game{
private:
  Player* p1;
  Player* p2;
  Ball m_ball;
public:
  Pong(Player* player1, Player* player2, Button* button, bool winByLead, int scoreConstraint);
  void start(void);
  void update();
};
