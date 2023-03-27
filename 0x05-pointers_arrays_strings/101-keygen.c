#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - entry point generates a random password
 *
 * Return: 0
 */
int main(void)
{
char c;
int x = rand() % 128;;

srand(time(0));
while (x <= 2645)
{
c = rand() % 128;
x += c;
putchar(c);
}
putchar(2772 - x);
putchar('\n');
return (0);
}
