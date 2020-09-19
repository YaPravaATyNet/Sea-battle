#ifndef PLAYER_BOAT_H

#define PLAYER BOAT_H

#include <stdio.h>
#include "generate_boat.h"

void createBoatsOfPlayer(struct Field *gameField);
int checkOfData (int x, int y, enum direction dir, int size);
void printField(struct Field *gameField);

#endif // PLAYER_BOAT_H
