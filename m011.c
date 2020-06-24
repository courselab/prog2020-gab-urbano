/* m011.c - Count words.

   This program takes the name of an ASCII text file passed as a command 
   line argument, and outputs the number of words in this file. A word is 
   a sequence of alphabetic characters delimited by blanks. A sample text 
   file i011.txt is provided for convenience (should you desire to test with
   another text file, make sure it is in pure ASCII format, not UTF-8 or 
   other milti-byte format.

   E.g.

      command line    : m011 i011.txt
      expected output : 98

   Directions:

      Please, edit function wordcount();
      do no not change function main().

 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define USAGE "m011 <filename>\n"
#define IN 1
#define OUT 0
#define MAX 1024

/* Return the number of words in ascii text file 'filename'.*/

int wordcount (char *filename) 
{
  //WIP
  FILE *fp;
  fp = fopen(filename, "r");

  int state, numWord = 0, n;
  
  state = OUT;
  while((n = getc(fp)) != EOF){
    if(isalpha(n) == 0){
      state = OUT;
    }
    else if(state == OUT){
      state = IN;
      numWord++;
    }
  }

  return numWord;
}

/* Do not edit function main. */

int main (int argc, char **argv)
{
  int n;
  int g;

  if (argc < 2)
    {
      printf (USAGE);
      exit(1);
    }
  
  n = wordcount (argv[1]);

  printf ("%d\n", n);
  
  return 0;
}
