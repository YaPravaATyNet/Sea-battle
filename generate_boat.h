#ifndef GENERATE_BOAT_H

#define GENERATE_BOAT_H

#include <stdio.h>
#include <stdlib.h>
#include "description.h"

void generateAllBoats(struct Field *gameField);
void generateBoat(int size, struct Field *gameField);
int checkOfBoat(int x, int y, enum direction dir, int size);
int checkOfLocation(int x, int y, enum direction dir, int size, struct Field *gameField);
int check(int x, int y, enum direction dir, int size, struct Field *field);
void createBoat(int x, int y, enum direction dir, int size, struct Field *gameField);

#endif // GENERATE_BOAT_H
