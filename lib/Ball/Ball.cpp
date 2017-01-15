<<<<<<< HEAD
#include <Ball.h>
//#include <Adafruit_IS31FL3731.h>
#include <Arduino.h>

Ball::Ball(Player* p1, Player* p2, int delay) : reference(){
  randomSeed(analogRead(reference.aPinSeed));
  this->p1 = p1;
  this->p2 = p2;
  this->delay = delay;
  genNewVals();
  this->lastTime = 0;
  this->currTime = millis();
}

/**
Draws the ball.

@test
*/
void Ball::draw(){
  currTime = millis();
  if(currTime - lastTime > delay){
    clear();
    move();
    getCurrDisp()->drawPixel(x, y, reference.qBright);
    lastTime = currTime;
  }
}

void Ball::genNewVals(){
  this->on74 = true; //random(2) == 1;
  this->x1 = 5;//random(4 ,6);
  this->y1 = 9;//random(7, 9);
  this->x = x1;
  this->y = y1;
  this->dX = 1;//random(-2, 3);
  this->dY = -1;//random(-2, 3);
  this->t = 0;
}

void Ball::printStats(){
  Serial.println("BALL X: " + String(x) + " Y: " + String(y) + " T: " + String(t) + " dX: " + String(dX)+ " dY: " + String(dY) + " DISP: " + String(on74) + "M: " + String(dY/dX));
}
/**
@todo documentation
@todo UNTESTED
*/
void Ball::clear(){
  getCurrDisp()->drawPixel(x, y, 0);
}

/**
@todo documentation
@test
*/
void Ball::move(){
  t++;
  //Serial.println("OLD");
  //printStats();

  x = x1 + dX * t;
  y = y1 + dY * t;

  //Serial.println("NEW");
//  printStats();

  uint8_t currPotPos = getCurrPot()->getPaddlePos();
  Serial.println(String(currPotPos));
  if(y == 9 && (x <= currPotPos && x >= currPotPos + getCurrPot()->getPaddleSize())){
    Serial.println("PADDLE COLLISION");
    dY *= -1;
    dX *= -1;
    y = 8;
  }

  if(y > 9){
    genNewVals();
  //  Serial.println();
    //Serial.println("GENERATING NEW VALUES");
  //  Serial.println();
  }

  if(y < 0){
    //Serial.println();
    //Serial.println("SWITCHING SCREEN");
  //  Serial.println();
    on74 ^= true;
    x = dY/dX || dX/dY == 0 ? 15 - x: 15 - x + dY/dX;
    y = 0;
    x1 = x;
    y1 = y;
    t = 0;
    dX *= -1;
    dY *= -1;
    //Serial.println("SWITCHED");
    //printStats();
  }

  if(x > 14 || x < 1){
    dX *= -1;
  //  Serial.println();
    //Serial.println("WALL COLLISION");
    //Serial.println();
  }
}

/**
@todo documentation
@test
*/
Adafruit_IS31FL3731* Ball::getCurrDisp(){
  return on74 ? p1->display : p2->display;
}

/**
@todo documentation
@test
*/
Pot* Ball::getCurrPot(){
  return on74 ? p1->pot : p2->pot;
=======
# include <Ball.h>


Ball::Ball(int x1, int y1, Player* player, Player* player1) : reference()
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

    screenCheck = !screenCheck;


  }
  if((x1>=player->pot->getCoord() && x1<=player->pot->getCoord() +2 && y1<=1 && screenCheck) ||
    (x1>=player1->pot->getCoord() && x1<=player1->pot->getCoord() +2 && y1<=1 && !screenCheck)){
      yz=-yz;
  }
  return screenCheck;
}

void Ball::drawBall(){
  clear();
  move();
  if(collisions())
  {
    display->drawPixel(x1,y1,reference.qBright);
  }
  else
  {
    display1->drawPixel(x1,y1,reference.qBright);
  }


>>>>>>> 0df60bc24b96fcefa4670f02c5314b11fca55191
}
