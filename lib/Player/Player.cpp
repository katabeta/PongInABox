#include <Player.h>

//TODO untested

Player::Player(Button* button, Pot* pot, Adafruit_IS31FL3731* display, uint8_t number){
  this->button = button;
  this->pot = pot;
  this->display = display;
  this->number = number;
  this->score = 0;
}

void Player::displayNumber(){
  display->printText(0, 0, "P" + number, 0, true, false, 0, 5);
}
