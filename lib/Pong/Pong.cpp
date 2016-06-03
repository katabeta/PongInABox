#include <Pong.h>


/**
@class Pong
    Defines the behaviour of the game of Pong. Extends Game.
    This is the class where the bahaviour specific to the game of pong is defined.

@param player1
    The *pointer* to the first player of the game (P1, player whose number variable is 1).
@param player2
    The *pointer* to the second player of the game (P2, player whose number variable is 2).
@param cofirmbutton
    The *pointer* to the button that isn't assigned to either of the players.

@test

@author Irina Lavryonova (katabeta)
*/

Pong::Pong(Player* player1, Player* player2, Button* confirmButton, bool winByLead, int scoreConstraint) : Game(player1, player2, confirmButton, winByLead, scoreConstraint), m_ball(player1, player2){
  this->p1 = player1;
  this->p2 = player2;
  //this->ball = Ball(p1, p2);
}

/*public*/
/**
Call this method to start the game. This method defines the sequence of events
to play pong. At the end of the sequence, it asks the users if they want to play again.
Public.

@todo NOT FINISHED
*/
void Pong::start(){
  do{
    Game::ready();
    Game::chooseDifficulty();
  }while(playAgain());
}

void Pong::update(){
  this->m_ball.draw();
  this->p1->pot->drawPaddle();
  this->p2->pot->drawPaddle();
}


/*private*/
