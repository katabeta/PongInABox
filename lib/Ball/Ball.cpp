# include <Ball.h>

Ball::Ball(int x1, int y1, Adafruit_IS31FL3731* display)
{
  this->x1 = 0;
  this->y1 =0;
  this->display = display;
}
void Ball::move(){
  x1 =x1 + 1;
  y1 = y1 + 1;
}

void Ball::collisions(){
  if (x1<=0)
  {
    x1 = -x1;
  }
if (y1>8)
{
  if(screenCheck)
}
}
void Ball::drawBall(){
  
  display->drawPixel(x1,y1,125);
}
