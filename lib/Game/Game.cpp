#include <Game.h>
#include <Ball.h>
#include <Player.h>


/**
@class Game
    defines general methods for all or most games.

@param player1
    the *pointer* to the first player of the game (P1, player whose number variable is 1).
@param player2
    the *pointer* to the second player of the game (P2, player whose number variable is 2).
@param cofirmbutton
    the *pointer* to the button that isn't assigned to either of the players.
@param winByLead
    set to true if the winning condition of this game depends on one player leading the other by a certain amount. Give the winning lead amount in the scoreCostraint argument if set to true.
@param scoreConstraint
    top score that would serve as the winning condition (relative or absolute score)

@test

@author Irina Lavryonova (katabeta)
*/
Game::Game(Player* player1, Player* player2, Button* confirmButton, Ball* ball, bool winByLead, int scoreConstraint):reference(){
  this->p1 = player1;
  this->p2 = player2;
  this->ball = ball;
  this->confirmButton = confirmButton;

  difficulty = 1;
}

/**
prompts the both of the players if they are ready.

@return true if both players press their button at prompt, false otherwise.

@todo if in a while loop, may need to put the return in a timeout to allow for a responce time
or alternatively have the confimation button be the decline button. However, that would muddle
its meaning.

@test
*/
bool Game::ready(){
  bool b1 = p1->button->get();
  bool b2 = p2->button->get();
  bool bt = b1 && b2;
  //Serial.println("b1: " + String(b1) + " b2: " + String(b2) + " bt: " + String(bt));
  return bt; //p1->button->get() && p2->button->get();
}

/**
Prompts the players to select a setting.

@test
*/
uint8_t Game::chooseDifficulty(){
  p1->display->printText("Press confirm button when yes", 1, false, 1);
  p2->display->printText("Press confirm button when yes", 1, false, 1);

  while(!confirmButton->get()){
    if(!p2->button->get()){
      p1->display->drawChar(0, 0, '+', 125, 0, 1);
    } else {
      p1->display->clear();
      p2->display->drawChar(5, 0, '1', 125, 0, 1); //-1
      difficulty--;
      p2->display->printText("D: ", 1, false, 1);
      delay(250);
    }
    if(!p1->button->get()){
      p2->display->drawChar(0, 0, '-', 125, 0, 1);
    } else {
      p2->display->clear();
      p1->display->drawChar(5, 0, '1', 125, 0, 1); //+1
      difficulty++;
      p1->display->printText("D: ", 1, false, 1);
      delay(250);
    }
  }
  return difficulty;
}

/**
Prompts the players if they want to play again.

@return true if both players want to play again, false otherwise.

@test
*/
bool Game::playAgain(){
  bool p1PlayAgain = false;
  //bool p2PlayAgain = false;
  p1->display->clear();
  p2->display->clear();
  p1->display->printText("Again?", 1, false, reference.qBright);
  p2->display->printText("Again?", 1, false, reference.qBright);

  bool toReturn = false;
  while(!toReturn){
    if(!p1->button->isPressed() && !p1PlayAgain){
      p1->display->drawChar(5, 0, 'N', reference.qBright, 0, 1);
      p2->display->drawChar(5, 0, 'N', reference.qBright, 0, 1);
    }
    if (p1->button->isPressed() || p2->button-> isPressed()){
      p1->display->clear();
      p2->display->clear();
      p1->display->drawChar(5, 0, 'Y', reference.qBright, 0, 1);
      p2->display->drawChar(5, 0, 'Y', reference.qBright, 0, 1);
      delay(2000);
      p1->display->clear();
      p2->display->clear();
      p1->score = 0;
      p2->score = 0;
      toReturn = true;

    }
    // if(!p2->button->isPressed() && !p2PlayAgain){
    //   p2->display->drawChar(0, 0, 'n', 125, 0, 1);
    // }
    //if (p2->button->isPressed()){
    //  p2->display->clear();
    //   p2->display->drawChar(0, 0, 'y', 125, 0, 1);
    //   p2PlayAgain = true;
    // }
    // if(p2->button->isPressed()){
    //   p1PlayAgain = false;
    //   //p1->display->drawChar(0, 0, 'w', 125, 0, 1);
    //   //p2->display->drawChar(0, 0, 'w', 125, 0, 1);
    //   break;
    // }
    //toReturn = p1PlayAgain;
    // if (p1->button->isPressed() == 1 || toReturn == 1){
    //   Serial.println("p1: " + String(p1->button->isPressed()) + " p2: "+ String(p2->button->isPressed()) + " toReturn: "+ String(toReturn));
    // }

  }


  return toReturn; //true only if both are true
}

/**
displays the score of both players on both of the displays,
with the first player's score first and the second player's score
second. Make sure to Player::displayNumber() at some point before
this so that the player knows which score is theirs.

@test
*/
void Game::displayScore(){
  p1->display->printText(p1->score + ":" + p2->score, 1, false, reference.qBright);
  p2->display->printText(p1->score + ":" + p2->score, 1, false, reference.qBright);
}

/**
counts down from 3 to 0 on both of the screen to signal that the game is about to start
and the players should be ready.

@test
*/
void Game::countdown(){
  p1->display->setRotation(2);
  p2->display->setRotation(0);
  for(int i = 3; i >= 0; i--){
    p1->display->drawChar(5, 0, String(i)[0], reference.qBright, 0, 1);
    p2->display->drawChar(5, 0, String(i)[0], reference.qBright, 0, 1);
    delay(1000);
  }
  p1->display->clear();
  p2->display->clear();
  p1->display->setRotation(0);
  p2->display->setRotation(2);
}

/**
draws the losing animation on the losing player's display

@param loser
    the *pointer* to the player who lost the game

@todo UNIMPLEMENTED
*/
void Game::drawLoseAnim(Player* loser){

  loser->display->drawChar(0, 0, 'L', reference.qBright, 0, 1);
  loser->display->drawChar(10, 0, String(loser->score)[0], reference.qBright, 0,1);
}

/**
draws the winning animation on the winning player's display

@param winner
    the *pointer* to the player who won the game

@todo UNIMPLEMENTED
*/
void Game::drawWinAnim(Player* winner){

  winner->display->drawChar(0, 0, 'W', reference.qBright, 0, 1);
  winner->display->drawChar(10, 0, String(winner->score)[0] , reference.qBright, 0,1);
}

bool Game::gameEnd(){
  if((p1->score==5) || (p2->score ==5)){
    return true;
  }
  else
  {
    return false;
  }
}
/*private*/
