#include <stdio.h>
#include "player_run.h"
#include "player_boat.h"

void playerTurn(struct Field *fieldOfComputer, struct Field *fieldOfPlayer){
  system(CLS);
  printf("Your field\n");
  printField(&*fieldOfPlayer);
  printf("\nComputer's field\n");
  printFieldWithoutBoats(&*fieldOfComputer);
  printf("\n");
  int x, y;
  do{
    printf("Choose target (line, column):");
    scanf("%d%d", &x, &y);
    if (checkOfData(x, y, 1, 1) == 0)
      printf("Error\n");
    else {
      if ((fieldOfComputer->field[x][y] == MISS) || (fieldOfComputer->field[x][y] == KILL))
        printf("This target is checked\n");
    }
  }while ((checkOfData(x, y, 1, 1) == 0)  || (fieldOfComputer->field[x][y] == MISS) || (fieldOfComputer->field[x][y] == KILL));
  if (fieldOfComputer->field[x][y] == SEA){
    fieldOfComputer->field[x][y] = MISS;
  }
  else{
    if((fieldOfComputer->field[x][y] == BOAT) && (killOrHit(&*fieldOfComputer, x, y) == 1)){
      fieldOfComputer->field[x][y] = KILL;
      fieldOfComputer->kill++;
      zoneOfMiss(&*fieldOfComputer, x, y);
      if (fieldOfComputer->kill < 10)
        playerTurn(&*fieldOfComputer, &*fieldOfPlayer);
    }
    else{
      fieldOfComputer->field[x][y] = KILL;
      playerTurn(&*fieldOfComputer, &*fieldOfPlayer);
    }
  }
}

void printFieldWithoutBoats(struct Field *field){
  for (int i = 0; i < N + 2; i++){
    for (int j = 0; j < N + 2; j++){
      if (field -> field[i][j] == BOAT)
        printf("%c ", SEA);
      else
        printf("%c ", field -> field[i][j]);
    }
    printf("\n");
  }
}

void zoneOfMiss(struct Field *field, int x, int y){
  enum orientation dir; // 0 - вертикально, 1 = горизонтально
  if  ((field->field[x - 1][y] == KILL) || (field->field[x + 1][y] == KILL))
    dir = VERT;
  else
    dir = HOR;

  int k = 0;
  while(k < 3){
    if (field->field[x - 1][y] == KILL){
      x--;
      k++;
    }
    else {
      if (field->field[x][y - 1] == KILL){
        y--;
        k++;
      }
      else
        break;
    }
  }

  int size = 1;
  int x1 = x - 1;
  int y1 = y - 1;
  if (dir == VERT){
    while (field->field[x][y] == KILL){
      if (field->field[x + 1][y] == KILL){
        size++;
        x++;
      }
      else
        break;
    }
    int x1 = x - size;
  }
  if (dir == HOR){
    while (field->field[x][y] == KILL){
      if (field->field[x][y + 1] == KILL){
        size++;
        y++;
      }
      else
        break;
    }
    int y1 = y - size;
  }
  for (int i = x1; i <= x + 1; i++){
    for (int j = y1; j <= y + 1; j++){
      if (field->field[i][j] == SEA){
        field->field[i][j] = MISS;
      }
    }
  }
}

int killOrHit(struct Field *field, int x, int y) {
  int counter;
  counter = count(x, y, 0, 1, &*field) + count(x, y, 0, -1, &*field) + count(x, y, 1, 0, &*field) + count(x, y, -1, 0, &*field);
  return (counter == 4) ? 1 : 0;
}

int count(int x, int y, int m, int n, struct Field *field){
  int counter = 0;
    if ((field->field[x + m][y + n]) != BOAT) {
      if ((field->field[x + m][y + n]) == KILL) {
        if ((field->field[x + 2 * m][y + 2 * n]) != BOAT) {
          if ((field->field[x + 2 * m][y + 2 * n]) == KILL) {
             if ((field->field[x + 3 * m][y + 3 * n]) != BOAT)
               counter++;
          }
          else counter++;
        }
      }
      else counter++;
    }
  return counter;
}


