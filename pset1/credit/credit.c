#include <stdio.h>
#include <string.h>
#include <stdbool.h>

long long getCardNumber () {
  char line[17];
  long long number;
  do {
    printf("Number: ");
    fgets(line, sizeof(line), stdin);
  } while (sscanf(line, "%lld", &number) != 1);
  return number;
}

bool isValidCard (char *cardNumber) {
  long total = 0;
  int length = strlen(cardNumber);

  for (int i = length - 2; i >= 0; i -= 2) {
    int charTimesTwo = (cardNumber[i] - '0') * 2;
    int result = charTimesTwo > 9 ? (charTimesTwo - 9) : charTimesTwo;
    cardNumber[i] = result + '0';
  }
  for(int x = 0; x < length; x++) {
    total += (cardNumber[x] - '0');
  }
  return (total % 10 == 0 && (length >= 13 && length <= 16));
}

int main (void) {
  char cardNumber[20];
  char originalNumber[20];
  sprintf(cardNumber, "%lld", getCardNumber());
  strcpy(originalNumber, cardNumber);
  
  if(isValidCard(cardNumber)){
    char firstDigit = originalNumber[0];
    char secondDigit = originalNumber[1];

    if(firstDigit == '4') printf("VISA\n");
    else if (firstDigit == '5' && ((secondDigit - '0') >=1 && (secondDigit - '0') <= 5)) {
      printf("MASTERCARD\n");
    } else if (firstDigit == '3' && (secondDigit == '4' || secondDigit == '7')) {
      printf("AMEX\n");
    } else printf("INVALID\n");

  } else {
    printf("INVALID\n");
  }
}
