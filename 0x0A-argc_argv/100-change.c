#include <stdio.h>
#include <stdlib.h>

/**
 * minimumCoin - Calculates the min amt of count to make change of an amt
 * @cent: The amount in cents
 *
 * Return: The minimum number of coins required
 */
int minimumCoin(int cent)
{
	int coin[] = {25, 10, 5, 2, 1};
	int numberCoins = 0;
	int ind = 0;

	if (cent < 0)
	{
		return (0);
	}

	while (cent > 0)
	{
		numberCoins += cent / coin[ind];
		cent %= coin[ind];
		ind++;

		if (ind == 5)
		{
			break;
		}
	}

		return (numberCoins);
}

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: Array containing the command-line arguments
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	int results;
	int cent;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

		cent = atoi(argv[1]);

	if (cent < 0)
	{
		printf("0\n");
	}
	else
	{
		results = minimumCoin(cent);
		printf("%d\n", results);
	}

	return (0);
}
