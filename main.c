#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algo.h"

#define TXT 1024
#define WORD 30

int main(void)
{
   char txt[TXT];
   char word[WORD];
   char x = '0';

   scanf("%[^\n^\t^' ']", word);
   scanf("%c", &x);
   scanf("%[^~]", txt);

   init(word, txt);
   printf("Gematria Sequences: ");
   GimatryProg();
   printf("\nAtbash Sequences: ");
   atbash();
   printf("\nAnagram Sequences: ");
   AnagramProg();

   return 0;
}