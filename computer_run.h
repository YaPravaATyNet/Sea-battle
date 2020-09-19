#ifndef COMPUTER_RUN_H

#define COMPUTER_RUN_H

#include <stdio.h>
#include "player_run.h"

void computerTurn(struct Field *fieldOfPlayer,  int *hit, int *hitX, int *hitY);
void choiceOfCoordinates(int hitX, int hitY, int *x, int *y, struct Field *battleComputer);
int missOrBorder(int x, int y, struct Field *field);

#endif // COMPUTER_RUN_H
