#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "func.h"


int main (void)
{

  char fname[20];
  
  int num, hp, frameSize;
  FILE *fptr = NULL;
  FILE *fptr1 = NULL;
  int i = 0;
  int count_lines = 1;
  char chr;
  printf ("----------------------------------------------\n");
  printf (" Input the filename to be opened(table.txt) :");
  scanf ("%s", fname);

  fptr = fopen (fname, "r");
  fptr1 = fopen (fname, "r");
  
  if (fptr == NULL)
    {
      perror ("Unable to open file!");
      exit (1);
    }
  
  chr = getc(fptr1);
    while (chr != EOF)
    {
        //Count whenever new line is encountered
        if (chr == '\n')
        {
            count_lines = count_lines + 1;
        }
        //take next character from file.
        chr = getc(fptr1);
    }
  
  
  int period[count_lines];
  float exec[count_lines];
  int deadine[count_lines];
  
  while (!feof (fptr))
    {
      fscanf (fptr, "%d %f %d", &period[i], &exec[i], &deadine[i]);
      printf ("%d %f %d", period[i], exec[i], deadine[i]);
      printf ("\n");
      i++;

    }

  fclose(fptr);
  size_t arr_size = sizeof (period) / sizeof (int);

  hp = hyperperiod (period,arr_size);

  frameSize = pframeSize1 (exec, period, deadine, hp,arr_size);

  printf ("frame size is : ");
  printf ("%d", frameSize);
  printf ("\n");
 
  
  createTable(exec, period, deadine, hp,arr_size,frameSize);
  //schedular();
  
  return 0;
}
