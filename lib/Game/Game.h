#pragma once
#include <Arduino.h>
#include <Player.h>
//#include <Button.h> ???


class Game{
private:
  Player* p1; /**< stores the *pointer* to the first player. To call methods on it, instead of examplePlayer.printText(...); use examplePlayer->printText(...);. To call methods of its members, use examplePlayer->exampleDisplay->printText(...);*/
  Player* p2; /**< stores the *pointer* to the second player. To call methods on it, instead of examplePlayer.printText(...); use examplePlayer->printText(...);. To call methods of its members, use examplePlayer->exampleDisplay->printText(...);*/
  Button* confirmButton; /**< stores the *pointer* to the button that isn't assigned to either player. To call methods on it, instead of exampleButton.printText(...); use exampleButton->printText(...); */
  uint8_t difficulty; /**< stores the settings difficulty*/

public:
  Game(Player* player1, Player* player2, Button* button);
  bool ready(void);
  uint8_t chooseDifficulty(void);
  void countdown(void);
  void displayScore(void); // s1 : s2
  void drawWinAnim(void);
  void drawLoseAnim(void);
  bool playAgain(void);
};
