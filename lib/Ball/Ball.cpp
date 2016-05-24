# include <Ball.h>

Ball::Ball(int x1, int y1, Adafruit_IS31FL3731* display,Adafruit_IS31FL3731* display1)
{
  randomSeed(analogRead(2));
  this->x1 = random(15);
  this->y1 = random(8);
  this->display = display;
  this->display1 = display1;
  this->xz = 1;
  this->yz=1;
  int screenInt = random(2);
  if (screenInt == 0){
    this->screenCheck = true;
  }
  else {
    this->screenCheck = false;
  }
}
void Ball::move(){
    x1 = xz+x1;
    y1 = yz+y1;

}

bool Ball::collisions(){
  if (x1<=0 || x1>=15)
  {
    xz = -xz;
  }
  if (y1>8)
  {
    screenCheck = !screenCheck;
    yz = -yz;
    x1 = 15-x1;
    xz = -xz;
  }
  if(y1<=0)
  {
    x1 = random(15);
    y1 = random(8);
  }
  return screenCheck;
}

void Ball::drawBall(){
  move();
  if(collisions())
  {
    display->drawPixel(x1,y1,125);
  }
  else
  {
    display1->drawPixel(x1,y1,125);
  }

}
