#ifndef PLAYER_RUN_H

#define PLAYER_RUN_H

#include <stdio.h>
#include "player_boat.h"

void playerTurn(struct Field *fieldOfComputer, struct Field *fieldOfPlayer);
void printFieldWithoutBoats(struct Field *field);
void zoneOfMiss(struct Field *field, int x, int y);
int killOrHit(struct Field *field, int x, int y);
int count(int x, int y, int m, int n, struct Field *field);

#endif // PLAYER_RUN_H

