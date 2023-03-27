#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - random password generator for 101-crackme
 *
 * Return: 0
 */

int main(void)
{
        char c[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        char p[58] = {'\0'};
        int s = 0;

        srand(time(NULL));
        while (s != 2772)
        {
                s = 0;
                for (int i = 0; i < 57; i++)
                {
                        int j = rand() % 62;
                        p[i] = c[j];
                        s += c[j];
                }
                p[57] = (s == 2772 - c[0]) ? c[0] : c[2772 - s - c[0]];
        }
        printf("%s", p);

        return (0);
}
