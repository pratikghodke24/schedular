#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "func.h"

void printArray(float exec[], int period[], int deadine[],int p[], int n,int del,size_t arr_size) 
{ 
    /*for (int i = 0; i < n; i++) 
      printf ("%d", p[i]);
  printf ("\n");*/
  int i;
  for (i = 0; i <  arr_size; i++)
  if(exec[i]==del) break;
  
  for (int j=i; j <  arr_size; j++)
        exec[j] = exec[j+1];
        
  for (int k=0; k <  arr_size; k++)
       { printf ("%f", exec[k]);
  printf ("\n");}
 // for (int i=0; i < (sizeof (exec) / sizeof (int)+1); i++)   
        
} 

void printAllUniqueParts (float *exec, int *period, int *deadine,int n,size_t arr_size)
  {
    int p[n];			// An array to store a partition 
    int k = 0;			// Index of last element in a partition 
    p[k] = n;			// Initialize first partition as number itself 

    // This loop first prints current partition then generates next 
    // partition. The loop stops when the current partition has all 1s 
    while (true)
      {
	// print current partition 
	printArray (exec, period, deadine,p, k + 1,n,arr_size);

	// Generate next partition 

	// Find the rightmost non-one value in p[]. Also, update the 
	// rem_val so that we know how much value can be accommodated 
	int rem_val = 0;
	while (k >= 0 && p[k] == 1)
	  {
	    rem_val += p[k];
	    k--;
	  }

	// if k < 0, all the values are 1 so there are no more partitions 
	if (k < 0)
	  return;

	// Decrease the p[k] found above and adjust the rem_val 
	p[k]--;
	rem_val++;


	// If rem_val is more, then the sorted order is violated.  Divide 
	// rem_val in different values of size p[k] and copy these values at 
	// different positions after p[k] 
	while (rem_val > p[k])
	  {
	    p[k + 1] = p[k];
	    rem_val = rem_val - p[k];
	    k++;
	  }

	// Copy rem_val to next position and increment position 
	p[k + 1] = rem_val;
	k++;
      }
  }

int slicing (float exec[], int period[], int deadine[],size_t arr_size) //not completed yet
{
  int largest = ceil(exec[0]);

  for (int i = 1; i < arr_size; i++)

    {

      if (largest < ceil(exec[i]))

	largest = ceil(exec[i]);

    }
  
    printAllUniqueParts (exec, period, deadine,largest,arr_size);
    
    
}

int gcd (int n1, int n2)
{
  while (n1 != n2)
    {
      if (n1 > n2)
	n1 -= n2;
      else
	n2 -= n1;
    }

  return n1;
}


bool check11 (int f, float exec[],size_t arr_size)
{
  int largest = ceil(exec[0]);

  for (int i = 1; i < arr_size; i++)

    {

      if (largest < ceil(exec[i]))

	largest = ceil(exec[i]);

    }
  if (f >= largest)
    return true;
  return false;
}

bool check22 (int f, int hp)
{
  if (hp % f == 0)
    return true;
  return false;
}

bool check33 (int f, int period[],int deadine[],size_t arr_size)
{
  for (int i = 0; i < arr_size; i++)
    if ((2 * f - gcd (period[i], f)) <= deadine[i])
      continue;
    else
      return false;

  return true;
}

int pframeSize1 (float exec[], int period[], int deadine[], int hp,size_t arr_size)
{
  int pframeSize[10];
  int count = 0;
  bool check1, check2, check3;

  for (int i = 0; i < arr_size; i++)
    {
      pframeSize[i] = 0;
    }
  for (int i = 1; i < hp + 1; i++)
    {
      check1 = check11 (i, exec,arr_size);
      check2 = check22 (i, hp);
      check3 = check33 (i, period,deadine,arr_size);
      if (check1 && check2 && check3)
	{
	  pframeSize[count] = i;
	  count++;
	}



    }

  int largest = pframeSize[0];

     for (int i = 1; i < count; i++)

     {

     if (largest < pframeSize[i])

     largest = pframeSize[i];

     } 
   
  if (largest == 0)  
  {
	//slicing (exec, period, deadine,arr_size);pframeSize1 (exec, period, deadine, hp,arr_size);
  }

  return largest;
  
}
