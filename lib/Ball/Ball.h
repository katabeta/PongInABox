#pragma once
#include <Player.h>
// #include <Adafruit_IS31FL3731.h>
// #include <Pot.h>

//Reference reference = Reference();

class Ball{
public:
  Ball(Player* p1, Player* p2, int delay);
  void draw(void);
  void printStats(void);
private:
  Player* p1;
  Player* p2;

  void move(void);
  //void draw(void);
  void clear(void);
  Adafruit_IS31FL3731* getCurrDisp(void);
  Pot* getCurrPot(void);

  int lastTime;
  int currTime;

  void genNewVals(void);

  Reference reference;

  int x1;
  int y1;
  int y;
  int x;
  int dX;
  int dY;
  int t;

  bool on74;
  int delay;
};
