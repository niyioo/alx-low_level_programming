#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the minimum number of coins to make
 * change for an amount of money
 *
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 *
 * Return: 0
 */

int main(int argc, char **argv)
{
	int i;
	int cents, num_coins = 0;
	int coins[] = {25, 10, 5, 2, 1};
	int num_coin_types = sizeof(coins) / sizeof(int);

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	cents = atoi(argv[1]);

	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}

	for (i = 0; i < num_coin_types; i++)
	{
		while (cents >= coins[i])
		{
			cents -= coins[i];
			num_coins++;
		}
	}
	printf("%d\n", num_coins);

	return (0);
}
