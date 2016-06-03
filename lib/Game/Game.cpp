#include <Game.h>


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
Game::Game(Player* player1, Player* player2, Button* confirmButton, bool winByLead, int scoreConstraint){
  this->p1 = player1;
  this->p2 = player2;
  this->confirmButton = confirmButton;

  p1->displayNumber();
  p2->displayNumber();

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
  return p1->pot->test() && p2->pot->test();
}

/**
Prompts the players to select a setting.

@test
*/
uint8_t Game::chooseDifficulty(){
  p1->display->printText("Press confirm button when yes", 1, false, 2);
  p2->display->printText("Press confirm button when yes", 1, false, 2);

  while(!confirmButton->get()){
    if(!p2->button->get()){
      p1->display->drawChar(0, 0, '+', 125, 0, 1);
    } else {
      p1->display->clear();
      p2->display->drawChar(5, 0, '1', 125, 0, 1); //-1
      difficulty--;
      p2->display->printText("D: " + difficulty, 1, false, 2);
      delay(250);
    }
    if(!p1->button->get()){
      p2->display->drawChar(0, 0, '-', 125, 0, 1);
    } else {
      p2->display->clear();
      p1->display->drawChar(5, 0, '1', 125, 0, 1); //+1
      difficulty++;
      p1->display->printText("D: " + difficulty, 1, false, 2);
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
  bool p2PlayAgain = false;
  p1->display->printText("Play again? y/n press button", 1, false, 2);
  p2->display->printText("Play again? y/n press button", 1, false, 2);
  p1->display->clear();
  p2->display->clear();
  if(!p1->button->get()){
    p1->display->drawChar(0, 0, 'n', 125, 0, 1);
  } else{
    p1->display->clear();
    p1->display->drawChar(0, 0, 'y', 125, 0, 1);
    p2PlayAgain = true;
  }
  if(!p2->button->get()){
    p2->display->drawChar(0, 0, 'n', 125, 0, 1);
  } else{
    p2->display->clear();
    p2->display->drawChar(0, 0, 'y', 125, 0, 1);
    p2PlayAgain = true;
  }

  return p1PlayAgain && p2PlayAgain; //true only if both are true
}

/**
displays the score of both players on both of the displays,
with the first player's score first and the second player's score
second. Make sure to Player::displayNumber() at some point before
this so that the player knows which score is theirs.

@test
*/
void Game::displayScore(){
  p1->display->printText(p1->score + ":" + p2->score, 1, false, 2);
  p2->display->printText(p1->score + ":" + p2->score, 1, false, 2);
}

/**
counts down from 3 to 0 on both of the screen to signal that the game is about to start
and the players should be ready.

@test
*/
void Game::countdown(){
  Serial.println("Countdown start");
  for(int i = 3; i >= 0; i++){
    p1->display->drawChar(0, 0, i, 125, 0, 1);
    p2->display->drawChar(0, 0, i, 125, 0, 1);
  }
}

/**
draws the losing animation on the losing player's display

@param loser
    the *pointer* to the player who lost the game

@todo UNIMPLEMENTED
*/
void Game::drawLoseAnim(Player* loser){
  loser->display->drawChar(0, 0, 'L', 154, 0, 1);
}

/**
draws the winning animation on the winning player's display

@param winner
    the *pointer* to the player who won the game

@todo UNIMPLEMENTED
*/
void Game::drawWinAnim(Player* winner){
  winner->display->drawChar(0, 0, 'W', 154, 0, 1);
}

/**
checks whether the condition for a win has been reached

@return true if the win condition has been reached, false otherwise

@test
*/
bool Game::endGameReached(){
  if(winByLead){
    return abs(p1->score - p2->score) == scoreConstrant;
  } else{
    return (p1->score == scoreConstrant || p2->score == scoreConstrant);
  }
}
/*private*/
