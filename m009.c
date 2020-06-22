/* m009.c - Sort vector.

   This program reads N<=100 numbers passed as command line
   arguments and ouputs them in ascending order. Choose the
   sorting algorithm of your preference (see below).

   E.g.

      command line    : m009 3 2 5 4 2
      expected output : 2 2 3 4 5

   Directions:

      Please, edit function sort();
      do no not edit function main().

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* Sort the first 'n' integers values in 'vector'. */

void sort (int* vector, int n)
{
  int min;
  int temp;
  int k;
  int j;

  for(k = 0; k < n; k++){

    min = vector[k];
    
    for(j = k; j < n; j++){
      if(vector[j] < min){
        temp = min;
        min = vector[j];
        vector[j] = temp;
        vector[k] = min;
      }
    }
  }
/*
  for(k = 0; k <= n; k++){

    min = vector[k];
    
    for(j = k; vector[j] < min; j++){
      temp = min;
      min = vector[j];
      vector[j] = temp;
      vector[k] = min;
    }
  }
*/  
}

#define USAGE "m009 <num1> <nun2> ... \n"

/* Do not edit this function. */

int main (int argc, char **argv)
{
  int values[MAX];
  int i;

  /* Read command line arguments into vector. */
  
  for (i=1; i<argc; i++)
    values[i-1] = atoi(argv[i]);


  /* Sort vector. */
  
  sort (values, argc-1);


  /* Output sorted vector. */
  
  for (i=0; i<argc-1; i++)
    printf ("%d ", values[i]);

  printf ("\n");
  
  return 0;
}

/* Tip: check these sorting methods

   Selection sort: https://en.wikipedia.org/wiki/Selection_sort
   Bubble sort: https://en.wikipedia.org/wiki/Bubble_sort
   Insertion sort: https://en.wikipedia.org/wiki/Insertion_sort
  
 */
