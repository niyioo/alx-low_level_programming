#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  char password[7];
  int i, num;

  srand(time(NULL));

  for (i = 0; i < 7; i++) {
    num = rand() % 62;
    if (num < 26) {
      password[i] = 'A' + num;
    } else if (num < 52) {
      password[i] = 'a' + num - 26;
    } else {
      password[i] = '0' + num - 52;
    }
  }

  printf("%s\n", password);

  return 0;
}

