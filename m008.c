/* m008.c - Lastname-Names.

   This program reads the name of a person from the standard input
   in the form 'First-name middle-names last-name' and outputs the 
   name in the form 'LAST-NAME, first-name middle-names'.
   The name should be entered using only ASCII characters (26 letter 
   of latim alphabet, no diacrictics).


   E.g.

      command line    : m008
      standard input  : John Little Bill Doe 
      expected output : DOE, John Little Bill

   Directions:

      Please, edit function lasname();
      do no not change function main().

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>//StackOverflow is the second step towards becoming a programmer 
#include <string.h>

#define MAX 256

/* Converts the string 's' from first-middle-last name 
   form into LAST-first-middle form. */

void lastname (char *s)
{
  int l = strlen(s) - 2;  //índice do ultimo caractere válido
  int a = 0;        //indice do ultimo espaço
  int i;
  int j = 0;

  char lastName[MAX]; 
  char fullName[MAX];

  i = l;
  while(s[i] != 32){
    a = i - 1;
    i--;    
  }

  for(i = a + 1; s[i + 1] != 0; i++){
    lastName[j] = toupper(s[i]);
    s[i] = 0;
    j++;
  }

  strcat (fullName, lastName);
  strcat (fullName, ", ");
  strcat (fullName, s);

  strcpy (s, fullName);
}

/* Do not edit this function. */

int main (int argc, char **argv)
{
  int n;
  char name[MAX];

  fgets (name, MAX-1, stdin);
  
  lastname (name);

  printf ("%s\n", name);
  
  return 0;
}
