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

void Ball::clear(){
  display->drawPixel(x1, y1, 0);
  display1->drawPixel(x1, y1, 0);
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
    if(screenCheck)
    {
      player1->score= player1->score + 1;

    }
    else
    {
      player->score= player->score + 1;

    }


    x1 = random(15);
    y1 = random(6,8);
    screenInt = random(2);
    screenCheck = screenInt ? 0 : 1;


  }
  if((x1>=player->pot->getCoord() && x1<=player->pot->getCoord() +2 && y1<=1 && !screenCheck) ||
    (x1>=player1->pot->getCoord() && x1<=player1->pot->getCoord() +2 && y1<=1 && screenCheck)){
      yz=-yz;
  }
  return screenCheck;
}

void Ball::drawBall(){
  clear();
  move();
  if(collisions())
  {
    display->drawPixel(x1,y1,10);
  }
  else
  {
    display1->drawPixel(x1,y1,10);
  }


}
