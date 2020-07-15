#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "func.h"

int lcm (int a, int b)
{
  int m = 1;

  while (m % a || m % b)
    m++;

  return m;
}

int hyperperiod (int period[],size_t arr_size)
{
  int hp = 0;

  hp = period[0];

  for (int i = 1; i < arr_size; i++)
    {
      hp = lcm (hp, period[i]);
    }
    
  printf ("hyper period is : ");
  printf ("%d", hp);
  printf ("\n");

  return hp;
}