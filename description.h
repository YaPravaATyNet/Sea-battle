#ifndef DESCRIPTION_H

#define DESCRIPTION_H

#include "information.h"

enum direction {
  UP,
  RIGHT,
  DOWN,
  LEFT
};

enum orientation {
  VERT,
  HOR
};

struct Boat{
  int size;
  int x, y;
  enum direction dir; // 0 - наверх, 1 - вправо, 2 - вниз, 3 - влево;
};

struct Field{
  char field[N + 2][N + 2];
  int kill;
};
void generateField(struct Field *gamefield);

#endif // DESCRIPTION_H
