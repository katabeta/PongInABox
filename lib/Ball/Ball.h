#include <Adafruit_IS31FL3731.h>

class Ball{
private:
  //int zx = Game-> difficulty;
  //int zy = Game-> difficulty;
public:
  int x1;
  int y1;
  int xz;
  int yz;
  Ball(int x1, int y1, Adafruit_IS31FL3731* display,Adafruit_IS31FL3731* display1);
  void move();
  bool collisions();
  void drawBall();
  bool screenCheck;



  Adafruit_IS31FL3731* display;
  Adafruit_IS31FL3731* display1;

};
