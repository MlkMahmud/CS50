#include <stdio.h>
#include <math.h>


float get_float(void) {
  char line[5];
  float change;
  do {
    printf("Change owed: ");
    fgets(line, sizeof(line), stdin);
  } while(sscanf(line, "%f", &change) != 1 || change < 0);
  return change;
}


int main (void) {
  float change = get_float();
  int result;
  int coins = 0;
  float quarter = .25;
  float dime = .10;
  float nickel = .05;
  float penny = .01;

  while(change > 0) {
    if (change >= quarter) {
        change = (round((change - quarter) * 100) /100);
    } else if (change >= dime) {
        change = (round((change - dime) * 100) /100);
    } else if (change >= nickel) {
        change = (round((change - nickel) * 100) /100);
    } else {
        change = (round((change - penny) * 100) /100);
    }
    coins += 1;
  }
  printf("%i\n", coins);
}
