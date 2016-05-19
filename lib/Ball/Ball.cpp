# include <Ball.h>

Ball::Ball(int x1, int y1, Adafruit_IS31FL3731* display)
{
  this->x1 = 0;
  this->y1 =0;
  this->display = display;
}
void Ball::move(){
  x1 = zx* x1;
  y1 = zy*y1;
}

void Ball::collisions(){
  if (x1<=0)
  {
    zx = -zx;
  }
  if
}
void Ball::drawBall(){

  display->drawPixel(x1,y1);
}
