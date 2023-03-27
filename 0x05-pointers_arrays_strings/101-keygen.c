#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    char c[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char p[58] = {'\0'};
    srand(time(NULL));
    int s = 0;
    while (s != 2772) {
        s = 0;
        for (int i = 0; i < 57; i++) {
            int j = rand() % 62;
            p[i] = c[j];
            s += c[j];
        }
        p[57] = s == 2772 - c[0] ? c[0] : c[2772 - s - c[0]];
    }
    printf("%s", p);
    return 0;
}

