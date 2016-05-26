#include <Adafruit_IS31FL3731.h>
#include <Player.h>


class Ball{
private:
  //int zx = Game-> difficulty;
  //int zy = Game-> difficulty;
public:
  int x1;
  int y1;
  int xz;
  int yz;
  int screenInt;
  Player* player;
  Player* player1;
  Ball(int x1, int y1, Player* player, Player* player1);
  void move();
  bool collisions();
  void drawBall();
  bool screenCheck;
  void clear();



  Adafruit_IS31FL3731* display;
  Adafruit_IS31FL3731* display1;

};
