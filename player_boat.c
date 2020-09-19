#include <stdio.h>
#include "player_boat.h"
#include "generate_boat.h"


void createBoatsOfPlayer(struct Field *gameField){
  printf("Now you must put your boats on the field. ");
  printf ("Enter number of line, number of column, direction and size (0 - up, 1 - right, 2 - down, 3 - left), press \"Enter\" and boat will appear on your field\n");
  struct Boat boat;
  int i = 0;
  while (i < 10){
    printf("Enter boat (line, column, direction, size): ");
    scanf("%d%d%d%d", &boat.x, &boat.y, &boat.dir, &boat.size);
    if((check(boat.x, boat.y, boat.dir, boat.size, &*gameField) == 1) && (checkOfData(boat.x, boat.y, boat.dir, boat.size) == 1)){
      createBoat(boat.x, boat.y, boat.dir, boat.size, &*gameField);
      i++;
      system(CLS);
      printField(&*gameField);
    }
    else printf("Error");
    printf("\n");
  }
}

int checkOfData (int x, int y, enum direction dir, int size){
    if ((x <= 10) && (x > 0) && (y <= 10) && (y > 0) && (dir <= 3) && (dir >= 0) && (size <= 4) && (size > 0))
      return 1;
    else
      return 0;
}

void printField(struct Field *gameField){
  for (int i = 0; i < N + 2; i++){
    for (int j = 0; j < N + 2; j++){
      printf("%c ", gameField -> field[i][j]);
    }
    printf("\n");
  }
}

