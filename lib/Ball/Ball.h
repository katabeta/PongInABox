#include <Adafruit_IS31FL3731.h>

class Ball{
private:
  //int zx = Game-> difficulty;
  //int zy = Game-> difficulty;
public:
  int x1;
  int y1;
  bool screenCheck=true;
  Ball(int x1, int y1, Adafruit_IS31FL3731* display);
  void move();
  void collisions();
  void drawBall();



  Adafruit_IS31FL3731* display;

};
