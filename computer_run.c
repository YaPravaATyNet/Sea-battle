#include <stdio.h>
#include "computer_run.h"
#include "player_run.h"

void computerTurn(struct Field *fieldOfPlayer, int *hit, int *hitX, int *hitY) {
  int x, y;
  if (*hit == 0) {
    *hitX = 0;
    *hitY = 0;
  }
  if (*hit == 1)
    choiceOfCoordinates(*hitX, *hitY, &x, &y, &*fieldOfPlayer);
  else{
    do{
      x = (rand() % N) + 1;
      y = (rand() % N) + 1;
    } while ((fieldOfPlayer->field[x][y] != SEA) && (fieldOfPlayer->field[x][y] != BOAT));
  }

  if (fieldOfPlayer->field[x][y] == SEA){
    fieldOfPlayer->field[x][y] = MISS;
  }
  else{
   if((fieldOfPlayer->field[x][y] == BOAT) && (killOrHit(&*fieldOfPlayer, x, y) == 1)) {
      fieldOfPlayer->field[x][y] = KILL;
      fieldOfPlayer->kill++;
      zoneOfMiss(&*fieldOfPlayer, x, y);
      *hit = 0;
      if (fieldOfPlayer->kill < 10){
        computerTurn(&*fieldOfPlayer, &*hit, hitX, hitY);
      }
    }
    else{
      fieldOfPlayer->field[x][y] = KILL;
      *hit = 1;
      *hitX = x;
      *hitY = y;
      computerTurn(&*fieldOfPlayer, &*hit, hitX, hitY);
    }
  }
}

void choiceOfCoordinates(int hitX, int hitY, int *x, int *y, struct Field *battleComputer) {
  enum orientation dir;
  if((battleComputer->field[hitX - 1][hitY] == KILL) || (battleComputer->field[hitX + 1][hitY] == KILL))
    dir = VERT; //вертикально
  else
    dir = HOR; //горизонтально
  if ((missOrBorder(hitX + 1, hitY, &*battleComputer) == 1) &&(missOrBorder(hitX - 1, hitY, &*battleComputer) == 1))
          dir = HOR;
  if ((missOrBorder(hitX, hitY + 1, &*battleComputer) == 1) &&(missOrBorder(hitX, hitY - 1, &*battleComputer) == 1))
          dir = VERT;
  if(dir == VERT){
    if (missOrBorder(hitX - 1, hitY, &*battleComputer) == 1)
      funct(hitX, hitY, 1, 0, &*x, &*y, &*battleComputer);
    else {
      if (missOrBorder(hitX + 1, hitY, &*battleComputer) == 1)
        funct(hitX, hitY, -1, 0, &*x, &*y, &*battleComputer);
      else{
        *x = hitX - 1;
        *y = hitY;
      }
    }
  }
  if (dir == HOR){
    if (missOrBorder(hitX, hitY - 1, &*battleComputer) == 1)
      funct(hitX, hitY, 0, 1, &*x, &*y, &*battleComputer);
    else {
      if (missOrBorder(hitX, hitY + 1, &*battleComputer) == 1)
        funct(hitX, hitY, 0, -1, &*x, &*y, &*battleComputer);
      else{
        *x = hitX;
        *y = hitY - 1;
      }
    }
  }
}

int missOrBorder(int x, int y, struct Field *field){
    return ((field->field[x][y] == MISS) || (field->field[x][y] == BORDER_HOR) || (field->field[x][y] == BORDER_VER)) ? 1 : 0;
}

void funct(int hitX, int hitY, int m, int n, int*x, int*y, struct Field *battle){
  int i = 0;
  while (i < 4){
    if (battle->field[hitX + m][hitY + n] == KILL){
      hitX = hitX + m;
      hitY = hitY + n;
      i++;
    }
    else{
      *x = hitX + m;
      *y = hitY + n;
      break;
    }
  }
}
