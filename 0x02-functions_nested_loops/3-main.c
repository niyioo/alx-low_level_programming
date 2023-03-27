#include "main.h"

/**
 * _islower - checks for lowercase character
 *
 * @c: input.
 *
 * Return: 1 if c is lowercase
 * 0 if c is not lowercase
 */

int main(void)
{
    int r;

    r = _islower('H');
    _putchar(r + '0');
    r = _islower('o');
    _putchar(r + '0');
    r = _islower(108);
    _putchar(r + '0');
    _putchar('\n');
    return (0);
}
