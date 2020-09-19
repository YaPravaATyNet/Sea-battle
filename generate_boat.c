#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "generate_boat.h"

void generateAllBoats(struct Field *gameField){
  int i, j;

  for (i = 4; i > 0 ; i--){
    for (j = 0; j < (5 - i); j++)
        generateBoat(i, &*gameField);
  }
}

void generateBoat(int size, struct Field *gameField){
  struct Boat boat;
  do{
    boat.x = (rand() % N) + 1;
    boat.y = (rand() % N) + 1;
    boat.dir = rand() % 4;
  } while (check(boat.x, boat.y, boat.dir, size, &*gameField) == 0);
  createBoat(boat.x, boat.y, boat.dir, size, &*gameField);
}

int checkOfBoat(int x, int y, enum direction dir, int size){
  switch (dir){
    case UP : return (x - size < 0) ? 0 : 1;  break;
    case RIGHT : return (y + size > N + 1) ? 0 : 1; break;
    case DOWN : return (x + size > N + 1) ? 0 : 1; break;
    case LEFT : return (y - size < 0) ? 0 : 1; break;

  }
}

int checkOfLocation(int x, int y, enum direction dir, int size, struct Field *gameField){
  int counter = 0;
  int x1 = x - 1;
  int x2 = x + 1;
  int y1 = y - 1;
  int y2 = y + 1;
  switch (dir){
    case UP : x1 = x - size; break;
    case RIGHT : y2 = y + size; break;
    case DOWN : x2 = x + size; break;
    case LEFT : y1 = y - size; break;
  }
  for (int i = x1; i <= x2; i++){
    for (int j = y1; j <= y2; j++){
      if (gameField -> field[i][j] != BOAT)
            counter++;
    }
  }

  return (counter == 3 * (size + 2)) ? 1:0;

}

int check(int x, int y, enum direction dir, int size, struct Field *field){
  return((checkOfLocation(x, y, dir, size, &*field) == 1) && (checkOfBoat(x, y, dir, size) == 1)) ? 1 : 0;
}

void createBoat(int x, int y, enum direction dir, int size, struct Field *gameField){
  int x1 = x;
  int y1 = y;
  for(int i = 0; i < size; i++){
    switch(dir){
      case UP : x1 = x - i; break;
      case RIGHT : y1 = y + i; break;
      case DOWN : x1 = x + i; break;
      case LEFT : y1 = y - i; break;
    }
    gameField -> field[x1][y1] = BOAT;
  }

}




