#include <Game.h>


//TODO UNTESTED

Game::Game(Player* player1, Player* player2, Button* confirmButton){
  this->p1 = player1;
  this->p2 = player2;
  this->confirmButton = confirmButton;

  p1->displayNumber();
  p2->displayNumber();

  difficulty = 1;
}

bool Game::ready(){
  return p1->pot->test() && p2->pot->test();
}
uint8_t Game::chooseDifficulty(){
  p1->display->printText(0, 0, "Press confirm button when yes", 125, true, false, 0, 5);
  p2->display->printText(0, 0, "Press confirm button when yes", 125, true, false, 0, 5);

  while(!confirmButton->get()){
    if(!p2->button->get()){
      p1->display->drawChar(0, 0, '+', 125, 0, 1);
    } else {
      p1->display->clear();
      p2->display->drawChar(5, 0, '1', 125, 0, 1); //-1
      difficulty--;
      p2->display->printText(0, 0, "D: " + difficulty, 125, true, false, 0, 5);
      delay(250);
    }
    if(!p1->button->get()){
      p2->display->drawChar(0, 0, '-', 125, 0, 1);
    } else {
      p2->display->clear();
      p1->display->drawChar(5, 0, '1', 125, 0, 1); //+1
      difficulty++;
      p1->display->printText(0, 0, "D: " + difficulty, 125, true, false, 0, 5);
      delay(250);
    }
  }
  return difficulty;
}

bool Game::playAgain(){
  bool p1PlayAgain = false;
  bool p2PlayAgain = false;
  p1->display->printText(0, 0, "Play again? y/n press button", 125, true, false, 0, 5);
  p2->display->printText(0, 0, "Play again? y/n press button", 125, true, false, 0, 5);
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
void Game::displayScore(){
  p1->display->printText(0, 0, p1->score + ":" + p2->score, 125, true, true, 1, 5);
  p2->display->printText(0, 0, p1->score + ":" + p2->score, 125, true, true, 1, 5);
}
void Game::countdown(){
  for(int i = 3; i >= 0; i++){
    p1->display->drawChar(0, 0, i, 125, 0, 1);
    p2->display->drawChar(0, 0, i, 125, 0, 1);
  }
}
void Game::drawLoseAnim(){

}
void Game::drawWinAnim(){
  
}
/*private*/
