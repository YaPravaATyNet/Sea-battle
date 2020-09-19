#include <stdio.h>
#include "description.h"

void generateField(struct Field *gamefield){

  for (int i = 0; i < N + 2; i++)
    gamefield -> field[0][i] = BORDER_HOR;
  for (int i = 1; i < N + 1; i++){
    gamefield -> field[i][0] = BORDER_VER;
    for (int j = 1; j < N + 1; j++){
        gamefield -> field[i][j] = SEA;
    }
    gamefield -> field[i][N + 1] = BORDER_VER;
  }
  for (int i = 0; i < N + 2; i++)
    gamefield -> field[N + 1][i] = BORDER_HOR;
}
