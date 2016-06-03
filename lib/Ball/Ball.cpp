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
}
