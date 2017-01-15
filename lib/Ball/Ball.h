#pragma once
<<<<<<< HEAD
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
=======
#include <Adafruit_IS31FL3731.h>
#include <Player.h>


class Ball{
private:
  Reference reference;

public:
  Ball(int x1, int y1, Player* player, Player* player1);
  int x1;
  int y1;
  int xz;
  int yz;
  int screenInt;
  Player* player;
  Player* player1;
  void move();
  bool collisions();
  void drawBall();
  bool screenCheck;
  void clear();



  Adafruit_IS31FL3731* display;
  Adafruit_IS31FL3731* display1;

>>>>>>> 0df60bc24b96fcefa4670f02c5314b11fca55191
};
