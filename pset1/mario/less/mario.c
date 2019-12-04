#include <stdio.h>

int get_height () {
  char line[5];
  int height;
  do {
    printf("Height: ");
    fgets(line, sizeof(line), stdin);
  } while (sscanf(line, "%i", &height) != 1 || height < 1 || height > 8);
    return height;
}

int main (void) {
  int height = get_height();
  char bricks[10] = "########";
  char padding[10] = "        ";

  for (int i = 1; i <= height; i++) {
    printf("%.*s%.*s\n", height - i, padding, i, bricks);
  }
}
