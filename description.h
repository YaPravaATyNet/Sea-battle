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
  enum direction dir; // 0 - ������, 1 - ������, 2 - ����, 3 - �����;
};

struct Field{
  char field[N + 2][N + 2];
  int kill;
};
void generateField(struct Field *gamefield);

#endif // DESCRIPTION_H
