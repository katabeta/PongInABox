#pragma once
#include <Arduino.h>
#include <Player.h>
//#include <Button.h> ???


class Game{
private:
  Player* p1; /**< stores the *pointer* to the first player. To call methods on it, instead of examplePlayer.printText(...); use examplePlayer->printText(...);. To call methods of its members, use examplePlayer->exampleDisplay->printText(...);*/
  Player* p2; /**< stores the *pointer* to the second player. To call methods on it, instead of examplePlayer.printText(...); use examplePlayer->printText(...);. To call methods of its members, use examplePlayer->exampleDisplay->printText(...);*/
  Ball* ball; /**< does something probably.*/
  Button* confirmButton; /**< stores the *pointer* to the button that isn't assigned to either player. To call methods on it, instead of exampleButton.printText(...); use exampleButton->printText(...); */
  uint8_t difficulty; /**< stores the settings difficulty*/
  bool winByLead; /**< stores whether this game is won by leading the other player by a certain amount*/
  int scoreConstraint; /**< stores the necessary relative or absolute score needed to win*/


public:
  Game(Player* player1, Player* player2, Button* confirmButton, bool winByLead, int scoreConstraint);
  bool ready(void);
  uint8_t chooseDifficulty(void);
  void countdown(void);
  void displayScore(void); // s1 : s2
  void drawWinAnim(Player* winner);
  void drawLoseAnim(Player* loser);
  bool playAgain(void);
  bool endGameReached(void);
};
