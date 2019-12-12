#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool is_alpha_string(char word []) {
  for(int i = 0; i < strlen(word); i++) {
    if (isalpha(word[i]) == 0){
      return false;
    }
  }
  return true;
}

int shift(char c) {
  int key = tolower(c) % 97;
  return key;
}

int main(int argc, char *argv[]) {
  char *key;
  char plaintext[300];
  int lower_bound = 96;
  int upper_bound = 122;
  if (argc != 2 || !is_alpha_string(argv[1])) {
    printf("Usage: ./vigenere keyword");
    exit(1);
  }
  key = argv[1]; 
  printf("plaintext: ");
  fgets(plaintext, sizeof(plaintext), stdin);

  for(int i = 0, k = 0; i < strlen(plaintext); i++) {
    if (key[k] == '\0') k = 0;

    if(isalpha(plaintext[i]) != 0) {
      char val = plaintext[i];
      int char_code = tolower(plaintext[i]);
      int shift_key = shift(key[k]);
      int new_char_code = char_code + shift_key;
      while (new_char_code > upper_bound) {
        new_char_code = lower_bound + (new_char_code % upper_bound);
      }
      plaintext[i] = isupper(val) > 0 ? toupper(new_char_code) : new_char_code;
      k++;
    }
  }
  printf("ciphertext: %s\n", plaintext);
}


