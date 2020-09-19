#include <stdio.h>
#include <stdlib.h>
#include "description.h"
#include "generate_boat.h"
#include "player_boat.h"
#include "gameplay.h"


int main(){
  srand(time(NULL));
  struct Field fieldOfComputer;
  generateField(&fieldOfComputer);
  generateAllBoats(&fieldOfComputer);
  struct Field fieldOfPlayer;
  generateField(&fieldOfPlayer);
  generateAllBoats(&fieldOfPlayer);
  //createBoatsOfPlayer(&fieldOfPlayer);
  game(&fieldOfPlayer, &fieldOfComputer);
  return 0;
}
