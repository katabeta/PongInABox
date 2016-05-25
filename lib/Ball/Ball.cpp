# include <Ball.h>

Ball::Ball(int x1, int y1, Player* player, Player* player1)
{
  randomSeed(analogRead(2));
  this->x1 = random(15);
  this->y1 = random(6,8);
  this->player = player;
  this->player1 = player1;
  this->display = player->display;
  this->display1 = player1->display;
  this->xz = 1;
  this->yz=1;
  this->screenInt = random(2);
  screenCheck = screenInt ? 0 : 1;
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
    y1 = random(6,8);
    screenInt = random(2);
    screenCheck = screenInt ? 0 : 1;

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
