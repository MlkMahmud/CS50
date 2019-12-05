#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


int main (int argc, char *argv[]) {
  int key;
  char plaintext[300];
  int lowerBound = 96;
  int upperBound = 122;

  if (argc != 2 || sscanf(argv[1], "%i", &key) != 1) {
    printf("Usage: ./caesar key\n");
    exit(1);
  }


  printf("plaintext: ");
  fgets(plaintext, sizeof(plaintext), stdin);

  long textLength = strlen(plaintext);

   for (int i = 0; i < textLength; i++) {
    if (isalpha(plaintext[i]) != 0) {
      char val = plaintext[i];
      char c = tolower(plaintext[i]);
      int charCode = c;
      int newCharCode = charCode + key;
      while(newCharCode > upperBound) {
        newCharCode = lowerBound + (newCharCode % upperBound);
      }
      plaintext[i] = isupper(val) > 0 ? toupper(newCharCode) : newCharCode;
     }
   }
   printf("ciphertext: %s", plaintext);
}
