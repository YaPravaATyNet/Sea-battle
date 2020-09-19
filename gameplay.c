#include <stdio.h>
#include "gameplay.h"
#include "description.h"
#include "player_boat.h"

void game(struct Field *fieldOfPlayer, struct Field *fieldOfComputer){
  fieldOfPlayer->kill = 0;
  fieldOfComputer->kill = 0;
  int hit = 0;
  int hitX = 0;
  int hitY = 0;
  while ((fieldOfPlayer->kill < NUMBER_OF_ALL_BOATS) && (fieldOfComputer->kill < NUMBER_OF_ALL_BOATS)){
    playerTurn(&*fieldOfComputer, &*fieldOfPlayer);
    computerTurn(&*fieldOfPlayer, &hit, &hitX, &hitY);
  }
  system(CLS);
  if (fieldOfPlayer->kill == NUMBER_OF_ALL_BOATS){
    printf("YOU LOSE\nYour field\n");
  }
  if (fieldOfComputer->kill == NUMBER_OF_ALL_BOATS){
    printf("YOU WIN\nYour Field\n");
  }
  printField(&*fieldOfPlayer);
  printf("Computer's field\n");
  printField(&*fieldOfComputer);
}


