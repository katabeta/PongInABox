#include <Player.h>


/**
@class Player
  Stores individual variables of a player.

@param button
    The *pointer* to the button of this player.
@param pot
    The *pointer* to the pot of this player.
@param display
    The *pointer* to the display of this player.
@param number
    The number of this player (1 or 2).

@test

@author Irina Lavryonova (katabeta)
*/
Player::Player(Button* button, Pot* pot, Adafruit_IS31FL3731* display, uint8_t number){
  this->button = button;
  this->pot = pot;
  this->display = display;
  this->number = number;
  this->score = 0;
}
