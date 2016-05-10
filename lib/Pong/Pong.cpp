#include <Pong.h>


//TODO UNTESTED

Pong::Pong(Player* player1, Player* player2, Button* confirmButton) : Game(player1, player2, confirmButton){
}

/*public*/
void Pong::start(){
  do{
    Game::ready();
    Game::chooseDifficulty();
  }while(playAgain());
}
/*private*/
void drawField(){
  
}
