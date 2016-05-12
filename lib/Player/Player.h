#pragma once
#include <Button.h>
#include <Adafruit_IS31FL3731.h>
#include <Pot.h>

class Player{
private:
public:
  Player(Button* button, Pot* pot, Adafruit_IS31FL3731* display, uint8_t number);

  void displayNumber(void);

  Button* button; /**< stores the *pointer* to this player's button. To call methods on it, instead of exampleButton.printText(...); use exampleButton->printText(...); */
  Pot* pot; /**< stores the *pointer* to this player's potentiometer. To call methods on it, instead of examplePot.printText(...); use examplePot->printText(...); */
  Adafruit_IS31FL3731* display; /**< stores the *pointer* to this player's display. To call methods on it, instead of exampleDisplay.printText(...); use exampleDisplay->printText(...); */
  uint8_t number; /**< stores the number of this player (1 or 2) */
  uint16_t score; /**< stores the score of this player. _If the game is based on score, then this must be updated throughout the game_*/
};
