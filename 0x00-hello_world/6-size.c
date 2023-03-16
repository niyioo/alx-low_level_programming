#include <stdio.h>

/**
 * main - Entry point
 *
 * printf to know the size of the
 * folloing data types, char, int, long int,
 * long long int, and float
 *
 * Return: Always 0 (Succes)
 */
int main() {

  char a;
  int b;
  long int c;
  long long int d;
  float e;

  printf("char size = %zu", sizeof (a));
  printf("\nint size = %zu", sizeof (b));
  printf("\nlong int size = %zu", sizeof(c));
  printf("\nlong long int size = %zu", sizeof(d));
  printf("\nfloat size = %zu", sizeof(e));

  return 0;
}
